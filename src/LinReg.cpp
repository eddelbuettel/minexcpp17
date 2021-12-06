// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// LinReg.cpp: A simple example for estimating the parameters of a
// linear regression model using data annealing SMC.
//
// Copyright (C) 2017         Dirk Eddelbuettel, Adam Johansen and Leah South
//
// This file is part of RcppSMC.
//
// RcppSMC is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// RcppSMC is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with RcppSMC.  If not, see <http://www.gnu.org/licenses/>.

//#include "LinReg.h"
#include <RcppArmadillo.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>

#include <iostream>
#include <cmath>

namespace LinReg {

    class rad_state
    {
    public:
        arma::vec theta; // (alpha,beta,phi)
    };

    class rad_obs
    {
    public:
        arma::vec y, x;
    };

    rad_obs data;
    double mean_x;
	
}


namespace LinReg {
    arma::mat covRW("2500 -2.5 0.03; -2.5 130.0 0.0; 0.03 0.0 0.04");
    arma::mat cholCovRW = arma::chol(covRW);
    const double a_prior = 3.0;
    const double b_prior = std::pow(2.0*300.0*300.0,-1.0);
}

using namespace std;
using namespace LinReg;

// LinReg() function callable from R via Rcpp::
// [[Rcpp::export]]
Rcpp::List LinReg_impl(arma::mat Data, unsigned long lNumber) {
    // Load observations -- or rather copy them in from R
    long lIterates = Data.n_rows;
    data.y = Data.col(0);
    data.x = Data.col(1);
    mean_x = arma::sum(data.x)/lIterates;

    // stuff deleted
        
    arma::mat theta(lNumber,3);
    arma::vec weights = {1, 2, 3}; //Sampler.GetParticleWeight();
    
    return Rcpp::List::create(Rcpp::Named("theta") = theta,
                              Rcpp::Named("weights") = weights);
}

