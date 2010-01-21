# ----------------------------------------------------------------------------
#  CLASSES: nightly
#
#  Test Case:  elevate.py
#
#  Tests:      mesh      - 2D rectilinear
#                          3D rectilinear, multiple domain,
#                          2D curvilinear, multiple domain
#              plots     - pc, mesh, filled boundary
#              operators - elevate
#              selection - none
#
#  Defect ID:  '5379, '5934 '6260, '6768
#
#  Programmer: Hank Childs
#  Date:       February 3, 2005
#
#  Modifications:
#
#    Hank Childs, Tue Jun  7 14:16:02 PDT 2005
#    Add tests for lighting of slices after elevation.
#
#    Hank Childs, Tue Nov 15 07:17:22 PST 2005
#    Add tests for macro expressions as secondary variables.
#
#    Hank Childs, Thu Jan 10 15:52:00 PST 2008
#    Add test for recenter expression with material plot.
#
#    Hank Childs, Wed Jan 16 17:26:03 PST 2008
#    Add testing for the "zeroFlag".
#
#    Mark C. Miller, Wed Jan 20 07:37:11 PST 2010
#    Added ability to swtich between Silo's HDF5 and PDB data.
# ----------------------------------------------------------------------------


OpenDatabase("../data/silo_%s_test_data/rect2d.silo"%SILO_MODE)

#One zonal variable
AddPlot("Pseudocolor", "u")
AddOperator("Elevate")
DrawPlots()
v = GetView3D()
v.viewNormal = (-0.707, 0, 0.707)
SetView3D(v)
Test("elevate01")

#One nodal variable
ChangeActivePlotsVar("d")
Test("elevate02")

#Primary variable zonal, Secondary variable zonal 
ChangeActivePlotsVar("p")
elevate_atts = ElevateAttributes()
elevate_atts.variable = "d"
SetOperatorOptions(elevate_atts)
Test("elevate03")

#Primary variable zonal, secondary nodal.
elevate_atts.variable = "u"
SetOperatorOptions(elevate_atts)
Test("elevate04")

#Primary variable nodal, secondary nodal.
ChangeActivePlotsVar("v")
Test("elevate05")

#Primary variable nodal, secondary zonal.
elevate_atts.variable = "p"
elevate_atts.useXYLimits = 1
SetOperatorOptions(elevate_atts)
Test("elevate06")

DeleteAllPlots()

AddPlot("Mesh", "quadmesh2d")
AddOperator("Elevate")
elevate_atts.variable = "p"
elevate_atts.useXYLimits = 1
SetOperatorOptions(elevate_atts)
DrawPlots()
Test("elevate07")

DeleteAllPlots()
AddPlot("FilledBoundary", "mat1")
AddOperator("Elevate")
elevate_atts.variable = "u"
elevate_atts.useXYLimits = 1
SetOperatorOptions(elevate_atts)
DrawPlots()
Test("elevate08")

DeleteAllPlots()
OpenDatabase("../data/silo_%s_test_data/rect3d.silo"%SILO_MODE)
AddPlot("Pseudocolor", "d")
AddOperator("Slice")
AddOperator("Elevate")
DrawPlots()
Test("elevate09")

# Testing expressions.  Test that macro expressions work as secondary
# variables ('6768).
DeleteAllPlots()
OpenDatabase("../data/silo_%s_test_data/noise.silo"%SILO_MODE)
DefineScalarExpression("vv", "hgslice+polar_radius(Mesh2D)")
AddPlot("Pseudocolor", "hgslice")
AddOperator("Elevate")
elevate_atts.variable = "vv"
SetOperatorOptions(elevate_atts)
DrawPlots()
Test("elevate10")

# Filled boundary with recentered expression
DeleteAllPlots()
OpenDatabase("../data/silo_%s_test_data/rect2d.silo"%SILO_MODE)
DefineScalarExpression("d2", "recenter(d)")
AddPlot("FilledBoundary", "mat1")
AddOperator("Elevate")
elevate_atts.variable = "d2"
SetOperatorOptions(elevate_atts)
DrawPlots()
Test("elevate11")

# Boundary plots that are elevated by zero height (no variable). '8346.
DeleteAllPlots()
OpenDatabase("../data/silo_%s_test_data/ucd2d.silo"%SILO_MODE)
AddPlot("Boundary", "mat1")
AddOperator("Elevate")
e = ElevateAttributes()
e.zeroFlag = 1
SetOperatorOptions(e)
DrawPlots()
v = GetView3D()
v.viewNormal = (0.5, 0.5, 0.5)
SetView3D(v)
Test("elevate12")

Exit()
