/****************************************************************************/
/*                                                                          */
/*           Module MEMORY                                  */
/*      External Declarations                               */
/*                                                                          */
/****************************************************************************/

/****************
 * Names:       *
 * Jakob Kallin *
 * Attila Nagy  *
 *              *
 * Group: #8    *
 ****************/

/****************************************************************************************************************************************
 ****************************************************** Table of results for pagefault frequency ****************************************
 ****************************************************************************************************************************************
 * Measurement #1                                                                                                                       *
 *LOTS_FREE:         1       2       3       4       5       6       7       8       9       10      11      12      13      14      15 *
 *MIN_FREE 1:      .2015   .2132   .2134   .2027   .2033   .1937   .2036   .1881   .2206   .2091   .1775   .2026   .2241   .2317   .2341*
 *MIN_FREE 2:      .1932   .2158   .1944   .2000   .1891   .1907   .2019   .2082   .2126   .2142   .2227   .2029   .2222   .2232   .2216*
 *MIN_FREE 3:      .2017   .2313   .2134   .2093   .2088   .2092   .2173   .2086   .2333   .2290   .2332   .2262   .2245   .2380   .2395*
 *MIN_FREE 4:      .2132   .2185   .2172   .2108   .2116   .2236   .2145   .2200   .2325   .2262   .2282   .2119   .2183   .2230   .2536*
 *MIN_FREE 5:      .2475   .2102   .2266   .1992   .2493   .2157   .2363   .2448   .2513   .2376   .2413   .2433   .2394   .2473   .2498*
 *MIN_FREE 6:      .2665   .2375   .2290   .2289   .2262   .2260   .2314   .2288   .2526   .2398   .2414   .2641   .2480   .2581   .2350*
 *MIN_FREE 7:      .2588   .2482   .2216   .2324   .2246   .2178   .2310   .2661   .2427   .2638   .2554   .2670   .2466   .2721   .2763*
 *MIN_FREE 8:      .2475   .2447   .2253   .2681   .2402   .2525   .2633   .2546   .2575   .2909   .2670   .2554   .3113   .2926   .2934*
 *MIN_FREE 9:      .2843   .2481   .2616   .2615   .2473   .2918   .2536   .2602   .2604   .2577   .3418   .2855   .2798   .3162   .3224*
 *MIN_FREE 10:     .2125   .2548   .2275   .2573   .2716   .2250   .2852   .2691   .3051   .2671   .2910   .3306   .3087   .3517   .2896*
 *MIN_FREE 11:     .3857   .2668   .2730   .3034   .2668   .3021   .3213   .3144   .3182   .3585   .2665   .3422   .3125   .2995   .3299*
 *MIN_FREE 12:     .4878   .3047   .2685   .2909   .2990   .3026   .3325   .2791   .2976   .3421   .3455   .3354   .3853   .3177   .2384*
 *MIN_FREE 13:     .3503   .3236   .3171   .3076   .3505   .3017   .3232   .3182   .3563   .3302   .3423   .3413   .3375   .4592   .5024*
 *MIN_FREE 14:     .4006   .3540   .3477   .3506   .3118   .3844   .3851   .3726   .3292   .3762   .3750   .3609   .3714   .4167   .3774*
 *MIN_FREE 15:     .4047   .3862   .3644   .3932   .3441   .3686   .3681   .4251   .3928   .3772   .4637   .4786   .5404   .5022   .5354*
 ****************************************************************************************************************************************
 * Measurement #2                                                                                                                       *
 *LOTS_FREE:         1       2       3       4       5       6       7       8       9       10      11      12      13      14      15 *
 *MIN_FREE 1:      .2456   .2094   .2187   .1984   .2056   .2217   .2112   .1986   .2476   .2252   .2119   .2296   .2385   .2578   .2281*
 *MIN_FREE 2:      .2224   .2245   .2196   .2339   .2155   .2258   .2030   .1976   .2111   .2276   .2377   .2492   .2151   .2307   .2579*
 *MIN_FREE 3:      .2289   .2045   .2244   .2079   .2329   .2221   .2178   .2410   .2344   .2287   .2180   .2293   .2338   .2436   .2505*
 *MIN_FREE 4:      .2503   .2294   .2101   .2316   .2256   .2361   .2395   .2500   .2083   .2383   .2256   .2591   .2688   .2533   .2638*
 *MIN_FREE 5:      .2413   .2570   .2331   .2235   .2301   .2408   .2514   .2379   .2377   .2532   .2620   .2847   .2525   .2677   .2709*
 *MIN_FREE 6:      .2618   .2478   .2277   .2493   .2281   .2446   .2334   .2358   .2556   .2641   .2735   .2645   .2545   .2697   .2769*
 *MIN_FREE 7:      .2422   .2365   .2413   .2604   .2676   .2361   .2543   .2553   .2478   .3023   .2565   .2771   .2922   .3308   .2953*
 *MIN_FREE 8:      .3448   .2679   .2622   .2522   .2862   .2519   .2769   .2655   .2744   .2705   .2816   .3207   .3098   .2828   .3562*
 *MIN_FREE 9:      .3199   .2673   .2811   .2677   .2739   .2611   .2644   .2917   .2835   .3005   .3213   .3017   .2839   .3242   .3466*
 *MIN_FREE 10:     .3007   .2614   .2697   .2899   .2690   .2829   .2866   .3021   .3125   .3250   .3667   .3095   .3646   .3170   .3645*
 *MIN_FREE 11:     .3956   .3044   .2640   .3104   .3178   .2965   .3180   .3080   .3152   .3430   .3270   .3357   .3334   .3652   .3622*
 *MIN_FREE 12:     .3423   .2959   .3172   .2937   .3049   .3157   .3843   .3418   .3417   .3488   .3325   .3049   .3658   .4046   .3773*
 *MIN_FREE 13:     .4071   .3413   .3419   .3041   .3688   .3451   .3887   .4078   .3684   .3806   .3775   .4016   .4081   .3655   .4347*
 *MIN_FREE 14:     .4838   .3777   .3575   .3449   .3720   .3964   .4078   .3697   .3830   .4033   .4271   .3583   .4124   .4628   .4417*
 *MIN_FREE 15:     .4708   .3816   .3726   .3845   .4454   .3900   .3595   .4226   .3812   .4533   .3982   .4861   .4801   .4873   .5043*
 ****************************************************************************************************************************************
 * Measurement #3                                                                                                                       *
 *LOTS_FREE:         1       2       3       4       5       6       7       8       9       10      11      12      13      14      15 *
 *MIN_FREE 1:      .1931   .2051   .2036   .2045   .2120   .2031   .2110   .2172   .2093   .2102   .2123   .2202   .2130   .2149   .1918*
 *MIN_FREE 2:      .2166   .1950   .2063   .2114   .2255   .2168   .2176   .2032   .2196   .2401   .2484   .2384   .2475   .2576   .2353*
 *MIN_FREE 3:      .2389   .2198   .2070   .2204   .2083   .2320   .1843   .2412   .2475   .2376   .2159   .2453   .2320   .2498   .2761*
 *MIN_FREE 4:      .2372   .2349   .2117   .2249   .2296   .2104   .2306   .2431   .2463   .2379   .2044   .2512   .2558   .2592   .2471*
 *MIN_FREE 5:      .2355   .2277   .2505   .2392   .2286   .2784   .2525   .2364   .2456   .2268   .2719   .2686   .2672   .2651   .2598*
 *MIN_FREE 6:      .2537   .2302   .2381   .2230   .2622   .2427   .2526   .2568   .2558   .2500   .2643   .2545   .2860   .3141   .2757*
 *MIN_FREE 7:      .3073   .2683   .2370   .2488   .2510   .2242   .2731   .2631   .2650   .2768   .2526   .3006   .2963   .2684   .2976*
 *MIN_FREE 8:      .2629   .2693   .2020   .2440   .2702   .2440   .2624   .2386   .2809   .2769   .2768   .3160   .3081   .2964   .3118*
 *MIN_FREE 9:      .3003   .2554   .2839   .2460   .2544   .2943   .2690   .3016   .3069   .2880   .2666   .2894   .3297   .2738   .3331*
 *MIN_FREE 10:     .2906   .2573   .2798   .2950   .3107   .3527   .2923   .3697   .2950   .3270   .3228   .3159   .3298   .3416   .2702*
 *MIN_FREE 11:     .3291   .3791   .2899   .2840   .3142   .3270   .3326   .3387   .3432   .3852   .2941   .3370   .3553   .3898   .3583*
 *MIN_FREE 12:     .3002   .3130   .3218   .3397   .3028   .3556   .3568   .3220   .3569   .3253   .3838   .3187   .3767   .4300   .3703*
 *MIN_FREE 13:     .3674   .3088   .3704   .3472   .3408   .3058   .3225   .2927   .3449   .3230   .3670   .3791   .3873   .4040   .4232*
 *MIN_FREE 14:     .4018   .3755   .3763   .4128   .3279   .3604   .3615   .3853   .3812   .4072   .3947   .4106   .4424   .4731   .4664*
 *MIN_FREE 15:     .4691   .4389   .3880   .3643   .4265   .3523   .4020   .4330   .4238   .4262   .4346   .4226   .5054   .6141   .5578*
 ****************************************************************************************************************************************/

