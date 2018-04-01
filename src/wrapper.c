
/* Python.h impiles `stdio, stdlib, etc` */

#include <Python.h>
#include "wrapper.h"


/* Initialises the Python module, this is then referenced in the PyModuleDef
 * structure */
PyMODINIT_FUNC PyInit_finance(void)
{
        Py_Initialize();

        return PyModule_Create(&module);
}


static PyObject* C_fv_annuity(PyObject* self, PyObject* args)
{
        (void) self;

        double pv, rate;
        uint32_t n;

        double res = 0.0;

        if(!PyArg_ParseTuple(args, "ddI", &pv, &rate, &n))
                goto cleanup;

        res = fv_annuity(pv, rate, n);

cleanup:

        return Py_BuildValue("d", res);

}


static PyObject* C_pv_annuity(PyObject* self, PyObject* args)
{
        (void) self;

        double fv, rate;
        uint32_t n;

        double res = 0.0;

        if(!PyArg_ParseTuple(args, "ddI", &fv, &rate, &n))
                goto cleanup;

        res = pv_annuity(fv, rate, n);

cleanup:

        return Py_BuildValue("d", res);

}


static PyObject* C_annuity_factor(PyObject* self, PyObject* args)
{
        (void) self;

        double rate;
        uint32_t n;

        double res = 0.0;

        if(!PyArg_ParseTuple(args, "dI", &rate, &n))
                goto cleanup;

        res = annuity_factor(rate, n);

cleanup:

        return Py_BuildValue("d", res);

}

