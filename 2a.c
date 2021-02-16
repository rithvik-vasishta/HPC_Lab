#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv){
	int SIZE = 100;
	int i, tid;
	int a[SIZE], b[SIZE], c[SIZE], d[SIZE];
	for(i=0; i<SIZE; i++){
		a[i] = b[i] = rand() % 50;
		//b[i] = rand() % 50;
		c[i] = d[i] = 0;
	}
#pragma omp parallel shared(a, b, c, d, SIZE) private(i, tid)
	{
		tid = omp_get_thread_num();
		if(tid == 0){
			printf("\nStarting with %d Threads\n", omp_get_num_threads());
		}
#pragma omp sections nowait
		{
#pragma omp section
			{
				for(i=0; i< SIZE; i++){
					c[i] = a[i] + b[i];
					printf("\nThread [%d] perfrming c[%d] = a[%d] + b[%d)", tid, i, i, i);
				}
			}
#pragma omp section
			{
				for(i=0; i< SIZE; i++){                                                                           d[i] = a[i] - b[i];                                                                       printf("\nThread [%d] perfrming d[%d] = a[%d] - b[%d)", tid, i, i, i);                                                                                                      }  
			}
		}
	}
	printf("\nDONE\n");
	printf("RESULTS");
	for(i=0; i<SIZE; i++){
		printf("%d + %d = %d\t%d - %d = %d\n", a[i], b[i], c[i], a[i], b[i], d[i]);
	}
	printf("\nDONE\n");
	return 0;
}
