#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int a, b;
#pragma omp threadprivate(a)
int main(){
	int tid;
#pragma omp parallel private(b)
	{
		a=100;
		b=200;
		printf("\nIn Region 1 thread[%d]: a=%d, b=%d", omp_get_thread_num(), a, b);
	}
#pragma omp parallel private(b)
	{
		printf("\nIn region 2 thread[%d]:a=%d, b=%d\n", omp_get_thread_num(), a, b);
	}
	return 0;
}
