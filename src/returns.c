
#include <stdint.h>
#include <math.h>
#include "finance.h"


/* Based off the Fisher Equation for real return */
double real_return(double nominal, double inflation)
{
        return (1 + nominal)/(1 + inflation) - 1;
}

/* Deduce the currency adjusted return relative to an international currency
 * with respect to the local currency */
double currency_adjusted_return(double real_return, double begin, double end)
{
        return (real_return * (end / begin)) - 1.0;
}


