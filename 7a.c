#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int a, b;
#pragma omp threadprivate(a)
int main(int argc, char** argv){
	printf("\nA is thread pvt, b is just pvt\n");
#pragma omp parallel private(b)
	{
		a = 100;
		b = 200;
		printf("\nIn Region 1 Thread[%d], a = %d, b = %d\n", omp_get_thread_num(), a, b);
	}
#pragma omp parallel private(b)
	{
		printf("\nIn Region 2 Thread[%d], a = %d, b = %d\n", omp_get_thread_num(), a, b);
	}
	printf("\nA persists, B doesnt");
	return 0;
}
