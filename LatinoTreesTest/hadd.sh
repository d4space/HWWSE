echo "hadd for root files: "


FILES="latino_stepB_*_numEvent1000.root"
ToTalFiles=""

for f in $FILES
do
  echo "Processing $f file..."
  ToTalFiles+=" $f"

done

echo "Total files: $ToTalFiles"

hadd latino_stepB_WZJet_n1000ForEachData.root $ToTalFiles

