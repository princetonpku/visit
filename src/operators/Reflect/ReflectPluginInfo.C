// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ****************************************************************************
//  File: ReflectPluginInfo.C
// ****************************************************************************

#include <ReflectPluginInfo.h>
#include <ReflectAttributes.h>

#include <visit-config.h>
VISIT_PLUGIN_VERSION(Reflect,OP_EXPORT)

VISIT_OPERATOR_PLUGIN_ENTRY(Reflect,General)

// ****************************************************************************
//  Method: ReflectGeneralPluginInfo::GetName
//
//  Purpose:
//    Return the name of the operator plugin.
//
//  Returns:    A pointer to the name of the operator plugin.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
ReflectGeneralPluginInfo::GetName() const
{
    return "Reflect";
}

// ****************************************************************************
//  Method: ReflectGeneralPluginInfo::GetVersion
//
//  Purpose:
//    Return the version of the operator plugin.
//
//  Returns:    A pointer to the version of the operator plugin.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
ReflectGeneralPluginInfo::GetVersion() const
{
    return "1.0";
}

// ****************************************************************************
//  Method: ReflectGeneralPluginInfo::GetID
//
//  Purpose:
//    Return the id of the operator plugin.
//
//  Returns:    A pointer to the id of the operator plugin.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
ReflectGeneralPluginInfo::GetID() const
{
    return "Reflect_1.0";
}
// ****************************************************************************
//  Method: ReflectGeneralPluginInfo::EnabledByDefault
//
//  Purpose:
//    Return true if this plugin should be enabled by default; false otherwise.
//
//  Returns:    true/false
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

bool
ReflectGeneralPluginInfo::EnabledByDefault() const
{
    return true;
}

// ****************************************************************************
//  Method: ReflectGeneralPluginInfo::GetCategoryName
//
//  Purpose:
//    Return the category name to which the operator belongs.
//
//  Returns:    Return the category name to which the operator belongs.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
ReflectGeneralPluginInfo::GetCategoryName() const
{
    return "Transforms";
}
