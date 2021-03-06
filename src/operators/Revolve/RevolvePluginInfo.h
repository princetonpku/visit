// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ****************************************************************************
//  File: RevolvePluginInfo.h
// ****************************************************************************

#ifndef REVOLVE_PLUGIN_INFO_H
#define REVOLVE_PLUGIN_INFO_H
#include <OperatorPluginInfo.h>
#include <operator_plugin_exports.h>

class RevolveAttributes;

// ****************************************************************************
//  Class: RevolvePluginInfo
//
//  Purpose:
//    Five classes that provide all the information about an Revolve operator
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
//  Modifications:
//
// ****************************************************************************

class RevolveGeneralPluginInfo : public virtual GeneralOperatorPluginInfo
{
  public:
    virtual const char *GetName() const;
    virtual const char *GetVersion() const;
    virtual const char *GetID() const;
    virtual bool  EnabledByDefault() const;
    virtual const char *GetCategoryName() const;
};

class RevolveCommonPluginInfo : public virtual CommonOperatorPluginInfo, public virtual RevolveGeneralPluginInfo
{
  public:
    virtual AttributeSubject *AllocAttributes();
    virtual void CopyAttributes(AttributeSubject *to, AttributeSubject *from);
};

class RevolveGUIPluginInfo : public virtual GUIOperatorPluginInfo, public virtual RevolveCommonPluginInfo
{
  public:
    virtual QString *GetMenuName() const;
    virtual QvisPostableWindowObserver *CreatePluginWindow(int type,
        AttributeSubject *attr, const QString &caption, const QString &shortName,
        QvisNotepadArea *notepad);
    virtual const char **XPMIconData() const;
};

class RevolveViewerEnginePluginInfo : public virtual ViewerEngineOperatorPluginInfo, public virtual RevolveCommonPluginInfo
{
  public:
    virtual AttributeSubject *GetClientAtts();
    virtual AttributeSubject *GetDefaultAtts();
    virtual void SetClientAtts(AttributeSubject *atts);
    virtual void GetClientAtts(AttributeSubject *atts);

    virtual void InitializeOperatorAtts(AttributeSubject *atts,
                                        const avtPlotMetaData &plot,
                                        const bool fromDefault);
    virtual void UpdateOperatorAtts(AttributeSubject *atts,
                                    const avtPlotMetaData &plot);
    virtual const char *GetMenuName() const;

    static void InitializeGlobalObjects();
  private:
    static RevolveAttributes *defaultAtts;
    static RevolveAttributes *clientAtts;
};

class RevolveViewerPluginInfo : public virtual ViewerOperatorPluginInfo, public virtual RevolveViewerEnginePluginInfo
{
  public:
    virtual const char **XPMIconData() const;
};

class RevolveEnginePluginInfo : public virtual EngineOperatorPluginInfo, public virtual RevolveViewerEnginePluginInfo
{
  public:
    virtual avtPluginFilter *AllocAvtPluginFilter();
};

class RevolveScriptingPluginInfo : public virtual ScriptingOperatorPluginInfo, public virtual RevolveCommonPluginInfo
{
  public:
    virtual void InitializePlugin(AttributeSubject *subj, void *data);
    virtual void *GetMethodTable(int *nMethods);
    virtual bool TypesMatch(void *pyobject);
    virtual char *GetLogString();
    virtual void SetDefaults(const AttributeSubject *atts);
};

#endif