/***************************************************************************
 * Discussion:                                                              
 *
 * Three measurement were performed to find the best MIN_FREE and LOTS_FREE
 * values. These results are represented by the tables above. During all the
 * test we used different seed file for each tables, but the seed does not
 * changed during the measurement. From the results above we draw the following
 * conclusion:
 *
 * In essence, the demon is prematurely removing pages that might be used
 * again. Every time this happens, we increase the risk of a page fault. The
 * MIN_FREE parameter determines how many frames should be free at any given
 * time. For each additional frame that stays free, we increase the risk of a
 * page fault because we have fewer pages in memory. The LOTS_FREE parameter
 * determines how many frames should be freed when the demon runs. For each
 * frame that is freed, as before we increase the risk of a page because we
 * have fewer pages in memory.
 *
 * Our optimal choice, then, is to set the values as low as possible: MIN_FREE
 * = 1 and LOTS_FREE = 1. In effect, we only free frames when they are just
 * about to run out, and we only free one at a time. This is essentially the
 * same as the second chance algorithm (without a demon): We delay swapping
 * pages until it's absolutely necessary, thus letting pages stay in memory for
 * as long as possible. 
 *
 * From the statistic it can seen that the lower the values, the lower the page
 * fault frequency. In fact, there were no best MIN_FREE values above 2.  There
 * might be some small variance, however, because the simulation runs for a
 * specified length of time, not for a specified number of memory references.
 * This means that some simulations might go through more sections of high
 * reference locality than others.
 * 
 ***************************************************************************/

