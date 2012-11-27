
#include <sys/queue.h>
#include <stdio.h>

/****************************************************************************/
/*                                                                          */
/* 			     Module CPU                                     */
/* 			External Declarations 				    */
/*                                                                          */
/****************************************************************************/


/* OSP constant      */

#define   MAX_PAGE                   16 /* max size of page tables          */

/* OSP enumeration constants */

typedef enum {
    false, true                         /* the boolean data type            */
} BOOL;

typedef enum {
    running, ready, waiting, done       /* types of status                  */
} STATUS;



/* external type definitions */

typedef struct page_entry_node PAGE_ENTRY;
typedef struct page_tbl_node PAGE_TBL;
typedef struct event_node EVENT;
typedef struct pcb_node PCB;
typedef struct pcb_node_wrapper WRAPPER;
typedef struct pcb_head HEAD;


/* external data structures */

struct page_entry_node {
    int    frame_id;    /* frame id holding this page                       */
    BOOL   valid;       /* page in main memory : valid = true; not : false  */
    BOOL   ref;         /* set to true every time page is referenced AD     */
    int    *hook;       /* can hook up anything here                        */
};

struct page_tbl_node {
    PCB    *pcb;        /* PCB of the process in question                   */
    PAGE_ENTRY page_entry[MAX_PAGE];
    int    *hook;       /* can hook up anything here                        */
};

struct pcb_node_wrapper {
    PCB*	node;
    CIRCLEQ_ENTRY(PCB) pcb_links;
};

struct pcb_node {
    int    pcb_id;         /* PCB id                                        */
    int    size;           /* process size in bytes; assigned by SIMCORE    */
    int    creation_time;  /* assigned by SIMCORE                           */
    int    last_dispatch;  /* last time the process was dispatched          */
    int    last_cpuburst;  /* length of the previous cpu burst              */
    int    accumulated_cpu;/* accumulated CPU time                          */
    PAGE_TBL *page_tbl;    /* page table associated with the PCB            */
    STATUS status;         /* status of process                             */
    EVENT  *event;         /* event upon which process may be suspended     */
    int    priority;       /* user-defined priority; used for scheduling    */
    PCB    *next;          /* next pcb in whatever queue                    */
    PCB    *prev;          /* previous pcb in whatever queue                */
    int    *hook;          /* can hook up anything here                     */
};


/* external variables */

extern PAGE_TBL *PTBR;		/* page table base register */

extern int    Quantum;		/* global time quantum; contains the value
				   entered at the beginning or changed 
				   at snapshot. Has no effect on timer
				   interrupts, unless passed to set_timer() */



/* external routines */

extern prepage(/* pcb */);
extern int start_cost(/* pcb */);
/*  PCB    *pcb; */    

extern set_timer(/* time_quantum */);
/*  int    time_quantum; */

extern int get_clock();





/****************************************************************************/
/*                                                                          */
/*				Module CPU				    */
/*			     Internal Routines				    */
/*                                                                          */
/****************************************************************************/

CIRCLEQ_HEAD(pcb_head, pcb_node_wrapper);
HEAD *head;




void cpu_init()
{
  CIRCLEQ_INIT(head);
  head = (HEAD*) malloc(sizeof(HEAD));
  head->cqh_first = NULL;
  head->cqh_last = NULL;
}

PCB* pop()
{
  if( CIRCLEQ_EMPTY(head) )
    return NULL;

  WRAPPER* p = CIRCLEQ_FIRST( head );
  //
  //CIRCLEQ_REMOVE( &h, p, pcb_links );
	if (CIRCLEQ_NEXT((p), pcb_links) == (void *)(head))	
		CIRCLEQ_LAST((head)) = CIRCLEQ_PREV((p), pcb_links);	
	else
	{ 
		//PCB* t;
		//t = p->pcb_links.cqe_next;
		(((p->pcb_links).cqe_next)->pcb_links).cqe_prev =	(p->pcb_links).cqe_prev;
		//WRAPPER* t1 = p->pcb_links.cqe_next;
    //WRAPPER* t2 = t1->pcb_links.cqe_prev;
    //WRAPPER* t3 =	p->pcb_links.cqe_prev;
	}
	if (CIRCLEQ_PREV((p), pcb_links) == (void *)(head))		
		CIRCLEQ_FIRST((head)) = CIRCLEQ_NEXT((p), pcb_links);	
	else								
		CIRCLEQ_NEXT(CIRCLEQ_PREV((p), pcb_links), pcb_links) =	
		    CIRCLEQ_NEXT((p), field);				


  return p->node;
}

void dispatch()
{
  PCB* current_pcb = PTBR->pcb;
  if( current_pcb != NULL &&
      current_pcb->status == running )
  {
    insert_ready(current_pcb);
  }

  current_pcb = pop();


  if( current_pcb != NULL )
  {
    PTBR = current_pcb->page_tbl;
    current_pcb->status = running;
    current_pcb->last_dispatch = get_clock();
    set_timer(Quantum);
  }
  else
  {
    PTBR = NULL;
  }
}

void insert_ready(pcb)
PCB *pcb;
{
  WRAPPER* i;
  CIRCLEQ_FOREACH(i,head,pcb_links)
  {
    if( i->node->pcb_id == pcb->pcb_id )
      return;
  }

  WRAPPER* new_pcb = malloc( sizeof(WRAPPER) );
  new_pcb->node = pcb;
  CIRCLEQ_INSERT_TAIL(head, new_pcb, pcb_links);
  pcb->status = ready;

  fprintf(stderr,"Head Node:\nself:%p\tfirst:%p\tlast:%p\n",
		  head, head->cqh_first, head->cqh_last);
  fprintf(stderr,"Processes in the ready queue:\n");

  WRAPPER* p;
  CIRCLEQ_FOREACH_REVERSE(p,head,pcb_links)
  {
	  fprintf(stderr,"Pid:%d\tself:%p\tprev:%p\tnext:%p\n",
			  p->node->pcb_id, p, p->pcb_links.cqe_prev, p->pcb_links.cqe_next);
  }
}

/* end of module */
