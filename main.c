#include <stdio.h>

#include "laureates.h"
#include "strings.h"
#include "strings_test.h"
#include "collections/slice.h"
#include "collections/slice_test.h"
#include "io/ioutil.h"
#include "io/ioutil_test.h"
#include "collections/stack.h"
#include "collections/stack_test.h"
#include "main/b_link_tree.h"
#include "main/b_link_tree_test.h"
#include "threads/threadpool.h"
#include <pthread.h>

void task(void *arg) {
    printf("Thread #%u working on %d\n", (int) pthread_self(), (int) arg);
}

int main() {
    puts("Making finalproject with 4 threads");
    threadpool thpool = thpool_init(4);

    puts("Adding 40 tasks to finalproject");
    int i;
    for (i = 0; i < 40; i++) {
        thpool_add_work(thpool, task, (void *) (uintptr_t) i);
    };

    thpool_wait(thpool);
    puts("Killing finalproject");
    thpool_destroy(thpool);

    return 0;
}
