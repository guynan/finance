
#include <stdint.h>
#include <math.h>
#include "annuity.h"


/* FV = PV (1 + r)**n */
double fv_annuity(double pv, double rate, uint32_t n)
{
        return pv * pow(1 + rate, n);
}

/* PV = FV / (1 + r)**n */
double pv_annuity(double fv, double rate, uint32_t n)
{
        return fv / pow(1 + rate, n);
}

/* (1 + r)**n */
double annuity_factor(double rate, uint32_t n)
{
        return pow(1 + rate, n);
}

