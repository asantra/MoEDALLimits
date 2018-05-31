#define myAnalysis_cxx
#include "myAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <TString.h>
#include <TTree.h>
#include <TFile.h>
#include <string>


void myAnalysis::Loop()
{
//   In a ROOT session, you can do:
//      root> .L myAnalysis.C
//      root> myAnalysis t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
    
   int events   = 0;
   int MMT      = 0;
   float acc    = 0;
   float accerr = 0;
   bool debug   = false;
    
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      //if(jentry%1000==0)cout << "Processed: " << jentry << endl;
      
      events++;
      bool atleastoneMMThitthisevent=false;
      for(size_t ii=0;ii<mmthit_hit_z->size();ii++) {     ///// MMT hit loop
        if(mmthit_hit_z->at(ii)<-1000) atleastoneMMThitthisevent=true; 
        if(debug)cout << "Inside the MMT loop" << endl;
      }  
      if(debug)cout << "Getting the events with at least one MMT hits" << endl;
      if(atleastoneMMThitthisevent) MMT++;
   }
   if(events!=0)acc = (float)MMT/(float)events;
   else acc = -888;
   if(MMT!=0)accerr=(float)acc*sqrt(MMT)/(float)MMT;
   else accerr = -999;
   cout << "acceptance: " << acc << "+/-" << accerr << endl;
}
