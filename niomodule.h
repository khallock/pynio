/*******************************************************
 * $Id: niomodule.h 16167 2015-04-10 14:19:16Z dbrown $
 *******************************************************/

#ifndef Py_NIOMODULE_H
#define Py_NIOMODULE_H
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Include file for NIO files and variables.
 *
 * adapted from code written by Konrad Hinsen
 * last revision: 2006-03-07
 */


#include <stdio.h>
#include "Python.h"
#include "pyconfig.h"

/* NIOFile object */

typedef struct NioFileObjectStruct NioFileObject;

struct NioFileObjectStruct {
  PyObject_HEAD
  PyObject *groups;  /* dictionary */
  PyObject *dimensions;   /* dictionary */
  PyObject *chunk_dimensions;   /* dictionary */
  PyObject *variables;    /* dictionary */
  PyObject *attributes;   /* dictionary */
  PyObject *ud_types;     /* dictionary */
  PyObject *name;         /* string */
  PyObject *mode;         /* string */
  PyObject *type;         /* string  : file or group  */
  PyObject *full_path;    /* string : path in the file system for the top-level file object ; otherwise the group hierarchy separated by slashes */
  PyObject *weakreflist;
  NioFileObject *parent;   /* this is the parent group -- the top-level file object has no parent; the root group has the top-level file object as a parent */
  NioFileObject *top;       /* this is the top-level file object */
  void *id;        /* this is a pointer to the NCL file object for the (top-level) file */
  void *gnode;     /* gnode is actually an advanced file structure that contains a groupnode -- it could be the top level grpnode (file) or else a group */
  char open;
  char define;
  char write;
  char being_destroyed;
  int recdim;
};

/* NIOVariable object */

typedef struct {
  PyObject_HEAD
  NioFileObject *file;  /* this is a file or a group depending on the parent of the variable */
  PyObject *attributes;   /* dictionary */
  char *name;
  NrmQuark *qdims;
  Py_ssize_t *dimensions;
/*
 *NrmQuark *qchunkdims;
 *Py_ssize_t *chunk_dimensions;
 */
  int type;               /* same as array types */
  int nd;
  int id;
  char unlimited;
} NioVariableObject;

/* Variable index structure */

typedef struct {
  Py_ssize_t start;
  Py_ssize_t stop;
  Py_ssize_t stride;
  short item;
  short unlimited;
  short no_start; /* start is not None */
  short no_stop;  /* stop is not None */
} NioIndex;

/*
 * C API functions
 */

typedef enum
{
    NioFile_Type_NUM = 0,
    NioVariable_Type_NUM,
    NioFile_Open_NUM,
    NioFile_Close_NUM,
    NioFile_Sync_NUM,
    NioFile_CreateGroup_NUM,
    NioFile_GetGroup_NUM,
    NioFile_CreateVariable_NUM,
    NioFile_GetVariable_NUM,
    NioFile_CreateDimension_NUM,
    NioFile_CreateChunkDimension_NUM,
    NioVariable_GetRank_NUM,
    NioVariable_GetShape_NUM,
    NioVariable_Indices_NUM,
    NioVariable_ReadAsArray_NUM,
    NioVariable_WriteArray_NUM,
    NioFile_GetAttribute_NUM,
    NioFile_SetAttribute_NUM,
    NioFile_SetAttributeString_NUM,
    NioVariable_GetAttribute_NUM,
    NioVariable_SetAttribute_NUM,
    NioVariable_SetAttributeString_NUM,
    NioFile_AddHistoryLine_NUM,
    NioVariable_WriteString_NUM,
    NioVariable_ReadAsString_NUM,
    NioFile_CreateVLEN_NUM,
    NioFile_CreateCOMPOUND_NUM,
    NioFile_CreateCOMPOUNDtype_NUM,
    NioVariable_GetSize_NUM,
    PyNIO_API_pointers /* Total number of C API pointers */
} NioFileGroupVariableNUM;

/* For backward compatibility only. Obsolete, do not use. */
#ifdef HAVE_PROTOTYPES
#define Py_PROTO(x) x
#else
#define Py_PROTO(x) ()
#endif
#ifndef Py_FPROTO
#define Py_FPROTO(x) Py_PROTO(x)
#endif

/* Type definitions */
/* Open a NIO file (i.e. create a new file object) */
#define NioFile_Open_RET NioFileObject *
#define NioFile_Open_PROTO Py_PROTO((char *filename, char *mode))

/* Close a NIO file. Returns -1 if there was an error. */
#define NioFile_Close_RET int
#define NioFile_Close_PROTO Py_PROTO((NioFileObject *file))

/* Ensure that all data is written to the disk file.
   Returns 0 if there was an error. */
