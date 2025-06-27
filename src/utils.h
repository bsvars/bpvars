#ifndef _UTILS_H_
#define _UTILS_H_

#include <RcppArmadillo.h>

arma::mat tcube_to_mat_by_slices (
    arma::cube  Y             // TRANSPOSED cube (T,N,C_g) - not (N,T,C_g) - to use reshape
);


int sample_arma (
    arma::vec y,
    arma::vec probabilities
);


#endif  // _UTILS_H_
