/*
 * Copyright (c) 2012, Robert Rueger <rueger@itp.uni-frankfurt.de>
 *
 * This file is part of hVMC.
 *
 * hVMC is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * hVMC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with hVMC.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SIMRUN_H_INCLUDED
#define SIMRUN_H_INCLUDED

#include <boost/mpi/communicator.hpp>

#include "macros.h"
#include "fptype.hpp"

#include "hmodvmc.hpp"
#include "binstat.hpp"
#include "simresults.hpp"
#include "options.hpp"
#include "varparam.hpp"


BasicSimResults simrun_basic(
  const Options& opts, const VariationalParameters& vpar,
  const boost::mpi::communicator& mpiflock
);

void simrun_basic_prepare(
  const Options& opts, const VariationalParameters& vpar, HubbardModelVMC*& model,
  const boost::mpi::communicator& mpiflock
);

BinnedData<fptype> simrun_basic_mccycle(
  const Options& opts, HubbardModelVMC* const model,
  const boost::mpi::communicator& mpiflock
);

// TODO: simulation with more observables (Robert Rueger, 2012-11-12 15:21)
// FullSimResults simrun_full( const Options& opts );
// ...

#endif // SIMRUN_H_INCLUDED
