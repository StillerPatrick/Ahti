#pragma once

#include <vector>
#include <complex>
#include <algorithm>
#include <fftw3.h>
#include <stdlib.h>
#include <array>

#include "hdf5.h"
#include "hdf5_hl.h"


#include "grid/Grid.hpp"
#include "grid/LocalGrid.hpp"
#include "math/CoeffEv.hpp"
#include "math/FourierCoeff.hpp"
#include "math/ValsEv.hpp"
#include "math/ScalarProd.h"
#include "math/TimeFt.h"
#include "math/RecontructWV.hpp"
#include "solvers/StaticCalcs1D.hpp"
#include "output/SaveStep.hpp"
#include "output/SaveCoeff.hpp"
#include "../containers/Array1D.hpp"
#include <iostream>

namespace solvers
{
    using std::complex;
    using std::vector;
    using Grid::LocalGrid;
    using Grid::Grid;
    using containers::Array1D;

    template <typename DIST, typename POT>
    void solve(Grid<1> g, DIST psi, POT V, int num_threads)
    {

        Array1D<fftw_complex > psi_rs(g.nx);
        Array1D<fftw_complex > psi_ks(g.nx);

        //init_psi(g, psi, psi_rs);

        //init_psi(g, [](double x){ return std::complex<double>(0,0);}, psi_ks);

        fftw_init_threads();

        //auto a = psi_ks.get_raw_ptr();
        fftw_plan_with_nthreads(num_threads);
        psi_ks.get(0);
        //fftw_plan ft = fftw_plan_dft_1d(g.nx, psi_rs.get_raw_ptr(), psi_ks.get_raw_ptr(), FFTW_FORWARD, FFTW_MEASURE);
        //fftw_plan ift = fftw_plan_dft_1d(g.nx, psi_ks.get_raw_ptr(), psi_rs.get_raw_ptr(), FFTW_BACKWARD, FFTW_MEASURE);



    }
}