#include <stdio.h>


/* OSP constants */

#define MAX_PAGE       16                 /* max size of page tables        */
#define MAX_FRAME      32                 /* size of the physical memory    */
#define PAGE_SIZE      512                /* size of a page in bytes        */

#define   COST_OF_PAGE_TRANSFER      6  /* cost of reading page  from drum  */


/* external enumeration constants */

typedef enum {
    false, true                         /* the boolean data type            */
} BOOL;

typedef enum {
    read, write                         /* type of actions for I/O requests */
} IO_ACTION;

typedef enum {
    load, store                         /* types of memory reference        */
} REFER_ACTION;

typedef enum {
    running, ready, waiting, done       /* types of status                  */
} STATUS;

typedef enum {
    iosvc, devint,                      /* types of interrupt               */
    pagefault, startsvc,
    termsvc, killsvc,
    waitsvc, sigsvc, timeint
} INT_TYPE;



/* external type definitions */

typedef struct page_entry_node PAGE_ENTRY;
typedef struct page_tbl_node PAGE_TBL;
typedef struct event_node EVENT;
typedef struct ofile_node OFILE;
typedef struct pcb_node PCB;
typedef struct iorb_node IORB;
typedef struct int_vector_node INT_VECTOR;
typedef struct frame_node FRAME;



