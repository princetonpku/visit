// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                      avtOriginalDataNumZonesQuery.C                       //
// ************************************************************************* //

#include <avtOriginalDataNumZonesQuery.h>

#include <avtOriginatingSource.h>
#include <ParsingExprList.h>

#include <string>

// ****************************************************************************
//  Method: avtOriginalDataNumZonesQuery constructor
//
//  Programmer: Kathleen Bonnell 
//  Creation:   February 18, 2004 
//
//  Modifications:
//
// ****************************************************************************

avtOriginalDataNumZonesQuery::avtOriginalDataNumZonesQuery() : avtNumZonesQuery() 
{
}


// ****************************************************************************
//  Method: avtOriginalDataNumZonesQuery destructor
//
//  Programmer: Kathleen Bonnell 
//  Creation:   February 18, 2004 
//
//  Modifications:
//
// ****************************************************************************
avtOriginalDataNumZonesQuery::~avtOriginalDataNumZonesQuery() 
{
}


// ****************************************************************************
//  Method: avtOriginalDataNumZonesQuery::ApplyFilters
//
//  Purpose:
//    Makes sure the entire SIL is used. 
//
//  Programmer: Kathleen Bonnell
//  Creation:   February 10, 2004 
//
//  Modifications:
//    Kathleen Bonnell, Mon Mar  7 18:09:14 PST 2005
//    Ensure that the correct DB variable is used.
//
//    Hank Childs, Fri Sep 23 10:53:37 PDT 2005
//    Data spec's DBVariable has been deprecated.  Use a different path.
//
// ****************************************************************************

avtDataObject_p
avtOriginalDataNumZonesQuery::ApplyFilters(avtDataObject_p inData)
{
    avtDataRequest_p dataRequest = inData->GetOriginatingSource()->
        GetGeneralContract()->GetDataRequest();

    std::string dbVar = ParsingExprList::GetRealVariable(
                       queryAtts.GetVariables()[0]);
    avtDataRequest_p new_dataRequest = new avtDataRequest(dataRequest,
                                                                dbVar.c_str());

    avtContract_p contract = 
        new avtContract(new_dataRequest, queryAtts.GetPipeIndex()); 

    avtDataObject_p retObj;
    CopyTo(retObj, inData);
    retObj->Update(contract);
    return retObj;
}

