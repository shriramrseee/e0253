#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define RDTSC(U, L) asm ("rdtsc; mov %%edx, %0; mov %%eax, %1;":"=r"(U),"=r"(L)::"%edx", "%eax"); 

int main() {
    int u1, l1, u2, l2, pid;
    long nc; 
    char* p = (char *) malloc(MEM);
    memset(p, 1, MEM);

    for(int i=0; i<ITER; i++) {

        RDTSC(u1, l1);
        pid = fork();
        RDTSC(u2, l2);

        nc = (((long) (u2-u1)) << 31) + (l2-l1);

        if(pid == -1)
            return -1;
        else if(pid == 0) {
            printf("%d %ld \n", i, nc);
            exit(0);
        }        
        else {
            printf("%d %ld \n", i, nc);
            wait(NULL);
        }
    }
        
    return 0;
}