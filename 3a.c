#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv){
	int i, n=100;
	int a[n], b[n];
	long long s = 0;
	for(i=0; i<n; i++)
		a[i] = b[i] = 1;
#pragma omp parallel for reduction(+:s)
	for(i=0; i<n; i++){
		//printf("Thread[%d] handling index %d\n", omp_get_thread_num(), i);
		s+= (a[i]+b[i]);
	}
	printf("\nThe sum is %lld", s);
	return 0;
}
