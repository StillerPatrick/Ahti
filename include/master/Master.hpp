#pragma once

#include "grid/Localgrid.hpp"
#include "grid/GridControl.hpp"

namespace Master {

    using namespace Grid;

    void start_master(  MPI_Datatype* LGrid1D,
                        MPI_Datatype* TimeType,
                        Sim1D* params,
                        int mpi_size,
                        int mpi_id
                        )
                        {

                            Localgrid1D mlgrid = *create_Localgrid1D(0,0,0);
                            control_sim_init( params, mpi_size, mpi_id, LGrid1D, &mlgrid);
                            printf("Rank %i, nx = %i, xmax = %i, xmin = %i \n", mpi_id, mlgrid.nx, mlgrid.xmax, mlgrid.xmin);

						}

}