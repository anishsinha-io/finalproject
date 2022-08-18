#ifndef __ERRORS
#define __ERRORS

#include <errno.h>
#include <stdbool.h>

#include "strings.h"

typedef int        (*cmpfunc)(const void *, const void *);

typedef int        (*hashfunc)(const void *);

typedef bool       (*validator)(const void *);

typedef string *(*to_string)(const void *);

#define err_abort(code, text) do { \
    fprintf(stderr, "%s at \"%s\":%d: %s\n", \
    text, __FILE__, __LINE__, strerror(code));\
                                 abort();  \
                                   \
} while(0)

#define errno_abort(text) do { \
    fprintf(stderr, "%s at \"%s\": %d: %s\n", text, __FILE__, __LINE__, strerror(errno)); abort();                            \
} while(0)

#endif