#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define RDTSC(U, L) asm volatile ("rdtsc; mov %%edx, %0; mov %%eax, %1;":"=r"(U),"=r"(L)::"%edx", "%eax");  // ASM for reading TSC register

int main() {
    int u1, l1, u2, l2;
    long ret, nc;
    char* p = (char *) malloc(MEM); // Allocating memory
    memset(p, 1, MEM);

    for(int i=0; i<ITER; i++) {

        RDTSC(u1, l1);
        ret = syscall(335); // System call. 335 is the my_precious call number for x86-64
        RDTSC(u2, l2);

        nc = (((long) (u2-u1)) << 32) | (l2-l1); // Get no. of cycles

        printf("%d %ld %ld %d\n", i, ret, nc, errno);
    }
    return 0;
}