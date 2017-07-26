//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jun  7 15:59:24 2017 by ROOT version 6.04/10
// from TTree tree2/tree2
// found on file: R1208_0_parsed.root
//////////////////////////////////////////////////////////

#ifndef AIDA_parsed_h
#define AIDA_parsed_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class AIDA_parsed {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Long64_t        t0;
   Long64_t        extT0;
   Int_t           ion_flag;
   Int_t           multinum;
   Int_t           adcSum;
   Int_t           asicNo;
   Long64_t        timestamp[16];   //[multinum]
   Long64_t        extTimestamp[16];   //[multinum]
   Int_t           stripNo[16];   //[multinum]
   Int_t           feeNo[16];   //[multinum]
   Int_t           chNo[16];   //[multinum]
   Int_t           rangeType[16];   //[multinum]
   Int_t           adcData[16];   //[multinum]
   Int_t           dssdNo[16];   //[multinum]

   // List of branches
   TBranch        *b_t0;   //!
   TBranch        *b_extT0;   //!
   TBranch        *b_ion_flag;   //!
   TBranch        *b_multinum;   //!
   TBranch        *b_adcSum;   //!
   TBranch        *b_asicNo;   //!
   TBranch        *b_timestamp;   //!
   TBranch        *b_extTimestamp;   //!
   TBranch        *b_stripNo;   //!
   TBranch        *b_feeNo;   //!
   TBranch        *b_chNo;   //!
   TBranch        *b_rangeType;   //!
   TBranch        *b_adcData;   //!
   TBranch        *b_dssdNo;   //!

   AIDA_parsed(char* filename, TTree *tree=0);
   virtual ~AIDA_parsed();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
//   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual Long64_t GetEntriesFast();
};

#endif

//#ifdef AIDA_parsed_cxx
AIDA_parsed::AIDA_parsed(char* filename, TTree *tree) : fChain(0) 
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

AIDA_parsed::~AIDA_parsed()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Long64_t AIDA_parsed::GetEntriesFast()
{
  if(!fChain) return -1;
  return fChain->GetEntriesFast();
}


Int_t AIDA_parsed::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t AIDA_parsed::LoadTree(Long64_t entry)
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

void AIDA_parsed::Init(TTree *tree)
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

   fChain->SetBranchAddress("t0", &t0, &b_t0);
   fChain->SetBranchAddress("extT0", &extT0, &b_extT0);
   fChain->SetBranchAddress("ion_flag", &ion_flag, &b_ion_flag);
   fChain->SetBranchAddress("multinum", &multinum, &b_multinum);
   fChain->SetBranchAddress("adcSum", &adcSum, &b_adcSum);
   fChain->SetBranchAddress("asicNo", &asicNo, &b_asicNo);
   fChain->SetBranchAddress("timestamp", timestamp, &b_timestamp);
   fChain->SetBranchAddress("extTimestamp", extTimestamp, &b_extTimestamp);
   fChain->SetBranchAddress("stripNo", stripNo, &b_stripNo);
   fChain->SetBranchAddress("feeNo", feeNo, &b_feeNo);
   fChain->SetBranchAddress("chNo", chNo, &b_chNo);
   fChain->SetBranchAddress("rangeType", rangeType, &b_rangeType);
   fChain->SetBranchAddress("adcData", adcData, &b_adcData);
   fChain->SetBranchAddress("dssdNo", dssdNo, &b_dssdNo);
   Notify();
}

Bool_t AIDA_parsed::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void AIDA_parsed::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t AIDA_parsed::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
//#endif // #ifdef AIDA_parsed_cxx
