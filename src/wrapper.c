
/* Python.h impiles `stdio, stdlib, etc` */

#include <Python.h>
#include <stddef.h>
#include <math.h>
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


static PyObject* C_bond_price(PyObject* self, PyObject* args)
{
        (void) self;

        double cp, rd, face;
        uint32_t n;

        double res = 0.0;

        if(!PyArg_ParseTuple(args, "dddI", &cp, &rd, &face, &n))
                goto cleanup;

        res = bond_price(cp, rd, face, n);

cleanup:

        return Py_BuildValue("d", res);

}


static PyObject* C_yield_to_maturity(PyObject* self, PyObject* args)
{
        (void) self;

        double cp, bp, face;
        uint32_t n;

        double res = 0.0;

        if(!PyArg_ParseTuple(args, "dddI", &cp, &bp, &face, &n))
                goto cleanup;

        res = yield_to_maturity(cp, bp, face, n);

cleanup:

        return Py_BuildValue("d", res);

}


static PyObject* C_coupon_rate(PyObject* self, PyObject* args)
{
        (void) self;

        double ytm, bp, face;
        uint32_t n;

        double res = 0.0;

        if(!PyArg_ParseTuple(args, "dddI", &bp, &ytm, &face, &n))
                goto cleanup;

        res = coupon_rate(bp, ytm, face, n);

cleanup:

        return Py_BuildValue("d", res);

}

static PyObject* C_pv_annuity_cash_flows(PyObject* self, PyObject* args)
{
        (void) self;

        double cf, r;
        uint32_t n;

        double res = 0.0;

        if(!PyArg_ParseTuple(args, "dddI", &cf, &r, &n))
                goto cleanup;

        res = pv_annuity_cash_flows(cf, r, n);

cleanup:

        return Py_BuildValue("d", res);

}

static PyObject* C_curr_adj_return(PyObject* self, PyObject* args)
{
        (void) self;

        double rr, begin, end;

        double res = 0.0;

        if(!PyArg_ParseTuple(args, "ddd", &rr, &begin, &end))
                goto cleanup;

        res = currency_adjusted_return(rr, begin, end);

cleanup:

        return Py_BuildValue("d", res);

}

static PyObject* C_real_returns(PyObject* self, PyObject* args)
{
        (void) self;

        double nominal, inflation;

        double res = 0.0;

        if(!PyArg_ParseTuple(args, "dd", &nominal, &inflation))
                goto cleanup;

        res = real_return(nominal, inflation);

cleanup:

        return Py_BuildValue("d", res);

}

static PyObject* C_geometric_mean(PyObject* self, PyObject* args)
{
        (void) self;

        PyObject* hprs;

        double res = 1.0;

        if(!PyArg_ParseTuple(args, "O!", &PyList_Type, &hprs))
                goto cleanup;

        size_t hpr_len = PyList_Size(hprs);

        for(size_t i = 0; i < hpr_len; i++){
                res *= (1.0 + PyFloat_AsDouble(PyList_GetItem(hprs, i)));
        }

        res = pow(res, 1.0/hpr_len) - 1.0;


cleanup:

        return Py_BuildValue("d", res);

}