/* external data structures */

struct frame_node {
    BOOL   free;        /* = true, if free                                  */
    PCB    *pcb;        /* process to which the frame currently belongs     */
    int    page_id;     /* vitrual page id - an index to the PCB's page tbl */
    BOOL   dirty;       /* indicates if the frame has been modified         */
    int    lock_count;  /* number of locks set on page involved in an       */
                        /* active I/O                                       */
    int    *hook;       /* can hook up anything here                        */
};

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

struct iorb_node {
    int    iorb_id;     /* iorb id                                          */
    int    dev_id;      /* associated device; index into the device table   */
    IO_ACTION action;   /* read/write                                       */
    int    block_id;    /* block involved in the I/O                        */
    int    page_id;     /* buffer page in the main memory                   */
    PCB    *pcb;        /* PCB of the process that issued the request       */
    EVENT  *event;      /* event used to synchronize processes with I/O     */
    OFILE  *file;       /* associated entry in the open files table         */
    IORB   *next;       /* next iorb in the device queue                    */
    IORB   *prev;       /* previous iorb in the device queue                */
    int    *hook;       /* can hook up anything here                        */
};

struct int_vector_node {
    INT_TYPE cause;           /* cause of interrupt                         */
    PCB    *pcb;              /* PCB to be started (if startsvc) or pcb that*/
            /* caused page fault (if fagefault interrupt) */
    int    page_id;           /* page causing pagefault                     */
    int    dev_id;            /* device causing devint                      */
    EVENT  *event;            /* event involved in waitsvc and sigsvc calls */
    IORB   *iorb;             /* IORB involved in iosvc call                */
};



/* extern variables */

extern INT_VECTOR Int_Vector;           /* interrupt vector                */
extern PAGE_TBL *PTBR;                  /* page table base register        */
extern FRAME Frame_Tbl[MAX_FRAME];      /* frame table                     */
extern int Prepage_Degree;    /* global degree of prepaging (0-10) */



/* external routines */

extern siodrum(/* action, pcb, page_id, frame_id */);
/*  IO_ACTION   action;
    PCB         *pcb; 
    int         page_id, frame_id;  */
extern int get_clock();
extern gen_int_handler();


/****************************************************************************/
/*                                                                          */
/*           Module MEMORY                                  */
/*      Internal Declarations                               */
/*                                                                          */
/****************************************************************************/

#define   PRIVATE         static
#define   PUBLIC
#define   TRUE            1
#define   FALSE           0
//#define   NULL            0      /*  NULL pointer   */
#define   UNLOCKED        0
#define   MAX_SIZE      MAX_PAGE*PAGE_SIZE /* max size of a job allowed     */


#define get_page_tbl(pcb)   pcb->page_tbl

#define lock_frame(frame_id)    Frame_Tbl[frame_id].lock_count++
#define unlock_frame(frame_id)    Frame_Tbl[frame_id].lock_count--
#define set_frame_dirty(frame_id) Frame_Tbl[frame_id].dirty = true


/* external variables */

static int trace = FALSE; /* Internal trace flag */
static int clock_hand = 0;



#define MIN_FREE 1
#define LOTS_FREE 1

typedef struct list_item_struct LIST_ITEM;
struct list_item_struct {
  PAGE_ENTRY *page;
  LIST_ITEM *next;
  LIST_ITEM *prev;
};

LIST_ITEM *current;