/*
#define NioFile_Sync_RET int
#define NioFile_Sync_PROTO Py_PROTO((NioFileObject *file))
*/
/* Create a new dimension. Returns -1 if there was an error. */
#define NioFile_CreateDimension_RET int
#define NioFile_CreateDimension_PROTO \
        Py_PROTO((NioFileObject *file, char *name, Py_ssize_t size))

/* Create a new chunk dimension. Returns -1 if there was an error. */
#define NioFile_CreateChunkDimension_RET int
#define NioFile_CreateChunkDimension_PROTO \
        Py_PROTO((NioFileObject *file, char *name, Py_ssize_t size))

/* Create a NIO group and return the group object */
#define NioFile_CreateGroup_RET NioFileObject *
#define NioFile_CreateGroup_PROTO \
      Py_PROTO((NioFileObject *file, char *name))

/* Create a NIO variable and return the variable object */
#define NioFile_CreateVariable_RET NioVariableObject *
#define NioFile_CreateVariable_PROTO \
      Py_PROTO((NioFileObject *file, char *name, int typecode, \
                char **dimension_names, int ndim))

/* Create a NIO vlen and return the vlen object */
#define NioFile_CreateVLEN_RET NioVariableObject *
#define NioFile_CreateVLEN_PROTO \
      Py_PROTO((NioFileObject *file, char *name, int typecode, \
                char **dimension_names, int ndim))

/* Create a NIO compound and return the compound object */
#define NioFile_CreateCOMPOUND_RET NioVariableObject *
#define NioFile_CreateCOMPOUND_PROTO \
      Py_PROTO((NioFileObject *file, char *name, \
                char **dimension_names, int ndim, \
                char **memb_names, int *memb_types, \
                int *memb_sizes, int nmemb))

/* Create a NIO compound type and return the compound object */
#define NioFile_CreateCOMPOUNDtype_RET NioVariableObject *
#define NioFile_CreateCOMPOUNDtype_PROTO \
      Py_PROTO((NioFileObject *file, char *name, \
                char **memb_names, int *memb_types, \
                int *memb_sizes, int nmemb))

/* Return an object referring to an existing variable */
#define NioFile_GetVariable_RET NioVariableObject *
#define NioFile_GetVariable_PROTO \
	  Py_PROTO((NioFileObject *file, char *name))

/* Get variable rank */
#define NioVariable_GetRank_RET int
#define NioVariable_GetRank_PROTO Py_PROTO((NioVariableObject *var))

/* Get variable shape */
#define NioVariable_GetShape_RET Py_ssize_t *
#define NioVariable_GetShape_PROTO Py_PROTO((NioVariableObject *var))

/* Allocate and initialize index structures for reading/writing data */
#define NioVariable_Indices_RET NioIndex *
#define NioVariable_Indices_PROTO Py_PROTO((NioVariableObject *var))

/* Read data and return an array object */
#define NioVariable_ReadAsArray_RET PyArrayObject *
#define NioVariable_ReadAsArray_PROTO \
	  Py_PROTO((NioVariableObject *var, NioIndex *indices))

/* Write array. Returns -1 if there was an error.  */
#define NioVariable_WriteArray_RET int
#define NioVariable_WriteArray_PROTO \
	  Py_PROTO((NioVariableObject *var, NioIndex *indices, \
		    PyObject *array))

/* Get file attribute */
#define NioFile_GetAttribute_RET PyObject *
#define NioFile_GetAttribute_PROTO \
	  Py_PROTO((NioFileObject *var, char *name))

/* Set file attribute */
#define NioFile_SetAttribute_RET int
#define NioFile_SetAttribute_PROTO \
	  Py_PROTO((NioFileObject *var, char *name, PyObject *value))

/* Set file attribute to string value */
#define NioFile_SetAttributeString_RET int
#define NioFile_SetAttributeString_PROTO \
	  Py_PROTO((NioFileObject *var, char *name, char *value))

/* Get variable attribute */
#define NioVariable_GetAttribute_RET PyObject *
#define NioVariable_GetAttribute_PROTO \
	  Py_PROTO((NioVariableObject *var, char *name))

/* Set variable attribute */
#define NioVariable_SetAttribute_RET int
#define NioVariable_SetAttribute_PROTO \
	  Py_PROTO((NioVariableObject *var, char *name, PyObject *value))

/* Set variable attribute to string value */
#define NioVariable_SetAttributeString_RET int
#define NioVariable_SetAttributeString_PROTO \
	  Py_PROTO((NioVariableObject *var, char *name, char *value))

/* Add entry to the history */
#define NioFile_AddHistoryLine_RET int
#define NioFile_AddHistoryLine_PROTO \
	  Py_PROTO((NioFileObject *self, char *text))

