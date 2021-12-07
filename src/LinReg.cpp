
#include <RcppArmadillo.h>

namespace LinRegNS {

    class rad_state {
    public:
        arma::vec theta; // (alpha,beta,phi)
    };

    class rad_obs {
    public:
        arma::vec y, x;
    };

    rad_obs data;
    double mean_x;
}

using namespace std;
using namespace LinRegNS;

// LinReg() function callable from R via Rcpp::
// [[Rcpp::export]]
Rcpp::List LinReg(arma::mat Data, unsigned long lNumber) {
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

