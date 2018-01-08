//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Feb  2 19:00:02 2017 by ROOT version 6.04/10
// from TTree tree/go4 tree
// found on file: run_1300.root
//////////////////////////////////////////////////////////

#ifndef eurica_h
#define eurica_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"
#include "TNamed.h"

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxEventInfo = 1;
   const Int_t kMaxGeCluster = 460;
   const Int_t kMaxGeAddback = 270;
   const Int_t kMaxBigRIPSRaw = 10;


class eurica {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain


   // Declaration of leaf types
   Int_t           GeCluster_;
   UInt_t          GeCluster_fUniqueID[kMaxGeCluster];   //[GeCluster_]
   UInt_t          GeCluster_fBits[kMaxGeCluster];   //[GeCluster_]
   Int_t           GeCluster_id[kMaxGeCluster];   //[GeCluster_]
   Int_t           GeCluster_fpl[kMaxGeCluster];   //[GeCluster_]
   TString         GeCluster_name[kMaxGeCluster];
   Int_t           GeCluster_fDataState[kMaxGeCluster];   //[GeCluster_]
   Int_t           GeCluster_channel[kMaxGeCluster];   //[GeCluster_]
   Int_t           GeCluster_fADCe[kMaxGeCluster];   //[GeCluster_]
   Int_t           GeCluster_fADCt[kMaxGeCluster];   //[GeCluster_]
   Int_t           GeCluster_fTDCs[kMaxGeCluster];   //[GeCluster_]
   Int_t           GeCluster_fTDCl[kMaxGeCluster];   //[GeCluster_]
   Double_t        GeCluster_fEnergy[kMaxGeCluster];   //[GeCluster_]
   Double_t        GeCluster_fTime[kMaxGeCluster];   //[GeCluster_]
   Int_t           GeAddback_;
   UInt_t          GeAddback_fUniqueID[kMaxGeAddback];   //[GeAddback_]
   UInt_t          GeAddback_fBits[kMaxGeAddback];   //[GeAddback_]
   Int_t           GeAddback_id[kMaxGeAddback];   //[GeAddback_]
   Int_t           GeAddback_fpl[kMaxGeAddback];   //[GeAddback_]
   TString         GeAddback_name[kMaxGeAddback];
   Int_t           GeAddback_fDataState[kMaxGeAddback];   //[GeAddback_]
   Int_t           GeAddback_channel[kMaxGeAddback];   //[GeAddback_]
   Int_t           GeAddback_fADCe[kMaxGeAddback];   //[GeAddback_]
   Int_t           GeAddback_fADCt[kMaxGeAddback];   //[GeAddback_]
   Int_t           GeAddback_fTDCs[kMaxGeAddback];   //[GeAddback_]
   Int_t           GeAddback_fTDCl[kMaxGeAddback];   //[GeAddback_]
   Double_t        GeAddback_fEnergy[kMaxGeAddback];   //[GeAddback_]
   Double_t        GeAddback_fTime[kMaxGeAddback];   //[GeAddback_]
   Int_t           EventInfo_;
   UInt_t          EventInfo_fUniqueID[kMaxEventInfo];   //[EventInfo_]
   UInt_t          EventInfo_fBits[kMaxEventInfo];   //[EventInfo_]
   TString         EventInfo_fName[kMaxEventInfo];
   TString         EventInfo_fTitle[kMaxEventInfo];
   Int_t           EventInfo_runnumber[kMaxEventInfo];   //[EventInfo_]
   Int_t           EventInfo_eventnumber[kMaxEventInfo];   //[EventInfo_]
   TString         EventInfo_subsysname[kMaxEventInfo];
   ULong64_t       EventInfo_timestamp[kMaxEventInfo];   //[EventInfo_]
   Int_t           EventInfo_comp_val[kMaxEventInfo];   //[EventInfo_]
   UInt_t          EventInfo_fBit[kMaxEventInfo];   //[EventInfo_]
   Int_t           BigRIPSRaw_;
   UInt_t          BigRIPSRaw_fUniqueID[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_fBits[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   TString         BigRIPSRaw_fName[kMaxBigRIPSRaw];
   TString         BigRIPSRaw_fTitle[kMaxBigRIPSRaw];
   UInt_t          BigRIPSRaw_F3PPAC1_X1[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F3PPAC1_X2[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F3PPAC2_X1[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F3PPAC2_X2[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F5PPAC1_X1[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F5PPAC1_X2[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F5PPAC2_X1[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F5PPAC2_X2[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F3SCI_L[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F3SCI_R[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F7SCI_L[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F7SCI_R[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F11PPAC1_X1[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F11PPAC1_Y1[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F11PPAC1_X2[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F11PPAC1_Y2[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F11PPAC2_X1[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F11PPAC2_Y1[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F11PPAC2_X2[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F11PPAC2_Y2[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F11SCI_L[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   UInt_t          BigRIPSRaw_F11SCI_R[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_DE[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_F3PPAC1_TDiffX[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_F3PPAC2_TDiffX[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_F5PPAC1_TDiffX[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_F5PPAC2_TDiffX[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_F3PPAC1_X[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_F3PPAC2_X[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_F5PPAC1_X[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_F5PPAC2_X[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_F3_X[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_F3_A[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_F5_X[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_F5_A[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_TF3SCI_L[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_TF3SCI_R[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_TF7SCI_L[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_TF7SCI_R[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_Delta_F3F5[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_TOF_F3F7[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_dT_F3L[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_dT_F3R[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_dT_F7L[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_dT_F7R[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_dT_F3F11L[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_dT_F3F11R[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_ToF_F7[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_ToF_F11[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_Beta_F3F5[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_Beta_F5F7[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_AoQ_F3F5[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Float_t         BigRIPSRaw_Zed_F11[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Bool_t          BigRIPSRaw_FlagEvent[kMaxBigRIPSRaw];   //[BigRIPSRaw_]
   Bool_t          BigRIPSRaw_FlagPPAC[kMaxBigRIPSRaw];   //[BigRIPSRaw_]

   // List of branches
   TBranch        *b_GeCluster_;   //!
   TBranch        *b_GeCluster_fUniqueID;   //!
   TBranch        *b_GeCluster_fBits;   //!
   TBranch        *b_GeCluster_id;   //!
   TBranch        *b_GeCluster_fpl;   //!
   TBranch        *b_GeCluster_name;   //!
   TBranch        *b_GeCluster_fDataState;   //!
   TBranch        *b_GeCluster_channel;   //!
   TBranch        *b_GeCluster_fADCe;   //!
   TBranch        *b_GeCluster_fADCt;   //!
   TBranch        *b_GeCluster_fTDCs;   //!
   TBranch        *b_GeCluster_fTDCl;   //!
   TBranch        *b_GeCluster_fEnergy;   //!
   TBranch        *b_GeCluster_fTime;   //!
   TBranch        *b_GeAddback_;   //!
   TBranch        *b_GeAddback_fUniqueID;   //!
   TBranch        *b_GeAddback_fBits;   //!
   TBranch        *b_GeAddback_id;   //!
   TBranch        *b_GeAddback_fpl;   //!
   TBranch        *b_GeAddback_name;   //!
   TBranch        *b_GeAddback_fDataState;   //!
   TBranch        *b_GeAddback_channel;   //!
   TBranch        *b_GeAddback_fADCe;   //!
   TBranch        *b_GeAddback_fADCt;   //!
   TBranch        *b_GeAddback_fTDCs;   //!
   TBranch        *b_GeAddback_fTDCl;   //!
   TBranch        *b_GeAddback_fEnergy;   //!
   TBranch        *b_GeAddback_fTime;   //!
   TBranch        *b_EventInfo_;   //!
   TBranch        *b_EventInfo_fUniqueID;   //!
   TBranch        *b_EventInfo_fBits;   //!
   TBranch        *b_EventInfo_fName;   //!
   TBranch        *b_EventInfo_fTitle;   //!
   TBranch        *b_EventInfo_runnumber;   //!
   TBranch        *b_EventInfo_eventnumber;   //!
   TBranch        *b_EventInfo_subsysname;   //!
   TBranch        *b_EventInfo_timestamp;   //!
   TBranch        *b_EventInfo_comp_val;   //!
   TBranch        *b_EventInfo_fBit;   //!
   TBranch        *b_BigRIPSRaw_;   //!
   TBranch        *b_BigRIPSRaw_fUniqueID;   //!
   TBranch        *b_BigRIPSRaw_fBits;   //!
   TBranch        *b_BigRIPSRaw_fName;   //!
   TBranch        *b_BigRIPSRaw_fTitle;   //!
   TBranch        *b_BigRIPSRaw_F3PPAC1_X1;   //!
   TBranch        *b_BigRIPSRaw_F3PPAC1_X2;   //!
   TBranch        *b_BigRIPSRaw_F3PPAC2_X1;   //!
   TBranch        *b_BigRIPSRaw_F3PPAC2_X2;   //!
   TBranch        *b_BigRIPSRaw_F5PPAC1_X1;   //!
   TBranch        *b_BigRIPSRaw_F5PPAC1_X2;   //!
   TBranch        *b_BigRIPSRaw_F5PPAC2_X1;   //!
   TBranch        *b_BigRIPSRaw_F5PPAC2_X2;   //!
   TBranch        *b_BigRIPSRaw_F3SCI_L;   //!
   TBranch        *b_BigRIPSRaw_F3SCI_R;   //!
   TBranch        *b_BigRIPSRaw_F7SCI_L;   //!
   TBranch        *b_BigRIPSRaw_F7SCI_R;   //!
   TBranch        *b_BigRIPSRaw_F11PPAC1_X1;   //!
   TBranch        *b_BigRIPSRaw_F11PPAC1_Y1;   //!
   TBranch        *b_BigRIPSRaw_F11PPAC1_X2;   //!
   TBranch        *b_BigRIPSRaw_F11PPAC1_Y2;   //!
   TBranch        *b_BigRIPSRaw_F11PPAC2_X1;   //!
   TBranch        *b_BigRIPSRaw_F11PPAC2_Y1;   //!
   TBranch        *b_BigRIPSRaw_F11PPAC2_X2;   //!
   TBranch        *b_BigRIPSRaw_F11PPAC2_Y2;   //!
   TBranch        *b_BigRIPSRaw_F11SCI_L;   //!
   TBranch        *b_BigRIPSRaw_F11SCI_R;   //!
   TBranch        *b_BigRIPSRaw_DE;   //!
   TBranch        *b_BigRIPSRaw_F3PPAC1_TDiffX;   //!
   TBranch        *b_BigRIPSRaw_F3PPAC2_TDiffX;   //!
   TBranch        *b_BigRIPSRaw_F5PPAC1_TDiffX;   //!
   TBranch        *b_BigRIPSRaw_F5PPAC2_TDiffX;   //!
   TBranch        *b_BigRIPSRaw_F3PPAC1_X;   //!
   TBranch        *b_BigRIPSRaw_F3PPAC2_X;   //!
   TBranch        *b_BigRIPSRaw_F5PPAC1_X;   //!
   TBranch        *b_BigRIPSRaw_F5PPAC2_X;   //!
   TBranch        *b_BigRIPSRaw_F3_X;   //!
   TBranch        *b_BigRIPSRaw_F3_A;   //!
   TBranch        *b_BigRIPSRaw_F5_X;   //!
   TBranch        *b_BigRIPSRaw_F5_A;   //!
   TBranch        *b_BigRIPSRaw_TF3SCI_L;   //!
   TBranch        *b_BigRIPSRaw_TF3SCI_R;   //!
   TBranch        *b_BigRIPSRaw_TF7SCI_L;   //!
   TBranch        *b_BigRIPSRaw_TF7SCI_R;   //!
   TBranch        *b_BigRIPSRaw_Delta_F3F5;   //!
   TBranch        *b_BigRIPSRaw_TOF_F3F7;   //!
   TBranch        *b_BigRIPSRaw_dT_F3L;   //!
   TBranch        *b_BigRIPSRaw_dT_F3R;   //!
   TBranch        *b_BigRIPSRaw_dT_F7L;   //!
   TBranch        *b_BigRIPSRaw_dT_F7R;   //!
   TBranch        *b_BigRIPSRaw_dT_F3F11L;   //!
   TBranch        *b_BigRIPSRaw_dT_F3F11R;   //!
   TBranch        *b_BigRIPSRaw_ToF_F7;   //!
   TBranch        *b_BigRIPSRaw_ToF_F11;   //!
   TBranch        *b_BigRIPSRaw_Beta_F3F5;   //!
   TBranch        *b_BigRIPSRaw_Beta_F5F7;   //!
   TBranch        *b_BigRIPSRaw_AoQ_F3F5;   //!
   TBranch        *b_BigRIPSRaw_Zed_F11;   //!
   TBranch        *b_BigRIPSRaw_FlagEvent;   //!
   TBranch        *b_BigRIPSRaw_FlagPPAC;   //!

//   eurica(TTree *tree=0);
   eurica(char *filename, TTree *tree=0); 
   virtual ~eurica();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
//   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
virtual void GetTsEntry(std::map <Long64_t, Long64_t> &mts);
};

#endif

eurica::eurica(char *filename, TTree *tree) : fChain(0)
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

/*//#ifdef eurica_cxx
eurica::eurica(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("run_1300.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("run_1300.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}*/

eurica::~eurica()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t eurica::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t eurica::LoadTree(Long64_t entry)
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

void eurica::Init(TTree *tree)
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

   fChain->SetBranchAddress("GeCluster", &GeCluster_, &b_GeCluster_);
   fChain->SetBranchAddress("GeCluster.fUniqueID", GeCluster_fUniqueID, &b_GeCluster_fUniqueID);
   fChain->SetBranchAddress("GeCluster.fBits", GeCluster_fBits, &b_GeCluster_fBits);
   fChain->SetBranchAddress("GeCluster.id", GeCluster_id, &b_GeCluster_id);
   fChain->SetBranchAddress("GeCluster.fpl", GeCluster_fpl, &b_GeCluster_fpl);
   fChain->SetBranchAddress("GeCluster.name", GeCluster_name, &b_GeCluster_name);
   fChain->SetBranchAddress("GeCluster.fDataState", GeCluster_fDataState, &b_GeCluster_fDataState);
   fChain->SetBranchAddress("GeCluster.channel", GeCluster_channel, &b_GeCluster_channel);
   fChain->SetBranchAddress("GeCluster.fADCe", GeCluster_fADCe, &b_GeCluster_fADCe);
   fChain->SetBranchAddress("GeCluster.fADCt", GeCluster_fADCt, &b_GeCluster_fADCt);
   fChain->SetBranchAddress("GeCluster.fTDCs", GeCluster_fTDCs, &b_GeCluster_fTDCs);
   fChain->SetBranchAddress("GeCluster.fTDCl", GeCluster_fTDCl, &b_GeCluster_fTDCl);
   fChain->SetBranchAddress("GeCluster.fEnergy", GeCluster_fEnergy, &b_GeCluster_fEnergy);
   fChain->SetBranchAddress("GeCluster.fTime", GeCluster_fTime, &b_GeCluster_fTime);
   fChain->SetBranchAddress("GeAddback", &GeAddback_, &b_GeAddback_);
   fChain->SetBranchAddress("GeAddback.fUniqueID", GeAddback_fUniqueID, &b_GeAddback_fUniqueID);
   fChain->SetBranchAddress("GeAddback.fBits", GeAddback_fBits, &b_GeAddback_fBits);
   fChain->SetBranchAddress("GeAddback.id", GeAddback_id, &b_GeAddback_id);
   fChain->SetBranchAddress("GeAddback.fpl", GeAddback_fpl, &b_GeAddback_fpl);
   fChain->SetBranchAddress("GeAddback.name", GeAddback_name, &b_GeAddback_name);
   fChain->SetBranchAddress("GeAddback.fDataState", GeAddback_fDataState, &b_GeAddback_fDataState);
   fChain->SetBranchAddress("GeAddback.channel", GeAddback_channel, &b_GeAddback_channel);
   fChain->SetBranchAddress("GeAddback.fADCe", GeAddback_fADCe, &b_GeAddback_fADCe);
   fChain->SetBranchAddress("GeAddback.fADCt", GeAddback_fADCt, &b_GeAddback_fADCt);
   fChain->SetBranchAddress("GeAddback.fTDCs", GeAddback_fTDCs, &b_GeAddback_fTDCs);
   fChain->SetBranchAddress("GeAddback.fTDCl", GeAddback_fTDCl, &b_GeAddback_fTDCl);
   fChain->SetBranchAddress("GeAddback.fEnergy", GeAddback_fEnergy, &b_GeAddback_fEnergy);
   fChain->SetBranchAddress("GeAddback.fTime", GeAddback_fTime, &b_GeAddback_fTime);
   fChain->SetBranchAddress("EventInfo", &EventInfo_, &b_EventInfo_);
   fChain->SetBranchAddress("EventInfo.fUniqueID", EventInfo_fUniqueID, &b_EventInfo_fUniqueID);
   fChain->SetBranchAddress("EventInfo.fBits", EventInfo_fBits, &b_EventInfo_fBits);
   fChain->SetBranchAddress("EventInfo.fName", EventInfo_fName, &b_EventInfo_fName);
   fChain->SetBranchAddress("EventInfo.fTitle", EventInfo_fTitle, &b_EventInfo_fTitle);
   fChain->SetBranchAddress("EventInfo.runnumber", EventInfo_runnumber, &b_EventInfo_runnumber);
   fChain->SetBranchAddress("EventInfo.eventnumber", EventInfo_eventnumber, &b_EventInfo_eventnumber);
   fChain->SetBranchAddress("EventInfo.subsysname", EventInfo_subsysname, &b_EventInfo_subsysname);
   fChain->SetBranchAddress("EventInfo.timestamp", EventInfo_timestamp, &b_EventInfo_timestamp);
   fChain->SetBranchAddress("EventInfo.comp_val", EventInfo_comp_val, &b_EventInfo_comp_val);
   fChain->SetBranchAddress("EventInfo.fBit", EventInfo_fBit, &b_EventInfo_fBit);
   fChain->SetBranchAddress("BigRIPSRaw", &BigRIPSRaw_, &b_BigRIPSRaw_);
   fChain->SetBranchAddress("BigRIPSRaw.fUniqueID", BigRIPSRaw_fUniqueID, &b_BigRIPSRaw_fUniqueID);
   fChain->SetBranchAddress("BigRIPSRaw.fBits", BigRIPSRaw_fBits, &b_BigRIPSRaw_fBits);
   fChain->SetBranchAddress("BigRIPSRaw.fName", BigRIPSRaw_fName, &b_BigRIPSRaw_fName);
   fChain->SetBranchAddress("BigRIPSRaw.fTitle", BigRIPSRaw_fTitle, &b_BigRIPSRaw_fTitle);
   fChain->SetBranchAddress("BigRIPSRaw.F3PPAC1_X1", BigRIPSRaw_F3PPAC1_X1, &b_BigRIPSRaw_F3PPAC1_X1);
   fChain->SetBranchAddress("BigRIPSRaw.F3PPAC1_X2", BigRIPSRaw_F3PPAC1_X2, &b_BigRIPSRaw_F3PPAC1_X2);
   fChain->SetBranchAddress("BigRIPSRaw.F3PPAC2_X1", BigRIPSRaw_F3PPAC2_X1, &b_BigRIPSRaw_F3PPAC2_X1);
   fChain->SetBranchAddress("BigRIPSRaw.F3PPAC2_X2", BigRIPSRaw_F3PPAC2_X2, &b_BigRIPSRaw_F3PPAC2_X2);
   fChain->SetBranchAddress("BigRIPSRaw.F5PPAC1_X1", BigRIPSRaw_F5PPAC1_X1, &b_BigRIPSRaw_F5PPAC1_X1);
   fChain->SetBranchAddress("BigRIPSRaw.F5PPAC1_X2", BigRIPSRaw_F5PPAC1_X2, &b_BigRIPSRaw_F5PPAC1_X2);
   fChain->SetBranchAddress("BigRIPSRaw.F5PPAC2_X1", BigRIPSRaw_F5PPAC2_X1, &b_BigRIPSRaw_F5PPAC2_X1);
   fChain->SetBranchAddress("BigRIPSRaw.F5PPAC2_X2", BigRIPSRaw_F5PPAC2_X2, &b_BigRIPSRaw_F5PPAC2_X2);
   fChain->SetBranchAddress("BigRIPSRaw.F3SCI_L", BigRIPSRaw_F3SCI_L, &b_BigRIPSRaw_F3SCI_L);
   fChain->SetBranchAddress("BigRIPSRaw.F3SCI_R", BigRIPSRaw_F3SCI_R, &b_BigRIPSRaw_F3SCI_R);
   fChain->SetBranchAddress("BigRIPSRaw.F7SCI_L", BigRIPSRaw_F7SCI_L, &b_BigRIPSRaw_F7SCI_L);
   fChain->SetBranchAddress("BigRIPSRaw.F7SCI_R", BigRIPSRaw_F7SCI_R, &b_BigRIPSRaw_F7SCI_R);
   fChain->SetBranchAddress("BigRIPSRaw.F11PPAC1_X1", BigRIPSRaw_F11PPAC1_X1, &b_BigRIPSRaw_F11PPAC1_X1);
   fChain->SetBranchAddress("BigRIPSRaw.F11PPAC1_Y1", BigRIPSRaw_F11PPAC1_Y1, &b_BigRIPSRaw_F11PPAC1_Y1);
   fChain->SetBranchAddress("BigRIPSRaw.F11PPAC1_X2", BigRIPSRaw_F11PPAC1_X2, &b_BigRIPSRaw_F11PPAC1_X2);
   fChain->SetBranchAddress("BigRIPSRaw.F11PPAC1_Y2", BigRIPSRaw_F11PPAC1_Y2, &b_BigRIPSRaw_F11PPAC1_Y2);
   fChain->SetBranchAddress("BigRIPSRaw.F11PPAC2_X1", BigRIPSRaw_F11PPAC2_X1, &b_BigRIPSRaw_F11PPAC2_X1);
   fChain->SetBranchAddress("BigRIPSRaw.F11PPAC2_Y1", BigRIPSRaw_F11PPAC2_Y1, &b_BigRIPSRaw_F11PPAC2_Y1);
   fChain->SetBranchAddress("BigRIPSRaw.F11PPAC2_X2", BigRIPSRaw_F11PPAC2_X2, &b_BigRIPSRaw_F11PPAC2_X2);
   fChain->SetBranchAddress("BigRIPSRaw.F11PPAC2_Y2", BigRIPSRaw_F11PPAC2_Y2, &b_BigRIPSRaw_F11PPAC2_Y2);
   fChain->SetBranchAddress("BigRIPSRaw.F11SCI_L", BigRIPSRaw_F11SCI_L, &b_BigRIPSRaw_F11SCI_L);
   fChain->SetBranchAddress("BigRIPSRaw.F11SCI_R", BigRIPSRaw_F11SCI_R, &b_BigRIPSRaw_F11SCI_R);
   fChain->SetBranchAddress("BigRIPSRaw.DE", BigRIPSRaw_DE, &b_BigRIPSRaw_DE);
   fChain->SetBranchAddress("BigRIPSRaw.F3PPAC1_TDiffX", BigRIPSRaw_F3PPAC1_TDiffX, &b_BigRIPSRaw_F3PPAC1_TDiffX);
   fChain->SetBranchAddress("BigRIPSRaw.F3PPAC2_TDiffX", BigRIPSRaw_F3PPAC2_TDiffX, &b_BigRIPSRaw_F3PPAC2_TDiffX);
   fChain->SetBranchAddress("BigRIPSRaw.F5PPAC1_TDiffX", BigRIPSRaw_F5PPAC1_TDiffX, &b_BigRIPSRaw_F5PPAC1_TDiffX);
   fChain->SetBranchAddress("BigRIPSRaw.F5PPAC2_TDiffX", BigRIPSRaw_F5PPAC2_TDiffX, &b_BigRIPSRaw_F5PPAC2_TDiffX);
   fChain->SetBranchAddress("BigRIPSRaw.F3PPAC1_X", BigRIPSRaw_F3PPAC1_X, &b_BigRIPSRaw_F3PPAC1_X);
   fChain->SetBranchAddress("BigRIPSRaw.F3PPAC2_X", BigRIPSRaw_F3PPAC2_X, &b_BigRIPSRaw_F3PPAC2_X);
   fChain->SetBranchAddress("BigRIPSRaw.F5PPAC1_X", BigRIPSRaw_F5PPAC1_X, &b_BigRIPSRaw_F5PPAC1_X);
   fChain->SetBranchAddress("BigRIPSRaw.F5PPAC2_X", BigRIPSRaw_F5PPAC2_X, &b_BigRIPSRaw_F5PPAC2_X);
   fChain->SetBranchAddress("BigRIPSRaw.F3_X", BigRIPSRaw_F3_X, &b_BigRIPSRaw_F3_X);
   fChain->SetBranchAddress("BigRIPSRaw.F3_A", BigRIPSRaw_F3_A, &b_BigRIPSRaw_F3_A);
   fChain->SetBranchAddress("BigRIPSRaw.F5_X", BigRIPSRaw_F5_X, &b_BigRIPSRaw_F5_X);
   fChain->SetBranchAddress("BigRIPSRaw.F5_A", BigRIPSRaw_F5_A, &b_BigRIPSRaw_F5_A);
   fChain->SetBranchAddress("BigRIPSRaw.TF3SCI_L", BigRIPSRaw_TF3SCI_L, &b_BigRIPSRaw_TF3SCI_L);
   fChain->SetBranchAddress("BigRIPSRaw.TF3SCI_R", BigRIPSRaw_TF3SCI_R, &b_BigRIPSRaw_TF3SCI_R);
   fChain->SetBranchAddress("BigRIPSRaw.TF7SCI_L", BigRIPSRaw_TF7SCI_L, &b_BigRIPSRaw_TF7SCI_L);
   fChain->SetBranchAddress("BigRIPSRaw.TF7SCI_R", BigRIPSRaw_TF7SCI_R, &b_BigRIPSRaw_TF7SCI_R);
   fChain->SetBranchAddress("BigRIPSRaw.Delta_F3F5", BigRIPSRaw_Delta_F3F5, &b_BigRIPSRaw_Delta_F3F5);
   fChain->SetBranchAddress("BigRIPSRaw.TOF_F3F7", BigRIPSRaw_TOF_F3F7, &b_BigRIPSRaw_TOF_F3F7);
   fChain->SetBranchAddress("BigRIPSRaw.dT_F3L", BigRIPSRaw_dT_F3L, &b_BigRIPSRaw_dT_F3L);
   fChain->SetBranchAddress("BigRIPSRaw.dT_F3R", BigRIPSRaw_dT_F3R, &b_BigRIPSRaw_dT_F3R);
   fChain->SetBranchAddress("BigRIPSRaw.dT_F7L", BigRIPSRaw_dT_F7L, &b_BigRIPSRaw_dT_F7L);
   fChain->SetBranchAddress("BigRIPSRaw.dT_F7R", BigRIPSRaw_dT_F7R, &b_BigRIPSRaw_dT_F7R);
   fChain->SetBranchAddress("BigRIPSRaw.dT_F3F11L", BigRIPSRaw_dT_F3F11L, &b_BigRIPSRaw_dT_F3F11L);
   fChain->SetBranchAddress("BigRIPSRaw.dT_F3F11R", BigRIPSRaw_dT_F3F11R, &b_BigRIPSRaw_dT_F3F11R);
   fChain->SetBranchAddress("BigRIPSRaw.ToF_F7", BigRIPSRaw_ToF_F7, &b_BigRIPSRaw_ToF_F7);
   fChain->SetBranchAddress("BigRIPSRaw.ToF_F11", BigRIPSRaw_ToF_F11, &b_BigRIPSRaw_ToF_F11);
   fChain->SetBranchAddress("BigRIPSRaw.Beta_F3F5", BigRIPSRaw_Beta_F3F5, &b_BigRIPSRaw_Beta_F3F5);
   fChain->SetBranchAddress("BigRIPSRaw.Beta_F5F7", BigRIPSRaw_Beta_F5F7, &b_BigRIPSRaw_Beta_F5F7);
   fChain->SetBranchAddress("BigRIPSRaw.AoQ_F3F5", BigRIPSRaw_AoQ_F3F5, &b_BigRIPSRaw_AoQ_F3F5);
   fChain->SetBranchAddress("BigRIPSRaw.Zed_F11", BigRIPSRaw_Zed_F11, &b_BigRIPSRaw_Zed_F11);
   fChain->SetBranchAddress("BigRIPSRaw.FlagEvent", BigRIPSRaw_FlagEvent, &b_BigRIPSRaw_FlagEvent);
   fChain->SetBranchAddress("BigRIPSRaw.FlagPPAC", BigRIPSRaw_FlagPPAC, &b_BigRIPSRaw_FlagPPAC);
   Notify();
}

Bool_t eurica::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void eurica::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t eurica::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

void eurica::GetTsEntry(std::map<Long64_t,Long64_t> &mts)
{
   Long64_t nenties = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb =0;
   for(Long64_t jentry = 0;jentry < nenties ;jentry++)
   {
      Long64_t ientry = LoadTree(jentry);
      if(ientry<0) break;
      nb = fChain->GetEntry(jentry); nbytes += nb;
      Long64_t ts = (Long64_t)EventInfo_timestamp[0];
      if(jentry%100000 == 0) std::cout<<"eurica ts = "<<ts<<std::endl;
      mts.insert(std::pair<Long64_t,Long64_t> (ts,jentry));
   }
}



//#endif // #ifdef eurica_cxx
