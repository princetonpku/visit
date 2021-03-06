// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <PDBPluginInfo.h>
#include <avtPDBFileFormat.h>
#include <avtMTSDFileFormatInterface.h>
#include <avtGenericDatabase.h>
#include <avtPDBOptions.h>

// ****************************************************************************
//  Method:  PDBCommonPluginInfo::GetDatabaseType
//
//  Purpose:
//    Returns the type of a PDB database.
//
//  Programmer:  generated by xml2info
//  Creation:    omitted
//
// ****************************************************************************
DatabaseType
PDBCommonPluginInfo::GetDatabaseType()
{
    return DB_TYPE_MTSD;
}

// ****************************************************************************
//  Method: PDBCommonPluginInfo::SetupDatabase
//
//  Purpose:
//      Sets up a PDB database.
//
//  Arguments:
//      list    A list of file names.
//      nList   The number of timesteps in list.
//      nBlocks The number of blocks in the list.
//
//  Returns:    A PDB database from list.
//
//  Programmer: whitlocb -- generated by xml2info
//  Creation:   Tue Apr 29 14:06:11 PST 2003
//
//  Modifications:
//    Brad Whitlock, Mon Jun 30 16:16:19 PST 2003
//    I had to add some custom code so the first file in the list gets opened
//    immediately. I also recoded how initialization occurs because
//    avtPDBFileFormat's constructor can throw an exception if we're not
//    opening a supported flavor of PDB.
//
//    Brad Whitlock, Tue Sep 16 11:42:56 PDT 2003
//    I rewrote this method so the plugin can have internal file formats
//    that have varying file format interfaces.
//
//    Brad Whitlock, Fri Dec 9 17:37:53 PST 2005
//    Renamed to PDB_CreateFileFormatInterface.
//
// ****************************************************************************

avtDatabase *
PDBCommonPluginInfo::SetupDatabase(const char *const *list,
                                   int nList, int nBlock)
{
    avtDatabase *db = 0;

    //
    // Create a file format interface based on information in the files.
    //
    avtFileFormatInterface *inter = PDB_CreateFileFormatInterface(list,
                                                                  nList,
                                                                  nBlock,
                                                                  readOptions);

    // If we created a file format interface, try creating a database.
    if(inter)
    {
        // Try and create the database using the interface that was created.
        TRY
        {
            db = new avtGenericDatabase(inter);
        }
        CATCH(VisItException)
        {
            delete inter;
            delete db;
            RETHROW;
        }
        ENDTRY
    }

    return db;
}


// ****************************************************************************
//  Method: PDBCommonPluginInfo::GetReadOptions
//
//  Purpose:
//      Gets the read options.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

DBOptionsAttributes *
PDBCommonPluginInfo::GetReadOptions() const
{
    return GetPDBReadOptions();
}

// ****************************************************************************
//  Method: PDBCommonPluginInfo::GetWriteOptions
//
//  Purpose:
//      Gets the write options.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

DBOptionsAttributes *
PDBCommonPluginInfo::GetWriteOptions() const
{
    return GetPDBWriteOptions();
}

