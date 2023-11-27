/* File: __nnlsmodule.c
 * This file is auto-generated with f2py (version:1.26.2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * Generation date: Wed Nov 24 04:33:34 2021
 * Do not edit this file directly unless you know what you are doing!!!
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef PY_SSIZE_T_CLEAN
#define PY_SSIZE_T_CLEAN
#endif /* PY_SSIZE_T_CLEAN */

/* Unconditionally included */
#include <Python.h>
#include <numpy/npy_os.h>

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "fortranobject.h"
#include <math.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *__nnls_error;
static PyObject *__nnls_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
/*need_typedefs*/

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

/* See fortranobject.h for definitions. The macros here are provided for BC. */
#define rank f2py_rank
#define shape f2py_shape
#define fshape f2py_shape
#define len f2py_len
#define flen f2py_flen
#define slen f2py_slen
#define size f2py_size

#define CHECKSCALAR(check,tcheck,name,show,var)\
    if (!(check)) {\
        char errstring[256];\
        sprintf(errstring, "%s: "show, "("tcheck") failed for "name, var);\
        PyErr_SetString(__nnls_error,errstring);\
        /*goto capi_fail;*/\
    } else 
#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
    PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
    fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int
int_from_pyobj(int* v, PyObject *obj, const char *errmess)
{
    PyObject* tmp = NULL;

    if (PyLong_Check(obj)) {
        *v = Npy__PyLong_AsInt(obj);
        return !(*v == -1 && PyErr_Occurred());
    }

    tmp = PyNumber_Long(obj);
    if (tmp) {
        *v = Npy__PyLong_AsInt(tmp);
        Py_DECREF(tmp);
        return !(*v == -1 && PyErr_Occurred());
    }

    if (PyComplex_Check(obj)) {
        PyErr_Clear();
        tmp = PyObject_GetAttrString(obj,"real");
    }
    else if (PyBytes_Check(obj) || PyUnicode_Check(obj)) {
        /*pass*/;
    }
    else if (PySequence_Check(obj)) {
        PyErr_Clear();
        tmp = PySequence_GetItem(obj, 0);
    }

    if (tmp) {
        if (int_from_pyobj(v, tmp, errmess)) {
            Py_DECREF(tmp);
            return 1;
        }
        Py_DECREF(tmp);
    }

    {
        PyObject* err = PyErr_Occurred();
        if (err == NULL) {
            err = __nnls_error;
        }
        PyErr_SetString(err, errmess);
    }
    return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(nnls,NNLS)(double*,int*,int*,int*,double*,double*,double*,double*,double*,int*,int*,int*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/************************************ nnls ************************************/
static char doc_f2py_rout___nnls_nnls[] = "\
x,rnorm,mode = nnls(a,m,n,b,w,zz,index_bn,maxiter,[mda,overwrite_a,overwrite_b])\n\nWrapper for ``nnls``.\
\n\nParameters\n----------\n"
"a : input rank-2 array('d') with bounds (mda,*)\n"
"m : input int\n"
"n : input int\n"
"b : input rank-1 array('d') with bounds (*)\n"
"w : input rank-1 array('d') with bounds (*)\n"
"zz : input rank-1 array('d') with bounds (*)\n"
"index_bn : input rank-1 array('i') with bounds (*)\n"
"maxiter : input int\n"
"\nOther Parameters\n----------------\n"
"overwrite_a : input int, optional\n    Default: 0\n"
"mda : input int, optional\n    Default: shape(a,0)\n"
"overwrite_b : input int, optional\n    Default: 0\n"
"\nReturns\n-------\n"
"x : rank-1 array('d') with bounds (n)\n"
"rnorm : float\n"
"mode : int";
/* extern void F_FUNC(nnls,NNLS)(double*,int*,int*,int*,double*,double*,double*,double*,double*,int*,int*,int*); */
static PyObject *f2py_rout___nnls_nnls(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*,int*,int*,int*,double*,double*,double*,double*,double*,int*,int*,int*)) {
    PyObject * volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
/*decl*/

    double *a = NULL;
    npy_intp a_Dims[2] = {-1, -1};
    const int a_Rank = 2;
    PyArrayObject *capi_a_as_array = NULL;
    int capi_a_intent = 0;
    int capi_overwrite_a = 0;
    PyObject *a_capi = Py_None;
    int mda = 0;
    PyObject *mda_capi = Py_None;
    int m = 0;
    PyObject *m_capi = Py_None;
    int n = 0;
    PyObject *n_capi = Py_None;
    double *b = NULL;
    npy_intp b_Dims[1] = {-1};
    const int b_Rank = 1;
    PyArrayObject *capi_b_as_array = NULL;
    int capi_b_intent = 0;
    int capi_overwrite_b = 0;
    PyObject *b_capi = Py_None;
    double *x = NULL;
    npy_intp x_Dims[1] = {-1};
    const int x_Rank = 1;
    PyArrayObject *capi_x_as_array = NULL;
    int capi_x_intent = 0;
    double rnorm = 0;
    double *w = NULL;
    npy_intp w_Dims[1] = {-1};
    const int w_Rank = 1;
    PyArrayObject *capi_w_as_array = NULL;
    int capi_w_intent = 0;
    PyObject *w_capi = Py_None;
    double *zz = NULL;
    npy_intp zz_Dims[1] = {-1};
    const int zz_Rank = 1;
    PyArrayObject *capi_zz_as_array = NULL;
    int capi_zz_intent = 0;
    PyObject *zz_capi = Py_None;
    int *index_bn = NULL;
    npy_intp index_bn_Dims[1] = {-1};
    const int index_bn_Rank = 1;
    PyArrayObject *capi_index_bn_as_array = NULL;
    int capi_index_bn_intent = 0;
    PyObject *index_bn_capi = Py_None;
    int mode = 0;
    int maxiter = 0;
    PyObject *maxiter_capi = Py_None;
    static char *capi_kwlist[] = {"a","m","n","b","w","zz","index_bn","maxiter","mda","overwrite_a","overwrite_b",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
    if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
        "OOOOOOOO|Oii:__nnls.nnls",\
        capi_kwlist,&a_capi,&m_capi,&n_capi,&b_capi,&w_capi,&zz_capi,&index_bn_capi,&maxiter_capi,&mda_capi,&capi_overwrite_a,&capi_overwrite_b))
        return NULL;
/*frompyobj*/
    /* Processing variable a */
    capi_a_intent |= (capi_overwrite_a?0:F2PY_INTENT_COPY);
    ;
    capi_a_intent |= F2PY_INTENT_IN;
    const char * capi_errmess = "__nnls.__nnls.nnls: failed to create array from the 1st argument `a`";
    capi_a_as_array = ndarray_from_pyobj(  NPY_DOUBLE,1,a_Dims,a_Rank,  capi_a_intent,a_capi,capi_errmess);
    if (capi_a_as_array == NULL) {
        PyObject* capi_err = PyErr_Occurred();
        if (capi_err == NULL) {
            capi_err = __nnls_error;
            PyErr_SetString(capi_err, capi_errmess);
        }
    } else {
        a = (double *)(PyArray_DATA(capi_a_as_array));

    /* Processing variable m */
        f2py_success = int_from_pyobj(&m,m_capi,"__nnls.nnls() 2nd argument (m) can't be converted to int");
    if (f2py_success) {
    /* Processing variable n */
        f2py_success = int_from_pyobj(&n,n_capi,"__nnls.nnls() 3rd argument (n) can't be converted to int");
    if (f2py_success) {
    /* Processing variable b */
    capi_b_intent |= (capi_overwrite_b?0:F2PY_INTENT_COPY);
    ;
    capi_b_intent |= F2PY_INTENT_IN;
    const char * capi_errmess = "__nnls.__nnls.nnls: failed to create array from the 4th argument `b`";
    capi_b_as_array = ndarray_from_pyobj(  NPY_DOUBLE,1,b_Dims,b_Rank,  capi_b_intent,b_capi,capi_errmess);
    if (capi_b_as_array == NULL) {
        PyObject* capi_err = PyErr_Occurred();
        if (capi_err == NULL) {
            capi_err = __nnls_error;
            PyErr_SetString(capi_err, capi_errmess);
        }
    } else {
        b = (double *)(PyArray_DATA(capi_b_as_array));

    /* Processing variable rnorm */
    /* Processing variable w */
    ;
    capi_w_intent |= F2PY_INTENT_IN;
    const char * capi_errmess = "__nnls.__nnls.nnls: failed to create array from the 5th argument `w`";
    capi_w_as_array = ndarray_from_pyobj(  NPY_DOUBLE,1,w_Dims,w_Rank,  capi_w_intent,w_capi,capi_errmess);
    if (capi_w_as_array == NULL) {
        PyObject* capi_err = PyErr_Occurred();
        if (capi_err == NULL) {
            capi_err = __nnls_error;
            PyErr_SetString(capi_err, capi_errmess);
        }
    } else {
        w = (double *)(PyArray_DATA(capi_w_as_array));

    /* Processing variable zz */
    ;
    capi_zz_intent |= F2PY_INTENT_IN;
    const char * capi_errmess = "__nnls.__nnls.nnls: failed to create array from the 6th argument `zz`";
    capi_zz_as_array = ndarray_from_pyobj(  NPY_DOUBLE,1,zz_Dims,zz_Rank,  capi_zz_intent,zz_capi,capi_errmess);
    if (capi_zz_as_array == NULL) {
        PyObject* capi_err = PyErr_Occurred();
        if (capi_err == NULL) {
            capi_err = __nnls_error;
            PyErr_SetString(capi_err, capi_errmess);
        }
    } else {
        zz = (double *)(PyArray_DATA(capi_zz_as_array));

    /* Processing variable index_bn */
    ;
    capi_index_bn_intent |= F2PY_INTENT_IN;
    const char * capi_errmess = "__nnls.__nnls.nnls: failed to create array from the 7th argument `index_bn`";
    capi_index_bn_as_array = ndarray_from_pyobj(  NPY_INT,1,index_bn_Dims,index_bn_Rank,  capi_index_bn_intent,index_bn_capi,capi_errmess);
    if (capi_index_bn_as_array == NULL) {
        PyObject* capi_err = PyErr_Occurred();
        if (capi_err == NULL) {
            capi_err = __nnls_error;
            PyErr_SetString(capi_err, capi_errmess);
        }
    } else {
        index_bn = (int *)(PyArray_DATA(capi_index_bn_as_array));

    /* Processing variable mode */
    /* Processing variable maxiter */
        f2py_success = int_from_pyobj(&maxiter,maxiter_capi,"__nnls.nnls() 8th argument (maxiter) can't be converted to int");
    if (f2py_success) {
    /* Processing variable mda */
    if (mda_capi == Py_None) mda = shape(a,0); else
        f2py_success = int_from_pyobj(&mda,mda_capi,"__nnls.nnls() 1st keyword (mda) can't be converted to int");
    if (f2py_success) {
    CHECKSCALAR(shape(a,0)==mda,"shape(a,0)==mda","1st keyword mda","nnls:mda=%d",mda) {
    /* Processing variable x */
    x_Dims[0]=n;
    capi_x_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
    const char * capi_errmess = "__nnls.__nnls.nnls: failed to create array from the hidden `x`";
    capi_x_as_array = ndarray_from_pyobj(  NPY_DOUBLE,1,x_Dims,x_Rank,  capi_x_intent,Py_None,capi_errmess);
    if (capi_x_as_array == NULL) {
        PyObject* capi_err = PyErr_Occurred();
        if (capi_err == NULL) {
            capi_err = __nnls_error;
            PyErr_SetString(capi_err, capi_errmess);
        }
    } else {
        x = (double *)(PyArray_DATA(capi_x_as_array));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
                (*f2py_func)(a,&mda,&m,&n,b,x,&rnorm,w,zz,index_bn,&mode,&maxiter);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
        if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
        CFUNCSMESS("Building return value.\n");
        capi_buildvalue = Py_BuildValue("Ndi",capi_x_as_array,rnorm,mode);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
        } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
    }  /* if (capi_x_as_array == NULL) ... else of x */
    /* End of cleaning variable x */
    } /*CHECKSCALAR(shape(a,0)==mda)*/
    } /*if (f2py_success) of mda*/
    /* End of cleaning variable mda */
    } /*if (f2py_success) of maxiter*/
    /* End of cleaning variable maxiter */
    /* End of cleaning variable mode */
    if((PyObject *)capi_index_bn_as_array!=index_bn_capi) {
        Py_XDECREF(capi_index_bn_as_array); }
    }  /* if (capi_index_bn_as_array == NULL) ... else of index_bn */
    /* End of cleaning variable index_bn */
    if((PyObject *)capi_zz_as_array!=zz_capi) {
        Py_XDECREF(capi_zz_as_array); }
    }  /* if (capi_zz_as_array == NULL) ... else of zz */
    /* End of cleaning variable zz */
    if((PyObject *)capi_w_as_array!=w_capi) {
        Py_XDECREF(capi_w_as_array); }
    }  /* if (capi_w_as_array == NULL) ... else of w */
    /* End of cleaning variable w */
    /* End of cleaning variable rnorm */
    if((PyObject *)capi_b_as_array!=b_capi) {
        Py_XDECREF(capi_b_as_array); }
    }  /* if (capi_b_as_array == NULL) ... else of b */
    /* End of cleaning variable b */
    } /*if (f2py_success) of n*/
    /* End of cleaning variable n */
    } /*if (f2py_success) of m*/
    /* End of cleaning variable m */
    if((PyObject *)capi_a_as_array!=a_capi) {
        Py_XDECREF(capi_a_as_array); }
    }  /* if (capi_a_as_array == NULL) ... else of a */
    /* End of cleaning variable a */
