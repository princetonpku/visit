// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                              avtVMetricOddy.C                             //
// ************************************************************************* //

#include "avtVMetricOddy.h"

#include <vtkCellType.h>

#include <verdict.h>

// ****************************************************************************
//  Method: avtVMetricOddy::Metric
//
//  Purpose:
//      Inspect an element and calculate the cell oddy.
//
//  Arguments:
//      coords    The set of xyz points for the cell.
//      numPoints The number of xyz points for the cell.
//      type      The vtk type of the cell.
//
//  Returns:      The oddy of the cell, or defaultValue if not supported.
//
//  Programmer:   Akira Haddox
//  Creation:     June 13, 2002
//
//  Modifications:
//
//    Hank Childs, Thu Oct 17 08:07:53 PDT 2002
//    Update for new verdict interface.
//
// ****************************************************************************

double avtVMetricOddy::Metric (double coords[][3], int type)
{
#ifdef HAVE_VERDICT 
    switch (type)
    {
        case VTK_HEXAHEDRON:
        case VTK_VOXEL:
            return v_hex_oddy(8, coords);

        case VTK_QUAD:
            return v_quad_oddy(4, coords);
    }
#endif
    return -1;
}