PRIVATE void list_insert(PAGE_ENTRY*);
PRIVATE void list_remove();
PRIVATE void put_into_frame(PCB *pcb, PAGE_ENTRY *page, int page_id);
PRIVATE void page_demon();

/**************************************************************************/
/*                    */
/*      memory_init()           */
/*                    */
/*   Description  : initialize the data structure in memory module        */
/*                    */
/*   called by    : SIMCORE module            */
/*                    */
/**************************************************************************/
PUBLIC
memory_init()
{
  current = NULL;
}


/**************************************************************************/
/*                    */
/*      get_page            */
/*                    */
/*  Description : To  transfer a page from drum to main memory        */
/*                        */
/*      Called by   : PAGEINT module            */
/*                    */
/*                    */
/**************************************************************************/
PUBLIC
get_page(pcb,page_id)
PCB   *pcb;
int    page_id;

{
  // If some locks have now been released, free the frames.
  int i = 0;
  for (i = 0; i < MAX_FRAME; ++i) {
    FRAME *frame = &(Frame_Tbl[i]);
    if (frame->pcb == NULL && frame->lock_count == 0) {
      frame->free = true;
    }
  }
  
  int free_frames = 0;
  for (i = 0; i < MAX_FRAME; ++i) {
    FRAME *frame = &(Frame_Tbl[i]);
    if (frame->free && frame->lock_count == 0) {
      ++free_frames;
    }
  }
  
  if (free_frames < MIN_FREE) {
    page_demon();
  }
  
  PAGE_ENTRY *page = &(pcb->page_tbl->page_entry[page_id]);
  list_insert(page);
  
  put_into_frame(pcb, page, page_id);
}

PRIVATE
void put_into_frame(PCB *pcb, PAGE_ENTRY *page, int page_id) {
  int free_frame = -1;
  int i = 0;
  
  for (i = 0; i < MAX_FRAME; ++i) {
    FRAME *frame = &(Frame_Tbl[i]);
    if (frame->free && frame->lock_count == 0) {
      free_frame = i;
      break;
    }
  }
  
  siodrum(read, pcb, page_id, free_frame);
  
  FRAME *frame = &(Frame_Tbl[free_frame]);
  frame->free = false;
  frame->pcb = pcb;
  frame->page_id = page_id;
  
  page->frame_id = free_frame;
  page->valid = true;
  page->ref = true;
}

PRIVATE
void page_demon() {
  // Do nothing with an empty list.
  if (current == NULL) {
    return;
  }
  
  int removed = 0;
  
  while (removed < LOTS_FREE) {
    PAGE_ENTRY *page = current->page;
    
    if (page->ref) {
      page->ref = false;
      current = current->next;
    } else {
      FRAME *frame = &(Frame_Tbl[page->frame_id]);
      if (frame->lock_count == 0) {
        // Copy frame to memory.
        if (frame->dirty) {
          siodrum(write, frame->pcb, frame->page_id, page->frame_id);
          frame->dirty = false;
        }
        
        // Make frame free for other processes.
        page->valid = false;
        frame->free = true;
        frame->pcb = NULL;
        frame->page_id = -1;
        
        ++removed;
        list_remove(); // current is updated here
      } else {
        // If we don't do list_remove(), we need to update current manually
        current = current->next;
      }
    }
  }
}

PRIVATE
void list_insert(PAGE_ENTRY *page) {
  LIST_ITEM *item = (LIST_ITEM*) malloc(sizeof(LIST_ITEM));
  item->page = page;
  item->next = NULL;
  item->prev = NULL;
  
  if (current == NULL) {
    item->next = item;
    item->prev = item;
    current = item;
  } else {
    LIST_ITEM *ahead = current->next;
    LIST_ITEM *behind = current;
    
    item->next = ahead;
    item->prev = behind;
    
    ahead->prev = item;
    behind->next = item;
    
    current = item;
  }
}


