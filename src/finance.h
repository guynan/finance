
#include <stdint.h>


/* In the absence of specification this is the value that will be used */
#define         PAR_VALUE       1000

/* Annuity Prototypes */
double pv_annuity_cash_flows(double cf, double r, double n);
double fv_annuity(double pv, double rate, uint32_t n);
double pv_annuity(double fv, double rate, uint32_t n);
double annuity_factor(double rate, uint32_t n);

/* Bond Prototypes */
double bond_price(double cp, double rd, double face, int32_t n);
double coupon_rate(double bp, double ytm, double face, int32_t n);
double yield_to_maturity(double cp, double bp, double face, int32_t n);

