#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv){
	int i, src, dst, tmp, rank, nprocs;
	int s=0;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(rank == 0){
		for(i=1; i<nprocs; i++){
			src = i;
			MPI_Recv(&tmp, 1, MPI_INT, src, 0, MPI_COMM_WORLD, &status);
			s += tmp;
			printf("In master process: sum to %d is %d\n", i, s);
		}
	}
	else{
		dst=0;
		MPI_Send(&rank, 1, MPI_INT, dst, 0, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}
