#include<stdio.h>
#define NUM_BLOCKS 8
#define BLOCK_WIDTH 5
__global__ void hello(){
    printf("\nHello from Thread [%d] inside Block [%d]", threadIdx.x, blockIdx.x);
}
int main(){
    hello<<<NUM_BLOCKS, BLOCK_WIDTH>>>();
    cudaDeviceSynchronize();
    printf("\nDONE");
    return 0;
}