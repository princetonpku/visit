// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ****************************************************************************
//  File: InverseGhostZonePluginInfo.C
// ****************************************************************************

#include <InverseGhostZonePluginInfo.h>
#include <InverseGhostZoneAttributes.h>

#include <visit-config.h>
VISIT_PLUGIN_VERSION(InverseGhostZone,OP_EXPORT)

VISIT_OPERATOR_PLUGIN_ENTRY(InverseGhostZone,General)

// ****************************************************************************
//  Method: InverseGhostZoneGeneralPluginInfo::GetName
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
InverseGhostZoneGeneralPluginInfo::GetName() const
{
    return "InverseGhostZone";
}

// ****************************************************************************
//  Method: InverseGhostZoneGeneralPluginInfo::GetVersion
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
InverseGhostZoneGeneralPluginInfo::GetVersion() const
{
    return "1.0";
}

// ****************************************************************************
//  Method: InverseGhostZoneGeneralPluginInfo::GetID
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
InverseGhostZoneGeneralPluginInfo::GetID() const
{
    return "InverseGhostZone_1.0";
}
// ****************************************************************************
//  Method: InverseGhostZoneGeneralPluginInfo::EnabledByDefault
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
InverseGhostZoneGeneralPluginInfo::EnabledByDefault() const
{
    return true;
}

// ****************************************************************************
//  Method: InverseGhostZoneGeneralPluginInfo::GetCategoryName
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
InverseGhostZoneGeneralPluginInfo::GetCategoryName() const
{
    return "Debugging";
}
