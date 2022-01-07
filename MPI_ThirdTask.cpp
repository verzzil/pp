#include "MPI_ThirdTask.h"
#include <iostream>
#include "mpi.h"

int main(int argc, char **argv)
{
    int rank, size;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    std::cout << "Общее число ПЭ" << size << " num " << rank << std::endl;
    MPI_Finalize();
    return 0;
}