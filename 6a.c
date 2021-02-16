#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv){
	int i, n=100, a[n];
	int pmax = 0,smax = 0;
	for(i=0; i<n; i++)
		a[i]=rand()%50;
	#pragma omp parallel shared(a, n) private(i)
	for(i=0; i<n; i++){
#pragma omp critical
		{
			printf("\nthread [%d] entered critical section",omp_get_thread_num());
			if(a[i]>pmax)
				pmax=a[i];
		}
	}
	for(i=0; i<n; i++)
		smax = (a[i]>smax)?a[i]:smax;
	printf("\nParalle MAx:%d\nSerial Max:%d\n", pmax, smax);
	return 0;
}
