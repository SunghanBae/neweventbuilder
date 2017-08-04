//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Apr 11 18:49:48 2017 by ROOT version 6.04/10
// from TTree tree/tr
// found on file: run1179_recoPID.root
//////////////////////////////////////////////////////////

#ifndef BigRIPS_reco_h
#define BigRIPS_reco_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"
#include "TNamed.h"
#include <TArtPPAC.hh>
#include <TArtPlastic.hh>
#include <TArtIC.hh>
#include <TArtFocalPlane.hh>
#include <TArtTOF.hh>
#include <TArtRIPS.hh>
#include <TArtBeam.hh>
//#include "eurica.h"

// Fixed size dimensions of array or collections stored in the TTree if any.
// const Int_t kMaxEventInfo = 1;
   const Int_t kMax_n_ion  = 1000;
   const Int_t kMax_n_gamma  = 1000;
   const Int_t kMaxBigRIPSPPAC = 71;
   const Int_t kMaxBigRIPSPlastic = 10;
   const Int_t kMaxBigRIPSIC = 4;
   const Int_t kMaxBigRIPSGe = 1;
   const Int_t kMaxBigRIPSFocalPlane = 12;
   const Int_t kMaxBigRIPSTOF = 1;
   const Int_t kMaxBigRIPSRIPS = 2;
   const Int_t kMaxBigRIPSBeam = 1;


// Header file for the classes stored in the TTree if any.

class BigRIPS_reco {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Long64_t        timestamp;

   Double_t        PPAC3X[2];
   Double_t        PPAC5X[2];
   Double_t        PPAC11X[2];
   Double_t        PPAC3Xdiff[2];
   Double_t        PPAC5Xdiff[2];
   Double_t        PPAC11Xdiff[2];
   Double_t        PPACTSumX[71];
   Double_t        PPACTSumY[71];
   Double_t        beta[2];
   Double_t        brho[2];
   Double_t        gam[2];
   Double_t        alpha;
   Double_t        delta[2];
   Double_t        aoq[2];
   Double_t        zet;
   Double_t        tof;

   // List of branches
   TBranch        *b_timestamp;   //!

   TBranch        *b_PPAC3X;   //!
   TBranch        *b_PPAC5X;   //!
   TBranch        *b_PPAC11X;   //!
   TBranch        *b_PPAC3Xdiff;   //!
   TBranch        *b_PPAC5Xdiff;   //!
   TBranch        *b_PPAC11Xdiff;   //!
   TBranch        *b_PPACTSumX;   //!
   TBranch        *b_PPACTSumY;   //!
   TBranch        *b_beta;   //!
   TBranch        *b_brho;   //!
   TBranch        *b_gam;   //!
   TBranch        *b_alpha;   //!
   TBranch        *b_delta;   //!
   TBranch        *b_aoq;   //!
   TBranch        *b_zet;   //!
   TBranch        *b_tof;   //!

   BigRIPS_reco(char* filename, TTree *tree=0);
   virtual ~BigRIPS_reco();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Int_t    GetEntriesFast();
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
//   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual void     GetTsEntry(std::map <Long64_t, Long64_t> &mts);


};

#endif

Int_t BigRIPS_reco::GetEntriesFast()
{
if(!fChain) return -1;
return fChain->GetEntriesFast();

}

//#ifdef BigRIPS_reco_cxx
BigRIPS_reco::BigRIPS_reco(char* filename, TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(filename);
      if (!f || !f->IsOpen()) {
         f = new TFile(filename);
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

BigRIPS_reco::~BigRIPS_reco()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t BigRIPS_reco::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t BigRIPS_reco::LoadTree(Long64_t entry)
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

void BigRIPS_reco::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("timestamp", &timestamp, &b_timestamp);

   fChain->SetBranchAddress("PPAC3X", PPAC3X, &b_PPAC3X);
   fChain->SetBranchAddress("PPAC5X", PPAC5X, &b_PPAC5X);
   fChain->SetBranchAddress("PPAC11X", PPAC11X, &b_PPAC11X);
   fChain->SetBranchAddress("PPAC3Xdiff", PPAC3Xdiff, &b_PPAC3Xdiff);
   fChain->SetBranchAddress("PPAC5Xdiff", PPAC5Xdiff, &b_PPAC5Xdiff);
   fChain->SetBranchAddress("PPAC11Xdiff", PPAC11Xdiff, &b_PPAC11Xdiff);
   fChain->SetBranchAddress("PPACTSumX", PPACTSumX, &b_PPACTSumX);
   fChain->SetBranchAddress("PPACTSumY", PPACTSumY, &b_PPACTSumY);
   fChain->SetBranchAddress("beta", beta, &b_beta);
   fChain->SetBranchAddress("brho", brho, &b_brho);
   fChain->SetBranchAddress("gam", gam, &b_gam);
   fChain->SetBranchAddress("alpha", &alpha, &b_alpha);
   fChain->SetBranchAddress("delta", delta, &b_delta);
   fChain->SetBranchAddress("aoq", aoq, &b_aoq);
   fChain->SetBranchAddress("zet", &zet, &b_zet);
   fChain->SetBranchAddress("tof", &tof, &b_tof);
   Notify();
}

Bool_t BigRIPS_reco::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void BigRIPS_reco::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t BigRIPS_reco::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

void BigRIPS_reco::GetTsEntry(std::map<Long64_t,Long64_t> &mts)
{  Long64_t ts;
   Long64_t nenties = fChain->GetEntriesFast();
   std::cout<<nenties<<"nenties in BigRIPS_reco "<<std::endl;
   Long64_t nbytes = 0, nb =0;
   for(Long64_t jentry = 0;jentry < nenties ;jentry++)
   {
      Long64_t ientry = LoadTree(jentry);
      if(ientry<0) break;
      nb = fChain->GetEntry(jentry); nbytes += nb;
      ts = timestamp;
      if(jentry%100000 ==0 && ts > 0) std::cout<<"jentry = "<<jentry<<" brips ts = "<<timestamp<<std::endl;
      if(ts != 0) mts.insert(std::pair<Long64_t,Long64_t> (ts,jentry));
   }
}


//#endif // #ifdef BigRIPS_reco_cxx
