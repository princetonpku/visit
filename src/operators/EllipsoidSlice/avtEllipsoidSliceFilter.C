// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//  File: avtEllipsoidSliceFilter.C
// ************************************************************************* //

#include <avtEllipsoidSliceFilter.h>
#include <vtkVisItCutter.h>
#include <vtkTransform.h>
#include <vtkQuadric.h>

// ****************************************************************************
//  Method: avtEllipsoidSliceFilter constructor
//
//  Programmer: pugmire -- generated by xml2avt
//  Creation:   Tue Jun 3 09:44:03 PDT 2014
//
// ****************************************************************************

avtEllipsoidSliceFilter::avtEllipsoidSliceFilter()
{
}


// ****************************************************************************
//  Method: avtEllipsoidSliceFilter destructor
//
//  Programmer: pugmire -- generated by xml2avt
//  Creation:   Tue Jun 3 09:44:03 PDT 2014
//
//  Modifications:
//
// ****************************************************************************

avtEllipsoidSliceFilter::~avtEllipsoidSliceFilter()
{
}


// ****************************************************************************
//  Method:  avtEllipsoidSliceFilter::Create
//
//  Programmer: pugmire -- generated by xml2avt
//  Creation:   Tue Jun 3 09:44:03 PDT 2014
//
// ****************************************************************************

avtFilter *
avtEllipsoidSliceFilter::Create()
{
    return new avtEllipsoidSliceFilter();
}


// ****************************************************************************
//  Method:      avtEllipsoidSliceFilter::SetAtts
//
//  Purpose:
//      Sets the state of the filter based on the attribute object.
//
//  Arguments:
//      a        The attributes to use.
//
//  Programmer: pugmire -- generated by xml2avt
//  Creation:   Tue Jun 3 09:44:03 PDT 2014
//
// ****************************************************************************

void
avtEllipsoidSliceFilter::SetAtts(const AttributeGroup *a)
{
    atts = *(const EllipsoidSliceAttributes*)a;
}


// ****************************************************************************
//  Method: avtEllipsoidSliceFilter::Equivalent
//
//  Purpose:
//      Returns true if creating a new avtEllipsoidSliceFilter with the given
//      parameters would result in an equivalent avtEllipsoidSliceFilter.
//
//  Programmer: pugmire -- generated by xml2avt
//  Creation:   Tue Jun 3 09:44:03 PDT 2014
//
// ****************************************************************************

bool
avtEllipsoidSliceFilter::Equivalent(const AttributeGroup *a)
{
    return (atts == *(EllipsoidSliceAttributes*)a);
}


// ****************************************************************************
//  Method: avtEllipsoidSliceFilter::ExecuteData
//
//  Purpose:
//      Sends the specified input and output through the EllipsoidSlice filter.
//
//  Arguments:
//      in_dr      The input data representation.
//
//  Returns:       The output data representation.
//
//  Programmer: pugmire -- generated by xml2avt
//  Creation:   Tue Jun 3 09:44:03 PDT 2014
//
//  Modifications:
//    Eric Brugger, Thu Jul 24 13:23:21 PDT 2014
//    Modified the class to work with avtDataRepresentation.
//
//    Eric Brugger, Tue Aug 25 10:09:02 PDT 2015
//    Modified the routine to return NULL if the output data set had no
//    geometry.
//
// ****************************************************************************

avtDataRepresentation *
avtEllipsoidSliceFilter::ExecuteData(avtDataRepresentation *in_dr)
{
    //
    // Get the VTK data set.
    //
    vtkDataSet *in_ds = in_dr->GetDataVTK();

    vtkQuadric *quadric = vtkQuadric::New();

    double coeffs[10];

    //Create a unit sphere, then scale, rotate it.
    coeffs[0] = 1.0;
    coeffs[1] = 1.0;
    coeffs[2] = 1.0;
    coeffs[3] = 0.;
    coeffs[4] = 0.;
    coeffs[5] = 0.;
    coeffs[6] = 0.;
    coeffs[7] = 0.;
    coeffs[8] = 0.;
    coeffs[9] = -1.0;
    quadric->SetCoefficients(coeffs);

    vtkTransform *t = vtkTransform::New();
    t->Scale(1./atts.GetRadii()[0], 1./atts.GetRadii()[1], 1./atts.GetRadii()[2]);
    t->RotateX(atts.GetRotationAngle()[0]);
    t->RotateY(atts.GetRotationAngle()[1]);
    t->RotateZ(atts.GetRotationAngle()[2]);
    t->Translate(-atts.GetOrigin()[0], -atts.GetOrigin()[1], -atts.GetOrigin()[2]);

    quadric->SetTransform(t);
    t->Delete();

    vtkVisItCutter *cutter = vtkVisItCutter::New();

    cutter->SetCutFunction(quadric);
    cutter->SetInputData(in_ds);
    cutter->Update();

    vtkDataSet *out_ds = cutter->GetOutput();
    
    avtDataRepresentation *out_dr = NULL;
    if (out_ds->GetNumberOfCells() > 0)
    {
        out_dr = new avtDataRepresentation(out_ds,
            in_dr->GetDomain(), in_dr->GetLabel());
    }

    quadric->Delete();
    cutter->Delete();
    
    return out_dr;
}


