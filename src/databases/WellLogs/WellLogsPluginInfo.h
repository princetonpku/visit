// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ****************************************************************************
//  WellLogsPluginInfo.h
// ****************************************************************************

#ifndef WELLLOGS_PLUGIN_INFO_H
#define WELLLOGS_PLUGIN_INFO_H
#include <DatabasePluginInfo.h>
#include <database_plugin_exports.h>

class avtDatabase;
class avtDatabaseWriter;

// ****************************************************************************
//  Class: WellLogsDatabasePluginInfo
//
//  Purpose:
//    Classes that provide all the information about the WellLogs plugin.
//    Portions are separated into pieces relevant to the appropriate
//    components of VisIt.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
//  Modifications:
//
// ****************************************************************************

class WellLogsGeneralPluginInfo : public virtual GeneralDatabasePluginInfo
{
  public:
    virtual const char *GetName() const;
    virtual const char *GetVersion() const;
    virtual const char *GetID() const;
    virtual bool  EnabledByDefault() const;
    virtual bool  HasWriter() const;
    virtual std::vector<std::string> GetDefaultFilePatterns() const;
    virtual bool  AreDefaultFilePatternsStrict() const;
    virtual bool  OpensWholeDirectory() const;
};

class WellLogsCommonPluginInfo : public virtual CommonDatabasePluginInfo, public virtual WellLogsGeneralPluginInfo
{
  public:
    virtual DatabaseType              GetDatabaseType();
    virtual avtDatabase              *SetupDatabase(const char * const *list,
                                                    int nList, int nBlock);
};

class WellLogsMDServerPluginInfo : public virtual MDServerDatabasePluginInfo, public virtual WellLogsCommonPluginInfo
{
  public:
    // this makes compilers happy... remove if we ever have functions here
    virtual void dummy();
};

class WellLogsEnginePluginInfo : public virtual EngineDatabasePluginInfo, public virtual WellLogsCommonPluginInfo
{
  public:
    virtual avtDatabaseWriter        *GetWriter(void);
};

#endif
