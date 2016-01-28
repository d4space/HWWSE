import glob
OutFile = open('list.txt','w')
AllFile= glob.glob("*.root")
for item in AllFile:
  print 'tree->Add(filesPath + "'+item+'");'
  OutFile.write('tree->Add(filesPath + "'+item+'");'+'\n')