/*end of cleanupfrompyobj*/
    if (capi_buildvalue == NULL) {
/*routdebugfailure*/
    } else {
/*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/******************************** end of nnls ********************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
    {"nnls",-1,{{-1}},0,0,(char *)  F_FUNC(nnls,NNLS),  (f2py_init_func)f2py_rout___nnls_nnls,doc_f2py_rout___nnls_nnls},

/*eof routine_defs*/
    {NULL}
};

static PyMethodDef f2py_module_methods[] = {

    {NULL,NULL}
};

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "__nnls",
    NULL,
    -1,
    f2py_module_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit___nnls(void) {
    int i;
    PyObject *m,*d, *s, *tmp;
    m = __nnls_module = PyModule_Create(&moduledef);
    Py_SET_TYPE(&PyFortran_Type, &PyType_Type);
    import_array();
    if (PyErr_Occurred())
        {PyErr_SetString(PyExc_ImportError, "can't initialize module __nnls (failed to import numpy)"); return m;}
    d = PyModule_GetDict(m);
    s = PyUnicode_FromString("1.26.2");
    PyDict_SetItemString(d, "__version__", s);
    Py_DECREF(s);
    s = PyUnicode_FromString(
        "This module '__nnls' is auto-generated with f2py (version:1.26.2).\nFunctions:\n"
"    x,rnorm,mode = nnls(a,m,n,b,w,zz,index_bn,maxiter,mda=shape(a,0),overwrite_a=0,overwrite_b=0)\n"
".");
    PyDict_SetItemString(d, "__doc__", s);
    Py_DECREF(s);
    s = PyUnicode_FromString("1.26.2");
    PyDict_SetItemString(d, "__f2py_numpy_version__", s);
    Py_DECREF(s);
    __nnls_error = PyErr_NewException ("__nnls.error", NULL, NULL);
    /*
     * Store the error object inside the dict, so that it could get deallocated.
     * (in practice, this is a module, so it likely will not and cannot.)
     */
    PyDict_SetItemString(d, "___nnls_error", __nnls_error);
    Py_DECREF(__nnls_error);
    for(i=0;f2py_routine_defs[i].name!=NULL;i++) {
        tmp = PyFortranObject_NewAsAttr(&f2py_routine_defs[i]);
        PyDict_SetItemString(d, f2py_routine_defs[i].name, tmp);
        Py_DECREF(tmp);
    }

/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
    if (! PyErr_Occurred())
        on_exit(f2py_report_on_exit,(void*)"__nnls");
#endif
    return m;
}
#ifdef __cplusplus
}
#endif
