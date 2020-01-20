#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define RDTSC(U, L) asm ("rdtsc; mov %%edx, %0; mov %%eax, %1;":"=r"(U),"=r"(L)::"%edx", "%eax");   

int main() {
    int u1, l1, u2, l2;
    long ret, nc;
    char* p = (char *) malloc(MEM);
    memset(p, 1, MEM);

    for(int i=0; i<ITER; i++) {

        RDTSC(u1, l1);
        ret = syscall(335);
        RDTSC(u2, l2);

        nc = (((long) (u2-u1)) << 31) + (l2-l1);

        printf("%d %ld %ld %d\n", i, ret, nc, errno);
    }
    return 0;
}