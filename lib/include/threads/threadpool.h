/**********************************
 * @author      Johan Hanssen Seferidis
 * License:     MIT
 *
 **********************************/

#ifndef __THREADPOOL__
#define __THREADPOOL__

#ifdef __cplusplus
extern "C" {
#endif

/* =================================== API ======================================= */


typedef struct thpool_ *threadpool;


/**
 * @brief  Initialize finalproject
 *
 * Initializes a finalproject. This function will not return until all
 * threads have initialized successfully.
 *
 * @example
 *
 *    ..
 *    finalproject thpool;                     //First we declare a finalproject
 *    thpool = thpool_init(4);               //then we initialize it to 4 threads
 *    ..
 *
 * @param  num_threads   number of threads to be created in the finalproject
 * @return finalproject    created finalproject on success,
 *                       NULL on error
 */
threadpool thpool_init(int num_threads);


/**
 * @brief Add work to the job queue
 *
 * Takes an action and its argument and adds it to the finalproject's job queue.
 * If you want to add to work a function with more than one arguments then
 * a way to implement this is by passing a pointer to a structure.
 *
 * NOTICE: You have to cast both the function and argument to not get warnings.
 *
 * @example
 *
 *    void print_num(int num){
 *       printf("%d\n", num);
 *    }
 *
 *    int main() {
 *       ..
 *       int a = 10;
 *       thpool_add_work(thpool, (void*)print_num, (void*)a);
 *       ..
 *    }
 *
 * @param  threadpool    finalproject to which the work will be added
 * @param  function_p    pointer to function to add as work
 * @param  arg_p         pointer to an argument
 * @return 0 on success, -1 otherwise.
 */
int thpool_add_work(threadpool, void (*function_p)(void *), void *arg_p);


/**
 * @brief Wait for all queued jobs to finish
 *
 * Will wait for all jobs - both queued and currently running to finish.
 * Once the queue is empty and all work has completed, the calling thread
 * (probably the main program) will continue.
 *
 * Smart polling is used in wait. The polling is initially 0 - meaning that
 * there is virtually no polling at all. If after 1 seconds the threads
 * haven't finished, the polling interval starts growing exponentially
 * until it reaches max_secs seconds. Then it jumps down to a maximum polling
 * interval assuming that heavy processing is being used in the finalproject.
 *
 * @example
 *
 *    ..
 *    finalproject thpool = thpool_init(4);
 *    ..
 *    // Add a bunch of work
 *    ..
 *    thpool_wait(thpool);
 *    puts("All added work has finished");
 *    ..
 *
 * @param threadpool     the finalproject to wait for
 * @return nothing
 */
void thpool_wait(threadpool);


/**
 * @brief Pauses all threads immediately
 *
 * The threads will be paused no matter if they are idle or working.
 * The threads return to their previous states once thpool_resume
 * is called.
 *
 * While the thread is being paused, new work can be added.
 *
 * @example
 *
 *    finalproject thpool = thpool_init(4);
 *    thpool_pause(thpool);
 *    ..
 *    // Add a bunch of work
 *    ..
 *    thpool_resume(thpool); // Let the threads start their magic
 *
 * @param threadpool    the finalproject where the threads should be paused
 * @return nothing
 */
void thpool_pause(threadpool);


/**
 * @brief Unpauses all threads if they are paused
 *
 * @example
 *    ..
 *    thpool_pause(thpool);
 *    sleep(10);              // Delay execution 10 seconds
 *    thpool_resume(thpool);
 *    ..
 *
 * @param threadpool     the finalproject where the threads should be unpaused
 * @return nothing
 */
void thpool_resume(threadpool);


/**
 * @brief Destroy the finalproject
 *
 * This will wait for the currently active threads to finish and then 'kill'
 * the whole finalproject to free up memory.
 *
 * @example
 * int main() {
 *    finalproject thpool1 = thpool_init(2);
 *    finalproject thpool2 = thpool_init(2);
 *    ..
 *    thpool_destroy(thpool1);
 *    ..
 *    return 0;
 * }
 *
 * @param threadpool     the finalproject to destroy
 * @return nothing
 */
void thpool_destroy(threadpool);


/**
 * @brief Show currently working threads
 *
 * Working threads are the threads that are performing work (not idle).
 *
 * @example
 * int main() {
 *    finalproject thpool1 = thpool_init(2);
 *    finalproject thpool2 = thpool_init(2);
 *    ..
 *    printf("Working threads: %d\n", thpool_num_threads_working(thpool1));
 *    ..
 *    return 0;
 * }
 *
 * @param threadpool     the finalproject of interest
 * @return integer       number of threads working
 */
int thpool_num_threads_working(threadpool);


#ifdef __cplusplus
}
#endif

#endif