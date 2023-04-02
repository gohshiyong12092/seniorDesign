#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

#define STR(x) #x
#define XSTR(s) STR(s)

// _____________________________________________________________

// TODO: Modify these values to match desired behavior.

// Number of loops for 'loop1'
/* Try keeping this value high enough, so the signature is noticeable
and you can collect good data but not so high the it takes more than
like 3 seconds to execute. */
#define LOOPS 375000

// Number of times instructions are repeated
/* We want this value to be large so the number of instructions that
we want to test is significantly more than the instructions needed
to maintain the loop and register values. Although it cannot be too large
or it will take a long time to compile, and the out file will be very
large. */
#define REPEAT 300

/* The next two values are used to calculate the number of
instructions that are executed. */

// Number of repeated instructions
#define NUM_REPEAT 0

//Number of pre repeated instruction
#define NUM_PRE_REPEAT 0

// _____________________________________________________________

int main(int argc, const char **argv) {

    

    clock_t start, end;
    double elapsed_time_ms;

    start = clock();

    // _____________________________________________________________
    for (int i = 0; i < 25000000; i++){
        asm volatile(
        
        "vpbroadcastd %xmm0,%ymm0\n\t"
          "vpbroadcastd %xmm1,%ymm1\n\t"
          "vpbroadcastd %xmm2,%ymm2\n\t"
          "vpbroadcastd %xmm0,%ymm0\n\t"
          "vpbroadcastd %xmm1,%ymm1\n\t"
          "vpbroadcastd %xmm2,%ymm2\n\t"
        );
    }
    

    // _____________________________________________________________
    
    end = clock();    
    elapsed_time_ms = (double)(end - start) * 1000 / CLOCKS_PER_SEC;
    unsigned long total_inst = (LOOPS*NUM_PRE_REPEAT)+((unsigned long)LOOPS*REPEAT*NUM_REPEAT);
    double total_inst_mil = total_inst / 1000000;
    printf("%lf %lf\n", total_inst_mil, elapsed_time_ms); 

    
    return (0);
}

