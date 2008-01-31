# ----------------------------------------------------------------------------
#  MODES: serial
#  CLASSES: nightly
#
#  Test Case:  parcoords.py
#
#  Tests:      Tests the parallel coordinates plot
#
#  Programmer: Jeremy Meredith
#  Date:       January 31, 2008
#
#  Modifications:
#
# ----------------------------------------------------------------------------

# Turn off all annotation
a = AnnotationAttributes()
a.axesFlag2D = 0
a.axesFlag = 0
a.triadFlag = 0
a.bboxFlag = 0
a.userInfoFlag = 0
a.databaseInfoFlag = 0
a.legendInfoFlag = 0
a.backgroundMode = 0
a.foregroundColor = (0, 0, 0, 255)
a.backgroundColor = (255, 255, 255, 255)
SetAnnotationAttributes(a)

TestSection("Test plot options")

OpenDatabase("../data/noise.silo")

#
# Set up a simple 3 variable parallel coordinates plot.
#
p = ParallelCoordinatesAttributes()
p.orderedAxisNames = ("hardyglobal", "shepardglobal", "chromeVf")
p.axisMinima = (-1e+37, -1e+37, -1e+37)
p.axisMaxima = (+1e+37, +1e+37, +1e+37)
p.extentMinima = (-1e+37, -1e+37, -1e+37)
p.extentMaxima = (+1e+37, +1e+37, +1e+37)
p.drawLines = 1
p.linesColor = (128, 0, 0, 255)
p.drawContext = 1
p.contextGamma = 2
p.contextNumPartitions = 512
p.contextColor = (0, 220, 0, 255)
p.drawLinesOnlyIfExtentsOn = 1
SetDefaultPlotOptions(p)
AddPlot("ParallelCoordinates", "hardyglobal")
DrawPlots()
Test("parcoords_01")

#
# Try setting some appearance-related attributes
#
p.contextGamma = 2.9
p.contextNumPartitions = 128
p.contextColor = (200, 0, 255, 255)
SetPlotOptions(p)
Test("parcoords_02")

p.contextGamma = 2.9
p.contextNumPartitions = 32
p.contextColor = (200, 0, 255, 255)
p.drawLinesOnlyIfExtentsOn = 0
SetPlotOptions(p)
Test("parcoords_03")

# Add an axis and make sure it works
p.orderedAxisNames = ("hardyglobal", "shepardglobal", "chromeVf", "radial")
p.axisMinima = (0,0,0,0)
p.axisMaxima = (0,0,0,0)
p.extentMinima = (0,0,0,0)
p.extentMaxima = (0,0,0,0)
p.drawLinesOnlyIfExtentsOn = 1
SetPlotOptions(p)
Test("parcoords_04")

Exit()
