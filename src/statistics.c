
#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include "finance.h"


/* Calculate the geometric mean */
double geometric_mean(double* hprs, size_t n_elem)
{
        double prod = 0.0;

        for(size_t i = 0; i < n_elem; i++){
                prod *= (1.0 + hprs[i]);
        }

        return pow(prod, 1.0/n_elem) - 1.0;

}

