// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                       avtZoneTypeRankExpression.C                         //
// ************************************************************************* //

#include <avtZoneTypeRankExpression.h>

#include <vtkCellData.h>
#include <vtkCellType.h>
#include <vtkDataSet.h>
#include <vtkIntArray.h>

// ****************************************************************************
//  Method: avtZoneTypeRankExpression constructor
//
//  Purpose:
//      Defines the constructor.  Note: this should not be inlined in the
//      header because it causes problems for certain compilers.
//
//  Programmer: Mark C. Miller 
//  Creation:   November 15, 2006 
//
// ****************************************************************************

avtZoneTypeRankExpression::avtZoneTypeRankExpression()
{
    ;
}


// ****************************************************************************
//  Method: avtZoneTypeRankExpression destructor
//
//  Purpose:
//      Defines the destructor.  Note: this should not be inlined in the header
//      because it causes problems for certain compilers.
//
//  Programmer: Mark C. Miller
//  Creation:   November 15, 2006 
//
// ****************************************************************************

avtZoneTypeRankExpression::~avtZoneTypeRankExpression()
{
    ;
}


// ****************************************************************************
//  Method: avtZoneTypeRankExpression::DeriveVariable
//
//  Purpose:
//      Determines the zon type of a cell.
//
//  Arguments:
//      inDS      The input dataset.
//
//  Returns:      The derived variable.  The calling class must free this
//                memory.
//
//  Programmer:   Mark C. Miller 
//  Creation:     November 15, 2006 
//
//  Modifications:
//    Mark C. Miller, Wed Apr  2 09:46:47 PDT 2008
//    Added case statement to set character for zone type.
//
//    Mark C. Miller, Thu Oct 23 15:59:17 PDT 2014
//    Made the output 3 chars long instead of one. Added cases for more
//    element types.
// ****************************************************************************

vtkDataArray *
avtZoneTypeRankExpression::DeriveVariable(vtkDataSet *in_ds, int currentDomainsIndex)
{
    vtkIdType ncells = in_ds->GetNumberOfCells();

    vtkIntArray *rv = vtkIntArray::New();
    rv->SetNumberOfComponents(1);
    rv->SetNumberOfTuples(ncells);
    for (vtkIdType i = 0 ; i < ncells ; i++)
    {
        int rank = -1;
        switch (in_ds->GetCellType(i))
        {
            // topo dim = -1 cell types
            case VTK_EMPTY_CELL:                       rank = 0; break;

            // topo dim = 0 cell types
            case VTK_VERTEX:                           rank = 1; break;
            case VTK_POLY_VERTEX:                      rank = 2; break;
            case VTK_CONVEX_POINT_SET:                 rank = 3; break;

            // topo dim = 1 cell types
            case VTK_LINE:                             rank = 4; break;
            case VTK_POLY_LINE:                        rank = 5; break;
            case VTK_QUADRATIC_EDGE:                   rank = 6; break;
            case VTK_HIGHER_ORDER_EDGE:                rank = 7; break;
            case VTK_CUBIC_LINE:                       rank = 8; break;
            case VTK_PARAMETRIC_CURVE:                 rank = 9; break;

            // topo dim = 2 cell types
            case VTK_TRIANGLE:                         rank = 10; break;
            case VTK_TRIANGLE_STRIP:                   rank = 11; break;
            case VTK_POLYGON:                          rank = 12; break;
            case VTK_PIXEL:                            rank = 13; break;
            case VTK_QUAD:                             rank = 14; break;
            case VTK_QUADRATIC_LINEAR_QUAD:            rank = 15; break;
            case VTK_QUADRATIC_TRIANGLE:               rank = 16; break;
            case VTK_QUADRATIC_QUAD:                   rank = 17; break;
            case VTK_BIQUADRATIC_QUAD:                 rank = 18; break;
            case VTK_BIQUADRATIC_TRIANGLE:             rank = 19; break;
            case VTK_PARAMETRIC_TRI_SURFACE:           rank = 20; break;
            case VTK_PARAMETRIC_QUAD_SURFACE:          rank = 21; break;
            case VTK_PARAMETRIC_SURFACE:               rank = 22; break;
            case VTK_HIGHER_ORDER_TRIANGLE:            rank = 23; break;
            case VTK_HIGHER_ORDER_QUAD:                rank = 24; break;
            case VTK_HIGHER_ORDER_POLYGON:             rank = 25; break;

            // topo dim = 3 cell types
            case VTK_TETRA:                            rank = 26; break;
            case VTK_PYRAMID:                          rank = 27; break;
            case VTK_WEDGE:                            rank = 28; break;
            case VTK_VOXEL:                            rank = 29; break;
            case VTK_HEXAHEDRON:                       rank = 30; break;
            case VTK_POLYHEDRON:                       rank = 31; break;
            case VTK_QUADRATIC_TETRA:                  rank = 32; break;
            case VTK_QUADRATIC_HEXAHEDRON:             rank = 33; break;
            case VTK_QUADRATIC_LINEAR_WEDGE:           rank = 34; break;
            case VTK_QUADRATIC_WEDGE:                  rank = 35; break;
            case VTK_QUADRATIC_PYRAMID:                rank = 36; break;
            case VTK_TRIQUADRATIC_HEXAHEDRON:          rank = 37; break;
            case VTK_BIQUADRATIC_QUADRATIC_WEDGE:      rank = 38; break;
            case VTK_BIQUADRATIC_QUADRATIC_HEXAHEDRON: rank = 39; break;
            case VTK_PARAMETRIC_TETRA_REGION:          rank = 40; break;
            case VTK_PARAMETRIC_HEX_REGION:            rank = 41; break;
            case VTK_HIGHER_ORDER_TETRAHEDRON:         rank = 42; break;
            case VTK_HIGHER_ORDER_PYRAMID:             rank = 43; break;
            case VTK_HIGHER_ORDER_WEDGE:               rank = 44; break;
            case VTK_HIGHER_ORDER_HEXAHEDRON:          rank = 45; break;
        }            

        rv->SetTuple1(i, rank);
    }

    return rv;
}

// ****************************************************************************
//  Method: avtZoneTypeRankExpression::UpdateDataObjectInfo
//
//  Purpose: Tell the output this is a treat as ascii variable
//
//  Programmer:   Mark C. Miller 
//  Creation:     April 2, 2008 
//
//  Modifications
//
//  Mark C. Miller, Wed Mar  4 18:31:50 PST 2020
//  Remove call to SetTreatAsASCII.
// ****************************************************************************

void
avtZoneTypeRankExpression::UpdateDataObjectInfo(void)
{
    avtSingleInputExpressionFilter::UpdateDataObjectInfo();

    avtDataAttributes &outAtts = GetOutput()->GetInfo().GetAttributes();
}
