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

#ifndef DETERMINANTAL_WAVEFUNCTIONS_H_INCLUDED
#define DETERMINANTAL_WAVEFUNCTIONS_H_INCLUDED

#include <vector>

#include <eigen3/Eigen/Core>

#include "macros.h"
#include "fptype.hpp"
#include "lattice.hpp"


struct SingleParticleOrbitals {

  // the actual orbitals
  Eigen::MatrixXfp orbitals;

  // the associated energies
  Eigen::MatrixXfp energies;

  // spin symmetric and orbitals spin eigenstates
  bool ssym;

  SingleParticleOrbitals(
    const Eigen::MatrixXfp& orbitals_init,
    const Eigen::MatrixXfp& energies_init,
    bool ssym_init
  ) : orbitals( orbitals_init ), energies( energies_init), ssym( ssym_init ) { }
};


SingleParticleOrbitals wf_tight_binding(
    const std::vector<fptype>& t,
    unsigned int N, Lattice* lat
);

#endif // DETERMINANTAL_WAVEFUNCTIONS_H_INCLUDED