PRIVATE
void list_remove() {
  if (current == NULL) {
    return;
  } else if (current->next == current) {
    free(current);
    current = NULL;
  } else {
    LIST_ITEM *ahead = current->next;
    LIST_ITEM *behind = current->prev;
    
    behind->next = ahead;
    ahead->prev = behind;
    free(current);
    
    current = ahead;
  }
}

/**************************************************************************/
/*                    */
/*                  deallocate              */
/*                    */
/*   Description : The job is history now so free the memory frames       */
/*                 occupied by the process.                     */
/*                 Set the pcb to NULL                                    */
/*                            */
/*   called by   : PROCSVC module                                         */
/*                    */
/**************************************************************************/
PUBLIC
deallocate(pcb)
PCB *pcb;
{
  if( current == NULL ){
    return;
  }

  int i;
  for( i=0; i < MAX_PAGE; ++i )
  {
    PAGE_ENTRY* page = &(pcb->page_tbl->page_entry[i]);
    if( !page->valid ){
      continue;
    }
    page->valid = false;
    page->ref = false;

    FRAME *frame = &(Frame_Tbl[page->frame_id]);
    
    frame->pcb = NULL;
    frame->page_id = -1;
    frame->dirty = false;
    
    if (frame->lock_count == 0) {
      frame->free = true;
    }

    // Removing page form the list
    LIST_ITEM* p = current;
    if (current->next == current) {
      free(current);
      current = NULL;
      return;
    } else {
      do {
        if (p->page == page) {
          LIST_ITEM *ahead = p->next;
          LIST_ITEM *behind = p->prev;

          behind->next = ahead;
          ahead->prev = behind;
          free(p);

          if (p == current) {
            current = ahead;
          }
        }
        p = p->next;
      } while ( p != current );

    }
  }
}
  

/************************************************************************/
/*                  */
/*       prepage            */
/*                  */
/*    Description : Swap the process specified in the argument from     */
/*                  drum/disk to main memory.                           */
/*              Will  use the prepaging policy.                     */
/*                    */
/*   called by    : CPU module            */
/*                  */
/************************************************************************/
PUBLIC
prepage(pcb)
PCB *pcb;
{
  /* Not part of lab. Leave empty  */
}   
           
/************************************************************************/
/*                  */
/*       start_cost           */
/*                  */
/*   called by    : CPU module            */
/*                  */
/************************************************************************/
PUBLIC
int start_cost(pcb)
PCB *pcb;
{
  /* Not part of lab. Leave empty  */
}   

 
/***************************************************************************/
/*                     */
/*        refer                    */
/*                     */
/*  Description : Called by SIMCORE module to simulate memory          */
/*          referencing by processes.                            */
/*                     */
/*      Called by   : SIMCORE module             */
/*                     */
/*  Call        : gen_int_handler()                  */
/*                    */
/*   You are not expected to change this routine                            */
/*                     */
/***************************************************************************/
PUBLIC
refer(logic_addr,action)
int          logic_addr;   /* logical address                              */
REFER_ACTION action;       /* a store operation will change memory content */
{
  int            job_size,
                 page_no,
                 frame_id;
  PAGE_TBL       *page_tbl_ptr;
  PCB            *pcb;
 
  if (PTBR != NULL)
    check_page_table(PTBR,1,"MEMORY.refer","","upon entering routine");

  pcb = PTBR->pcb;

  if (trace)
    printf("Hello refer(pcb: %d,logic_addr: %d,action: %d)\n",
          pcb->pcb_id,logic_addr,action);
  

  job_size = pcb->size;
  page_tbl_ptr = get_page_tbl(pcb); /* macro */

  if (logic_addr < MAX_SIZE && logic_addr < job_size && logic_addr >= 0){

       page_no = logic_addr / PAGE_SIZE;

       if (page_tbl_ptr->page_entry[page_no].valid == false) {
          /* page fault                                             */
          /* set interrupt vector Int_Vector to indicate page fault */
          /* call interrupt handler                                 */
       
          Int_Vector.pcb = pcb;
          Int_Vector.page_id = page_no;
          Int_Vector.cause   = pagefault;
          gen_int_handler();
       }

       page_tbl_ptr->page_entry[page_no].ref = true;

       if (( page_tbl_ptr->page_entry[page_no].valid == true) &&
                 (action == store)) {

         frame_id = page_tbl_ptr->page_entry[page_no].frame_id;
         set_frame_dirty(frame_id); /* macro */

       }

  }
  else {
    printf("CLOCK> %6d#*** ERROR: MEMORY.refer>\n\t\tPCB %d: Invalid address passed to refer(%d, ...)\n\n\n",
        get_clock(),pcb->pcb_id,logic_addr);
    print_sim_frame_tbl();
    osp_abort();
  }

} 


