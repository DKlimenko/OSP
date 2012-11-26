#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

CIRCLEQ_HEAD(pcb_head, pcb) head;

struct pcb {
  int life;
  int pid;
  CIRCLEQ_ENTRY(pcb) pcb_links;
} *current_pcb;

struct dispatch_timer_t {
  void* (*fp)();
  int after;
}dp_timer;

pthread_mutex_t queue_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t cur_pcb_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dirty_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_t dispatch_thr;

static const proc_spawn_time = 5;
static const max_proc_time = 10;
static const quantum = 4;
static stop = 0;
static dirty = 0;

void* dispatch();

void init_dp_timer()
{
  dp_timer.after = quantum;
  dp_timer.fp = dispatch;
}

void set_dirty(int i)
{
  pthread_mutex_lock( &dirty_lock );
  dirty = i;
  pthread_mutex_unlock( &dirty_lock );
}

struct pcb* pop()
{
  if( CIRCLEQ_EMPTY(&head) )
    return NULL;

  struct pcb* p = CIRCLEQ_FIRST( &head );

  pthread_mutex_lock( &cur_pcb_lock );
  CIRCLEQ_REMOVE( &head, p, pcb_links );
  pthread_mutex_unlock( &cur_pcb_lock );

  return p;
}

void push(struct pcb* ent)
{
  pthread_mutex_lock( &queue_lock );
  CIRCLEQ_INSERT_TAIL(&head, ent, pcb_links);
  pthread_mutex_unlock( &queue_lock );
}

void insert_ready( struct pcb* p )
{
  struct pcb* i;
  CIRCLEQ_FOREACH(i,&head,pcb_links)
  {
    if( p->pid == i->pid )
      return;
  }
  push(p);
  set_dirty(1);
}

void* run_timer()
{
  sleep( dp_timer.after );
  dp_timer.fp();
}

void set_timer()
{
  pthread_create(&dispatch_thr, NULL, run_timer, NULL);
}

void *proc_generator()
{
  while(!stop)
  {
    struct pcb *proc = malloc(sizeof(struct pcb));
    proc->life = (rand() % max_proc_time) + 1 ;
    proc->pid = rand();
    insert_ready( proc );
    sleep( proc_spawn_time );
  }
}

void* printer()
{
  while(!stop)
  {
    if(!dirty)
      continue;

    struct pcb* p;

    system("clear");
    printf("Head Node:\nself:%p\tfirst:%p\tlast:%p\n",
        &head, head.cqh_first, head.cqh_last);
    printf("Processes in the ready queue:\n");
    CIRCLEQ_FOREACH_REVERSE(p,&head,pcb_links)
    {
      printf("Pid:%d\tlife:%d\tself:%p\tprev:%p\tnext:%p\n", 
           p->pid, p->life, p, p->pcb_links.cqe_prev, p->pcb_links.cqe_next);
    }

    if(current_pcb)
    {
      printf("\nCurrent procces:\n");
      printf("Pid:%d\tlife:%d\tself:%p\tprev:%p\tnext:%p\n", 
           current_pcb->pid, current_pcb->life, current_pcb, current_pcb->pcb_links.cqe_prev, current_pcb->pcb_links.cqe_next);
    }

    set_dirty(0);
  }
}

void* dispatch()
{
  if( current_pcb )
      /*current_pcb.status == RUNNING )*/
  {
    insert_ready(current_pcb);
  }

  current_pcb = pop();
  set_dirty(1);

  if(!stop)
  {
    set_timer();
  }

  if( !current_pcb )
    return;
  /*current_pcb.status = RUNNING;*/
  /*last_dispatch = get.check();*/

}

void* cpu()
{
  while(!stop)
  {
    if( current_pcb )
    {
      pthread_mutex_lock( &cur_pcb_lock );
      --(current_pcb->life);
      pthread_mutex_unlock( &cur_pcb_lock );
      set_dirty(1);

      if( current_pcb->life <= 0 )
      {
        free(current_pcb);
        current_pcb = NULL;
        pthread_cancel(dispatch_thr);
        dispatch();
      }
    }
    sleep(1);
  }
}

int main(int argc, const char *argv[])
{
  CIRCLEQ_INIT(&head);
  init_dp_timer();
  pthread_t proc_gen_thr, printer_thr, cpu_thr;

  pthread_create(&proc_gen_thr, NULL, proc_generator, NULL);
  while( !CIRCLEQ_EMPTY(&head) ); /* Wait until first process generated */

  pthread_create(&dispatch_thr, NULL, dispatch, NULL);
  while( current_pcb ); /* Wait until process started */

  pthread_create(&cpu_thr, NULL, cpu, NULL);

  pthread_create(&printer_thr, NULL, printer, NULL);

  /* Wait until 'exit' typed*/
  char in[5];
  while( scanf("%s",in) && 
         strcmp(in,"exit"));
  stop = 1;

  pthread_join(proc_gen_thr, NULL);
  pthread_join(printer_thr, NULL);
  pthread_join(dispatch_thr, NULL);
  pthread_join(cpu_thr, NULL);

  return 0;
}

