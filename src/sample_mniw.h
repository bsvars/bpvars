#ifndef _SAMPLE_MNIW_H_
#define _SAMPLE_MNIW_H_

#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;


arma::field<arma::mat> rmniw1(
    const arma::mat& A,     // KxN
    const arma::mat& V,     // KxK
    const arma::mat& S,     // NxN
    const double&    nu     // scalar
);


arma::mat rmn1(
    const arma::mat& A,     // KxN
    const arma::mat& V,     // KxK
    const arma::mat& S      // NxN
);


double sample_m (
    const arma::mat&    aux_A,    // KxN
    const arma::mat&    aux_V,    // KxK
    const double&       aux_s,   // scalar
    const double&       aux_w,   // scalar
    const Rcpp::List&   prior
);


arma::vec sample_m_bvars (
    const arma::cube&   aux_A_c,    // KxNxC
    const arma::cube&   aux_Sigma_c_inv,    // KxKxC
    const arma::vec&    aux_w,   // scalar
    const Rcpp::List&   prior
);


double sample_m_gg (
    const arma::cube&   aux_A_g,    // KxNxG
    const arma::mat&    aux_V,    // KxK
    const double&       aux_s,   // scalar
    const Rcpp::List&   prior
);


double sample_w (
    const arma::mat&    aux_V,    // KxK
    const Rcpp::List&   prior
);


arma::vec sample_w_bvars (
    const arma::cube&   aux_A_c,          // KxNxC
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const arma::vec&    aux_m,
    const Rcpp::List&   prior
);


double sample_s (
    const arma::mat&    aux_A,      // KxN
    const arma::mat&    aux_V,      // KxK
    const arma::mat&    aux_Sigma,  // NxN
    const double&       aux_m,      // scalar
    const Rcpp::List&   prior
);


arma::vec sample_s_bvars (
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const arma::vec&    aux_nu,           // C
    const Rcpp::List&   prior
);


double sample_s_gg (
    const arma::cube&   aux_A_g,      // KxNxG
    const arma::cube&   aux_Sigma_g,  // NxNxG
    const arma::mat&    aux_V,      // KxK
    const double&       aux_m,      // scalar
    const Rcpp::List&   prior
);


double log_kernel_nu (
    const double&       aux_nu,           // scalar
    const arma::cube&   aux_Sigma_c_cpp,  // NxNxC
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const arma::mat&    aux_Sigma,        // NxN
    const double&       prior_lambda,     // scalar
    const int&          C,                // scalar
    const int&          N,                // scalar
    const int&          K                 // scalar
);


double log_kernel_nu_bvars (
    const double&       aux_nu,           // scalar
    const double&       aux_s,
    const arma::mat&    aux_Sigma_c_cpp,  // NxNxC
    const arma::mat&    prior_S,        // NxN
    const double&       prior_lambda,     // scalar
    const int&          N,                // scalar
    const int&          K                 // scalar
);


double log_kernel_nu_gg (
    const double&       aux_nu,           // scalar
    const arma::cube&   aux_Sigma_c_cpp,  // NxNxC
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const arma::cube&   aux_Sigma_g,      // NxNxG
    const double&       prior_lambda,     // scalar
    const arma::vec&    group_allocation, // C
    const int&          C,                // scalar
    const int&          N,                // scalar
    const int&          K                 // scalar
);


double cov_nu (
    const double&   aux_nu,
    const int&      C,
    const int&      N
);


double cov_nu_bvars (
    const double&   aux_nu,
    const int&      N
);


arma::vec sample_nu (
    double&             aux_nu,           // scalar
    double&             adaptive_scale,
    const arma::cube&   aux_Sigma_c_cpp,  // NxNxC
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const arma::mat&    aux_Sigma,        // NxN
    const Rcpp::List&   prior,
    const int&          iteration,        // MCMC iteration passed
    const arma::vec&    adptive_alpha_gamma // 2x1 vector with target acceptance rate and step size
);


Rcpp::List sample_nu_bvars (
    arma::vec&          aux_nu,           // C
    arma::vec&          adaptive_scale,   // C
    arma::vec&          aux_s,            // C
    const arma::cube&   aux_Sigma_c_cpp,  // NxNxC
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const Rcpp::List&   prior,
    const int&          iteration,        // MCMC iteration passed
    const arma::vec&    adptive_alpha_gamma // 2x1 vector with target acceptance rate and step size
);


