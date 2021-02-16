#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define BLOCK_SIZE 3
int w=3, h=3;
int size = w*h;
int memsize = sizeof(float)*size;
__global__ void matrixMultiply(float *a, float *b, float *c, int w, int h){
    int tx = (blockIdx.x * blockDim.x) + threadIdx.x;
    int ty = (blockIdx.y * blockDim.y) + threadIdx.y;
    float v = 0;
    int i;
    for(i=0; i<w; i++){
        v+= a[ty*w + i]*b[i*h + tx];
    }
    c[ty*w + tx] = v;
}

void printMatrix(float *a){
    int i;
    for(i=0; i<size; i++){
        printf("%f\t", a[i]);
        if((i+1)%w == 0)
          printf("\n");
    }
}

int main(int argc, char** argv){
    float *ha, *hb, *hc, *a, *b, *c;
    int i;
    ha = (float*)malloc(memsize);
    hb = (float*)malloc(memsize);
    hc = (float*)malloc(memsize);
    
    for(i=0; i<size; i++)
      ha[i] = hb[i] = i;    
    printMatrix(ha);
    printMatrix(hb);
    cudaMalloc(&a, memsize);
    cudaMalloc(&b, memsize);
    cudaMalloc(&c, memsize);
    cudaMemcpy(a, ha, memsize, cudaMemcpyHostToDevice);
    cudaMemcpy(b, hb, memsize, cudaMemcpyHostToDevice);
    dim3 threads(BLOCK_SIZE, BLOCK_SIZE);
    dim3 grid(w/threads.x, h/threads.y);
    matrixMultiply<<<grid,threads>>>(a, b, c, w, w);
    cudaMemcpy(hc, c, memsize, cudaMemcpyDeviceToHost);
    printMatrix(hc);
    cudaFree(a);
    cudaFree(b);
    cudaFree(c);
    free(ha);
    free(hb);
    free(hc);
    printf("DONE");
    return 0;
}