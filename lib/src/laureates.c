#include "laureates.h"

int read_laureate(laureate *buf, int loc) {
    off_t offset = (off_t) (sizeof(laureate) * (off_t) loc);
    int   fd     = open("/Users/anishsinha/Home/cprojects/finalproject/data/db.bin", O_RDONLY);
    pread(fd, buf, sizeof(laureate), offset);
    return 0;
}