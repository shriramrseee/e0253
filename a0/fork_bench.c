#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define RDTSC(U, L) asm ("rdtsc; mov %%edx, %0; mov %%eax, %1;":"=r"(U),"=r"(L)::"%edx", "%eax"); // ASM for reading TSC register

int main() {
    int u1, l1, u2, l2, pid;
    long nc; 
    char* p = (char *) malloc(MEM); // Allocating memory
    memset(p, 1, MEM);

    for(int i=0; i<ITER; i++) {

        RDTSC(u1, l1);
        pid = fork(); // System call
        RDTSC(u2, l2);

        nc = (((long) (u2-u1)) << 32) | (l2-l1); // Get no. of cycles

        if(pid == -1)
            return -1;
        else if(pid == 0) {
            printf("%d %ld \n", i, nc); // Print from child
            return 0;
        }        
        else {
            printf("%d %ld \n", i, nc); // Print from parent
            wait(NULL); // Wait for child
        }
    }
        
    return 0;
}