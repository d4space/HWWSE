import glob
import os
AllFile= glob.glob("cratio_hww2l2v_13TeV_of0j_*.png")
for item in AllFile:
  newItem = item.replace('hww2l2v_13TeV_of0j', 'met_13TeV_of')
  print 'old name:', item
  print 'new name:', newItem
  cmd = 'mv '+item+' '+newItem
  os.system(cmd)
