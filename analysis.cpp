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

#include "analysis.hpp"

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <cmath>

#include <boost/filesystem/path.hpp>

#define EIGEN_NO_AUTOMATIC_RESIZING
#include <eigen3/Eigen/Core>

#include "fptype.hpp"
#include "lattice.hpp"
#include "mccrun_prepare.hpp"

using namespace std;
namespace fs = boost::filesystem;


void analysis_static_structure_factor(
  const Options& opts, const MCCResults& res )
{
  cout << ":: Calculating static structure factor" << endl;

  // check if we have the required data
  if ( !res.nncorr ) {
    cout << "ERROR: Calculation of the static structure factor requires "
            "measurements of the density density correlation, but no such data "
            "was found in the result file" << endl;
    return;
  }
  const Eigen::VectorXfp& nn = res.nncorr.get();

  // make lattice and all the q vectors that we will use in the Fourier transform
  const shared_ptr<Lattice>& lat = prepare_lattice( opts );
  const vector<Eigen::VectorXfp>& allq = lat->get_qvectors();

  // open a file to output our results to
  ofstream ssfac_file( (
    opts["calc.working-dir"].as<fs::path>() / "ana_ssfac.txt"
  ).string() );

  for ( auto q = allq.begin(); q != allq.end(); ++q ) {
    fptype sum = 0.f;
    for ( unsigned int l = 0; l < lat->L; ++l ) {
      for ( unsigned int k = l + 1; k < lat->L; ++k ) {
        sum += cos( q->dot( lat->r( 0, k ) - lat->r( 0, l ) ) ) * nn( l, k);
      }
    }
    const fptype Nq = 2.f / static_cast<fptype>( lat->L ) * sum;
    ssfac_file << q->transpose() << " " << Nq << endl;
    if ( opts.count("verbose") ) {
      cout << q->transpose() << " " << Nq << endl;
    }
  }
}