/* Write string. Returns -1 if there was an error.  */
#define NioVariable_WriteString_RET int
#define NioVariable_WriteString_PROTO \
	  Py_PROTO((NioVariableObject *var, PyBytesObject *value))

/* Read string  */
#define NioVariable_ReadAsString_RET PyBytesObject *
#define NioVariable_ReadAsString_PROTO \
	  Py_PROTO((NioVariableObject *var))



#ifdef _NIO_MODULE

/* Type object declarations */
static PyTypeObject NioFile_Type;
static PyTypeObject NioVariable_Type;

/* Type check macros */
#define NioFile_Check(op) ((op)->ob_type == &NioFile_Type)
#define NioVariable_Check(op) ((op)->ob_type == &NioVariable_Type)

/* C API function declarations */
static NioFile_Open_RET NioFile_Open NioFile_Open_PROTO;
static NioFile_Close_RET NioFile_Close NioFile_Close_PROTO;
/*
static NioFile_Sync_RET NioFile_Sync NioFile_Sync_PROTO;
*/
static NioFile_CreateDimension_RET NioFile_CreateDimension \
  NioFile_CreateDimension_PROTO;
static NioFile_CreateChunkDimension_RET NioFile_CreateChunkDimension \
  NioFile_CreateChunkDimension_PROTO;
static NioFile_CreateVariable_RET NioFile_CreateVariable \
  NioFile_CreateVariable_PROTO;
static NioFile_GetVariable_RET NioFile_GetVariable \
  NioFile_GetVariable_PROTO;
static NioVariable_GetRank_RET NioVariable_GetRank \
  NioVariable_GetRank_PROTO;
static NioVariable_GetShape_RET NioVariable_GetShape \
  NioVariable_GetShape_PROTO;
static NioVariable_Indices_RET NioVariable_Indices \
  NioVariable_Indices_PROTO;
static NioVariable_ReadAsArray_RET NioVariable_ReadAsArray \
  NioVariable_ReadAsArray_PROTO;
static NioVariable_ReadAsString_RET NioVariable_ReadAsString \
  NioVariable_ReadAsString_PROTO;
static NioVariable_WriteArray_RET NioVariable_WriteArray \
  NioVariable_WriteArray_PROTO;
static NioVariable_WriteString_RET NioVariable_WriteString \
  NioVariable_WriteString_PROTO;
static NioFile_GetAttribute_RET NioFile_GetAttribute \
  NioFile_GetAttribute_PROTO;
static NioFile_SetAttribute_RET NioFile_SetAttribute \
  NioFile_SetAttribute_PROTO;
static NioFile_SetAttributeString_RET NioFile_SetAttributeString \
  NioFile_SetAttributeString_PROTO;
static NioVariable_GetAttribute_RET NioVariable_GetAttribute \
  NioVariable_GetAttribute_PROTO;
static NioVariable_SetAttribute_RET NioVariable_SetAttribute \
  NioVariable_SetAttribute_PROTO;
static NioVariable_SetAttributeString_RET \
  NioVariable_SetAttributeString \
  NioVariable_SetAttributeString_PROTO;
static NioFile_AddHistoryLine_RET NioFile_AddHistoryLine \
  NioFile_AddHistoryLine_PROTO;
static NioFile_CreateVLEN_RET NioFile_CreateVLEN NioFile_CreateVLEN_PROTO;
static NioFile_CreateCOMPOUND_RET NioFile_CreateCOMPOUND NioFile_CreateCOMPOUND_PROTO;
static NioFile_CreateCOMPOUNDtype_RET NioFile_CreateCOMPOUNDtype NioFile_CreateCOMPOUNDtype_PROTO;

#else

/* C API address pointer */ 
static void **PyNIO_API;

/* Type check macros */
#define NioFile_Check(op) \
   ((op)->ob_type == (PyTypeObject *)PyNIO_API[NioFile_Type_NUM])
#define NioVariable_Check(op) \
   ((op)->ob_type == (PyTypeObject *)PyNIO_API[NioVariable_Type_NUM])

/* C API function declarations */
#define NioFile_Open \
  (*(NioFile_Open_RET (*)NioFile_Open_PROTO) \
   PyNIO_API[NioFile_Open_NUM])
#define NioFile_Close \
  (*(NioFile_Close_RET (*)NioFile_Close_PROTO) \
   PyNIO_API[NioFile_Close_NUM])
#define NioFile_Sync \
  (*(NioFile_Sync_RET (*)NioFile_Sync_PROTO) \
   PyNIO_API[NioFile_Sync_NUM])
#define NioFile_CreateDimension \
  (*(NioFile_CreateDimension_RET (*)NioFile_CreateDimension_PROTO) \
   PyNIO_API[NioFile_CreateDimension_NUM])
#define NioFile_CreateChunkDimension \
  (*(NioFile_CreateChunkDimension_RET (*)NioFile_CreateChunkDimension_PROTO) \
   PyNIO_API[NioFile_CreateChunkDimension_NUM])
