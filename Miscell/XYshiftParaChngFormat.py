import sys

if len(sys.argv) <= 1 :
  print "no argument" 
  print "Usage : XYshiftParaChngFormat.py [File to convert] >& [txt]"
  print "ex : XYshiftParaChngFormat.py multPhiCorr_741_25nsDY_cfi.py >& XYShiftMC_76X.txt"
  exit()

FileToConvert = sys.argv[1]

f = open(FileToConvert,'r')
lines = f.readlines()
f.close()

# define global variables
Section = None
ptclType = None
nameParVar = None
netaMin= None
netaMax= None
formula = None
ncountpx = None
splitpx = None
spx1 = None
spx2 = None
spx3 = None
px1 = None
px2 = None
px3 = None
spy1 = None
spy2 = None
spy3 = None
py1 = None
py2 = None
py3 = None

for line in lines:
  #print(line.find('name'))	# if found : return offset, if not found : return -1
  if line.find('name') != -1:
    Section = line[23:-4]	# slice charactor index 
  if line.find('type') != -1:
    ptclType = line[21:-3]	# slice charactor index 
  if line.find('varType') != -1:
    nameParVar = line[24:-3]	# slice charactor index 
  if line.find('etaMin') != -1:
    netaMin = line[24:-3]	# slice charactor index 
  if line.find('etaMax') != -1:
    netaMax = line[24:-3]	# slice charactor index 
  if line.find('fx') != -1:
    formula = line[21:-4]	# slice charactor index 
  if line.find('px') != -1:
    ncountpx = line.count(',')  # count number of "," character = number of value
    if ncountpx == 2:
      splitpx = line.split(',')	# split by "," character 
      spx1 = splitpx[0]
      spx2 = splitpx[1]
      px1 = spx1[21:]
      px2 = spx2[:-1]
    if ncountpx == 3:
      splitpx = line.split(',')	# split by "," character 
      spx1 = splitpx[0]
      spx2 = splitpx[1]
      spx3 = splitpx[2]
      px1 = spx1[21:]
      px2 = spx2[0:]
      px3 = spx3[:-1]
  if line.find('py') != -1:
    ncountpy = line.count(',')  # count number of "," character = number of value
    if ncountpy == 2:
      splitpy = line.split(',')	# split by "," character 
      spy1 = splitpy[0]
      spy2 = splitpy[1]
      py1 = spy1[21:]
      py2 = spy2[:-1]
      print ('[%s]') % Section
      print ('{%s 1 eta 1 %s %s}') % (ptclType,nameParVar,formula)
      print ('X %s %s %s %s %s') % (netaMin,netaMax, ncountpx, px1, px2)
      print ('Y %s %s %s %s %s') % (netaMin,netaMax, ncountpy, py1, py2)
    if ncountpy == 3:
      splitpy = line.split(',')	# split by "," character 
      spy1 = splitpy[0]
      spy2 = splitpy[1]
      spy3 = splitpy[2]
      py1 = spy1[21:]
      py2 = spy2[0:]
      py3 = spy3[:-1]
      print ('[%s]') % Section
      print ('{%s 1 eta 1 %s %s}') % (ptclType,nameParVar,formula)
      print ('X %s %s %s %s %s %s') % (netaMin,netaMax, ncountpx, px1, px2, px3)
      print ('Y %s %s %s %s %s %s') % (netaMin,netaMax, ncountpy, py1, py2, py3)
     
#    t = line.split('"')	# split line by (something)

# method 2
#f = open("./multPhiCorr_741_25nsDY_cfi.py",'r')
#while True:
#	line = f.readline()
#	if not line: break
#	print(line)
#f.close()

#method 3
#f = open("./multPhiCorr_741_25nsDY_cfi.py",'r')
#data = f.rad()
#print(data)
#f.close()




