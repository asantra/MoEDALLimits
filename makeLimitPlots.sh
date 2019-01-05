#! /bin/bash
## run like: bash makeLimitPlots.sh <PhotonFusion/DrellYan/Combined> <directoryName>

processName=$1
directoryName=$2

if [ $processName = "PhotonFusion" ]; then
   inputBetaText="PhotonFusion_Geom402_AllMMT_150KEvents_betaDependent.txt"
   inputNoBetaText="PhotonFusion_Geom402_AllMMT_150KEvents_betaIndependent.txt"
elif [ $processName = "DrellYan" ]; then
   inputBetaText="DrellYan_Geom402_AllMMT_150KEvents_betaDependent.txt"
   inputNoBetaText="DrellYan_Geom402_AllMMT_150KEvents_betaIndependent.txt"
else
   inputBetaText="Combined_PFandDY_Geom402_AllMMT_150KEvents_betaDependent.txt"
   inputNoBetaText="Combined_PFandDY_Geom402_AllMMT_150KEvents_betaIndependent.txt"
fi

echo "process chosen: ", $processName
echo "inputfiles Beta: ", $inputBetaText
echo "inputfiles NoBeta: ", $inputNoBetaText

root -l -b << EOF
std::cout << "---------------------------" << std::endl;
std::cout << "making root files from Text" << std::endl;
std::cout << "---------------------------" << std::endl;
.L rootFromText.C++
std::cout << "text to root: AllMMT, betaDependent" << std::endl;
rootFromText("$inputBetaText", "AcceptanceAllMMT_betaDependent.root")
std::cout << "text to root: AllMMT, betaIndependent" << std::endl;
rootFromText("$inputNoBetaText", "AcceptanceAllMMT_betaIndependent.root")
//std::cout << "text to root: ForwardMMT, betaDependent" << std::endl;
//rootFromText("AcceptanceForwardMMT_betaDependent.txt", "AcceptanceForwardMMT_betaDependent.root")
//std::cout << "text to root: ForwardMMT, betaIndependent" << std::endl;
//rootFromText("AcceptanceForwardMMT_betaIndependent.txt", "AcceptanceForwardMMT_betaIndependent.root")
.q
EOF
root -l -b << EOF
std::cout << "---------------------------" << std::endl;
std::cout << "making CLs limit plots     " << std::endl;
std::cout << "---------------------------" << std::endl;
.L calculate.C++
std::cout << "CLs limit: AllMMT, betaDependent" << std::endl;
calculate("AcceptanceAllMMT_betaDependent.root")
std::cout << "CLs limit: AllMMT, betaIndependent" << std::endl;
calculate("AcceptanceAllMMT_betaIndependent.root")
//std::cout << "CLs limit: ForwardMMT, betaDependent" << std::endl;
//calculate("AcceptanceForwardMMT_betaDependent.root")
//std::cout << "CLs limit: ForwardMMT, betaIndependent" << std::endl;
//calculate("AcceptanceForwardMMT_betaIndependent.root")
.q
EOF
root -l -b << EOF
std::cout << "-----------------------" << std::endl;
std::cout << "making final plots     " << std::endl;
std::cout << "-----------------------" << std::endl;
.L plot_2018data.C
std::cout << "Limit plot: AllMMT, betaDependent" << std::endl;
plot_2018data("AcceptanceAllMMT_betaDependent.root","_AllMMT_betaDependent", "betaDependent", "$processName")
.q
EOF
name1="AcceptanceAllMMT_betaDependent_"
name2=$processName
name3=".root"
fullName="$name1$name2$name3"
mv AcceptanceAllMMT_betaDependent.root $fullName
root -l -b << EOF
std::cout << "-----------------------" << std::endl;
std::cout << "making final plots     " << std::endl;
std::cout << "-----------------------" << std::endl;
.L plot_2018data.C
std::cout << "Limit plot: AllMMT, betaIndependent" << std::endl;
plot_2018data("AcceptanceAllMMT_betaIndependent.root","_AllMMT_betaIndependent", "betaIndependent", "$processName")
.q
EOF
name12="AcceptanceAllMMT_betaIndependent_"
name22=$processName
name32=".root"
fullName2="$name12$name22$name32"
mv AcceptanceAllMMT_betaIndependent.root $fullName2
# root -l -b << EOF
# std::cout << "-----------------------" << std::endl;
# std::cout << "making final plots     " << std::endl;
# std::cout << "-----------------------" << std::endl;
# .L plot_2016data.C
# std::cout << "Limit plot: ForwardMMT, betaDependent" << std::endl;
# plot_2016data("AcceptanceForwardMMT_betaDependent.root","_ForwardMMT_betaDependent", "betaDependent")
# .q
# EOF
# root -l -b << EOF
# std::cout << "-----------------------" << std::endl;
# std::cout << "making final plots     " << std::endl;
# std::cout << "-----------------------" << std::endl;
# .L plot_2016data.C
# std::cout << "Limit plot: ForwardMMT, betaIndependent" << std::endl;
# plot_2016data("AcceptanceForwardMMT_betaIndependent.root","_ForwardMMT_betaIndependent", "betaIndependent")
# .q
# EOF
mkdir $directoryName
mv massPlot*.png $directoryName
mv AcceptanceAllMMT*.root $directoryName
mv $inputBetaText $directoryName
mv $inputNoBetaText $directoryName
