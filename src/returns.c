
#include <stdint.h>
#include <math.h>
#include "finance.h"


/* Based off the Fisher Equation for real return */
double real_return(double nominal, double inflation)
{
        return (1 + nominal)/(1 + inflation) - 1;
}


