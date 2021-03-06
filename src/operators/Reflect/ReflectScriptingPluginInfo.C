// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//  ReflectScriptingPluginInfo.C
// ************************************************************************* //
#include <PyReflectAttributes.h>
#include <ReflectPluginInfo.h>

VISIT_OPERATOR_PLUGIN_ENTRY(Reflect,Scripting)

// ****************************************************************************
// Method: ReflectScriptingPluginInfo::InitializePlugin
//
// Purpose:
//   Calls the initialization function for the plugin.
//
// Arguments:
//   subj    : A pointer to the plugin's state object.
//   data    : A pointer to data to be used by the observer function.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

void
ReflectScriptingPluginInfo::InitializePlugin(AttributeSubject *subj,
    void *data)
{
    PyReflectAttributes_StartUp((ReflectAttributes *)subj, data);
}

// ****************************************************************************
// Method: ReflectScriptingPluginInfo::GetMethodTable
//
// Purpose:
//   Returns a pointer to the plugin's Python method table. These methods are
//   added to the top-level visit module's methods.
//
// Arguments:
//   nMethods : Returns the number of methods in the method table.
//
// Returns:    A pointer to the method table.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

void *
ReflectScriptingPluginInfo::GetMethodTable(int *nMethods)
{
    return PyReflectAttributes_GetMethodTable(nMethods);
}

// ****************************************************************************
// Method: ReflectScriptingPluginInfo::TypesMatch
//
// Purpose:
//   Returns whether or not the input PyObject is Reflect plot attributes.
//
// Arguments:
//   pyobject : A PyObject cast to void*.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

bool
ReflectScriptingPluginInfo::TypesMatch(void *pyobject)
{
    return PyReflectAttributes_Check((PyObject *)pyobject);
}

// ****************************************************************************
// Method: ReflectScriptingPluginInfo::GetLogString
//
// Purpose:
//   Gets a string representation of the current attributes.
//
// Arguments:
//   val : Whether or not to log state information.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

char *
ReflectScriptingPluginInfo::GetLogString()
{
    std::string s(PyReflectAttributes_GetLogString());
    char *v = new char[s.size() + 1];
    strcpy(v, s.c_str());
    return v;
}

// ****************************************************************************
// Method: ReflectScriptingPluginInfo::SetDefaults
//
// Purpose:
//   Used to set the default values for a plugin's state object.
//
// Arguments:
//   atts : The new state.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

void
ReflectScriptingPluginInfo::SetDefaults(const AttributeSubject *atts)
{
    PyReflectAttributes_SetDefaults((const ReflectAttributes *)atts);
}
