
 #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 # 1. Produce the histograms
 #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ./run.sh 0
 ./run.sh 1
 
 #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 # 2. Print top-background values and data-driven number (alplha)
 #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 root -l -b -q standAloneTop.C
 
 
 #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 # 3. Print DY scale, top scale and WW cross section
 #
 #    njet       = {0, 1, 2, 3}
 #    ichannel   = {-1, All, SF, OF, MuMu, EE, EMu, MuE}
 #    luminosity = 19365
 #    printLevel = {SILENT, NOTE, DEBUG}
 #    drawTheXS  = false
 #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 root -l runXS.C


 # To compute the WW cross section removing the "XYZ" cut
 #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 root -l -b -q runXS.C\(0,All,19365,\"XYZ\",1\)


 # To compute the WW cross section at "XYZ" cut level
 #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 root -l -b -q runXS.C\(0,All,19365,\"XYZ\",0\)


 #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 # 4. Draw distributions
 #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 root -l drawDistributions.C

#----------------------------
# 5. SS for 0+1+2 X "--"+"++"
#----------------------------
 ./combineLatinoTree_SS.sh
 vi drawDistributions.sh
 use drawDistributions_SS.C NJET=10 for this inclusive SS

