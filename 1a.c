#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	int i, n = 100;
	int chunk = 10;
	int a[n],b[n],c[n];
	int tid;
	for(i=0; i<n; i++){
		a[i] = b[i] = 10*i;
	}
#pragma omp parallel shared(a, b, c, chunk) private(i, tid)
	{
		tid = omp_get_thread_num();
		if(tid == 0){
			printf("Starting with %d Threads\n", omp_get_num_threads());
		}
#pragma omp for schedule(dynamic, chunk)
		for(i=0; i<n; i++){
			printf("Thread %d at index %d\n", tid, i);
			c[i] = a[i] + b[i];
		}
	}
	printf("\nOUTPUT\n");
	for(i=0;i<n;i++){
		printf("%d + %d = %d\n", a[i], b[i], c[i]);
	}
	return 0;
}
