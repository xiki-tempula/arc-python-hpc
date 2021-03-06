/* File: f_array_sqrt_ompmodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * Generation date: Tue Mar  6 17:55:01 2018
 * Do not edit this file directly unless you know what you are doing!!!
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include <stdarg.h>
#include "fortranobject.h"
#include <math.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *f_array_sqrt_omp_error;
static PyObject *f_array_sqrt_omp_module;

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

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (PyArray_NDIM((PyArrayObject *)(capi_ ## var ## _tmp)))
#define old_shape(var,dim) PyArray_DIM(((PyArrayObject *)(capi_ ## var ## _tmp)),dim)
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_ ## var ## _tmp), ## __VA_ARGS__, -1)

#define CHECKSCALAR(check,tcheck,name,show,var)\
    if (!(check)) {\
        char errstring[256];\
        sprintf(errstring, "%s: "show, "("tcheck") failed for "name, var);\
        PyErr_SetString(f_array_sqrt_omp_error,errstring);\
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
static int f2py_size(PyArrayObject* var, ...)
{
  npy_int sz = 0;
  npy_int dim;
  npy_int rank;
  va_list argp;
  va_start(argp, var);
  dim = va_arg(argp, npy_int);
  if (dim==-1)
    {
      sz = PyArray_SIZE(var);
    }
  else
    {
      rank = PyArray_NDIM(var);
      if (dim>=1 && dim<=rank)
        sz = PyArray_DIM(var, dim-1);
      else
        fprintf(stderr, "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will be 0.\n", dim, rank);
    }
  va_end(argp);
  return sz;
}

static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
    PyObject* tmp = NULL;
    if (PyInt_Check(obj)) {
        *v = (int)PyInt_AS_LONG(obj);
        return 1;
    }
    tmp = PyNumber_Int(obj);
    if (tmp) {
        *v = PyInt_AS_LONG(tmp);
        Py_DECREF(tmp);
        return 1;
    }
    if (PyComplex_Check(obj))
        tmp = PyObject_GetAttrString(obj,"real");
    else if (PyString_Check(obj) || PyUnicode_Check(obj))
        /*pass*/;
    else if (PySequence_Check(obj))
        tmp = PySequence_GetItem(obj,0);
    if (tmp) {
        PyErr_Clear();
        if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
        Py_DECREF(tmp);
    }
    {
        PyObject* err = PyErr_Occurred();
        if (err==NULL) err = f_array_sqrt_omp_error;
        PyErr_SetString(err,errmess);
    }
    return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC_US(array_sqrt,ARRAY_SQRT)(int*,double*,double*,int*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/********************************* array_sqrt *********************************/
static char doc_f2py_rout_f_array_sqrt_omp_array_sqrt[] = "\
a_out = array_sqrt(a_in,nt,[n])\n\nWrapper for ``array_sqrt``.\
\n\nParameters\n----------\n"
"a_in : input rank-1 array('d') with bounds (n)\n"
"nt : input int\n"
"\nOther Parameters\n----------------\n"
"n : input int, optional\n    Default: len(a_in)\n"
"\nReturns\n-------\n"
"a_out : rank-1 array('d') with bounds (n)";
/* extern void F_FUNC_US(array_sqrt,ARRAY_SQRT)(int*,double*,double*,int*); */
static PyObject *f2py_rout_f_array_sqrt_omp_array_sqrt(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,double*,double*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int n = 0;
  PyObject *n_capi = Py_None;
  double *a_in = NULL;
  npy_intp a_in_Dims[1] = {-1};
  const int a_in_Rank = 1;
  PyArrayObject *capi_a_in_tmp = NULL;
  int capi_a_in_intent = 0;
  PyObject *a_in_capi = Py_None;
  double *a_out = NULL;
  npy_intp a_out_Dims[1] = {-1};
  const int a_out_Rank = 1;
  PyArrayObject *capi_a_out_tmp = NULL;
  int capi_a_out_intent = 0;
  int nt = 0;
  PyObject *nt_capi = Py_None;
  static char *capi_kwlist[] = {"a_in","nt","n",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OO|O:f_array_sqrt_omp.array_sqrt",\
    capi_kwlist,&a_in_capi,&nt_capi,&n_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable nt */
    f2py_success = int_from_pyobj(&nt,nt_capi,"f_array_sqrt_omp.array_sqrt() 2nd argument (nt) can't be converted to int");
  if (f2py_success) {
  /* Processing variable a_in */
  ;
  capi_a_in_intent |= F2PY_INTENT_IN;
  capi_a_in_tmp = array_from_pyobj(NPY_DOUBLE,a_in_Dims,a_in_Rank,capi_a_in_intent,a_in_capi);
  if (capi_a_in_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(f_array_sqrt_omp_error,"failed in converting 1st argument `a_in' of f_array_sqrt_omp.array_sqrt to C/Fortran array" );
  } else {
    a_in = (double *)(PyArray_DATA(capi_a_in_tmp));

  /* Processing variable n */
  if (n_capi == Py_None) n = len(a_in); else
    f2py_success = int_from_pyobj(&n,n_capi,"f_array_sqrt_omp.array_sqrt() 1st keyword (n) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(len(a_in)>=n,"len(a_in)>=n","1st keyword n","array_sqrt:n=%d",n) {
  /* Processing variable a_out */
  a_out_Dims[0]=n;
  capi_a_out_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_a_out_tmp = array_from_pyobj(NPY_DOUBLE,a_out_Dims,a_out_Rank,capi_a_out_intent,Py_None);
  if (capi_a_out_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(f_array_sqrt_omp_error,"failed in converting hidden `a_out' of f_array_sqrt_omp.array_sqrt to C/Fortran array" );
  } else {
    a_out = (double *)(PyArray_DATA(capi_a_out_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&n,a_in,a_out,&nt);
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
    capi_buildvalue = Py_BuildValue("N",capi_a_out_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_a_out_tmp == NULL) ... else of a_out*/
  /* End of cleaning variable a_out */
  } /*CHECKSCALAR(len(a_in)>=n)*/
  } /*if (f2py_success) of n*/
  /* End of cleaning variable n */
  if((PyObject *)capi_a_in_tmp!=a_in_capi) {
    Py_XDECREF(capi_a_in_tmp); }
  }  /*if (capi_a_in_tmp == NULL) ... else of a_in*/
  /* End of cleaning variable a_in */
  } /*if (f2py_success) of nt*/
  /* End of cleaning variable nt */
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
/***************************** end of array_sqrt *****************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"array_sqrt",-1,{{-1}},0,(char *)F_FUNC_US(array_sqrt,ARRAY_SQRT),(f2py_init_func)f2py_rout_f_array_sqrt_omp_array_sqrt,doc_f2py_rout_f_array_sqrt_omp_array_sqrt},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "f_array_sqrt_omp",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyMODINIT_FUNC PyInit_f_array_sqrt_omp(void) {
#else
#define RETVAL
PyMODINIT_FUNC initf_array_sqrt_omp(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = f_array_sqrt_omp_module = PyModule_Create(&moduledef);
#else
  m = f_array_sqrt_omp_module = Py_InitModule("f_array_sqrt_omp", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module f_array_sqrt_omp (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module 'f_array_sqrt_omp' is auto-generated with f2py (version:2).\nFunctions:\n"
"  a_out = array_sqrt(a_in,nt,n=len(a_in))\n"
".");
  PyDict_SetItemString(d, "__doc__", s);
  f_array_sqrt_omp_error = PyErr_NewException ("f_array_sqrt_omp.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));

/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"f_array_sqrt_omp");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif
