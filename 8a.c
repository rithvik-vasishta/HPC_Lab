#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	int f1=1, f2=1, fact1=1, fact2=1, i;
	int n=10;
#pragma omp parallel for private(f1) shared(n, fact1)
	for(i=f1; i<=n; i++){
#pragma omp critical
		fact1*=i;}
#pragma omp parallel for firstprivate(f2) shared(n, fact2)
	for(i=f2; i<=n; i++){
#pragma omp critical
		fact2*=i;}

	printf("\nPrivate fact(10) is %d\nFirst private fact(10) is %d\n",fact1, fact2);
       return 0;
}       
