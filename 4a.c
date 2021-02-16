#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n = 3;
int main(int argc, char** argv){
	int tid, nthreads, i, j, k, chunk = 10;
	double a[n][n], b[n][n], c[n][n];
#pragma omp parallel shared(a, b, c, chunk) private(i, tid)
	{
		tid = omp_get_thread_num();
		if(tid == 0){
			printf("\nStarting with %d threads\n", omp_get_num_threads());
		}
#pragma omp for schedule(static, chunk)
		for(i=0; i<n; i++){
			printf("\nThread [%d] initialising Matrix A:", tid);
			for(j=0; j<n; j++)
				a[i][j] = i+j;
		}
#pragma omp for schedule(static, chunk) 
		for(i=0; i<n; i++){                                                                                                                                                   printf("\nThread [%d] initialising Matrix B:", tid);                                                                                                          for(j=0; j<n; j++)                                                                                                                                                    b[i][j] = i+j;
		}    
#pragma omp for schedule(static, chunk)
		for(i=0; i<n; i++){
			printf("\nThread [%d] initialising Matrix X:", tid);
			for(j=0; j<n; j++)
				c[i][j] = 0;
		}
#pragma omp for schedule(static, chunk)
		for(i=0; i<n; i++){
			printf("\nThread [%d] calculating product", tid);
			for(j=0; j<n;j++)
				for(k=0; k<n; k++)
					c[i][j] += a[i][k]*b[k][j];
		}
	}
	printf("\n\nResult:\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%f\t", c[i][j]);
		printf("\n");
	}
	return 0;
}	
