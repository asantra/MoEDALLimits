
date
echo ${HOST}
 
tempDir=`mktemp -d -p /tmp/`
cd ${tempDir}
echo 'In temporary directory '${tempDir}

# setupATLAS
# rcSetup 2.0.19,Base

export AtlasSetup=/afs/cern.ch/atlas/software/dist/AtlasSetup
source $AtlasSetup/scripts/asetup.sh 17.2.1.4,x86_64,slc5,gcc43,runtime

#localSetupROOT
#source /afs/cern.ch/sw/lcg/app/releases/ROOT/5.30.00/x86_64-slc5-gcc43-opt/root/bin/thisroot.sh
#p=$PWD
#cd /afs/cern.ch/sw/lcg/app/releases/ROOT/5.30.00/x86_64-slc5-gcc43-opt/root/bin/
#source thisroot.sh
#cd $p

outDir='/atlas/users/pmermod/moedalLimits_13TeV/'

cp ${outDir}/* .

date

echo "starting xs limit calculations"
root -l -q -b calculate.C

echo 'done.'

date

cp *.root ${outDir}/

cd ${outDir}
ls -l

echo 'removing temporary directory'
rm -rf ${tempDir}

date
