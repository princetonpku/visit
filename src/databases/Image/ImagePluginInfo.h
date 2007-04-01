// ****************************************************************************
//                               ImagePluginInfo.h
// ****************************************************************************

#ifndef IMAGE_PLUGIN_INFO_H
#define IMAGE_PLUGIN_INFO_H
#include <DatabasePluginInfo.h>
#include <database_plugin_exports.h>

class avtDatabase;
class avtDatabaseWriter;

// ****************************************************************************
//  Class: ImageDatabasePluginInfo
//
//  Purpose:
//    Classes that provide all the information about the Image plugin.
//    Portions are separated into pieces relevant to the appropriate
//    components of VisIt.
//
//  Programmer: wojtan2 -- generated by xml2info
//  Creation:   Tue Jun 15 15:08:03 PST 2004
//
//  Modifications:
//
// ****************************************************************************

class ImageGeneralPluginInfo : public virtual GeneralDatabasePluginInfo
{
  public:
    virtual char *GetName() const;
    virtual char *GetVersion() const;
    virtual char *GetID() const;
    virtual bool  EnabledByDefault() const;
};

class ImageCommonPluginInfo : public virtual CommonDatabasePluginInfo, public virtual ImageGeneralPluginInfo
{
  public:
    virtual DatabaseType              GetDatabaseType();
    virtual std::vector<std::string>  GetDefaultExtensions();
    virtual avtDatabase              *SetupDatabase(const char * const *list,
                                                    int nList, int nBlock);
    virtual avtDatabaseWriter        *GetWriter(void);
};

class ImageMDServerPluginInfo : public virtual MDServerDatabasePluginInfo, public virtual ImageCommonPluginInfo
{
  public:
    // this makes compilers happy... remove if we ever have functions here
    virtual void dummy();
};

class ImageEnginePluginInfo : public virtual EngineDatabasePluginInfo, public virtual ImageCommonPluginInfo
{
  public:
    // this makes compilers happy... remove if we ever have functions here
    virtual void dummy();
};

#endif
