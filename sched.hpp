/*
 * Copyright (c) 2013, Robert Rueger <rueger@itp.uni-frankfurt.de>
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

#ifndef SCHED_H_INCLUDED
#define SCHED_H_INCLUDED

#include <boost/mpi/communicator.hpp>

#include "options.hpp"


void sched_master(
  const Options& opts,
  const boost::mpi::communicator& mpicomm
);

void sched_slave(
  const Options& opts,
  const boost::mpi::communicator& mpicomm
);

#endif // SCHED_H_INCLUDED
