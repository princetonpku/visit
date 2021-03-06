// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <PyReflectAttributes.h>
#include <ObserverToCallback.h>
#include <stdio.h>
#include <Py2and3Support.h>

// ****************************************************************************
// Module: PyReflectAttributes
//
// Purpose:
//   This class contains attributes for the reflect operator.
//
// Note:       Autogenerated by xml2python. Do not modify by hand!
//
// Programmer: xml2python
// Creation:   omitted
//
// ****************************************************************************

//
// This struct contains the Python type information and a ReflectAttributes.
//
struct ReflectAttributesObject
{
    PyObject_HEAD
    ReflectAttributes *data;
    bool        owns;
    PyObject   *parent;
};

//
// Internal prototypes
//
static PyObject *NewReflectAttributes(int);
std::string
PyReflectAttributes_ToString(const ReflectAttributes *atts, const char *prefix)
{
    std::string str;
    char tmpStr[1000];

    const char *octant_names = "PXPYPZ, NXPYPZ, PXNYPZ, NXNYPZ, PXPYNZ, "
        "NXPYNZ, PXNYNZ, NXNYNZ";
    switch (atts->GetOctant())
    {
      case ReflectAttributes::PXPYPZ:
          snprintf(tmpStr, 1000, "%soctant = %sPXPYPZ  # %s\n", prefix, prefix, octant_names);
          str += tmpStr;
          break;
      case ReflectAttributes::NXPYPZ:
          snprintf(tmpStr, 1000, "%soctant = %sNXPYPZ  # %s\n", prefix, prefix, octant_names);
          str += tmpStr;
          break;
      case ReflectAttributes::PXNYPZ:
          snprintf(tmpStr, 1000, "%soctant = %sPXNYPZ  # %s\n", prefix, prefix, octant_names);
          str += tmpStr;
          break;
      case ReflectAttributes::NXNYPZ:
          snprintf(tmpStr, 1000, "%soctant = %sNXNYPZ  # %s\n", prefix, prefix, octant_names);
          str += tmpStr;
          break;
      case ReflectAttributes::PXPYNZ:
          snprintf(tmpStr, 1000, "%soctant = %sPXPYNZ  # %s\n", prefix, prefix, octant_names);
          str += tmpStr;
          break;
      case ReflectAttributes::NXPYNZ:
          snprintf(tmpStr, 1000, "%soctant = %sNXPYNZ  # %s\n", prefix, prefix, octant_names);
          str += tmpStr;
          break;
      case ReflectAttributes::PXNYNZ:
          snprintf(tmpStr, 1000, "%soctant = %sPXNYNZ  # %s\n", prefix, prefix, octant_names);
          str += tmpStr;
          break;
      case ReflectAttributes::NXNYNZ:
          snprintf(tmpStr, 1000, "%soctant = %sNXNYNZ  # %s\n", prefix, prefix, octant_names);
          str += tmpStr;
          break;
      default:
          break;
    }

    if(atts->GetUseXBoundary())
        snprintf(tmpStr, 1000, "%suseXBoundary = 1\n", prefix);
    else
        snprintf(tmpStr, 1000, "%suseXBoundary = 0\n", prefix);
    str += tmpStr;
    snprintf(tmpStr, 1000, "%sspecifiedX = %g\n", prefix, atts->GetSpecifiedX());
    str += tmpStr;
    if(atts->GetUseYBoundary())
        snprintf(tmpStr, 1000, "%suseYBoundary = 1\n", prefix);
    else
        snprintf(tmpStr, 1000, "%suseYBoundary = 0\n", prefix);
    str += tmpStr;
    snprintf(tmpStr, 1000, "%sspecifiedY = %g\n", prefix, atts->GetSpecifiedY());
    str += tmpStr;
    if(atts->GetUseZBoundary())
        snprintf(tmpStr, 1000, "%suseZBoundary = 1\n", prefix);
    else
        snprintf(tmpStr, 1000, "%suseZBoundary = 0\n", prefix);
    str += tmpStr;
    snprintf(tmpStr, 1000, "%sspecifiedZ = %g\n", prefix, atts->GetSpecifiedZ());
    str += tmpStr;
    {   const int *reflections = atts->GetReflections();
        snprintf(tmpStr, 1000, "%sreflections = (", prefix);
        str += tmpStr;
        for(int i = 0; i < 8; ++i)
        {
            snprintf(tmpStr, 1000, "%d", reflections[i]);
            str += tmpStr;
            if(i < 7)
            {
                snprintf(tmpStr, 1000, ", ");
                str += tmpStr;
            }
        }
        snprintf(tmpStr, 1000, ")\n");
        str += tmpStr;
    }
    {   const double *planePoint = atts->GetPlanePoint();
        snprintf(tmpStr, 1000, "%splanePoint = (", prefix);
        str += tmpStr;
        for(int i = 0; i < 3; ++i)
        {
            snprintf(tmpStr, 1000, "%g", planePoint[i]);
            str += tmpStr;
            if(i < 2)
            {
                snprintf(tmpStr, 1000, ", ");
                str += tmpStr;
            }
        }
        snprintf(tmpStr, 1000, ")\n");
        str += tmpStr;
    }
    {   const double *planeNormal = atts->GetPlaneNormal();
        snprintf(tmpStr, 1000, "%splaneNormal = (", prefix);
        str += tmpStr;
        for(int i = 0; i < 3; ++i)
        {
            snprintf(tmpStr, 1000, "%g", planeNormal[i]);
            str += tmpStr;
            if(i < 2)
            {
                snprintf(tmpStr, 1000, ", ");
                str += tmpStr;
            }
        }
        snprintf(tmpStr, 1000, ")\n");
        str += tmpStr;
    }
    const char *reflectType_names = "Plane, Axis";
    switch (atts->GetReflectType())
    {
      case ReflectAttributes::Plane:
          snprintf(tmpStr, 1000, "%sreflectType = %sPlane  # %s\n", prefix, prefix, reflectType_names);
          str += tmpStr;
          break;
      case ReflectAttributes::Axis:
          snprintf(tmpStr, 1000, "%sreflectType = %sAxis  # %s\n", prefix, prefix, reflectType_names);
          str += tmpStr;
          break;
      default:
          break;
    }

    return str;
}

