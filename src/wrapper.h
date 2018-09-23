
#ifndef __PYMOD_INIT__
#define __PYMOD_INIT__

#include "finance.h"


/*
 * static PyObject* method(PyObject* self, PyObject* args);
 *
 * in order to be able to be run by the interpreter. */


/* Externally visible Python functions */

/* Annuity */
static PyObject* C_fv_annuity(PyObject* self, PyObject* args);
static PyObject* C_pv_annuity(PyObject* self, PyObject* args);
static PyObject* C_annuity_factor(PyObject* self, PyObject* args);
static PyObject* C_pv_annuity_cash_flows(PyObject* self, PyObject* args);

/* Bonds */
static PyObject* C_bond_price(PyObject* self, PyObject* args);
static PyObject* C_yield_to_maturity(PyObject* self, PyObject* args);
static PyObject* C_coupon_rate(PyObject* self, PyObject* args);

/* Returns */
static PyObject* C_real_returns(PyObject* self, PyObject* args);

/* Python Initialisation */
PyMODINIT_FUNC init_finance(void);


/* Begin Python module setup */


/* Any Go function that intends to be called from Python has a partner C
 * function wrapper to interface Go types with the Python-C API.
 *
 * The members of this structure correspond to:
 *
 * {
 *      "module_name",
 *      C_function_pointer_for_method,
 *      VARIABLE_ARGS_FLAG
 *      "Python documentation string, NULL if unwanted",
 * },
 * */
static PyMethodDef ModuleMethods[] = {

        {"fv_annuity",  C_fv_annuity, METH_VARARGS,
        "Calculate the future value of a present value annuity."},

        {"pv_annuity",  C_pv_annuity, METH_VARARGS,
        "Calculate the present value of a future value annuity."},

        {"annuity_factor",  C_annuity_factor, METH_VARARGS,
        "Calculate the annuity factor with given r, n."},

        {"bond_price",  C_bond_price, METH_VARARGS,
        "Calculate the bond price with coupon price, discount rate, par value"
        " and the number of periods."
        },

        {"yield_to_maturity",  C_yield_to_maturity, METH_VARARGS,
        "Calculate the expected rate of return on a bond."},

        {"coupon_rate",  C_coupon_rate, METH_VARARGS,
        "Calculate the coupon rate of a bond."},

        {"pv_annuity_cash_flows", C_pv_annuity_cash_flows, METH_VARARGS,
        "Calculate present value of an annuity with constant cash flows."},

        {"real_return", C_real_returns, METH_VARARGS,
        "Calculate the real return based upon the nominal return and"
        "inflation rate, according to the Fisher Equation"},

        /* Sentinel */
        {NULL, NULL, 0, NULL}
};


static struct PyModuleDef module = {

        PyModuleDef_HEAD_INIT,

        /* name of module */
        "finance",

        /* module documentation, may be NULL */
        "Python finance module written in C",

        /* size of per-interpreter state of the module, or -1 if the module
         * keeps state in global variables. */
        -1,

        /* The table containing the information about our methods */
        ModuleMethods,

        /* A set of optional arguments */

        /* An array of slot definitions for multi-phase initialization */
        NULL,

        /* A traversal function to call during GC traversal of the module */
        NULL,

        /* A clear function to call during GC clearing of the module */
        NULL,

        /* A function to call during deallocation of the module */
        NULL,
};


/* End Python module setup */


#endif

