#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define RDTSC(U, L) asm ("rdtsc; mov %%edx, %0; mov %%eax, %1;":"=r"(U),"=r"(L)::"%edx", "%eax");   

int main() {
    int u1, l1, u2, l2;
    long ret;
    RDTSC(u1, l1);
    ret = syscall(295);
    RDTSC(u2, l2);
    printf("%ld %d %d %d\n", ret, u2-u1, l2-l1, errno);
    return 0;
}