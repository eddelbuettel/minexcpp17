// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// LinReg
Rcpp::List LinReg(arma::mat Data, unsigned long lNumber);
RcppExport SEXP _minExCpp17_LinReg(SEXP DataSEXP, SEXP lNumberSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Data(DataSEXP);
    Rcpp::traits::input_parameter< unsigned long >::type lNumber(lNumberSEXP);
    rcpp_result_gen = Rcpp::wrap(LinReg(Data, lNumber));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_minExCpp17_LinReg", (DL_FUNC) &_minExCpp17_LinReg, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_minExCpp17(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
