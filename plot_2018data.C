#include <TFile.h>
#include <TTree.h>
#include <TGraph.h>
#include <TMultiGraph.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TImage.h>
#include <TLegendEntry.h>
#include <TLatex.h>
#include "TH1F.h"
#include "TString.h"
#include <iostream>

int getMassIndex(int massValue){
  int index;
  if(massValue == 200){
    index = 0;
  }
  else if(massValue == 500){
    index = 1;
  }
  else if(massValue == 1000){
    index = 2;
  }
  else if(massValue == 1500){
    index = 3;
  }
  else if(massValue == 2000){
    index = 4;
  }
  else if(massValue == 2500){
    index = 5;
  }
  else if(massValue == 3000){
    index = 6;
  }
  else if(massValue == 4000){
    index = 7;
  }
  else if(massValue == 5000){
    index = 8;
  }
  else if(massValue == 6000){
    index = 9;
  }
  return index;
}

int getChargeIndex(int chargeValue){
  return chargeValue-1;
}

int getLineColor(int itr){
  int colors[6] = {1,2,8,4,6,49};
  return colors[itr];
}

int getMarkerStyle(int itr){
  int colors[6] = {20,21,22,23,29,3};
  return colors[itr];
}



double findXsec(TString processName, float spinValue, int massIndex, TString betaValue){
    double crossSections = 0;
    if(processName == "DrellYan"){
        if(betaValue == "betaIndependent"){
            if(spinValue == 0){
                if(massIndex==0)crossSections = 29.58*1000.;
                else if(massIndex==1)crossSections = 0.6244*1000.;
                else if(massIndex==2)crossSections = 0.01449*1000.;
                else if(massIndex==3)crossSections = 0.0008123*1000.;
                else if(massIndex==4)crossSections = 6.052e-05*1000.;
                else if(massIndex==5)crossSections = 4.983e-06*1000.;
                else if(massIndex==6)crossSections = 4.425e-07*1000.;
                else if(massIndex==7)crossSections = 3.692e-09*1000.;
                else if(massIndex==8)crossSections = 7.746e-12*1000.;
                else if(massIndex==9)crossSections = 2.452e-17*1000.;
            }else if(spinValue == 0.5){
                if(massIndex==0)crossSections = 342.3*1000.;
                else if(massIndex==1)crossSections = 8.462*1000.;
                else if(massIndex==2)crossSections = 0.2405*1000.;
                else if(massIndex==3)crossSections = 0.01633*1000.;
                else if(massIndex==4)crossSections = 0.001468*1000.;
                else if(massIndex==5)crossSections = 0.0001426*1000.;
                else if(massIndex==6)crossSections = 1.445e-05*1000.;
                else if(massIndex==7)crossSections = 1.648e-07*1000.;
                else if(massIndex==8)crossSections = 6.377e-10*1000.;
                else if(massIndex==9)crossSections = 6.611e-15*1000.;
            }else if(spinValue == 1.0){
                if(massIndex==0)crossSections = 4625*1000.;
                else if(massIndex==1)crossSections = 56.09*1000.;
                else if(massIndex==2)crossSections = 0.8949*1000.;
                else if(massIndex==3)crossSections = 0.04102*1000.;
                else if(massIndex==4)crossSections = 0.002684*1000.;
                else if(massIndex==5)crossSections = 0.0002028*1000.;
                else if(massIndex==6)crossSections = 1.697e-05*1000.;
                else if(massIndex==7)crossSections = 1.259e-07*1000.;
                else if(massIndex==8)crossSections = 2.349e-10*1000.;
                else if(massIndex==9)crossSections = 6.859e-16*1000.;
            }
          }
          else{
            if(spinValue == 0){
                if(massIndex==0)crossSections = 16.68*1000.;
                else if(massIndex==1)crossSections = 0.3149*1000.;
                else if(massIndex==2)crossSections = 0.006237*1000.;
                else if(massIndex==3)crossSections = 0.0003*1000.;
                else if(massIndex==4)crossSections = 1.928e-05*1000.;
                else if(massIndex==5)crossSections = 1.393e-06*1000.;
                else if(massIndex==6)crossSections = 1.109e-07*1000.;
                else if(massIndex==7)crossSections = 6.839e-10*1000.;
                else if(massIndex==8)crossSections = 8.06e-13*1000.;
                else if(massIndex==9)crossSections = 8.245e-19*1000.; 
            }else if(spinValue == 0.5){
                if(massIndex==0)crossSections = 144*1000.;
                else if(massIndex==1)crossSections = 3.12*1000.;
                else if(massIndex==2)crossSections = 0.0744*1000.;
                else if(massIndex==3)crossSections = 0.004271*1000.;
                else if(massIndex==4)crossSections = 0.0003247*1000.;
                else if(massIndex==5)crossSections = 2.713e-05*1000.;
                else if(massIndex==6)crossSections = 2.429e-06*1000.;
                else if(massIndex==7)crossSections = 2.081e-08*1000.;
                else if(massIndex==8)crossSections = 4.474e-11*1000.;
                else if(massIndex==9)crossSections = 1.452e-16*1000.;
            }else if(spinValue == 1.0){
                if(massIndex==0)crossSections = 3603*1000.;
                else if(massIndex==1)crossSections = 36.19*1000.;
                else if(massIndex==2)crossSections = 0.4654*1000.;
                else if(massIndex==3)crossSections = 0.01764*1000.;
                else if(massIndex==4)crossSections = 0.0009708*1000.;
                else if(massIndex==5)crossSections = 6.349e-05*1000.;
                else if(massIndex==6)crossSections = 4.695e-06*1000.;
                else if(massIndex==7)crossSections = 2.474e-08*1000.;
                else if(massIndex==8)crossSections = 2.527e-11*1000.;
                else if(massIndex==9)crossSections = 2.327e-17*1000.;
            } 
        }
    }
    else if(processName == "PhotonFusion"){
        if(betaValue == "betaIndependent"){
            if(spinValue == 0){
                if(massIndex==0)crossSections = 1.164e04*1000.;
                else if(massIndex==1)crossSections = 325.5*1000.;
                else if(massIndex==2)crossSections = 10.68*1000.;
                else if(massIndex==3)crossSections = 0.8366*1000.;
                else if(massIndex==4)crossSections = 0.08832*1000.;
                else if(massIndex==5)crossSections = 0.01011*1000.;
                else if(massIndex==6)crossSections = 0.001104*1000.;
                else if(massIndex==7)crossSections = 7.283e-06*1000.;
                else if(massIndex==8)crossSections = 7.193e-09*1000.;
                else if(massIndex==9)crossSections = 1.269e-14*1000.;
//                 std::cout << "picking up the xsec for spin 0, betaIn" << std::endl;
            }else if(spinValue == 0.5){
                if(massIndex==0)crossSections = 6.574e04*1000.;
                else if(massIndex==1)crossSections = 1694*1000.;
                else if(massIndex==2)crossSections = 49.82*1000.;
                else if(massIndex==3)crossSections = 3.545*1000.;
                else if(massIndex==4)crossSections = 0.3411*1000.;
                else if(massIndex==5)crossSections = 0.03577*1000.;
                else if(massIndex==6)crossSections = 0.00359*1000.;
                else if(massIndex==7)crossSections = 2.022e-05*1000.;
                else if(massIndex==8)crossSections = 1.744e-08*1000.;
                else if(massIndex==9)crossSections = 2.71e-14*1000.;
//                 std::cout << "picking up the xsec for spin 0.5, betaIn" << std::endl;
            }else if(spinValue == 1.0){
                if(massIndex==0)crossSections = 7.279e5*1000.;
                else if(massIndex==1)crossSections = 1.647e4*1000.;
                else if(massIndex==2)crossSections = 443.1*1000.;
                else if(massIndex==3)crossSections = 30.19*1000.;
                else if(massIndex==4)crossSections = 2.852*1000.;
                else if(massIndex==5)crossSections = 0.2969*1000.;
                else if(massIndex==6)crossSections = 0.02994*1000.;
                else if(massIndex==7)crossSections = 0.0001727*1000.;
                else if(massIndex==8)crossSections = 1.545e-07*1000.;
                else if(massIndex==9)crossSections = 2.51e-13*1000.;
//                 std::cout << "picking up the xsec for spin 1, betaIn" << std::endl;
            }
          }
          else{
            if(spinValue == 0){
                if(massIndex==0)crossSections = 2763*1000.;
                else if(massIndex==1)crossSections = 58.4*1000.;
                else if(massIndex==2)crossSections = 1.341*1000.;
                else if(massIndex==3)crossSections = 0.07619*1000.;
                else if(massIndex==4)crossSections = 0.005862*1000.;
                else if(massIndex==5)crossSections = 0.0004849*1000.;
                else if(massIndex==6)crossSections = 3.741e-05*1000.;
                else if(massIndex==7)crossSections = 1.092e-07*1000.;
                else if(massIndex==8)crossSections = 3.605e-11*1000.;
                else if(massIndex==9)crossSections = 7.785e-18*1000.;
//                 std::cout << "picking up the xsec for spin 0, beta" << std::endl;
            }else if(spinValue == 0.5){
                if(massIndex==0)crossSections = 2.049e04*1000.;
                else if(massIndex==1)crossSections = 414.6*1000.;
                else if(massIndex==2)crossSections = 8.804*1000.;
                else if(massIndex==3)crossSections = 0.4591*1000.;
                else if(massIndex==4)crossSections = 0.03207*1000.;
                else if(massIndex==5)crossSections = 0.002394*1000.;
                else if(massIndex==6)crossSections = 0.0001656*1000.;
                else if(massIndex==7)crossSections = 3.876e-07*1000.;
                else if(massIndex==8)crossSections = 1.028e-10*1000.;
                else if(massIndex==9)crossSections = 1.773e-17*1000.;
//                 std::cout << "picking up the xsec for spin 0.5, beta" << std::endl;
            }else if(spinValue == 1.0){
                if(massIndex==0)crossSections = 2.996e5*1000.;
                else if(massIndex==1)crossSections = 4949*1000.;
                else if(massIndex==2)crossSections = 88.6*1000.;
                else if(massIndex==3)crossSections = 4.194*1000.;
                else if(massIndex==4)crossSections = 0.2766*1000.;
                else if(massIndex==5)crossSections = 0.01988*1000.;
                else if(massIndex==6)crossSections = 0.001349*1000.;
                else if(massIndex==7)crossSections = 3.158e-06*1000.;
                else if(massIndex==8)crossSections = 8.695e-10*1000.;
                else if(massIndex==9)crossSections = 1.603e-16*1000.;
//                 std::cout << "picking up the xsec for spin 0.5, beta" << std::endl;
            } 
         }
    }
    return crossSections;
}



