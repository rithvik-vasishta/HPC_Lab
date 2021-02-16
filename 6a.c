#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
	int n=100, i;
	int tid, a[n];
	for(i=0; i<100; i++)
		a[i] = rand()%50;
	int pmax = 0, smax = 0;
#pragma omp parallel shared(a, n) private(i, tid)
	{
		for(i=0; i<n; i++){
			printf("\nIn Thread [%d]\n", omp_get_thread_num());
		       	#pragma omp critical
			{
				printf("\nThread [%d] in critical section\n", omp_get_thread_num());
				if(a[i] > pmax)
					pmax = a[i];
			}
		}
	}
	for(i=0; i<n; i++)
		smax = (a[i] > smax)?a[i]:smax;
	printf("\nParallel and Serial Maximums: %d %d", pmax, smax);
	return 0;
}
