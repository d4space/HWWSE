echo "hadd for root files: "


FILES="higgsCombineNoCust_*.MultiDimFit.mH125.6.123456.root"
ToTalFiles=""

for f in $FILES
do
  echo "Processing $f file..."
  ToTalFiles+=" $f"

done

echo "Total files: $ToTalFiles"

hadd higgsCombineNoCust_All.MultiDimFit.mH125.6.123456.root $ToTalFiles

