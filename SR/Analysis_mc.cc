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
#include <tuple>
#include <set>



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
 
  TFile hfile1("/Users/Martina/Desktop/CMS/map_FR/fake_rate_e.root");
  fakeRate_e[0] = (TGraphAsymmErrors*)hfile1.Get("fakeRate_e_eta1");
  fakeRate_e[1] = (TGraphAsymmErrors*)hfile1.Get("fakeRate_e_eta2");
  fakeRate_e[2] = (TGraphAsymmErrors*)hfile1.Get("fakeRate_e_eta3");



  //, "DoubleEG.root " ,"DoubleMuon.root " , "MuonEG.root " ,

   const int nSamples= 25;
  const int nSamples_eff = 8;
   
  const TString fileList[nSamples] = {"SingleMuon.root " ,"SingleElectron.root " , "DoubleEG.root " ,"DoubleMuon.root " , "MuonEG.root " ,
				      "majo_40.root",

				      "WZTo3LNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1.root " ,

				      "ZZTo4L_13TeV_powheg_pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1.root " ,

				      "ZGTo2LG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1.root " ,
				      "WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1.root " ,
				      "TGJets_TuneCUETP8M1_13TeV_amcatnlo_madspin_pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV.root " ,

				      "ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1.root " ,
				      "WWG_TuneCUETP8M1_13TeV-amcatnlo-pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1.root " ,
				      "WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1.root " ,
				      "WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1.root " ,
				      "WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1.root " ,


				      "TTGJets_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV.root " ,
				      "TTTT_TuneCUETP8M1_13TeV-amcatnlo-pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1.root " ,
				      "TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV.root " ,
				      "TTZToLLNuNu_M-10_TuneCUETP8M1_13TeV-amcatnlo-pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1.root " ,
				     
				      "tZq_ll_4f_13TeV-amcatnlo-pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1.root " ,
				      "ST_tWll_5f_LO_13TeV-MadGraph-pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1.root " ,		
				      "VHToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1.root " ,
				      "ttHToNonbb_M125_TuneCUETP8M2_ttHtranche3_13TeV-powheg-pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1.root ",
				      "GluGluHToZZTo4L_M125_13TeV_powheg2_JHUgenV6_pythia8_crab_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1.root " };






  // "GluGluHToZZTo4L_M125_13TeV_powheg2_JHUgenV6_pythia8.root"};
  const TString names[nSamples] = {"data","data","data","data","data",
				   "Majorana1",
				   "WZ",
				   
				   "ZZ",

				   "X+gamma",
				   "X+gamma",
				   "X+gamma",
				   

				   "triboson",
				   "triboson",
				   "triboson",
				   "triboson",
				   "triboson",

				   "TT+X",
				   "TT+X",
				   "TT+X", 
				   "TT+X",
				   

				   "T/H + X",
				   "T/H + X",
				   "T/H + X",
				   "T/H + X",
				   "T/H + X"};

  const TString eff_names[nSamples_eff +1] = {"data","Majorana1", "WZ","ZZ", "X+gamma", "triboson", "TT+X", "T/H + X", "no-prompt"};
  const double xSections[nSamples-5]= {0.04892,

				       4.42965,

				       1.256,

				       123.9,
				       405.271,
				       2.967,

				       0.01398,
				       0.2147 ,
				       0.2086 ,
				       0.1651,
				       0.05565,

				       3.697,
				       0.009103,
				       0.2043,
				       0.2529,

				       0.0758,
				       0.01123,
				       0.952,
				       0.2151,
				       0.01181};
				     
  //0.01212};
  double luminosity = 36.814;

  TFile *hfile[nSamples];
  TTree *inputTree[nSamples];
  //TApplication* rootapp = new TApplication("example",&argc, argv);


  // Declaration of leaf types
  ULong64_t       _eventNb=0;
  ULong64_t       _runNb=0;
  ULong64_t       _lumiBlock=0;
  Int_t _nLeptons;
  _nLeptons = 5;
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
  Int_t           _nEle;
  Int_t           _nMu;
  Int_t           _nTau;
  Int_t           _flavors[_nLeptons];   //[_nLeptons]
  Double_t        _charges[_nLeptons];   //[_nLeptons]
  Double_t        _isolation[_nLeptons];   //[_nLeptons]
  Double_t        _isolation_absolute[_nLeptons];   //[_nLeptons]
  Double_t        _miniisolation[_nLeptons];   //[_nLeptons]
  Double_t        _miniisolationCharged[_nLeptons];   //[_nLeptons]
  Double_t        _ptrel[_nLeptons];   //[_nLeptons]
  Double_t        _ptratio[_nLeptons];   //[_nLeptons]
  Double_t        _muonSegmentComp[_nLeptons];   //[_nLeptons]
  Double_t        _mll[3];
  Int_t           _origin[_nLeptons];   //[_nLeptons]
  Int_t           _originReduced[_nLeptons];   //[_nLeptons]
  Bool_t          _isPromptFinalState[_nLeptons];   //[_nLeptons]
  Bool_t          _fromHardProcessFinalState[_nLeptons];   //[_nLeptons]
  Double_t        _PVchi2;
  Double_t        _PVerr[3];
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
  Bool_t          _ismedium[_nLeptons];   //[_nLeptons]
  Bool_t          _istight[_nLeptons];   //[_nLeptons]
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
  Int_t           _n_PV;
  Double_t        _n_MCTruth_PV;
  Double_t        _met;
  Double_t        _met_phi;
  Double_t        HT;
  Double_t        _genmet;
  Double_t        _genmet_phi;
  Double_t        _genqpt;
  Double_t        _genqpt20;
  Double_t        _mompt[_nLeptons];   //[_nLeptons]
  Double_t        _momphi[_nLeptons];   //[_nLeptons]
  Double_t        _mometa[_nLeptons];   //[_nLeptons]
  Int_t           _mompdg[_nLeptons];   //[_nLeptons]
  Int_t           _n_bJets;
  Int_t           _n_Jets;
  _n_Jets = 10;
  Bool_t          _bTagged[_n_Jets];   //[_n_Jets]
  Double_t        _jetEta[_n_Jets];   //[_n_Jets]
  Double_t        _jetPhi[_n_Jets];   //[_n_Jets]
  Double_t        _jetPt[_n_Jets];   //[_n_Jets]
  Int_t           _jetFlavour[_n_Jets];   //[_n_Jets]
  Double_t        _jetE[_n_Jets];   //[_n_Jets]
  Double_t        _csv[_n_Jets];   //[_n_Jets]
  Int_t           _clean[_n_Jets];   //[_n_Jets]
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
  Double_t        _weight;
  Double_t        _LHEweight[111];
  Double_t        _LHEweightID[111];
  Double_t        _mgluino;
  Double_t        _mchi0;
  Int_t           _nMajorana;
  Int_t           _findMatched;
  Bool_t          HLT_TripleMu_12_10_5;
  Int_t           HLT_TripleMu_12_10_5_prescale;
  Bool_t          HLT_DiMu9_Ele9_CaloIdL_TrackIdL;
  Int_t           HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale;
  Bool_t          HLT_Mu8_DiEle12_CaloIdL_TrackIdL;
  Int_t           HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale;
  Bool_t          HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;
  Int_t           HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale;
  Bool_t          HLT_TripleMu_5_3_3_DZ_Mass3p8;
  Int_t           HLT_TripleMu_5_3_3_DZ_Mass3p8_prescale;
  Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;
  Int_t           HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale;
  Bool_t          HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ;
  Int_t           HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale;
  Bool_t          HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ;
  Int_t           HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale;
  Bool_t          HLT_Mu30_TkMu11;
  Int_t           HLT_Mu30_TkMu11_prescale;
  Bool_t          HLT_Mu40_TkMu11;
  Int_t           HLT_Mu40_TkMu11_prescale;
  Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;
  Int_t           HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale;
  Bool_t          HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL;
  Int_t           HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale;
  Bool_t          HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL;
  Int_t           HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale;
  Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
  Int_t           HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale;
  Bool_t          HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
  Int_t           HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale;
  Bool_t          HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ;
  Int_t           HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_prescale;
  Bool_t          HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL;
  Int_t           HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_prescale;
  Bool_t          HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL;
  Int_t           HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_prescale;
  Bool_t          HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
  Int_t           HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale;
  Bool_t          HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf;
  Int_t           HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_prescale;
  Bool_t          HLT_DoubleEle33_CaloIdL_GsfTrkIdVL;
  Int_t           HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_prescale;
  Bool_t          HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;
  Int_t           HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_prescale;
  Bool_t          HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL;
  Int_t           HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_prescale;
  Bool_t          HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
  Int_t           HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale;
  Bool_t          HLT_Mu50;
  Int_t           HLT_Mu50_prescale;
  Bool_t          HLT_TkMu50;
  Int_t           HLT_TkMu50_prescale;
  Bool_t          HLT_IsoMu27;
  Int_t           HLT_IsoMu27_prescale;
  Bool_t          HLT_IsoTkMu27;
  Int_t           HLT_IsoTkMu27_prescale;
  Bool_t          HLT_IsoMu24;
  Int_t           HLT_IsoMu24_prescale;
  Bool_t          HLT_IsoTkMu24;
  Int_t           HLT_IsoTkMu24_prescale;
  Bool_t          HLT_IsoMu24_eta2p1;
  Int_t           HLT_IsoMu24_eta2p1_prescale;
  Bool_t          HLT_IsoTkMu24_eta2p1;
  Int_t           HLT_IsoTkMu24_eta2p1_prescale;
  Bool_t          HLT_IsoMu22_eta2p1;
  Int_t           HLT_IsoMu22_eta2p1_prescale;
  Bool_t          HLT_IsoTkMu22_eta2p1;
  Int_t           HLT_IsoTkMu22_eta2p1_prescale;
  Bool_t          HLT_IsoTkMu22;
  Int_t           HLT_IsoTkMu22_prescale;
  Bool_t          HLT_Mu45_eta2p1;
  Int_t           HLT_Mu45_eta2p1_prescale;
  Bool_t          HLT_Ele32_WPTight_Gsf;
  Int_t           HLT_Ele32_WPTight_Gsf_prescale;
  Bool_t          HLT_Ele32_eta2p1_WPTight_Gsf;
  Int_t           HLT_Ele32_eta2p1_WPTight_Gsf_prescale;
  Bool_t          HLT_Ele30_WPTight_Gsf;
  Int_t           HLT_Ele30_WPTight_Gsf_prescale;
  Bool_t          HLT_Ele30_eta2p1_WPTight_Gsf;
  Int_t           HLT_Ele30_eta2p1_WPTight_Gsf_prescale;
  Bool_t          HLT_Ele27_WPTight_Gsf;
  Int_t           HLT_Ele27_WPTight_Gsf_prescale;
  Bool_t          HLT_Ele27_eta2p1_WPTight_Gsf;
  Int_t           HLT_Ele27_eta2p1_WPTight_Gsf_prescale;
  Bool_t          HLT_Ele27_eta2p1_WPLoose_Gsf;
  Int_t           HLT_Ele27_eta2p1_WPLoose_Gsf_prescale;
  Bool_t          HLT_Ele25_eta2p1_WPTight_Gsf;
  Int_t           HLT_Ele25_eta2p1_WPTight_Gsf_prescale;
  Bool_t          HLT_Ele25_WPTight_Gsf;
  Int_t           HLT_Ele25_WPTight_Gsf_prescale;
  Bool_t          HLT_Ele8_CaloIdM_TrackIdM_PFJet30;
  Int_t           HLT_Ele8_CaloIdM_TrackIdM_PFJet30_prescale;
  Bool_t          HLT_Ele12_CaloIdM_TrackIdM_PFJet30;
  Int_t           HLT_Ele12_CaloIdM_TrackIdM_PFJet30_prescale;
  Bool_t          HLT_Ele8_CaloIdM_TrackIdM_IsoVL_PFJet30;
  Int_t           HLT_Ele8_CaloIdM_TrackIdM_IsoVL_PFJet30_prescale;
  Bool_t          HLT_Ele12_CaloIdM_TrackIdM_IsoVL_PFJet30;
  Int_t           HLT_Ele12_CaloIdM_TrackIdM_IsoVL_PFJet30_prescale;
  Bool_t          HLT_Mu8_TrkIsoVVL_v;
  Int_t           HLT_Mu8_TrkIsoVVL_v_prescale;
  Bool_t          HLT_Mu17_TrkIsoVVL_v;
  Int_t           HLT_Mu17_TrkIsoVVL_v_prescale;
  Bool_t          HLT_Mu24_TrkIsoVVL_v;
  Int_t           HLT_Mu24_TrkIsoVVL_v_prescale;
  Bool_t          HLT_Mu34_TrkIsoVVL_v;
  Int_t           HLT_Mu34_TrkIsoVVL_v_prescale;
  Bool_t          HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v;
  Int_t           HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v_prescale;
  Bool_t          HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v;
  Int_t           HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v_prescale;
  Bool_t          HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v;
  Int_t           HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v_prescale;
  Bool_t          HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v;
  Int_t           HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v_prescale;
  Bool_t          HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v;
  Int_t           HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v_prescale;
  Bool_t          HLT_Mu3_PFJet40_v;
  Int_t           HLT_Mu3_PFJet40_v_prescale;
  Bool_t          HLT_Mu8_v;
  Int_t           HLT_Mu8_v_prescale;
  Bool_t          HLT_Mu17_v;
  Int_t           HLT_Mu17_v_prescale;
  Bool_t          HLT_Mu24_v;
  Int_t           HLT_Mu24_v_prescale;
  Bool_t          HLT_Mu34_v;
  Int_t           HLT_Mu34_v_prescale;
  Bool_t          HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v;
  Int_t           HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale;
  Bool_t          HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v;
  Int_t           HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale;
  Bool_t          HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v;
  Int_t           HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale;
  Bool_t          HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v;
  Int_t           HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale;
  Bool_t          HLT_Ele12_CaloIdL_TrkIdL_IsoVL_v;
  Int_t           HLT_Ele12_CaloIdL_TrkIdL_IsoVL_v_prescale;
  Bool_t          HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v;
  Int_t           HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v_prescale;
  Bool_t          HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v;
  Int_t           HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v_prescale;




  Bool_t          Flag_HBHENoiseFilter;
  Bool_t          Flag_HBHENoiseIsoFilter;
  Bool_t          Flag_EcalDeadCellTriggerPrimitiveFilter;
  Bool_t          Flag_goodVertices;
  Bool_t          Flag_eeBadScFilter;
  Bool_t          Flag_globalTightHalo2016Filter;
  Int_t           _gen_nL;
  Double_t        _gen_lPt[21];   //[_gen_nL]
  Double_t        _gen_lE[21];   //[_gen_nL]
  Double_t        _gen_lEta[21];   //[_gen_nL]
  Double_t        _gen_lPhi[21];   //[_gen_nL]
  Int_t           _gen_lmompdg[21];   //[_gen_nL]
  Double_t        _gen_charges[21];   //[_gen_nL]
  Int_t           _gen_flavors[21];   //[_gen_nL]
  Int_t           _gen_nNu;
  Double_t        _gen_nuPt[11];   //[_gen_nNu]
  Double_t        _gen_nuE[11];   //[_gen_nNu]
  Double_t        _gen_nuEta[11];   //[_gen_nNu]
  Double_t        _gen_nuPhi[11];   //[_gen_nNu]
  Int_t           _gen_numompdg[11];   //[_gen_nNu]
  Int_t           _gen_nMajo;
  Double_t        _gen_majoPt[1];   //[_gen_nMajo]
  Double_t        _gen_majoE[1];   //[_gen_nMajo]
  Double_t        _gen_majoEta[1];   //[_gen_nMajo]
  Double_t        _gen_majoPhi[1];   //[_gen_nMajo]
  Int_t           _gen_nW;
  Double_t        _gen_wPt[1];   //[_gen_nW]
  Double_t        _gen_wE[1];   //[_gen_nW]
  Double_t        _gen_wEta[1];   //[_gen_nW]
  Double_t        _gen_wPhi[1];   //[_gen_nW]
  Int_t           _gen_wmompdg[1];   //[_gen_nW]

  // List of branches

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
  TBranch        *b_HLT_TripleMu_12_10_5;   //!
  TBranch        *b_HLT_TripleMu_12_10_5_prescale;   //!
  TBranch        *b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL;   //!
  TBranch        *b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale;   //!
  TBranch        *b_HLT_Mu8_DiEle12_CaloIdL_TrackIdL;   //!
  TBranch        *b_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale;   //!
  TBranch        *b_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;   //!
  TBranch        *b_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale;   //!
  TBranch        *b_HLT_TripleMu_5_3_3_DZ_Mass3p8;   //!
  TBranch        *b_HLT_TripleMu_5_3_3_DZ_Mass3p8_prescale;   //!
  TBranch        *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;   //!
  TBranch        *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale;   //!
  TBranch        *b_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ;   //!
  TBranch        *b_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale;   //!
  TBranch        *b_HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ;   //!
  TBranch        *b_HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale;   //!
  TBranch        *b_HLT_Mu30_TkMu11;   //!
  TBranch        *b_HLT_Mu30_TkMu11_prescale;   //!
  TBranch        *b_HLT_Mu40_TkMu11;   //!
  TBranch        *b_HLT_Mu40_TkMu11_prescale;   //!
  TBranch        *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;   //!
  TBranch        *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale;   //!
  TBranch        *b_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL;   //!
  TBranch        *b_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale;   //!
  TBranch        *b_HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL;   //!
  TBranch        *b_HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale;   //!
  TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;   //!
  TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale;   //!
  TBranch        *b_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;   //!
  TBranch        *b_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale;   //!
  TBranch        *b_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ;   //!
  TBranch        *b_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_prescale;   //!
  TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL;   //!
  TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_prescale;   //!
  TBranch        *b_HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL;   //!
  TBranch        *b_HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_prescale;   //!
  TBranch        *b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;   //!
  TBranch        *b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale;   //!
  TBranch        *b_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf;   //!
  TBranch        *b_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_prescale;   //!
  TBranch        *b_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL;   //!
  TBranch        *b_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_prescale;   //!
  TBranch        *b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;   //!
  TBranch        *b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_prescale;   //!
  TBranch        *b_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL;   //!
  TBranch        *b_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_prescale;   //!
  TBranch        *b_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;   //!
  TBranch        *b_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale;   //!
  TBranch        *b_HLT_Mu50;   //!
  TBranch        *b_HLT_Mu50_prescale;   //!
  TBranch        *b_HLT_TkMu50;   //!
  TBranch        *b_HLT_TkMu50_prescale;   //!
  TBranch        *b_HLT_IsoMu27;   //!
  TBranch        *b_HLT_IsoMu27_prescale;   //!
  TBranch        *b_HLT_IsoTkMu27;   //!
  TBranch        *b_HLT_IsoTkMu27_prescale;   //!
  TBranch        *b_HLT_IsoMu24;   //!
  TBranch        *b_HLT_IsoMu24_prescale;   //!
  TBranch        *b_HLT_IsoTkMu24;   //!
  TBranch        *b_HLT_IsoTkMu24_prescale;   //!
  TBranch        *b_HLT_IsoMu24_eta2p1;   //!
  TBranch        *b_HLT_IsoMu24_eta2p1_prescale;   //!
  TBranch        *b_HLT_IsoTkMu24_eta2p1;   //!
  TBranch        *b_HLT_IsoTkMu24_eta2p1_prescale;   //!
  TBranch        *b_HLT_IsoMu22_eta2p1;   //!
  TBranch        *b_HLT_IsoMu22_eta2p1_prescale;   //!
  TBranch        *b_HLT_IsoTkMu22_eta2p1;   //!
  TBranch        *b_HLT_IsoTkMu22_eta2p1_prescale;   //!
  TBranch        *b_HLT_IsoTkMu22;   //!
  TBranch        *b_HLT_IsoTkMu22_prescale;   //!
  TBranch        *b_HLT_Mu45_eta2p1;   //!
  TBranch        *b_HLT_Mu45_eta2p1_prescale;   //!
  TBranch        *b_HLT_Ele32_WPTight_Gsf;   //!
  TBranch        *b_HLT_Ele32_WPTight_Gsf_prescale;   //!
  TBranch        *b_HLT_Ele32_eta2p1_WPTight_Gsf;   //!
  TBranch        *b_HLT_Ele32_eta2p1_WPTight_Gsf_prescale;   //!
  TBranch        *b_HLT_Ele30_WPTight_Gsf;   //!
  TBranch        *b_HLT_Ele30_WPTight_Gsf_prescale;   //!
  TBranch        *b_HLT_Ele30_eta2p1_WPTight_Gsf;   //!
  TBranch        *b_HLT_Ele30_eta2p1_WPTight_Gsf_prescale;   //!
  TBranch        *b_HLT_Ele27_WPTight_Gsf;   //!
  TBranch        *b_HLT_Ele27_WPTight_Gsf_prescale;   //!
  TBranch        *b_HLT_Ele27_eta2p1_WPTight_Gsf;   //!
  TBranch        *b_HLT_Ele27_eta2p1_WPTight_Gsf_prescale;   //!
  TBranch        *b_HLT_Ele27_eta2p1_WPLoose_Gsf;   //!
  TBranch        *b_HLT_Ele27_eta2p1_WPLoose_Gsf_prescale;   //!
  TBranch        *b_HLT_Ele25_eta2p1_WPTight_Gsf;   //!
  TBranch        *b_HLT_Ele25_eta2p1_WPTight_Gsf_prescale;   //!
  TBranch        *b_HLT_Ele25_WPTight_Gsf;   //!
  TBranch        *b_HLT_Ele25_WPTight_Gsf_prescale;   //!
  TBranch        *b_HLT_Ele8_CaloIdM_TrackIdM_PFJet30;   //!
  TBranch        *b_HLT_Ele8_CaloIdM_TrackIdM_PFJet30_prescale;   //!
  TBranch        *b_HLT_Ele12_CaloIdM_TrackIdM_PFJet30;   //!
  TBranch        *b_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_prescale;   //!
  TBranch        *b_HLT_Ele8_CaloIdM_TrackIdM_IsoVL_PFJet30;   //!
  TBranch        *b_HLT_Ele8_CaloIdM_TrackIdM_IsoVL_PFJet30_prescale;   //!
  TBranch        *b_HLT_Ele12_CaloIdM_TrackIdM_IsoVL_PFJet30;   //!
  TBranch        *b_HLT_Ele12_CaloIdM_TrackIdM_IsoVL_PFJet30_prescale;   //!
  TBranch        *b_HLT_Mu8_TrkIsoVVL_v;   //!
  TBranch        *b_HLT_Mu8_TrkIsoVVL_v_prescale;   //!
  TBranch        *b_HLT_Mu17_TrkIsoVVL_v;   //!
  TBranch        *b_HLT_Mu17_TrkIsoVVL_v_prescale;   //!
  TBranch        *b_HLT_Mu24_TrkIsoVVL_v;   //!
  TBranch        *b_HLT_Mu24_TrkIsoVVL_v_prescale;   //!
  TBranch        *b_HLT_Mu34_TrkIsoVVL_v;   //!
  TBranch        *b_HLT_Mu34_TrkIsoVVL_v_prescale;   //!
  TBranch        *b_HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v;   //!
  TBranch        *b_HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v_prescale;   //!
  TBranch        *b_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v;   //!
  TBranch        *b_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v_prescale;   //!
  TBranch        *b_HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v;   //!
  TBranch        *b_HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v_prescale;   //!
  TBranch        *b_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v;   //!
  TBranch        *b_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v_prescale;   //!
  TBranch        *b_HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v;   //!
  TBranch        *b_HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v_prescale;   //!
  TBranch        *b_HLT_Mu3_PFJet40_v;   //!
  TBranch        *b_HLT_Mu3_PFJet40_v_prescale;   //!
  TBranch        *b_HLT_Mu8_v;   //!
  TBranch        *b_HLT_Mu8_v_prescale;   //!
  TBranch        *b_HLT_Mu17_v;   //!
  TBranch        *b_HLT_Mu17_v_prescale;   //!
  TBranch        *b_HLT_Mu24_v;   //!
  TBranch        *b_HLT_Mu24_v_prescale;   //!
  TBranch        *b_HLT_Mu34_v;   //!
  TBranch        *b_HLT_Mu34_v_prescale;   //!
  TBranch        *b_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v;   //!
  TBranch        *b_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale;   //!
  TBranch        *b_HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v;   //!
  TBranch        *b_HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale;   //!
  TBranch        *b_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v;   //!
  TBranch        *b_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale;   //!
  TBranch        *b_HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v;   //!
  TBranch        *b_HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale;   //!
  TBranch        *b_HLT_Ele12_CaloIdL_TrkIdL_IsoVL_v;   //!
  TBranch        *b_HLT_Ele12_CaloIdL_TrkIdL_IsoVL_v_prescale;   //!
  TBranch        *b_HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v;   //!
  TBranch        *b_HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v_prescale;   //!
  TBranch        *b_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v;   //!
  TBranch        *b_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v_prescale;   //!
  TBranch        *b_Flag_HBHENoiseFilter;   //!
  TBranch        *b_Flag_HBHENoiseIsoFilter;   //!
  TBranch        *b_Flag_EcalDeadCellTriggerPrimitiveFilter;   //!
  TBranch        *b_Flag_goodVertices;   //!
  TBranch        *b_Flag_eeBadScFilter;   //!
  TBranch        *b_Flag_globalTightHalo2016Filter;   //!
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
 
    
    

  double hcounter[nSamples];
    
  for(int sam = 0; sam < nSamples; ++sam){
   
    cout<<"================================= 1"<<endl;
    cout<<"--------> "<< "name " << names[sam] << endl;
    cout<<"--------> "<< "fileList[sam] " << fileList[sam] << endl;
    hfile[sam] = new TFile("/Users/Martina/Desktop/CMS/FILE/"+fileList[sam],"read");
    hfile[sam]->cd("trileptonProducer");
    inputTree[sam] = static_cast<TTree*>(hfile[sam]->Get("trileptonProducer/trileptonTree"));
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
    inputTree[sam]->SetBranchAddress("HLT_TripleMu_12_10_5", &HLT_TripleMu_12_10_5, &b_HLT_TripleMu_12_10_5);
    inputTree[sam]->SetBranchAddress("HLT_TripleMu_12_10_5_prescale", &HLT_TripleMu_12_10_5_prescale, &b_HLT_TripleMu_12_10_5_prescale);
    inputTree[sam]->SetBranchAddress("HLT_DiMu9_Ele9_CaloIdL_TrackIdL", &HLT_DiMu9_Ele9_CaloIdL_TrackIdL, &b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL);
    inputTree[sam]->SetBranchAddress("HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale", &HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale, &b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu8_DiEle12_CaloIdL_TrackIdL", &HLT_Mu8_DiEle12_CaloIdL_TrackIdL, &b_HLT_Mu8_DiEle12_CaloIdL_TrackIdL);
    inputTree[sam]->SetBranchAddress("HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale", &HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale, &b_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL", &HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL, &b_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL);
    inputTree[sam]->SetBranchAddress("HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale", &HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale, &b_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale);
    inputTree[sam]->SetBranchAddress("HLT_TripleMu_5_3_3_DZ_Mass3p8", &HLT_TripleMu_5_3_3_DZ_Mass3p8, &b_HLT_TripleMu_5_3_3_DZ_Mass3p8);
    inputTree[sam]->SetBranchAddress("HLT_TripleMu_5_3_3_DZ_Mass3p8_prescale", &HLT_TripleMu_5_3_3_DZ_Mass3p8_prescale, &b_HLT_TripleMu_5_3_3_DZ_Mass3p8_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ);
    inputTree[sam]->SetBranchAddress("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ", &HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ, &b_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ);
    inputTree[sam]->SetBranchAddress("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale", &HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale, &b_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale);
    inputTree[sam]->SetBranchAddress("HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ", &HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ, &b_HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ);
    inputTree[sam]->SetBranchAddress("HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale", &HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale, &b_HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu30_TkMu11", &HLT_Mu30_TkMu11, &b_HLT_Mu30_TkMu11);
    inputTree[sam]->SetBranchAddress("HLT_Mu30_TkMu11_prescale", &HLT_Mu30_TkMu11_prescale, &b_HLT_Mu30_TkMu11_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu40_TkMu11", &HLT_Mu40_TkMu11, &b_HLT_Mu40_TkMu11);
    inputTree[sam]->SetBranchAddress("HLT_Mu40_TkMu11_prescale", &HLT_Mu40_TkMu11_prescale, &b_HLT_Mu40_TkMu11_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL);
    inputTree[sam]->SetBranchAddress("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", &HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL, &b_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL);
    inputTree[sam]->SetBranchAddress("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale", &HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale, &b_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale);
    inputTree[sam]->SetBranchAddress("HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL", &HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL, &b_HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL);
    inputTree[sam]->SetBranchAddress("HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale", &HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale, &b_HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
    inputTree[sam]->SetBranchAddress("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
    inputTree[sam]->SetBranchAddress("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ);
    inputTree[sam]->SetBranchAddress("HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL", &HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL, &b_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL);
    inputTree[sam]->SetBranchAddress("HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_prescale", &HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_prescale, &b_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_prescale);
    inputTree[sam]->SetBranchAddress("HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL", &HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL, &b_HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL);
    inputTree[sam]->SetBranchAddress("HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_prescale", &HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_prescale, &b_HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
    inputTree[sam]->SetBranchAddress("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
    inputTree[sam]->SetBranchAddress("HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf", &HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf, &b_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf);
    inputTree[sam]->SetBranchAddress("HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_prescale", &HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_prescale, &b_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_prescale);
    inputTree[sam]->SetBranchAddress("HLT_DoubleEle33_CaloIdL_GsfTrkIdVL", &HLT_DoubleEle33_CaloIdL_GsfTrkIdVL, &b_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL);
    inputTree[sam]->SetBranchAddress("HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_prescale", &HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_prescale, &b_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL", &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL, &b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL);
    inputTree[sam]->SetBranchAddress("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_prescale", &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_prescale, &b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL", &HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL, &b_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL);
    inputTree[sam]->SetBranchAddress("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_prescale", &HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_prescale, &b_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
    inputTree[sam]->SetBranchAddress("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
    //    inputTree[sam]->SetBranchAddress("HLT_DoubleEle33_CaloIdL_GsfTrkIdVL", &HLT_DoubleEle33_CaloIdL_GsfTrkIdVL, &b_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL);
    //    inputTree[sam]->SetBranchAddress("HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_prescale", &HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_prescale, &b_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu50", &HLT_Mu50, &b_HLT_Mu50);
    inputTree[sam]->SetBranchAddress("HLT_Mu50_prescale", &HLT_Mu50_prescale, &b_HLT_Mu50_prescale);
    inputTree[sam]->SetBranchAddress("HLT_TkMu50", &HLT_TkMu50, &b_HLT_TkMu50);
    inputTree[sam]->SetBranchAddress("HLT_TkMu50_prescale", &HLT_TkMu50_prescale, &b_HLT_TkMu50_prescale);
    inputTree[sam]->SetBranchAddress("HLT_IsoMu27", &HLT_IsoMu27, &b_HLT_IsoMu27);
    inputTree[sam]->SetBranchAddress("HLT_IsoMu27_prescale", &HLT_IsoMu27_prescale, &b_HLT_IsoMu27_prescale);
    inputTree[sam]->SetBranchAddress("HLT_IsoTkMu27", &HLT_IsoTkMu27, &b_HLT_IsoTkMu27);
    inputTree[sam]->SetBranchAddress("HLT_IsoTkMu27_prescale", &HLT_IsoTkMu27_prescale, &b_HLT_IsoTkMu27_prescale);
    inputTree[sam]->SetBranchAddress("HLT_IsoMu24", &HLT_IsoMu24, &b_HLT_IsoMu24);
    inputTree[sam]->SetBranchAddress("HLT_IsoMu24_prescale", &HLT_IsoMu24_prescale, &b_HLT_IsoMu24_prescale);
    inputTree[sam]->SetBranchAddress("HLT_IsoTkMu24", &HLT_IsoTkMu24, &b_HLT_IsoTkMu24);
    inputTree[sam]->SetBranchAddress("HLT_IsoTkMu24_prescale", &HLT_IsoTkMu24_prescale, &b_HLT_IsoTkMu24_prescale);
    inputTree[sam]->SetBranchAddress("HLT_IsoMu24_eta2p1", &HLT_IsoMu24_eta2p1, &b_HLT_IsoMu24_eta2p1);
    inputTree[sam]->SetBranchAddress("HLT_IsoMu24_eta2p1_prescale", &HLT_IsoMu24_eta2p1_prescale, &b_HLT_IsoMu24_eta2p1_prescale);
    inputTree[sam]->SetBranchAddress("HLT_IsoTkMu24_eta2p1", &HLT_IsoTkMu24_eta2p1, &b_HLT_IsoTkMu24_eta2p1);
    inputTree[sam]->SetBranchAddress("HLT_IsoTkMu24_eta2p1_prescale", &HLT_IsoTkMu24_eta2p1_prescale, &b_HLT_IsoTkMu24_eta2p1_prescale);
    inputTree[sam]->SetBranchAddress("HLT_IsoMu22_eta2p1", &HLT_IsoMu22_eta2p1, &b_HLT_IsoMu22_eta2p1);
    inputTree[sam]->SetBranchAddress("HLT_IsoMu22_eta2p1_prescale", &HLT_IsoMu22_eta2p1_prescale, &b_HLT_IsoMu22_eta2p1_prescale);
    inputTree[sam]->SetBranchAddress("HLT_IsoTkMu22_eta2p1", &HLT_IsoTkMu22_eta2p1, &b_HLT_IsoTkMu22_eta2p1);
    inputTree[sam]->SetBranchAddress("HLT_IsoTkMu22_eta2p1_prescale", &HLT_IsoTkMu22_eta2p1_prescale, &b_HLT_IsoTkMu22_eta2p1_prescale);
    inputTree[sam]->SetBranchAddress("HLT_IsoTkMu22", &HLT_IsoTkMu22, &b_HLT_IsoTkMu22);
    inputTree[sam]->SetBranchAddress("HLT_IsoTkMu22_prescale", &HLT_IsoTkMu22_prescale, &b_HLT_IsoTkMu22_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu45_eta2p1", &HLT_Mu45_eta2p1, &b_HLT_Mu45_eta2p1);
    inputTree[sam]->SetBranchAddress("HLT_Mu45_eta2p1_prescale", &HLT_Mu45_eta2p1_prescale, &b_HLT_Mu45_eta2p1_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele32_WPTight_Gsf", &HLT_Ele32_WPTight_Gsf, &b_HLT_Ele32_WPTight_Gsf);
    inputTree[sam]->SetBranchAddress("HLT_Ele32_WPTight_Gsf_prescale", &HLT_Ele32_WPTight_Gsf_prescale, &b_HLT_Ele32_WPTight_Gsf_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele32_eta2p1_WPTight_Gsf", &HLT_Ele32_eta2p1_WPTight_Gsf, &b_HLT_Ele32_eta2p1_WPTight_Gsf);
    inputTree[sam]->SetBranchAddress("HLT_Ele32_eta2p1_WPTight_Gsf_prescale", &HLT_Ele32_eta2p1_WPTight_Gsf_prescale, &b_HLT_Ele32_eta2p1_WPTight_Gsf_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele30_WPTight_Gsf", &HLT_Ele30_WPTight_Gsf, &b_HLT_Ele30_WPTight_Gsf);
    inputTree[sam]->SetBranchAddress("HLT_Ele30_WPTight_Gsf_prescale", &HLT_Ele30_WPTight_Gsf_prescale, &b_HLT_Ele30_WPTight_Gsf_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele30_eta2p1_WPTight_Gsf", &HLT_Ele30_eta2p1_WPTight_Gsf, &b_HLT_Ele30_eta2p1_WPTight_Gsf);
    inputTree[sam]->SetBranchAddress("HLT_Ele30_eta2p1_WPTight_Gsf_prescale", &HLT_Ele30_eta2p1_WPTight_Gsf_prescale, &b_HLT_Ele30_eta2p1_WPTight_Gsf_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele27_WPTight_Gsf", &HLT_Ele27_WPTight_Gsf, &b_HLT_Ele27_WPTight_Gsf);
    inputTree[sam]->SetBranchAddress("HLT_Ele27_WPTight_Gsf_prescale", &HLT_Ele27_WPTight_Gsf_prescale, &b_HLT_Ele27_WPTight_Gsf_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele27_eta2p1_WPTight_Gsf", &HLT_Ele27_eta2p1_WPTight_Gsf, &b_HLT_Ele27_eta2p1_WPTight_Gsf);
    inputTree[sam]->SetBranchAddress("HLT_Ele27_eta2p1_WPTight_Gsf_prescale", &HLT_Ele27_eta2p1_WPTight_Gsf_prescale, &b_HLT_Ele27_eta2p1_WPTight_Gsf_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele27_eta2p1_WPLoose_Gsf", &HLT_Ele27_eta2p1_WPLoose_Gsf, &b_HLT_Ele27_eta2p1_WPLoose_Gsf);
    inputTree[sam]->SetBranchAddress("HLT_Ele27_eta2p1_WPLoose_Gsf_prescale", &HLT_Ele27_eta2p1_WPLoose_Gsf_prescale, &b_HLT_Ele27_eta2p1_WPLoose_Gsf_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele25_eta2p1_WPTight_Gsf", &HLT_Ele25_eta2p1_WPTight_Gsf, &b_HLT_Ele25_eta2p1_WPTight_Gsf);
    inputTree[sam]->SetBranchAddress("HLT_Ele25_eta2p1_WPTight_Gsf_prescale", &HLT_Ele25_eta2p1_WPTight_Gsf_prescale, &b_HLT_Ele25_eta2p1_WPTight_Gsf_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele25_WPTight_Gsf", &HLT_Ele25_WPTight_Gsf, &b_HLT_Ele25_WPTight_Gsf);
    inputTree[sam]->SetBranchAddress("HLT_Ele25_WPTight_Gsf_prescale", &HLT_Ele25_WPTight_Gsf_prescale, &b_HLT_Ele25_WPTight_Gsf_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele8_CaloIdM_TrackIdM_PFJet30", &HLT_Ele8_CaloIdM_TrackIdM_PFJet30, &b_HLT_Ele8_CaloIdM_TrackIdM_PFJet30);
    inputTree[sam]->SetBranchAddress("HLT_Ele8_CaloIdM_TrackIdM_PFJet30_prescale", &HLT_Ele8_CaloIdM_TrackIdM_PFJet30_prescale, &b_HLT_Ele8_CaloIdM_TrackIdM_PFJet30_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele12_CaloIdM_TrackIdM_PFJet30", &HLT_Ele12_CaloIdM_TrackIdM_PFJet30, &b_HLT_Ele12_CaloIdM_TrackIdM_PFJet30);
    inputTree[sam]->SetBranchAddress("HLT_Ele12_CaloIdM_TrackIdM_PFJet30_prescale", &HLT_Ele12_CaloIdM_TrackIdM_PFJet30_prescale, &b_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele8_CaloIdM_TrackIdM_IsoVL_PFJet30", &HLT_Ele8_CaloIdM_TrackIdM_IsoVL_PFJet30, &b_HLT_Ele8_CaloIdM_TrackIdM_IsoVL_PFJet30);
    inputTree[sam]->SetBranchAddress("HLT_Ele8_CaloIdM_TrackIdM_IsoVL_PFJet30_prescale", &HLT_Ele8_CaloIdM_TrackIdM_IsoVL_PFJet30_prescale, &b_HLT_Ele8_CaloIdM_TrackIdM_IsoVL_PFJet30_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele12_CaloIdM_TrackIdM_IsoVL_PFJet30", &HLT_Ele12_CaloIdM_TrackIdM_IsoVL_PFJet30, &b_HLT_Ele12_CaloIdM_TrackIdM_IsoVL_PFJet30);
    inputTree[sam]->SetBranchAddress("HLT_Ele12_CaloIdM_TrackIdM_IsoVL_PFJet30_prescale", &HLT_Ele12_CaloIdM_TrackIdM_IsoVL_PFJet30_prescale, &b_HLT_Ele12_CaloIdM_TrackIdM_IsoVL_PFJet30_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu8_TrkIsoVVL_v", &HLT_Mu8_TrkIsoVVL_v, &b_HLT_Mu8_TrkIsoVVL_v);
    inputTree[sam]->SetBranchAddress("HLT_Mu8_TrkIsoVVL_v_prescale", &HLT_Mu8_TrkIsoVVL_v_prescale, &b_HLT_Mu8_TrkIsoVVL_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu17_TrkIsoVVL_v", &HLT_Mu17_TrkIsoVVL_v, &b_HLT_Mu17_TrkIsoVVL_v);
    inputTree[sam]->SetBranchAddress("HLT_Mu17_TrkIsoVVL_v_prescale", &HLT_Mu17_TrkIsoVVL_v_prescale, &b_HLT_Mu17_TrkIsoVVL_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu24_TrkIsoVVL_v", &HLT_Mu24_TrkIsoVVL_v, &b_HLT_Mu24_TrkIsoVVL_v);
    inputTree[sam]->SetBranchAddress("HLT_Mu24_TrkIsoVVL_v_prescale", &HLT_Mu24_TrkIsoVVL_v_prescale, &b_HLT_Mu24_TrkIsoVVL_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu34_TrkIsoVVL_v", &HLT_Mu34_TrkIsoVVL_v, &b_HLT_Mu34_TrkIsoVVL_v);
    inputTree[sam]->SetBranchAddress("HLT_Mu34_TrkIsoVVL_v_prescale", &HLT_Mu34_TrkIsoVVL_v_prescale, &b_HLT_Mu34_TrkIsoVVL_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v", &HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v, &b_HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v);
    inputTree[sam]->SetBranchAddress("HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v_prescale", &HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v_prescale, &b_HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v", &HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v, &b_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v);
    inputTree[sam]->SetBranchAddress("HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v_prescale", &HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v_prescale, &b_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v", &HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v, &b_HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v);
    inputTree[sam]->SetBranchAddress("HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v_prescale", &HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v_prescale, &b_HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v", &HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v, &b_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v);
    inputTree[sam]->SetBranchAddress("HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v_prescale", &HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v_prescale, &b_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v", &HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v, &b_HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v);
    inputTree[sam]->SetBranchAddress("HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v_prescale", &HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v_prescale, &b_HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu3_PFJet40_v", &HLT_Mu3_PFJet40_v, &b_HLT_Mu3_PFJet40_v);
    inputTree[sam]->SetBranchAddress("HLT_Mu3_PFJet40_v_prescale", &HLT_Mu3_PFJet40_v_prescale, &b_HLT_Mu3_PFJet40_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu8_v", &HLT_Mu8_v, &b_HLT_Mu8_v);
    inputTree[sam]->SetBranchAddress("HLT_Mu8_v_prescale", &HLT_Mu8_v_prescale, &b_HLT_Mu8_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu17_v", &HLT_Mu17_v, &b_HLT_Mu17_v);
    inputTree[sam]->SetBranchAddress("HLT_Mu17_v_prescale", &HLT_Mu17_v_prescale, &b_HLT_Mu17_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu24_v", &HLT_Mu24_v, &b_HLT_Mu24_v);
    inputTree[sam]->SetBranchAddress("HLT_Mu24_v_prescale", &HLT_Mu24_v_prescale, &b_HLT_Mu24_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Mu34_v", &HLT_Mu34_v, &b_HLT_Mu34_v);
    inputTree[sam]->SetBranchAddress("HLT_Mu34_v_prescale", &HLT_Mu34_v_prescale, &b_HLT_Mu34_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v", &HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v, &b_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v);
    inputTree[sam]->SetBranchAddress("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale", &HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale, &b_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v", &HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v, &b_HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v);
    inputTree[sam]->SetBranchAddress("HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale", &HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale, &b_HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v", &HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v, &b_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v);
    inputTree[sam]->SetBranchAddress("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale", &HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale, &b_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v", &HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v, &b_HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v);
    inputTree[sam]->SetBranchAddress("HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale", &HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale, &b_HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele12_CaloIdL_TrkIdL_IsoVL_v", &HLT_Ele12_CaloIdL_TrkIdL_IsoVL_v, &b_HLT_Ele12_CaloIdL_TrkIdL_IsoVL_v);
    inputTree[sam]->SetBranchAddress("HLT_Ele12_CaloIdL_TrkIdL_IsoVL_v_prescale", &HLT_Ele12_CaloIdL_TrkIdL_IsoVL_v_prescale, &b_HLT_Ele12_CaloIdL_TrkIdL_IsoVL_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v", &HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v);
    inputTree[sam]->SetBranchAddress("HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v_prescale", &HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v_prescale, &b_HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v_prescale);
    inputTree[sam]->SetBranchAddress("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v", &HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v);
    inputTree[sam]->SetBranchAddress("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v_prescale", &HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v_prescale, &b_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v_prescale);
    inputTree[sam]->SetBranchAddress("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter, &b_Flag_HBHENoiseFilter);
    inputTree[sam]->SetBranchAddress("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter, &b_Flag_HBHENoiseIsoFilter);
    inputTree[sam]->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
    inputTree[sam]->SetBranchAddress("Flag_goodVertices", &Flag_goodVertices, &b_Flag_goodVertices);
    inputTree[sam]->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter, &b_Flag_eeBadScFilter);
    inputTree[sam]->SetBranchAddress("Flag_globalTightHalo2016Filter", &Flag_globalTightHalo2016Filter, &b_Flag_globalTightHalo2016Filter);
    inputTree[sam]->SetBranchAddress("_gen_nL", &_gen_nL, &b__gen_nL);
    inputTree[sam]->SetBranchAddress("_gen_lPt", _gen_lPt, &b__gen_lPt);
    inputTree[sam]->SetBranchAddress("_gen_lE", _gen_lE, &b__gen_lE);
    inputTree[sam]->SetBranchAddress("_gen_lEta", _gen_lEta, &b__gen_lEta);
    inputTree[sam]->SetBranchAddress("_gen_lPhi", _gen_lPhi, &b__gen_lPhi);
    inputTree[sam]->SetBranchAddress("_gen_lmompdg", _gen_lmompdg, &b__gen_lmompdg);
    inputTree[sam]->SetBranchAddress("_gen_charges", _gen_charges, &b__gen_charges);
    inputTree[sam]->SetBranchAddress("_gen_flavors", _gen_flavors, &b__gen_flavors);
    inputTree[sam]->SetBranchAddress("_gen_nNu", &_gen_nNu, &b__gen_nNu);
    inputTree[sam]->SetBranchAddress("_gen_nuPt", _gen_nuPt, &b__gen_nuPt);
    inputTree[sam]->SetBranchAddress("_gen_nuE", _gen_nuE, &b__gen_nuE);
    inputTree[sam]->SetBranchAddress("_gen_nuEta", _gen_nuEta, &b__gen_nuEta);
    inputTree[sam]->SetBranchAddress("_gen_nuPhi", _gen_nuPhi, &b__gen_nuPhi);
    inputTree[sam]->SetBranchAddress("_gen_numompdg", _gen_numompdg, &b__gen_numompdg);
    inputTree[sam]->SetBranchAddress("_gen_nMajo", &_gen_nMajo, &b__gen_nMajo);
    inputTree[sam]->SetBranchAddress("_gen_majoPt", &_gen_majoPt, &b__gen_majoPt);
    inputTree[sam]->SetBranchAddress("_gen_majoE", &_gen_majoE, &b__gen_majoE);
    inputTree[sam]->SetBranchAddress("_gen_majoEta", &_gen_majoEta, &b__gen_majoEta);
    inputTree[sam]->SetBranchAddress("_gen_majoPhi", &_gen_majoPhi, &b__gen_majoPhi);
    inputTree[sam]->SetBranchAddress("_gen_nW", &_gen_nW, &b__gen_nW);
    inputTree[sam]->SetBranchAddress("_gen_wPt", &_gen_wPt, &b__gen_wPt);
    inputTree[sam]->SetBranchAddress("_gen_wE", &_gen_wE, &b__gen_wE);
    inputTree[sam]->SetBranchAddress("_gen_wEta", &_gen_wEta, &b__gen_wEta);
    inputTree[sam]->SetBranchAddress("_gen_wPhi", &_gen_wPhi, &b__gen_wPhi);
    inputTree[sam]->SetBranchAddress("_gen_wmompdg", &_gen_wmompdg, &b__gen_wmompdg);
    TH1D* _hCounter = new TH1D("hCounter", "Events counter", 5,0,5);
    _hCounter->Read("hCounter");
    hcounter[sam] = _hCounter->GetBinContent(1);
  }//end for on tree
    
  //******************* HISTO **********************
  const int nCat=6;
  const int nDist = 27;  //Number of distributions to plot
  TH1D* Histos[nDist][nCat][nSamples_eff +1];
  const TString catNames[nCat] ={"all_ossf", "low_ossf", "high_ossf", "all_n_ossf", "low_n_ossf", "high_n_ossf"};
  const TString Histnames_ossf[nDist] = { "LeptonPt_le","LeptonPt_subl", "LeptonPt_tr","Sum3Pt","Sum2Pt_lt","Sum2Pt_st","Sum2Pt_ls","Mlll","Mll","Mll_pair OSSF", "MET", "MT", "NJets", "NbJets","HT", "DeltaR_pair","DeltaR_lt","DeltaR_st","RelIso_l", "RelIso_t", "dxy_l", "dxy_t","dz_l", "dz_t","3dIP_l", "3dIP_t", "flavors"};

  //const TString Histnames_n_ossf[nDist] = { "LeptonPt_le","LeptonPt_subl" "LeptonPt_tr","Sum3Pt","Sum2Pt_lt","Sum2Pt_st","Sum2Pt_ls","Mlll","Mll","Mll_pair NOSSF", "MET", "MT", "NJets", "NbJets","HT", "DeltaR","DeltaR_pair","DeltaR_lt","DeltaR_st","RelIso_l", "RelIso_t", "dxy_l", "dxy_t","dz_l", "dz_t","3dIP_l", "3dIP_t"};

  const TString Xaxes[nDist] = {"P_{T}(leading l) (GeV)","P_{T}(sub-leading l) (GeV)", "P_{T}(trailing l) (GeV)", "SumP_{T}(3leptons) (GeV)","SumP_{T}(leading+trailing) (GeV)","SumP_{T}(sub-leading+trailing) (GeV)","SumP_{T}(leading+sub-leading) (GeV)",
				"M_{lll} (GeV)","M_{ll} (sub-leading+soft) (GeV)", "M_{ll} OSSF pair (GeV)", "MET (GeV)", "M_{T} (GeV)", "number of jets", "number of b-jets","HT (GeV)" , "#Delta R (OSSF pair)", "#Delta R (leading,trailing)", "#Delta R (sub-leading, trailing)", "relIso(leading)", "relIso(trailing)", "|d_{xy}(leading)| (cm)", "|d_{xy}(trailing)| (cm)", "|d_{z}(leading)| (cm)", "|d_{z}(trailing)| (cm)",  "|3DIP(leading)| (cm)","|3DIP(trailing)| (cm)","flavors"};

  const TString Units[nDist] = {"GeV", "GeV", "GeV", "GeV", "GeV","GeV","GeV","GeV","GeV","GeV","GeV","GeV", "", "", "GeV",  "", "", "",  "cm", "cm","cm", "cm", "cm", "cm","cm","cm",""};

  const double HistMin[nDist] = { 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  const double HistMax[nDist] = {100, 100, 100, 200, 200,  200,  200,  100,  100,  100, 200, 100, 10,10, 100, 4,4,4,0.1,0.1,0.015,0.015, 0.015, 0.15, 0.8, 0.8, 5};
  const int nBins[nDist] = {10, 10, 10, 50, 50, 50,50,20,20,20,50,20,10,10,20,25,25,25,50,50,50,20,20,20,20,20, 5};


  double data_sum1=0;
  double data_sum2=0;
  double mc_sum1=0;
  double mc_sum2=0;



 
  for(int i = 0; i < nDist; ++i){
    // cout<<"-------> numero isto: "<<i<<endl;
    float BinWidth = (HistMax[i] - HistMin[i])/nBins[i];
    std::ostringstream strs; strs << BinWidth; std::string Yaxis = strs.str();
    for(int effsam = 0; effsam < nSamples_eff + 1; ++effsam){
      //cout<<"------------> numero sample: "<<effsam<<endl;
      for(int cat = 0; cat < nCat; ++cat){
	//cout<<"--------------------------> numero cat: "<<cat<<endl;


	Histos[i][cat][effsam] = new TH1D(eff_names[effsam] + catNames[cat] + Histnames_ossf[i] , eff_names[effsam] + catNames[cat] + Histnames_ossf[i] + ";" + Xaxes[i] + "; events /" + Yaxis + Units[i], nBins[i], HistMin[i], HistMax[i]);
	Histos[i][cat][effsam]->Sumw2();
	
	//cout<<i<<" - "<< Histnames_ossf[i] <<")   "<<effsam<<"  -  "<<eff_names[effsam]<<"]   "<<cat<<"  -  "<<catNames[cat]<<"} "<<" --->  "<<Xaxes[i]<<"  "<<Units[i]<<"   "<<HistMin[i]<<"   "<<HistMax[i]<<"   "<<nBins[i]<<endl;
      }
    }
  }
  //Calculate the center of the maximum bin of each histogram
  double maxBinC[nDist];
  for(int i = 0; i < nDist; ++i){
    maxBinC[i] = Histos[i][0][0]->GetBinCenter(Histos[i][0][0]->GetNbinsX());
  }
  //Loop over all samples
  Double_t Counter[nSamples];
  for(int i = 0; i  < nSamples; ++i){
    Counter[i] = 0;
  }
  Double_t scale[nSamples - 5];
  std::set<long> events;
  std::set<long> excess;
  //CHANGE 5 BACK to nsamples
  const double MVA_cuts_pt15[3] = {0.77, 0.56, 0.48};
  const double MVA_cuts_pt25[3] = {0.52, 0.11, -0.01};


  std::set<std::tuple<long, long, long> > usedEvents;

  for(int sam = 0, effsam = 0; sam < nSamples; ++sam, ++effsam){
    Long64_t nEntries = inputTree[sam]->GetEntries();
    if(sam != 0){
      if(names[sam] == names[sam -1]) --effsam;
    }
    if(sam > 4){ // 5 data set
      scale[sam -5] = xSections[sam -5]*luminosity*1000/(hcounter[sam]);
    }
	 
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
      //if (it > 5) continue; 
      if (it%10000 == 0) cout<<'.'<<flush;
      double scal = 0;
      if(effsam == 0) scal = 1;
      else{
	scal = scale[sam-5]*_weight; 
	//scal*= PUweights->GetBinContent(PUweights->FindBin(_n_trueInteractions));
      }


      if(effsam == 0){
	auto event = usedEvents.find(std::make_tuple(_eventNb, _lumiBlock, _runNb));
	if(event != usedEvents.end()) continue;
	usedEvents.insert(std::make_tuple(_eventNb, _lumiBlock, _runNb));
      }



  
      //cout<<_runNb<<"  "<<_eventNb<< "  "<<_lumiBlock<<endl;
       //********************* TRIGGERS **********************
      bool lowM_trigger_all = false;
      bool lowM_trigger_mmm = false;
      bool lowM_trigger_eee = false;
      bool lowM_trigger_mme = false;
      bool lowM_trigger_mee = false;

      
      if ((effsam == 0 && _runNb < 280919)  || effsam != 0) { // no run H
	  if(HLT_Ele27_WPTight_Gsf   ||   HLT_IsoMu24   ||   HLT_IsoTkMu24)lowM_trigger_all = true;
	  if (HLT_TripleMu_12_10_5   ||   HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ   ||   HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ   ||   HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ || HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL   ||   HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL   ||   HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL) lowM_trigger_mmm = true;
	  if (HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL   ||   HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ)lowM_trigger_eee = true;
	  if (HLT_DiMu9_Ele9_CaloIdL_TrackIdL   ||   HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ   ||   HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ   ||   HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ   ||   HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL   ||   HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL   ||   HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL ||  HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ   ||   HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ   ||   HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ   ||   HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ) lowM_trigger_mme = true;
	  if (HLT_Mu8_DiEle12_CaloIdL_TrackIdL   ||   HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ   ||   HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ   ||   HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ   ||   HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ   ||   HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ ) lowM_trigger_mee = true;
	}//end no run H

      if ((effsam == 0 && _runNb >= 280919)) { // si run H
	  if(HLT_Ele27_WPTight_Gsf   ||   HLT_IsoMu24   ||   HLT_IsoTkMu24)lowM_trigger_all = true;
	  if (HLT_TripleMu_12_10_5   ||   HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ   ||   HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ   ||   HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ ) lowM_trigger_mmm = true;
	  if (HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL   ||   HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ)lowM_trigger_eee = true;
	  if (HLT_DiMu9_Ele9_CaloIdL_TrackIdL   ||   HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ   ||   HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ   ||   HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ   ||   HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ   ||   HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ   ||   HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ   ||   HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ) lowM_trigger_mme = true;
	  if (HLT_Mu8_DiEle12_CaloIdL_TrackIdL   ||   HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ   ||   HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ   ||   HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ   ||   HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ   ||   HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ) lowM_trigger_mee = true;
	  }//end si run H





      //number of leptons in tree
      if(_nLeptons < 3) continue;
      
      

      double newMVALooseFR[3]= {-0.98, -1, -0.81};
      double isolation_loose=0.6;

      //new indices of good leptons
      unsigned* ind = new unsigned[_nLeptons];
      //Count number of FO leptons that are not taus
      unsigned lCount = 0;
      unsigned* _isFO= new unsigned[_nLeptons];
      for(unsigned l = 0; l < _nLeptons; ++l){
	_isFO[l] = false;
	if (_flavors[l] == 0 && _lPt[l] < 10 ) continue;
	if (_flavors[l] == 1 && _lPt[l] < 5 ) continue;
	if(TMath::Abs(_ipPV[l]) > 0.05 || TMath::Abs(_ipZPV[l]) > 0.1 || _3dIPsig [l] > 4) continue;

	int eta = -1;
	if(TMath::Abs(_lEta[l]) < 0.8 ) eta = 0;
	else if(TMath::Abs(_lEta[l]) < 1.479 ) eta = 1;
	else eta = 2;

	_isFO[l] = false;
	if (_flavors[l] == 1 && _ismedium[l] && _isolation[l] < isolation_loose ) _isFO[l] = true;		  
	if (_flavors[l] == 0 ){
	  if (eta == 0 && _mvaValue[l] > newMVALooseFR[0] && _isolation[l] < isolation_loose ) _isFO[l] = true;
	  if (eta == 1 && _mvaValue[l] > newMVALooseFR[1] && _isolation[l] < isolation_loose ) _isFO[l] = true;
	  if (eta == 2 && _mvaValue[l] > newMVALooseFR[2] && _isolation[l] < isolation_loose ) _isFO[l] = true;		  
	}	 
	if(_isFO[l] && _flavors[l] != 2){
	  ind[lCount] = l;
	  ++lCount;
	}
      }

      //cout<<"before   1"<<endl;
      if(lCount < 3) continue;
      if (lCount != 3 ) continue;

      

      //Determine nBjets:
      int nBjets = 0;
      for(unsigned j = 0; j < _n_Jets; ++j){
	if(_csv[j] > 0.5426){
	  nBjets ++;
	}
      }

      //cout<<"after   1"<<endl;

      double* comparison_mva= new double[_nLeptons];
      //Calculate and store conePt of each FO object
      double* conePt = new double[_nLeptons];
      for(unsigned l = 0; l < lCount; ++l){
	conePt[ind[l]]=0;
	conePt[ind[l]] = _lPt[ind[l]]* maximum (0, _isolation[ind[l]] - 0.1);
	_lPt[ind[l]] = _lPt[ind[l]]* maximum (0, _isolation[ind[l]] - 0.1);
	_lE[ind[l]] = _lE[ind[l]] *  maximum (0, _isolation[ind[l]] - 0.1);


	int eta = -1;
	if(TMath::Abs(_lEta[l]) < 0.8 ) eta = 0;
	else if(TMath::Abs(_lEta[l]) < 1.479 ) eta = 1;
	else eta = 2;
	if (_flavors[l] == 0 ){
	  _passedMVA90[l] = _mvaValue[l] >  std::min( MVA_cuts_pt15[eta], std::max(MVA_cuts_pt25[eta] , MVA_cuts_pt15[eta] + (MVA_cuts_pt25[eta] - MVA_cuts_pt15[eta])*0.1 *( _lPt[l]-15) ) );
	  comparison_mva[l] = std::min( MVA_cuts_pt15[eta], std::max(MVA_cuts_pt25[eta] , MVA_cuts_pt15[eta] + (MVA_cuts_pt25[eta] - MVA_cuts_pt15[eta])*0.1 *( _lPt[l]-15) ) );

	}
	if (_flavors[l] == 1 ) {
	  _passedMVA90[l] = false;
	  _mvaValue[l] = -5;
	  comparison_mva[l] = -100;
	}

      }
      //Order FO leptons by Pt
      unsigned* ordind = new unsigned[lCount];
      std::set<unsigned> usedLep;
      for(unsigned k =0; k < lCount; ++k){
	//unsigned maxI = 999;
	double maxConePt = 0;
	for(unsigned l = 0; l < lCount; ++l){
	  if(usedLep.find(ind[l]) == usedLep.end()){
	    if(conePt[ind[l]] > maxConePt){
	      maxConePt = conePt[ind[l]];
	      ordind[k] = ind[l];
	    }
	  }
	}
	usedLep.insert(ordind[k]);
      }
      for(unsigned i = 0; i < lCount; ++i){
	ind[i] = ordind[i];
      }

      if(conePt[ind[0]] < 25) continue;
      if(conePt[ind[1]] < 15) continue;
      if(_flavors[ind[2]]== 1 && conePt[ind[2]] < 5) continue;
      if(_flavors[ind[2]]== 0 && conePt[ind[2]] < 10) continue;

      

      //Check number of tight leptons
      unsigned tightC = 0;
      unsigned* _isT= new unsigned[_nLeptons];
      for(unsigned l = 0; l < lCount; ++l){
	_isT[ind[l]] = false;
	if (_flavors[ind[l]]== 1 && _ismedium[ind[l]] && _isolation[ind[l]] < 0.1)       _isT[ind[l]] = true;
	if (_flavors[ind[l]]== 0 && _isolation[ind[l]] < 0.1 && _passedMVA90[ind[l]])    _isT[ind[l]] = true;
      }
      
      for(unsigned l = 0; l < lCount; ++l){
	if(_isT[ind[l]]) ++tightC;	
	else break;
      }

      //Check number of prompt leptons MC
      unsigned promptC = 0;
      for(unsigned l = 0; l < lCount; ++l){
	if (effsam != 0 && _originReduced[ind[l]] == 0) promptC++;	
      }
      //cout<<"before   2"<<endl;
      if (effsam != 0 && promptC != 3) continue;
      //cout<<"after   2"<<endl;

      bool tightFail = (tightC < 3);
      //if (tightFail) continue;

      if(tightFail ){
	if (effsam  == 0 )scal *= -1;
	if (effsam  != 0 )scal = 1 * scal;
       
	for(unsigned l = 0; l < lCount; ++l){	

	  if(!_isT[ind[l]] && _isFO[ind[l]]){
	    double fr = FR_factor (*&fakeRate_mu, *&fakeRate_e ,_lEta[ind[l]], _flavors[ind[l]], conePt[ind[l]]);
	    //cout<<l<<")  "<<fr<<endl;
	    scal *= -fr/(1-fr);
	    //cout<<l<<") "<<scal<<endl;
	  }
	}   
      }
      

      if (effsam == 0 && !tightFail) data_sum1++;
      if (effsam != 0 || (effsam == 0 && tightFail)) mc_sum1 = mc_sum1 + scal;

      
      // ========================================== Variables and Analysis or CR cuts
      TLorentzVector lepton_reco[3];
      lepton_reco[0].SetPtEtaPhiE( _lPt[ind[0]],  _lEta[ind[0]], _lPhi[ind[0]], _lE[ind[0]]); 
      lepton_reco[1].SetPtEtaPhiE( _lPt[ind[1]],  _lEta[ind[1]], _lPhi[ind[1]], _lE[ind[1]]); 
      lepton_reco[2].SetPtEtaPhiE( _lPt[ind[2]],  _lEta[ind[2]], _lPhi[ind[2]], _lE[ind[2]]); 
      int flavors_3l[3];
      flavors_3l[0]=_flavors[ind[0]];
      flavors_3l[1]=_flavors[ind[1]];
      flavors_3l[2]=_flavors[ind[2]];
      int charge_3l[3];
      charge_3l[0]=_charges[ind[0]];
      charge_3l[1]=_charges[ind[1]];
      charge_3l[2]=_charges[ind[2]];

      
         
      TLorentzVector sum_3l_rec;
      sum_3l_rec.SetPtEtaPhiE(0,0,0,0);
      sum_3l_rec= (lepton_reco[0]+ lepton_reco[1]+lepton_reco[2] );
      TLorentzVector sum_2l_rec;
      sum_2l_rec.SetPtEtaPhiE(0,0,0,0);
      sum_2l_rec= (lepton_reco[1]+lepton_reco[2]);
      // met and mT
      

      //================== event classification ========================     
      TLorentzVector pair [3];
      int kind[1] ={-1}; // 0 no-ossf
      // 1 ossf
      ossf_no_ossf( kind, pair,lepton_reco[0], lepton_reco[1], lepton_reco[2], flavors_3l, charge_3l);
      if (kind[0]  == -1) continue;  

      TLorentzVector sum_2l_rec_pair;
      sum_2l_rec_pair.SetPtEtaPhiE(0,0,0,0);
      sum_2l_rec_pair= (pair[0]+pair[1] );



      TLorentzVector lepton_transv;
      TLorentzVector METvec;
      double m_T=0;      
      lepton_transv.SetPtEtaPhiE(pair[2].Pt(),0, pair[2].Phi(), pair[2].Pt());
      METvec.SetPtEtaPhiE(_met, 0, _met_phi,_met);        
      m_T= (lepton_transv + METvec).Mag();
    
      //**************************
      bool ossf_event= false;
      if (kind[0] == 1) ossf_event = true;
      bool low_pt_event=false;
      bool high_pt_event = false;
      if (lepton_reco[0].Pt()< 30) low_pt_event= true;
      if (lepton_reco[0].Pt()> 30)  high_pt_event = true;

      int event_clas[1]={-1};
      class_os( event_clas,  flavors_3l, charge_3l);
      if (event_clas[0] == -1) continue;
      
      //cout<<event_clas[0]<<endl;
      
      
      //********************** DELTA R MIN, MAX
      Double_t delta_R_max=-1;
      Double_t delta_R_min=-1;

      delta_R_max = lepton_reco[0].DeltaR(lepton_reco[1]);
      if (lepton_reco[0].DeltaR(lepton_reco[2]) > delta_R_max) delta_R_max = lepton_reco[0].DeltaR(lepton_reco[2]);
      if (lepton_reco[1].DeltaR(lepton_reco[2]) > delta_R_max) delta_R_max = lepton_reco[1].DeltaR(lepton_reco[2]);

      delta_R_min = lepton_reco[0].DeltaR(lepton_reco[1]);
      if (lepton_reco[0].DeltaR(lepton_reco[2]) < delta_R_min) delta_R_min = lepton_reco[0].DeltaR(lepton_reco[2]);
      if (lepton_reco[1].DeltaR(lepton_reco[2]) < delta_R_min) delta_R_min = lepton_reco[1].DeltaR(lepton_reco[2]);
      
       
      //************************** TRIGGER
      // 1* = eee
      // 2* = emm
      // 3* = eem
      // 4* = eet
      // 5* = ett
      // 6* = mmm
      //cout<<"tot:  "<<lowM_trigger_all<<endl;
      //cout<<"eee: "<<lowM_trigger_eee<<endl;
      //cout<<"mmm: "<<lowM_trigger_mmm<<endl;
      //cout<<"eem: "<<lowM_trigger_mee<<endl;
      //cout<<"emm: "<<lowM_trigger_mme<<endl;

     
      bool trigger_fired = false;
      if ((event_clas[0]== 1 ||  event_clas[0]== 10)   &&  (lowM_trigger_all   || lowM_trigger_eee)) trigger_fired = true;
      if ((event_clas[0]== 2 ||  event_clas[0]== 20)   &&  (lowM_trigger_all   || lowM_trigger_mme)) trigger_fired = true;
      if ((event_clas[0]== 3 ||  event_clas[0]== 30)   &&  (lowM_trigger_all   || lowM_trigger_mee)) trigger_fired = true;
      if ((event_clas[0]== 4 ||  event_clas[0]== 40)   &&  (lowM_trigger_all   || lowM_trigger_mmm)) trigger_fired = true;
      
      //if ( !trigger_fired ) cout <<"trigger not fired"<<endl;

      //cout<<event_clas[0]<<"    before   3"<<endl;
      if ( effsam != 1 && !trigger_fired ) continue;
      //cout<<event_clas[0]<<"   after   3"<<endl;


      //////////////// //////////////// //////////////// //////////////// CUT  //////////////// //////////////// //////////////// //////////////// 
      //////////////// CR
      bool CR_dy=false;
      bool CR_ttbar=false;
      bool CR_wz=false;
      bool SR=false;
      
      if (ossf_event){
      	if(nBjets == 0 && _met < 75 && sum_3l_rec.M() < 80  && delta_R_min > 0.05 && delta_R_max > 2 ) SR = true;	
      }
      if (!ossf_event){
      	if(nBjets == 0 && _met < 75 && sum_3l_rec.M() < 80  ) SR = true;
	event_clas[0] = event_clas[0] *0.1;
      }
         
      if (ossf_event){
	if(nBjets == 0 && _met < 30 && m_T < 30 && (fabs(sum_2l_rec_pair.M() - 91.1876) < 15) ) CR_dy = true;
	if(nBjets == 0 && _met > 30 && m_T > 50 && (fabs(sum_2l_rec_pair.M() - 91.1876) < 15) ){
	  if(conePt[ind[0]] > 40 && conePt[ind[1]] > 20 && conePt[ind[2]] > 10)	  CR_wz = true; 	 
	}
      }
      if (!ossf_event && nBjets !=0 ){
	CR_ttbar =true;
	event_clas[0] = event_clas[0] *0.1;
      }
      //////////////// //////////////// //////////////// ////////////////      //////////////// //////////////// //////////////// //////////////// 
      //if (tightFail) continue;
      
      bool data_control_region=false;
      if(effsam == 0 && tightFail)  data_control_region=true;
      bool data_yield=false;
      if (effsam == 0 && tightC == 3) {
	scal = 1;
	data_yield = true;
      }
      double pt_cone_leading=lepton_reco[0].Pt() ;
      double pt_cone_sub_leading=lepton_reco[1].Pt();
      double pt_cone_trailing=lepton_reco[2].Pt();


      double values[nDist] = { pt_cone_leading, pt_cone_sub_leading, pt_cone_trailing,
			       pt_cone_leading+ pt_cone_sub_leading+ pt_cone_trailing,
			       pt_cone_leading+ pt_cone_trailing,
			       pt_cone_sub_leading+ pt_cone_trailing,
			       pt_cone_leading+ pt_cone_sub_leading,
			       sum_3l_rec.M(),sum_2l_rec.M(),sum_2l_rec_pair.M(),
			       _met,m_T,
			       static_cast<double>(_n_Jets), static_cast<double>(nBjets),HT,
			       pair[0].DeltaR(pair[1]),lepton_reco[0].DeltaR(lepton_reco[2]),lepton_reco[1].DeltaR(lepton_reco[2]),
			       _isolation[ind[0]],_isolation[ind[2]],
			       fabs(_ipPV[ind[0]]),fabs(_ipPV[ind[2]]),
			       fabs(_ipZPV[ind[0]]),fabs(_ipZPV[ind[2]]),
			       fabs(_3dIP[ind[0]]), fabs(_3dIP[ind[2]]), static_cast<double>(event_clas[0])};

      unsigned fill = effsam;
      if( data_control_region ) fill = nSamples_eff;
      if (data_yield) fill = 0;
      
      if (data_yield) data_sum2++;
      if (effsam != 0 || data_control_region) mc_sum2 = mc_sum2 + scal;


     

      //************************** OSSF ***********************************
      if (ossf_event && SR){
	for(int numero_histo = 0; numero_histo < nDist; ++numero_histo){
	  Histos[numero_histo][0][fill]->Fill(TMath::Min(values[numero_histo], maxBinC[numero_histo]), scal);
	  if (low_pt_event)Histos[numero_histo][1][fill]->Fill(TMath::Min(values[numero_histo], maxBinC[numero_histo]), scal);       
	  if (high_pt_event) Histos[numero_histo][2][fill]->Fill(TMath::Min(values[numero_histo], maxBinC[numero_histo]), scal);
	   if (numero_histo == 26){
	    Histos[numero_histo][0][fill]->Fill(TMath::Min(0., maxBinC[numero_histo]), scal);
	    if (low_pt_event)Histos[numero_histo][1][fill]->Fill(TMath::Min(0., maxBinC[numero_histo]), scal);       
	    if (high_pt_event) Histos[numero_histo][2][fill]->Fill(TMath::Min(0., maxBinC[numero_histo]), scal);
	  }
	}//end for
      }//end ossf
      //************************** NOSSF ***********************************
     if (!ossf_event && SR){
	for(int numero_histo = 0; numero_histo < nDist; ++numero_histo){
	  Histos[numero_histo][3][fill]->Fill(TMath::Min(values[numero_histo], maxBinC[numero_histo]), scal);
	  if (low_pt_event)Histos[numero_histo][4][fill]->Fill(TMath::Min(values[numero_histo], maxBinC[numero_histo]), scal);       
	  if (high_pt_event) Histos[numero_histo][5][fill]->Fill(TMath::Min(values[numero_histo], maxBinC[numero_histo]), scal);
	   if (numero_histo == 26){
	    Histos[numero_histo][3][fill]->Fill(TMath::Min(0., maxBinC[numero_histo]), scal);
	    if (low_pt_event)Histos[numero_histo][4][fill]->Fill(TMath::Min(0., maxBinC[numero_histo]), scal);       
	    if (high_pt_event) Histos[numero_histo][5][fill]->Fill(TMath::Min(0., maxBinC[numero_histo]), scal);
	  }
	}//end for
      }//end n_ossf
  
    }
  }


 

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
      for(unsigned effsam1 = 2; effsam1 < nSamples_eff + 1; ++effsam1){
	bkgYields[dist][cat][effsam1 -2] = (TH1D*) Histos[dist][cat][effsam1]->Clone();
	if(effsam1 > 2){
	  dataYields[dist][cat]->Add(bkgYields[dist][cat][effsam1 -2]);
	}
      }
    }
  }
  const TString sigNames[1] = {"m_{N} = 40 |V|^{2} = 10^{-5}"};
  TH1D* signals[1];
  //Plot the yields as a function of the search region
  for(unsigned dist = 0; dist < nDist; ++dist){
    for(unsigned cat = 0; cat < nCat; ++cat){
      signals[0] = (TH1D*) Histos[dist][cat][1]->Clone() ;
      plotDataVSMC(dataYields[dist][cat], bkgYields[dist][cat], eff_names, nSamples_eff - 1, Histnames_ossf[dist] + "_" +  catNames[cat], false, 0, true, signals,  sigNames ,1);
    }
  }



  cout<<"data:  "<<data_sum2  <<"  /  "<<data_sum1<<endl;
   cout<<"mc:  "<<mc_sum2  <<"  /  "<<mc_sum1<<endl;

 
}// end analisi






//==================================================================
double Analysis_mc::maximum(double a, double b){
  double massimo=0;
  massimo = a;
  if (massimo < b) massimo = b; 
  return massimo+1; 
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
/*
//==================================================================
double Analysis_mc::fakeWeight(const unsigned ind, const int flavors, const double conePt, const double eta, const bool tight, TH2D* frMap, const unsigned lCount){
	unsigned nFO = 0;
	double fr[4];
	for(unsigned l = 0; l < lCount; ++l){
		if(!tight[ind[l]]){
			fr[nFO] = frMap[flavors[ind[l]]]->GetBinContent(frMap[flavors[ind[l]]]->FindBin(TMath::Min(conePt[l], 99.), fabs(eta[ind[l]])));
			++nFO;
		}
	}
	double weight = 1;
	for(unsigned f = 0; f < nFO; ++f){
		weight *= fr[f]/(1-fr[f]);
	}
	if(nFO == 2) weight*= -1;
	return weight;
}
*/







//==================================================================
double Analysis_mc::FR_factor(TGraphAsymmErrors *fakeRate_mu[3],
			      TGraphAsymmErrors *fakeRate_e[3],
			      double eta,
			      double flavors,
			      double lptcone
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

  //double momentum = part.Pt() * maximum( 1, iso - 0.1);
  double momentum = lptcone;

  double factor=0;
  double factore=0;
  if (flavors == 0){
    if (momentum < 70){
      if (eta < 0.8){
	factore = fakeRate_e_histo[0]->GetBinContent(fakeRate_e_histo[0]->FindBin(momentum));
      }//eta1
      else if (eta > 0.8 && eta<1.479){
	factore = fakeRate_e_histo[1]->GetBinContent(fakeRate_e_histo[1]->FindBin(momentum));
      }//eta1
      else {
	factore = fakeRate_e_histo[2]->GetBinContent(fakeRate_e_histo[2]->FindBin(momentum));
      }//eta1
    }// <70
    else {
      if (eta < 0.8){
	factore = fakeRate_e_histo[0]->GetBinContent(fakeRate_e_histo[0]->FindBin(68));
      }//eta1
      else if (eta > 0.8 && eta<1.479){
	factore = fakeRate_e_histo[1]->GetBinContent(fakeRate_e_histo[1]->FindBin(68));
      }//eta1
      else {
	factore = fakeRate_e_histo[2]->GetBinContent(fakeRate_e_histo[2]->FindBin(68));
      }//eta1
    }
  }//e

  if (flavors == 1){
    if (momentum < 70){
      if (eta < 0.8){
	factore = fakeRate_mu_histo[0]->GetBinContent(fakeRate_mu_histo[0]->FindBin(momentum));
      }//eta1
      else if (eta > 0.8 && eta<1.479){
	factore = fakeRate_mu_histo[1]->GetBinContent(fakeRate_mu_histo[1]->FindBin(momentum));
      }//eta1
      else {
	factore = fakeRate_mu_histo[2]->GetBinContent(fakeRate_mu_histo[2]->FindBin(momentum));
      }//eta1
    }// <70
    else {
      if (eta < 0.8){
	factore = fakeRate_mu_histo[0]->GetBinContent(fakeRate_mu_histo[0]->FindBin(68));
      }//eta1
      else if (eta > 0.8 && eta<1.479){
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


  
  return factore;

}




//___________________________________________________________________
void Analysis_mc::class_os(int event_clas[1], int  flavors_3l[3], int  charge_3l[3]){
    
  int ch_lepton1=charge_3l[0];
  int ch_lepton2=charge_3l[1];
  int ch_lepton3=charge_3l[2];
  int fl_lepton1=flavors_3l[0];
  int fl_lepton2=flavors_3l[1];
  int fl_lepton3=flavors_3l[2];


  // 1* = eee
  // 2* = emm
  // 3* = eem
  // 4* = mmm

  


    
  event_clas[0]=-1;


  if (ch_lepton1 == ch_lepton2 && ch_lepton1 == ch_lepton3 && ch_lepton3 == ch_lepton2)   event_clas[0]=-1;


  if (fl_lepton2 == 0 ||  fl_lepton3  == 0 ||  fl_lepton1== 0) {
    if ((fl_lepton2 + fl_lepton3 + fl_lepton1) == 0 ) event_clas[0] = 10; //e e e
    if ((fl_lepton2 + fl_lepton3 + fl_lepton1) == 1 ) event_clas[0] = 30; //e e mu
    if ((fl_lepton2 + fl_lepton3 + fl_lepton1) == 2 ) {
      if (fl_lepton2 == 1 ||  fl_lepton3  == 1 ||  fl_lepton1== 1) event_clas[0]=20; // e mu mu
    }
  }// at least an electron
  else if (fl_lepton2 == 1 &&  fl_lepton3  == 1 &&  fl_lepton1 == 1) {
    event_clas[0] = 40;
  }
  else {
    event_clas[0] =-1;
  }

  if (event_clas[0]  == 30){
    if ((fl_lepton1 == 0 && fl_lepton2 == 0 && fl_lepton3 == 1) ) { // e e mu
      if ((ch_lepton1 + ch_lepton2) == 0) event_clas[0] = 3;
    }
    if (fl_lepton1 == 0 && fl_lepton2 == 1 && fl_lepton3 == 0) { // e mu e
      if ((ch_lepton1 + ch_lepton3) == 0) event_clas[0] = 3;
    }
    if (fl_lepton1 == 1 && fl_lepton2 == 0 && fl_lepton3 == 0 ) { // mu e e
      if ((ch_lepton2 + ch_lepton3) == 0) event_clas[0] = 3;
    }
  }
  
 
  if (event_clas[0]  == 20){
    if ((fl_lepton1 == 1 && fl_lepton2 == 1 && fl_lepton3 == 0) ) { // e e mu
      if ((ch_lepton1 + ch_lepton2) == 0) event_clas[0] = 2;
    }
    if (fl_lepton1 == 1 && fl_lepton2 == 0 && fl_lepton3 == 1 ) { // e mu e
      if ((ch_lepton1 + ch_lepton3) == 0) event_clas[0] = 2;
    }
    if (fl_lepton1 == 0 && fl_lepton2 == 1 && fl_lepton3 == 1 ) { // mu e e
      if  ((ch_lepton2 + ch_lepton3) == 0)event_clas[0] = 2;
    }
  }


  if (event_clas[0]  == 10 ) {
    if ((ch_lepton1 + ch_lepton2 + ch_lepton3) == 1 || (ch_lepton1 + ch_lepton2 + ch_lepton3) == -1)  event_clas[0] =1;
  }

  if (event_clas[0]  == 40 ) {
    if ((ch_lepton1 + ch_lepton2 + ch_lepton3) == 1 || (ch_lepton1 + ch_lepton2 + ch_lepton3) == -1)  event_clas[0] =4;
  }


}



//___________________________________________________________________
void Analysis_mc::ossf_no_ossf(int kind[1],TLorentzVector pair[3],TLorentzVector leep1, TLorentzVector leep2,TLorentzVector leep3, int  flavors_3l[3], int  charge_3l[3]){
    
  int ch_lepton1=charge_3l[0];
  int ch_lepton2=charge_3l[1];
  int ch_lepton3=charge_3l[2];
  int fl_lepton1=flavors_3l[0];
  int fl_lepton2=flavors_3l[1];
  int fl_lepton3=flavors_3l[2];
    
    
  kind[0] = -1;

  if (ch_lepton1 == ch_lepton2 && ch_lepton1 == ch_lepton3 && ch_lepton3 == ch_lepton2)   kind[0] = -1;

    
  // OSSF
  if (     ((ch_lepton1 + ch_lepton2) == 0   && (fl_lepton1 == fl_lepton2))  || ((ch_lepton1 + ch_lepton3) == 0   && (fl_lepton1 == fl_lepton3)) || ((ch_lepton3 + ch_lepton2) == 0   && (fl_lepton3 == fl_lepton2)) ){ // ossf
    //cout<<"in function where kind is 1: "<<kind[0]<<endl;
    kind[0] = 1;
    double i_m[3]={33333,33333,33333};
    double mass_inv=0;
    int index_inv=100;
    double min_mass=999;
    if ((ch_lepton1 + ch_lepton2) == 0 && (fl_lepton1 == fl_lepton2)) i_m[0]= TMath:: Abs((leep1 + leep2).Mag() - 91.1876);
    if ((ch_lepton1 + ch_lepton3) == 0 && (fl_lepton1 == fl_lepton3)) i_m[1]= TMath:: Abs((leep1 + leep3).Mag() - 91.1876);
    if ((ch_lepton2 + ch_lepton3) == 0 && (fl_lepton3 == fl_lepton2)) i_m[2]= TMath:: Abs((leep2 + leep3).Mag() - 91.1876);
    for (int i =0; i < 3; i++){
      if (i_m[i] == 33333) continue;
      mass_inv = i_m[i];
      if (min_mass > mass_inv ){
	min_mass = mass_inv;
	index_inv = i;
      }
    }
    if (index_inv == 0) {
      pair[0].SetPtEtaPhiE( leep1.Pt(),  leep1.Eta(), leep1.Phi(), leep1.E());
      pair[1].SetPtEtaPhiE( leep2.Pt(),  leep2.Eta(), leep2.Phi(), leep2.E());
      pair[2].SetPtEtaPhiE( leep3.Pt(),  leep3.Eta(), leep3.Phi(), leep3.E());
    }
    if (index_inv == 1) {
      pair[0].SetPtEtaPhiE( leep1.Pt(),  leep1.Eta(), leep1.Phi(), leep1.E());
      pair[1].SetPtEtaPhiE( leep3.Pt(),  leep3.Eta(), leep3.Phi(), leep3.E());
      pair[2].SetPtEtaPhiE( leep2.Pt(),  leep2.Eta(), leep2.Phi(), leep2.E());

    }
    if (index_inv == 2) {
      pair[0].SetPtEtaPhiE( leep2.Pt(),  leep2.Eta(), leep2.Phi(), leep2.E());
      pair[1].SetPtEtaPhiE( leep3.Pt(),  leep3.Eta(), leep3.Phi(), leep3.E());
      pair[2].SetPtEtaPhiE( leep1.Pt(),  leep1.Eta(), leep1.Phi(), leep1.E());

    }
  }// end ossf
  // No_OSSF
  else if (   ((ch_lepton1 + ch_lepton2) == 0  )  || ((ch_lepton1 + ch_lepton3) == 0   ) || ((ch_lepton3 + ch_lepton2) == 0   )   ){
    //cout<<"in function where kind is 0: "<<kind[0]<<endl;

    kind[0] = 0;
    double i_m[3]={33333,33333,33333};
    double mass_inv=0;
    int index_inv=100;
    double min_mass=999;
    if ((ch_lepton1 + ch_lepton2) == 0 ) i_m[0]= TMath:: Abs((leep1 + leep2).Mag() - 91.1876);
    if ((ch_lepton1 + ch_lepton3) == 0 ) i_m[1]= TMath:: Abs((leep1 + leep3).Mag() - 91.1876);
    if ((ch_lepton2 + ch_lepton3) == 0 ) i_m[2]= TMath:: Abs((leep2 + leep3).Mag() - 91.1876);
    for (int i =0; i < 3; i++){
      if (i_m[i] == 33333) continue;
      mass_inv = i_m[i];
      if (min_mass > mass_inv ){
	min_mass = mass_inv;
	index_inv = i;
      }
    }
     if (index_inv == 0) {
      pair[0].SetPtEtaPhiE( leep1.Pt(),  leep1.Eta(), leep1.Phi(), leep1.E());
      pair[1].SetPtEtaPhiE( leep2.Pt(),  leep2.Eta(), leep2.Phi(), leep2.E());
      pair[2].SetPtEtaPhiE( leep3.Pt(),  leep3.Eta(), leep3.Phi(), leep3.E());
    }
    if (index_inv == 1) {
      pair[0].SetPtEtaPhiE( leep1.Pt(),  leep1.Eta(), leep1.Phi(), leep1.E());
      pair[1].SetPtEtaPhiE( leep3.Pt(),  leep3.Eta(), leep3.Phi(), leep3.E());
      pair[2].SetPtEtaPhiE( leep2.Pt(),  leep2.Eta(), leep2.Phi(), leep2.E());

    }
    if (index_inv == 2) {
      pair[0].SetPtEtaPhiE( leep2.Pt(),  leep2.Eta(), leep2.Phi(), leep2.E());
      pair[1].SetPtEtaPhiE( leep3.Pt(),  leep3.Eta(), leep3.Phi(), leep3.E());
      pair[2].SetPtEtaPhiE( leep1.Pt(),  leep1.Eta(), leep1.Phi(), leep1.E());

    }
        
        
  }//end no-ossf
    
    
  /*
    cout<< ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   "<<kind<<endl;
    cout<<"1: "<<ch_lepton1<<"  "<<fl_lepton1<< "  "<< leep1.Pt()<< endl;
    cout<<"2: "<<ch_lepton2<<"  "<<fl_lepton2<< "  "<< leep2.Pt()<< endl;
    cout<<"3: "<<ch_lepton3<<"  "<<fl_lepton3<< "  "<< leep3.Pt()<< endl;
    cout<<"pair 1: "<<pair1.Pt()<< endl;
    cout<<"pair 2: "<<pair2.Pt()<< endl;
  */
  //cout<<"in function "<<kind[0]<<endl;
}





//___________________________________________________________________
void Analysis_mc::fr_selection(int number, TLorentzVector lepton_fake_order[3],TLorentzVector leep1, TLorentzVector leep2,TLorentzVector leep3, int index_leptons[3],  int flavor_leptons[3], int origin_leptons[3],int index_3l[3],  int flavor_3l[3], int origin_3l[3]){

  lepton_fake_order[0].SetPtEtaPhiE(0,0,0,0);
  lepton_fake_order[1].SetPtEtaPhiE(0,0,0,0);
  lepton_fake_order[2].SetPtEtaPhiE(0,0,0,0);
  for(int i =0; i< 3; i++){
    index_leptons[i]=  -5;
    flavor_leptons[i]= -5;
    origin_leptons[i]= -5;
  }

  if (number == 3) {
    lepton_fake_order[0].SetPtEtaPhiE(leep1.Pt(),leep1.Eta(),leep1.Phi(),leep1.E());
    lepton_fake_order[1].SetPtEtaPhiE(leep2.Pt(),leep2.Eta(),leep2.Phi(),leep2.E());
    lepton_fake_order[2].SetPtEtaPhiE(leep3.Pt(),leep3.Eta(),leep3.Phi(),leep3.E());
    index_leptons[0]=index_3l[0];
    index_leptons[1]=index_3l[1];
    index_leptons[2]=index_3l[2];
    flavor_leptons[0]=flavor_3l[0];
    flavor_leptons[1]=flavor_3l[1];
    flavor_leptons[2]=flavor_3l[2];
    origin_leptons[0]=origin_3l[0];
    origin_leptons[1]=origin_3l[1];
    origin_leptons[2]=origin_3l[2];
  }
  if (number == 0) {
    lepton_fake_order[0].SetPtEtaPhiE(leep1.Pt(),leep1.Eta(),leep1.Phi(),leep1.E());
    lepton_fake_order[1].SetPtEtaPhiE(leep2.Pt(),leep2.Eta(),leep2.Phi(),leep2.E());
    lepton_fake_order[2].SetPtEtaPhiE(leep3.Pt(),leep3.Eta(),leep3.Phi(),leep3.E());
    index_leptons[0]=index_3l[0];
    index_leptons[1]=index_3l[1];
    index_leptons[2]=index_3l[2];
    flavor_leptons[0]=flavor_3l[0];
    flavor_leptons[1]=flavor_3l[1];
    flavor_leptons[2]=flavor_3l[2];
    origin_leptons[0]=origin_3l[0];
    origin_leptons[1]=origin_3l[1];
    origin_leptons[2]=origin_3l[2];
  }

  

}//end fr
