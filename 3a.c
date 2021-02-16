#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv){
	int i, n=1000;
	int a[n], b[n];
	for(i=0; i<n; i++)
		a[i] = b[i] = rand()%2;
	long long s =0;
#pragma omp parallel for reduction(+:s)
	for(i=0; i<n; i++){
		printf("\nThread %d at index %d\n",omp_get_thread_num(), i);
	       	s += (a[i] + b[i]);
	}
	printf("\nSum is: %lld", s);
	return 0;
}
