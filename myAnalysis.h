//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun May 20 23:38:05 2018 by ROOT version 6.06/06
// from TTree MonopoleNtuple/Monopole Simulation Data
// found on file: MonopoleData_betaIndependent_SpinHalf_q40_run_08_maximal.root
//////////////////////////////////////////////////////////

#ifndef myAnalysis_h
#define myAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class myAnalysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           RunNumber;
   Int_t           EventNumber;
   Int_t           mc_n;
   vector<float>   *mc_initial_x;
   vector<float>   *mc_initial_y;
   vector<float>   *mc_initial_z;
   vector<float>   *mc_initial_t;
   vector<float>   *mc_initial_px;
   vector<float>   *mc_initial_py;
   vector<float>   *mc_initial_pz;
   vector<float>   *mc_initial_e;
   vector<float>   *mc_final_x;
   vector<float>   *mc_final_y;
   vector<float>   *mc_final_z;
   vector<float>   *mc_final_t;
   vector<float>   *mc_particle_m;
   vector<float>   *mc_particle_qe;
   vector<float>   *mc_particle_qm;
   vector<int>     *mc_particle_pdg;
   vector<int>     *mc_particle_barcode;
   Int_t           mmthit_n;
   vector<float>   *mmthit_hit_x;
   vector<float>   *mmthit_hit_y;
   vector<float>   *mmthit_hit_z;
   vector<float>   *mmthit_hit_t;
   vector<int>     *mmthit_hit_detid;
   vector<int>     *mmthit_particle_barcode;
   Int_t           ntdhit_n;
   vector<float>   *ntdhit_hit_entryx;
   vector<float>   *ntdhit_hit_entryy;
   vector<float>   *ntdhit_hit_entryz;
   vector<float>   *ntdhit_hit_dispx;
   vector<float>   *ntdhit_hit_dispy;
   vector<float>   *ntdhit_hit_dispz;
   vector<float>   *ntdhit_hit_t;
   vector<float>   *ntdhit_hit_e;
   vector<float>   *ntdhit_hit_pmag;
   vector<int>     *ntdhit_hit_detid;
   vector<int>     *ntdhit_particle_barcode;

   // List of branches
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_mc_n;   //!
   TBranch        *b_mc_initial_x;   //!
   TBranch        *b_mc_initial_y;   //!
   TBranch        *b_mc_initial_z;   //!
   TBranch        *b_mc_initial_t;   //!
   TBranch        *b_mc_initial_px;   //!
   TBranch        *b_mc_initial_py;   //!
   TBranch        *b_mc_initial_pz;   //!
   TBranch        *b_mc_initial_e;   //!
   TBranch        *b_mc_final_x;   //!
   TBranch        *b_mc_final_y;   //!
   TBranch        *b_mc_final_z;   //!
   TBranch        *b_mc_final_t;   //!
   TBranch        *b_mc_particle_m;   //!
   TBranch        *b_mc_particle_qe;   //!
   TBranch        *b_mc_particle_qm;   //!
   TBranch        *b_mc_particle_pdg;   //!
   TBranch        *b_mc_particle_barcode;   //!
   TBranch        *b_mmthit_n;   //!
   TBranch        *b_mmthit_hit_x;   //!
   TBranch        *b_mmthit_hit_y;   //!
   TBranch        *b_mmthit_hit_z;   //!
   TBranch        *b_mmthit_hit_t;   //!
   TBranch        *b_mmthit_hit_detid;   //!
   TBranch        *b_mmthit_particle_barcode;   //!
   TBranch        *b_ntdhit_n;   //!
   TBranch        *b_ntdhit_hit_entryx;   //!
   TBranch        *b_ntdhit_hit_entryy;   //!
   TBranch        *b_ntdhit_hit_entryz;   //!
   TBranch        *b_ntdhit_hit_dispx;   //!
   TBranch        *b_ntdhit_hit_dispy;   //!
   TBranch        *b_ntdhit_hit_dispz;   //!
   TBranch        *b_ntdhit_hit_t;   //!
   TBranch        *b_ntdhit_hit_e;   //!
   TBranch        *b_ntdhit_hit_pmag;   //!
   TBranch        *b_ntdhit_hit_detid;   //!
   TBranch        *b_ntdhit_particle_barcode;   //!

   myAnalysis(TTree *tree=0);
   virtual ~myAnalysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef myAnalysis_cxx
myAnalysis::myAnalysis(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("MonopoleData_betaIndependent_SpinHalf_q40_run_08_maximal.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("MonopoleData_betaIndependent_SpinHalf_q40_run_08_maximal.root");
      }
      f->GetObject("MonopoleNtuple",tree);

   }
   Init(tree);
}

