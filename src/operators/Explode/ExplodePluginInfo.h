// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ****************************************************************************
//  File: ExplodePluginInfo.h
// ****************************************************************************

#ifndef EXPLODE_PLUGIN_INFO_H
#define EXPLODE_PLUGIN_INFO_H
#include <OperatorPluginInfo.h>
#include <operator_plugin_exports.h>

class ExplodeAttributes;

// ****************************************************************************
//  Class: ExplodePluginInfo
//
//  Purpose:
//    Five classes that provide all the information about an Explode operator
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
//  Modifications:
//
// ****************************************************************************

class ExplodeGeneralPluginInfo : public virtual GeneralOperatorPluginInfo
{
  public:
    virtual const char *GetName() const;
    virtual const char *GetVersion() const;
    virtual const char *GetID() const;
    virtual bool  EnabledByDefault() const;
    virtual const char *GetCategoryName() const;
};

class ExplodeCommonPluginInfo : public virtual CommonOperatorPluginInfo, public virtual ExplodeGeneralPluginInfo
{
  public:
    virtual AttributeSubject *AllocAttributes();
    virtual void CopyAttributes(AttributeSubject *to, AttributeSubject *from);
};

class ExplodeGUIPluginInfo : public virtual GUIOperatorPluginInfo, public virtual ExplodeCommonPluginInfo
{
  public:
    virtual QString *GetMenuName() const;
    virtual QvisPostableWindowObserver *CreatePluginWindow(int type,
        AttributeSubject *attr, const QString &caption, const QString &shortName,
        QvisNotepadArea *notepad);
};

class ExplodeViewerEnginePluginInfo : public virtual ViewerEngineOperatorPluginInfo, public virtual ExplodeCommonPluginInfo
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
    static ExplodeAttributes *defaultAtts;
    static ExplodeAttributes *clientAtts;
    // User-defined functions
  public:
    void PrivateSetOperatorAtts(AttributeSubject *, const avtPlotMetaData &);
};

class ExplodeViewerPluginInfo : public virtual ViewerOperatorPluginInfo, public virtual ExplodeViewerEnginePluginInfo
{
  public:
};

class ExplodeEnginePluginInfo : public virtual EngineOperatorPluginInfo, public virtual ExplodeViewerEnginePluginInfo
{
  public:
    virtual avtPluginFilter *AllocAvtPluginFilter();
};

class ExplodeScriptingPluginInfo : public virtual ScriptingOperatorPluginInfo, public virtual ExplodeCommonPluginInfo
{
  public:
    virtual void InitializePlugin(AttributeSubject *subj, void *data);
    virtual void *GetMethodTable(int *nMethods);
    virtual bool TypesMatch(void *pyobject);
    virtual char *GetLogString();
    virtual void SetDefaults(const AttributeSubject *atts);
};

#endif
