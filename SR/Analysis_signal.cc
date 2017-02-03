#include <iostream>
#include <cmath>
#include "TH1.h"
#include "TH2.h"
#include "TTree.h"
#include "TBranch.h"
#include "TLorentzVector.h"
#include "TLorentzRotation.h"
#include "TFile.h"
#include "TCanvas.h"
#include <TLegend.h>
#include <TPad.h>
#include "TF1.h"
#include "TF2.h"
#include <TStyle.h>
#include "TLine.h"
#include "TProfile.h"
#include "TAttFill.h"
#include <iostream>
#include <cstring>
#include <string>
#include <TGraphErrors.h>
#include <Riostream.h>
#include "TFile.h"
#include <TChain.h>
#include <TClonesArray.h>
#include <TLegendEntry.h>
#include <TGraphAsymmErrors.h>
#include <Analysis_signal.h>



using namespace std;


ClassImp(Analysis_signal)

//_______________________________________________________default constructor_____
Analysis_signal::Analysis_signal():TObject()

{
}
//_______________________________________________________ constructor_____
Analysis_signal::Analysis_signal(string FileNameTree_in):TObject()

{
}
//________________________________________________________________distruttore_____
Analysis_signal::~Analysis_signal()	 {
  // destructor
}

//==================================================================
void Analysis_signal::selection_ossf(int massa,
                                     int num_histo_kin,
                                     int num_histo,
                                     double xsection,
                                     double luminosity,
                                     string FileNameTree_in,
                                     TH1D* histo_ossf_kin_rec_l1 [num_histo_kin],
                                     TH1D* histo_ossf_kin_rec_l2 [num_histo_kin],
                                     TH1D* histo_ossf_kin_rec_l3 [num_histo_kin],
                                     TH1D* histo_ossf_kin_gen_l1 [num_histo_kin],
                                     TH1D* histo_ossf_kin_gen_l2 [num_histo_kin],
                                     TH1D* histo_ossf_kin_gen_l3 [num_histo_kin],
                                     TH1D* histo_ossf_rec[num_histo],
                                     TH1D* histo_ossf_gen[num_histo],
                                     TH1D* histo_n_ossf_kin_rec_l1 [num_histo_kin],
                                     TH1D* histo_n_ossf_kin_rec_l2 [num_histo_kin],
                                     TH1D* histo_n_ossf_kin_rec_l3 [num_histo_kin],
                                     TH1D* histo_n_ossf_kin_gen_l1 [num_histo_kin],
                                     TH1D* histo_n_ossf_kin_gen_l2 [num_histo_kin],
                                     TH1D* histo_n_ossf_kin_gen_l3 [num_histo_kin],
                                     TH1D* histo_n_ossf_rec[num_histo],
                                     TH1D* histo_n_ossf_gen[num_histo],
                                     TH1D* flavor_plot_ossf,
                                     TH1D* flavor_plot_n_ossf,


				     TH2D *signal_5_2d_ossf,
				     TH2D *signal_10_2d_ossf,
				     TH2D *signal_15_2d_ossf,
				     TH2D *signal_20_2d_ossf,
				     TH2D *signal_40_2d_ossf,
				     TH2D *signal_50_2d_ossf,
				     TH2D *signal_60_2d_ossf,

				     TH2D *signal_5_2d_n_ossf,
				     TH2D *signal_10_2d_n_ossf,
				     TH2D *signal_15_2d_n_ossf,
				     TH2D *signal_20_2d_n_ossf,
				     TH2D *signal_40_2d_n_ossf,
				     TH2D *signal_50_2d_n_ossf,
				     TH2D *signal_60_2d_n_ossf,
TH2D *signal_5_2d_pt_ossf,
TH2D *signal_10_2d_pt_ossf,
TH2D *signal_15_2d_pt_ossf,
TH2D *signal_20_2d_pt_ossf,
TH2D *signal_40_2d_pt_ossf,
TH2D *signal_50_2d_pt_ossf,
TH2D *signal_60_2d_pt_ossf,

TH2D *signal_5_2d_pt_n_ossf,
TH2D *signal_10_2d_pt_n_ossf,
TH2D *signal_15_2d_pt_n_ossf,
TH2D *signal_20_2d_pt_n_ossf,
TH2D *signal_40_2d_pt_n_ossf,
TH2D *signal_50_2d_pt_n_ossf,
TH2D *signal_60_2d_pt_n_ossf
                                     ){
    
   // Declaration of leaf types
    TClonesArray    *_leptonP4;
    TClonesArray    *_gen_leptonP4;
    TClonesArray    *_gen_nuP4;
    TClonesArray    *_gen_majoP4;
    TClonesArray    *_gen_wP4;
    ULong64_t       _eventNb=0;
    ULong64_t       _runNb=0;
    ULong64_t       _lumiBlock=0;
    Int_t           _nLeptons=0;
    _nLeptons=30;
    Double_t        _lPt[_nLeptons];   //[_nLeptons]
    Double_t        _lEta[_nLeptons];   //[_nLeptons]
    Double_t        _lPhi[_nLeptons];   //[_nLeptons]
    Double_t        _lE[_nLeptons];   //[_nLeptons]
    Double_t        _lPtmc[_nLeptons];   //[_nLeptons]
    Double_t        _lEtamc[_nLeptons];   //[_nLeptons]
    Double_t        _lPhimc[_nLeptons];   //[_nLeptons]
    Double_t        _lEmc[_nLeptons];   //[_nLeptons]
    Double_t        _lpdgmc[_nLeptons];   //[_nLeptons]
    Double_t        _lchargemc[_nLeptons];   //[_nLeptons]
    Double_t        _nuPtmc[_nLeptons];   //[_nLeptons]
    Double_t        _nuEtamc[_nLeptons];   //[_nLeptons]
    Double_t        _nuPhimc[_nLeptons];   //[_nLeptons]
    Double_t        _nuEmc[_nLeptons];   //[_nLeptons]
    Double_t        _mtmc[_nLeptons];   //[_nLeptons]
    Int_t           _nZboson;
    Int_t           _nEle=0;
    Int_t           _nMu=0;
    Int_t           _nTau=0;
    Int_t           _flavors[_nLeptons];   //[_nLeptons]
    Double_t        _charges[_nLeptons];   //[_nLeptons]
    Int_t           _indeces[_nLeptons];   //[_nLeptons]
    Double_t        _isolation[_nLeptons];   //[_nLeptons]
    Double_t        _isolation_absolute[_nLeptons];   //[_nLeptons]
    Double_t        _miniisolation[_nLeptons][2];   //[_nLeptons]
    Double_t        _miniisolationCharged[_nLeptons][2];   //[_nLeptons]
    Bool_t          _multiisolation[_nLeptons][5];   //[_nLeptons]
    Double_t        _ptrel[_nLeptons];   //[_nLeptons]
    Double_t        _ptratio[_nLeptons];   //[_nLeptons]
    Double_t        _muonSegmentComp[_nLeptons];   //[_nLeptons]
    Double_t        _mll[_nLeptons];
    Int_t           _origin[_nLeptons];   //[_nLeptons]
    Int_t           _originReduced[_nLeptons];   //[_nLeptons]
    Bool_t          _isPromptFinalState[_nLeptons];   //[_nLeptons]
    Bool_t          _fromHardProcessFinalState[_nLeptons];   //[_nLeptons]
    Double_t        _PVchi2;
    Double_t        _PVerr[_nLeptons];
    Double_t        _ipPV[_nLeptons];   //[_nLeptons]
    Double_t        _ipPVerr[_nLeptons];   //[_nLeptons]
    Double_t        _ipZPV[_nLeptons];   //[_nLeptons]
    Double_t        _ipZPVerr[_nLeptons];   //[_nLeptons]
    Double_t        _ipPVmc[_nLeptons];   //[_nLeptons]
    Double_t        _3dIP[_nLeptons];   //[_nLeptons]
    Double_t        _3dIPerr[_nLeptons];   //[_nLeptons]
    Double_t        _3dIPsig[_nLeptons];   //[_nLeptons]
    Double_t        _mt[_nLeptons];   //[_nLeptons]
    Bool_t          _isloose[_nLeptons];   //[_nLeptons]
    Bool_t          _istight[_nLeptons];   //[_nLeptons]
    Bool_t          _ismedium[_nLeptons];   //[_nLeptons]
    Bool_t          _istightID[_nLeptons];   //[_nLeptons]
    Bool_t          _trigEmulator[_nLeptons];   //[_nLeptons]
    Bool_t          _isotrigEmulator[_nLeptons];   //[_nLeptons]
    Double_t        _closeJetPtAll[_nLeptons];   //[_nLeptons]
    Double_t        _closeJetAngAll[_nLeptons];   //[_nLeptons]
    Int_t           _trackSelectionMultiplicity[_nLeptons];   //[_nLeptons]
    Double_t        _closeJetCSVAll[_nLeptons];   //[_nLeptons]
    Bool_t          _chargeConst[_nLeptons];   //[_nLeptons]
    Int_t           _hitsNumber[_nLeptons];   //[_nLeptons]
    Bool_t          _vtxFitConversion[_nLeptons];   //[_nLeptons]
    Double_t        _mvaValue[_nLeptons];   //[_nLeptons]
    Bool_t          _decayModeFinding[_nLeptons];   //[_nLeptons]
    Bool_t          _looseMVA_dR03[_nLeptons];   //[_nLeptons]
    Bool_t          _mediumMVA_dR03[_nLeptons];   //[_nLeptons]
    Bool_t          _vlooseMVAold[_nLeptons];   //[_nLeptons]
    Bool_t          _looseMVAold[_nLeptons];   //[_nLeptons]
    Bool_t          _mediumMVAold[_nLeptons];   //[_nLeptons]
    Bool_t          _tightMVAold[_nLeptons];   //[_nLeptons]
    Bool_t          _vtightMVAold[_nLeptons];   //[_nLeptons]
    Bool_t          _decayModeFindingNewDMs[_nLeptons];   //[_nLeptons]
    Bool_t          _vlooseMVAnew[_nLeptons];   //[_nLeptons]
    Bool_t          _looseMVAnew[_nLeptons];   //[_nLeptons]
    Bool_t          _mediumMVAnew[_nLeptons];   //[_nLeptons]
    Bool_t          _tightMVAnew[_nLeptons];   //[_nLeptons]
    Bool_t          _vtightMVAnew[_nLeptons];   //[_nLeptons]
    Int_t           _n_PV=0;
    Double_t        _n_MCTruth_PV=0;
    Double_t        _met=0;
    Double_t        _met_phi=0;
    Double_t        HT=0;
    Double_t        _genmet=0;
    Double_t        _genmet_phi=0;
    Double_t        _genqpt=0;
    Double_t        _genqpt20=0;
    Double_t        _mompt[_nLeptons];   //[_nLeptons]
    Double_t        _momphi[_nLeptons];   //[_nLeptons]
    Double_t        _mometa[_nLeptons];   //[_nLeptons]
    Int_t           _mompdg[_nLeptons];   //[_nLeptons]
    Int_t           _n_bJets=0;
    Int_t           _n_Jets=0;
    _n_Jets=50;
    Bool_t          _bTagged[_n_Jets];   //[_n_Jets]
    Double_t        _jetEta[_n_Jets];   //[_n_Jets]
    Double_t        _jetPhi[_n_Jets];   //[_n_Jets]
    Double_t        _jetPt[_n_Jets];   //[_n_Jets]
    Int_t           _jetFlavour[_n_Jets];   //[_n_Jets]
    Double_t        _jetE[_n_Jets];   //[_n_Jets]
    Double_t        _csv[_n_Jets];   //[_n_Jets]
    Double_t        _jetDeltaR[_n_Jets][_nLeptons];   //[_n_Jets]
    int _clean[_n_Jets];
    Double_t        _jecUnc[_n_Jets];   //[_n_Jets]
    Double_t        _jetPtUp[_n_Jets];   //[_n_Jets]
    Double_t        _jetPtDown[_n_Jets];   //[_n_Jets]
    Double_t        _matchedjetPt[_n_Jets];   //[_n_Jets]
    Double_t        _matchedjetEta[_n_Jets];   //[_n_Jets]
    Double_t        _matchedjetPhi[_n_Jets];   //[_n_Jets]
    Double_t        _matchedjetE[_n_Jets];   //[_n_Jets]
    Double_t        _matchedjetM[_n_Jets];   //[_n_Jets]
    Bool_t          _matchGjet[_n_Jets];   //[_n_Jets]
    Double_t        _btagSF[19][_n_Jets];
    Double_t        _weight=0.;
    Double_t        _LHEweight[111];
    Double_t        _LHEweightID[111];
    Double_t        _mgluino=0.;
    Double_t        _mchi0=0.;
    Int_t           _nMajorana=0;
    Bool_t           _passedMVA80[_nLeptons] ;
    Bool_t           _passedMVA90[_nLeptons];
    Int_t           _findMatched[_nLeptons];
    Int_t           _gen_nL=0;
    _gen_nL=30;
    Double_t        _gen_lPt[_gen_nL];   //[_gen_nL]
    Double_t        _gen_lE[_gen_nL];   //[_gen_nL]
    Double_t        _gen_lEta[_gen_nL];   //[_gen_nL]
    Double_t        _gen_lPhi[_gen_nL];   //[_gen_nL]
    Int_t           _gen_lmompdg[_gen_nL];   //[_gen_nL]
    Double_t        _gen_charges[_gen_nL];   //[_gen_nL]
    Int_t           _gen_flavors[_gen_nL];   //[_gen_nL]
    Int_t           _gen_nNu=0;
    _gen_nNu=30;
    Double_t        _gen_nuPt[_gen_nNu];   //[_gen_nNu]
    Double_t        _gen_nuE[_gen_nNu];   //[_gen_nNu]
    Double_t        _gen_nuEta[_gen_nNu];   //[_gen_nNu]
    Double_t        _gen_nuPhi[_gen_nNu];   //[_gen_nNu]
    Int_t           _gen_numompdg[_gen_nNu];   //[_gen_nL]
    Int_t           _gen_nMajo;
    _gen_nMajo=30;
    Double_t        _gen_majoPt[_gen_nMajo];   //[_gen_nMajo]
    Double_t        _gen_majoE[_gen_nMajo];   //[_gen_nMajo]
    Double_t        _gen_majoEta[_gen_nMajo];   //[_gen_nMajo]
    Double_t        _gen_majoPhi[_gen_nMajo];   //[_gen_nMajo]
    Int_t           _gen_nW=0;
    _gen_nW=30;
    Double_t        _gen_wPt[_gen_nW];   //[_gen_nW]
    Double_t        _gen_wE[_gen_nW];   //[_gen_nW]
    Double_t        _gen_wEta[_gen_nW];   //[_gen_nW]
    Double_t        _gen_wPhi[_gen_nW];   //[_gen_nW]
    Int_t           _gen_wmompdg[_gen_nW];   //[_gen_nL]
    
    
    
    
     TFile hfile(FileNameTree_in.c_str());
    TH1D *h_Counter = (TH1D*)hfile.Get("trileptonProducer/hCounter");
    TTree *tree = (TTree*)hfile.Get("trileptonProducer/trileptonTree");
    
    _leptonP4 = 0;
    _gen_leptonP4=0;
    _gen_nuP4=0;
    _gen_majoP4=0;
    _gen_wP4=0;
    
    
    // List of branches
    TBranch        *b__leptonP4;   //!
    TBranch        *b__gen_leptonP4;   //!
    TBranch        *b__gen_nuP4;   //!
    TBranch        *b__gen_majoP4;   //!
    TBranch        *b__gen_wP4;   //!
    TBranch        *b__eventNb;   //!
    TBranch        *b__runNb;   //!
    TBranch        *b__lumiBlock;   //!
    TBranch        *b__nLeptons;   //!
    TBranch        *b__lPt;   //!
    TBranch        *b__lEta;   //!
    TBranch        *b__lPhi;   //!
    TBranch        *b__lE;   //!
    TBranch        *b__lPtmc;   //!
    TBranch        *b__lEtamc;   //!
    TBranch        *b__lPhimc;   //!
    TBranch        *b__lEmc;   //!
    TBranch        *b__lpdgmc;   //!
    TBranch        *b__lchargemc;   //!
    TBranch        *b__nuPtmc;   //!
    TBranch        *b__nuEtamc;   //!
    TBranch        *b__nuPhimc;   //!
    TBranch        *b__nuEmc;   //!
    TBranch        *b__mtmc;   //!
    TBranch        *b__nZboson;   //!
    TBranch        *b__nEle;   //!
    TBranch        *b__nMu;   //!
    TBranch        *b__nTau;   //!
    TBranch        *b__flavors;   //!
    TBranch        *b__charges;   //!
    TBranch        *b__indeces;   //!
    TBranch        *b__isolation;   //!
    TBranch        *b__isolation_absolute;   //!
    TBranch        *b__miniisolation;   //!
    TBranch        *b__miniisolationCharged;   //!
    TBranch        *b__multiisolation;   //!
    TBranch        *b__ptrel;   //!
    TBranch        *b__ptratio;   //!
    TBranch        *b__muonSegmentComp;   //!
    TBranch        *b__mll;   //!
    TBranch        *b__origin;   //!
    TBranch        *b__originReduced;   //!
    TBranch        *b__isPromptFinalState;   //!
    TBranch        *b__fromHardProcessFinalState;   //!
    TBranch        *b__PVchi2;   //!
    TBranch        *b__PVerr;   //!
    TBranch        *b__ipPV;   //!
    TBranch        *b__ipPVerr;   //!
    TBranch        *b__ipZPV;   //!
    TBranch        *b__ipZPVerr;   //!
    TBranch        *b__ipPVmc;   //!
    TBranch        *b__3dIP;   //!
    TBranch        *b__3dIPerr;   //!
    TBranch        *b__3dIPsig;   //!
    TBranch        *b__mt;   //!
    TBranch        *b__isloose;   //!
    TBranch        *b__istight;   //!
    
    TBranch        *b__ismedium;   //!
    TBranch        *b__istightID;   //!
    TBranch        *b__trigEmulator;   //!
    TBranch        *b__isotrigEmulator;   //!
    TBranch        *b__closeJetPtAll;   //!
    TBranch        *b__closeJetAngAll;   //!
    TBranch        *b__trackSelectionMultiplicity;   //!
    TBranch        *b__closeJetCSVAll;   //!
    TBranch        *b__chargeConst;   //!
    TBranch        *b__hitsNumber;   //!
    TBranch        *b__vtxFitConversion;   //!
    TBranch        *b__mvaValue;   //!
    TBranch        *b__decayModeFinding;   //!
    TBranch        *b__looseMVA_dR03;   //!
    TBranch        *b__mediumMVA_dR03;   //!
    TBranch        *b__vlooseMVAold;   //!
    TBranch        *b__looseMVAold;   //!
    TBranch        *b__mediumMVAold;   //!
    TBranch        *b__tightMVAold;   //!
    TBranch        *b__vtightMVAold;   //!
    TBranch        *b__decayModeFindingNewDMs;   //!
    TBranch        *b__vlooseMVAnew;   //!
    TBranch        *b__looseMVAnew;   //!
    TBranch        *b__mediumMVAnew;   //!
    TBranch        *b__tightMVAnew;   //!
    TBranch        *b__vtightMVAnew;   //!
    TBranch        *b__n_PV;   //!
    TBranch        *b__n_MCTruth_PV;   //!
    TBranch        *b__met;   //!
    TBranch        *b__met_phi;   //!
    TBranch        *b_HT;   //!
    TBranch        *b__genmet;   //!
    TBranch        *b__genmet_phi;   //!
    TBranch        *b__genqpt;   //!
    TBranch        *b__genqpt20;   //!
    TBranch        *b__mompt;   //!
    TBranch        *b__momphi;   //!
    TBranch        *b__mometa;   //!
    TBranch        *b__mompdg;   //!
    TBranch        *b__n_bJets;   //!
    TBranch        *b__n_Jets;   //!
    TBranch        *b__bTagged;   //!
    TBranch        *b__jetEta;   //!
    TBranch        *b__jetPhi;   //!
    TBranch        *b__jetPt;   //!
    TBranch        *b__jetFlavour;   //!
    TBranch        *b__jetE;   //!
    TBranch        *b__csv;   //!
    TBranch        *b__jetDeltaR;   //!
    TBranch        *b__clean;   //!
    TBranch        *b__jecUnc;   //!
    TBranch        *b__jetPtUp;   //!
    TBranch        *b__jetPtDown;   //!
    TBranch        *b__matchedjetPt;   //!
    TBranch        *b__matchedjetEta;   //!
    TBranch        *b__matchedjetPhi;   //!
    TBranch        *b__matchedjetE;   //!
    TBranch        *b__matchedjetM;   //!
    TBranch        *b__matchGjet;   //!
    TBranch        *b__btagSF;   //!
    TBranch        *b__weight;   //!
    TBranch        *b__LHEweight;   //!
    TBranch        *b__LHEweightID;   //!
    TBranch        *b__mgluino;   //!
    TBranch        *b__mchi0;   //!
    TBranch        *b__nMajorana;   //!
    TBranch        *b__passedMVA80;   //!
    TBranch        *b__passedMVA90;   //!
    TBranch        *b__findMatched;   //!
    TBranch        *b__gen_nL;   //!
    TBranch        *b__gen_lPt;   //!
    TBranch        *b__gen_lE;   //!
    TBranch        *b__gen_lEta;   //!
    TBranch        *b__gen_lPhi;   //!
    TBranch        *b__gen_lmompdg;   //!
    TBranch        *b__gen_charges;   //!
    TBranch        *b__gen_flavors;   //!
    TBranch        *b__gen_nNu;   //!
    TBranch        *b__gen_nuPt;   //!
    TBranch        *b__gen_nuE;   //!
    TBranch        *b__gen_nuEta;   //!
    TBranch        *b__gen_nuPhi;   //!
    TBranch        *b__gen_numompdg;   //!
    TBranch        *b__gen_nMajo;   //!
    TBranch        *b__gen_majoPt;   //!
    TBranch        *b__gen_majoE;   //!
    TBranch        *b__gen_majoEta;   //!
    TBranch        *b__gen_majoPhi;   //!
    TBranch        *b__gen_nW;   //!
    TBranch        *b__gen_wPt;   //!
    TBranch        *b__gen_wE;   //!
    TBranch        *b__gen_wEta;   //!
    TBranch        *b__gen_wPhi;   //!
    TBranch        *b__gen_wmompdg;   //!
    
    tree->SetBranchAddress("_leptonP4", &_leptonP4, &b__leptonP4);
    tree->SetBranchAddress("_gen_leptonP4", &_gen_leptonP4, &b__gen_leptonP4);
    tree->SetBranchAddress("_gen_nuP4", &_gen_nuP4, &b__gen_nuP4);
    tree->SetBranchAddress("_gen_majoP4", &_gen_majoP4, &b__gen_majoP4);
    tree->SetBranchAddress("_gen_wP4", &_gen_wP4, &b__gen_wP4);
    tree->SetBranchAddress("_eventNb", &_eventNb, &b__eventNb);
    tree->SetBranchAddress("_runNb", &_runNb, &b__runNb);
    tree->SetBranchAddress("_lumiBlock", &_lumiBlock, &b__lumiBlock);
    tree->SetBranchAddress("_nLeptons", &_nLeptons, &b__nLeptons);
    tree->SetBranchAddress("_lPt", _lPt, &b__lPt);
    tree->SetBranchAddress("_lEta", _lEta, &b__lEta);
    tree->SetBranchAddress("_lPhi", _lPhi, &b__lPhi);
    tree->SetBranchAddress("_lE", _lE, &b__lE);
    tree->SetBranchAddress("_lPtmc", _lPtmc, &b__lPtmc);
    tree->SetBranchAddress("_lEtamc", _lEtamc, &b__lEtamc);
    tree->SetBranchAddress("_lPhimc", _lPhimc, &b__lPhimc);
    tree->SetBranchAddress("_lEmc", _lEmc, &b__lEmc);
    tree->SetBranchAddress("_lpdgmc", _lpdgmc, &b__lpdgmc);
    tree->SetBranchAddress("_lchargemc", _lchargemc, &b__lchargemc);
    tree->SetBranchAddress("_nuPtmc", _nuPtmc, &b__nuPtmc);
    tree->SetBranchAddress("_nuEtamc", _nuEtamc, &b__nuEtamc);
    tree->SetBranchAddress("_nuPhimc", _nuPhimc, &b__nuPhimc);
    tree->SetBranchAddress("_nuEmc", _nuEmc, &b__nuEmc);
    tree->SetBranchAddress("_mtmc", _mtmc, &b__mtmc);
    tree->SetBranchAddress("_nZboson", &_nZboson, &b__nZboson);
    tree->SetBranchAddress("_nEle", &_nEle, &b__nEle);
    tree->SetBranchAddress("_nMu", &_nMu, &b__nMu);
    tree->SetBranchAddress("_nTau", &_nTau, &b__nTau);
    tree->SetBranchAddress("_flavors", _flavors, &b__flavors);
    tree->SetBranchAddress("_charges", _charges, &b__charges);
    tree->SetBranchAddress("_indeces", _indeces, &b__indeces);
    tree->SetBranchAddress("_isolation", _isolation, &b__isolation);
    tree->SetBranchAddress("_isolation_absolute", _isolation_absolute, &b__isolation_absolute);
    tree->SetBranchAddress("_miniisolation", _miniisolation, &b__miniisolation);
    tree->SetBranchAddress("_miniisolationCharged", _miniisolationCharged, &b__miniisolationCharged);
    tree->SetBranchAddress("_multiisolation", _multiisolation, &b__multiisolation);
    tree->SetBranchAddress("_ptrel", _ptrel, &b__ptrel);
    tree->SetBranchAddress("_ptratio", _ptratio, &b__ptratio);
    tree->SetBranchAddress("_muonSegmentComp", _muonSegmentComp, &b__muonSegmentComp);
    tree->SetBranchAddress("_mll", _mll, &b__mll);
    tree->SetBranchAddress("_origin", _origin, &b__origin);
    tree->SetBranchAddress("_originReduced", _originReduced, &b__originReduced);
    tree->SetBranchAddress("_isPromptFinalState", _isPromptFinalState, &b__isPromptFinalState);
    tree->SetBranchAddress("_fromHardProcessFinalState", _fromHardProcessFinalState, &b__fromHardProcessFinalState);
    tree->SetBranchAddress("_PVchi2", &_PVchi2, &b__PVchi2);
    tree->SetBranchAddress("_PVerr", _PVerr, &b__PVerr);
    tree->SetBranchAddress("_ipPV", _ipPV, &b__ipPV);
    tree->SetBranchAddress("_ipPVerr", _ipPVerr, &b__ipPVerr);
    tree->SetBranchAddress("_ipZPV", _ipZPV, &b__ipZPV);
    tree->SetBranchAddress("_ipZPVerr", _ipZPVerr, &b__ipZPVerr);
    tree->SetBranchAddress("_ipPVmc", _ipPVmc, &b__ipPVmc);
    tree->SetBranchAddress("_3dIP", _3dIP, &b__3dIP);
    tree->SetBranchAddress("_3dIPerr", _3dIPerr, &b__3dIPerr);
    tree->SetBranchAddress("_3dIPsig", _3dIPsig, &b__3dIPsig);
    tree->SetBranchAddress("_mt", _mt, &b__mt);
    tree->SetBranchAddress("_isloose", _isloose, &b__isloose);
    tree->SetBranchAddress("_istight", _istight, &b__istight);
    tree->SetBranchAddress("_ismedium", _ismedium, &b__ismedium);
    tree->SetBranchAddress("_istightID", _istightID, &b__istightID);
    tree->SetBranchAddress("_trigEmulator", _trigEmulator, &b__trigEmulator);
    tree->SetBranchAddress("_isotrigEmulator", _isotrigEmulator, &b__isotrigEmulator);
    tree->SetBranchAddress("_closeJetPtAll", _closeJetPtAll, &b__closeJetPtAll);
    tree->SetBranchAddress("_closeJetAngAll", _closeJetAngAll, &b__closeJetAngAll);
    tree->SetBranchAddress("_trackSelectionMultiplicity", _trackSelectionMultiplicity, &b__trackSelectionMultiplicity);
    tree->SetBranchAddress("_closeJetCSVAll", _closeJetCSVAll, &b__closeJetCSVAll);
    tree->SetBranchAddress("_chargeConst", _chargeConst, &b__chargeConst);
    tree->SetBranchAddress("_hitsNumber", _hitsNumber, &b__hitsNumber);
    tree->SetBranchAddress("_vtxFitConversion", _vtxFitConversion, &b__vtxFitConversion);
    tree->SetBranchAddress("_mvaValue", _mvaValue, &b__mvaValue);
    tree->SetBranchAddress("_decayModeFinding", _decayModeFinding, &b__decayModeFinding);
    tree->SetBranchAddress("_looseMVA_dR03", _looseMVA_dR03, &b__looseMVA_dR03);
    tree->SetBranchAddress("_mediumMVA_dR03", _mediumMVA_dR03, &b__mediumMVA_dR03);
    tree->SetBranchAddress("_vlooseMVAold", _vlooseMVAold, &b__vlooseMVAold);
    tree->SetBranchAddress("_looseMVAold", _looseMVAold, &b__looseMVAold);
    tree->SetBranchAddress("_mediumMVAold", _mediumMVAold, &b__mediumMVAold);
    tree->SetBranchAddress("_tightMVAold", _tightMVAold, &b__tightMVAold);
    tree->SetBranchAddress("_vtightMVAold", _vtightMVAold, &b__vtightMVAold);
    tree->SetBranchAddress("_decayModeFindingNewDMs", _decayModeFindingNewDMs, &b__decayModeFindingNewDMs);
    tree->SetBranchAddress("_vlooseMVAnew", _vlooseMVAnew, &b__vlooseMVAnew);
    tree->SetBranchAddress("_looseMVAnew", _looseMVAnew, &b__looseMVAnew);
    tree->SetBranchAddress("_mediumMVAnew", _mediumMVAnew, &b__mediumMVAnew);
    tree->SetBranchAddress("_tightMVAnew", _tightMVAnew, &b__tightMVAnew);
    tree->SetBranchAddress("_vtightMVAnew", _vtightMVAnew, &b__vtightMVAnew);
    tree->SetBranchAddress("_n_PV", &_n_PV, &b__n_PV);
    tree->SetBranchAddress("_n_MCTruth_PV", &_n_MCTruth_PV, &b__n_MCTruth_PV);
    tree->SetBranchAddress("_met", &_met, &b__met);
    tree->SetBranchAddress("_met_phi", &_met_phi, &b__met_phi);
    tree->SetBranchAddress("HT", &HT, &b_HT);
    tree->SetBranchAddress("_genmet", &_genmet, &b__genmet);
    tree->SetBranchAddress("_genmet_phi", &_genmet_phi, &b__genmet_phi);
    tree->SetBranchAddress("_genqpt", &_genqpt, &b__genqpt);
    tree->SetBranchAddress("_genqpt20", &_genqpt20, &b__genqpt20);
    tree->SetBranchAddress("_mompt", _mompt, &b__mompt);
    tree->SetBranchAddress("_momphi", _momphi, &b__momphi);
    tree->SetBranchAddress("_mometa", _mometa, &b__mometa);
    tree->SetBranchAddress("_mompdg", _mompdg, &b__mompdg);
    tree->SetBranchAddress("_n_bJets", &_n_bJets, &b__n_bJets);
    tree->SetBranchAddress("_n_Jets", &_n_Jets, &b__n_Jets);
    tree->SetBranchAddress("_bTagged", _bTagged, &b__bTagged);
    tree->SetBranchAddress("_jetEta", _jetEta, &b__jetEta);
    tree->SetBranchAddress("_jetPhi", _jetPhi, &b__jetPhi);
    tree->SetBranchAddress("_jetPt", _jetPt, &b__jetPt);
    tree->SetBranchAddress("_jetFlavour", _jetFlavour, &b__jetFlavour);
    tree->SetBranchAddress("_jetE", _jetE, &b__jetE);
    tree->SetBranchAddress("_csv", _csv, &b__csv);
    tree->SetBranchAddress("_jetDeltaR", _jetDeltaR, &b__jetDeltaR);
    tree->SetBranchAddress("_clean", _clean, &b__clean);
    tree->SetBranchAddress("_jecUnc", _jecUnc, &b__jecUnc);
    tree->SetBranchAddress("_jetPtUp", _jetPtUp, &b__jetPtUp);
    tree->SetBranchAddress("_jetPtDown", _jetPtDown, &b__jetPtDown);
    tree->SetBranchAddress("_matchedjetPt", _matchedjetPt, &b__matchedjetPt);
    tree->SetBranchAddress("_matchedjetEta", _matchedjetEta, &b__matchedjetEta);
    tree->SetBranchAddress("_matchedjetPhi", _matchedjetPhi, &b__matchedjetPhi);
    tree->SetBranchAddress("_matchedjetE", _matchedjetE, &b__matchedjetE);
    tree->SetBranchAddress("_matchedjetM", _matchedjetM, &b__matchedjetM);
    tree->SetBranchAddress("_matchGjet", _matchGjet, &b__matchGjet);
    tree->SetBranchAddress("_btagSF", _btagSF, &b__btagSF);
    tree->SetBranchAddress("_weight", &_weight, &b__weight);
    tree->SetBranchAddress("_LHEweight", _LHEweight, &b__LHEweight);
    tree->SetBranchAddress("_LHEweightID", _LHEweightID, &b__LHEweightID);
    tree->SetBranchAddress("_mgluino", &_mgluino, &b__mgluino);
    tree->SetBranchAddress("_mchi0", &_mchi0, &b__mchi0);
    tree->SetBranchAddress("_nMajorana", &_nMajorana, &b__nMajorana);
    tree->SetBranchAddress("_passedMVA80", &_passedMVA80, &b__passedMVA80);
    tree->SetBranchAddress("_passedMVA90", &_passedMVA90, &b__passedMVA90);
    tree->SetBranchAddress("_findMatched", &_findMatched, &b__findMatched);
    tree->SetBranchAddress("_gen_nL", &_gen_nL, &b__gen_nL);
    tree->SetBranchAddress("_gen_lPt", _gen_lPt, &b__gen_lPt);
    tree->SetBranchAddress("_gen_lE", _gen_lE, &b__gen_lE);
    tree->SetBranchAddress("_gen_lEta", _gen_lEta, &b__gen_lEta);
    tree->SetBranchAddress("_gen_lPhi", _gen_lPhi, &b__gen_lPhi);
    tree->SetBranchAddress("_gen_lmompdg", _gen_lmompdg, &b__gen_lmompdg);
    tree->SetBranchAddress("_gen_charges", _gen_charges, &b__gen_charges);
    tree->SetBranchAddress("_gen_flavors", _gen_flavors, &b__gen_flavors);
    tree->SetBranchAddress("_gen_nNu", &_gen_nNu, &b__gen_nNu);
    tree->SetBranchAddress("_gen_nuPt", _gen_nuPt, &b__gen_nuPt);
    tree->SetBranchAddress("_gen_nuE", _gen_nuE, &b__gen_nuE);
    tree->SetBranchAddress("_gen_nuEta", _gen_nuEta, &b__gen_nuEta);
    tree->SetBranchAddress("_gen_nuPhi", _gen_nuPhi, &b__gen_nuPhi);
    tree->SetBranchAddress("_gen_numompdg", _gen_numompdg, &b__gen_numompdg);
    tree->SetBranchAddress("_gen_nMajo", &_gen_nMajo, &b__gen_nMajo);
    //tree->SetBranchAddress("_gen_majoPt", _gen_majoPt, &b__gen_majoPt);
    //tree->SetBranchAddress("_gen_majoE", _gen_majoE, &b__gen_majoE);
    //tree->SetBranchAddress("_gen_majoEta", _gen_majoEta, &b__gen_majoEta);
    //tree->SetBranchAddress("_gen_majoPhi", _gen_majoPhi, &b__gen_majoPhi);
    tree->SetBranchAddress("_gen_nW", &_gen_nW, &b__gen_nW);
    tree->SetBranchAddress("_gen_wPt", _gen_wPt, &b__gen_wPt);
    tree->SetBranchAddress("_gen_wE", _gen_wE, &b__gen_wE);
    tree->SetBranchAddress("_gen_wEta", _gen_wEta, &b__gen_wEta);
    tree->SetBranchAddress("_gen_wPhi", _gen_wPhi, &b__gen_wPhi);
    tree->SetBranchAddress("_gen_wmompdg", _gen_wmompdg, &b__gen_wmompdg);
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
  int index_pt_lead=0;
  double pt_lead=0;
  double max_pt=0;
  int index_pt_sublead=0;
  double pt_sublead=0;
  double max1_pt=0;
    
  int n_ossf=0;
  int n_n_ossf=0;
    
    
  double denominatore_ossf=0;
  double denominatore_n_ossf=0;
  double denominatore_eee_ossf=0;
  double denominatore_eee_n_ossf=0;
  double denominatore_eem_ossf=0;
  double denominatore_eem_n_ossf=0;
  double denominatore_emm_ossf=0;
  double denominatore_emm_n_ossf=0;
  double denominatore_mmm_ossf=0;
  double denominatore_mmm_n_ossf=0;
    
  const int bin_num=100;
  double numerator_ossf[bin_num];
  double numerator_n_ossf[bin_num];
  double numerator_min_ossf[bin_num];
  double numerator_min_n_ossf[bin_num];
  double numerator_eee_ossf[bin_num];
  double numerator_eee_n_ossf[bin_num];
  double numerator_eee_min_ossf[bin_num];
  double numerator_eee_min_n_ossf[bin_num];
  double numerator_emm_ossf[bin_num];
  double numerator_emm_n_ossf[bin_num];
  double numerator_emm_min_ossf[bin_num];
  double numerator_emm_min_n_ossf[bin_num];
  double numerator_eem_ossf[bin_num];
  double numerator_eem_n_ossf[bin_num];
  double numerator_eem_min_ossf[bin_num];
  double numerator_eem_min_n_ossf[bin_num];
  double numerator_mmm_ossf[bin_num];
  double numerator_mmm_n_ossf[bin_num];
  double numerator_mmm_min_ossf[bin_num];
  double numerator_mmm_min_n_ossf[bin_num];
    
  for (int i =0; i<bin_num; i++){
    numerator_ossf[i]=0;
    numerator_n_ossf[i]=0;
    numerator_min_ossf[i]=0;
    numerator_min_n_ossf[i]=0;
    numerator_eee_ossf[i]=0;;
    numerator_eee_n_ossf[i]=0;;
    numerator_eee_min_ossf[i]=0;;
    numerator_eee_min_n_ossf[i]=0;;
    numerator_emm_ossf[i]=0;;
    numerator_emm_n_ossf[i]=0;;
    numerator_emm_min_ossf[i]=0;;
    numerator_emm_min_n_ossf[i]=0;;
    numerator_eem_ossf[i]=0;;
    numerator_eem_n_ossf[i]=0;;
    numerator_eem_min_ossf[i]=0;;
    numerator_eem_min_n_ossf[i]=0;;
    numerator_mmm_ossf[i]=0;;
    numerator_mmm_n_ossf[i]=0;;
    numerator_mmm_min_ossf[i]=0;;
    numerator_mmm_min_n_ossf[i]=0;;
  }
    
    
  int event_clas=-1;
  // 1 eee
  // 2 emumu
  // 3 eemu
  // 4 eetau
  // 5 e tautau
    
  int index_ossf=0;
  int electron_mva=0;
  int muon_tigh=0;
  int good_event=0;
  int iso_cut=0;
  int numero_jet=0;
  int	test_ip = 0;

  double number_event_tot=0;
  double number_event_ossf=0;
  double number_event_n_ossf=0;

    

  cout<<"new tree  analisi signal"<<endl;
  for(Int_t et=0;et< tree->GetEntries();et++){
        
  //cout<<"=======================    new event"<<endl;
      if (et % 100000 == 0 ) cout<<et<< ")   100000 loop   "<< FileNameTree_in.c_str() <<endl;
      //if (et > 10000) continue;
        tree->GetEvent(et);
        
        
        //===================== cleaning electron ======================
        //-================ jet cleaning =============
        Int_t numero_leptoni=0;
        Int_t numero_leptoni_puliti=0;
        TLorentzVector muone;
        TLorentzVector elettrone;
        if (_nLeptons < 3) continue;
        
         for(int i =0; i <_nLeptons; i++){
            numero_leptoni++;
            if (_flavors[i] == 0 ){
                elettrone.SetPtEtaPhiE(0,0,0,0);
                elettrone.SetPtEtaPhiE(_lPt[i], _lEta[i], _lPhi[i], _lE[i]);
                for(int j =0; j <_nLeptons; j++){
                    if (_flavors[j] == 1 ){
                        muone.SetPtEtaPhiE(0,0,0,0);
                        muone.SetPtEtaPhiE(_lPt[j], _lEta[j], _lPhi[j], _lE[j]);
                        //histo_ossf_kin_rec_l1[3]->Fill(elettrone.DeltaR(muone));
                        if (elettrone.DeltaR(muone) < 0.05) numero_leptoni_puliti++;
                    }//end muon
                }//end loop j
            }// end electron
        }//end loop i
        
        numero_leptoni= numero_leptoni - numero_leptoni_puliti;
        //cout<<"n "<<numero_leptoni<<endl;
        if(numero_leptoni != 3) continue;

	
        

        
        //*****************************************************************
        //if (_nLeptons != 3) continue;
	electron_mva=0;
        muon_tigh=0;
	test_ip=0;
	iso_cut=0;

	for(int i = 0; i < _nLeptons; ++i){
	  if(iso_cut!=1){
	    if(!( _isolation_absolute[i]/_lPt[i] < 0.1))iso_cut=1;
	  }
	  if(test_ip!=1){
	    if(TMath::Abs(_ipPV[i]) > 0.05 || TMath::Abs(_ipZPV[i]) > 0.1  || _3dIPsig [i] > 4) test_ip=1;
	  }
	  if (_flavors[i] == 0 && electron_mva!=1) {
	    if (! _passedMVA90[i]  )  electron_mva=1;
	  }//end electron
	  if (_flavors[i] == 1 && muon_tigh !=1) {
	    if (!_ismedium[i])   muon_tigh=1;
	  }//end muon
                
	}//end for

	
	if ( test_ip == 1) continue;
	if ( electron_mva == 1) continue;
	if ( muon_tigh == 1) continue;
	if ( iso_cut == 1) continue;  
	// -------------->           


        /*
        // ==================== Matched MC ============================
        const int nL = _nLeptons;
        const int gen_nL = _gen_nL;
        TLorentzVector Lep[20];
        TLorentzVector GenLep[20];
        int match_matrix[2][3];
        for (int i= 0; i<2 ; i++){
            for (int j= 0; j<3 ; j++){
                match_matrix[i][j]=0;
            }
        }
        for(int i = 0; i < _nLeptons; ++i){
            Lep[i].SetPtEtaPhiE(_lPt[i], _lEta[i], _lPhi[i], _lE[i]);
        }
        for(int i = 0; i < _gen_nL; ++i){
            GenLep[i].SetPtEtaPhiE(_gen_lPt[i], _gen_lEta[i], _gen_lPhi[i], _gen_lE[i]);
        }
        int match[nL];
        for(int i = 0; i < _nLeptons; ++i){
            match[i] = -1;
        }
        std::vector <int> UsedGen;
        std::vector <int> UsedReco;
        for(int n = 0; n < _nLeptons; ++n){
            double MinDeltaR = 999;
            int matched = -1;
            for(int i = 0; i < _nLeptons; ++i){
                if(_lPt[i] == 0) continue;
                bool recoused = false;
                for(int j = 0; j < UsedReco.size(); ++j){
                    if(i == UsedReco[j]){
                        recoused = true;
                        break;
                    }
                }
                if(recoused) continue;
                for(int j = 0; j < _gen_nL; ++j){
                    if(_gen_lPt[j] == 0) continue;
                    if(_charges[i] != _gen_charges[j] || _flavors[i] != _gen_flavors[j]) continue;
                    bool genused = false;
                    for(int k = 0; k < UsedGen.size(); ++k){
                        if(j == UsedGen[k]){
                            genused = true;
                            break;
                        }
                    }
                    if(genused) continue;
                    if(Lep[i].DeltaR(GenLep[j]) < MinDeltaR){
                        matched = i;
                        match[i] = j;
                        MinDeltaR = Lep[i].DeltaR(GenLep[j]);
                        //cout<<"gen_flavor:  "<<_gen_flavors[j]<<endl;
                    }
                }
            }
            if (matched  == -1) continue;
            if (match[matched]  == -1) continue;
            UsedReco.push_back(matched);
            UsedGen.push_back(match[matched]);
        }
        for(int i =0; i<UsedReco.size(); i++){
            match_matrix[0][i] = UsedReco.at(i);
        }
        for(int i =0; i<UsedGen.size(); i++){
            match_matrix[1][i] = UsedGen.at(i);
        }
        UsedGen.clear();
        UsedReco.clear();
	*/
       //================= pT leading ==========================
        pt_lead=0;
        index_pt_lead=100;
        max_pt=0;
        //cout<<"===================="<<endl;
        for (int i = 0 ; i < _nLeptons ; i++){
            // if (_flavors[i] !=0) continue;
            pt_lead = _lPt[i];
            //cout<<"1} "<<pt_lead<<"  vs  "<< max_pt<<endl;
            if(max_pt < pt_lead) { //
                max_pt= pt_lead;
                index_pt_lead= i;
                //cout<<"''''''  "<<max_pt<<"  "<<index_pt_lead<<endl;
            }// end if
        }
        if (max_pt < 15 ) continue;
        //================= pT sub-leading ==========================
        pt_sublead=0;
        index_pt_sublead=100;
        max1_pt=0;
        //cout<<"===================="<<endl;
        for (int i = 0 ; i < _nLeptons ; i++){
            if (i == index_pt_lead) continue;
            pt_sublead = _lPt[i];
            //cout<<"2} "<<pt_sublead<<"  vs  "<< max1_pt<<endl;
            if(max1_pt < pt_sublead) { //
                max1_pt= pt_sublead;
                index_pt_sublead= i;
                //cout<<"''''''  "<<max1_pt<<"  "<<index_pt_sublead<<endl;
            }// end if
        }
	if (max1_pt < 10 ) continue;
        //========== *********** GEN LEVEL *********** ============
        TLorentzVector lepton_gen[3];
        TLorentzVector lepton_reco[3];
        TLorentzVector neutrino_gen[1];
        int i_lepton1=0;
        int i_lepton2=0;
        int i_lepton3=0;
        int c_lepton1=0;
        int c_lepton2=0;
        int c_lepton3=0;
        int f_lepton1=0;
        int f_lepton2=0;
        int f_lepton3=0;
        int i_lepton1_gen=0;
        int i_lepton2_gen=0;
        int i_lepton3_gen=0;
        int in_lepton=0;
        c_lepton1=0;
        c_lepton2=0;
        c_lepton3=0;
        f_lepton1=0;
        f_lepton2=0;
        f_lepton3=0;
        //cout<<"++++++++++++++++++"<<endl;
        for (int i = 0 ; i < _nLeptons ; i++){ // loop over leptons
            
	  //cout<<i<<")  "<<_lPt[i]<<endl;
            //cout<<"lead "<<index_pt_lead<<endl;
            
            
        
            //out<<"flav: "<<_flavors[i]<<" "<<_gen_flavors[match[i]]<<endl;
            /////////////////////////////////////////// lepton1
            if (i == index_pt_lead) {// lepton1
                i_lepton1=i;
                c_lepton1=_charges[i];
                f_lepton1=_flavors[i];
		lepton_reco[0]= *(TLorentzVector *)_leptonP4->At(i_lepton1);
		lepton_gen[0]= *(TLorentzVector *)_leptonP4->At(i_lepton1);
               
            }//origin =0
            
            else if (i == index_pt_sublead) {// lepton2
                i_lepton2=i;
                c_lepton2=_charges[i];
                f_lepton2=_flavors[i];
		lepton_reco[1]= *(TLorentzVector *)_leptonP4->At(i_lepton2);
		lepton_gen[1]= *(TLorentzVector *)_leptonP4->At(i_lepton2);
               
            }
            /////////////////////////////////////////// lepton2
            else {
                i_lepton3=i;
                c_lepton3=_charges[i];
                f_lepton3=_flavors[i];
		lepton_reco[2]= *(TLorentzVector *)_leptonP4->At(i_lepton3);
		lepton_gen[2]= *(TLorentzVector *)_leptonP4->At(i_lepton3);
               
            }
        }//loop lepton
        // invariant masses
        
	int veto_bjets=0;
	veto_bjets=0;
	TLorentzVector jetb_vec={0,0,0,0};
        for(int i =0; i <_n_Jets; i++){
	  jetb_vec.SetPtEtaPhiE(0,0,0,0);
	  jetb_vec.SetPtEtaPhiE(_jetPt[i],_jetEta[i],_jetPhi[i], _jetE[i]);
	  if (lepton_reco[0].DeltaR( jetb_vec )<0.4)continue;
	  if (lepton_reco[1].DeltaR( jetb_vec )<0.4)continue;
	  if (lepton_reco[2].DeltaR( jetb_vec )<0.4)continue;
            if (_csv[i] > 0.460) veto_bjets++;
            //cout<<"   "<<_csv[i]<<endl;
	  }
	  //if (veto_bjets !=0) cout<<veto_bjets<<endl;
	if (veto_bjets !=0) continue;



        
        
        //==================== event pT claasification =====================
        if (lepton_reco[1].Pt() < 10 ) continue;
        if ( f_lepton3 == 0 && lepton_reco[2].Pt() < 10 ) continue;
        
        //if (lepton_reco[0].Pt()< 30) continue;
        //if (lepton_reco[0].Pt()> 30) continue;
        
        
	  //********************** scalar factor ***************
        double w_factor=0;
        w_factor= (_weight*xsection*luminosity)/(h_Counter->GetBinContent(1));
        if (et % 10000 == 0 ) {
            cout<<"factor: "<<w_factor<< endl;
            cout<<"h_counter: "<<h_Counter->GetBinContent(1)<< endl;
        }

      
    //================== event classification ========================
    event_clas=-1;
    if (f_lepton2 == 0 ||  f_lepton3  == 0 ||  f_lepton1== 0) {
      if ((f_lepton2 + f_lepton3 + f_lepton1) == 0 ) event_clas = 10; //e e e
      if ((f_lepton2 + f_lepton3 + f_lepton1) == 1 ) event_clas = 30; //e e mu
      if ((f_lepton2 + f_lepton3 + f_lepton1) == 4 ) event_clas = 50; //e tau tau
      if ((f_lepton2 + f_lepton3 + f_lepton1) == 2 ) {
	if (f_lepton2 == 2 ||  f_lepton3  == 2 ||  f_lepton1== 2) event_clas=40; // e e tau
	if (f_lepton2 == 1 ||  f_lepton3  == 1 ||  f_lepton1== 1) event_clas=20; // e mu mu
      }
    }// at least an electron
    else if (f_lepton2 == 1 &&  f_lepton3  == 1 &&  f_lepton1 == 1) {
      event_clas = 60;
    }
    else {
      event_clas =-1;
    }
        
    TLorentzVector pair1_gen;
    TLorentzVector pair2_gen;
    TLorentzVector pair1_rec;
    TLorentzVector pair2_rec;
        
        
        
    if (event_clas  == 30){
      if ((f_lepton1 == 0 && f_lepton2 == 0 && f_lepton3 == 1) ) { // e e mu
	pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	pair2_rec .SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	pair1_gen.SetPtEtaPhiE( lepton_gen[0].Pt(),  lepton_gen[0].Eta(), lepton_gen[0].Phi(), lepton_gen[0].E());
	pair2_gen .SetPtEtaPhiE( lepton_gen[1].Pt(),  lepton_gen[1].Eta(), lepton_gen[1].Phi(), lepton_gen[1].E());
	if ((c_lepton1 + c_lepton2) == 0) event_clas = 3;
                
      }
      if (f_lepton1 == 0 && f_lepton2 == 1 && f_lepton3 == 0) { // e mu e
	pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	pair1_gen.SetPtEtaPhiE( lepton_gen[0].Pt(),  lepton_gen[0].Eta(), lepton_gen[0].Phi(), lepton_gen[0].E());
	pair2_gen .SetPtEtaPhiE( lepton_gen[2].Pt(),  lepton_gen[2].Eta(), lepton_gen[2].Phi(), lepton_gen[2].E());
	if ((c_lepton1 + c_lepton3) == 0) event_clas = 3;
      }
      if (f_lepton1 == 1 && f_lepton2 == 0 && f_lepton3 == 0 ) { // mu e e
	pair1_rec.SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	pair1_gen.SetPtEtaPhiE( lepton_gen[1].Pt(),  lepton_gen[1].Eta(), lepton_gen[1].Phi(), lepton_gen[1].E());
	pair2_gen .SetPtEtaPhiE( lepton_gen[2].Pt(),  lepton_gen[2].Eta(), lepton_gen[2].Phi(), lepton_gen[2].E());
	if ((c_lepton2 + c_lepton3) == 0) event_clas = 3;
      }
    }
    if (event_clas  == 40){
      if ((f_lepton1 == 0 && f_lepton2 == 0 && f_lepton3 == 2) ) { // e e mu
	pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	pair2_rec .SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	pair1_gen.SetPtEtaPhiE( lepton_gen[0].Pt(),  lepton_gen[0].Eta(), lepton_gen[0].Phi(), lepton_gen[0].E());
	pair2_gen .SetPtEtaPhiE( lepton_gen[1].Pt(),  lepton_gen[1].Eta(), lepton_gen[1].Phi(), lepton_gen[1].E());
	if ((c_lepton1 + c_lepton2) == 0) event_clas = 4;
      }
      if (f_lepton1 == 0 && f_lepton2 == 2 && f_lepton3 == 0 ) { // e mu e
	pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	pair1_gen.SetPtEtaPhiE( lepton_gen[0].Pt(),  lepton_gen[0].Eta(), lepton_gen[0].Phi(), lepton_gen[0].E());
	pair2_gen .SetPtEtaPhiE( lepton_gen[2].Pt(),  lepton_gen[2].Eta(), lepton_gen[2].Phi(), lepton_gen[2].E());
	if ((c_lepton1 + c_lepton3) == 0) event_clas = 4;
      }
      if (f_lepton1 == 2 && f_lepton2 == 0 && f_lepton3 == 0) { // mu e e
	pair1_rec.SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	pair1_gen.SetPtEtaPhiE( lepton_gen[1].Pt(),  lepton_gen[1].Eta(), lepton_gen[1].Phi(), lepton_gen[1].E());
	pair2_gen .SetPtEtaPhiE( lepton_gen[2].Pt(),  lepton_gen[2].Eta(), lepton_gen[2].Phi(), lepton_gen[2].E());
	if  ((c_lepton2 + c_lepton3) == 0)event_clas = 4;
      }
    }
    if (event_clas  == 50){
      if ((f_lepton1 == 2 && f_lepton2 == 2 && f_lepton3 == 0) ) { // e e mu
	pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	pair1_gen.SetPtEtaPhiE( lepton_gen[0].Pt(),  lepton_gen[0].Eta(), lepton_gen[0].Phi(), lepton_gen[0].E());
	pair2_gen .SetPtEtaPhiE( lepton_gen[1].Pt(),  lepton_gen[1].Eta(), lepton_gen[1].Phi(), lepton_gen[1].E());
	pair2_rec .SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	if ((c_lepton1 + c_lepton2) == 0) event_clas = 5;
      }
      if (f_lepton1 == 2 && f_lepton2 == 0 && f_lepton3 == 2 ) { // e mu e
	pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	pair1_gen.SetPtEtaPhiE( lepton_gen[0].Pt(),  lepton_gen[0].Eta(), lepton_gen[0].Phi(), lepton_gen[0].E());
	pair2_gen .SetPtEtaPhiE( lepton_gen[2].Pt(),  lepton_gen[2].Eta(), lepton_gen[2].Phi(), lepton_gen[2].E());
	if ((c_lepton1 + c_lepton3) == 0) event_clas = 5;
      }
      if (f_lepton1 == 0 && f_lepton2 == 2 && f_lepton3 == 2 ) { // mu e e
	pair1_rec.SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	pair1_gen.SetPtEtaPhiE( lepton_gen[1].Pt(),  lepton_gen[1].Eta(), lepton_gen[1].Phi(), lepton_gen[1].E());
	pair2_gen .SetPtEtaPhiE( lepton_gen[2].Pt(),  lepton_gen[2].Eta(), lepton_gen[2].Phi(), lepton_gen[2].E());
	if  ((c_lepton2 + c_lepton3) == 0)event_clas = 5;
      }
    }
    if (event_clas  == 20){
      if ((f_lepton1 == 1 && f_lepton2 == 1 && f_lepton3 == 0) ) { // e e mu
	pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	pair2_rec .SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	pair1_gen.SetPtEtaPhiE( lepton_gen[0].Pt(),  lepton_gen[0].Eta(), lepton_gen[0].Phi(), lepton_gen[0].E());
	pair2_gen .SetPtEtaPhiE( lepton_gen[1].Pt(),  lepton_gen[1].Eta(), lepton_gen[1].Phi(), lepton_gen[1].E());
	if ((c_lepton1 + c_lepton2) == 0) event_clas = 2;
      }
      if (f_lepton1 == 1 && f_lepton2 == 0 && f_lepton3 == 1 ) { // e mu e
	pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	pair1_gen.SetPtEtaPhiE( lepton_gen[0].Pt(),  lepton_gen[0].Eta(), lepton_gen[0].Phi(), lepton_gen[0].E());
	pair2_gen .SetPtEtaPhiE( lepton_gen[2].Pt(),  lepton_gen[2].Eta(), lepton_gen[2].Phi(), lepton_gen[2].E());
	if ((c_lepton1 + c_lepton3) == 0) event_clas = 2;
      }
      if (f_lepton1 == 0 && f_lepton2 == 1 && f_lepton3 == 1 ) { // mu e e
	pair1_rec.SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	pair1_gen.SetPtEtaPhiE( lepton_gen[1].Pt(),  lepton_gen[1].Eta(), lepton_gen[1].Phi(), lepton_gen[1].E());
	pair2_gen .SetPtEtaPhiE( lepton_gen[2].Pt(),  lepton_gen[2].Eta(), lepton_gen[2].Phi(), lepton_gen[2].E());
	if  ((c_lepton2 + c_lepton3) == 0)event_clas = 2;
      }
    }
    double i_m[3]={0,0,0};
    double mass_inv=0;
    int index_inv=100;
    double min_mass=999;
        
    if (event_clas  == 10 ) {
      if ((c_lepton1 + c_lepton2 + c_lepton3) == 1 || (c_lepton1 + c_lepton2 + c_lepton3) == -1) {
	event_clas =1;
	if ((c_lepton1 + c_lepton2) == 0) i_m[0]= TMath:: Abs((lepton_reco[0] + lepton_reco[1]).Mag() - 91.1876);
	if ((c_lepton1 + c_lepton3) == 0) i_m[1]= TMath:: Abs((lepton_reco[0] + lepton_reco[2]).Mag() - 91.1876);
	if ((c_lepton2 + c_lepton3) == 0) i_m[2]= TMath:: Abs((lepton_reco[1] + lepton_reco[2]).Mag() - 91.1876);
	for (int i =0; i < 3; i++){
	  mass_inv = i_m[i];
	  if (min_mass > mass_inv ){
	    min_mass = mass_inv;
	    index_inv = i;
	  }
	}
	if (index_inv == 0) {
	  pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	  pair1_gen.SetPtEtaPhiE( lepton_gen[0].Pt(),  lepton_gen[0].Eta(), lepton_gen[0].Phi(), lepton_gen[0].E());
	  pair2_gen .SetPtEtaPhiE( lepton_gen[1].Pt(),  lepton_gen[1].Eta(), lepton_gen[1].Phi(), lepton_gen[1].E());
	}
	if (index_inv == 1) {
	  pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	  pair1_gen.SetPtEtaPhiE( lepton_gen[0].Pt(),  lepton_gen[0].Eta(), lepton_gen[0].Phi(), lepton_gen[0].E());
	  pair2_gen .SetPtEtaPhiE( lepton_gen[2].Pt(),  lepton_gen[2].Eta(), lepton_gen[2].Phi(), lepton_gen[2].E());
	}
	if (index_inv == 2) {
	  pair1_rec.SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	  pair1_gen.SetPtEtaPhiE( lepton_gen[1].Pt(),  lepton_gen[1].Eta(), lepton_gen[1].Phi(), lepton_gen[1].E());
	  pair2_gen .SetPtEtaPhiE( lepton_gen[2].Pt(),  lepton_gen[2].Eta(), lepton_gen[2].Phi(), lepton_gen[2].E());
	}
      }
    }
        
        
    double i_mmu[3]={0,0,0};
    double mass_inv_mu=0;
    int index_inv_mu=100;
    double min_mass_mu=999;
        
    if (event_clas  == 60 ) {
      if ((c_lepton1 + c_lepton2 + c_lepton3) == 1 || (c_lepton1 + c_lepton2 + c_lepton3) == -1) {
	event_clas =6;
	if ((c_lepton1 + c_lepton2) == 0) i_mmu[0]= TMath:: Abs((lepton_reco[0] + lepton_reco[1]).Mag() - 91.1876);
	if ((c_lepton1 + c_lepton3) == 0) i_mmu[1]= TMath:: Abs((lepton_reco[0] + lepton_reco[2]).Mag() - 91.1876);
	if ((c_lepton2 + c_lepton3) == 0) i_mmu[2]= TMath:: Abs((lepton_reco[1] + lepton_reco[2]).Mag() - 91.1876);
	for (int i =0; i < 3; i++){
	  mass_inv_mu = i_mmu[i];
	  if (min_mass_mu > mass_inv_mu ){
	    min_mass_mu = mass_inv_mu;
	    index_inv_mu = i;
	  }
	}
	if (index_inv_mu == 0) {
	  pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	  pair1_gen.SetPtEtaPhiE( lepton_gen[0].Pt(),  lepton_gen[0].Eta(), lepton_gen[0].Phi(), lepton_gen[0].E());
	  pair2_gen .SetPtEtaPhiE( lepton_gen[1].Pt(),  lepton_gen[1].Eta(), lepton_gen[1].Phi(), lepton_gen[1].E());
	}
	if (index_inv_mu == 1) {
	  pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	  pair1_gen.SetPtEtaPhiE( lepton_gen[0].Pt(),  lepton_gen[0].Eta(), lepton_gen[0].Phi(), lepton_gen[0].E());
	  pair2_gen .SetPtEtaPhiE( lepton_gen[2].Pt(),  lepton_gen[2].Eta(), lepton_gen[2].Phi(), lepton_gen[2].E());
	}
	if (index_inv_mu == 2) {
	  pair1_rec.SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	  pair1_gen.SetPtEtaPhiE( lepton_gen[1].Pt(),  lepton_gen[1].Eta(), lepton_gen[1].Phi(), lepton_gen[1].E());
	  pair2_gen .SetPtEtaPhiE( lepton_gen[2].Pt(),  lepton_gen[2].Eta(), lepton_gen[2].Phi(), lepton_gen[2].E());
	}
      }
    }
        
        
    //cout<< "classe: "<< event_clas<< "  --> pt: "<< lepton_reco[0].Pt()<<","<<lepton_reco[1].Pt()<<","<<lepton_reco[2].Pt()<< " flavour: "<<f_lepton1<<"."<<f_lepton2<<"."<<f_lepton3<<"  charge:  "<<c_lepton1<<"."<<c_lepton2<<"."<<c_lepton3<<endl;
        
    // ============================ OSSF =======================
    index_ossf=0;
    if ((c_lepton2 + c_lepton3) == 0){
      if (f_lepton2 ==  f_lepton3 ) index_ossf =1;
    }
    //if (index_ossf == 0) continue;
        
    TLorentzVector sum_3l_gen;
    sum_3l_gen.SetPtEtaPhiE(0,0,0,0);
    sum_3l_gen= (lepton_gen[0]+ lepton_gen[1]+lepton_gen[2] );
    TLorentzVector sum_3l_rec;
    sum_3l_rec.SetPtEtaPhiE(0,0,0,0);
    sum_3l_rec= (lepton_reco[0]+ lepton_reco[1]+lepton_reco[2] );
    TLorentzVector sum_2l_gen;
    sum_2l_gen.SetPtEtaPhiE(0,0,0,0);
    sum_2l_gen= (lepton_gen[1]+lepton_gen[2] );
    TLorentzVector sum_2l_rec;
    sum_2l_rec.SetPtEtaPhiE(0,0,0,0);
    sum_2l_rec= (lepton_reco[1]+lepton_reco[2]  );
    TLorentzVector sum_2l_gen_pair;
    sum_2l_gen_pair.SetPtEtaPhiE(0,0,0,0);
    sum_2l_gen_pair= (pair1_gen+pair2_gen );
    TLorentzVector sum_2l_rec_pair;
    sum_2l_rec_pair.SetPtEtaPhiE(0,0,0,0);
    sum_2l_rec_pair= (pair1_rec+pair2_rec );
        
        
    // met and mT
    TLorentzVector lepton_transv[2];
    TLorentzVector lepton_transv_gen[2];
    TLorentzVector METvec;
    TLorentzVector METvec_gen;
    double m_T=0;
    double m_T_gen=0;
        
    lepton_transv[0].SetPtEtaPhiE(lepton_reco[1].Pt(),0, lepton_reco[1].Phi(), lepton_reco[1].Pt());
    lepton_transv[1].SetPtEtaPhiE(lepton_reco[2].Pt(),0, lepton_reco[2].Phi(), lepton_reco[2].Pt());
    lepton_transv_gen[0].SetPtEtaPhiE(lepton_gen[1].Pt(),0, lepton_gen[1].Phi(), lepton_gen[1].Pt());
    lepton_transv_gen[1].SetPtEtaPhiE(lepton_gen[2].Pt(),0, lepton_gen[2].Phi(), lepton_gen[2].Pt());
    METvec.SetPtEtaPhiE(_met, 0, _met_phi,_met);
    METvec_gen.SetPtEtaPhiE(_genmet, 0, _genmet_phi,_genmet);
        
    m_T= (lepton_transv[0]+lepton_transv[1] + METvec).Mag();
    m_T_gen= (lepton_transv_gen[0]+lepton_transv_gen[1] + METvec_gen).Mag();
        
        
       
        
        
    //========================== B VETO ========================
    if (veto_bjets != 0) continue;
      if (event_clas == -1) continue;
      
      
      
      // if ( lepton_reco[0].Pt() > 50) continue;
      //if (TMath::Abs(sum_2l_rec.M() - 91.1876) < 10) continue;
      // if (TMath::Abs(sum_2l_rec_pair.M() - 91.1876) < 10) continue;
      //if ((TMath::Abs(sum_3l_rec.M() - 91.1876) < 10) || sum_3l_rec.M() < 30) continue;
      
      
      
    if (event_clas == 1 ||event_clas == 2 ||event_clas == 3 ||event_clas == 4 || event_clas == 5 || event_clas ==6) number_event_ossf= number_event_ossf + 1*w_factor;
    if (event_clas == 10 ||event_clas == 20 ||event_clas == 30 ||event_clas == 40 || event_clas == 50 || event_clas ==60) number_event_n_ossf= number_event_n_ossf+ 1*w_factor;
	
        
        
    //-================ jet cleaning =============
    TLorentzVector jet_vec={0,0,0,0};
    for(int i =0; i <_n_Jets; i++){
      jet_vec.SetPtEtaPhiE(0,0,0,0);
      jet_vec.SetPtEtaPhiE(_jetPt[i],_jetEta[i],_jetPhi[i], _jetE[i]);
      if (lepton_reco[0].DeltaR( jet_vec )<0.4)continue;
      if (lepton_reco[1].DeltaR( jet_vec )<0.4)continue;
      if (lepton_reco[2].DeltaR( jet_vec )<0.4)continue;
      numero_jet++;
            
      if (event_clas == 1 ||event_clas == 2 ||event_clas == 3 ||event_clas == 4 || event_clas == 5 || event_clas ==6){
	histo_ossf_rec[7]-> Fill(_jetPt[i],w_factor);
	histo_ossf_rec[8]-> Fill(_jetEta[i],w_factor);
	histo_ossf_rec[9]-> Fill(_jetPhi[i],w_factor);
	histo_ossf_rec[10]-> Fill(_jetFlavour[i],w_factor);
      }
      if (event_clas == 10 ||event_clas == 20 ||event_clas == 30 ||event_clas == 40 || event_clas == 50 || event_clas == 60){
	histo_n_ossf_rec[7]-> Fill(_jetPt[i],w_factor);
	histo_n_ossf_rec[8]-> Fill(_jetEta[i],w_factor);
	histo_n_ossf_rec[9]-> Fill(_jetPhi[i],w_factor);
	histo_n_ossf_rec[10]-> Fill(_jetFlavour[i],w_factor);
      }
    }
    //================ OSSF !!!!!!! ===================================
    //************************** HISTOGRAMS REC *************************
    if (event_clas == 1 ||event_clas == 2 ||event_clas == 3 ||event_clas == 4 || event_clas == 5 || event_clas == 6 ){
      //cout<< "classe: "<< event_clas<< "  --> pt: "<< lepton_reco[0].Pt()<<","<<lepton_reco[1].Pt()<<","<<lepton_reco[2].Pt()<< " flavour: "<<f_lepton1<<"."<<f_lepton2<<"."<<f_lepton3<<"  charge:  "<<c_lepton1<<"."<<c_lepton2<<"."<<c_lepton3<<endl;
            
            
      histo_ossf_kin_rec_l1[0]->Fill(lepton_reco[0].Pt(),w_factor); //pt
      histo_ossf_kin_rec_l1[1]->Fill(lepton_reco[0].Eta(),w_factor); // eta
      histo_ossf_kin_rec_l1[2]->Fill(lepton_reco[0].Phi(),w_factor); //phi
      histo_ossf_kin_rec_l2[0]->Fill(lepton_reco[1].Pt(),w_factor); //pt
      histo_ossf_kin_rec_l2[1]->Fill(lepton_reco[1].Eta(),w_factor); // eta
      histo_ossf_kin_rec_l2[2]->Fill(lepton_reco[1].Phi(),w_factor); //phi
      histo_ossf_kin_rec_l3[0]->Fill(lepton_reco[2].Pt(),w_factor); //pt
      histo_ossf_kin_rec_l3[1]->Fill(lepton_reco[2].Eta(),w_factor); // eta
      histo_ossf_kin_rec_l3[2]->Fill(lepton_reco[2].Phi(),w_factor); //phi
      histo_ossf_rec[0]-> Fill(_met,w_factor);
      histo_ossf_rec[1]-> Fill(lepton_reco[0].Pt()+lepton_reco[1].Pt()+lepton_reco[2].Pt(),w_factor);
      histo_ossf_rec[2]-> Fill(sum_3l_rec.Mag(),w_factor);
      histo_ossf_rec[3]-> Fill(sum_2l_rec.Mag(),w_factor);
      histo_ossf_rec[4]-> Fill(numero_jet,w_factor);
      histo_ossf_rec[5]-> Fill(lepton_reco[0].Pt()+lepton_reco[2].Pt(),w_factor);
      histo_ossf_rec[6]-> Fill(HT,w_factor);
            
      //************************** histo_ossfGRAMS GEN *************************
      histo_ossf_kin_gen_l1[0]->Fill(lepton_gen[0].Pt(),w_factor); //pt
      histo_ossf_kin_gen_l1[1]->Fill(lepton_gen[0].Eta(),w_factor); // eta
      histo_ossf_kin_gen_l1[2]->Fill(lepton_gen[0].Phi(),w_factor); //phi
      histo_ossf_kin_gen_l2[0]->Fill(lepton_gen[1].Pt(),w_factor); //pt
      histo_ossf_kin_gen_l2[1]->Fill(lepton_gen[1].Eta(),w_factor); // eta
      histo_ossf_kin_gen_l2[2]->Fill(lepton_gen[1].Phi(),w_factor); //phi
      histo_ossf_kin_gen_l3[0]->Fill(lepton_gen[2].Pt(),w_factor); //pt
      histo_ossf_kin_gen_l3[1]->Fill(lepton_gen[2].Eta(),w_factor); // eta
      histo_ossf_kin_gen_l3[2]->Fill(lepton_gen[2].Phi(),w_factor); //phi
      histo_ossf_gen[0]-> Fill(_genmet,w_factor);
      histo_ossf_gen[1]-> Fill(m_T_gen,w_factor);
      histo_ossf_gen[2]-> Fill(sum_3l_gen.Mag(),w_factor);
      histo_ossf_gen[3]-> Fill(sum_2l_gen.Mag(),w_factor);
    }// OSSF
        
    //================ n_ossf !!!!!!! ===================================
    //************************** HISTOGRAMS REC *************************
    if (event_clas == 10 ||event_clas == 20 ||event_clas == 30 ||event_clas == 40 || event_clas == 50 || event_clas == 60){
            
      histo_n_ossf_kin_rec_l1[0]->Fill(lepton_reco[0].Pt(),w_factor); //pt
      histo_n_ossf_kin_rec_l1[1]->Fill(lepton_reco[0].Eta(),w_factor); // eta
      histo_n_ossf_kin_rec_l1[2]->Fill(lepton_reco[0].Phi(),w_factor); //phi
      histo_n_ossf_kin_rec_l2[0]->Fill(lepton_reco[1].Pt(),w_factor); //pt
      histo_n_ossf_kin_rec_l2[1]->Fill(lepton_reco[1].Eta(),w_factor); // eta
      histo_n_ossf_kin_rec_l2[2]->Fill(lepton_reco[1].Phi(),w_factor); //phi
      histo_n_ossf_kin_rec_l3[0]->Fill(lepton_reco[2].Pt(),w_factor); //pt
      histo_n_ossf_kin_rec_l3[1]->Fill(lepton_reco[2].Eta(),w_factor); // eta
      histo_n_ossf_kin_rec_l3[2]->Fill(lepton_reco[2].Phi(),w_factor); //phi
      histo_n_ossf_rec[0]-> Fill(_met,w_factor);
      histo_n_ossf_rec[1]-> Fill(lepton_reco[0].Pt()+lepton_reco[1].Pt()+lepton_reco[2].Pt(),w_factor);
      histo_n_ossf_rec[2]-> Fill(sum_3l_rec.Mag(),w_factor);
      histo_n_ossf_rec[3]-> Fill(sum_2l_rec.Mag(),w_factor);
      histo_n_ossf_rec[4]-> Fill(numero_jet,w_factor);
      histo_n_ossf_rec[5]-> Fill(lepton_reco[0].Pt()+lepton_reco[2].Pt(),w_factor);
      histo_n_ossf_rec[6]-> Fill(HT,w_factor);
            
            
      //************************** histo_n_ossfGRAMS GEN *************************
      histo_n_ossf_kin_gen_l1[0]->Fill(lepton_gen[0].Pt(),w_factor); //pt
      histo_n_ossf_kin_gen_l1[1]->Fill(lepton_gen[0].Eta(),w_factor); // eta
      histo_n_ossf_kin_gen_l1[2]->Fill(lepton_gen[0].Phi(),w_factor); //phi
      histo_n_ossf_kin_gen_l2[0]->Fill(lepton_gen[1].Pt(),w_factor); //pt
      histo_n_ossf_kin_gen_l2[1]->Fill(lepton_gen[1].Eta(),w_factor); // eta
      histo_n_ossf_kin_gen_l2[2]->Fill(lepton_gen[1].Phi(),w_factor); //phi
      histo_n_ossf_kin_gen_l3[0]->Fill(lepton_gen[2].Pt(),w_factor); //pt
      histo_n_ossf_kin_gen_l3[1]->Fill(lepton_gen[2].Eta(),w_factor); // eta
      histo_n_ossf_kin_gen_l3[2]->Fill(lepton_gen[2].Phi(),w_factor); //phi
      histo_n_ossf_gen[0]-> Fill(_genmet,w_factor);
      histo_n_ossf_gen[1]-> Fill(m_T_gen,w_factor);
      histo_n_ossf_gen[2]-> Fill(sum_3l_gen.Mag(),w_factor);
      histo_n_ossf_gen[3]-> Fill(sum_2l_gen.Mag(),w_factor);
    }// n_ossf
        
        
    if (event_clas == 1 ||event_clas == 2 ||event_clas == 3 ||event_clas == 4 || event_clas == 5 || event_clas == 6 ){
      n_ossf++;
      histo_ossf_rec[11]-> Fill(sum_2l_rec_pair.Mag(),w_factor);
      histo_ossf_gen[4]-> Fill(sum_2l_gen_pair.Mag(),w_factor);
      //flavor_plot_ossf->Fill(event_clas+1, w_factor);
    }
    if (event_clas == 10 ||event_clas == 20 ||event_clas == 30 ||event_clas == 40 || event_clas == 50 || event_clas == 60){
      n_n_ossf++;
      histo_n_ossf_rec[11]-> Fill(sum_2l_rec_pair.Mag(),w_factor);
      histo_n_ossf_gen[4]-> Fill(sum_2l_gen_pair.Mag(),w_factor);
      //lavor_plot_n_ossf->Fill((event_clas*0.1)+1, w_factor);
    }
        
    if (event_clas == 1)flavor_plot_ossf->Fill(event_clas+1, w_factor);
    if (event_clas == 2)flavor_plot_ossf->Fill(event_clas+2, w_factor);
    if (event_clas == 3)flavor_plot_ossf->Fill(event_clas+2, w_factor);
    if (event_clas == 4)flavor_plot_ossf->Fill(event_clas+2, w_factor);
    if (event_clas == 5)flavor_plot_ossf->Fill(event_clas+2, w_factor);
    if (event_clas == 6)flavor_plot_ossf->Fill(event_clas-3, w_factor);
    if (event_clas == 10)flavor_plot_n_ossf->Fill((event_clas*0.1)+1, w_factor);
    if (event_clas == 20)flavor_plot_n_ossf->Fill((event_clas*0.1)+2, w_factor);
    if (event_clas == 30)flavor_plot_n_ossf->Fill((event_clas*0.1)+2, w_factor);
    if (event_clas == 40)flavor_plot_n_ossf->Fill((event_clas*0.1)+2, w_factor);
    if (event_clas == 50)flavor_plot_n_ossf->Fill((event_clas*0.1)+2, w_factor);
    if (event_clas == 60)flavor_plot_n_ossf->Fill((event_clas*0.1)-3, w_factor);
        
        

	
     if (event_clas == 1 ||event_clas == 2 ||event_clas == 3 ||event_clas == 4 || event_clas == 5 || event_clas == 6 ){
	  if (((f_lepton1 == 0 && f_lepton2 == 1) || (f_lepton1 == 1 && f_lepton2 == 0)) && lepton_reco[0].DeltaR(lepton_reco[1]) > 0.05){
            histo_ossf_kin_rec_l1[3]->Fill(lepton_reco[0].DeltaR(lepton_reco[1]));
	  }
	  if (((f_lepton1 == 1 && f_lepton2 == 1) || (f_lepton1 == 0 && f_lepton2 == 0)) ){
            histo_ossf_kin_rec_l1[3]->Fill(lepton_reco[0].DeltaR(lepton_reco[1]));
	  }



	  if (((f_lepton1 == 0 && f_lepton3 == 1) || (f_lepton1 == 1 && f_lepton3 == 0)) && lepton_reco[0].DeltaR(lepton_reco[2]) > 0.05){
            histo_ossf_kin_rec_l1[3]->Fill(lepton_reco[0].DeltaR(lepton_reco[2]));
	  }
	  if (((f_lepton1 == 1 && f_lepton3 == 1) || (f_lepton1 == 0 && f_lepton3 == 0)) ){
            histo_ossf_kin_rec_l1[3]->Fill(lepton_reco[0].DeltaR(lepton_reco[2]));
	  }


	   
	  if (((f_lepton3 == 0 && f_lepton2 == 1) || (f_lepton3 == 1 && f_lepton2 == 0)) && lepton_reco[0].DeltaR(lepton_reco[1]) > 0.05){
            histo_ossf_kin_rec_l1[3]->Fill(lepton_reco[1].DeltaR(lepton_reco[2]));
	  }
	  if (((f_lepton3 == 1 && f_lepton2 == 1) || (f_lepton3 == 0 && f_lepton2 == 0)) ){
            histo_ossf_kin_rec_l1[3]->Fill(lepton_reco[1].DeltaR(lepton_reco[2]));
	  }

	  //histo_ossf_kin_rec_l1[3]->Fill(lepton_reco[0].DeltaR(lepton_reco[2]));
	  //histo_ossf_kin_rec_l1[3]->Fill(lepton_reco[1].DeltaR(lepton_reco[2]));
            //histo_ossf_kin_rec_l1[3]->Fill(pair1_rec.DeltaR(pair2_rec));
        }
        if (event_clas == 10 ||event_clas == 20 ||event_clas == 30 ||event_clas == 40 || event_clas == 50 || event_clas == 60 ){

	  if (((f_lepton1 == 0 && f_lepton2 == 1) || (f_lepton1 == 1 && f_lepton2 == 0)) && lepton_reco[0].DeltaR(lepton_reco[1]) > 0.05){
	    histo_n_ossf_kin_rec_l1[3]->Fill(lepton_reco[0].DeltaR(lepton_reco[1]));
	  }
	  if (((f_lepton1 == 1 && f_lepton2 == 1) || (f_lepton1 == 0 && f_lepton2 == 0)) ){
	    histo_n_ossf_kin_rec_l1[3]->Fill(lepton_reco[0].DeltaR(lepton_reco[1]));
	  }



	  if (((f_lepton1 == 0 && f_lepton3 == 1) || (f_lepton1 == 1 && f_lepton3 == 0)) && lepton_reco[0].DeltaR(lepton_reco[2]) > 0.05){
	    histo_n_ossf_kin_rec_l1[3]->Fill(lepton_reco[0].DeltaR(lepton_reco[2]));
	  }
	  if (((f_lepton1 == 1 && f_lepton3 == 1) || (f_lepton1 == 0 && f_lepton3 == 0)) ){
	    histo_n_ossf_kin_rec_l1[3]->Fill(lepton_reco[0].DeltaR(lepton_reco[2]));
	  }



	  if (((f_lepton3 == 0 && f_lepton2 == 1) || (f_lepton3 == 1 && f_lepton2 == 0)) && lepton_reco[0].DeltaR(lepton_reco[1]) > 0.05){
	    histo_n_ossf_kin_rec_l1[3]->Fill(lepton_reco[1].DeltaR(lepton_reco[2]));
	  }
	  if (((f_lepton3 == 1 && f_lepton2 == 1) || (f_lepton3 == 0 && f_lepton2 == 0)) ){
	    histo_n_ossf_kin_rec_l1[3]->Fill(lepton_reco[1].DeltaR(lepton_reco[2]));
	  }



	  //histo_n_ossf_kin_rec_l1[3]->Fill(lepton_reco[0].DeltaR(lepton_reco[1]));
            //histo_n_ossf_kin_rec_l1[3]->Fill(lepton_reco[0].DeltaR(lepton_reco[2]));
	    // histo_n_ossf_kin_rec_l1[3]->Fill(lepton_reco[1].DeltaR(lepton_reco[2]));
            //histo_n_ossf_kin_rec_l1[3]->Fill(pair1_rec.DeltaR(pair2_rec));
        }

    Double_t delta_ossf_R_max=-1;
    Double_t delta_ossf_R_min=-1;
    //if (event_clas == 1 ||event_clas == 2 ||event_clas == 3 ||event_clas == 4 || event_clas == 5 || event_clas == 6 ){

      delta_ossf_R_max = lepton_reco[0].DeltaR(lepton_reco[1]);
      if (lepton_reco[0].DeltaR(lepton_reco[2]) > delta_ossf_R_max) delta_ossf_R_max = lepton_reco[0].DeltaR(lepton_reco[2]);
      if (lepton_reco[1].DeltaR(lepton_reco[2]) > delta_ossf_R_max) delta_ossf_R_max = lepton_reco[1].DeltaR(lepton_reco[2]);

      delta_ossf_R_min = lepton_reco[0].DeltaR(lepton_reco[1]);
      if (lepton_reco[0].DeltaR(lepton_reco[2]) < delta_ossf_R_min) delta_ossf_R_min = lepton_reco[0].DeltaR(lepton_reco[2]);
      if (lepton_reco[1].DeltaR(lepton_reco[2]) < delta_ossf_R_min) delta_ossf_R_min = lepton_reco[1].DeltaR(lepton_reco[2]);
      
    
      
      

      if (massa==50 ) { // zgamma
	signal_50_2d_ossf->Fill(delta_ossf_R_min,delta_ossf_R_max);
	signal_50_2d_pt_ossf->Fill(lepton_reco[2].Pt(),lepton_reco[0].Pt());
      }
      if (massa==20 ) { // ttamma
	signal_20_2d_ossf->Fill(delta_ossf_R_min,delta_ossf_R_max);
	signal_20_2d_pt_ossf->Fill(lepton_reco[2].Pt(),lepton_reco[0].Pt());
      }
      if (massa==10) { // wgamma
	signal_10_2d_ossf->Fill(delta_ossf_R_min,delta_ossf_R_max);
	signal_10_2d_pt_ossf->Fill(lepton_reco[2].Pt(),lepton_reco[0].Pt());
      }
      if (massa==60 ) { // zgamma
	signal_60_2d_ossf->Fill(delta_ossf_R_min,delta_ossf_R_max);
	signal_60_2d_pt_ossf->Fill(lepton_reco[2].Pt(),lepton_reco[0].Pt());
      }
      if (massa==40 ) { // ttamma
	signal_40_2d_ossf->Fill(delta_ossf_R_min,delta_ossf_R_max);
	signal_40_2d_pt_ossf->Fill(lepton_reco[2].Pt(),lepton_reco[0].Pt());
      }
      if (massa==5) { // wgamma
	signal_5_2d_ossf->Fill(delta_ossf_R_min,delta_ossf_R_max);
	signal_5_2d_pt_ossf->Fill(lepton_reco[2].Pt(),lepton_reco[0].Pt());
      }
      if (massa==15) { // wgamma
	signal_15_2d_ossf->Fill(delta_ossf_R_min,delta_ossf_R_max);
	signal_15_2d_pt_ossf->Fill(lepton_reco[2].Pt(),lepton_reco[0].Pt());
      }

      //}
    Double_t delta_n_ossf_R_max=-1;
    Double_t delta_n_ossf_R_min=-1;
    if (event_clas == 10 ||event_clas == 20 ||event_clas == 30 ||event_clas == 40 || event_clas == 50 || event_clas == 60 ){
    
      delta_n_ossf_R_max = lepton_reco[0].DeltaR(lepton_reco[1]);
      if (lepton_reco[0].DeltaR(lepton_reco[2]) > delta_n_ossf_R_max) delta_n_ossf_R_max = lepton_reco[0].DeltaR(lepton_reco[2]);
      if (lepton_reco[1].DeltaR(lepton_reco[2]) > delta_n_ossf_R_max) delta_n_ossf_R_max = lepton_reco[1].DeltaR(lepton_reco[2]);
            
      delta_n_ossf_R_min = lepton_reco[0].DeltaR(lepton_reco[1]);
      if (lepton_reco[0].DeltaR(lepton_reco[2]) < delta_n_ossf_R_min) delta_n_ossf_R_min = lepton_reco[0].DeltaR(lepton_reco[2]);
      if (lepton_reco[1].DeltaR(lepton_reco[2]) < delta_n_ossf_R_min) delta_n_ossf_R_min = lepton_reco[1].DeltaR(lepton_reco[2]);


      if (massa==50 ) { // zgamma
	signal_50_2d_n_ossf->Fill(delta_n_ossf_R_min,delta_n_ossf_R_max);
	signal_50_2d_pt_n_ossf->Fill(lepton_reco[2].Pt(),lepton_reco[0].Pt());
      }
      if (massa==20 ) { // ttamma
	signal_20_2d_n_ossf->Fill(delta_n_ossf_R_min,delta_n_ossf_R_max);
	signal_20_2d_pt_n_ossf->Fill(lepton_reco[2].Pt(),lepton_reco[0].Pt());
      }
      if (massa==10) { // wgamma
	signal_10_2d_n_ossf->Fill(delta_n_ossf_R_min,delta_n_ossf_R_max);
	signal_10_2d_pt_n_ossf->Fill(lepton_reco[2].Pt(),lepton_reco[0].Pt());
      }
      if (massa==60 ) { // zgamma
	signal_60_2d_n_ossf->Fill(delta_n_ossf_R_min,delta_n_ossf_R_max);
	signal_60_2d_pt_n_ossf->Fill(lepton_reco[2].Pt(),lepton_reco[0].Pt());
      }
      if (massa==40 ) { // ttamma
	signal_40_2d_n_ossf->Fill(delta_n_ossf_R_min,delta_n_ossf_R_max);
	signal_40_2d_pt_n_ossf->Fill(lepton_reco[2].Pt(),lepton_reco[0].Pt());
      }
      if (massa==5) { // wgamma
	signal_5_2d_n_ossf->Fill(delta_n_ossf_R_min,delta_n_ossf_R_max);
	signal_5_2d_pt_n_ossf->Fill(lepton_reco[2].Pt(),lepton_reco[0].Pt());
      }
      if (massa==15) { // wgamma
	signal_15_2d_n_ossf->Fill(delta_n_ossf_R_min,delta_n_ossf_R_max);
	signal_15_2d_pt_n_ossf->Fill(lepton_reco[2].Pt(),lepton_reco[0].Pt());
      }
	 


    }



        
        
    flavor_plot_ossf->SetBinContent(1, n_ossf*w_factor);
    flavor_plot_n_ossf->SetBinContent(1, n_n_ossf*w_factor);
        

        
    if (event_clas == 1 ||event_clas == 2 ||event_clas == 3 ||event_clas == 4 || event_clas == 5 || event_clas == 6 )   denominatore_ossf= denominatore_ossf +1*w_factor;
    if (event_clas == 10 ||event_clas == 20 ||event_clas == 30 ||event_clas == 40 || event_clas == 50 || event_clas == 60)  denominatore_n_ossf= denominatore_n_ossf +1*w_factor;
        
        
    for (int i = 0; i< bin_num; i++){
      if (event_clas == 1 ||event_clas == 2 ||event_clas == 3 ||event_clas == 4 || event_clas == 5 || event_clas == 6 ){
	if (lepton_reco[0].Pt() < i) numerator_ossf[i] = numerator_ossf[i] +  w_factor;
	if (lepton_reco[0].Pt() > i) numerator_min_ossf[i] = numerator_min_ossf[i] +  w_factor;
      }
      if (event_clas == 10 ||event_clas == 20 ||event_clas == 30 ||event_clas == 40 || event_clas == 50 || event_clas == 60){
	if (lepton_reco[0].Pt() < i) numerator_n_ossf[i] = numerator_n_ossf[i] +  w_factor;
	if (lepton_reco[0].Pt() > i) numerator_min_n_ossf[i] = numerator_min_n_ossf[i] +  w_factor;
      }
    }
    }//end tree    
        
    if (massa==50 ) { // zgamma
      std::ofstream signal_ptcut_50_min("codes_eff/txt_file/signal_ptcut_50_min.txt");
      for (int i =0; i < bin_num ; i++) {
	signal_ptcut_50_min<<i<<" "<< numerator_min_ossf[i]<<" "<<numerator_min_n_ossf[i]<<" "<<denominatore_ossf<<" "<<denominatore_n_ossf<<endl;
      }
    }
    if (massa==20) { // ttamma
      std::ofstream signal_ptcut_20_min("codes_eff/txt_file/signal_ptcut_20_min.txt");
      for (int i =0; i < bin_num ; i++) {
	signal_ptcut_20_min<<i<<" "<< numerator_min_ossf[i]<<" "<<numerator_min_n_ossf[i]<<" "<<denominatore_ossf<<" "<<denominatore_n_ossf<<endl;
      }
    }
    if (massa==10 ) { // wgamma
      std::ofstream signal_ptcut_10_min("codes_eff/txt_file/signal_ptcut_10_min.txt");
      for (int i =0; i < bin_num ; i++) {
	signal_ptcut_10_min<<i<<" "<< numerator_min_ossf[i]<<" "<<numerator_min_n_ossf[i]<<" "<<denominatore_ossf<<" "<<denominatore_n_ossf<<endl;
      }
    }
        
        
        
        
    if (massa==50 ) { // zgamma
      std::ofstream signal_ptcut_50_max("codes_eff/txt_file/signal_ptcut_50_max.txt");
      for (int i =0; i < bin_num ; i++) {
	signal_ptcut_50_max<<i<<" "<< numerator_ossf[i]<<" "<<numerator_n_ossf[i]<<" "<<" "<<denominatore_ossf<<" "<<denominatore_n_ossf<<endl;
      }
    }
    if (massa==20) { // ttamma
      std::ofstream signal_ptcut_20_max("codes_eff/txt_file/signal_ptcut_20_max.txt");
      for (int i =0; i < bin_num ; i++) {
	signal_ptcut_20_max<<i<<" "<< numerator_ossf[i]<<" "<<numerator_n_ossf[i]<<" "<<" "<<denominatore_ossf<<" "<<denominatore_n_ossf<<endl;
      }
    }
    if (massa==10 ) { // wgamma
      std::ofstream signal_ptcut_10_max("codes_eff/txt_file/signal_ptcut_10_max.txt");
      for (int i =0; i < bin_num ; i++) {
	signal_ptcut_10_max<<i<<" "<< numerator_ossf[i]<<" "<<numerator_n_ossf[i]<<" "<<" "<<denominatore_ossf<<" "<<denominatore_n_ossf<<endl;
      }
    }

    if (massa==60 ) { // zgamma
      std::ofstream signal_ptcut_60_min("codes_eff/txt_file/signal_ptcut_60_min.txt");
      for (int i =0; i < bin_num ; i++) {
        signal_ptcut_60_min<<i<<" "<< numerator_min_ossf[i]<<" "<<numerator_min_n_ossf[i]<<" "<<denominatore_ossf<<" "<<denominatore_n_ossf<<endl;
      }
    }
    if (massa==40) { // ttamma
      std::ofstream signal_ptcut_40_min("codes_eff/txt_file/signal_ptcut_40_min.txt");
      for (int i =0; i < bin_num ; i++) {
        signal_ptcut_40_min<<i<<" "<< numerator_min_ossf[i]<<" "<<numerator_min_n_ossf[i]<<" "<<denominatore_ossf<<" "<<denominatore_n_ossf<<endl;
      }
    }
    if (massa==5 ) { // wgamma
      std::ofstream signal_ptcut_5_min("codes_eff/txt_file/signal_ptcut_5_min.txt");
      for (int i =0; i < bin_num ; i++) {
        signal_ptcut_5_min<<i<<" "<< numerator_min_ossf[i]<<" "<<numerator_min_n_ossf[i]<<" "<<denominatore_ossf<<" "<<denominatore_n_ossf<<endl;
      }
    }
    if (massa==15 ) { // wgamma
      std::ofstream signal_ptcut_15_min("codes_eff/txt_file/signal_ptcut_15_min.txt");
      for (int i =0; i < bin_num ; i++) {
        signal_ptcut_15_min<<i<<" "<< numerator_min_ossf[i]<<" "<<numerator_min_n_ossf[i]<<" "<<denominatore_ossf<<" "<<denominatore_n_ossf<<endl;
      }
    }
    if (massa==15 ) { // wgamma
      std::ofstream signal_ptcut_15_max("codes_eff/txt_file/signal_ptcut_15_max.txt");
      for (int i =0; i < bin_num ; i++) {
        signal_ptcut_15_max<<i<<" "<< numerator_ossf[i]<<" "<<numerator_n_ossf[i]<<" "<<" "<<denominatore_ossf<<" "<<denominatore_n_ossf<<endl;
      }
    }



    if (massa==60 ) { // zgamma
      std::ofstream signal_ptcut_60_max("codes_eff/txt_file/signal_ptcut_60_max.txt");
      for (int i =0; i < bin_num ; i++) {
        signal_ptcut_60_max<<i<<" "<< numerator_ossf[i]<<" "<<numerator_n_ossf[i]<<" "<<" "<<denominatore_ossf<<" "<<denominatore_n_ossf<<endl;
      }
    }
    if (massa==40) { // ttamma
      std::ofstream signal_ptcut_40_max("codes_eff/txt_file/signal_ptcut_40_max.txt");
      for (int i =0; i < bin_num ; i++) {
        signal_ptcut_40_max<<i<<" "<< numerator_ossf[i]<<" "<<numerator_n_ossf[i]<<" "<<" "<<denominatore_ossf<<" "<<denominatore_n_ossf<<endl;
      }
    }
    if (massa==5 ) { // wgamma
      std::ofstream signal_ptcut_5_max("codes_eff/txt_file/signal_ptcut_5_max.txt");
      for (int i =0; i < bin_num ; i++) {
        signal_ptcut_5_max<<i<<" "<< numerator_ossf[i]<<" "<<numerator_n_ossf[i]<<" "<<" "<<denominatore_ossf<<" "<<denominatore_n_ossf<<endl;
      }
    }


   
        


  cout<<massa<<endl;
  cout<<"tot: "<<number_event_tot<<endl;
  cout<<"ossf after b veto: "<<number_event_ossf<<endl;
  cout<<"no ossf after b veto: "<<number_event_n_ossf<<endl;


}// end selection_ossf







