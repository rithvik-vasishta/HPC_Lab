#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 __global__ void vecAdd(double *a, double *b, double *c, int n){
     int id = blockIdx.x*blockDim.x + threadIdx.x;
     if(id<n){
         c[id] = a[id] + b[id];
     }
 }

 int main(int argc, char** argv){
     int i, n = 100;
     double *ha, *hb, *hc, *a, *b, *c;
     int bytes = sizeof(double)*n;
     ha = (double*)malloc(bytes);
     hb = (double*)malloc(bytes);
     hc = (double*)malloc(bytes);
     cudaMalloc(&a, bytes);
     cudaMalloc(&b, bytes);
     cudaMalloc(&c, bytes);
     for(i=0; i<n; i++){
         ha[i] = hb[i] = rand()%50;
     }
     cudaMemcpy(a, ha, bytes, cudaMemcpyHostToDevice);
     cudaMemcpy(b, hb, bytes, cudaMemcpyHostToDevice);
     int blocksize, gridsize;
     blocksize = 1024;
     gridsize = (int)ceil((float)n/blocksize);
     vecAdd<<<gridsize, blocksize>>>(a, b, c, n);
     cudaMemcpy(hc, c, bytes, cudaMemcpyDeviceToHost);
     for(i=0; i<n; i++){
         printf("%f + %f = %f\n", ha[i], hb[i], hc[i]);
     }
     printf("\nDONE\n");
     return 0;
 }