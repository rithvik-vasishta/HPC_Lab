#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv){
	int n=10, fact1 = 1, fact2 = 1, f1=1, f2=2;
	int i;
#pragma omp parallel for private(f1) shared(n, fact1)
	
	for(i=f1; i<=n; i++){
		#pragma omp critical
			fact1 *= i;
		}
	
	printf("\nFactorial(10) with private: %d\n", fact1);
#pragma omp parallel for firstprivate(f2) shared(n, fact2)
	for(i=f2; i<=n; i++){
		#pragma omp critical
		fact2 *= i;
	}
	printf("\nFactorial(10) with firstprivate: %d\n", fact2);
	return 0;
}

