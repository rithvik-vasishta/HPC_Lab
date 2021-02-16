#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char** argv){
	int numprocs, rank, i;
	char msg[50];
	strcpy(msg, "HELLO");
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(rank == 3){
		for(i=0; i<numprocs; i++){
			if(i!=3){
				MPI_Send(msg, 50, MPI_CHAR, i, 0, MPI_COMM_WORLD);
			}
		}
	}
	else{
		MPI_Recv(msg, 50, MPI_CHAR, 3, 0, MPI_COMM_WORLD, &status);
		printf("Thread [%d] received message:%s\n", rank, msg);
	}
	MPI_Finalize();
	return 0;
}


