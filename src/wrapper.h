
#ifndef __PYMOD_INIT__
#define __PYMOD_INIT__

#include "annuity.h"


/*
 * static PyObject* method(PyObject* self, PyObject* args);
 *
 * in order to be able to be run by the interpreter. */


/* Externally visible Python functions */
static PyObject* C_fv_annuity(PyObject* self, PyObject* args);
static PyObject* C_pv_annuity(PyObject* self, PyObject* args);
static PyObject* C_annuity_factor(PyObject* self, PyObject* args);
/*
static PyObject* C_parseArray(PyObject* self, PyObject* args);
static PyObject* C_large_init(PyObject* self, PyObject* args);
static PyObject * C_GoisPrime(PyObject* self, PyObject* args);
static PyObject* C_returnslice(PyObject* self, PyObject* args);
*/


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

