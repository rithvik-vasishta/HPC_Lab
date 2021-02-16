#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv){

	int tid, nthreads, procs, max_threads, inparallel, dynamic_flag, nested_flag;
#pragma omp parallel private(tid, nthreads)
	{
		tid = omp_get_thread_num();
		if(tid == 0){
			nthreads = omp_get_num_threads();
			procs = omp_get_num_procs();
			max_threads = omp_get_max_threads();
			inparallel = omp_in_parallel();
			dynamic_flag = omp_get_dynamic();
			nested_flag = omp_get_nested();
			printf("Number of Threads: %d\n", nthreads);
			printf("Number of processes: %d\n", procs);
			printf("Maximum threads: %d\n", max_threads);
			printf("Threads in Parallel: %d\n", max_threads);
			printf("Dynamic Flag: %d\n", dynamic_flag);
			printf("Nested Flag: %d\n", nested_flag);
		}
	}
	return 0;
}
