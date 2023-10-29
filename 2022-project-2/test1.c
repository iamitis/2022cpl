//
// Created by 10054 on 2023/2/7.
//
#include "D:\cpl\ramfs\ramfs.h"
#include "D:\cpl\ramfs\ramfs.c"
#include <assert.h>
#include <string.h>

int main() {
    init_ramfs();
    assert(rmkdir("/dir") == 0);
    assert(rmkdir("//dir") == -1);
    assert(rmkdir("/a/b") == -1);
    int fd;
    assert((fd = ropen("//dir///////1.txt", O_CREAT | O_RDWR)) >= 0);
    assert(rwrite(fd, "hello", 5) == 5);
    assert(rseek(fd, 0, SEEK_CUR) == 5);
    assert(rseek(fd, 0, SEEK_SET) == 0);
    char buf[10];
    assert(rread(fd, buf, 7) == 5);
    assert(memcmp(buf, "hello", 5) == 0);
    assert(rseek(fd, 3, SEEK_END) == 8);
    assert(rwrite(fd, "world", 5) == 5);
    assert(rseek(fd, 5, SEEK_SET) == 5);
    assert(rread(fd, buf, 8) == 8);
    assert(memcmp(buf, "\0\0\0world", 8) == 0);
    assert(rclose(fd) == 0);
    assert(rclose(fd + 1) == -1);
    return 0;
}
