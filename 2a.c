#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv){
	int i, tid, n=100, chunk=10;
	int a[n], b[n], c[n], d[n];
	for(i=0; i<n; i++)
		a[i] = b[i] = rand()%50;
	#pragma omp parallel shared(a, b, c, d, n) private(i, tid)
	{
		tid = omp_get_thread_num();
		if(tid == 0)
			printf("\nStarting with %d threads\n", tid);
#pragma omp sections nowait
		{
#pragma omp section
			for(i=0; i<n; i++)
			{
				printf("Thread[%d] doinf c=a+b\n", tid);
				c[i]=a[i]+b[i];
			}
#pragma omp section
			for(i=0; i<n; i++)
			{
				printf("Thread[%d] doing d=a-b\n", tid);
				d[i]=a[i]-b[i];
			}
		}
	}
	printf("\nDONE\n");
	for(i=0; i<n; i++)
		//printf("%d+%d=%d\t%d-%d=%d\n", a[i], b[i], c[i], a[i], b[i], d[i]);
	return 0;
}	
