#include <TROOT.h>
#include <TFile.h>
#include <TTree.h>
#include <iostream>
#include <sstream>
#include <TString.h>

void rootFromText(TString inputFile, TString outputRoot){

  TFile* rootfile;
  TTree* ntuple;
  
  Int_t mass;
  Int_t charge;
  Float_t spin;
  Float_t efficiency;
  Float_t uncertainty;

  char line[100];

  rootfile = new TFile(outputRoot,"RECREATE");
  rootfile->cd();

  ntuple = new TTree("ntuple", "Info for Limit Plots");
  ntuple->Branch("mass", &mass);
  ntuple->Branch("charge", &charge);
  ntuple->Branch("spin", &spin);
  ntuple->Branch("efficiency", &efficiency);
  ntuple->Branch("uncertainty", &uncertainty);

  FILE *fp = fopen(inputFile,"r");

  while (fgets(line,100,fp) != NULL) {
    sscanf(line,"%d %d %g %g %g",&charge,&mass,&spin,&efficiency,&uncertainty);
    ntuple->Fill();
  }

  fclose(fp);

  rootfile->Write();
  rootfile->Close();
 
}
