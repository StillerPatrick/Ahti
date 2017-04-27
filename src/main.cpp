#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>



// Alpaka for Kernel Acceleration
#include <alpaka/alpaka.hpp>

// MPI
#include <mpi.h>




// Use useful debugging output
#define DEBUG_ENABLED
#include "debug/DebugDef.h"

#include "worker/Worker.hpp"

int
main(int argc, char **argv)
{


    int size;
    int rank;

    // MPI calls
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    
    auto in_fun = [](std::complex<double> x) {return std::exp(-x*x);};
    auto pot_fun = [](double x) {return x*x/2.0;};
    Grid::Grid<1> g(0.0, 100.0, 65536/4, 0.0, 20.0, 10);
    Worker::start_worker(g, size, rank, in_fun, pot_fun);
    
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();

    return EXIT_SUCCESS;

}
