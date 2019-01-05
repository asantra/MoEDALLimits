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
#include <iostream>

int getMassIndex(int massValue){
  int index;
  if(massValue == 200){
    index = 0;
  }else if(massValue == 500){
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

void makePlots(float spinValue){
  using namespace std;
  TFile *f = TFile::Open("info.root");
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
    if(spin==0 && charge==1 && mass==4000) limits[massIndex][chargeIndex]=7000; /// by hand this point to avoid bug
    if(limits[massIndex][chargeIndex]<0) limits[massIndex][chargeIndex]=1e10;  /// set to the sky when no limit available
  }
  
  if(spinValue == 0){
    crossSections[0][0] = 29.55*1000.;
    crossSections[1][0] = 0.626*1000.;
    crossSections[2][0] = 0.01448*1000.;
    crossSections[3][0] = 0.0008117*1000.;
    crossSections[4][0] = 6.048e-05*1000.;
    crossSections[5][0] = 4.99e-06*1000.;
    crossSections[6][0] = 4.419e-07*1000.;
    crossSections[7][0] = 3.695e-09*1000.;
    crossSections[8][0] = 7.742e-12*1000.;
    crossSections[9][0] = 2.445e-17*1000.;    
  }else{
    crossSections[0][0] = 341.9*1000.;
    crossSections[1][0] = 8.462*1000.;
    crossSections[2][0] = 0.2403*1000.;
    crossSections[3][0] = 0.01636*1000.;
    crossSections[4][0] = 0.001466*1000.;
    crossSections[5][0] = 0.0001428*1000.;
    crossSections[6][0] = 1.441e-05*1000.;
    crossSections[7][0] = 1.647e-07*1000.;
    crossSections[8][0] = 6.394e-10*1000.;
    crossSections[9][0] = 6.618e-15*1000.;    
  }

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 6; j++){
      //cross section scales as charge^2
      crossSections[i][j] = crossSections[i][0] * (j+1) * (j+1);
//       limits[i][j] = 3/(0.371*0.02);  
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
  
//   for(int i = 0; i < 6; i++){
//     int counter1 = 0; //number of removed points from mass plots
//     int counter2 = 0; //number of removed points from charge plots
//     for(int j = 0; j < 6; j++){
//       double x; double y;
//       limitVsMass[i]->GetPoint(j-counter1,x,y);
//       //cout<<i<<"\t"<<j<<"\t"<<x<<"\t"<<y<<endl;
//       if(y <50 || y>10000 || i>3){
// 	limitVsMass[i]->RemovePoint(j-counter1);
// 	counter1++;
//       }
//       limitVsCharge[i]->GetPoint(j-counter2,x,y);
//       if(y <50 || y>10000 || j>3){
// 	limitVsCharge[i]->RemovePoint(j-counter2);
// 	counter2++;
//       }
//     }
//   }

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
  leg1 = new TLegend(0.73,0.18,0.93,0.52);
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
  leg3 = new TLegend(0.51,0.18,0.73,0.52);
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
  if(spinValue==0){
    c1 = new TCanvas("massPlot_boson","",1200,900);
    leg3->SetHeader("LO DY spin 0");
  }else{
    c1 = new TCanvas("massPlot_fermion","",1200,900);
    leg3->SetHeader("LO DY spin 1/2");
  }
  c1->SetLogy();
  massGraphs->Draw("A");
  massGraphs->GetXaxis()->SetTitle("Mass [GeV]"); 
  massGraphs->GetXaxis()->SetTitleSize(0.06);
  massGraphs->GetXaxis()->SetLabelSize(0.06);
  massGraphs->GetYaxis()->SetTitle("#sigma [fb]");
  massGraphs->GetYaxis()->SetTitleSize(0.06);  
  massGraphs->GetYaxis()->SetLabelSize(0.06);  
  massGraphs->GetYaxis()->SetRangeUser(1,1e5);
  leg1->Draw();
  leg3->Draw();
  TLatex Tl; //Tl.SetTextFont(43); 
  Tl.SetTextSize(0.05);
  Tl.DrawLatexNDC(.44, .87, "#sqrt{s} = 13 TeV, 0.371 fb^{-1}");
  TImage *MoEDALgif = TImage::Open("MoEDAL-logo.png");
  TPad *logosubpad1 = new TPad("logosubpad1","logo subpad",0.78,0.76,0.93,0.92,0,3);
  logosubpad1->Draw(); 
  logosubpad1->cd();
  MoEDALgif->Draw(); 
  c1->Print(".png");
  c1->Close();

//   TLegend *leg2;
//   TLegend *leg4;
//   TCanvas* c2;
//   if(spinValue==0){
//     c2 = new TCanvas("chargePlot_boson","",1200,900);
//     leg2 = new TLegend(0.64,0.38,0.92,0.56);
//     leg4 = new TLegend(0.2,0.27,0.4,0.42);
//     leg4->SetHeader("LO DY spin 0");
//   }else{
//     c2 = new TCanvas("chargePlot_fermion","",1200,900);
//     leg2 = new TLegend(0.62,0.2,0.92,0.40);
//     leg4 = new TLegend(0.28,0.2,0.48,0.35);
//     leg4->SetHeader("LO DY spin 1/2");
//   }
//   leg2->SetHeader("95% CL Limits");
//   TLegendEntry *header = (TLegendEntry*)leg2->GetListOfPrimitives()->First();
//   header->SetTextAlign(22);
//   leg2->SetNColumns(2);
//   leg2->SetTextSize(0.03);
//   leg4->SetTextSize(0.03);
//   TLegendEntry* l21 = leg2->AddEntry(limitVsCharge[0],"100 GeV","lp");
//   TLegendEntry* l22 = leg2->AddEntry(limitVsCharge[1],"500 GeV","lp");
//   TLegendEntry* l23 = leg2->AddEntry(limitVsCharge[2],"1000 GeV","lp");
//   TLegendEntry* l24 = leg2->AddEntry(limitVsCharge[3],"2000 GeV","lp");
//   TLegendEntry* l25 = leg2->AddEntry(limitVsCharge[4],"3000 GeV","lp");
//   TLegendEntry* l26 = leg2->AddEntry(limitVsCharge[5],"3500 GeV","lp");
//   l21->SetTextColor(getLineColor(0));l22->SetTextColor(getLineColor(1));
//   l23->SetTextColor(getLineColor(2));l24->SetTextColor(getLineColor(3));
//   l25->SetTextColor(getLineColor(4));l26->SetTextColor(getLineColor(5));
//   TLegendEntry* l42 = leg4->AddEntry(crossSectionVsCharge[1],"500 GeV","l");
//   TLegendEntry* l43 = leg4->AddEntry(crossSectionVsCharge[2],"1000 GeV","l");
//   l42->SetTextColor(getLineColor(1));
//   l43->SetTextColor(getLineColor(2));
//   leg2->SetBorderSize(0);
//   leg2->SetFillColor(kWhite);
//   leg2->SetShadowColor(kWhite);
//   leg4->SetBorderSize(0);
//   leg4->SetFillColor(kWhite);
//   leg4->SetShadowColor(kWhite);
//   c2->SetLogy();
//   chargeGraphs->Draw("A");
//   chargeGraphs->GetXaxis()->SetTitle("Charge [g_{D}]"); 
//   chargeGraphs->GetYaxis()->SetTitle("#sigma [fb]");
//   chargeGraphs->GetXaxis()->SetRangeUser(0.5,4.5);
//   chargeGraphs->GetYaxis()->SetRangeUser(1,1e5);
//   leg2->Draw();
//   leg4->Draw();
//   Tl.DrawLatexNDC(.28, .85, "#sqrt{s} = 13 TeV, 0.371 fb^{-1}");
//   TPad *logosubpad2 = new TPad("logosubpad1","logo subpad",0.18,0.81,0.28,0.92,0,3);
//   logosubpad2->Draw(); 
//   logosubpad2->cd();
//   MoEDALgif->Draw();
//   c2->Print(".png");
//   c2->Close();
// 
  
// */ 
 
}

void plot(){

  gROOT->LoadMacro("MoEDALStyle.C");
  SetMoEDALStyle();
  
  makePlots(0.);
  makePlots(0.5);

}
