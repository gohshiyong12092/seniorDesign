#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#ifdef _MSC_VER
#include <intrin.h> /* for rdtscp and clflush */
#pragma optimize("gt",on)
#else
#include <x86intrin.h> /* for rdtscp and clflush */
#endif
#include <unistd.h>
int main(){
    int scalar = 10;
    int result[8];

    __asm__ (
        "vpbroadcastd %0, %%ymm0\n\t"  // Broadcast scalar to YMM0
        "vmovdqa %%ymm0, %1\n\t"      // Move YMM0 to result array
        :                              // Output operands
        : "r" (scalar), "m" (result)   // Input operands
        : "%ymm0"                      // Clobbered registers
    );

    int i;
    for (i = 0; i < 8; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    return 0;
}