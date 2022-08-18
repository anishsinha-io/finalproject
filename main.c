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

//void task(void *arg) {
//    printf("Thread #%u working on %d\n", (int) pthread_self(), (int) arg);
//}

int main() {
    test_strings();
    test_slice();
    test_ioutil();
    test_stack();
    test_b_link_tree();
    return 0;
}
