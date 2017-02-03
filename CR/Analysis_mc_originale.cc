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
#include <THStack.h>
#include <TPaveText.h>
#include <Analysis_mc.h>
#include "TApplication.h"
#include "TColor.h"



//include C++ library classes
#include <sstream>
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using std::cout;
using std::endl;
using std::flush;
using std::ofstream;

//include other parts of the code
#include "tdrstyle.h"
#include "plotCode_new.h"



using namespace std;




static Double_t pigreco= TMath::ACos(-1);
ClassImp(Analysis_mc)

//_______________________________________________________default constructor_____
Analysis_mc::Analysis_mc():TObject()

{
}
//_______________________________________________________ constructor_____
Analysis_mc::Analysis_mc(string FileNameTree_in):TObject()

{
}
//________________________________________________________________distruttore_____
Analysis_mc::~Analysis_mc()	 {
  // destructor
}


//==================================================================
void Analysis_mc::analisi(int num_histo_kin
			  ){
  
  cout<<"in analisi"<<endl;
  cout<<"---------------------------"<<endl;

  setTDRStyle();
  //gROOT->SetBatch(kTRUE);


   
  TGraphAsymmErrors *fakeRate_mu[3];
  TGraphAsymmErrors *fakeRate_mu_04_from_qcd[3];
  TGraphAsymmErrors *fakeRate_e[3];

  TFile hfile2("/Users/Martina/Desktop/CMS/map_FR/fake_rate_mu.root");
  fakeRate_mu[0] = (TGraphAsymmErrors*)hfile2.Get("fakeRate_mu_eta1");
  fakeRate_mu[1] = (TGraphAsymmErrors*)hfile2.Get("fakeRate_mu_eta2");
  fakeRate_mu[2] = (TGraphAsymmErrors*)hfile2.Get("fakeRate_mu_eta3");
  fakeRate_mu_04_from_qcd[0] = (TGraphAsymmErrors*)hfile2.Get("fakeRate_mu_04_eta1");
  fakeRate_mu_04_from_qcd[1] = (TGraphAsymmErrors*)hfile2.Get("fakeRate_mu_04_eta2");
  fakeRate_mu_04_from_qcd[2] = (TGraphAsymmErrors*)hfile2.Get("fakeRate_mu_04_eta3");

  TFile hfile1("/Users/Martina/Desktop/CMS/map_FR/fake_rate.root");
  fakeRate_e[0] = (TGraphAsymmErrors*)hfile1.Get("fakeRate_e_eta1");
  fakeRate_e[1] = (TGraphAsymmErrors*)hfile1.Get("fakeRate_e_eta2");
  fakeRate_e[2] = (TGraphAsymmErrors*)hfile1.Get("fakeRate_e_eta3");





  const int nSamples= 19;
  const int nSamples_eff = 7;
   
  const TString fileList[nSamples] = {"MuonEG.root", "DoubleMuon.root", "DoubleEG.root", 

				      "majo_40.root",
				      "WZTo3LNu_TuneCUETP8M1_13TeV-powheg-pythia8.root",

				      "ZGTo2LG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8.root",
				      "WGToLNuG_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",

				      "ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root",
				      "WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root", 
				      "WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root",
				      "WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root", 

				      "TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8.root",
				      "TTZToLLNuNu_M-10_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root",
				      "tZq_ll_4f_13TeV-amcatnlo-pythia8_TuneCUETP8M1.root",
				      "TTGJets_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8.root",
				      "TTTT_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root",
					
				      "ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix.root",
				      "ZZTo4L_13TeV_powheg_pythia8.root",
				      "VHToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8.root"};
  // "GluGluHToZZTo4L_M125_13TeV_powheg2_JHUgenV6_pythia8.root"};
  const TString names[nSamples] = {"total MC","total MC","total MC","Majorana1", "WZ",  "X+gamma", "X+gamma","triboson","triboson","triboson","triboson", "TT+X","TT+X","TT+X","TT+X","TT+X", "ZZ/H","ZZ/H","ZZ/H"};
  const TString eff_names[nSamples_eff +1] = {"total","Majorana1", "WZ","X+gamma", "triboson", "TT+X", "ZZ/H", "no-prompt"};
  const double xSections[nSamples-3]= {0.004892, 4.42965,117.864, 405.271 , 0.01398 ,0.05565 ,0.1651 ,0.2086 ,0.2043,0.2529,0.0758,3.697,0.009103,0.215,1.212,0.952};
				       //0.01212};
  double luminosity = 36.3;

  TFile *hfile[nSamples];
  TTree *inputTree[nSamples];
  //TApplication* rootapp = new TApplication("example",&argc, argv);


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
  Double_t        _mvaValue_HZZ[_nLeptons];   //[_nLeptons]
  Bool_t          _passedCutBasedIdTight[_nLeptons];   //[_nLeptons]
  Bool_t          _passedCutBasedIdMedium[_nLeptons];   //[_nLeptons]
  Bool_t          _passedMVA80[_nLeptons];   //[_nLeptons]
  Bool_t          _passedMVA90[_nLeptons];   //[_nLeptons]
  Bool_t          _passedMVA_SUSY[_nLeptons][3];   //[_nLeptons]
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
   TBranch        *b__isolation;   //!
   TBranch        *b__isolation_absolute;   //!
   TBranch        *b__miniisolation;   //!
   TBranch        *b__miniisolationCharged;   //!
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
   TBranch        *b__ismedium;   //!
   TBranch        *b__istight;   //!
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
   TBranch        *b__mvaValue_HZZ;   //!
   TBranch        *b__passedCutBasedIdTight;   //!
   TBranch        *b__passedCutBasedIdMedium;   //!
   TBranch        *b__passedMVA80;   //!
   TBranch        *b__passedMVA90;   //!
   TBranch        *b__passedMVA_SUSY;   //!
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
   TBranch        *b__findMatched;   //!
    _leptonP4 = 0;
    _gen_leptonP4=0;
    _gen_nuP4=0;
    _gen_majoP4=0;
    _gen_wP4=0;
    
    

  double hcounter[nSamples];
    
  for(int sam = 0; sam < nSamples; ++sam){
    cout << "name " << names[sam] << endl;
    cout<<"================================= 1"<<endl;
    hfile[sam] = new TFile("/Users/Martina/Desktop/CMS/FILE/"+fileList[sam],"read");
    hfile[sam]->cd("trileptonProducer");
    inputTree[sam] = static_cast<TTree*>(hfile[sam]->Get("trileptonProducer/trileptonTree"));

        cout<<"================================= 2"<<endl;


    inputTree[sam]->SetBranchAddress("_leptonP4", &_leptonP4, &b__leptonP4);

        cout<<"================================= 3"<<endl;

    inputTree[sam]->SetBranchAddress("_gen_leptonP4", &_gen_leptonP4, &b__gen_leptonP4);
    inputTree[sam]->SetBranchAddress("_gen_nuP4", &_gen_nuP4, &b__gen_nuP4);
    inputTree[sam]->SetBranchAddress("_gen_majoP4", &_gen_majoP4, &b__gen_majoP4);
    //    inputTree[sam]->SetBranchAddress("_gen_majoP4", &_gen_majoP4, &b__gen_majoP4);
    inputTree[sam]->SetBranchAddress("_gen_wP4", &_gen_wP4, &b__gen_wP4);
    inputTree[sam]->SetBranchAddress("_eventNb", &_eventNb, &b__eventNb);
    inputTree[sam]->SetBranchAddress("_runNb", &_runNb, &b__runNb);
    inputTree[sam]->SetBranchAddress("_lumiBlock", &_lumiBlock, &b__lumiBlock);
    inputTree[sam]->SetBranchAddress("_nLeptons", &_nLeptons, &b__nLeptons);
    inputTree[sam]->SetBranchAddress("_lPt", _lPt, &b__lPt);
    inputTree[sam]->SetBranchAddress("_lEta", _lEta, &b__lEta);
    inputTree[sam]->SetBranchAddress("_lPhi", _lPhi, &b__lPhi);
    inputTree[sam]->SetBranchAddress("_lE", _lE, &b__lE);
    inputTree[sam]->SetBranchAddress("_lPtmc", _lPtmc, &b__lPtmc);
    inputTree[sam]->SetBranchAddress("_lEtamc", _lEtamc, &b__lEtamc);
    inputTree[sam]->SetBranchAddress("_lPhimc", _lPhimc, &b__lPhimc);
    inputTree[sam]->SetBranchAddress("_lEmc", _lEmc, &b__lEmc);
    inputTree[sam]->SetBranchAddress("_lpdgmc", _lpdgmc, &b__lpdgmc);
    inputTree[sam]->SetBranchAddress("_lchargemc", _lchargemc, &b__lchargemc);
inputTree[sam]->SetBranchAddress("_nuPtmc", _nuPtmc, &b__nuPtmc);
inputTree[sam]->SetBranchAddress("_nuEtamc", _nuEtamc, &b__nuEtamc);
inputTree[sam]->SetBranchAddress("_nuPhimc", _nuPhimc, &b__nuPhimc);
inputTree[sam]->SetBranchAddress("_nuEmc", _nuEmc, &b__nuEmc);
inputTree[sam]->SetBranchAddress("_mtmc", _mtmc, &b__mtmc);
inputTree[sam]->SetBranchAddress("_nZboson", &_nZboson, &b__nZboson);
inputTree[sam]->SetBranchAddress("_nEle", &_nEle, &b__nEle);
inputTree[sam]->SetBranchAddress("_nMu", &_nMu, &b__nMu);
inputTree[sam]->SetBranchAddress("_nTau", &_nTau, &b__nTau);
inputTree[sam]->SetBranchAddress("_flavors", _flavors, &b__flavors);
inputTree[sam]->SetBranchAddress("_charges", _charges, &b__charges);
inputTree[sam]->SetBranchAddress("_isolation", _isolation, &b__isolation);
inputTree[sam]->SetBranchAddress("_isolation_absolute", _isolation_absolute, &b__isolation_absolute);
inputTree[sam]->SetBranchAddress("_miniisolation", _miniisolation, &b__miniisolation);
inputTree[sam]->SetBranchAddress("_miniisolationCharged", _miniisolationCharged, &b__miniisolationCharged);
inputTree[sam]->SetBranchAddress("_ptrel", _ptrel, &b__ptrel);
inputTree[sam]->SetBranchAddress("_ptratio", _ptratio, &b__ptratio);
inputTree[sam]->SetBranchAddress("_muonSegmentComp", _muonSegmentComp, &b__muonSegmentComp);
inputTree[sam]->SetBranchAddress("_mll", _mll, &b__mll);
inputTree[sam]->SetBranchAddress("_origin", _origin, &b__origin);
inputTree[sam]->SetBranchAddress("_originReduced", _originReduced, &b__originReduced);
inputTree[sam]->SetBranchAddress("_isPromptFinalState", _isPromptFinalState, &b__isPromptFinalState);
inputTree[sam]->SetBranchAddress("_fromHardProcessFinalState", _fromHardProcessFinalState, &b__fromHardProcessFinalState);
inputTree[sam]->SetBranchAddress("_PVchi2", &_PVchi2, &b__PVchi2);
inputTree[sam]->SetBranchAddress("_PVerr", _PVerr, &b__PVerr);
inputTree[sam]->SetBranchAddress("_ipPV", _ipPV, &b__ipPV);
inputTree[sam]->SetBranchAddress("_ipPVerr", _ipPVerr, &b__ipPVerr);
inputTree[sam]->SetBranchAddress("_ipZPV", _ipZPV, &b__ipZPV);
inputTree[sam]->SetBranchAddress("_ipZPVerr", _ipZPVerr, &b__ipZPVerr);
inputTree[sam]->SetBranchAddress("_ipPVmc", _ipPVmc, &b__ipPVmc);
inputTree[sam]->SetBranchAddress("_3dIP", _3dIP, &b__3dIP);
inputTree[sam]->SetBranchAddress("_3dIPerr", _3dIPerr, &b__3dIPerr);
inputTree[sam]->SetBranchAddress("_3dIPsig", _3dIPsig, &b__3dIPsig);
inputTree[sam]->SetBranchAddress("_mt", _mt, &b__mt);
inputTree[sam]->SetBranchAddress("_isloose", _isloose, &b__isloose);
inputTree[sam]->SetBranchAddress("_ismedium", _ismedium, &b__ismedium);
inputTree[sam]->SetBranchAddress("_istight", _istight, &b__istight);
inputTree[sam]->SetBranchAddress("_trigEmulator", _trigEmulator, &b__trigEmulator);
inputTree[sam]->SetBranchAddress("_isotrigEmulator", _isotrigEmulator, &b__isotrigEmulator);
inputTree[sam]->SetBranchAddress("_closeJetPtAll", _closeJetPtAll, &b__closeJetPtAll);
inputTree[sam]->SetBranchAddress("_closeJetAngAll", _closeJetAngAll, &b__closeJetAngAll);
inputTree[sam]->SetBranchAddress("_trackSelectionMultiplicity", _trackSelectionMultiplicity, &b__trackSelectionMultiplicity);
inputTree[sam]->SetBranchAddress("_closeJetCSVAll", _closeJetCSVAll, &b__closeJetCSVAll);
inputTree[sam]->SetBranchAddress("_chargeConst", _chargeConst, &b__chargeConst);
inputTree[sam]->SetBranchAddress("_hitsNumber", _hitsNumber, &b__hitsNumber);
inputTree[sam]->SetBranchAddress("_vtxFitConversion", _vtxFitConversion, &b__vtxFitConversion);
inputTree[sam]->SetBranchAddress("_mvaValue", _mvaValue, &b__mvaValue);
inputTree[sam]->SetBranchAddress("_mvaValue_HZZ", _mvaValue_HZZ, &b__mvaValue_HZZ);
inputTree[sam]->SetBranchAddress("_passedCutBasedIdTight", _passedCutBasedIdTight, &b__passedCutBasedIdTight);
inputTree[sam]->SetBranchAddress("_passedCutBasedIdMedium", _passedCutBasedIdMedium, &b__passedCutBasedIdMedium);
inputTree[sam]->SetBranchAddress("_passedMVA80", _passedMVA80, &b__passedMVA80);
inputTree[sam]->SetBranchAddress("_passedMVA90", _passedMVA90, &b__passedMVA90);
inputTree[sam]->SetBranchAddress("_passedMVA_SUSY", _passedMVA_SUSY, &b__passedMVA_SUSY);
inputTree[sam]->SetBranchAddress("_n_PV", &_n_PV, &b__n_PV);
inputTree[sam]->SetBranchAddress("_n_MCTruth_PV", &_n_MCTruth_PV, &b__n_MCTruth_PV);
inputTree[sam]->SetBranchAddress("_met", &_met, &b__met);
inputTree[sam]->SetBranchAddress("_met_phi", &_met_phi, &b__met_phi);
inputTree[sam]->SetBranchAddress("HT", &HT, &b_HT);
inputTree[sam]->SetBranchAddress("_genmet", &_genmet, &b__genmet);
inputTree[sam]->SetBranchAddress("_genmet_phi", &_genmet_phi, &b__genmet_phi);
inputTree[sam]->SetBranchAddress("_genqpt", &_genqpt, &b__genqpt);
inputTree[sam]->SetBranchAddress("_genqpt20", &_genqpt20, &b__genqpt20);
inputTree[sam]->SetBranchAddress("_mompt", _mompt, &b__mompt);
inputTree[sam]->SetBranchAddress("_momphi", _momphi, &b__momphi);
inputTree[sam]->SetBranchAddress("_mometa", _mometa, &b__mometa);
inputTree[sam]->SetBranchAddress("_mompdg", _mompdg, &b__mompdg);
inputTree[sam]->SetBranchAddress("_n_bJets", &_n_bJets, &b__n_bJets);
inputTree[sam]->SetBranchAddress("_n_Jets", &_n_Jets, &b__n_Jets);
inputTree[sam]->SetBranchAddress("_bTagged", _bTagged, &b__bTagged);
inputTree[sam]->SetBranchAddress("_jetEta", _jetEta, &b__jetEta);
inputTree[sam]->SetBranchAddress("_jetPhi", _jetPhi, &b__jetPhi);
inputTree[sam]->SetBranchAddress("_jetPt", _jetPt, &b__jetPt);
inputTree[sam]->SetBranchAddress("_jetFlavour", _jetFlavour, &b__jetFlavour);
inputTree[sam]->SetBranchAddress("_jetE", _jetE, &b__jetE);
inputTree[sam]->SetBranchAddress("_csv", _csv, &b__csv);
inputTree[sam]->SetBranchAddress("_clean", _clean, &b__clean);
inputTree[sam]->SetBranchAddress("_jecUnc", _jecUnc, &b__jecUnc);
inputTree[sam]->SetBranchAddress("_jetPtUp", _jetPtUp, &b__jetPtUp);
inputTree[sam]->SetBranchAddress("_jetPtDown", _jetPtDown, &b__jetPtDown);
inputTree[sam]->SetBranchAddress("_matchedjetPt", _matchedjetPt, &b__matchedjetPt);
inputTree[sam]->SetBranchAddress("_matchedjetEta", _matchedjetEta, &b__matchedjetEta);
inputTree[sam]->SetBranchAddress("_matchedjetPhi", _matchedjetPhi, &b__matchedjetPhi);
inputTree[sam]->SetBranchAddress("_matchedjetE", _matchedjetE, &b__matchedjetE);
inputTree[sam]->SetBranchAddress("_matchedjetM", _matchedjetM, &b__matchedjetM);
inputTree[sam]->SetBranchAddress("_matchGjet", _matchGjet, &b__matchGjet);
inputTree[sam]->SetBranchAddress("_btagSF", _btagSF, &b__btagSF);
inputTree[sam]->SetBranchAddress("_weight", &_weight, &b__weight);
inputTree[sam]->SetBranchAddress("_LHEweight", _LHEweight, &b__LHEweight);
inputTree[sam]->SetBranchAddress("_LHEweightID", _LHEweightID, &b__LHEweightID);
inputTree[sam]->SetBranchAddress("_mgluino", &_mgluino, &b__mgluino);
inputTree[sam]->SetBranchAddress("_mchi0", &_mchi0, &b__mchi0);
inputTree[sam]->SetBranchAddress("_nMajorana", &_nMajorana, &b__nMajorana);
inputTree[sam]->SetBranchAddress("_findMatched", &_findMatched, &b__findMatched);
    TH1D* _hCounter = new TH1D("hCounter", "Events counter", 5,0,5);
    _hCounter->Read("hCounter");
    hcounter[sam] = _hCounter->GetBinContent(1);
  }//end for on tree
    
  //******************* HISTO **********************
  const int nCat=6;
  const int nDist = 26;  //Number of distributions to plot
  TH1D* Histos[nDist][nCat][nSamples_eff +1];
  const TString catNames[nCat] ={"all_ossf", "low_ossf", "high_ossf", "all_n_ossf", "low_n_ossf", "high_n_ossf"};
  const TString Histnames_ossf[nDist] = { "LeptonPt_le","LeptonPt_subl" "LeptonPt_tr","Sum3Pt","Sum2Pt_lt","Sum2Pt_st","Sum2Pt_ls","Mlll","Mll","Mll_pair OSSF", "MET", "MT", "NJets", "NbJets","HT", "DeltaR_pair","DeltaR_lt","DeltaR_st","RelIso_l", "RelIso_t", "dxy_l", "dxy_t","dz_l", "dz_t","3dIP_l", "3dIP_t"};

  //const TString Histnames_n_ossf[nDist] = { "LeptonPt_le","LeptonPt_subl" "LeptonPt_tr","Sum3Pt","Sum2Pt_lt","Sum2Pt_st","Sum2Pt_ls","Mlll","Mll","Mll_pair NOSSF", "MET", "MT", "NJets", "NbJets","HT", "DeltaR","DeltaR_pair","DeltaR_lt","DeltaR_st","RelIso_l", "RelIso_t", "dxy_l", "dxy_t","dz_l", "dz_t","3dIP_l", "3dIP_t"};

  const TString Xaxes[nDist] = {"P_{T}(leading l) (GeV)","P_{T}(sub-leading l) (GeV)", "P_{T}(trailing l) (GeV)", "SumP_{T}(3leptons) (GeV)","SumP_{T}(leading+trailing) (GeV)","SumP_{T}(sub-leading+trailing) (GeV)","SumP_{T}(leading+sub-leading) (GeV)",
"M_{lll} (GeV)","M_{ll} (sub-leadinf+soft) (GeV)", "M_{ll} OSSF pair (GeV)", "MET (GeV)", "M_{T} (GeV)", "number of jets", "number of b-jets","HT (GeV)" , "#Delta R (OSSF pair)", "#Delta R (leading,trailing)", "#Delta R (sub-leading, trailing)", "relIso(leading)", "relIso(trailing)", "|d_{xy}(leading)| (cm)", "|d_{xy}(trailing)| (cm)", "|d_{z}(leading)| (cm)", "|d_{z}(trailing)| (cm)",  "|3DIP(leading)| (cm)","|3DIP(trailing)| (cm)"};

  const TString Units[nDist] = {"GeV", "GeV", "GeV", "GeV", "GeV","GeV","GeV","GeV","GeV","GeV","GeV","GeV", "", "", "GeV",  "", "", "",  "cm", "cm","cm", "cm", "cm", "cm","cm","cm"};

  const double HistMin[nDist] = { 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  const double HistMax[nDist] = {200, 200, 200, 200, 200,  200,  200,  200,  200,  200, 200, 100, 10,10, 100, 4,4,4,1,1,0.015,0.015, 0.015, 0.15, 0.8, 0.8};
  const int nBins[nDist] = {50, 50, 50, 50, 50, 50,50,50,50,50,50,20,10,10,20,25,25,25,50,50,50,20,20,20,20,20};
 
  for(int i = 0; i < nDist; ++i){
    float BinWidth = (HistMax[i] - HistMin[i])/nBins[i];
    std::ostringstream strs; strs << BinWidth; std::string Yaxis = strs.str();
    for(int effsam = 0; effsam < nSamples_eff + 1; ++effsam){
      for(int cat = 0; cat < nCat; ++cat){
	Histos[i][cat][effsam] = new TH1D(eff_names[effsam] + catNames[cat] + Histnames_ossf[i] , eff_names[effsam] + catNames[cat] + Histnames_ossf[i] + ";" + Xaxes[i] + "; events /" + Yaxis + Units[i], nBins[i], HistMin[i], HistMax[i]);
	Histos[i][cat][effsam]->Sumw2();
	
      }
    }
  }
  //Calculate the center of the maximum bin of each histogram
  double maxBinC[nDist];
  for(int i = 0; i < nDist; ++i){
    maxBinC[i] = Histos[0][0][i]->GetBinCenter(Histos[0][0][i]->GetNbinsX());
  }
  //Loop over all samples
  Double_t Counter[nSamples];
  for(int i = 0; i  < nSamples; ++i){
    Counter[i] = 0;
  }
  Double_t scale[nSamples];
  std::set<long> events;
  std::set<long> excess;
  //CHANGE 5 BACK to nsamples
  const double MVA_cuts_pt15[3] = {0.77, 0.56, 0.48};
  const double MVA_cuts_pt25[3] = {0.52, 0.11, -0.01};



  for(int sam = 0, effsam = 0; sam < nSamples; ++sam, ++effsam){
    Long64_t nEntries = inputTree[sam]->GetEntries();
    if(sam != 0){
      if(names[sam] == names[sam -1]) --effsam;
    }
    if(sam > 3){
      scale[sam -3] = xSections[sam -3]*luminosity*1000/(hcounter[sam]);
    }
	 
    scale[sam] = xSections[sam ]*luminosity/(hcounter[sam]);	  
    std::cout<<"Entries in "<< fileList[sam] <<" "<<nEntries<<std::endl;
    cout << effsam << endl;	
	  
    int index_pt_lead=0;
    double pt_lead=0;
    double max_pt=0;
    int index_pt_sublead=0;
    double pt_sublead=0;
    double max1_pt=0;
	  
    int testcounter = 0;
    for (Long64_t it = 0; it < nEntries; ++it){
      inputTree[sam]->GetEntry(it);
      if (it%10000 == 0) cout<<'.'<<flush;
      double scal = 0;
      if(effsam == 0) scal = 1;
      else{
	scal = scale[sam-3]*_weight; 
	//scal*= PUweights->GetBinContent(PUweights->FindBin(_n_trueInteractions));
      }
      if(effsam == 0){
	auto evit = events.find(_eventNb);
	if (evit != events.end()) continue;
	events.insert(_eventNb); 
      }


      std::vector<int> index_good_leptons;
      std::vector<int> index_electron_too_close;
      // ------------------------------------->  MVA SUSY
      // ------------------------------------->  ELECTRON CLEANING
      TLorentzVector muone;
      TLorentzVector elettrone;
      for(int i =0; i <_nLeptons; i++){  
	int eta = -1;
	if(TMath::Abs(_lEta[i]) < 0.8 ) {
	  eta = 0;
	} else if(TMath::Abs(_lEta[i]) < 1.479 ) {
	  eta = 1;
	} else{
	  eta = 2;
	}    
	_passedMVA90[i] = _mvaValue[i] >  std::min( MVA_cuts_pt15[eta], std::max(MVA_cuts_pt25[eta] , MVA_cuts_pt15[eta] + (MVA_cuts_pt25[eta] - MVA_cuts_pt15[eta])*0.1 *( _lPt[i]-15) ) );

	if (_flavors[i] == 0 ){
	  elettrone.SetPtEtaPhiE(0,0,0,0);
	  elettrone.SetPtEtaPhiE(_lPt[i], _lEta[i], _lPhi[i], _lE[i]);
	  for(int j =0; j <_nLeptons; j++){
	    if (_flavors[j] == 1 ){
	      muone.SetPtEtaPhiE(0,0,0,0);
	      muone.SetPtEtaPhiE(_lPt[j], _lEta[j], _lPhi[j], _lE[j]);
	      if (elettrone.DeltaR(muone) < 0.05) index_electron_too_close.push_back(i);
	    }//end muon
	  }//end loop j
	}// end electron
      }//end loop i
    
      // ------------------------------------->  EVENT SELECTION === 3LLL
      /* muons --> iso<0.4 + medium
	 electrons --> iso<0.4 + Loose MVA */
      for(int i =0; i <_nLeptons; i++){
	if(TMath::Abs(_ipPV[i]) > 0.05 || TMath::Abs(_ipZPV[i]) > 0.1 || _3dIPsig [i] > 4) continue;
	if (_flavors[i] == 1 && _ismedium[i] && _isolation[i] < 0.4) index_good_leptons.push_back(i);
	if (index_electron_too_close.size() !=0){
	  if (_flavors[i] ==0  && _lPt[i]* maximum( 1, _isolation[i] - 0.1) > 20){
	    if (_lEta[i] < 0.8 && _mvaValue[i] > -1 && _isolation[i] < 0.4) {
	      if (i != index_electron_too_close.at(0) )	index_good_leptons.push_back(i);
	    }//eta1
	    if ( (_lEta[i] > 0.8 && _lEta[i] < 1.479) && _mvaValue[i] > -1  && _isolation[i] < 0.4) {
	      if (i != index_electron_too_close.at(0) )	index_good_leptons.push_back(i);
	    }//eta2
	    if ( (_lEta[i] > 1.479 && _lEta[i] < 2.5) && _mvaValue[i] > -0.9  && _isolation[i] < 0.4) {
	      if (i != index_electron_too_close.at(0) )	index_good_leptons.push_back(i);
	    }//eta3
	  }//end only electron
	}//end index_electron_too_close.size() !=0
	    

	if (index_electron_too_close.size() ==0){
	  if (_flavors[i] ==0  && _lPt[i]* maximum( 1, _isolation[i] - 0.1) > 20){
	    if (_lEta[i] < 0.8 && _mvaValue[i] > -0.98  && _isolation[i] < 0.4) 	index_good_leptons.push_back(i);
	    if ( (_lEta[i] > 0.8 && _lEta[i] < 1.479) && _mvaValue[i] > -1  && _isolation[i] < 0.4)   index_good_leptons.push_back(i);
	    if ( (_lEta[i] > 1.479 && _lEta[i] < 2.5) && _mvaValue[i] > -0.81  && _isolation[i] < 0.4)  index_good_leptons.push_back(i);
	  }//end only electron
	}
      }
            if( index_good_leptons.size() != 3) continue; 
   

      //================= pT leading ==========================
      pt_lead=0;
      index_pt_lead=100;
      max_pt=0;
      for (int i = 0 ; i < _nLeptons ; i++){
	if (i != index_good_leptons.at(0) && i != index_good_leptons.at(1) && i != index_good_leptons.at(2)) continue;
	pt_lead = _lPt[i];
	if(max_pt < pt_lead) { //
	  max_pt= pt_lead;
	  index_pt_lead= i;
	}// end if
      }
      if (max_pt < 15 ) continue;
      //================= pT sub-leading ==========================
      pt_sublead=0;
      index_pt_sublead=100;
      max1_pt=0;
      for (int i = 0 ; i < _nLeptons ; i++){
	if (i != index_good_leptons.at(0) && i != index_good_leptons.at(1) && i != index_good_leptons.at(2)) continue;
	if (i == index_pt_lead) continue;
	pt_sublead = _lPt[i];
	if(max1_pt < pt_sublead) { //
	  max1_pt= pt_sublead;
	  index_pt_sublead= i;
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
      int o_lepton1=0;
      int o_lepton2=0;
      int o_lepton3=0;
      c_lepton1=0;
      c_lepton2=0;
      c_lepton3=0;
      o_lepton1=0;
      o_lepton2=0;
      o_lepton3=0;
      f_lepton1=0;
      f_lepton2=0;
      f_lepton3=0;
      //cout<<"++++++++++++++++++"<<endl;
      for (int i = 0 ; i < _nLeptons ; i++){ // loop over leptons
	if (i != index_good_leptons.at(0) && i != index_good_leptons.at(1) && i != index_good_leptons.at(2)) continue;
	/////////////////////////////////////////// lepton1
	if (i == index_pt_lead) {// lepton1
	  i_lepton1=i;
	  c_lepton1=_charges[i];
	  f_lepton1=_flavors[i];
	  o_lepton1=_originReduced[i];
	  lepton_reco[0]= *(TLorentzVector *)_leptonP4->At(i_lepton1);
	  lepton_gen[0]= *(TLorentzVector *)_leptonP4->At(i_lepton1);
               
	}//origin =0
            
	else if (i == index_pt_sublead) {// lepton2
	  i_lepton2=i;
	  c_lepton2=_charges[i];
	  f_lepton2=_flavors[i];
	  o_lepton2=_originReduced[i];
	  lepton_reco[1]= *(TLorentzVector *)_leptonP4->At(i_lepton2);
	  lepton_gen[1]= *(TLorentzVector *)_leptonP4->At(i_lepton2);
               
	}
	/////////////////////////////////////////// lepton2
	else {
	  i_lepton3=i;
	  c_lepton3=_charges[i];
	  f_lepton3=_flavors[i];
	  o_lepton3=_originReduced[i];
	  lepton_reco[2]= *(TLorentzVector *)_leptonP4->At(i_lepton3);
	  lepton_gen[2]= *(TLorentzVector *)_leptonP4->At(i_lepton3);
               
	}
      }//loop lepton   
  
      // ------------------------------------->  Jet cleaning + b-veto
      int veto_bjets=0;
      veto_bjets=0;
      std::vector<int> index_good_jets;
      TLorentzVector jetb_vec={0,0,0,0};
      for(int i =0; i <_n_Jets; i++){
	jetb_vec.SetPtEtaPhiE(0,0,0,0);
	jetb_vec.SetPtEtaPhiE(_jetPt[i],_jetEta[i],_jetPhi[i], _jetE[i]);
	if (lepton_reco[0].DeltaR( jetb_vec )<0.4)continue;
	if (lepton_reco[1].DeltaR( jetb_vec )<0.4)continue;
	if (lepton_reco[2].DeltaR( jetb_vec )<0.4)continue;
	index_good_jets.push_back(i);
	if (_csv[i] > 0.460) veto_bjets++;
      }
      //**************************
      if (veto_bjets !=0) continue;
      //**************************
      //================== event classification ========================
      int event_clas=-1;
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
      TLorentzVector pair1_rec;
      TLorentzVector pair2_rec;      
      if (event_clas  == 30){
	if ((f_lepton1 == 0 && f_lepton2 == 0 && f_lepton3 == 1) ) { // e e mu
	  pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	  if ((c_lepton1 + c_lepton2) == 0) event_clas = 3;              
	}
	if (f_lepton1 == 0 && f_lepton2 == 1 && f_lepton3 == 0) { // e mu e
	  pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	  if ((c_lepton1 + c_lepton3) == 0) event_clas = 3;
	}
	if (f_lepton1 == 1 && f_lepton2 == 0 && f_lepton3 == 0 ) { // mu e e
	  pair1_rec.SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	  if ((c_lepton2 + c_lepton3) == 0) event_clas = 3;
	}
      }
      if (event_clas  == 40){
	if ((f_lepton1 == 0 && f_lepton2 == 0 && f_lepton3 == 2) ) { // e e mu
	  pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	  if ((c_lepton1 + c_lepton2) == 0) event_clas = 4;
	}
	if (f_lepton1 == 0 && f_lepton2 == 2 && f_lepton3 == 0 ) { // e mu e
	  pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	  if ((c_lepton1 + c_lepton3) == 0) event_clas = 4;
	}
	if (f_lepton1 == 2 && f_lepton2 == 0 && f_lepton3 == 0) { // mu e e
	  pair1_rec.SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	  if  ((c_lepton2 + c_lepton3) == 0)event_clas = 4;
	}
      }
      if (event_clas  == 50){
	if ((f_lepton1 == 2 && f_lepton2 == 2 && f_lepton3 == 0) ) { // e e mu
	  pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	  if ((c_lepton1 + c_lepton2) == 0) event_clas = 5;
	}
	if (f_lepton1 == 2 && f_lepton2 == 0 && f_lepton3 == 2 ) { // e mu e
	  pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	  if ((c_lepton1 + c_lepton3) == 0) event_clas = 5;
	}
	if (f_lepton1 == 0 && f_lepton2 == 2 && f_lepton3 == 2 ) { // mu e e
	  pair1_rec.SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	  if  ((c_lepton2 + c_lepton3) == 0)event_clas = 5;
	}
      }
      if (event_clas  == 20){
	if ((f_lepton1 == 1 && f_lepton2 == 1 && f_lepton3 == 0) ) { // e e mu
	  pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	  if ((c_lepton1 + c_lepton2) == 0) event_clas = 2;
	}
	if (f_lepton1 == 1 && f_lepton2 == 0 && f_lepton3 == 1 ) { // e mu e
	  pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	  if ((c_lepton1 + c_lepton3) == 0) event_clas = 2;
	}
	if (f_lepton1 == 0 && f_lepton2 == 1 && f_lepton3 == 1 ) { // mu e e
	  pair1_rec.SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	  pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
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
	  }
	  if (index_inv == 1) {
	    pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	    pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	  }
	  if (index_inv == 2) {
	    pair1_rec.SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	    pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
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
	  }
	  if (index_inv_mu == 1) {
	    pair1_rec.SetPtEtaPhiE( lepton_reco[0].Pt(),  lepton_reco[0].Eta(), lepton_reco[0].Phi(), lepton_reco[0].E());
	    pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	  }
	  if (index_inv_mu == 2) {
	    pair1_rec.SetPtEtaPhiE( lepton_reco[1].Pt(),  lepton_reco[1].Eta(), lepton_reco[1].Phi(), lepton_reco[1].E());
	    pair2_rec .SetPtEtaPhiE( lepton_reco[2].Pt(),  lepton_reco[2].Eta(), lepton_reco[2].Phi(), lepton_reco[2].E());
	  }
	}
      }
      //**************************
      if (event_clas  == -1) continue;
      bool ossf_event= false;
      if (event_clas == 1 ||event_clas == 2 ||event_clas == 3 ||event_clas == 4 || event_clas == 5 || event_clas ==6) ossf_event = true;
      bool low_pt_event=false;
      bool high_pt_event = false;
      if (lepton_reco[0].Pt()< 30) low_pt_event= true;
      if (lepton_reco[0].Pt()> 30)  high_pt_event = true;
      //**************************
      // ------------------------------------->  Variable to fill the histo
      TLorentzVector sum_3l_rec;
      sum_3l_rec.SetPtEtaPhiE(0,0,0,0);
      sum_3l_rec= (lepton_reco[0]+ lepton_reco[1]+lepton_reco[2] );
      TLorentzVector sum_2l_rec;
      sum_2l_rec.SetPtEtaPhiE(0,0,0,0);
      sum_2l_rec= (lepton_reco[1]+lepton_reco[2]);
      TLorentzVector sum_2l_rec_pair;
      sum_2l_rec_pair.SetPtEtaPhiE(0,0,0,0);
      sum_2l_rec_pair= (pair1_rec+pair2_rec );
        
      // met and mT
      TLorentzVector lepton_transv[2];
      TLorentzVector METvec;
      double m_T=0;      
      lepton_transv[0].SetPtEtaPhiE(lepton_reco[1].Pt(),0, lepton_reco[1].Phi(), lepton_reco[1].Pt());
      lepton_transv[1].SetPtEtaPhiE(lepton_reco[2].Pt(),0, lepton_reco[2].Phi(), lepton_reco[2].Pt());
      METvec.SetPtEtaPhiE(_met, 0, _met_phi,_met);   
      m_T= (lepton_transv[0]+lepton_transv[1] + METvec).Mag();

      // ------------------------------------->  Fake estimation
      int number_ttt=0;
      int number_T_prompt=0;
      int number_L_prompt=0;
      for (int i = 0 ; i < _nLeptons ; i++){ // loop over lepton
	if (i != index_good_leptons.at(0) && i != index_good_leptons.at(1) && i != index_good_leptons.at(2)) continue;
	if (_flavors[i] == 1 && _isolation[i] < 0.1)   number_ttt++;
	if (_flavors[i] == 0 && _passedMVA90[i] && _isolation[i] < 0.1)   number_ttt++;
	if(effsam != 0) { // only MC
	  if (_flavors[i] == 1 && _isolation[i] < 0.1 && _originReduced[i] == 0)   number_T_prompt++;
	  if (_flavors[i] == 0 && _passedMVA90[i] && _isolation[i] < 0.1 && _originReduced[i] == 0) number_T_prompt++;
	  if (_flavors[i] == 1 && _isolation[i] > 0.1 && _originReduced[i] == 0)   number_L_prompt++;
	  if (_flavors[i] == 0 && !_passedMVA90[i] && _isolation[i] > 0.1 && _originReduced[i] == 0) number_L_prompt++;
	}
      }
      //   number_ttt  == 3 TTT
      //   number_ttt  == 2 TTL
      //   number_ttt  == 1 TLL
      //   number_ttt  == 0 LLL
      TLorentzVector lepton_1;
      TLorentzVector lepton_2;
      TLorentzVector lepton_3;
      lepton_1.SetPtEtaPhiE(0,0,0,0);
      lepton_2.SetPtEtaPhiE(0,0,0,0);
      lepton_3.SetPtEtaPhiE(0,0,0,0);
      int index_leptons[3]={-5,-5,-5};
      int flavor_leptons[3]={-5,-5,-5};
      int origin_leptons[3]={-5,-5,-5};
      if (number_ttt == 3) {    
	lepton_1.SetPtEtaPhiE(lepton_reco[0].Pt(),lepton_reco[0].Eta(),lepton_reco[0].Phi(),lepton_reco[0].E());
	lepton_2.SetPtEtaPhiE(lepton_reco[1].Pt(),lepton_reco[1].Eta(),lepton_reco[1].Phi(),lepton_reco[1].E());
	lepton_3.SetPtEtaPhiE(lepton_reco[2].Pt(),lepton_reco[2].Eta(),lepton_reco[2].Phi(),lepton_reco[2].E());
	index_leptons[0]=i_lepton1;
	index_leptons[1]=i_lepton2;
	index_leptons[2]=i_lepton3;
	flavor_leptons[0]=f_lepton1;
	flavor_leptons[1]=f_lepton2;
	flavor_leptons[2]=f_lepton3;
	origin_leptons[0]=o_lepton1;
	origin_leptons[1]=o_lepton2;
	origin_leptons[2]=o_lepton3;
      }
      if (number_ttt == 0) {
	lepton_1.SetPtEtaPhiE(lepton_reco[0].Pt(),lepton_reco[0].Eta(),lepton_reco[0].Phi(),lepton_reco[0].E());
	lepton_2.SetPtEtaPhiE(lepton_reco[1].Pt(),lepton_reco[1].Eta(),lepton_reco[1].Phi(),lepton_reco[1].E());
	lepton_3.SetPtEtaPhiE(lepton_reco[2].Pt(),lepton_reco[2].Eta(),lepton_reco[2].Phi(),lepton_reco[2].E());
	index_leptons[0]=i_lepton1;
	index_leptons[1]=i_lepton2;
	index_leptons[2]=i_lepton3;
	flavor_leptons[0]=f_lepton1;
	flavor_leptons[1]=f_lepton2;
	flavor_leptons[2]=f_lepton3;
	origin_leptons[0]=o_lepton1;
	origin_leptons[1]=o_lepton2;
	origin_leptons[2]=o_lepton3;
      }
      if (number_ttt == 2) {
	for (int i = 0 ; i < _nLeptons ; i++){
	  if (i != index_good_leptons.at(0) && i != index_good_leptons.at(1) && i != index_good_leptons.at(2)) continue;
	  if (index_leptons[0] ==-5 && ((_flavors[i] == 1 && _isolation[i] < 0.1) ||  (_flavors[i] == 0 && _passedMVA90[i] && _isolation[i] < 0.1))) {
	    lepton_1.SetPtEtaPhiE(_lPt[i],_lEta[i],_lPhi[i],_lE[i]);
	    index_leptons[0]= i;
	    flavor_leptons[0] = _flavors[i];
	    origin_leptons[0]=_originReduced[i];
	  }//end first tight      
	  if ((index_leptons[0] !=-5 && index_leptons[0] !=i && index_leptons[1] ==-5) && ((_flavors[i] == 1 && _isolation[i] < 0.1) ||  (_flavors[i] == 0 && _passedMVA90[i] && _isolation[i] < 0.1))) {
	    lepton_2.SetPtEtaPhiE(_lPt[i],_lEta[i],_lPhi[i],_lE[i]);
	    index_leptons[1]= i;
	    flavor_leptons[1] = _flavors[i];
	    origin_leptons[1]=_originReduced[i];
	  }//end second tight        
	  if (index_leptons[2] ==-5  && ( (_flavors[i] == 1 && !(_isolation[i] < 0.1)) ||  (_flavors[i] == 0 && (!_passedMVA90[i] || !(_isolation[i] < 0.1))))) {
	    lepton_3 .SetPtEtaPhiE(_lPt[i],_lEta[i],_lPhi[i],_lE[i]);
	    index_leptons[2]= i;
	    flavor_leptons[2] = _flavors[i];
	    origin_leptons[2]=_originReduced[i];
	  }//end loose
	}//loop lepton
      }// ==2
      if (number_ttt == 1) {
	for (int i = 0 ; i < _nLeptons ; i++){
	  if (i != index_good_leptons.at(0) && i != index_good_leptons.at(1) && i != index_good_leptons.at(2)) continue;
	  if (index_leptons[0] ==-5 && ((_flavors[i] == 1 && _isolation[i] < 0.1) ||  (_flavors[i] == 0 && _passedMVA90[i] && _isolation[i] < 0.1))) {
	    lepton_1.SetPtEtaPhiE(_lPt[i],_lEta[i],_lPhi[i],_lE[i]);
	    index_leptons[0]= i;
	    flavor_leptons[0] = _flavors[i];
	  }//end first tight      
	  if (index_leptons[1] ==-5 &&( (_flavors[i] == 1 && !(_isolation[i] < 0.1)) ||  (_flavors[i] == 0 && (!_passedMVA90[i] || !(_isolation[i] < 0.1)))) ){
	    lepton_2.SetPtEtaPhiE(_lPt[i],_lEta[i],_lPhi[i],_lE[i]);
	    index_leptons[1]= i;
	    flavor_leptons[1] = _flavors[i];
	  }//end first loose
        
	  if ((index_leptons[1] !=-5 && index_leptons[1] !=i && index_leptons[2] ==-5)  &&( (_flavors[i] == 1 && !(_isolation[i] < 0.1)) ||  (_flavors[i] == 0 && (!_passedMVA90[i] || !(_isolation[i] < 0.1))))) {
	    lepton_2.SetPtEtaPhiE(_lPt[i],_lEta[i],_lPhi[i],_lE[i]);
	    index_leptons[2]= i;
	    flavor_leptons[2] = _flavors[i];
	  }//end second loose
	}//loop lepton     
      }// ==1
      double fattore_fr=1;

      // MC
      if(effsam != 0) {
	if (number_T_prompt == 3) scal = scal;
	if (number_T_prompt == 2 && number_L_prompt == 1 && number_ttt == 2){
	  fattore_fr = -  FR_factor (*&fakeRate_mu, *&fakeRate_e ,lepton_3, flavor_leptons[2], _isolation[index_leptons[2]]);
	  scal = scal *fattore_fr;
	}
      }//end MC
      //data for FR
      bool data_control_region=false;
      if(effsam == 0 && (number_ttt == 0 || number_ttt == 2 || number_ttt == 1))  data_control_region=true;

      if(effsam == 0) {// data
	if (number_ttt == 0) fattore_fr = FR_factor (*&fakeRate_mu, *&fakeRate_e, lepton_1, flavor_leptons[0], _isolation[index_leptons[0]]) * FR_factor (*&fakeRate_mu, *&fakeRate_e, lepton_2, flavor_leptons[1], _isolation[index_leptons[1]]) * FR_factor (*&fakeRate_mu, *&fakeRate_e, lepton_3, flavor_leptons[2], _isolation[index_leptons[2]]);
	if (number_ttt == 1) fattore_fr = - FR_factor (*&fakeRate_mu, *&fakeRate_e, lepton_2, flavor_leptons[1], _isolation[index_leptons[1]]) * FR_factor (*&fakeRate_mu, *&fakeRate_e, lepton_3, flavor_leptons[2], _isolation[index_leptons[2]]);
	if (number_ttt == 2) fattore_fr =  FR_factor (*&fakeRate_mu, *&fakeRate_e ,lepton_3, flavor_leptons[2], _isolation[index_leptons[2]]);	      
	scal = scal* fattore_fr;
      }//data


	    
      double pt_cone_leading=lepton_reco[0].Pt() * maximum( 1, _isolation[index_leptons[0]] - 0.1);
      double pt_cone_sub_leading=lepton_reco[1].Pt() * maximum( 1, _isolation[index_leptons[1]] - 0.1);
      double pt_cone_trailing=lepton_reco[2].Pt() * maximum( 1, _isolation[index_leptons[2]] - 0.1);

      double values[nDist] = { pt_cone_leading, pt_cone_sub_leading, pt_cone_trailing,
			       pt_cone_leading+ pt_cone_sub_leading+ pt_cone_trailing,
			       pt_cone_leading+ pt_cone_trailing,
			       pt_cone_sub_leading+ pt_cone_trailing,
			       pt_cone_leading+ pt_cone_sub_leading,
			       sum_3l_rec.M(),sum_2l_rec.M(),sum_2l_rec_pair.M(),
			       _met,m_T,
			       static_cast<double>(_n_Jets), static_cast<double>(_n_bJets),HT,
			       pair1_rec.DeltaR(pair2_rec),lepton_reco[0].DeltaR(lepton_reco[2]),lepton_reco[1].DeltaR(lepton_reco[2]),
			       _isolation[index_leptons[0]],_isolation[index_leptons[2]],
			       fabs(_ipPV[index_leptons[0]]),fabs(_ipPV[index_leptons[2]]),
			       fabs(_ipZPV[index_leptons[0]]),fabs(_ipZPV[index_leptons[2]]),
			       fabs(_3dIP[index_leptons[0]]), fabs(_3dIP[index_leptons[2]])};

      unsigned fill = effsam;
      if(data_control_region ) fill = nSamples_eff;


      //************************** OSSF ***********************************
      if(ossf_event){
	for(int i = 0; i < nDist; ++i){
	  Histos[i][0][fill]->Fill(TMath::Min(values[i], maxBinC[i]), scal);
	  if (low_pt_event)Histos[i][1][fill]->Fill(TMath::Min(values[i], maxBinC[i]), scal);       
	  if (high_pt_event) Histos[i][2][fill]->Fill(TMath::Min(values[i], maxBinC[i]), scal);
	}//end for
      }//end ossf
      //************************** NOSSF ***********************************
      if(!ossf_event){
	for(int i = 0; i < nDist; ++i){
	  Histos[i][3][fill]->Fill(TMath::Min(values[i], maxBinC[i]), scal);
	  if (low_pt_event)Histos[i][4][fill]->Fill(TMath::Min(values[i], maxBinC[i]), scal);       
	  if (high_pt_event) Histos[i][5][fill]->Fill(TMath::Min(values[i], maxBinC[i]), scal);
	}//end for
      }//end n_ossf

	 
    }

  }


 

  /*THStack* stack_all_ossf[nDist];
    THStack* stack_all_n_ossf[nDist];
    THStack* stack_ossf_low[nDist];
    THStack* stack_n_ossf_low[nDist];
    THStack* stack_ossf_high[nDist];
    THStack* stack_n_ossf_high[nDist];
    for(int i = 0; i < nDist; ++i){
    stack_all_ossf[i] = new THStack("stack_all_ossf" + Histnames[i], "stack_all_ossf" + Histnames[i]);
    stack_ossf_low[i] = new THStack("stack_ossf_low" + Histnames[i], "stack_ossf_low" + Histnames[i]);
    stack_ossf_high[i] = new THStack("stack_ossf_high" + Histnames[i], "stack_ossf_high" + Histnames[i]);
    tack_all_n_ossf[i] = new THStack("stack_all_n_ossf" + Histnames[i], "stack_all_n_ossf" + Histnames[i]);
    stack_n_ossf_low[i] = new THStack("stack_n_ossf_low" + Histnames[i], "stack_n_ossf_low" + Histnames[i]);
    stack_n_ossf_high[i] = new THStack("stack_n_ossf_high" + Histnames[i], "stack_n_ossf_high" + Histnames[i]);
    
    for(int effsam = 1; effsam < nSamples_eff ; ++effsam){
    //if (effsam == 1 || effsam == 2 || effsam== 3) continue;
    StackCol(Histos_all_ossf[effsam][i], colors[nSamples_eff - effsam -1]);
    stack_all_ossf[i]->Add(Histos_all_ossf[effsam][i], "f");
    StackCol(Histos_ossf_low[effsam][i], colors[nSamples_eff - effsam -1]);
    stack_ossf_low[i]->Add(Histos_ossf_low[effsam][i], "f");
    StackCol(Histos_ossf_high[effsam][i], colors[nSamples_eff - effsam -1]);
    stack_ossf_high[i]->Add(Histos_ossf_high[effsam][i], "f");
    StackCol(Histos_all_n_ossf[effsam][i], colors[nSamples_eff - effsam -1]);
    stack_all_n_ossf[i]->Add(Histos_all_n_ossf[effsam][i], "f");
    StackCol(Histos_n_ossf_low[effsam][i], colors[nSamples_eff - effsam -1]);
    stack_n_ossf_low[i]->Add(Histos_n_ossf_low[effsam][i], "f");
    StackCol(Histos_n_ossf_high[effsam][i], colors[nSamples_eff - effsam -1]);
    stack_n_ossf_high[i]->Add(Histos_n_ossf_high[effsam][i], "f");
    }
    }
		
	
    TLegend *MT_MC_Legend_all_ossf = new TLegend(0.65,0.40,0.95,0.9,NULL,"brNDC");
    MT_MC_Legend_all_ossf->SetFillStyle(0);
    MT_MC_Legend_all_ossf->AddEntry(Histos_all_ossf[0][0],eff_names[0]);
    for(int effsam = nSamples_eff - 1; effsam > 0; --effsam){
    MT_MC_Legend_all_ossf->AddEntry(Histos_all_ossf[effsam][0],eff_names[effsam]);
    }
    TLegend *MT_MC_Legend_ossf_low = new TLegend(0.65,0.40,0.95,0.9,NULL,"brNDC");
    MT_MC_Legend_ossf_low->SetFillStyle(0);
    MT_MC_Legend_ossf_low->AddEntry(Histos_ossf_low[0][0],eff_names[0]);
    for(int effsam = nSamples_eff - 1; effsam > 0; --effsam){
    MT_MC_Legend_ossf_low->AddEntry(Histos_ossf_low[effsam][0],eff_names[effsam]);
    }
    TLegend *MT_MC_Legend_ossf_high = new TLegend(0.65,0.40,0.95,0.9,NULL,"brNDC");
    MT_MC_Legend_ossf_high->SetFillStyle(0);
    MT_MC_Legend_ossf_high->AddEntry(Histos_ossf_high[0][0],eff_names[0]);
    for(int effsam = nSamples_eff - 1; effsam > 0; --effsam){
    MT_MC_Legend_ossf_high->AddEntry(Histos_ossf_high[effsam][0],eff_names[effsam]);
    }
    TLegend *MT_MC_Legend_all_n_ossf = new TLegend(0.65,0.40,0.95,0.9,NULL,"brNDC");
    MT_MC_Legend_all_n_ossf->SetFillStyle(0);
    MT_MC_Legend_all_n_ossf->AddEntry(Histos_all_n_ossf[0][0],eff_names[0]);
    for(int effsam = nSamples_eff - 1; effsam > 0; --effsam){
    MT_MC_Legend_all_n_ossf->AddEntry(Histos_all_n_ossf[effsam][0],eff_names[effsam]);
    }
    TLegend *MT_MC_Legend_n_ossf_low = new TLegend(0.65,0.40,0.95,0.9,NULL,"brNDC");
    MT_MC_Legend_n_ossf_low->SetFillStyle(0);
    MT_MC_Legend_n_ossf_low->AddEntry(Histos_n_ossf_low[0][0],eff_names[0]);
    for(int effsam = nSamples_eff - 1; effsam > 0; --effsam){
    MT_MC_Legend_n_ossf_low->AddEntry(Histos_n_ossf_low[effsam][0],eff_names[effsam]);
    }
    TLegend *MT_MC_Legend_n_ossf_high = new TLegend(0.65,0.40,0.95,0.9,NULL,"brNDC");
    MT_MC_Legend_n_ossf_high->SetFillStyle(0);
    MT_MC_Legend_n_ossf_high->AddEntry(Histos_n_ossf_high[0][0],eff_names[0]);
    for(int effsam = nSamples_eff - 1; effsam > 0; --effsam){
    MT_MC_Legend_n_ossf_high->AddEntry(Histos_n_ossf_high[effsam][0],eff_names[effsam]);
    }
  */

  //Split data and MC histograms for plotting and propagating uncertainties
  TH1D* dataYields[nDist][nCat];
  for(unsigned dist = 0; dist < nDist; ++dist){
    for(unsigned cat = 0; cat < nCat; ++cat){
      dataYields[dist][cat] = (TH1D*) Histos[dist][cat][2]->Clone();
    }
  }
  TH1D* bkgYields[nDist][nCat][nSamples_eff -1]; //change to nSamples_eff if sig is removed
  for(unsigned dist = 0; dist < nDist; ++dist){
    for(unsigned cat = 0; cat < nCat; ++cat){
      for(unsigned effsam = 2; effsam < nSamples_eff + 1; ++effsam){
	bkgYields[dist][cat][effsam -2] = (TH1D*) Histos[dist][cat][effsam]->Clone();
	if(effsam > 2){
	  dataYields[dist][cat]->Add(bkgYields[dist][cat][effsam -2]);
	}
      }
    }
  }
  const TString sigNames[1] = {"m_{N} = 40 |V|^{2} = 10^{-5}"};
  TH1D* signals[1];
  //Plot the yields as a function of the search region
  for(unsigned dist = 0; dist < nDist; ++dist){
    for(unsigned cat = 0; cat < nCat; ++cat){
      signals[0] = (TH1D*) Histos[cat][1][dist]->Clone() ;
      plotDataVSMC(dataYields[dist][cat], bkgYields[dist][cat], eff_names, nSamples_eff - 1, Histnames_ossf[dist] + "_" +  catNames[cat], false, 0, true, signals,  sigNames ,1);
    }
  }



 
}// end analisi






//==================================================================
double Analysis_mc::maximum(double a, double b){
  double massimo=0;
  massimo = a;
  if (massimo < b) massimo = b; 
  return massimo; 
}

//___________________________________________________________________

void Analysis_mc::from_TGraph_to_TH1D (TGraphAsymmErrors *graph, TH1D *histo, int number_point){

  const int numero= number_point;

  double x_graph[numero];
  double y_graph[numero];  
  for (int i =0; i <number_point; i ++){
    x_graph[i]=0;
    y_graph[i]=0;
  }
  for (int i =0; i <number_point; i ++){
    graph -> GetPoint(i, x_graph[i], y_graph[i]);
    histo->SetBinContent (i+1, x_graph[i],  y_graph[i]);

    //cout<<i<<") "<<y_graph[i]<<"  "<< histo->GetBinContent (i+1)<<endl;

  }
}

//==================================================================
double Analysis_mc::FR_factor(TGraphAsymmErrors *fakeRate_mu[3],
			      TGraphAsymmErrors *fakeRate_e[3],
			      TLorentzVector part,
			      Int_t flavors,
			      double iso
			      ){
  TH1D *fakeRate_mu_histo[3];
  TH1D *fakeRate_e_histo[3];  
  Double_t newBins_mu1[7] = {5,10, 15, 25, 35, 50, 70};
  Double_t newBins_e1[6] = {10, 15, 25, 35, 50, 70};
  fakeRate_mu_histo[0]= new TH1D("fake_rate_mu_histo_eta1","",6,newBins_mu1);
  fakeRate_mu_histo[1]= new TH1D("fake_rate_mu_histo_eta2","",6,newBins_mu1);
  fakeRate_mu_histo[2]= new TH1D("fake_rate_mu_histo_eta3","",6,newBins_mu1);
  fakeRate_e_histo[0]= new TH1D("fake_rate_e_histo_eta1","",5,newBins_e1);
  fakeRate_e_histo[1]= new TH1D("fake_rate_e_histo_eta2","",5,newBins_e1);
  fakeRate_e_histo[2]= new TH1D("fake_rate_e_histo_eta3","",5,newBins_e1);

  for (int i=0; i< 3; i++){
    from_TGraph_to_TH1D(*&fakeRate_mu[i],*&fakeRate_mu_histo[i],6);
    from_TGraph_to_TH1D(*&fakeRate_e[i],*&fakeRate_e_histo[i],5);    
  }

  double momentum = part.Pt() * maximum( 1, iso - 0.1);


  double factor=0;
  double factore=0;
  if (flavors == 0){
    if (momentum < 70){
      if (part.Eta() < 0.8){
	factore = fakeRate_e_histo[0]->GetBinContent(fakeRate_e_histo[0]->FindBin(momentum));
      }//eta1
      else if (part.Eta() > 0.8 && part.Eta()<1.479){
	factore = fakeRate_e_histo[1]->GetBinContent(fakeRate_e_histo[1]->FindBin(momentum));
      }//eta1
      else {
	factore = fakeRate_e_histo[2]->GetBinContent(fakeRate_e_histo[2]->FindBin(momentum));
      }//eta1
    }// <70
    else {
      if (part.Eta() < 0.8){
	factore = fakeRate_e_histo[0]->GetBinContent(fakeRate_e_histo[0]->FindBin(68));
      }//eta1
      else if (part.Eta() > 0.8 && part.Eta()<1.479){
	factore = fakeRate_e_histo[1]->GetBinContent(fakeRate_e_histo[1]->FindBin(68));
      }//eta1
      else {
	factore = fakeRate_e_histo[2]->GetBinContent(fakeRate_e_histo[2]->FindBin(68));
      }//eta1
    }
  }//e

  if (flavors == 1){
    if (momentum < 70){
      if (part.Eta() < 0.8){
	factore = fakeRate_mu_histo[0]->GetBinContent(fakeRate_mu_histo[0]->FindBin(momentum));
      }//eta1
      else if (part.Eta() > 0.8 && part.Eta()<1.479){
	factore = fakeRate_mu_histo[1]->GetBinContent(fakeRate_mu_histo[1]->FindBin(momentum));
      }//eta1
      else {
	factore = fakeRate_mu_histo[2]->GetBinContent(fakeRate_mu_histo[2]->FindBin(momentum));
      }//eta1
    }// <70
    else {
      if (part.Eta() < 0.8){
	factore = fakeRate_mu_histo[0]->GetBinContent(fakeRate_mu_histo[0]->FindBin(68));
      }//eta1
      else if (part.Eta() > 0.8 && part.Eta()<1.479){
	factore = fakeRate_mu_histo[1]->GetBinContent(fakeRate_mu_histo[1]->FindBin(68));
      }//eta1
      else {
	factore = fakeRate_mu_histo[2]->GetBinContent(fakeRate_mu_histo[2]->FindBin(68));
      }//eta1
    }
  }//e

  delete fakeRate_mu_histo[0];
  delete fakeRate_mu_histo[1];
  delete fakeRate_mu_histo[2];
  delete fakeRate_e_histo[0];
  delete fakeRate_e_histo[1];
  delete fakeRate_e_histo[2];


  factor = factore/(1-factore);
  return factor;

}
