if [ $# -lt 1 ]; then
    echo "  "
    echo "  ./turn2LatinoTree index"
    echo "  "
    exit -1
fi

export INDEX=$1


python cmssw2latino.py  stepB_${INDEX}_numEvent1000.root

rm -rf stepB_${INDEX}_numEvent1000.root