void makePlots(float spinValue, TString rootFileName, TString canvasName, TString betaValue, TString processName){
  using namespace std;
  TFile *f = TFile::Open(rootFileName);
  TTree *T = (TTree*)f->Get("ntuple");

  int mass, charge;
  float spin;
  double limit;

  T->SetBranchAddress("mass",&mass);
  T->SetBranchAddress("charge",&charge);
  T->SetBranchAddress("spin",&spin);
  T->SetBranchAddress("limit",&limit);
  
  double limits[10][6]; //first index for mass, second index for charge
  double crossSections[10][6]; //first index for mass, second index for charge
  
  
  for (Long64_t ievt=0; ievt < T->GetEntries(); ievt++) {
    T->GetEntry(ievt);
    if(spin!=spinValue) continue;
    cout<<mass<<","<<charge<<endl;
    int massIndex = getMassIndex(mass);
    int chargeIndex = getChargeIndex(charge);
    cout<<massIndex<<","<<chargeIndex<<endl;
    limits[massIndex][chargeIndex] = limit*1000.;
    //if(spin==0 && charge==1 && mass==4000) limits[massIndex][chargeIndex]=7000; /// by hand this point to avoid bug, this is removed by Arka for 4.0 inv fb data
    if(limits[massIndex][chargeIndex]<0) limits[massIndex][chargeIndex]=1e10;  /// set to the sky when no limit available
    /// rescale 2015 limits to 2015+2016 luminosity
    //limits[massIndex][chargeIndex]=0.371/2.277*limits[massIndex][chargeIndex];  // this is removed by Arka for 4.0 inv fb
    /// inefficiency du to SQUID jumps (0.2% for 1gD and 2% for 2gD)
    //if(chargeIndex==0) limits[massIndex][chargeIndex]=1.002*limits[massIndex][chargeIndex]; // this is removed by Arka for 4.0 inv fb
    //if(chargeIndex==1) limits[massIndex][chargeIndex]=1.02*limits[massIndex][chargeIndex];  // this is removed by Arka for 4.0 inv fb
  } 
  
  
  //// old value of cross-section for photon fusion when the photon beam was used
//   if(betaValue == "betaIndependent"){
//         if(spinValue == 0){
//             crossSections[0][0] = 1214*1000.;
//             crossSections[1][0] = 35.56*1000.;
//             crossSections[2][0] = 1.282*1000.;
//             crossSections[3][0] = 0.1123*1000.;
//             crossSections[4][0] = 0.01341*1000.;
//             crossSections[5][0] = 0.001729*1000.;
//             crossSections[6][0] = 0.0002086*1000.;
//             crossSections[7][0] = 1.589e-06*1000.;
//             crossSections[8][0] = 1.851e-09*1000.;
//             crossSections[9][0] = 4.18e-15*1000.;  
//         }else if(spinValue == 0.5){
//             crossSections[0][0] = 6929*1000.;
//             crossSections[1][0] = 187.3*1000.;
//             crossSections[2][0] = 6.09*1000.;
//             crossSections[3][0] = 0.4869*1000.;
//             crossSections[4][0] = 0.05289*1000.;
//             crossSections[5][0] = 0.006209*1000.;
//             crossSections[6][0] = 0.0006843*1000.;
//             crossSections[7][0] = 4.432e-06*1000.;
//             crossSections[8][0] = 4.497e-09*1000.;
//             crossSections[9][0] = 8.915e-15*1000.;    
//         }else if(spinValue == 1.0){
//             crossSections[0][0] = 7.979e4*1000.;
//             crossSections[1][0] = 1865*1000.;
//             crossSections[2][0] = 54.84*1000.;
//             crossSections[3][0] = 4.177*1000.;
//             crossSections[4][0] = 0.4435*1000.;
//             crossSections[5][0] = 0.05156*1000.;
//             crossSections[6][0] = 0.00571*1000.;
//             crossSections[7][0] = 3.788e-05*1000.;
//             crossSections[8][0] = 3.983e-08*1000.;
//             crossSections[9][0] = 8.257e-14*1000.; 
//         }
//     }
//     else{
//         if(spinValue == 0){
//             crossSections[0][0] = 294.5*1000.;
//             crossSections[1][0] = 6.611*1000.;
//             crossSections[2][0] = 0.1706*1000.;
//             crossSections[3][0] = 0.011*1000.;
//             crossSections[4][0] = 0.0009579*1000.;
//             crossSections[5][0] = 8.807e-05*1000.;
//             crossSections[6][0] = 7.397e-06*1000.;
//             crossSections[7][0] = 2.472e-08*1000.;
//             crossSections[8][0] = 9.671e-12*1000.;
//             crossSections[9][0] = 2.478e-18*1000.;  
//         }else if(spinValue == 0.5){
//             crossSections[0][0] = 2221*1000.;
//             crossSections[1][0] = 47.59*1000.;
//             crossSections[2][0] = 1.138*1000.;
//             crossSections[3][0] = 0.06757*1000.;
//             crossSections[4][0] = 0.005348*1000.;
//             crossSections[5][0] = 0.0004416*1000.;
//             crossSections[6][0] = 3.313e-05*1000.;
//             crossSections[7][0] = 8.833e-08*1000.;
//             crossSections[8][0] = 2.768e-11*1000.;
//             crossSections[9][0] = 5.633e-18*1000.;    
//         }else if(spinValue == 1.0){
//             crossSections[0][0] = 3.421e4*1000.;
//             crossSections[1][0] = 587.7*1000.;
//             crossSections[2][0] = 11.75*1000.;
//             crossSections[3][0] = 0.6292*1000.;
//             crossSections[4][0] = 0.04645*1000.;
//             crossSections[5][0] = 0.003679*1000.;
//             crossSections[6][0] = 0.0002705*1000.;
//             crossSections[7][0] = 7.197e-07*1000.;
//             crossSections[8][0] = 2.341e-10*1000.;
//             crossSections[9][0] = 5.095e-17*1000.; 
//         } 
//     }
//
  
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 6; j++){
      //cross section scales as charge^4 for photon fusion
      if(processName=="PhotonFusion") crossSections[i][j] = findXsec("PhotonFusion", spinValue, i, betaValue) * (j+1) * (j+1) * (j+1) * (j+1);
      //cross section scales as charge^2 for DrellYan
      else if(processName=="DrellYan") crossSections[i][j] = findXsec("DrellYan", spinValue, i, betaValue) * (j+1) * (j+1);
      //cross section scales as charge^2 for DrellYan and charge^4 for photon fusion
      else crossSections[i][j] = findXsec("DrellYan", spinValue, i, betaValue) * (j+1) * (j+1) + findXsec("PhotonFusion", spinValue, i, betaValue) * (j+1) * (j+1) * (j+1) * (j+1);
    }
  }

  TGraph* limitVsMass[10]; // for different charges
  TGraph* limitVsCharge[6]; // for different masses
  TGraph* crossSectionVsMass[10]; // for different charges
  TGraph* crossSectionVsCharge[6]; // for different masses

  double massPoints[10] = {200.,500.,1000.,1500.,2000.,2500.,3000.,4000.,5000.,6000.};
  double chargePoints[6] = {1.,2.,3.,4.,5.,6.}; 
  
  for(int i = 0; i < 6; i++){
    //first use i as charge index
    double limitPoints1[10] = {limits[0][i],limits[1][i],limits[2][i],limits[3][i],limits[4][i],limits[5][i],limits[6][i],limits[7][i],limits[8][i],limits[9][i]};
    double crossSectionPoints1[10] = {crossSections[0][i],crossSections[1][i],crossSections[2][i],crossSections[3][i],crossSections[4][i],crossSections[5][i],crossSections[6][i],crossSections[7][i],crossSections[8][i],crossSections[9][i]};
    limitVsMass[i] = new TGraph(10,massPoints,limitPoints1);
    crossSectionVsMass[i] = new TGraph(10,massPoints,crossSectionPoints1);
//     //then use i as mass index
//     double limitPoints2[6] = {limits[i][0],limits[i][1],limits[i][2],limits[i][3],limits[i][4],limits[i][5]};
//     double crossSectionPoints2[6] = {crossSections[i][0],crossSections[i][1],crossSections[i][2],crossSections[i][3],crossSections[i][4],crossSections[i][5]};
//     limitVsCharge[i] = new TGraph(6,chargePoints,limitPoints2);
//     crossSectionVsCharge[i] = new TGraph(6,chargePoints,crossSectionPoints2);
  }
  
  for(int i = 0; i < 6; i++){
    int counter1 = 0; //number of removed points from mass plots
    // int counter2 = 0; //number of removed points from charge plots
    for(int j = 0; j < 10; j++){
      double x; double y;
      limitVsMass[i]->GetPoint(j-counter1,x,y);
      //cout<<i<<"\t"<<j<<"\t"<<x<<"\t"<<y<<endl;
      if(y < 5 || y > 1e8){
        limitVsMass[i]->RemovePoint(j-counter1);
        counter1++;
      }
//       limitVsCharge[i]->GetPoint(j-counter2,x,y);
//       if(y <50 || y>10000 || j>3){
// 	limitVsCharge[i]->RemovePoint(j-counter2);
// 	counter2++;
//       }
    }
  }

  TMultiGraph *massGraphs = new TMultiGraph();
  TMultiGraph *chargeGraphs = new TMultiGraph();  
  
  for(int i = 0; i < 5; i++){
    int color = getLineColor(i);
    limitVsMass[i]->SetLineColor(color);
    limitVsMass[i]->SetMarkerColor(color);
    limitVsMass[i]->SetMarkerStyle(getMarkerStyle(i));
    limitVsMass[i]->SetMarkerSize(2);
    if(i==4) limitVsMass[i]->SetMarkerSize(2.8);
    limitVsMass[i]->SetLineStyle(2);
    limitVsMass[i]->SetLineWidth(3);
    
//     limitVsCharge[i]->SetLineColor(color);
//     limitVsCharge[i]->SetMarkerColor(color);
//     limitVsCharge[i]->SetMarkerStyle(getMarkerStyle(i));
//     limitVsCharge[i]->SetMarkerSize(2); 
//     limitVsCharge[i]->SetLineStyle(2);
//     limitVsCharge[i]->SetLineWidth(3);
    crossSectionVsMass[i]->SetLineColor(color);
    crossSectionVsMass[i]->SetLineWidth(2);
//     crossSectionVsCharge[i]->SetLineColor(color);
//     crossSectionVsCharge[i]->SetLineWidth(2);
    //cout<<limitVsMass[i]->GetN()<<endl;
    if(limitVsMass[i]->GetN() > 0){
      massGraphs->Add(limitVsMass[i],"lp");
      massGraphs->Add(crossSectionVsMass[i],"c");
    }
//     chargeGraphs->Add(limitVsCharge[i],"lp");
//     chargeGraphs->Add(crossSectionVsCharge[i],"c");
  }
  
  TLegend *leg1;
  leg1 = new TLegend(0.73,0.18,0.93,0.42);
  leg1->SetHeader("95% CL Limits");
  leg1->SetTextSize(0.04);
  TLegendEntry* l11 = leg1->AddEntry(limitVsMass[0],"1 g_{D}","lp");
  TLegendEntry* l12 = leg1->AddEntry(limitVsMass[1],"2 g_{D}","lp");
  TLegendEntry* l13 = leg1->AddEntry(limitVsMass[2],"3 g_{D}","lp");
  TLegendEntry* l14 = leg1->AddEntry(limitVsMass[3],"4 g_{D}","lp");
  TLegendEntry* l15 = leg1->AddEntry(limitVsMass[4],"5 g_{D}","lp");
  l11->SetTextColor(getLineColor(0));l12->SetTextColor(getLineColor(1));
  l13->SetTextColor(getLineColor(2));l14->SetTextColor(getLineColor(3));
  l15->SetTextColor(getLineColor(4));
  leg1->SetBorderSize(0);
  leg1->SetFillColor(kWhite);
  leg1->SetShadowColor(kWhite);

  TLegend *leg3;
  leg3 = new TLegend(0.43,0.18,0.73,0.42);
  leg3->SetTextSize(0.04);
  TLegendEntry* l31 = leg3->AddEntry(crossSectionVsMass[0],"1 g_{D}","l");
  TLegendEntry* l32 = leg3->AddEntry(crossSectionVsMass[1],"2 g_{D}","l");
  TLegendEntry* l33 = leg3->AddEntry(crossSectionVsMass[2],"3 g_{D}","l");
  TLegendEntry* l34 = leg3->AddEntry(crossSectionVsMass[3],"4 g_{D}","l");
  TLegendEntry* l35 = leg3->AddEntry(crossSectionVsMass[4],"5 g_{D}","l");
  l31->SetTextColor(getLineColor(0));l32->SetTextColor(getLineColor(1));
  l33->SetTextColor(getLineColor(2));l34->SetTextColor(getLineColor(3));
  l35->SetTextColor(getLineColor(4));
  leg3->SetBorderSize(0);
  leg3->SetFillColor(kWhite);
  leg3->SetShadowColor(kWhite);

  TCanvas* c1;
  TString betaString = "";
  if(betaValue == "betaDependent")betaString=" #beta";
  if(spinValue==0){
    c1 = new TCanvas("massPlot_spinzero_"+processName+canvasName,"",1200,900);
    if(processName=="PhotonFusion")leg3->SetHeader("LO #gamma#gamma spin 0"+betaString);
    else if(processName=="DrellYan") leg3->SetHeader("LO DY spin 0"+betaString);
    else leg3->SetHeader("LO #gamma#gamma+DY spin 0"+betaString);
  }else if(spinValue==0.5){
    c1 = new TCanvas("massPlot_spinhalf_"+processName+canvasName,"",1200,900);
    if(processName=="PhotonFusion")leg3->SetHeader("LO #gamma#gamma spin 1/2"+betaString);
    else if(processName=="DrellYan")leg3->SetHeader("LO DY spin 1/2"+betaString);
    else leg3->SetHeader("LO #gamma#gamma+DY spin 1/2"+betaString);
  }else if(spinValue==1.0){
    c1 = new TCanvas("massPlot_spinone_"+processName+canvasName,"",1200,900);
    if(processName=="PhotonFusion")leg3->SetHeader("LO #gamma#gamma spin 1"+betaString);
    else if(processName=="DrellYan")leg3->SetHeader("LO DY spin 1"+betaString);
    else leg3->SetHeader("LO #gamma#gamma+DY spin 1"+betaString);
  }
  c1->SetLogy();
  massGraphs->Draw("A");
  massGraphs->GetXaxis()->SetTitle("Mass [GeV]"); 
  massGraphs->GetXaxis()->SetTitleSize(0.06);
  massGraphs->GetXaxis()->SetLabelSize(0.06);
  massGraphs->GetYaxis()->SetTitle("#sigma [fb]");
  massGraphs->GetYaxis()->SetTitleSize(0.06);  
  massGraphs->GetYaxis()->SetLabelSize(0.06);  
  massGraphs->GetYaxis()->SetRangeUser(5e-1,1e4);
  leg1->Draw();
  leg3->Draw();
  TLatex Tl; //Tl.SetTextFont(43); 
  Tl.SetTextSize(0.05);
  Tl.DrawLatexNDC(.48, .84, "#sqrt{s} = 13 TeV, 4.0 fb^{-1}");
  TImage *MoEDALgif = TImage::Open("MoEDAL-logo.png");
  TPad *logosubpad1 = new TPad("logosubpad1","logo subpad",0.81,0.76,0.93,0.92,0,3);
  logosubpad1->Draw(); 
  logosubpad1->cd();
  MoEDALgif->Draw();
  TLatex *MoEDALprel=new TLatex(3500,5200,"MoEDAL #it{preliminary}");
  MoEDALprel->Draw();
  c1->Print(".png");
  c1->Close();
 
}

void plot_2018data(TString rootFile, TString canvasName, TString betaValue, TString processName){

  gROOT->LoadMacro("MoEDALStyle.C");
  SetMoEDALStyle();
  
  makePlots(0., rootFile, canvasName, betaValue, processName);
  makePlots(0.5, rootFile, canvasName, betaValue, processName);
  makePlots(1.0, rootFile, canvasName, betaValue, processName);

}
