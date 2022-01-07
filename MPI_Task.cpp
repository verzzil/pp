#include <iostream>
#include "mpi.h"

int main(int args, char **argv)
{
    int rank;
    MPI_Status status;
    MPI_Init(&args, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int a[5];
    a[0] = 10;
    a[1] = rank;
    if(rank == 1)
        MPI_Send(&a[1],1,MPI_INT,0,99,MPI_COMM_WORLD);
    else {
        MPI_Recv(&a[0],1,MPI_INT,1,99,MPI_COMM_WORLD,&status);
        std::cout << a[0];
    }
    MPI_Finalize();
}

int main3(int argc, char **argv)
{
    int size, rank;

    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    if(rank % 2 == 0) {
        std::printf("Proccess %d is not even\n",rank);
    } else {
        std::printf("Proccess %d is even\n",rank);
    }

    std::printf("Total processes number %d", size);
    MPI_Finalize();
}