myAnalysis::~myAnalysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t myAnalysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t myAnalysis::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void myAnalysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   mc_initial_x = 0;
   mc_initial_y = 0;
   mc_initial_z = 0;
   mc_initial_t = 0;
   mc_initial_px = 0;
   mc_initial_py = 0;
   mc_initial_pz = 0;
   mc_initial_e = 0;
   mc_final_x = 0;
   mc_final_y = 0;
   mc_final_z = 0;
   mc_final_t = 0;
   mc_particle_m = 0;
   mc_particle_qe = 0;
   mc_particle_qm = 0;
   mc_particle_pdg = 0;
   mc_particle_barcode = 0;
   mmthit_hit_x = 0;
   mmthit_hit_y = 0;
   mmthit_hit_z = 0;
   mmthit_hit_t = 0;
   mmthit_hit_detid = 0;
   mmthit_particle_barcode = 0;
   ntdhit_hit_entryx = 0;
   ntdhit_hit_entryy = 0;
   ntdhit_hit_entryz = 0;
   ntdhit_hit_dispx = 0;
   ntdhit_hit_dispy = 0;
   ntdhit_hit_dispz = 0;
   ntdhit_hit_t = 0;
   ntdhit_hit_e = 0;
   ntdhit_hit_pmag = 0;
   ntdhit_hit_detid = 0;
   ntdhit_particle_barcode = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("mc_n", &mc_n, &b_mc_n);
   fChain->SetBranchAddress("mc_initial_x", &mc_initial_x, &b_mc_initial_x);
   fChain->SetBranchAddress("mc_initial_y", &mc_initial_y, &b_mc_initial_y);
   fChain->SetBranchAddress("mc_initial_z", &mc_initial_z, &b_mc_initial_z);
   fChain->SetBranchAddress("mc_initial_t", &mc_initial_t, &b_mc_initial_t);
   fChain->SetBranchAddress("mc_initial_px", &mc_initial_px, &b_mc_initial_px);
   fChain->SetBranchAddress("mc_initial_py", &mc_initial_py, &b_mc_initial_py);
   fChain->SetBranchAddress("mc_initial_pz", &mc_initial_pz, &b_mc_initial_pz);
   fChain->SetBranchAddress("mc_initial_e", &mc_initial_e, &b_mc_initial_e);
   fChain->SetBranchAddress("mc_final_x", &mc_final_x, &b_mc_final_x);
   fChain->SetBranchAddress("mc_final_y", &mc_final_y, &b_mc_final_y);
   fChain->SetBranchAddress("mc_final_z", &mc_final_z, &b_mc_final_z);
   fChain->SetBranchAddress("mc_final_t", &mc_final_t, &b_mc_final_t);
   fChain->SetBranchAddress("mc_particle_m", &mc_particle_m, &b_mc_particle_m);
   fChain->SetBranchAddress("mc_particle_qe", &mc_particle_qe, &b_mc_particle_qe);
   fChain->SetBranchAddress("mc_particle_qm", &mc_particle_qm, &b_mc_particle_qm);
   fChain->SetBranchAddress("mc_particle_pdg", &mc_particle_pdg, &b_mc_particle_pdg);
   fChain->SetBranchAddress("mc_particle_barcode", &mc_particle_barcode, &b_mc_particle_barcode);
   fChain->SetBranchAddress("mmthit_n", &mmthit_n, &b_mmthit_n);
   fChain->SetBranchAddress("mmthit_hit_x", &mmthit_hit_x, &b_mmthit_hit_x);
   fChain->SetBranchAddress("mmthit_hit_y", &mmthit_hit_y, &b_mmthit_hit_y);
   fChain->SetBranchAddress("mmthit_hit_z", &mmthit_hit_z, &b_mmthit_hit_z);
   fChain->SetBranchAddress("mmthit_hit_t", &mmthit_hit_t, &b_mmthit_hit_t);
   fChain->SetBranchAddress("mmthit_hit_detid", &mmthit_hit_detid, &b_mmthit_hit_detid);
   fChain->SetBranchAddress("mmthit_particle_barcode", &mmthit_particle_barcode, &b_mmthit_particle_barcode);
   fChain->SetBranchAddress("ntdhit_n", &ntdhit_n, &b_ntdhit_n);
   fChain->SetBranchAddress("ntdhit_hit_entryx", &ntdhit_hit_entryx, &b_ntdhit_hit_entryx);
   fChain->SetBranchAddress("ntdhit_hit_entryy", &ntdhit_hit_entryy, &b_ntdhit_hit_entryy);
   fChain->SetBranchAddress("ntdhit_hit_entryz", &ntdhit_hit_entryz, &b_ntdhit_hit_entryz);
   fChain->SetBranchAddress("ntdhit_hit_dispx", &ntdhit_hit_dispx, &b_ntdhit_hit_dispx);
   fChain->SetBranchAddress("ntdhit_hit_dispy", &ntdhit_hit_dispy, &b_ntdhit_hit_dispy);
   fChain->SetBranchAddress("ntdhit_hit_dispz", &ntdhit_hit_dispz, &b_ntdhit_hit_dispz);
   fChain->SetBranchAddress("ntdhit_hit_t", &ntdhit_hit_t, &b_ntdhit_hit_t);
   fChain->SetBranchAddress("ntdhit_hit_e", &ntdhit_hit_e, &b_ntdhit_hit_e);
   fChain->SetBranchAddress("ntdhit_hit_pmag", &ntdhit_hit_pmag, &b_ntdhit_hit_pmag);
   fChain->SetBranchAddress("ntdhit_hit_detid", &ntdhit_hit_detid, &b_ntdhit_hit_detid);
   fChain->SetBranchAddress("ntdhit_particle_barcode", &ntdhit_particle_barcode, &b_ntdhit_particle_barcode);
   Notify();
}

Bool_t myAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void myAnalysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t myAnalysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef myAnalysis_cxx
