#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv){
	int tid;
	tid = omp_get_thread_num();
	if(tid == 0){
		printf("In master\n");
		printf("Number of threads %d\n", omp_get_num_threads());
		printf("Maximum threads %d\n", omp_get_max_threads());
		printf("Threads in parallel %d\n", omp_in_parallel());
		printf("Is dynamic? %d\n", omp_get_dynamic());
		printf("Is nested? %d\n", omp_get_nested());
	}
	return 0;
}
