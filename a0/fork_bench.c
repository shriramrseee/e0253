#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define RDTSC(U, L) asm ("rdtsc; mov %%edx, %0; mov %%eax, %1;":"=r"(U),"=r"(L)::"%edx", "%eax");   

int main() {
    int u1, l1, u2, l2;
    int pid=1; 
    // printf("Parent PID: %d \n", getpid());
    RDTSC(u1, l1);
    pid = fork();
    RDTSC(u2, l2);
    if(pid == -1)
        return -1;
    else if(pid == 0) {
        // printf("I am Child! \n");
        printf("%d %d \n", u2-u1, l2-l1);
    }        
    else {
        // printf("Child PID: %d \n", pid);
        printf("%d %d \n", u2-u1, l2-l1);

    }
        
    return 0;
}