/*************************************************************************/
/*                   */
/*      lock_page          */
/*                   */
/*  Description:   To lock the chunk of memory mentioned in iorb     */
/*           to protect it from being swapped out.             */
/*                   */
/*  Called by  :   DEVICES module          */
/*                                                                       */
/*      call       :   gen_int_handler in INTER module                   */
/*                     lock_frame                                        */
/*                    */
/*   You are not expected to change this routine                            */
/*                   */
/*************************************************************************/
PUBLIC
lock_page(iorb)
IORB *iorb;
{
   int           page_id ;
   int           frame_id;
   PAGE_TBL      *page_tbl_ptr;

    if (trace)
        printf("Hello lock_page(iorb). The pcb is %d\n",iorb->pcb->pcb_id);

    check_iorb(iorb,1,"MEMORY.lock_page","","upon entering routine");

    page_tbl_ptr = get_page_tbl(iorb->pcb); /* macro */
    page_id      =  iorb->page_id;

    if (page_tbl_ptr->page_entry[page_id].valid == false) {
       
          Int_Vector.pcb = iorb->pcb;
          Int_Vector.page_id = page_id;
          Int_Vector.cause   = pagefault;
          gen_int_handler();
    }

    frame_id = page_tbl_ptr->page_entry[page_id].frame_id;


    if (iorb->action == read)
        set_frame_dirty(frame_id);  /* macro */
    lock_frame(frame_id); /* macro */
 } 


/*************************************************************************/
/*                                                                       */
/*              unlock_page()                                            */
/*                                                                       */
/*          description : Unlocked the page which has finished I/O       */
/*                                                                       */
/*          Called by   : DEVICES module                                 */
/*                                                                       */
/*          Call        : unlock_frame                                   */
/*                    */
/*   You are not expected to change this routine                            */
/*                                                                       */
/*************************************************************************/
PUBLIC
unlock_page(iorb)
IORB *iorb;
{
   int              page_id ;
   int              frame_id;
   PAGE_TBL        *page_tbl_ptr;

   if (trace)
       printf("Hello unlock_page(iorb). The pcb is %d\n",iorb->pcb->pcb_id);

   check_iorb(iorb,1,"MEMORY.unlock_page","","upon entering routine");

   page_tbl_ptr = get_page_tbl(iorb->pcb);  /* macro */
   page_id      = iorb->page_id;
   frame_id = page_tbl_ptr->page_entry[page_id].frame_id;


   unlock_frame(frame_id);  /* macro */

} 

/****************************************************************************/
/*                      */
/*      print_page_tbl              */
/*                      */
/*  Description : Print the page table of a process.        */
/*                    For debugging purpose                                 */
/*                      */
/****************************************************************************/


print_page_tbl(page_tbl_ptr)
PAGE_TBL   *page_tbl_ptr;
{
  int i;

  printf("\n\n");
  for (i=0; i<MAX_PAGE; i++)
        printf("pg=%d    valid=%d  ref=%d  frame=%d\n",
                i, page_tbl_ptr->page_entry[i].valid,
                page_tbl_ptr->page_entry[i].ref,
                page_tbl_ptr->page_entry[i].frame_id);

  printf("\n\n");
}

