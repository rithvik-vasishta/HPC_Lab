#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv){
	int i, tid, n=100, chunk = 10;
	int a[n], b[n], c[n];
	for(i=0; i<n; i++)
		a[i] = b[i] = rand()%10;
#pragma omp parallel shared(a, b, c, chunk) private(i, tid)
	{
		tid = omp_get_thread_num();
		if(tid == 0){
			printf("Starting with %d threads\n", omp_get_num_threads());
		}
#pragma omp for schedule(dynamic, chunk)
		for(i=0; i<n; i++)
		{
			printf("Thread[%d] hadling %d index\n", tid, i);
			c[i] = a[i] + b[i];
		}
	}
	printf("Results:\n");
	for(i=0; i<n; i++)
		printf("%d + %d = %d\n", a[i], b[i], c[i]);
	printf("\nDONE\n");
	return 0;
}