arma::vec sample_nu_gg (
    double&             aux_nu,           // scalar
    double&             adaptive_scale,
    const arma::cube&   aux_Sigma_c_cpp,  // NxNxC
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const arma::cube&   aux_Sigma_g,      // NxNxG
    const arma::vec&    group_allocation, // C
    const Rcpp::List&   prior,
    const int&          iteration,        // MCMC iteration passed
    const arma::vec&    adptive_alpha_gamma // 2x1 vector with target acceptance rate and step size
);


arma::mat sample_Sigma (
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const double&       aux_s,            // scalar
    const double&       aux_nu,           // scalar
    const Rcpp::List&   prior
);


arma::cube sample_Sigma_g (
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const arma::vec&    group_allocation, // C
    const double&       aux_s,            // scalar
    const double&       aux_nu,           // scalar
    const Rcpp::List&   prior,
    const int&          G                 
);


arma::field<arma::mat> sample_AV (
    const arma::cube&   aux_A_c_cpp,      // KxNxC
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const double&       aux_s,            // scalar
    const double&       aux_m,            // scalar
    const double&       aux_w,            // scalar
    const Rcpp::List&   prior
);


arma::field<arma::mat> sample_AV_jaro (
    const arma::cube&   aux_A_c_cpp,      // KxNxC
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    arma::mat&          aux_A,            // KxN
    double&             aux_s,            // scalar
    const Rcpp::List&   prior
);


arma::cube sample_A_g (
    const arma::cube&   aux_A_c_cpp,      // KxNxC
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const arma::mat&    aux_V,            // KxK
    const arma::vec&    group_allocation, // C
    const double&       aux_s,            // scalar
    const double&       aux_m,            // scalar
    const Rcpp::List&   prior,
    const int&          G                 // scalar
);


arma::mat sample_V_gg (
    const arma::cube&   aux_A_c_cpp,      // KxNxC
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const arma::cube&   aux_A_g,          // KxNxG
    const arma::vec&    group_allocation, // C
    const double&       aux_s,            // scalar
    const double&       aux_m,            // scalar
    const double&       aux_w,            // scalar
    const Rcpp::List&   prior
);


arma::field<arma::mat> sample_A_c_Sigma_c (
    const arma::mat&    Y_c,              // T_cxN
    const arma::mat&    X_c,              // T_cxK
    const arma::mat&    aux_A,            // KxN
    const arma::mat&    aux_V,            // KxK
    const arma::mat&    aux_Sigma,        // NxN
    const double&       aux_nu            // scalar
);


arma::field<arma::mat> sample_A_c_Sigma_c_bvars (
    const arma::mat&    Y_c,              // T_cxN
    const arma::mat&    X_c,              // T_cxK
    const arma::mat&    aux_A,            // KxN
    const arma::mat&    aux_V_inv,            // KxK
    const arma::mat&    aux_Sigma,        // NxN
    const double&       aux_nu            // scalar
);


double log_kernel_ga (
    const arma::mat&    YG,               // (C_g*T, N) - only group-specific
    const arma::mat&    XG,               // (C_g*T, K)
    const arma::mat     A_g,              // (K, N)
    const arma::mat     Sigma_g,          // (N, N)
    const arma::mat&    aux_A,            // KxN
    const arma::mat&    aux_V_inv,        // KxK
    const arma::mat&    aux_Sigma,        // NxN
    const arma::mat&    aux_Sigma_inv,    // NxN
    const double&       aux_nu            // scalar
);


arma::vec sample_group_allocation (
    arma::vec&          aux_ga,           // (C, 1)
    const arma::cube&   yt,               // (T, N, C)
    const arma::cube&   xt,               // (T, K, C)
    const arma::cube    aux_A_g,          // (K, N, G)
    const arma::cube    aux_Sigma_g,      // (N, N, G)
    const arma::mat&    aux_A,            // KxN
    const arma::mat&    aux_V_inv,        // KxK
    const arma::mat&    aux_Sigma,        // NxN
    const arma::mat&    aux_Sigma_inv,    // NxN
    const double&       aux_nu            // scalar
);


#endif  // _SAMPLE_MNIW_H_
