

#include <math.h>
#include <stdint.h>
#include "finance.h"


/* This calculation returns the bond price given the coupon payment `cp`, the
 * discount rate `rd`, face value `face`, the number of periods `n` and the
 * current period `t`. This works by calculating the present value of the
 * coupon payments and then the present value of the par value. */
double bond_price(double cp, double rd, double face, int32_t n)
{
        double pv_coupon = 0;
        double pv_parval = 0;

        for(int32_t t = 1; t <= n; t++){
                pv_coupon += pow((1.0 + rd), t * -1.0);
        }
        pv_coupon *= cp;

        pv_parval = pv_annuity(face, rd, n);

        return pv_coupon + pv_parval;
}


/* Calculate the expected rate of return on a bond. This is the rate that
 * investors earn on a bond if they hold it to maturity. We take the coupon
 * payment `cp`, the current bond price `bp`, the face value and also the
 * number of periods to maturity `n`. */
double yield_to_maturity(double cp, double bp, double face, int32_t n)
{
        double ytm = 0;

        double num = cp + ((face - bp) / n);
        ytm = num / ((bp + face) / 2);

        return ytm;

}

/* Calculate the coupon rate for a bond with a given yield to maturity `ytm`,
 * par value `face` and the number of remaining periods given at `n`. */
double coupon_rate(double bp, double ytm, double face, int32_t n)
{
        return (bp - pv_annuity(face, ytm, n)) /
                        (1 / ytm - 1/(ytm * annuity_factor(ytm, n)));
}




