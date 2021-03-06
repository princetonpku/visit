// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                          avtSamplePointsSink.C                            //
// ************************************************************************* //

#include <avtSamplePointsSink.h>

#include <DebugStream.h>
#include <ImproperUseException.h>

#include <cstring>

// ****************************************************************************
//  Method: avtSamplePointsSink constructor
//
//  Programmer: Hank Childs
//  Creation:   May 29, 2001
//
// ****************************************************************************

avtSamplePointsSink::avtSamplePointsSink()
{
    input = NULL;
}


// ****************************************************************************
//  Method: avtSamplePointsSink destructor
//
//  Purpose:
//      Defines the destructor.  Note: this should not be inlined in the header
//      because it causes problems for certain compilers.
//
//  Programmer: Hank Childs
//  Creation:   February 5, 2004
//
// ****************************************************************************

avtSamplePointsSink::~avtSamplePointsSink()
{
    ;
}


// ****************************************************************************
//  Method: avtSamplePointsSink::SetTypedInput
//
//  Purpose:
//      Sets the input of the sink and performs some type checking.
//
//  Arguments:
//      in      The sample points as a data object.
//
//  Programmer: Hank Childs
//  Creation:   May 29, 2001
//
//  Modifications:
//    Brad Whitlock, Thu Apr 4 14:50:16 PST 2002
//    Made CopyTo an inline template function.
//
// ****************************************************************************

void
avtSamplePointsSink::SetTypedInput(avtDataObject_p in)
{
    if (strcmp(in->GetType(), "avtSamplePoints") != 0)
    {
        //
        // Should create a new exception here, but I'm under time constraints.
        //
        debug1 << "Looking for avtSamplePoints, but found type \""
               << in->GetType() << "\"." << endl;
        EXCEPTION0(ImproperUseException);
    }

    CopyTo(input, in);
}


// ****************************************************************************
//  Method: avtSamplePointsSink::GetInput
//
//  Purpose:
//      Gets the input of the sink (properly typed as an avtDataObject).
//
//  Returns:    The input of the sink.
//
//  Programmer: Hank Childs
//  Creation:   May 29, 2001
//
//  Modifications:
//    Brad Whitlock, Thu Apr 4 14:50:50 PST 2002
//    Made CopyTo an inline template function.
//
// ****************************************************************************

avtDataObject_p
avtSamplePointsSink::GetInput(void)
{
    avtDataObject_p rv;
    CopyTo(rv, input);
    return rv;
}

// ****************************************************************************
//  Method: avtSamplePointsSink::GetInput
//
//  Purpose:
//      Gets the input of the sink (properly typed as an avtDataObject).
//
//  Returns:    The input of the sink.
//
//  Programmer: Tom Fogal
//  Creation:   June 23, 2008
//
// ****************************************************************************

const avtDataObject_p
avtSamplePointsSink::GetInput(void) const
{
    avtDataObject_p rv;
    CopyTo(rv, input);
    return rv;
}
