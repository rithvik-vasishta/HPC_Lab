#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int n=3;
int main(int argc, char** argv){
	int i, j, k, chunk = 1, tid;
	int a[n][n], b[n][n], c[n][n];
#pragma omp parallel shared(a, b, c, chunk) private(i, j, k, tid)
	{
		tid = omp_get_thread_num();
		if(tid == 0){
			printf("\nStarting with %d Threads", omp_get_num_threads());
		}
#pragma omp for schedule(static, chunk)
		for(i=0; i<n; i++){
			//printf("\nThread[%d] initialising Matrix A:", tid);
			for(j=0; j<n; j++){
				 printf("\nThread[%d] initialising Matrix A:", tid);
				a[i][j] = i+j;}
		}
#pragma omp for schedule(static, chunk)
		for(i=0; i<n; i++){
			//printf("\nThread[%d] initialising Matrix B:", tid);
			for(j=0; j<n; j++){
				printf("\nThread[%d] initialising Matrix B:", tid);
				b[i][j]=i+j;}
		}
#pragma omp for schedule(static, chunk)
		for(i=0; i<n; i++){
			//printf("\nThread[%d] initia;ising Matrix C:", tid);
			for(j=0; j<n; j++){
				printf("\nThread[%d] initia;ising Matrix C:", tid);
				c[i][j] = 0;}
		}
#pragma omp for schedule(static, chunk)
		for(i=0; i<n; i++){
			printf("\nThread[%d] Calculating product", tid);
			for(j=0; j<n; j++)
				for(k=0; k<n; k++)
					c[i][j] += a[i][k]*b[k][j];
		}
	}
	printf("\nMATRIX A\n");
	for(i=0; i<n; i++){                                                                                                                                                   for(j=0; j<n; j++)                                                                                                                                                    printf("%d\t", a[i][j]);                                                                                                                              printf("\n");                                                                                                                                         } 
	printf("\nMATRIX B\n");
	for(i=0; i<n; i++){                                                                                                                                                   for(j=0; j<n; j++)                                                                                                                                                    printf("%d\t", b[i][j]);                                                                                                                              printf("\n");                                                                                                                                         } 
	printf("\nRESULT\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			printf("%d\t", c[i][j]);
		printf("\n");
	}
	return 0;
}

