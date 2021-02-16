#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char** argv){
	int rank, i;
	char msg[20];
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(rank == 0)
		strcpy(msg, "HELLO");
	MPI_Bcast(msg, 20, MPI_CHAR, 0, MPI_COMM_WORLD);
	printf("In process %d received msg: %s\n", rank, msg);
	MPI_Finalize();
	return 0;
}