static PyObject *
ReflectAttributes_Notify(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;
    obj->data->Notify();
    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ReflectAttributes_SetOctant(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;

    int ival;
    if(!PyArg_ParseTuple(args, "i", &ival))
        return NULL;

    // Set the octant in the object.
    if(ival >= 0 && ival < 8)
        obj->data->SetOctant(ReflectAttributes::Octant(ival));
    else
    {
        fprintf(stderr, "An invalid octant value was given. "
                        "Valid values are in the range of [0,7]. "
                        "You can also use the following names: "
                        "PXPYPZ, NXPYPZ, PXNYPZ, NXNYPZ, PXPYNZ, "
                        "NXPYNZ, PXNYNZ, NXNYNZ.");
        return NULL;
    }

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ReflectAttributes_GetOctant(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;
    PyObject *retval = PyInt_FromLong(long(obj->data->GetOctant()));
    return retval;
}

/*static*/ PyObject *
ReflectAttributes_SetUseXBoundary(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;

    int ival;
    if(!PyArg_ParseTuple(args, "i", &ival))
        return NULL;

    // Set the useXBoundary in the object.
    obj->data->SetUseXBoundary(ival != 0);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ReflectAttributes_GetUseXBoundary(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;
    PyObject *retval = PyInt_FromLong(obj->data->GetUseXBoundary()?1L:0L);
    return retval;
}

/*static*/ PyObject *
ReflectAttributes_SetSpecifiedX(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;

    double dval;
    if(!PyArg_ParseTuple(args, "d", &dval))
        return NULL;

    // Set the specifiedX in the object.
    obj->data->SetSpecifiedX(dval);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ReflectAttributes_GetSpecifiedX(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;
    PyObject *retval = PyFloat_FromDouble(obj->data->GetSpecifiedX());
    return retval;
}

/*static*/ PyObject *
ReflectAttributes_SetUseYBoundary(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;

    int ival;
    if(!PyArg_ParseTuple(args, "i", &ival))
        return NULL;

    // Set the useYBoundary in the object.
    obj->data->SetUseYBoundary(ival != 0);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ReflectAttributes_GetUseYBoundary(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;
    PyObject *retval = PyInt_FromLong(obj->data->GetUseYBoundary()?1L:0L);
    return retval;
}

/*static*/ PyObject *
ReflectAttributes_SetSpecifiedY(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;

    double dval;
    if(!PyArg_ParseTuple(args, "d", &dval))
        return NULL;

    // Set the specifiedY in the object.
    obj->data->SetSpecifiedY(dval);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ReflectAttributes_GetSpecifiedY(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;
    PyObject *retval = PyFloat_FromDouble(obj->data->GetSpecifiedY());
    return retval;
}

/*static*/ PyObject *
ReflectAttributes_SetUseZBoundary(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;

    int ival;
    if(!PyArg_ParseTuple(args, "i", &ival))
        return NULL;

    // Set the useZBoundary in the object.
    obj->data->SetUseZBoundary(ival != 0);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ReflectAttributes_GetUseZBoundary(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;
    PyObject *retval = PyInt_FromLong(obj->data->GetUseZBoundary()?1L:0L);
    return retval;
}

/*static*/ PyObject *
ReflectAttributes_SetSpecifiedZ(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;

    double dval;
    if(!PyArg_ParseTuple(args, "d", &dval))
        return NULL;

    // Set the specifiedZ in the object.
    obj->data->SetSpecifiedZ(dval);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ReflectAttributes_GetSpecifiedZ(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;
    PyObject *retval = PyFloat_FromDouble(obj->data->GetSpecifiedZ());
    return retval;
}

/*static*/ PyObject *
ReflectAttributes_SetReflections(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;

    int *ivals = obj->data->GetReflections();
    if(!PyArg_ParseTuple(args, "iiiiiiii", &ivals[0], &ivals[1], &ivals[2], &ivals[3], &ivals[4], &ivals[5], &ivals[6], &ivals[7]))
    {
        PyObject     *tuple;
        if(!PyArg_ParseTuple(args, "O", &tuple))
            return NULL;

        if(PyTuple_Check(tuple))
        {
            if(PyTuple_Size(tuple) != 8)
                return NULL;

            PyErr_Clear();
            for(int i = 0; i < PyTuple_Size(tuple); ++i)
            {
                PyObject *item = PyTuple_GET_ITEM(tuple, i);
                if(PyFloat_Check(item))
                    ivals[i] = int(PyFloat_AS_DOUBLE(item));
                else if(PyInt_Check(item))
                    ivals[i] = int(PyInt_AS_LONG(item));
                else if(PyLong_Check(item))
                    ivals[i] = int(PyLong_AsDouble(item));
                else
                    ivals[i] = 0;
            }
        }
        else
            return NULL;
    }

    // Mark the reflections in the object as modified.
    obj->data->SelectReflections();

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ReflectAttributes_GetReflections(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;
    // Allocate a tuple the with enough entries to hold the reflections.
    PyObject *retval = PyTuple_New(8);
    const int *reflections = obj->data->GetReflections();
    for(int i = 0; i < 8; ++i)
        PyTuple_SET_ITEM(retval, i, PyInt_FromLong(long(reflections[i])));
    return retval;
}

/*static*/ PyObject *
ReflectAttributes_SetPlanePoint(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;

    double *dvals = obj->data->GetPlanePoint();
    if(!PyArg_ParseTuple(args, "ddd", &dvals[0], &dvals[1], &dvals[2]))
    {
        PyObject     *tuple;
        if(!PyArg_ParseTuple(args, "O", &tuple))
            return NULL;

        if(PyTuple_Check(tuple))
        {
            if(PyTuple_Size(tuple) != 3)
                return NULL;

            PyErr_Clear();
            for(int i = 0; i < PyTuple_Size(tuple); ++i)
            {
                PyObject *item = PyTuple_GET_ITEM(tuple, i);
                if(PyFloat_Check(item))
                    dvals[i] = PyFloat_AS_DOUBLE(item);
                else if(PyInt_Check(item))
                    dvals[i] = double(PyInt_AS_LONG(item));
                else if(PyLong_Check(item))
                    dvals[i] = PyLong_AsDouble(item);
                else
                    dvals[i] = 0.;
            }
        }
        else
            return NULL;
    }

    // Mark the planePoint in the object as modified.
    obj->data->SelectPlanePoint();

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ReflectAttributes_GetPlanePoint(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;
    // Allocate a tuple the with enough entries to hold the planePoint.
    PyObject *retval = PyTuple_New(3);
    const double *planePoint = obj->data->GetPlanePoint();
    for(int i = 0; i < 3; ++i)
        PyTuple_SET_ITEM(retval, i, PyFloat_FromDouble(planePoint[i]));
    return retval;
}

/*static*/ PyObject *
ReflectAttributes_SetPlaneNormal(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;

    double *dvals = obj->data->GetPlaneNormal();
    if(!PyArg_ParseTuple(args, "ddd", &dvals[0], &dvals[1], &dvals[2]))
    {
        PyObject     *tuple;
        if(!PyArg_ParseTuple(args, "O", &tuple))
            return NULL;

        if(PyTuple_Check(tuple))
        {
            if(PyTuple_Size(tuple) != 3)
                return NULL;

            PyErr_Clear();
            for(int i = 0; i < PyTuple_Size(tuple); ++i)
            {
                PyObject *item = PyTuple_GET_ITEM(tuple, i);
                if(PyFloat_Check(item))
                    dvals[i] = PyFloat_AS_DOUBLE(item);
                else if(PyInt_Check(item))
                    dvals[i] = double(PyInt_AS_LONG(item));
                else if(PyLong_Check(item))
                    dvals[i] = PyLong_AsDouble(item);
                else
                    dvals[i] = 0.;
            }
        }
        else
            return NULL;
    }

    // Mark the planeNormal in the object as modified.
    obj->data->SelectPlaneNormal();

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ReflectAttributes_GetPlaneNormal(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;
    // Allocate a tuple the with enough entries to hold the planeNormal.
    PyObject *retval = PyTuple_New(3);
    const double *planeNormal = obj->data->GetPlaneNormal();
    for(int i = 0; i < 3; ++i)
        PyTuple_SET_ITEM(retval, i, PyFloat_FromDouble(planeNormal[i]));
    return retval;
}

/*static*/ PyObject *
ReflectAttributes_SetReflectType(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;

    int ival;
    if(!PyArg_ParseTuple(args, "i", &ival))
        return NULL;

    // Set the reflectType in the object.
    if(ival >= 0 && ival < 2)
        obj->data->SetReflectType(ReflectAttributes::ReflectType(ival));
    else
    {
        fprintf(stderr, "An invalid reflectType value was given. "
                        "Valid values are in the range of [0,1]. "
                        "You can also use the following names: "
                        "Plane, Axis.");
        return NULL;
    }

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ReflectAttributes_GetReflectType(PyObject *self, PyObject *args)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)self;
    PyObject *retval = PyInt_FromLong(long(obj->data->GetReflectType()));
    return retval;
}



PyMethodDef PyReflectAttributes_methods[REFLECTATTRIBUTES_NMETH] = {
    {"Notify", ReflectAttributes_Notify, METH_VARARGS},
    {"SetOctant", ReflectAttributes_SetOctant, METH_VARARGS},
    {"GetOctant", ReflectAttributes_GetOctant, METH_VARARGS},
    {"SetUseXBoundary", ReflectAttributes_SetUseXBoundary, METH_VARARGS},
    {"GetUseXBoundary", ReflectAttributes_GetUseXBoundary, METH_VARARGS},
    {"SetSpecifiedX", ReflectAttributes_SetSpecifiedX, METH_VARARGS},
    {"GetSpecifiedX", ReflectAttributes_GetSpecifiedX, METH_VARARGS},
    {"SetUseYBoundary", ReflectAttributes_SetUseYBoundary, METH_VARARGS},
    {"GetUseYBoundary", ReflectAttributes_GetUseYBoundary, METH_VARARGS},
    {"SetSpecifiedY", ReflectAttributes_SetSpecifiedY, METH_VARARGS},
    {"GetSpecifiedY", ReflectAttributes_GetSpecifiedY, METH_VARARGS},
    {"SetUseZBoundary", ReflectAttributes_SetUseZBoundary, METH_VARARGS},
    {"GetUseZBoundary", ReflectAttributes_GetUseZBoundary, METH_VARARGS},
    {"SetSpecifiedZ", ReflectAttributes_SetSpecifiedZ, METH_VARARGS},
    {"GetSpecifiedZ", ReflectAttributes_GetSpecifiedZ, METH_VARARGS},
    {"SetReflections", ReflectAttributes_SetReflections, METH_VARARGS},
    {"GetReflections", ReflectAttributes_GetReflections, METH_VARARGS},
    {"SetPlanePoint", ReflectAttributes_SetPlanePoint, METH_VARARGS},
    {"GetPlanePoint", ReflectAttributes_GetPlanePoint, METH_VARARGS},
    {"SetPlaneNormal", ReflectAttributes_SetPlaneNormal, METH_VARARGS},
    {"GetPlaneNormal", ReflectAttributes_GetPlaneNormal, METH_VARARGS},
    {"SetReflectType", ReflectAttributes_SetReflectType, METH_VARARGS},
    {"GetReflectType", ReflectAttributes_GetReflectType, METH_VARARGS},
    {NULL, NULL}
};

//
// Type functions
//

static void
ReflectAttributes_dealloc(PyObject *v)
{
   ReflectAttributesObject *obj = (ReflectAttributesObject *)v;
   if(obj->parent != 0)
       Py_DECREF(obj->parent);
   if(obj->owns)
       delete obj->data;
}

static PyObject *ReflectAttributes_richcompare(PyObject *self, PyObject *other, int op);
PyObject *
PyReflectAttributes_getattr(PyObject *self, char *name)
{
    if(strcmp(name, "octant") == 0)
        return ReflectAttributes_GetOctant(self, NULL);
    if(strcmp(name, "PXPYPZ") == 0)
        return PyInt_FromLong(long(ReflectAttributes::PXPYPZ));
    if(strcmp(name, "NXPYPZ") == 0)
        return PyInt_FromLong(long(ReflectAttributes::NXPYPZ));
    if(strcmp(name, "PXNYPZ") == 0)
        return PyInt_FromLong(long(ReflectAttributes::PXNYPZ));
    if(strcmp(name, "NXNYPZ") == 0)
        return PyInt_FromLong(long(ReflectAttributes::NXNYPZ));
    if(strcmp(name, "PXPYNZ") == 0)
        return PyInt_FromLong(long(ReflectAttributes::PXPYNZ));
    if(strcmp(name, "NXPYNZ") == 0)
        return PyInt_FromLong(long(ReflectAttributes::NXPYNZ));
    if(strcmp(name, "PXNYNZ") == 0)
        return PyInt_FromLong(long(ReflectAttributes::PXNYNZ));
    if(strcmp(name, "NXNYNZ") == 0)
        return PyInt_FromLong(long(ReflectAttributes::NXNYNZ));

    if(strcmp(name, "useXBoundary") == 0)
        return ReflectAttributes_GetUseXBoundary(self, NULL);
    if(strcmp(name, "specifiedX") == 0)
        return ReflectAttributes_GetSpecifiedX(self, NULL);
    if(strcmp(name, "useYBoundary") == 0)
        return ReflectAttributes_GetUseYBoundary(self, NULL);
    if(strcmp(name, "specifiedY") == 0)
        return ReflectAttributes_GetSpecifiedY(self, NULL);
    if(strcmp(name, "useZBoundary") == 0)
        return ReflectAttributes_GetUseZBoundary(self, NULL);
    if(strcmp(name, "specifiedZ") == 0)
        return ReflectAttributes_GetSpecifiedZ(self, NULL);
    if(strcmp(name, "reflections") == 0)
        return ReflectAttributes_GetReflections(self, NULL);
    if(strcmp(name, "planePoint") == 0)
        return ReflectAttributes_GetPlanePoint(self, NULL);
    if(strcmp(name, "planeNormal") == 0)
        return ReflectAttributes_GetPlaneNormal(self, NULL);
    if(strcmp(name, "reflectType") == 0)
        return ReflectAttributes_GetReflectType(self, NULL);
    if(strcmp(name, "Plane") == 0)
        return PyInt_FromLong(long(ReflectAttributes::Plane));
    if(strcmp(name, "Axis") == 0)
        return PyInt_FromLong(long(ReflectAttributes::Axis));


    return Py_FindMethod(PyReflectAttributes_methods, self, name);
}

int
PyReflectAttributes_setattr(PyObject *self, char *name, PyObject *args)
{
    // Create a tuple to contain the arguments since all of the Set
    // functions expect a tuple.
    PyObject *tuple = PyTuple_New(1);
    PyTuple_SET_ITEM(tuple, 0, args);
    Py_INCREF(args);
    PyObject *obj = NULL;

    if(strcmp(name, "octant") == 0)
        obj = ReflectAttributes_SetOctant(self, tuple);
    else if(strcmp(name, "useXBoundary") == 0)
        obj = ReflectAttributes_SetUseXBoundary(self, tuple);
    else if(strcmp(name, "specifiedX") == 0)
        obj = ReflectAttributes_SetSpecifiedX(self, tuple);
    else if(strcmp(name, "useYBoundary") == 0)
        obj = ReflectAttributes_SetUseYBoundary(self, tuple);
    else if(strcmp(name, "specifiedY") == 0)
        obj = ReflectAttributes_SetSpecifiedY(self, tuple);
    else if(strcmp(name, "useZBoundary") == 0)
        obj = ReflectAttributes_SetUseZBoundary(self, tuple);
    else if(strcmp(name, "specifiedZ") == 0)
        obj = ReflectAttributes_SetSpecifiedZ(self, tuple);
    else if(strcmp(name, "reflections") == 0)
        obj = ReflectAttributes_SetReflections(self, tuple);
    else if(strcmp(name, "planePoint") == 0)
        obj = ReflectAttributes_SetPlanePoint(self, tuple);
    else if(strcmp(name, "planeNormal") == 0)
        obj = ReflectAttributes_SetPlaneNormal(self, tuple);
    else if(strcmp(name, "reflectType") == 0)
        obj = ReflectAttributes_SetReflectType(self, tuple);

    if(obj != NULL)
        Py_DECREF(obj);

    Py_DECREF(tuple);
    if( obj == NULL)
        PyErr_Format(PyExc_RuntimeError, "Unable to set unknown attribute: '%s'", name);
    return (obj != NULL) ? 0 : -1;
}

static int
ReflectAttributes_print(PyObject *v, FILE *fp, int flags)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)v;
    fprintf(fp, "%s", PyReflectAttributes_ToString(obj->data, "").c_str());
    return 0;
}

PyObject *
ReflectAttributes_str(PyObject *v)
{
    ReflectAttributesObject *obj = (ReflectAttributesObject *)v;
    return PyString_FromString(PyReflectAttributes_ToString(obj->data,"").c_str());
}

//
// The doc string for the class.
//
#if PY_MAJOR_VERSION > 2 || (PY_MAJOR_VERSION == 2 && PY_MINOR_VERSION >= 5)
static const char *ReflectAttributes_Purpose = "This class contains attributes for the reflect operator.";
#else
static char *ReflectAttributes_Purpose = "This class contains attributes for the reflect operator.";
#endif

//
// Python Type Struct Def Macro from Py2and3Support.h
//
//         VISIT_PY_TYPE_OBJ( VPY_TYPE,
//                            VPY_NAME,
//                            VPY_OBJECT,
//                            VPY_DEALLOC,
//                            VPY_PRINT,
//                            VPY_GETATTR,
//                            VPY_SETATTR,
//                            VPY_STR,
//                            VPY_PURPOSE,
//                            VPY_RICHCOMP,
//                            VPY_AS_NUMBER)

//
// The type description structure
//

VISIT_PY_TYPE_OBJ(ReflectAttributesType,         \
                  "ReflectAttributes",           \
                  ReflectAttributesObject,       \
                  ReflectAttributes_dealloc,     \
                  ReflectAttributes_print,       \
                  PyReflectAttributes_getattr,   \
                  PyReflectAttributes_setattr,   \
                  ReflectAttributes_str,         \
                  ReflectAttributes_Purpose,     \
                  ReflectAttributes_richcompare, \
                  0); /* as_number*/

//
// Helper function for comparing.
//
static PyObject *
ReflectAttributes_richcompare(PyObject *self, PyObject *other, int op)
{
    // only compare against the same type 
    if ( Py_TYPE(self) != &ReflectAttributesType
         || Py_TYPE(other) != &ReflectAttributesType)
    {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }

    PyObject *res = NULL;
    ReflectAttributes *a = ((ReflectAttributesObject *)self)->data;
    ReflectAttributes *b = ((ReflectAttributesObject *)other)->data;

    switch (op)
    {
       case Py_EQ:
           res = (*a == *b) ? Py_True : Py_False;
           break;
       case Py_NE:
           res = (*a != *b) ? Py_True : Py_False;
           break;
       default:
           res = Py_NotImplemented;
           break;
    }

    Py_INCREF(res);
    return res;
}

//
// Helper functions for object allocation.
//

static ReflectAttributes *defaultAtts = 0;
static ReflectAttributes *currentAtts = 0;

static PyObject *
NewReflectAttributes(int useCurrent)
{
    ReflectAttributesObject *newObject;
    newObject = PyObject_NEW(ReflectAttributesObject, &ReflectAttributesType);
    if(newObject == NULL)
        return NULL;
    if(useCurrent && currentAtts != 0)
        newObject->data = new ReflectAttributes(*currentAtts);
    else if(defaultAtts != 0)
        newObject->data = new ReflectAttributes(*defaultAtts);
    else
        newObject->data = new ReflectAttributes;
    newObject->owns = true;
    newObject->parent = 0;
    return (PyObject *)newObject;
}

static PyObject *
WrapReflectAttributes(const ReflectAttributes *attr)
{
    ReflectAttributesObject *newObject;
    newObject = PyObject_NEW(ReflectAttributesObject, &ReflectAttributesType);
    if(newObject == NULL)
        return NULL;
    newObject->data = (ReflectAttributes *)attr;
    newObject->owns = false;
    newObject->parent = 0;
    return (PyObject *)newObject;
}

///////////////////////////////////////////////////////////////////////////////
//
// Interface that is exposed to the VisIt module.
//
///////////////////////////////////////////////////////////////////////////////

PyObject *
ReflectAttributes_new(PyObject *self, PyObject *args)
{
    int useCurrent = 0;
    if (!PyArg_ParseTuple(args, "i", &useCurrent))
    {
        if (!PyArg_ParseTuple(args, ""))
            return NULL;
        else
            PyErr_Clear();
    }

    return (PyObject *)NewReflectAttributes(useCurrent);
}

//
// Plugin method table. These methods are added to the visitmodule's methods.
//
static PyMethodDef ReflectAttributesMethods[] = {
    {"ReflectAttributes", ReflectAttributes_new, METH_VARARGS},
    {NULL,      NULL}        /* Sentinel */
};

static Observer *ReflectAttributesObserver = 0;

std::string
PyReflectAttributes_GetLogString()
{
    std::string s("ReflectAtts = ReflectAttributes()\n");
    if(currentAtts != 0)
        s += PyReflectAttributes_ToString(currentAtts, "ReflectAtts.");
    return s;
}

static void
PyReflectAttributes_CallLogRoutine(Subject *subj, void *data)
{
    typedef void (*logCallback)(const std::string &);
    logCallback cb = (logCallback)data;

    if(cb != 0)
    {
        std::string s("ReflectAtts = ReflectAttributes()\n");
        s += PyReflectAttributes_ToString(currentAtts, "ReflectAtts.");
        cb(s);
    }
}

void
PyReflectAttributes_StartUp(ReflectAttributes *subj, void *data)
{
    if(subj == 0)
        return;

    currentAtts = subj;
    PyReflectAttributes_SetDefaults(subj);

    //
    // Create the observer that will be notified when the attributes change.
    //
    if(ReflectAttributesObserver == 0)
    {
        ReflectAttributesObserver = new ObserverToCallback(subj,
            PyReflectAttributes_CallLogRoutine, (void *)data);
    }

}

void
PyReflectAttributes_CloseDown()
{
    delete defaultAtts;
    defaultAtts = 0;
    delete ReflectAttributesObserver;
    ReflectAttributesObserver = 0;
}

PyMethodDef *
PyReflectAttributes_GetMethodTable(int *nMethods)
{
    *nMethods = 1;
    return ReflectAttributesMethods;
}

bool
PyReflectAttributes_Check(PyObject *obj)
{
    return (obj->ob_type == &ReflectAttributesType);
}

ReflectAttributes *
PyReflectAttributes_FromPyObject(PyObject *obj)
{
    ReflectAttributesObject *obj2 = (ReflectAttributesObject *)obj;
    return obj2->data;
}

PyObject *
PyReflectAttributes_New()
{
    return NewReflectAttributes(0);
}

PyObject *
PyReflectAttributes_Wrap(const ReflectAttributes *attr)
{
    return WrapReflectAttributes(attr);
}

void
PyReflectAttributes_SetParent(PyObject *obj, PyObject *parent)
{
    ReflectAttributesObject *obj2 = (ReflectAttributesObject *)obj;
    obj2->parent = parent;
}

void
PyReflectAttributes_SetDefaults(const ReflectAttributes *atts)
{
    if(defaultAtts)
        delete defaultAtts;

    defaultAtts = new ReflectAttributes(*atts);
}