#define NioFile_CreateVariable \
  (*(NioFile_CreateVariable_RET (*)NioFile_CreateVariable_PROTO) \
   PyNIO_API[NioFile_CreateVariable_NUM])
#define NioFile_GetVariable \
  (*(NioFile_GetVariable_RET (*)NioFile_GetVariable_PROTO) \
   PyNIO_API[NioFile_GetVariable_NUM])
#define NioVariable_GetRank \
  (*(NioVariable_GetRank_RET (*)NioVariable_GetRank_PROTO) \
   PyNIO_API[NioVariable_GetRank_NUM])
#define NioVariable_GetShape \
  (*(NioVariable_GetShape_RET (*)NioVariable_GetShape_PROTO) \
   PyNIO_API[NioVariable_GetShape_NUM])
#define NioVariable_Indices \
  (*(NioVariable_Indices_RET (*)NioVariable_Indices_PROTO) \
   PyNIO_API[NioVariable_Indices_NUM])
#define NioVariable_ReadAsArray \
  (*(NioVariable_ReadAsArray_RET (*)NioVariable_ReadAsArray_PROTO) \
   PyNIO_API[NioVariable_ReadAsArray_NUM])
#define NioVariable_ReadAsString \
  (*(NioVariable_ReadAsString_RET (*)NioVariable_ReadAsString_PROTO) \
   PyNIO_API[NioVariable_ReadAsString_NUM])
#define NioVariable_WriteArray \
  (*(NioVariable_WriteArray_RET (*)NioVariable_WriteArray_PROTO) \
   PyNIO_API[NioVariable_WriteArray_NUM])
#define NioVariable_WriteString \
  (*(NioVariable_WriteString_RET (*)NioVariable_WriteString_PROTO) \
   PyNIO_API[NioVariable_WriteString_NUM])
#define NioFile_GetAttribute \
  (*(NioFile_GetAttribute_RET (*)NioFile_GetAttribute_PROTO) \
   PyNIO_API[NioFile_GetAttribute_NUM])
#define NioFile_SetAttribute \
  (*(NioFile_SetAttribute_RET (*)NioFile_SetAttribute_PROTO) \
   PyNIO_API[NioFile_SetAttribute_NUM])
#define NioFile_SetAttributeString \
  (*(NioFile_SetAttributeString_RET \
     (*)NioFile_SetAttributeString_PROTO) \
   PyNIO_API[NioFile_SetAttributeString_NUM])
#define NioVariable_GetAttribute \
  (*(NioVariable_GetAttribute_RET (*)NioVariable_GetAttribute_PROTO) \
   PyNIO_API[NioVariable_GetAttribute_NUM])
#define NioVariable_SetAttribute \
  (*(NioVariable_SetAttribute_RET (*)NioVariable_SetAttribute_PROTO) \
   PyNIO_API[NioVariable_SetAttribute_NUM])
#define NioVariable_SetAttributeString \
  (*(NioVariable_SetAttributeString_RET \
     (*)NioVariable_SetAttributeString_PROTO) \
   PyNIO_API[NioVariable_SetAttributeString_NUM])
#define NioFile_AddHistoryLine \
  (*(NioFile_AddHistoryLine_RET \
     (*)NioFile_AddHistoryLine_PROTO) \
   PyNIO_API[NioFile_AddHistoryLine_NUM])

#define import_NIO() \
{ \
  PyObject *module = PyImport_ImportModule("nio"); \
  if (module != NULL) { \
    PyObject *module_dict = PyModule_GetDict(module); \
    PyObject *c_api_object = PyDict_GetItemString(module_dict, "_C_API"); \
    if (PyCObject_Check(c_api_object)) { \
      PyNIO_API = (void **)PyCObject_AsVoidPtr(c_api_object); \
    } \
  } \
}

#endif

#define	PyArray_VLEN		NCL_vlen
#define PyArray_ENUM		NCL_enum
#define PyArray_OPAQUE		NCL_opaque
#define PyArray_COMPOUND	NCL_compound
#define PyArray_REFERENCE	NCL_reference
#define PyArray_LIST		NCL_list
#define PyArray_LISTARRAY	NCL_listarray

typedef enum
{
    PyArray_VLENLTR = 'v',
    PyArray_COMPOUNDLTR = 'x',
    PyArray_ENUMLTR = 'u',
    PyArray_OPAQUELTR = 'a',
    PyArray_REFERENCELTR = 'r',
    PyArray_LISTLTR = 't',
    PyArray_LISTARRAYLTR = 'y'
} PYNIOEXTRATYPECHAR;

#ifdef __cplusplus
}
#endif
#endif /* Py_NIOMODULE_H */
