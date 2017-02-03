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
#include <Analysis.h>
#include <Analysis_signal.h>
#include <Analysis_mc.h>
#include <THStack.h>
#include <TPaveText.h>
#include <THStack.h>


using namespace std;
const int num_histo_kin= 3;
const int num_histo= 12;



//__________________________________________________________
void cosmesi_sample(Int_t numero,TH1D *histo_positive){
    
    
    histo_positive->GetYaxis()->SetNdivisions(506);
    histo_positive->GetXaxis()->SetNdivisions(506);
    histo_positive->SetMinimum(0);
    
    histo_positive->SetTitle("");
    
    //histo_positive->Scale(1/histo_positive->Integral());
    
    //isto_positive->GetXaxis()->SetTitleOffset(0.75);
    //histo_positive->GetXaxis()->SetTitleSize(0.05);
    histo_positive->GetXaxis() ->SetTitleFont(132);
    //histo_positive->GetXaxis()->SetLabelSize(0.04);
    //histo_positive->GetXaxis()->SetLabelOffset(0.005);
    histo_positive->GetXaxis()->SetLabelFont(132);
    
    histo_positive->GetYaxis()->SetLabelFont(132);
    
    histo_positive->GetYaxis()->SetNdivisions(506);
    
    //histo_positive->	GetYaxis ()->SetTitleOffset(0.75);
    //histo_positive->	GetYaxis()->SetTitleSize(0.06);
    histo_positive->	GetYaxis() ->SetTitleFont(132);
    //histo_positive->GetYaxis()->SetLabelOffset(0.005);
    // histo_positive->GetYaxis()->SetLabelSize(0.04);
    
    if (numero == 1){
        histo_positive->SetLineColor(kRed);
    }
    if (numero == 2 ){
        histo_positive->SetLineColor(kBlue);
    }
    if (numero == 3){
        histo_positive->SetLineColor(8);
    }
    if (numero == 4 ){
        //histo_positive->SetLineStyle(9);
        histo_positive->SetLineColor(kOrange);
    }
    if (numero == 5){
        //histo_positive->SetLineStyle(9);
        histo_positive->SetLineColor(kMagenta);
    }
    if (numero == 6){
        //histo_positive->SetLineStyle(9);
        histo_positive->SetLineColor(kBlack);
    }
    if (numero == 7){
        //histo_positive->SetLineStyle(9);
        histo_positive->SetLineColor(kGray+2);
    }
}//end cosmesi






void majo (string inputRootFile= "file_mva_gen1.root");


// ********************************************************************
void majo(string inputRootFile){
    Double_t pigreco= TMath::ACos(-1);
    
    cout<<"in analisi"<<endl;
    cout<<"---------------------------"<<endl;
    
    //============ delta r 2d================
    TH2D *wg_2d_ossf= new TH2D ("wg_2d_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *wz_2d_ossf= new TH2D ("wz_2d_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *zg_2d_ossf= new TH2D ("zg_2d_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *tt_2d_ossf= new TH2D ("tt_2d_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *dy1_2d_ossf= new TH2D ("dy1_2d_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *dy2_2d_ossf= new TH2D ("dy2_2d_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *dy1_2d_n_ossf= new TH2D ("dy1_2d_n_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *dy2_2d_n_ossf= new TH2D ("dy2_2d_n_ossf", "", 40, 0, 4, 40, 0, 4);
    
    TH2D *wg_2d_n_ossf= new TH2D ("wg_2d_n_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *wz_2d_n_ossf= new TH2D ("wz_2d_n_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *zg_2d_n_ossf= new TH2D ("zg_2d_n_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *tt_2d_n_ossf= new TH2D ("tt_2d_n_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *signal_10_2d_ossf= new TH2D ("signal_10_2d_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *signal_15_2d_ossf= new TH2D ("signal_15_2d_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *signal_5_2d_ossf= new TH2D ("signal_5_2d_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *signal_40_2d_ossf= new TH2D ("signal_40_2d_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *signal_60_2d_ossf= new TH2D ("signal_60_2d_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *signal_20_2d_ossf= new TH2D ("signal_20_2d_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *signal_50_2d_ossf= new TH2D ("signal_50_2d_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *signal_10_2d_n_ossf= new TH2D ("signal_10_2d_n_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *signal_15_2d_n_ossf= new TH2D ("signal_15_2d_n_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *signal_5_2d_n_ossf= new TH2D ("signal_5_2d_n_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *signal_40_2d_n_ossf= new TH2D ("signal_40_2d_n_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *signal_60_2d_n_ossf= new TH2D ("signal_60_2d_n_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *signal_20_2d_n_ossf= new TH2D ("signal_20_2d_n_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *signal_50_2d_n_ossf= new TH2D ("signal_50_2d_n_ossf", "", 40, 0, 4, 40, 0, 4);
    TH2D *signal_10_2d_pt_ossf= new TH2D ("signal_10_2d_pt_ossf", "", 100,0,50,200,0,100);
    TH2D *signal_15_2d_pt_ossf= new TH2D ("signal_15_2d_pt_ossf", "", 100,0,50,200,0,100);
    TH2D *signal_5_2d_pt_ossf= new TH2D ("signal_5_2d_pt_ossf", "", 100,0,50,200,0,100);
    TH2D *signal_40_2d_pt_ossf= new TH2D ("signal_40_2d_pt_ossf", "", 100,0,50,200,0,100);
    TH2D *signal_60_2d_pt_ossf= new TH2D ("signal_60_2d_pt_ossf", "", 100,0,50,200,0,100);
    TH2D *signal_20_2d_pt_ossf= new TH2D ("signal_20_2d_pt_ossf", "", 100,0,50,200,0,100);
    TH2D *signal_50_2d_pt_ossf= new TH2D ("signal_50_2d_pt_ossf", "", 100,0,50,200,0,100);
    TH2D *signal_10_2d_pt_n_ossf= new TH2D ("signal_10_2d_pt_n_ossf", "", 100,0,50,200,0,100);
    TH2D *signal_15_2d_pt_n_ossf= new TH2D ("signal_15_2d_pt_n_ossf", "", 100,0,50,200,0,100);
    TH2D *signal_5_2d_pt_n_ossf= new TH2D ("signal_5_2d_pt_n_ossf", "", 100,0,50,200,0,100);
    TH2D *signal_40_2d_pt_n_ossf= new TH2D ("signal_40_2d_pt_n_ossf", "", 100,0,50,200,0,100);
    TH2D *signal_60_2d_pt_n_ossf= new TH2D ("signal_60_2d_pt_n_ossf", "", 100,0,50,200,0,100);
    TH2D *signal_20_2d_pt_n_ossf= new TH2D ("signal_20_2d_pt_n_ossf", "", 100,0,50,200,0,100);
    TH2D *signal_50_2d_pt_n_ossf= new TH2D ("signal_50_2d_pt_n_ossf", "", 100,0,50,200,0,100);
    
    
    // ================= flavor stuff ================
    
    TH1D *flavor_plot_signal_50_ossf = new TH1D ("flavor_plot_signal_50_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_signal_20_ossf = new TH1D ("flavor_plot_signal_20_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_signal_50_n_ossf = new TH1D ("flavor_plot_signal_50_n_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_signal_20_n_ossf = new TH1D ("flavor_plot_signal_20_n_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_signal_10_ossf = new TH1D ("flavor_plot_signal_10_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_signal_10_n_ossf = new TH1D ("flavor_plot_signal_10_n_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_signal_15_ossf = new TH1D ("flavor_plot_signal_15_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_signal_15_n_ossf = new TH1D ("flavor_plot_signal_15_n_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_signal_60_ossf = new TH1D ("flavor_plot_signal_60_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_signal_40_ossf = new TH1D ("flavor_plot_signal_40_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_signal_60_n_ossf = new TH1D ("flavor_plot_signal_60_n_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_signal_40_n_ossf = new TH1D ("flavor_plot_signal_40_n_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_signal_5_ossf = new TH1D ("flavor_plot_signal_5_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_signal_5_n_ossf = new TH1D ("flavor_plot_signal_5_n_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_zg_ossf = new TH1D ("flavor_plot_zg_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_zg_n_ossf = new TH1D ("flavor_plot_zg_n_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_tt_ossf = new TH1D ("flavor_plot_tt_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_tt_n_ossf = new TH1D ("flavor_plot_tt_n_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_wg_ossf = new TH1D ("flavor_plot_wg_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_wg_n_ossf = new TH1D ("flavor_plot_wg_n_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_wz_ossf = new TH1D ("flavor_plot_wz_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_wz_n_ossf = new TH1D ("flavor_plot_wz_n_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_dy1_ossf = new TH1D ("flavor_plot_dy1_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_dy1_n_ossf = new TH1D ("flavor_plot_dy1_n_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_dy2_ossf = new TH1D ("flavor_plot_dy2_ossf", "", 7, 0.5, 7.5);
    TH1D *flavor_plot_dy2_n_ossf = new TH1D ("flavor_plot_dy2_n_ossf", "", 7, 0.5, 7.5);
    THStack *hs_ossf_flavor, *hs_n_ossf_flavor;
    hs_ossf_flavor = new THStack("hs_ossf_flavor","");
    hs_n_ossf_flavor = new THStack("hs_n_ossf_flavor","");
    
    
    //========================= HISTO STACK ============================================
    
    THStack *hs_ossf_rec_pt_l1, *hs_ossf_rec_eta_l1, *hs_ossf_rec_phi_l1  ;
    THStack *hs_ossf_rec_pt_l2, *hs_ossf_rec_eta_l2, *hs_ossf_rec_phi_l2  ;
    THStack *hs_ossf_rec_pt_l3, *hs_ossf_rec_eta_l3, *hs_ossf_rec_phi_l3  ;
    THStack *hs_ossf_gen_pt_l1, *hs_ossf_gen_eta_l1, *hs_ossf_gen_phi_l1  ;
    THStack *hs_ossf_gen_pt_l2, *hs_ossf_gen_eta_l2, *hs_ossf_gen_phi_l2  ;
    THStack *hs_ossf_gen_pt_l3, *hs_ossf_gen_eta_l3, *hs_ossf_gen_phi_l3  ;
    THStack *hs_ossf_rec_met, *hs_ossf_rec_mT, *hs_ossf_rec_mlll, *hs_ossf_rec_mll, *hs_ossf_rec_mll_pair, *hs_ossf_gen_mll_pair;
    THStack *hs_ossf_gen_met, *hs_ossf_gen_mT, *hs_ossf_gen_mlll, *hs_ossf_gen_mll   ;
    THStack *hs_ossf_rec_nJet, *hs_ossf_rec_nbJet, *hs_ossf_rec_HT, *hs_ossf_rec_jetPt, *hs_ossf_rec_jetEta, *hs_ossf_rec_jetPhi, *hs_ossf_rec_jetFlavour   ;
    
    
    
    hs_ossf_rec_pt_l1 = new THStack("hs_ossf_rec_pt_l1","");
    hs_ossf_rec_pt_l2 = new THStack("hs_ossf_rec_pt_l2","");
    hs_ossf_rec_pt_l3 = new THStack("hs_ossf_rec_pt_l3","");
    hs_ossf_gen_pt_l1 = new THStack("hs_ossf_gen_pt_l1","");
    hs_ossf_gen_pt_l2 = new THStack("hs_ossf_gen_pt_l2","");
    hs_ossf_gen_pt_l3 = new THStack("hs_ossf_gen_pt_l3","");
    
    hs_ossf_rec_met = new THStack("hs_ossf_rec_met","");
    hs_ossf_gen_met = new THStack("hs_ossf_gen_met","");
    hs_ossf_rec_mT = new THStack("hs_ossf_rec_mT","");
    hs_ossf_gen_mT = new THStack("hs_ossf_gen_mT","");
    hs_ossf_rec_mlll = new THStack("hs_ossf_rec_mlll","");
    hs_ossf_gen_mlll = new THStack("hs_ossf_gen_mlll","");
    hs_ossf_rec_mll = new THStack("hs_ossf_rec_mll","");
    hs_ossf_gen_mll = new THStack("hs_ossf_gen_mll","");
    hs_ossf_rec_mll_pair = new THStack("hs_ossf_rec_mll_pair","");
    hs_ossf_gen_mll_pair = new THStack("hs_ossf_gen_mll_pair","");
    
    hs_ossf_rec_nJet = new THStack("hs_ossf_rec_nJet","");
    hs_ossf_rec_nbJet = new THStack("hs_ossf_rec_nbJet","");
    hs_ossf_rec_HT = new THStack("hs_ossf_rec_HT","");
    hs_ossf_rec_jetPt = new THStack("hs_ossf_rec_jetPt","");
    hs_ossf_rec_jetEta = new THStack("hs_ossf_rec_jetEta","");
    hs_ossf_rec_jetPhi = new THStack("hs_ossf_rec_jetPhi","");
    hs_ossf_rec_jetFlavour = new THStack("hs_ossf_rec_jetFlavour","");
    //========================= HISTO STACK ============================================
    
    THStack *hs_n_ossf_rec_pt_l1, *hs_n_ossf_rec_eta_l1, *hs_n_ossf_rec_phi_l1  ;
    THStack *hs_n_ossf_rec_pt_l2, *hs_n_ossf_rec_eta_l2, *hs_n_ossf_rec_phi_l2  ;
    THStack *hs_n_ossf_rec_pt_l3, *hs_n_ossf_rec_eta_l3, *hs_n_ossf_rec_phi_l3  ;
    THStack *hs_n_ossf_gen_pt_l1, *hs_n_ossf_gen_eta_l1, *hs_n_ossf_gen_phi_l1  ;
    THStack *hs_n_ossf_gen_pt_l2, *hs_n_ossf_gen_eta_l2, *hs_n_ossf_gen_phi_l2  ;
    THStack *hs_n_ossf_gen_pt_l3, *hs_n_ossf_gen_eta_l3, *hs_n_ossf_gen_phi_l3  ;
    THStack *hs_n_ossf_rec_met, *hs_n_ossf_rec_mT, *hs_n_ossf_rec_mlll, *hs_n_ossf_rec_mll,  *hs_n_ossf_rec_mll_pair, *hs_n_ossf_gen_mll_pair;
    THStack *hs_n_ossf_gen_met, *hs_n_ossf_gen_mT, *hs_n_ossf_gen_mlll, *hs_n_ossf_gen_mll   ;
    THStack *hs_n_ossf_rec_nJet, *hs_n_ossf_rec_nbJet, *hs_n_ossf_rec_HT, *hs_n_ossf_rec_jetPt, *hs_n_ossf_rec_jetEta, *hs_n_ossf_rec_jetPhi, *hs_n_ossf_rec_jetFlavour   ;
    
    
    
    hs_n_ossf_rec_pt_l1 = new THStack("hs_n_ossf_rec_pt_l1","");
    hs_n_ossf_rec_pt_l2 = new THStack("hs_n_ossf_rec_pt_l2","");
    hs_n_ossf_rec_pt_l3 = new THStack("hs_n_ossf_rec_pt_l3","");
    hs_n_ossf_gen_pt_l1 = new THStack("hs_n_ossf_gen_pt_l1","");
    hs_n_ossf_gen_pt_l2 = new THStack("hs_n_ossf_gen_pt_l2","");
    hs_n_ossf_gen_pt_l3 = new THStack("hs_n_ossf_gen_pt_l3","");
    
    hs_n_ossf_rec_met = new THStack("hs_n_ossf_rec_met","");
    hs_n_ossf_gen_met = new THStack("hs_n_ossf_gen_met","");
    hs_n_ossf_rec_mT = new THStack("hs_n_ossf_rec_mT","");
    hs_n_ossf_gen_mT = new THStack("hs_n_ossf_gen_mT","");
    hs_n_ossf_rec_mlll = new THStack("hs_n_ossf_rec_mlll","");
    hs_n_ossf_gen_mlll = new THStack("hs_n_ossf_gen_mlll","");
    hs_n_ossf_rec_mll = new THStack("hs_n_ossf_rec_mll","");
    hs_n_ossf_gen_mll = new THStack("hs_n_ossf_gen_mll","");
    hs_n_ossf_rec_mll_pair = new THStack("hs_ossf_rec_mll_pair","");
    hs_n_ossf_gen_mll_pair = new THStack("hs_ossf_gen_mll_pair","");
    
    hs_n_ossf_rec_nJet = new THStack("hs_n_ossf_rec_nJet","");
    hs_n_ossf_rec_nbJet = new THStack("hs_n_ossf_rec_nbJet","");
    hs_n_ossf_rec_HT = new THStack("hs_n_ossf_rec_HT","");
    hs_n_ossf_rec_jetPt = new THStack("hs_n_ossf_rec_jetPt","");
    hs_n_ossf_rec_jetEta = new THStack("hs_n_ossf_rec_jetEta","");
    hs_n_ossf_rec_jetPhi = new THStack("hs_n_ossf_rec_jetPhi","");
    hs_n_ossf_rec_jetFlavour = new THStack("hs_n_ossf_rec_jetFlavour","");
    
    
    int nbin=50;
    
    /////////////////// 1 signal_50_ossf /////////////////////////
    static TH1D* histo_signal_50_ossf_kin_rec_l1[4];
    static TH1D* histo_signal_50_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_signal_50_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_signal_50_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_signal_50_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_signal_50_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_signal_50_ossf_rec[num_histo];
    static TH1D* histo_signal_50_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_signal_50_ossf_kin_rec_l1[0] = new TH1D("h_signal_50_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_50_ossf_kin_rec_l1[1] = new TH1D("h_signal_50_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_50_ossf_kin_rec_l1[2] = new TH1D("h_signal_50_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_50_ossf_kin_rec_l1[3] = new TH1D("h_signal_50_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_signal_50_ossf_kin_rec_l2[0] = new TH1D("h_signal_50_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_50_ossf_kin_rec_l2[1] = new TH1D("h_signal_50_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_50_ossf_kin_rec_l2[2] = new TH1D("h_signal_50_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_50_ossf_kin_rec_l3[0] = new TH1D("h_signal_50_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_50_ossf_kin_rec_l3[1] = new TH1D("h_signal_50_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_50_ossf_kin_rec_l3[2] = new TH1D("h_signal_50_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_50_ossf_rec[0] = new TH1D ("h_signal_50_ossf_rec_met", "", nbin, 0, 100);
    histo_signal_50_ossf_rec[1] = new TH1D ("h_signal_50_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_signal_50_ossf_rec[2] = new TH1D ("h_signal_50_ossf_rec_lll", "", nbin, 0, 100);
    histo_signal_50_ossf_rec[3] = new TH1D ("h_signal_50_ossf_rec_ll", "", nbin, 0, 100);
    histo_signal_50_ossf_rec[4] = new TH1D ("h_signal_50_ossf_rec_nJet", "", 10, 0, 10);
    histo_signal_50_ossf_rec[5] = new TH1D ("h_signal_50_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_signal_50_ossf_rec[6] = new TH1D ("h_signal_50_ossf_rec_HT", "", nbin, 0, 100);
    histo_signal_50_ossf_rec[7] = new TH1D ("h_signal_50_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_signal_50_ossf_rec[8] = new TH1D ("h_signal_50_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_signal_50_ossf_rec[9] = new TH1D ("h_signal_50_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_signal_50_ossf_rec[10] = new TH1D ("h_signal_50_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_signal_50_ossf_rec[11] = new TH1D ("h_signal_50_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_signal_50_ossf_kin_gen_l1[0] = new TH1D("h_signal_50_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_50_ossf_kin_gen_l1[1] = new TH1D("h_signal_50_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_50_ossf_kin_gen_l1[2] = new TH1D("h_signal_50_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_50_ossf_kin_gen_l2[0] = new TH1D("h_signal_50_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_50_ossf_kin_gen_l2[1] = new TH1D("h_signal_50_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_50_ossf_kin_gen_l2[2] = new TH1D("h_signal_50_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_50_ossf_kin_gen_l3[0] = new TH1D("h_signal_50_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_50_ossf_kin_gen_l3[1] = new TH1D("h_signal_50_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_50_ossf_kin_gen_l3[2] = new TH1D("h_signal_50_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_50_ossf_gen[0] = new TH1D ("h_signal_50_ossf_gen_met", "", nbin, 0, 100);
    histo_signal_50_ossf_gen[1] = new TH1D ("h_signal_50_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_signal_50_ossf_gen[2] = new TH1D ("h_signal_50_ossf_gen_lll", "", nbin, 0, 100);
    histo_signal_50_ossf_gen[3] = new TH1D ("h_signal_50_ossf_gen_ll", "", nbin, 0, 100);
    histo_signal_50_ossf_gen[4] = new TH1D ("h_signal_50_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_signal_50_ossf_kin_rec_l1[i]->Sumw2();
        histo_signal_50_ossf_kin_rec_l2[i]->Sumw2();
        histo_signal_50_ossf_kin_rec_l3[i]->Sumw2();
        histo_signal_50_ossf_kin_gen_l1[i]->Sumw2();
        histo_signal_50_ossf_kin_gen_l2[i]->Sumw2();
        histo_signal_50_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_signal_50_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_signal_50_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 signal_50_n_ossf /////////////////////////
    static TH1D* histo_signal_50_n_ossf_kin_rec_l1[4];
    static TH1D* histo_signal_50_n_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_signal_50_n_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_signal_50_n_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_signal_50_n_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_signal_50_n_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_signal_50_n_ossf_rec[num_histo];
    static TH1D* histo_signal_50_n_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_signal_50_n_ossf_kin_rec_l1[0] = new TH1D("h_signal_50_n_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_50_n_ossf_kin_rec_l1[1] = new TH1D("h_signal_50_n_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_50_n_ossf_kin_rec_l1[2] = new TH1D("h_signal_50_n_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_50_n_ossf_kin_rec_l1[3] = new TH1D("h_signal_50_n_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_signal_50_n_ossf_kin_rec_l2[0] = new TH1D("h_signal_50_n_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_50_n_ossf_kin_rec_l2[1] = new TH1D("h_signal_50_n_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_50_n_ossf_kin_rec_l2[2] = new TH1D("h_signal_50_n_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_50_n_ossf_kin_rec_l3[0] = new TH1D("h_signal_50_n_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_50_n_ossf_kin_rec_l3[1] = new TH1D("h_signal_50_n_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_50_n_ossf_kin_rec_l3[2] = new TH1D("h_signal_50_n_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_50_n_ossf_rec[0] = new TH1D ("h_signal_50_n_ossf_rec_met", "", nbin, 0, 100);
    histo_signal_50_n_ossf_rec[1] = new TH1D ("h_signal_50_n_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_signal_50_n_ossf_rec[2] = new TH1D ("h_signal_50_n_ossf_rec_lll", "", nbin, 0, 100);
    histo_signal_50_n_ossf_rec[3] = new TH1D ("h_signal_50_n_ossf_rec_ll", "", nbin, 0, 100);
    histo_signal_50_n_ossf_rec[4] = new TH1D ("h_signal_50_n_ossf_rec_nJet", "", 10, 0, 10);
    histo_signal_50_n_ossf_rec[5] = new TH1D ("h_signal_50_n_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_signal_50_n_ossf_rec[6] = new TH1D ("h_signal_50_n_ossf_rec_HT", "", nbin, 0, 100);
    histo_signal_50_n_ossf_rec[7] = new TH1D ("h_signal_50_n_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_signal_50_n_ossf_rec[8] = new TH1D ("h_signal_50_n_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_signal_50_n_ossf_rec[9] = new TH1D ("h_signal_50_n_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_signal_50_n_ossf_rec[10] = new TH1D ("h_signal_50_n_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_signal_50_n_ossf_rec[11] = new TH1D ("h_signal_50_n_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_signal_50_n_ossf_kin_gen_l1[0] = new TH1D("h_signal_50_n_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_50_n_ossf_kin_gen_l1[1] = new TH1D("h_signal_50_n_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_50_n_ossf_kin_gen_l1[2] = new TH1D("h_signal_50_n_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_50_n_ossf_kin_gen_l2[0] = new TH1D("h_signal_50_n_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_50_n_ossf_kin_gen_l2[1] = new TH1D("h_signal_50_n_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_50_n_ossf_kin_gen_l2[2] = new TH1D("h_signal_50_n_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_50_n_ossf_kin_gen_l3[0] = new TH1D("h_signal_50_n_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_50_n_ossf_kin_gen_l3[1] = new TH1D("h_signal_50_n_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_50_n_ossf_kin_gen_l3[2] = new TH1D("h_signal_50_n_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_50_n_ossf_gen[0] = new TH1D ("h_signal_50_n_ossf_gen_met", "", nbin, 0, 100);
    histo_signal_50_n_ossf_gen[1] = new TH1D ("h_signal_50_n_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_signal_50_n_ossf_gen[2] = new TH1D ("h_signal_50_n_ossf_gen_lll", "", nbin, 0, 100);
    histo_signal_50_n_ossf_gen[3] = new TH1D ("h_signal_50_n_ossf_gen_ll", "", nbin, 0, 100);
    histo_signal_50_n_ossf_gen[4] = new TH1D ("h_signal_50_n_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_signal_50_n_ossf_kin_rec_l1[i]->Sumw2();
        histo_signal_50_n_ossf_kin_rec_l2[i]->Sumw2();
        histo_signal_50_n_ossf_kin_rec_l3[i]->Sumw2();
        histo_signal_50_n_ossf_kin_gen_l1[i]->Sumw2();
        histo_signal_50_n_ossf_kin_gen_l2[i]->Sumw2();
        histo_signal_50_n_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_signal_50_n_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_signal_50_n_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 signal_20_ossf /////////////////////////
    static TH1D* histo_signal_20_ossf_kin_rec_l1[4];
    static TH1D* histo_signal_20_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_signal_20_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_signal_20_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_signal_20_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_signal_20_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_signal_20_ossf_rec[num_histo];
    static TH1D* histo_signal_20_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_signal_20_ossf_kin_rec_l1[0] = new TH1D("h_signal_20_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_20_ossf_kin_rec_l1[1] = new TH1D("h_signal_20_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_20_ossf_kin_rec_l1[2] = new TH1D("h_signal_20_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_20_ossf_kin_rec_l1[3] = new TH1D("h_signal_20_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_signal_20_ossf_kin_rec_l2[0] = new TH1D("h_signal_20_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_20_ossf_kin_rec_l2[1] = new TH1D("h_signal_20_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_20_ossf_kin_rec_l2[2] = new TH1D("h_signal_20_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_20_ossf_kin_rec_l3[0] = new TH1D("h_signal_20_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_20_ossf_kin_rec_l3[1] = new TH1D("h_signal_20_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_20_ossf_kin_rec_l3[2] = new TH1D("h_signal_20_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_20_ossf_rec[0] = new TH1D ("h_signal_20_ossf_rec_met", "", nbin, 0, 100);
    histo_signal_20_ossf_rec[1] = new TH1D ("h_signal_20_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_signal_20_ossf_rec[2] = new TH1D ("h_signal_20_ossf_rec_lll", "", nbin, 0, 100);
    histo_signal_20_ossf_rec[3] = new TH1D ("h_signal_20_ossf_rec_ll", "", nbin, 0, 100);
    histo_signal_20_ossf_rec[4] = new TH1D ("h_signal_20_ossf_rec_nJet", "", 10, 0, 10);
    histo_signal_20_ossf_rec[5] = new TH1D ("h_signal_20_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_signal_20_ossf_rec[6] = new TH1D ("h_signal_20_ossf_rec_HT", "", nbin, 0, 100);
    histo_signal_20_ossf_rec[7] = new TH1D ("h_signal_20_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_signal_20_ossf_rec[8] = new TH1D ("h_signal_20_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_signal_20_ossf_rec[9] = new TH1D ("h_signal_20_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_signal_20_ossf_rec[10] = new TH1D ("h_signal_20_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_signal_20_ossf_rec[11] = new TH1D ("h_signal_20_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_signal_20_ossf_kin_gen_l1[0] = new TH1D("h_signal_20_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_20_ossf_kin_gen_l1[1] = new TH1D("h_signal_20_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_20_ossf_kin_gen_l1[2] = new TH1D("h_signal_20_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_20_ossf_kin_gen_l2[0] = new TH1D("h_signal_20_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_20_ossf_kin_gen_l2[1] = new TH1D("h_signal_20_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_20_ossf_kin_gen_l2[2] = new TH1D("h_signal_20_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_20_ossf_kin_gen_l3[0] = new TH1D("h_signal_20_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_20_ossf_kin_gen_l3[1] = new TH1D("h_signal_20_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_20_ossf_kin_gen_l3[2] = new TH1D("h_signal_20_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_20_ossf_gen[0] = new TH1D ("h_signal_20_ossf_gen_met", "", nbin, 0, 100);
    histo_signal_20_ossf_gen[1] = new TH1D ("h_signal_20_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_signal_20_ossf_gen[2] = new TH1D ("h_signal_20_ossf_gen_lll", "", nbin, 0, 100);
    histo_signal_20_ossf_gen[3] = new TH1D ("h_signal_20_ossf_gen_ll", "", nbin, 0, 100);
    histo_signal_20_ossf_gen[4] = new TH1D ("h_signal_20_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_signal_20_ossf_kin_rec_l1[i]->Sumw2();
        histo_signal_20_ossf_kin_rec_l2[i]->Sumw2();
        histo_signal_20_ossf_kin_rec_l3[i]->Sumw2();
        histo_signal_20_ossf_kin_gen_l1[i]->Sumw2();
        histo_signal_20_ossf_kin_gen_l2[i]->Sumw2();
        histo_signal_20_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_signal_20_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_signal_20_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 signal_20_n_ossf /////////////////////////
    static TH1D* histo_signal_20_n_ossf_kin_rec_l1[4];
    static TH1D* histo_signal_20_n_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_signal_20_n_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_signal_20_n_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_signal_20_n_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_signal_20_n_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_signal_20_n_ossf_rec[num_histo];
    static TH1D* histo_signal_20_n_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_signal_20_n_ossf_kin_rec_l1[0] = new TH1D("h_signal_20_n_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_20_n_ossf_kin_rec_l1[1] = new TH1D("h_signal_20_n_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_20_n_ossf_kin_rec_l1[2] = new TH1D("h_signal_20_n_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_20_n_ossf_kin_rec_l1[3] = new TH1D("h_signal_20_n_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_signal_20_n_ossf_kin_rec_l2[0] = new TH1D("h_signal_20_n_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_20_n_ossf_kin_rec_l2[1] = new TH1D("h_signal_20_n_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_20_n_ossf_kin_rec_l2[2] = new TH1D("h_signal_20_n_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_20_n_ossf_kin_rec_l3[0] = new TH1D("h_signal_20_n_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_20_n_ossf_kin_rec_l3[1] = new TH1D("h_signal_20_n_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_20_n_ossf_kin_rec_l3[2] = new TH1D("h_signal_20_n_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_20_n_ossf_rec[0] = new TH1D ("h_signal_20_n_ossf_rec_met", "", nbin, 0, 100);
    histo_signal_20_n_ossf_rec[1] = new TH1D ("h_signal_20_n_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_signal_20_n_ossf_rec[2] = new TH1D ("h_signal_20_n_ossf_rec_lll", "", nbin, 0, 100);
    histo_signal_20_n_ossf_rec[3] = new TH1D ("h_signal_20_n_ossf_rec_ll", "", nbin, 0, 100);
    histo_signal_20_n_ossf_rec[4] = new TH1D ("h_signal_20_n_ossf_rec_nJet", "", 10, 0, 10);
    histo_signal_20_n_ossf_rec[5] = new TH1D ("h_signal_20_n_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_signal_20_n_ossf_rec[6] = new TH1D ("h_signal_20_n_ossf_rec_HT", "", nbin, 0, 100);
    histo_signal_20_n_ossf_rec[7] = new TH1D ("h_signal_20_n_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_signal_20_n_ossf_rec[8] = new TH1D ("h_signal_20_n_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_signal_20_n_ossf_rec[9] = new TH1D ("h_signal_20_n_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_signal_20_n_ossf_rec[10] = new TH1D ("h_signal_20_n_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_signal_20_n_ossf_rec[11] = new TH1D ("h_signal_20_n_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_signal_20_n_ossf_kin_gen_l1[0] = new TH1D("h_signal_20_n_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_20_n_ossf_kin_gen_l1[1] = new TH1D("h_signal_20_n_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_20_n_ossf_kin_gen_l1[2] = new TH1D("h_signal_20_n_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_20_n_ossf_kin_gen_l2[0] = new TH1D("h_signal_20_n_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_20_n_ossf_kin_gen_l2[1] = new TH1D("h_signal_20_n_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_20_n_ossf_kin_gen_l2[2] = new TH1D("h_signal_20_n_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_20_n_ossf_kin_gen_l3[0] = new TH1D("h_signal_20_n_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_20_n_ossf_kin_gen_l3[1] = new TH1D("h_signal_20_n_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_20_n_ossf_kin_gen_l3[2] = new TH1D("h_signal_20_n_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_20_n_ossf_gen[0] = new TH1D ("h_signal_20_n_ossf_gen_met", "", nbin, 0, 100);
    histo_signal_20_n_ossf_gen[1] = new TH1D ("h_signal_20_n_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_signal_20_n_ossf_gen[2] = new TH1D ("h_signal_20_n_ossf_gen_lll", "", nbin, 0, 100);
    histo_signal_20_n_ossf_gen[3] = new TH1D ("h_signal_20_n_ossf_gen_ll", "", nbin, 0, 100);
    histo_signal_20_n_ossf_gen[4] = new TH1D ("h_signal_20_n_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_signal_20_n_ossf_kin_rec_l1[i]->Sumw2();
        histo_signal_20_n_ossf_kin_rec_l2[i]->Sumw2();
        histo_signal_20_n_ossf_kin_rec_l3[i]->Sumw2();
        histo_signal_20_n_ossf_kin_gen_l1[i]->Sumw2();
        histo_signal_20_n_ossf_kin_gen_l2[i]->Sumw2();
        histo_signal_20_n_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_signal_20_n_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_signal_20_n_ossf_gen[i]-> Sumw2();
    }
    
    
    /////////////////// 1 signal_15_ossf /////////////////////////
    static TH1D* histo_signal_15_ossf_kin_rec_l1[4];
    static TH1D* histo_signal_15_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_signal_15_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_signal_15_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_signal_15_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_signal_15_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_signal_15_ossf_rec[num_histo];
    static TH1D* histo_signal_15_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_signal_15_ossf_kin_rec_l1[0] = new TH1D("h_signal_15_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_15_ossf_kin_rec_l1[1] = new TH1D("h_signal_15_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_15_ossf_kin_rec_l1[2] = new TH1D("h_signal_15_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_15_ossf_kin_rec_l1[3] = new TH1D("h_signal_15_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_signal_15_ossf_kin_rec_l2[0] = new TH1D("h_signal_15_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_15_ossf_kin_rec_l2[1] = new TH1D("h_signal_15_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_15_ossf_kin_rec_l2[2] = new TH1D("h_signal_15_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_15_ossf_kin_rec_l3[0] = new TH1D("h_signal_15_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_15_ossf_kin_rec_l3[1] = new TH1D("h_signal_15_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_15_ossf_kin_rec_l3[2] = new TH1D("h_signal_15_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_15_ossf_rec[0] = new TH1D ("h_signal_15_ossf_rec_met", "", nbin, 0, 100);
    histo_signal_15_ossf_rec[1] = new TH1D ("h_signal_15_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_signal_15_ossf_rec[2] = new TH1D ("h_signal_15_ossf_rec_lll", "", nbin, 0, 100);
    histo_signal_15_ossf_rec[3] = new TH1D ("h_signal_15_ossf_rec_ll", "", nbin, 0, 100);
    histo_signal_15_ossf_rec[4] = new TH1D ("h_signal_15_ossf_rec_nJet", "", 10, 0, 10);
    histo_signal_15_ossf_rec[5] = new TH1D ("h_signal_15_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_signal_15_ossf_rec[6] = new TH1D ("h_signal_15_ossf_rec_HT", "", nbin, 0, 100);
    histo_signal_15_ossf_rec[7] = new TH1D ("h_signal_15_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_signal_15_ossf_rec[8] = new TH1D ("h_signal_15_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_signal_15_ossf_rec[9] = new TH1D ("h_signal_15_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_signal_15_ossf_rec[10] = new TH1D ("h_signal_15_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_signal_15_ossf_rec[11] = new TH1D ("h_signal_15_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_signal_15_ossf_kin_gen_l1[0] = new TH1D("h_signal_15_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_15_ossf_kin_gen_l1[1] = new TH1D("h_signal_15_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_15_ossf_kin_gen_l1[2] = new TH1D("h_signal_15_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_15_ossf_kin_gen_l2[0] = new TH1D("h_signal_15_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_15_ossf_kin_gen_l2[1] = new TH1D("h_signal_15_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_15_ossf_kin_gen_l2[2] = new TH1D("h_signal_15_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_15_ossf_kin_gen_l3[0] = new TH1D("h_signal_15_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_15_ossf_kin_gen_l3[1] = new TH1D("h_signal_15_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_15_ossf_kin_gen_l3[2] = new TH1D("h_signal_15_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_15_ossf_gen[0] = new TH1D ("h_signal_15_ossf_gen_met", "", nbin, 0, 100);
    histo_signal_15_ossf_gen[1] = new TH1D ("h_signal_15_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_signal_15_ossf_gen[2] = new TH1D ("h_signal_15_ossf_gen_lll", "", nbin, 0, 100);
    histo_signal_15_ossf_gen[3] = new TH1D ("h_signal_15_ossf_gen_ll", "", nbin, 0, 100);
    histo_signal_15_ossf_gen[4] = new TH1D ("h_signal_15_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_signal_15_ossf_kin_rec_l1[i]->Sumw2();
        histo_signal_15_ossf_kin_rec_l2[i]->Sumw2();
        histo_signal_15_ossf_kin_rec_l3[i]->Sumw2();
        histo_signal_15_ossf_kin_gen_l1[i]->Sumw2();
        histo_signal_15_ossf_kin_gen_l2[i]->Sumw2();
        histo_signal_15_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_signal_15_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_signal_15_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 signal_15_n_ossf /////////////////////////
    static TH1D* histo_signal_15_n_ossf_kin_rec_l1[4];
    static TH1D* histo_signal_15_n_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_signal_15_n_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_signal_15_n_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_signal_15_n_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_signal_15_n_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_signal_15_n_ossf_rec[num_histo];
    static TH1D* histo_signal_15_n_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_signal_15_n_ossf_kin_rec_l1[0] = new TH1D("h_signal_15_n_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_15_n_ossf_kin_rec_l1[1] = new TH1D("h_signal_15_n_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_15_n_ossf_kin_rec_l1[2] = new TH1D("h_signal_15_n_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_15_n_ossf_kin_rec_l1[3] = new TH1D("h_signal_15_n_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_signal_15_n_ossf_kin_rec_l2[0] = new TH1D("h_signal_15_n_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_15_n_ossf_kin_rec_l2[1] = new TH1D("h_signal_15_n_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_15_n_ossf_kin_rec_l2[2] = new TH1D("h_signal_15_n_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_15_n_ossf_kin_rec_l3[0] = new TH1D("h_signal_15_n_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_15_n_ossf_kin_rec_l3[1] = new TH1D("h_signal_15_n_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_15_n_ossf_kin_rec_l3[2] = new TH1D("h_signal_15_n_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_15_n_ossf_rec[0] = new TH1D ("h_signal_15_n_ossf_rec_met", "", nbin, 0, 100);
    histo_signal_15_n_ossf_rec[1] = new TH1D ("h_signal_15_n_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_signal_15_n_ossf_rec[2] = new TH1D ("h_signal_15_n_ossf_rec_lll", "", nbin, 0, 100);
    histo_signal_15_n_ossf_rec[3] = new TH1D ("h_signal_15_n_ossf_rec_ll", "", nbin, 0, 100);
    histo_signal_15_n_ossf_rec[4] = new TH1D ("h_signal_15_n_ossf_rec_nJet", "", 10, 0, 10);
    histo_signal_15_n_ossf_rec[5] = new TH1D ("h_signal_15_n_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_signal_15_n_ossf_rec[6] = new TH1D ("h_signal_15_n_ossf_rec_HT", "", nbin, 0, 100);
    histo_signal_15_n_ossf_rec[7] = new TH1D ("h_signal_15_n_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_signal_15_n_ossf_rec[8] = new TH1D ("h_signal_15_n_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_signal_15_n_ossf_rec[9] = new TH1D ("h_signal_15_n_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_signal_15_n_ossf_rec[10] = new TH1D ("h_signal_15_n_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_signal_15_n_ossf_rec[11] = new TH1D ("h_signal_15_n_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_signal_15_n_ossf_kin_gen_l1[0] = new TH1D("h_signal_15_n_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_15_n_ossf_kin_gen_l1[1] = new TH1D("h_signal_15_n_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_15_n_ossf_kin_gen_l1[2] = new TH1D("h_signal_15_n_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_15_n_ossf_kin_gen_l2[0] = new TH1D("h_signal_15_n_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_15_n_ossf_kin_gen_l2[1] = new TH1D("h_signal_15_n_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_15_n_ossf_kin_gen_l2[2] = new TH1D("h_signal_15_n_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_15_n_ossf_kin_gen_l3[0] = new TH1D("h_signal_15_n_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_15_n_ossf_kin_gen_l3[1] = new TH1D("h_signal_15_n_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_15_n_ossf_kin_gen_l3[2] = new TH1D("h_signal_15_n_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_15_n_ossf_gen[0] = new TH1D ("h_signal_15_n_ossf_gen_met", "", nbin, 0, 100);
    histo_signal_15_n_ossf_gen[1] = new TH1D ("h_signal_15_n_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_signal_15_n_ossf_gen[2] = new TH1D ("h_signal_15_n_ossf_gen_lll", "", nbin, 0, 100);
    histo_signal_15_n_ossf_gen[3] = new TH1D ("h_signal_15_n_ossf_gen_ll", "", nbin, 0, 100);
    histo_signal_15_n_ossf_gen[4] = new TH1D ("h_signal_15_n_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_signal_15_n_ossf_kin_rec_l1[i]->Sumw2();
        histo_signal_15_n_ossf_kin_rec_l2[i]->Sumw2();
        histo_signal_15_n_ossf_kin_rec_l3[i]->Sumw2();
        histo_signal_15_n_ossf_kin_gen_l1[i]->Sumw2();
        histo_signal_15_n_ossf_kin_gen_l2[i]->Sumw2();
        histo_signal_15_n_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_signal_15_n_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_signal_15_n_ossf_gen[i]-> Sumw2();
    }
    
    /////////////////// 1 signal_40_ossf /////////////////////////
    static TH1D* histo_signal_40_ossf_kin_rec_l1[4];
    static TH1D* histo_signal_40_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_signal_40_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_signal_40_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_signal_40_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_signal_40_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_signal_40_ossf_rec[num_histo];
    static TH1D* histo_signal_40_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_signal_40_ossf_kin_rec_l1[0] = new TH1D("h_signal_40_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_40_ossf_kin_rec_l1[1] = new TH1D("h_signal_40_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_40_ossf_kin_rec_l1[2] = new TH1D("h_signal_40_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_40_ossf_kin_rec_l1[3] = new TH1D("h_signal_40_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_signal_40_ossf_kin_rec_l2[0] = new TH1D("h_signal_40_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_40_ossf_kin_rec_l2[1] = new TH1D("h_signal_40_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_40_ossf_kin_rec_l2[2] = new TH1D("h_signal_40_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_40_ossf_kin_rec_l3[0] = new TH1D("h_signal_40_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_40_ossf_kin_rec_l3[1] = new TH1D("h_signal_40_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_40_ossf_kin_rec_l3[2] = new TH1D("h_signal_40_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_40_ossf_rec[0] = new TH1D ("h_signal_40_ossf_rec_met", "", nbin, 0, 100);
    histo_signal_40_ossf_rec[1] = new TH1D ("h_signal_40_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_signal_40_ossf_rec[2] = new TH1D ("h_signal_40_ossf_rec_lll", "", nbin, 0, 100);
    histo_signal_40_ossf_rec[3] = new TH1D ("h_signal_40_ossf_rec_ll", "", nbin, 0, 100);
    histo_signal_40_ossf_rec[4] = new TH1D ("h_signal_40_ossf_rec_nJet", "", 10, 0, 10);
    histo_signal_40_ossf_rec[5] = new TH1D ("h_signal_40_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_signal_40_ossf_rec[6] = new TH1D ("h_signal_40_ossf_rec_HT", "", nbin, 0, 100);
    histo_signal_40_ossf_rec[7] = new TH1D ("h_signal_40_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_signal_40_ossf_rec[8] = new TH1D ("h_signal_40_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_signal_40_ossf_rec[9] = new TH1D ("h_signal_40_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_signal_40_ossf_rec[10] = new TH1D ("h_signal_40_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_signal_40_ossf_rec[11] = new TH1D ("h_signal_40_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_signal_40_ossf_kin_gen_l1[0] = new TH1D("h_signal_40_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_40_ossf_kin_gen_l1[1] = new TH1D("h_signal_40_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_40_ossf_kin_gen_l1[2] = new TH1D("h_signal_40_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_40_ossf_kin_gen_l2[0] = new TH1D("h_signal_40_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_40_ossf_kin_gen_l2[1] = new TH1D("h_signal_40_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_40_ossf_kin_gen_l2[2] = new TH1D("h_signal_40_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_40_ossf_kin_gen_l3[0] = new TH1D("h_signal_40_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_40_ossf_kin_gen_l3[1] = new TH1D("h_signal_40_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_40_ossf_kin_gen_l3[2] = new TH1D("h_signal_40_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_40_ossf_gen[0] = new TH1D ("h_signal_40_ossf_gen_met", "", nbin, 0, 100);
    histo_signal_40_ossf_gen[1] = new TH1D ("h_signal_40_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_signal_40_ossf_gen[2] = new TH1D ("h_signal_40_ossf_gen_lll", "", nbin, 0, 100);
    histo_signal_40_ossf_gen[3] = new TH1D ("h_signal_40_ossf_gen_ll", "", nbin, 0, 100);
    histo_signal_40_ossf_gen[4] = new TH1D ("h_signal_40_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_signal_40_ossf_kin_rec_l1[i]->Sumw2();
        histo_signal_40_ossf_kin_rec_l2[i]->Sumw2();
        histo_signal_40_ossf_kin_rec_l3[i]->Sumw2();
        histo_signal_40_ossf_kin_gen_l1[i]->Sumw2();
        histo_signal_40_ossf_kin_gen_l2[i]->Sumw2();
        histo_signal_40_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_signal_40_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_signal_40_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 signal_40_n_ossf /////////////////////////
    static TH1D* histo_signal_40_n_ossf_kin_rec_l1[4];
    static TH1D* histo_signal_40_n_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_signal_40_n_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_signal_40_n_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_signal_40_n_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_signal_40_n_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_signal_40_n_ossf_rec[num_histo];
    static TH1D* histo_signal_40_n_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_signal_40_n_ossf_kin_rec_l1[0] = new TH1D("h_signal_40_n_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_40_n_ossf_kin_rec_l1[1] = new TH1D("h_signal_40_n_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_40_n_ossf_kin_rec_l1[2] = new TH1D("h_signal_40_n_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_40_n_ossf_kin_rec_l1[3] = new TH1D("h_signal_40_n_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_signal_40_n_ossf_kin_rec_l2[0] = new TH1D("h_signal_40_n_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_40_n_ossf_kin_rec_l2[1] = new TH1D("h_signal_40_n_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_40_n_ossf_kin_rec_l2[2] = new TH1D("h_signal_40_n_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_40_n_ossf_kin_rec_l3[0] = new TH1D("h_signal_40_n_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_40_n_ossf_kin_rec_l3[1] = new TH1D("h_signal_40_n_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_40_n_ossf_kin_rec_l3[2] = new TH1D("h_signal_40_n_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_40_n_ossf_rec[0] = new TH1D ("h_signal_40_n_ossf_rec_met", "", nbin, 0, 100);
    histo_signal_40_n_ossf_rec[1] = new TH1D ("h_signal_40_n_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_signal_40_n_ossf_rec[2] = new TH1D ("h_signal_40_n_ossf_rec_lll", "", nbin, 0, 100);
    histo_signal_40_n_ossf_rec[3] = new TH1D ("h_signal_40_n_ossf_rec_ll", "", nbin, 0, 100);
    histo_signal_40_n_ossf_rec[4] = new TH1D ("h_signal_40_n_ossf_rec_nJet", "", 10, 0, 10);
    histo_signal_40_n_ossf_rec[5] = new TH1D ("h_signal_40_n_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_signal_40_n_ossf_rec[6] = new TH1D ("h_signal_40_n_ossf_rec_HT", "", nbin, 0, 100);
    histo_signal_40_n_ossf_rec[7] = new TH1D ("h_signal_40_n_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_signal_40_n_ossf_rec[8] = new TH1D ("h_signal_40_n_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_signal_40_n_ossf_rec[9] = new TH1D ("h_signal_40_n_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_signal_40_n_ossf_rec[10] = new TH1D ("h_signal_40_n_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_signal_40_n_ossf_rec[11] = new TH1D ("h_signal_40_n_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_signal_40_n_ossf_kin_gen_l1[0] = new TH1D("h_signal_40_n_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_40_n_ossf_kin_gen_l1[1] = new TH1D("h_signal_40_n_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_40_n_ossf_kin_gen_l1[2] = new TH1D("h_signal_40_n_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_40_n_ossf_kin_gen_l2[0] = new TH1D("h_signal_40_n_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_40_n_ossf_kin_gen_l2[1] = new TH1D("h_signal_40_n_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_40_n_ossf_kin_gen_l2[2] = new TH1D("h_signal_40_n_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_40_n_ossf_kin_gen_l3[0] = new TH1D("h_signal_40_n_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_40_n_ossf_kin_gen_l3[1] = new TH1D("h_signal_40_n_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_40_n_ossf_kin_gen_l3[2] = new TH1D("h_signal_40_n_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_40_n_ossf_gen[0] = new TH1D ("h_signal_40_n_ossf_gen_met", "", nbin, 0, 100);
    histo_signal_40_n_ossf_gen[1] = new TH1D ("h_signal_40_n_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_signal_40_n_ossf_gen[2] = new TH1D ("h_signal_40_n_ossf_gen_lll", "", nbin, 0, 100);
    histo_signal_40_n_ossf_gen[3] = new TH1D ("h_signal_40_n_ossf_gen_ll", "", nbin, 0, 100);
    histo_signal_40_n_ossf_gen[4] = new TH1D ("h_signal_40_n_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_signal_40_n_ossf_kin_rec_l1[i]->Sumw2();
        histo_signal_40_n_ossf_kin_rec_l2[i]->Sumw2();
        histo_signal_40_n_ossf_kin_rec_l3[i]->Sumw2();
        histo_signal_40_n_ossf_kin_gen_l1[i]->Sumw2();
        histo_signal_40_n_ossf_kin_gen_l2[i]->Sumw2();
        histo_signal_40_n_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_signal_40_n_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_signal_40_n_ossf_gen[i]-> Sumw2();
    }
    
    /////////////////// 1 signal_60_ossf /////////////////////////
    static TH1D* histo_signal_60_ossf_kin_rec_l1[4];
    static TH1D* histo_signal_60_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_signal_60_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_signal_60_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_signal_60_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_signal_60_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_signal_60_ossf_rec[num_histo];
    static TH1D* histo_signal_60_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_signal_60_ossf_kin_rec_l1[0] = new TH1D("h_signal_60_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_60_ossf_kin_rec_l1[1] = new TH1D("h_signal_60_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_60_ossf_kin_rec_l1[2] = new TH1D("h_signal_60_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_60_ossf_kin_rec_l1[3] = new TH1D("h_signal_60_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_signal_60_ossf_kin_rec_l2[0] = new TH1D("h_signal_60_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_60_ossf_kin_rec_l2[1] = new TH1D("h_signal_60_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_60_ossf_kin_rec_l2[2] = new TH1D("h_signal_60_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_60_ossf_kin_rec_l3[0] = new TH1D("h_signal_60_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_60_ossf_kin_rec_l3[1] = new TH1D("h_signal_60_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_60_ossf_kin_rec_l3[2] = new TH1D("h_signal_60_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_60_ossf_rec[0] = new TH1D ("h_signal_60_ossf_rec_met", "", nbin, 0, 100);
    histo_signal_60_ossf_rec[1] = new TH1D ("h_signal_60_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_signal_60_ossf_rec[2] = new TH1D ("h_signal_60_ossf_rec_lll", "", nbin, 0, 100);
    histo_signal_60_ossf_rec[3] = new TH1D ("h_signal_60_ossf_rec_ll", "", nbin, 0, 100);
    histo_signal_60_ossf_rec[4] = new TH1D ("h_signal_60_ossf_rec_nJet", "", 10, 0, 10);
    histo_signal_60_ossf_rec[5] = new TH1D ("h_signal_60_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_signal_60_ossf_rec[6] = new TH1D ("h_signal_60_ossf_rec_HT", "", nbin, 0, 100);
    histo_signal_60_ossf_rec[7] = new TH1D ("h_signal_60_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_signal_60_ossf_rec[8] = new TH1D ("h_signal_60_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_signal_60_ossf_rec[9] = new TH1D ("h_signal_60_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_signal_60_ossf_rec[10] = new TH1D ("h_signal_60_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_signal_60_ossf_rec[11] = new TH1D ("h_signal_60_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_signal_60_ossf_kin_gen_l1[0] = new TH1D("h_signal_60_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_60_ossf_kin_gen_l1[1] = new TH1D("h_signal_60_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_60_ossf_kin_gen_l1[2] = new TH1D("h_signal_60_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_60_ossf_kin_gen_l2[0] = new TH1D("h_signal_60_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_60_ossf_kin_gen_l2[1] = new TH1D("h_signal_60_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_60_ossf_kin_gen_l2[2] = new TH1D("h_signal_60_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_60_ossf_kin_gen_l3[0] = new TH1D("h_signal_60_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_60_ossf_kin_gen_l3[1] = new TH1D("h_signal_60_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_60_ossf_kin_gen_l3[2] = new TH1D("h_signal_60_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_60_ossf_gen[0] = new TH1D ("h_signal_60_ossf_gen_met", "", nbin, 0, 100);
    histo_signal_60_ossf_gen[1] = new TH1D ("h_signal_60_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_signal_60_ossf_gen[2] = new TH1D ("h_signal_60_ossf_gen_lll", "", nbin, 0, 100);
    histo_signal_60_ossf_gen[3] = new TH1D ("h_signal_60_ossf_gen_ll", "", nbin, 0, 100);
    histo_signal_60_ossf_gen[4] = new TH1D ("h_signal_60_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_signal_60_ossf_kin_rec_l1[i]->Sumw2();
        histo_signal_60_ossf_kin_rec_l2[i]->Sumw2();
        histo_signal_60_ossf_kin_rec_l3[i]->Sumw2();
        histo_signal_60_ossf_kin_gen_l1[i]->Sumw2();
        histo_signal_60_ossf_kin_gen_l2[i]->Sumw2();
        histo_signal_60_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_signal_60_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_signal_60_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 signal_60_n_ossf /////////////////////////
    static TH1D* histo_signal_60_n_ossf_kin_rec_l1[4];
    static TH1D* histo_signal_60_n_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_signal_60_n_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_signal_60_n_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_signal_60_n_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_signal_60_n_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_signal_60_n_ossf_rec[num_histo];
    static TH1D* histo_signal_60_n_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_signal_60_n_ossf_kin_rec_l1[0] = new TH1D("h_signal_60_n_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_60_n_ossf_kin_rec_l1[1] = new TH1D("h_signal_60_n_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_60_n_ossf_kin_rec_l1[2] = new TH1D("h_signal_60_n_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_60_n_ossf_kin_rec_l1[3] = new TH1D("h_signal_60_n_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_signal_60_n_ossf_kin_rec_l2[0] = new TH1D("h_signal_60_n_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_60_n_ossf_kin_rec_l2[1] = new TH1D("h_signal_60_n_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_60_n_ossf_kin_rec_l2[2] = new TH1D("h_signal_60_n_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_60_n_ossf_kin_rec_l3[0] = new TH1D("h_signal_60_n_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_60_n_ossf_kin_rec_l3[1] = new TH1D("h_signal_60_n_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_60_n_ossf_kin_rec_l3[2] = new TH1D("h_signal_60_n_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_60_n_ossf_rec[0] = new TH1D ("h_signal_60_n_ossf_rec_met", "", nbin, 0, 100);
    histo_signal_60_n_ossf_rec[1] = new TH1D ("h_signal_60_n_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_signal_60_n_ossf_rec[2] = new TH1D ("h_signal_60_n_ossf_rec_lll", "", nbin, 0, 100);
    histo_signal_60_n_ossf_rec[3] = new TH1D ("h_signal_60_n_ossf_rec_ll", "", nbin, 0, 100);
    histo_signal_60_n_ossf_rec[4] = new TH1D ("h_signal_60_n_ossf_rec_nJet", "", 10, 0, 10);
    histo_signal_60_n_ossf_rec[5] = new TH1D ("h_signal_60_n_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_signal_60_n_ossf_rec[6] = new TH1D ("h_signal_60_n_ossf_rec_HT", "", nbin, 0, 100);
    histo_signal_60_n_ossf_rec[7] = new TH1D ("h_signal_60_n_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_signal_60_n_ossf_rec[8] = new TH1D ("h_signal_60_n_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_signal_60_n_ossf_rec[9] = new TH1D ("h_signal_60_n_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_signal_60_n_ossf_rec[10] = new TH1D ("h_signal_60_n_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_signal_60_n_ossf_rec[11] = new TH1D ("h_signal_60_n_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_signal_60_n_ossf_kin_gen_l1[0] = new TH1D("h_signal_60_n_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_60_n_ossf_kin_gen_l1[1] = new TH1D("h_signal_60_n_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_60_n_ossf_kin_gen_l1[2] = new TH1D("h_signal_60_n_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_60_n_ossf_kin_gen_l2[0] = new TH1D("h_signal_60_n_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_60_n_ossf_kin_gen_l2[1] = new TH1D("h_signal_60_n_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_60_n_ossf_kin_gen_l2[2] = new TH1D("h_signal_60_n_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_60_n_ossf_kin_gen_l3[0] = new TH1D("h_signal_60_n_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_60_n_ossf_kin_gen_l3[1] = new TH1D("h_signal_60_n_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_60_n_ossf_kin_gen_l3[2] = new TH1D("h_signal_60_n_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_60_n_ossf_gen[0] = new TH1D ("h_signal_60_n_ossf_gen_met", "", nbin, 0, 100);
    histo_signal_60_n_ossf_gen[1] = new TH1D ("h_signal_60_n_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_signal_60_n_ossf_gen[2] = new TH1D ("h_signal_60_n_ossf_gen_lll", "", nbin, 0, 100);
    histo_signal_60_n_ossf_gen[3] = new TH1D ("h_signal_60_n_ossf_gen_ll", "", nbin, 0, 100);
    histo_signal_60_n_ossf_gen[4] = new TH1D ("h_signal_60_n_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_signal_60_n_ossf_kin_rec_l1[i]->Sumw2();
        histo_signal_60_n_ossf_kin_rec_l2[i]->Sumw2();
        histo_signal_60_n_ossf_kin_rec_l3[i]->Sumw2();
        histo_signal_60_n_ossf_kin_gen_l1[i]->Sumw2();
        histo_signal_60_n_ossf_kin_gen_l2[i]->Sumw2();
        histo_signal_60_n_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_signal_60_n_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_signal_60_n_ossf_gen[i]-> Sumw2();
    }
    
    /////////////////// 1 signal_5_ossf /////////////////////////
    static TH1D* histo_signal_5_ossf_kin_rec_l1[4];
    static TH1D* histo_signal_5_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_signal_5_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_signal_5_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_signal_5_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_signal_5_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_signal_5_ossf_rec[num_histo];
    static TH1D* histo_signal_5_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_signal_5_ossf_kin_rec_l1[0] = new TH1D("h_signal_5_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_5_ossf_kin_rec_l1[1] = new TH1D("h_signal_5_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_5_ossf_kin_rec_l1[2] = new TH1D("h_signal_5_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_5_ossf_kin_rec_l1[3] = new TH1D("h_signal_5_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_signal_5_ossf_kin_rec_l2[0] = new TH1D("h_signal_5_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_5_ossf_kin_rec_l2[1] = new TH1D("h_signal_5_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_5_ossf_kin_rec_l2[2] = new TH1D("h_signal_5_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_5_ossf_kin_rec_l3[0] = new TH1D("h_signal_5_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_5_ossf_kin_rec_l3[1] = new TH1D("h_signal_5_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_5_ossf_kin_rec_l3[2] = new TH1D("h_signal_5_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_5_ossf_rec[0] = new TH1D ("h_signal_5_ossf_rec_met", "", nbin, 0, 100);
    histo_signal_5_ossf_rec[1] = new TH1D ("h_signal_5_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_signal_5_ossf_rec[2] = new TH1D ("h_signal_5_ossf_rec_lll", "", nbin, 0, 100);
    histo_signal_5_ossf_rec[3] = new TH1D ("h_signal_5_ossf_rec_ll", "", nbin, 0, 100);
    histo_signal_5_ossf_rec[4] = new TH1D ("h_signal_5_ossf_rec_nJet", "", 10, 0, 10);
    histo_signal_5_ossf_rec[5] = new TH1D ("h_signal_5_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_signal_5_ossf_rec[6] = new TH1D ("h_signal_5_ossf_rec_HT", "", nbin, 0, 100);
    histo_signal_5_ossf_rec[7] = new TH1D ("h_signal_5_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_signal_5_ossf_rec[8] = new TH1D ("h_signal_5_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_signal_5_ossf_rec[9] = new TH1D ("h_signal_5_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_signal_5_ossf_rec[10] = new TH1D ("h_signal_5_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_signal_5_ossf_rec[11] = new TH1D ("h_signal_5_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_signal_5_ossf_kin_gen_l1[0] = new TH1D("h_signal_5_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_5_ossf_kin_gen_l1[1] = new TH1D("h_signal_5_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_5_ossf_kin_gen_l1[2] = new TH1D("h_signal_5_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_5_ossf_kin_gen_l2[0] = new TH1D("h_signal_5_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_5_ossf_kin_gen_l2[1] = new TH1D("h_signal_5_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_5_ossf_kin_gen_l2[2] = new TH1D("h_signal_5_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_5_ossf_kin_gen_l3[0] = new TH1D("h_signal_5_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_5_ossf_kin_gen_l3[1] = new TH1D("h_signal_5_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_5_ossf_kin_gen_l3[2] = new TH1D("h_signal_5_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_5_ossf_gen[0] = new TH1D ("h_signal_5_ossf_gen_met", "", nbin, 0, 100);
    histo_signal_5_ossf_gen[1] = new TH1D ("h_signal_5_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_signal_5_ossf_gen[2] = new TH1D ("h_signal_5_ossf_gen_lll", "", nbin, 0, 100);
    histo_signal_5_ossf_gen[3] = new TH1D ("h_signal_5_ossf_gen_ll", "", nbin, 0, 100);
    histo_signal_5_ossf_gen[4] = new TH1D ("h_signal_5_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_signal_5_ossf_kin_rec_l1[i]->Sumw2();
        histo_signal_5_ossf_kin_rec_l2[i]->Sumw2();
        histo_signal_5_ossf_kin_rec_l3[i]->Sumw2();
        histo_signal_5_ossf_kin_gen_l1[i]->Sumw2();
        histo_signal_5_ossf_kin_gen_l2[i]->Sumw2();
        histo_signal_5_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_signal_5_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_signal_5_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 signal_5_n_ossf /////////////////////////
    static TH1D* histo_signal_5_n_ossf_kin_rec_l1[4];
    static TH1D* histo_signal_5_n_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_signal_5_n_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_signal_5_n_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_signal_5_n_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_signal_5_n_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_signal_5_n_ossf_rec[num_histo];
    static TH1D* histo_signal_5_n_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_signal_5_n_ossf_kin_rec_l1[0] = new TH1D("h_signal_5_n_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_5_n_ossf_kin_rec_l1[1] = new TH1D("h_signal_5_n_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_5_n_ossf_kin_rec_l1[2] = new TH1D("h_signal_5_n_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_5_n_ossf_kin_rec_l1[3] = new TH1D("h_signal_5_n_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_signal_5_n_ossf_kin_rec_l2[0] = new TH1D("h_signal_5_n_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_5_n_ossf_kin_rec_l2[1] = new TH1D("h_signal_5_n_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_5_n_ossf_kin_rec_l2[2] = new TH1D("h_signal_5_n_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_5_n_ossf_kin_rec_l3[0] = new TH1D("h_signal_5_n_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_5_n_ossf_kin_rec_l3[1] = new TH1D("h_signal_5_n_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_5_n_ossf_kin_rec_l3[2] = new TH1D("h_signal_5_n_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_5_n_ossf_rec[0] = new TH1D ("h_signal_5_n_ossf_rec_met", "", nbin, 0, 100);
    histo_signal_5_n_ossf_rec[1] = new TH1D ("h_signal_5_n_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_signal_5_n_ossf_rec[2] = new TH1D ("h_signal_5_n_ossf_rec_lll", "", nbin, 0, 100);
    histo_signal_5_n_ossf_rec[3] = new TH1D ("h_signal_5_n_ossf_rec_ll", "", nbin, 0, 100);
    histo_signal_5_n_ossf_rec[4] = new TH1D ("h_signal_5_n_ossf_rec_nJet", "", 10, 0, 10);
    histo_signal_5_n_ossf_rec[5] = new TH1D ("h_signal_5_n_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_signal_5_n_ossf_rec[6] = new TH1D ("h_signal_5_n_ossf_rec_HT", "", nbin, 0, 100);
    histo_signal_5_n_ossf_rec[7] = new TH1D ("h_signal_5_n_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_signal_5_n_ossf_rec[8] = new TH1D ("h_signal_5_n_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_signal_5_n_ossf_rec[9] = new TH1D ("h_signal_5_n_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_signal_5_n_ossf_rec[10] = new TH1D ("h_signal_5_n_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_signal_5_n_ossf_rec[11] = new TH1D ("h_signal_5_n_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_signal_5_n_ossf_kin_gen_l1[0] = new TH1D("h_signal_5_n_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_5_n_ossf_kin_gen_l1[1] = new TH1D("h_signal_5_n_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_5_n_ossf_kin_gen_l1[2] = new TH1D("h_signal_5_n_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_5_n_ossf_kin_gen_l2[0] = new TH1D("h_signal_5_n_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_5_n_ossf_kin_gen_l2[1] = new TH1D("h_signal_5_n_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_5_n_ossf_kin_gen_l2[2] = new TH1D("h_signal_5_n_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_5_n_ossf_kin_gen_l3[0] = new TH1D("h_signal_5_n_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_5_n_ossf_kin_gen_l3[1] = new TH1D("h_signal_5_n_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_5_n_ossf_kin_gen_l3[2] = new TH1D("h_signal_5_n_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_5_n_ossf_gen[0] = new TH1D ("h_signal_5_n_ossf_gen_met", "", nbin, 0, 100);
    histo_signal_5_n_ossf_gen[1] = new TH1D ("h_signal_5_n_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_signal_5_n_ossf_gen[2] = new TH1D ("h_signal_5_n_ossf_gen_lll", "", nbin, 0, 100);
    histo_signal_5_n_ossf_gen[3] = new TH1D ("h_signal_5_n_ossf_gen_ll", "", nbin, 0, 100);
    histo_signal_5_n_ossf_gen[4] = new TH1D ("h_signal_5_n_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_signal_5_n_ossf_kin_rec_l1[i]->Sumw2();
        histo_signal_5_n_ossf_kin_rec_l2[i]->Sumw2();
        histo_signal_5_n_ossf_kin_rec_l3[i]->Sumw2();
        histo_signal_5_n_ossf_kin_gen_l1[i]->Sumw2();
        histo_signal_5_n_ossf_kin_gen_l2[i]->Sumw2();
        histo_signal_5_n_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_signal_5_n_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_signal_5_n_ossf_gen[i]-> Sumw2();
    }
    
    
    
    
    
    
    
    /////////////////// 1 signal_10_ossf /////////////////////////
    static TH1D* histo_signal_10_ossf_kin_rec_l1[4];
    static TH1D* histo_signal_10_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_signal_10_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_signal_10_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_signal_10_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_signal_10_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_signal_10_ossf_rec[num_histo];
    static TH1D* histo_signal_10_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_signal_10_ossf_kin_rec_l1[0] = new TH1D("h_signal_10_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_10_ossf_kin_rec_l1[1] = new TH1D("h_signal_10_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_10_ossf_kin_rec_l1[2] = new TH1D("h_signal_10_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_10_ossf_kin_rec_l1[3] = new TH1D("h_signal_10_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_signal_10_ossf_kin_rec_l2[0] = new TH1D("h_signal_10_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_10_ossf_kin_rec_l2[1] = new TH1D("h_signal_10_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_10_ossf_kin_rec_l2[2] = new TH1D("h_signal_10_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_10_ossf_kin_rec_l3[0] = new TH1D("h_signal_10_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_10_ossf_kin_rec_l3[1] = new TH1D("h_signal_10_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_10_ossf_kin_rec_l3[2] = new TH1D("h_signal_10_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_10_ossf_rec[0] = new TH1D ("h_signal_10_ossf_rec_met", "", nbin, 0, 100);
    histo_signal_10_ossf_rec[1] = new TH1D ("h_signal_10_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_signal_10_ossf_rec[2] = new TH1D ("h_signal_10_ossf_rec_lll", "", nbin, 0, 100);
    histo_signal_10_ossf_rec[3] = new TH1D ("h_signal_10_ossf_rec_ll", "", nbin, 0, 100);
    histo_signal_10_ossf_rec[4] = new TH1D ("h_signal_10_ossf_rec_nJet", "", 10, 0, 10);
    histo_signal_10_ossf_rec[5] = new TH1D ("h_signal_10_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_signal_10_ossf_rec[6] = new TH1D ("h_signal_10_ossf_rec_HT", "", nbin, 0, 100);
    histo_signal_10_ossf_rec[7] = new TH1D ("h_signal_10_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_signal_10_ossf_rec[8] = new TH1D ("h_signal_10_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_signal_10_ossf_rec[9] = new TH1D ("h_signal_10_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_signal_10_ossf_rec[10] = new TH1D ("h_signal_10_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_signal_10_ossf_rec[11] = new TH1D ("h_signal_10_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_signal_10_ossf_kin_gen_l1[0] = new TH1D("h_signal_10_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_10_ossf_kin_gen_l1[1] = new TH1D("h_signal_10_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_10_ossf_kin_gen_l1[2] = new TH1D("h_signal_10_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_10_ossf_kin_gen_l2[0] = new TH1D("h_signal_10_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_10_ossf_kin_gen_l2[1] = new TH1D("h_signal_10_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_10_ossf_kin_gen_l2[2] = new TH1D("h_signal_10_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_10_ossf_kin_gen_l3[0] = new TH1D("h_signal_10_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_10_ossf_kin_gen_l3[1] = new TH1D("h_signal_10_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_10_ossf_kin_gen_l3[2] = new TH1D("h_signal_10_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_10_ossf_gen[0] = new TH1D ("h_signal_10_ossf_gen_met", "", nbin, 0, 100);
    histo_signal_10_ossf_gen[1] = new TH1D ("h_signal_10_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_signal_10_ossf_gen[2] = new TH1D ("h_signal_10_ossf_gen_lll", "", nbin, 0, 100);
    histo_signal_10_ossf_gen[3] = new TH1D ("h_signal_10_ossf_gen_ll", "", nbin, 0, 100);
    histo_signal_10_ossf_gen[4] = new TH1D ("h_signal_10_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_signal_10_ossf_kin_rec_l1[i]->Sumw2();
        histo_signal_10_ossf_kin_rec_l2[i]->Sumw2();
        histo_signal_10_ossf_kin_rec_l3[i]->Sumw2();
        histo_signal_10_ossf_kin_gen_l1[i]->Sumw2();
        histo_signal_10_ossf_kin_gen_l2[i]->Sumw2();
        histo_signal_10_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_signal_10_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_signal_10_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 signal_10_n_ossf /////////////////////////
    static TH1D* histo_signal_10_n_ossf_kin_rec_l1[4];
    static TH1D* histo_signal_10_n_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_signal_10_n_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_signal_10_n_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_signal_10_n_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_signal_10_n_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_signal_10_n_ossf_rec[num_histo];
    static TH1D* histo_signal_10_n_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_signal_10_n_ossf_kin_rec_l1[0] = new TH1D("h_signal_10_n_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_10_n_ossf_kin_rec_l1[1] = new TH1D("h_signal_10_n_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_10_n_ossf_kin_rec_l1[2] = new TH1D("h_signal_10_n_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_10_n_ossf_kin_rec_l1[3] = new TH1D("h_signal_10_n_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_signal_10_n_ossf_kin_rec_l2[0] = new TH1D("h_signal_10_n_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_10_n_ossf_kin_rec_l2[1] = new TH1D("h_signal_10_n_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_10_n_ossf_kin_rec_l2[2] = new TH1D("h_signal_10_n_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_10_n_ossf_kin_rec_l3[0] = new TH1D("h_signal_10_n_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_10_n_ossf_kin_rec_l3[1] = new TH1D("h_signal_10_n_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_10_n_ossf_kin_rec_l3[2] = new TH1D("h_signal_10_n_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_10_n_ossf_rec[0] = new TH1D ("h_signal_10_n_ossf_rec_met", "", nbin, 0, 100);
    histo_signal_10_n_ossf_rec[1] = new TH1D ("h_signal_10_n_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_signal_10_n_ossf_rec[2] = new TH1D ("h_signal_10_n_ossf_rec_lll", "", nbin, 0, 100);
    histo_signal_10_n_ossf_rec[3] = new TH1D ("h_signal_10_n_ossf_rec_ll", "", nbin, 0, 100);
    histo_signal_10_n_ossf_rec[4] = new TH1D ("h_signal_10_n_ossf_rec_nJet", "", 10, 0, 10);
    histo_signal_10_n_ossf_rec[5] = new TH1D ("h_signal_10_n_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_signal_10_n_ossf_rec[6] = new TH1D ("h_signal_10_n_ossf_rec_HT", "", nbin, 0, 100);
    histo_signal_10_n_ossf_rec[7] = new TH1D ("h_signal_10_n_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_signal_10_n_ossf_rec[8] = new TH1D ("h_signal_10_n_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_signal_10_n_ossf_rec[9] = new TH1D ("h_signal_10_n_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_signal_10_n_ossf_rec[10] = new TH1D ("h_signal_10_n_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_signal_10_n_ossf_rec[11] = new TH1D ("h_signal_10_n_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_signal_10_n_ossf_kin_gen_l1[0] = new TH1D("h_signal_10_n_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_10_n_ossf_kin_gen_l1[1] = new TH1D("h_signal_10_n_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_signal_10_n_ossf_kin_gen_l1[2] = new TH1D("h_signal_10_n_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_signal_10_n_ossf_kin_gen_l2[0] = new TH1D("h_signal_10_n_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_10_n_ossf_kin_gen_l2[1] = new TH1D("h_signal_10_n_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_10_n_ossf_kin_gen_l2[2] = new TH1D("h_signal_10_n_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_10_n_ossf_kin_gen_l3[0] = new TH1D("h_signal_10_n_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_signal_10_n_ossf_kin_gen_l3[1] = new TH1D("h_signal_10_n_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_signal_10_n_ossf_kin_gen_l3[2] = new TH1D("h_signal_10_n_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_signal_10_n_ossf_gen[0] = new TH1D ("h_signal_10_n_ossf_gen_met", "", nbin, 0, 100);
    histo_signal_10_n_ossf_gen[1] = new TH1D ("h_signal_10_n_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_signal_10_n_ossf_gen[2] = new TH1D ("h_signal_10_n_ossf_gen_lll", "", nbin, 0, 100);
    histo_signal_10_n_ossf_gen[3] = new TH1D ("h_signal_10_n_ossf_gen_ll", "", nbin, 0, 100);
    histo_signal_10_n_ossf_gen[4] = new TH1D ("h_signal_10_n_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_signal_10_n_ossf_kin_rec_l1[i]->Sumw2();
        histo_signal_10_n_ossf_kin_rec_l2[i]->Sumw2();
        histo_signal_10_n_ossf_kin_rec_l3[i]->Sumw2();
        histo_signal_10_n_ossf_kin_gen_l1[i]->Sumw2();
        histo_signal_10_n_ossf_kin_gen_l2[i]->Sumw2();
        histo_signal_10_n_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_signal_10_n_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_signal_10_n_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 zg_ossf /////////////////////////
    static TH1D* histo_zg_ossf_kin_rec_l1[4];
    static TH1D* histo_zg_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_zg_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_zg_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_zg_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_zg_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_zg_ossf_rec[num_histo];
    static TH1D* histo_zg_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_zg_ossf_kin_rec_l1[0] = new TH1D("h_zg_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_zg_ossf_kin_rec_l1[1] = new TH1D("h_zg_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_zg_ossf_kin_rec_l1[2] = new TH1D("h_zg_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_zg_ossf_kin_rec_l1[3] = new TH1D("h_zg_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_zg_ossf_kin_rec_l2[0] = new TH1D("h_zg_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_zg_ossf_kin_rec_l2[1] = new TH1D("h_zg_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_zg_ossf_kin_rec_l2[2] = new TH1D("h_zg_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_zg_ossf_kin_rec_l3[0] = new TH1D("h_zg_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_zg_ossf_kin_rec_l3[1] = new TH1D("h_zg_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_zg_ossf_kin_rec_l3[2] = new TH1D("h_zg_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_zg_ossf_rec[0] = new TH1D ("h_zg_ossf_rec_met", "", nbin, 0, 100);
    histo_zg_ossf_rec[1] = new TH1D ("h_zg_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_zg_ossf_rec[2] = new TH1D ("h_zg_ossf_rec_lll", "", nbin, 0, 100);
    histo_zg_ossf_rec[3] = new TH1D ("h_zg_ossf_rec_ll", "", nbin, 0, 100);
    histo_zg_ossf_rec[4] = new TH1D ("h_zg_ossf_rec_nJet", "", 10, 0, 10);
    histo_zg_ossf_rec[5] = new TH1D ("h_zg_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_zg_ossf_rec[6] = new TH1D ("h_zg_ossf_rec_HT", "", nbin, 0, 100);
    histo_zg_ossf_rec[7] = new TH1D ("h_zg_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_zg_ossf_rec[8] = new TH1D ("h_zg_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_zg_ossf_rec[9] = new TH1D ("h_zg_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_zg_ossf_rec[10] = new TH1D ("h_zg_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_zg_ossf_rec[11] = new TH1D ("h_zg_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_zg_ossf_kin_gen_l1[0] = new TH1D("h_zg_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_zg_ossf_kin_gen_l1[1] = new TH1D("h_zg_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_zg_ossf_kin_gen_l1[2] = new TH1D("h_zg_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_zg_ossf_kin_gen_l2[0] = new TH1D("h_zg_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_zg_ossf_kin_gen_l2[1] = new TH1D("h_zg_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_zg_ossf_kin_gen_l2[2] = new TH1D("h_zg_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_zg_ossf_kin_gen_l3[0] = new TH1D("h_zg_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_zg_ossf_kin_gen_l3[1] = new TH1D("h_zg_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_zg_ossf_kin_gen_l3[2] = new TH1D("h_zg_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_zg_ossf_gen[0] = new TH1D ("h_zg_ossf_gen_met", "", nbin, 0, 100);
    histo_zg_ossf_gen[1] = new TH1D ("h_zg_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_zg_ossf_gen[2] = new TH1D ("h_zg_ossf_gen_lll", "", nbin, 0, 100);
    histo_zg_ossf_gen[3] = new TH1D ("h_zg_ossf_gen_ll", "", nbin, 0, 100);
    histo_zg_ossf_gen[4] = new TH1D ("h_zg_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_zg_ossf_kin_rec_l1[i]->Sumw2();
        histo_zg_ossf_kin_rec_l2[i]->Sumw2();
        histo_zg_ossf_kin_rec_l3[i]->Sumw2();
        histo_zg_ossf_kin_gen_l1[i]->Sumw2();
        histo_zg_ossf_kin_gen_l2[i]->Sumw2();
        histo_zg_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_zg_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_zg_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 zg_n_ossf /////////////////////////
    static TH1D* histo_zg_n_ossf_kin_rec_l1[4];
    static TH1D* histo_zg_n_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_zg_n_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_zg_n_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_zg_n_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_zg_n_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_zg_n_ossf_rec[num_histo];
    static TH1D* histo_zg_n_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_zg_n_ossf_kin_rec_l1[0] = new TH1D("h_zg_n_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_zg_n_ossf_kin_rec_l1[1] = new TH1D("h_zg_n_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_zg_n_ossf_kin_rec_l1[2] = new TH1D("h_zg_n_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_zg_n_ossf_kin_rec_l1[3] = new TH1D("h_zg_n_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_zg_n_ossf_kin_rec_l2[0] = new TH1D("h_zg_n_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_zg_n_ossf_kin_rec_l2[1] = new TH1D("h_zg_n_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_zg_n_ossf_kin_rec_l2[2] = new TH1D("h_zg_n_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_zg_n_ossf_kin_rec_l3[0] = new TH1D("h_zg_n_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_zg_n_ossf_kin_rec_l3[1] = new TH1D("h_zg_n_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_zg_n_ossf_kin_rec_l3[2] = new TH1D("h_zg_n_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_zg_n_ossf_rec[0] = new TH1D ("h_zg_n_ossf_rec_met", "", nbin, 0, 100);
    histo_zg_n_ossf_rec[1] = new TH1D ("h_zg_n_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_zg_n_ossf_rec[2] = new TH1D ("h_zg_n_ossf_rec_lll", "", nbin, 0, 100);
    histo_zg_n_ossf_rec[3] = new TH1D ("h_zg_n_ossf_rec_ll", "", nbin, 0, 100);
    histo_zg_n_ossf_rec[4] = new TH1D ("h_zg_n_ossf_rec_nJet", "", 10, 0, 10);
    histo_zg_n_ossf_rec[5] = new TH1D ("h_zg_n_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_zg_n_ossf_rec[6] = new TH1D ("h_zg_n_ossf_rec_HT", "", nbin, 0, 100);
    histo_zg_n_ossf_rec[7] = new TH1D ("h_zg_n_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_zg_n_ossf_rec[8] = new TH1D ("h_zg_n_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_zg_n_ossf_rec[9] = new TH1D ("h_zg_n_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_zg_n_ossf_rec[10] = new TH1D ("h_zg_n_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_zg_n_ossf_rec[11] = new TH1D ("h_zg_n_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_zg_n_ossf_kin_gen_l1[0] = new TH1D("h_zg_n_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_zg_n_ossf_kin_gen_l1[1] = new TH1D("h_zg_n_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_zg_n_ossf_kin_gen_l1[2] = new TH1D("h_zg_n_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_zg_n_ossf_kin_gen_l2[0] = new TH1D("h_zg_n_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_zg_n_ossf_kin_gen_l2[1] = new TH1D("h_zg_n_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_zg_n_ossf_kin_gen_l2[2] = new TH1D("h_zg_n_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_zg_n_ossf_kin_gen_l3[0] = new TH1D("h_zg_n_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_zg_n_ossf_kin_gen_l3[1] = new TH1D("h_zg_n_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_zg_n_ossf_kin_gen_l3[2] = new TH1D("h_zg_n_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_zg_n_ossf_gen[0] = new TH1D ("h_zg_n_ossf_gen_met", "", nbin, 0, 100);
    histo_zg_n_ossf_gen[1] = new TH1D ("h_zg_n_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_zg_n_ossf_gen[2] = new TH1D ("h_zg_n_ossf_gen_lll", "", nbin, 0, 100);
    histo_zg_n_ossf_gen[3] = new TH1D ("h_zg_n_ossf_gen_ll", "", nbin, 0, 100);
    histo_zg_n_ossf_gen[4] = new TH1D ("h_zg_n_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_zg_n_ossf_kin_rec_l1[i]->Sumw2();
        histo_zg_n_ossf_kin_rec_l2[i]->Sumw2();
        histo_zg_n_ossf_kin_rec_l3[i]->Sumw2();
        histo_zg_n_ossf_kin_gen_l1[i]->Sumw2();
        histo_zg_n_ossf_kin_gen_l2[i]->Sumw2();
        histo_zg_n_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_zg_n_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_zg_n_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 tt_ossf /////////////////////////
    static TH1D* histo_tt_ossf_kin_rec_l1[4];
    static TH1D* histo_tt_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_tt_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_tt_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_tt_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_tt_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_tt_ossf_rec[num_histo];
    static TH1D* histo_tt_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_tt_ossf_kin_rec_l1[0] = new TH1D("h_tt_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_tt_ossf_kin_rec_l1[1] = new TH1D("h_tt_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_tt_ossf_kin_rec_l1[2] = new TH1D("h_tt_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_tt_ossf_kin_rec_l1[3] = new TH1D("h_tt_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_tt_ossf_kin_rec_l2[0] = new TH1D("h_tt_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_tt_ossf_kin_rec_l2[1] = new TH1D("h_tt_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_tt_ossf_kin_rec_l2[2] = new TH1D("h_tt_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_tt_ossf_kin_rec_l3[0] = new TH1D("h_tt_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_tt_ossf_kin_rec_l3[1] = new TH1D("h_tt_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_tt_ossf_kin_rec_l3[2] = new TH1D("h_tt_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_tt_ossf_rec[0] = new TH1D ("h_tt_ossf_rec_met", "", nbin, 0, 100);
    histo_tt_ossf_rec[1] = new TH1D ("h_tt_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_tt_ossf_rec[2] = new TH1D ("h_tt_ossf_rec_lll", "", nbin, 0, 100);
    histo_tt_ossf_rec[3] = new TH1D ("h_tt_ossf_rec_ll", "", nbin, 0, 100);
    histo_tt_ossf_rec[4] = new TH1D ("h_tt_ossf_rec_nJet", "", 10, 0, 10);
    histo_tt_ossf_rec[5] = new TH1D ("h_tt_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_tt_ossf_rec[6] = new TH1D ("h_tt_ossf_rec_HT", "", nbin, 0, 100);
    histo_tt_ossf_rec[7] = new TH1D ("h_tt_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_tt_ossf_rec[8] = new TH1D ("h_tt_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_tt_ossf_rec[9] = new TH1D ("h_tt_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_tt_ossf_rec[10] = new TH1D ("h_tt_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_tt_ossf_rec[11] = new TH1D ("h_tt_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_tt_ossf_kin_gen_l1[0] = new TH1D("h_tt_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_tt_ossf_kin_gen_l1[1] = new TH1D("h_tt_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_tt_ossf_kin_gen_l1[2] = new TH1D("h_tt_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_tt_ossf_kin_gen_l2[0] = new TH1D("h_tt_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_tt_ossf_kin_gen_l2[1] = new TH1D("h_tt_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_tt_ossf_kin_gen_l2[2] = new TH1D("h_tt_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_tt_ossf_kin_gen_l3[0] = new TH1D("h_tt_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_tt_ossf_kin_gen_l3[1] = new TH1D("h_tt_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_tt_ossf_kin_gen_l3[2] = new TH1D("h_tt_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_tt_ossf_gen[0] = new TH1D ("h_tt_ossf_gen_met", "", nbin, 0, 100);
    histo_tt_ossf_gen[1] = new TH1D ("h_tt_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_tt_ossf_gen[2] = new TH1D ("h_tt_ossf_gen_lll", "", nbin, 0, 100);
    histo_tt_ossf_gen[3] = new TH1D ("h_tt_ossf_gen_ll", "", nbin, 0, 100);
    histo_tt_ossf_gen[4] = new TH1D ("h_tt_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_tt_ossf_kin_rec_l1[i]->Sumw2();
        histo_tt_ossf_kin_rec_l2[i]->Sumw2();
        histo_tt_ossf_kin_rec_l3[i]->Sumw2();
        histo_tt_ossf_kin_gen_l1[i]->Sumw2();
        histo_tt_ossf_kin_gen_l2[i]->Sumw2();
        histo_tt_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_tt_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_tt_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 tt_n_ossf /////////////////////////
    static TH1D* histo_tt_n_ossf_kin_rec_l1[4];
    static TH1D* histo_tt_n_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_tt_n_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_tt_n_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_tt_n_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_tt_n_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_tt_n_ossf_rec[num_histo];
    static TH1D* histo_tt_n_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_tt_n_ossf_kin_rec_l1[0] = new TH1D("h_tt_n_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_tt_n_ossf_kin_rec_l1[1] = new TH1D("h_tt_n_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_tt_n_ossf_kin_rec_l1[2] = new TH1D("h_tt_n_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_tt_n_ossf_kin_rec_l1[3] = new TH1D("h_tt_n_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_tt_n_ossf_kin_rec_l2[0] = new TH1D("h_tt_n_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_tt_n_ossf_kin_rec_l2[1] = new TH1D("h_tt_n_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_tt_n_ossf_kin_rec_l2[2] = new TH1D("h_tt_n_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_tt_n_ossf_kin_rec_l3[0] = new TH1D("h_tt_n_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_tt_n_ossf_kin_rec_l3[1] = new TH1D("h_tt_n_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_tt_n_ossf_kin_rec_l3[2] = new TH1D("h_tt_n_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_tt_n_ossf_rec[0] = new TH1D ("h_tt_n_ossf_rec_met", "", nbin, 0, 100);
    histo_tt_n_ossf_rec[1] = new TH1D ("h_tt_n_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_tt_n_ossf_rec[2] = new TH1D ("h_tt_n_ossf_rec_lll", "", nbin, 0, 100);
    histo_tt_n_ossf_rec[3] = new TH1D ("h_tt_n_ossf_rec_ll", "", nbin, 0, 100);
    histo_tt_n_ossf_rec[4] = new TH1D ("h_tt_n_ossf_rec_nJet", "", 10, 0, 10);
    histo_tt_n_ossf_rec[5] = new TH1D ("h_tt_n_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_tt_n_ossf_rec[6] = new TH1D ("h_tt_n_ossf_rec_HT", "", nbin, 0, 100);
    histo_tt_n_ossf_rec[7] = new TH1D ("h_tt_n_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_tt_n_ossf_rec[8] = new TH1D ("h_tt_n_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_tt_n_ossf_rec[9] = new TH1D ("h_tt_n_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_tt_n_ossf_rec[10] = new TH1D ("h_tt_n_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_tt_n_ossf_rec[11] = new TH1D ("h_tt_n_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_tt_n_ossf_kin_gen_l1[0] = new TH1D("h_tt_n_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_tt_n_ossf_kin_gen_l1[1] = new TH1D("h_tt_n_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_tt_n_ossf_kin_gen_l1[2] = new TH1D("h_tt_n_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_tt_n_ossf_kin_gen_l2[0] = new TH1D("h_tt_n_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_tt_n_ossf_kin_gen_l2[1] = new TH1D("h_tt_n_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_tt_n_ossf_kin_gen_l2[2] = new TH1D("h_tt_n_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_tt_n_ossf_kin_gen_l3[0] = new TH1D("h_tt_n_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_tt_n_ossf_kin_gen_l3[1] = new TH1D("h_tt_n_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_tt_n_ossf_kin_gen_l3[2] = new TH1D("h_tt_n_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_tt_n_ossf_gen[0] = new TH1D ("h_tt_n_ossf_gen_met", "", nbin, 0, 100);
    histo_tt_n_ossf_gen[1] = new TH1D ("h_tt_n_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_tt_n_ossf_gen[2] = new TH1D ("h_tt_n_ossf_gen_lll", "", nbin, 0, 100);
    histo_tt_n_ossf_gen[3] = new TH1D ("h_tt_n_ossf_gen_ll", "", nbin, 0, 100);
    histo_tt_n_ossf_gen[4] = new TH1D ("h_tt_n_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_tt_n_ossf_kin_rec_l1[i]->Sumw2();
        histo_tt_n_ossf_kin_rec_l2[i]->Sumw2();
        histo_tt_n_ossf_kin_rec_l3[i]->Sumw2();
        histo_tt_n_ossf_kin_gen_l1[i]->Sumw2();
        histo_tt_n_ossf_kin_gen_l2[i]->Sumw2();
        histo_tt_n_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_tt_n_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_tt_n_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 wg_ossf /////////////////////////
    static TH1D* histo_wg_ossf_kin_rec_l1[4];
    static TH1D* histo_wg_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_wg_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_wg_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_wg_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_wg_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_wg_ossf_rec[num_histo];
    static TH1D* histo_wg_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_wg_ossf_kin_rec_l1[0] = new TH1D("h_wg_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wg_ossf_kin_rec_l1[1] = new TH1D("h_wg_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_wg_ossf_kin_rec_l1[2] = new TH1D("h_wg_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_wg_ossf_kin_rec_l1[3] = new TH1D("h_wg_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_wg_ossf_kin_rec_l2[0] = new TH1D("h_wg_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wg_ossf_kin_rec_l2[1] = new TH1D("h_wg_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_wg_ossf_kin_rec_l2[2] = new TH1D("h_wg_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_wg_ossf_kin_rec_l3[0] = new TH1D("h_wg_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wg_ossf_kin_rec_l3[1] = new TH1D("h_wg_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_wg_ossf_kin_rec_l3[2] = new TH1D("h_wg_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_wg_ossf_rec[0] = new TH1D ("h_wg_ossf_rec_met", "", nbin, 0, 100);
    histo_wg_ossf_rec[1] = new TH1D ("h_wg_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_wg_ossf_rec[2] = new TH1D ("h_wg_ossf_rec_lll", "", nbin, 0, 100);
    histo_wg_ossf_rec[3] = new TH1D ("h_wg_ossf_rec_ll", "", nbin, 0, 100);
    histo_wg_ossf_rec[4] = new TH1D ("h_wg_ossf_rec_nJet", "", 10, 0, 10);
    histo_wg_ossf_rec[5] = new TH1D ("h_wg_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_wg_ossf_rec[6] = new TH1D ("h_wg_ossf_rec_HT", "", nbin, 0, 100);
    histo_wg_ossf_rec[7] = new TH1D ("h_wg_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_wg_ossf_rec[8] = new TH1D ("h_wg_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_wg_ossf_rec[9] = new TH1D ("h_wg_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_wg_ossf_rec[10] = new TH1D ("h_wg_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_wg_ossf_rec[11] = new TH1D ("h_wg_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_wg_ossf_kin_gen_l1[0] = new TH1D("h_wg_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wg_ossf_kin_gen_l1[1] = new TH1D("h_wg_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_wg_ossf_kin_gen_l1[2] = new TH1D("h_wg_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_wg_ossf_kin_gen_l2[0] = new TH1D("h_wg_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wg_ossf_kin_gen_l2[1] = new TH1D("h_wg_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_wg_ossf_kin_gen_l2[2] = new TH1D("h_wg_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_wg_ossf_kin_gen_l3[0] = new TH1D("h_wg_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wg_ossf_kin_gen_l3[1] = new TH1D("h_wg_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_wg_ossf_kin_gen_l3[2] = new TH1D("h_wg_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_wg_ossf_gen[0] = new TH1D ("h_wg_ossf_gen_met", "", nbin, 0, 100);
    histo_wg_ossf_gen[1] = new TH1D ("h_wg_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_wg_ossf_gen[2] = new TH1D ("h_wg_ossf_gen_lll", "", nbin, 0, 100);
    histo_wg_ossf_gen[3] = new TH1D ("h_wg_ossf_gen_ll", "", nbin, 0, 100);
    histo_wg_ossf_gen[4] = new TH1D ("h_wg_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_wg_ossf_kin_rec_l1[i]->Sumw2();
        histo_wg_ossf_kin_rec_l2[i]->Sumw2();
        histo_wg_ossf_kin_rec_l3[i]->Sumw2();
        histo_wg_ossf_kin_gen_l1[i]->Sumw2();
        histo_wg_ossf_kin_gen_l2[i]->Sumw2();
        histo_wg_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_wg_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_wg_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 wg_n_ossf /////////////////////////
    static TH1D* histo_wg_n_ossf_kin_rec_l1[4];
    static TH1D* histo_wg_n_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_wg_n_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_wg_n_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_wg_n_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_wg_n_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_wg_n_ossf_rec[num_histo];
    static TH1D* histo_wg_n_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_wg_n_ossf_kin_rec_l1[0] = new TH1D("h_wg_n_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wg_n_ossf_kin_rec_l1[1] = new TH1D("h_wg_n_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_wg_n_ossf_kin_rec_l1[2] = new TH1D("h_wg_n_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_wg_n_ossf_kin_rec_l1[3] = new TH1D("h_wg_n_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_wg_n_ossf_kin_rec_l2[0] = new TH1D("h_wg_n_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wg_n_ossf_kin_rec_l2[1] = new TH1D("h_wg_n_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_wg_n_ossf_kin_rec_l2[2] = new TH1D("h_wg_n_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_wg_n_ossf_kin_rec_l3[0] = new TH1D("h_wg_n_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wg_n_ossf_kin_rec_l3[1] = new TH1D("h_wg_n_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_wg_n_ossf_kin_rec_l3[2] = new TH1D("h_wg_n_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_wg_n_ossf_rec[0] = new TH1D ("h_wg_n_ossf_rec_met", "", nbin, 0, 100);
    histo_wg_n_ossf_rec[1] = new TH1D ("h_wg_n_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_wg_n_ossf_rec[2] = new TH1D ("h_wg_n_ossf_rec_lll", "", nbin, 0, 100);
    histo_wg_n_ossf_rec[3] = new TH1D ("h_wg_n_ossf_rec_ll", "", nbin, 0, 100);
    histo_wg_n_ossf_rec[4] = new TH1D ("h_wg_n_ossf_rec_nJet", "", 10, 0, 10);
    histo_wg_n_ossf_rec[5] = new TH1D ("h_wg_n_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_wg_n_ossf_rec[6] = new TH1D ("h_wg_n_ossf_rec_HT", "", nbin, 0, 100);
    histo_wg_n_ossf_rec[7] = new TH1D ("h_wg_n_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_wg_n_ossf_rec[8] = new TH1D ("h_wg_n_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_wg_n_ossf_rec[9] = new TH1D ("h_wg_n_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_wg_n_ossf_rec[10] = new TH1D ("h_wg_n_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_wg_n_ossf_rec[11] = new TH1D ("h_wg_n_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_wg_n_ossf_kin_gen_l1[0] = new TH1D("h_wg_n_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wg_n_ossf_kin_gen_l1[1] = new TH1D("h_wg_n_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_wg_n_ossf_kin_gen_l1[2] = new TH1D("h_wg_n_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_wg_n_ossf_kin_gen_l2[0] = new TH1D("h_wg_n_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wg_n_ossf_kin_gen_l2[1] = new TH1D("h_wg_n_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_wg_n_ossf_kin_gen_l2[2] = new TH1D("h_wg_n_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_wg_n_ossf_kin_gen_l3[0] = new TH1D("h_wg_n_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wg_n_ossf_kin_gen_l3[1] = new TH1D("h_wg_n_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_wg_n_ossf_kin_gen_l3[2] = new TH1D("h_wg_n_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_wg_n_ossf_gen[0] = new TH1D ("h_wg_n_ossf_gen_met", "", nbin, 0, 100);
    histo_wg_n_ossf_gen[1] = new TH1D ("h_wg_n_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_wg_n_ossf_gen[2] = new TH1D ("h_wg_n_ossf_gen_lll", "", nbin, 0, 100);
    histo_wg_n_ossf_gen[3] = new TH1D ("h_wg_n_ossf_gen_ll", "", nbin, 0, 100);
    histo_wg_n_ossf_gen[4] = new TH1D ("h_wg_n_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_wg_n_ossf_kin_rec_l1[i]->Sumw2();
        histo_wg_n_ossf_kin_rec_l2[i]->Sumw2();
        histo_wg_n_ossf_kin_rec_l3[i]->Sumw2();
        histo_wg_n_ossf_kin_gen_l1[i]->Sumw2();
        histo_wg_n_ossf_kin_gen_l2[i]->Sumw2();
        histo_wg_n_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_wg_n_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_wg_n_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 wz_ossf /////////////////////////
    static TH1D* histo_wz_ossf_kin_rec_l1[4];
    static TH1D* histo_wz_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_wz_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_wz_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_wz_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_wz_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_wz_ossf_rec[num_histo];
    static TH1D* histo_wz_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_wz_ossf_kin_rec_l1[0] = new TH1D("h_wz_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wz_ossf_kin_rec_l1[1] = new TH1D("h_wz_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_wz_ossf_kin_rec_l1[2] = new TH1D("h_wz_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_wz_ossf_kin_rec_l1[3] = new TH1D("h_wz_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_wz_ossf_kin_rec_l2[0] = new TH1D("h_wz_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wz_ossf_kin_rec_l2[1] = new TH1D("h_wz_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_wz_ossf_kin_rec_l2[2] = new TH1D("h_wz_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_wz_ossf_kin_rec_l3[0] = new TH1D("h_wz_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wz_ossf_kin_rec_l3[1] = new TH1D("h_wz_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_wz_ossf_kin_rec_l3[2] = new TH1D("h_wz_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_wz_ossf_rec[0] = new TH1D ("h_wz_ossf_rec_met", "", nbin, 0, 100);
    histo_wz_ossf_rec[1] = new TH1D ("h_wz_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_wz_ossf_rec[2] = new TH1D ("h_wz_ossf_rec_lll", "", nbin, 0, 100);
    histo_wz_ossf_rec[3] = new TH1D ("h_wz_ossf_rec_ll", "", nbin, 0, 100);
    histo_wz_ossf_rec[4] = new TH1D ("h_wz_ossf_rec_nJet", "", 10, 0, 10);
    histo_wz_ossf_rec[5] = new TH1D ("h_wz_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_wz_ossf_rec[6] = new TH1D ("h_wz_ossf_rec_HT", "", nbin, 0, 100);
    histo_wz_ossf_rec[7] = new TH1D ("h_wz_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_wz_ossf_rec[8] = new TH1D ("h_wz_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_wz_ossf_rec[9] = new TH1D ("h_wz_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_wz_ossf_rec[10] = new TH1D ("h_wz_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_wz_ossf_rec[11] = new TH1D ("h_wz_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_wz_ossf_kin_gen_l1[0] = new TH1D("h_wz_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wz_ossf_kin_gen_l1[1] = new TH1D("h_wz_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_wz_ossf_kin_gen_l1[2] = new TH1D("h_wz_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_wz_ossf_kin_gen_l2[0] = new TH1D("h_wz_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wz_ossf_kin_gen_l2[1] = new TH1D("h_wz_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_wz_ossf_kin_gen_l2[2] = new TH1D("h_wz_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_wz_ossf_kin_gen_l3[0] = new TH1D("h_wz_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wz_ossf_kin_gen_l3[1] = new TH1D("h_wz_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_wz_ossf_kin_gen_l3[2] = new TH1D("h_wz_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_wz_ossf_gen[0] = new TH1D ("h_wz_ossf_gen_met", "", nbin, 0, 100);
    histo_wz_ossf_gen[1] = new TH1D ("h_wz_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_wz_ossf_gen[2] = new TH1D ("h_wz_ossf_gen_lll", "", nbin, 0, 100);
    histo_wz_ossf_gen[3] = new TH1D ("h_wz_ossf_gen_ll", "", nbin, 0, 100);
    histo_wz_ossf_gen[4] = new TH1D ("h_wz_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_wz_ossf_kin_rec_l1[i]->Sumw2();
        histo_wz_ossf_kin_rec_l2[i]->Sumw2();
        histo_wz_ossf_kin_rec_l3[i]->Sumw2();
        histo_wz_ossf_kin_gen_l1[i]->Sumw2();
        histo_wz_ossf_kin_gen_l2[i]->Sumw2();
        histo_wz_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_wz_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_wz_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 wz_n_ossf /////////////////////////
    static TH1D* histo_wz_n_ossf_kin_rec_l1[4];
    static TH1D* histo_wz_n_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_wz_n_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_wz_n_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_wz_n_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_wz_n_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_wz_n_ossf_rec[num_histo];
    static TH1D* histo_wz_n_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_wz_n_ossf_kin_rec_l1[0] = new TH1D("h_wz_n_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wz_n_ossf_kin_rec_l1[1] = new TH1D("h_wz_n_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_wz_n_ossf_kin_rec_l1[2] = new TH1D("h_wz_n_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_wz_n_ossf_kin_rec_l1[3] = new TH1D("h_wz_n_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_wz_n_ossf_kin_rec_l2[0] = new TH1D("h_wz_n_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wz_n_ossf_kin_rec_l2[1] = new TH1D("h_wz_n_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_wz_n_ossf_kin_rec_l2[2] = new TH1D("h_wz_n_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_wz_n_ossf_kin_rec_l3[0] = new TH1D("h_wz_n_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wz_n_ossf_kin_rec_l3[1] = new TH1D("h_wz_n_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_wz_n_ossf_kin_rec_l3[2] = new TH1D("h_wz_n_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_wz_n_ossf_rec[0] = new TH1D ("h_wz_n_ossf_rec_met", "", nbin, 0, 100);
    histo_wz_n_ossf_rec[1] = new TH1D ("h_wz_n_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_wz_n_ossf_rec[2] = new TH1D ("h_wz_n_ossf_rec_lll", "", nbin, 0, 100);
    histo_wz_n_ossf_rec[3] = new TH1D ("h_wz_n_ossf_rec_ll", "", nbin, 0, 100);
    histo_wz_n_ossf_rec[4] = new TH1D ("h_wz_n_ossf_rec_nJet", "", 10, 0, 10);
    histo_wz_n_ossf_rec[5] = new TH1D ("h_wz_n_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_wz_n_ossf_rec[6] = new TH1D ("h_wz_n_ossf_rec_HT", "", nbin, 0, 100);
    histo_wz_n_ossf_rec[7] = new TH1D ("h_wz_n_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_wz_n_ossf_rec[8] = new TH1D ("h_wz_n_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_wz_n_ossf_rec[9] = new TH1D ("h_wz_n_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_wz_n_ossf_rec[10] = new TH1D ("h_wz_n_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_wz_n_ossf_rec[11] = new TH1D ("h_wz_n_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_wz_n_ossf_kin_gen_l1[0] = new TH1D("h_wz_n_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wz_n_ossf_kin_gen_l1[1] = new TH1D("h_wz_n_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_wz_n_ossf_kin_gen_l1[2] = new TH1D("h_wz_n_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_wz_n_ossf_kin_gen_l2[0] = new TH1D("h_wz_n_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wz_n_ossf_kin_gen_l2[1] = new TH1D("h_wz_n_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_wz_n_ossf_kin_gen_l2[2] = new TH1D("h_wz_n_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_wz_n_ossf_kin_gen_l3[0] = new TH1D("h_wz_n_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_wz_n_ossf_kin_gen_l3[1] = new TH1D("h_wz_n_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_wz_n_ossf_kin_gen_l3[2] = new TH1D("h_wz_n_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_wz_n_ossf_gen[0] = new TH1D ("h_wz_n_ossf_gen_met", "", nbin, 0, 100);
    histo_wz_n_ossf_gen[1] = new TH1D ("h_wz_n_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_wz_n_ossf_gen[2] = new TH1D ("h_wz_n_ossf_gen_lll", "", nbin, 0, 100);
    histo_wz_n_ossf_gen[3] = new TH1D ("h_wz_n_ossf_gen_ll", "", nbin, 0, 100);
    histo_wz_n_ossf_gen[4] = new TH1D ("h_wz_n_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_wz_n_ossf_kin_rec_l1[i]->Sumw2();
        histo_wz_n_ossf_kin_rec_l2[i]->Sumw2();
        histo_wz_n_ossf_kin_rec_l3[i]->Sumw2();
        histo_wz_n_ossf_kin_gen_l1[i]->Sumw2();
        histo_wz_n_ossf_kin_gen_l2[i]->Sumw2();
        histo_wz_n_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_wz_n_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_wz_n_ossf_gen[i]-> Sumw2();
    }
    
    /////////////////// 1 dy1_ossf /////////////////////////
    static TH1D* histo_dy1_ossf_kin_rec_l1[4];
    static TH1D* histo_dy1_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_dy1_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_dy1_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_dy1_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_dy1_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_dy1_ossf_rec[num_histo];
    static TH1D* histo_dy1_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_dy1_ossf_kin_rec_l1[0] = new TH1D("h_dy1_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy1_ossf_kin_rec_l1[1] = new TH1D("h_dy1_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_dy1_ossf_kin_rec_l1[2] = new TH1D("h_dy1_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_dy1_ossf_kin_rec_l1[3] = new TH1D("h_dy1_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_dy1_ossf_kin_rec_l2[0] = new TH1D("h_dy1_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy1_ossf_kin_rec_l2[1] = new TH1D("h_dy1_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_dy1_ossf_kin_rec_l2[2] = new TH1D("h_dy1_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_dy1_ossf_kin_rec_l3[0] = new TH1D("h_dy1_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy1_ossf_kin_rec_l3[1] = new TH1D("h_dy1_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_dy1_ossf_kin_rec_l3[2] = new TH1D("h_dy1_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_dy1_ossf_rec[0] = new TH1D ("h_dy1_ossf_rec_met", "", nbin, 0, 100);
    histo_dy1_ossf_rec[1] = new TH1D ("h_dy1_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_dy1_ossf_rec[2] = new TH1D ("h_dy1_ossf_rec_lll", "", nbin, 0, 100);
    histo_dy1_ossf_rec[3] = new TH1D ("h_dy1_ossf_rec_ll", "", nbin, 0, 100);
    histo_dy1_ossf_rec[4] = new TH1D ("h_dy1_ossf_rec_nJet", "", 10, 0, 10);
    histo_dy1_ossf_rec[5] = new TH1D ("h_dy1_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_dy1_ossf_rec[6] = new TH1D ("h_dy1_ossf_rec_HT", "", nbin, 0, 100);
    histo_dy1_ossf_rec[7] = new TH1D ("h_dy1_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_dy1_ossf_rec[8] = new TH1D ("h_dy1_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_dy1_ossf_rec[9] = new TH1D ("h_dy1_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_dy1_ossf_rec[10] = new TH1D ("h_dy1_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_dy1_ossf_rec[11] = new TH1D ("h_dy1_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_dy1_ossf_kin_gen_l1[0] = new TH1D("h_dy1_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy1_ossf_kin_gen_l1[1] = new TH1D("h_dy1_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_dy1_ossf_kin_gen_l1[2] = new TH1D("h_dy1_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_dy1_ossf_kin_gen_l2[0] = new TH1D("h_dy1_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy1_ossf_kin_gen_l2[1] = new TH1D("h_dy1_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_dy1_ossf_kin_gen_l2[2] = new TH1D("h_dy1_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_dy1_ossf_kin_gen_l3[0] = new TH1D("h_dy1_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy1_ossf_kin_gen_l3[1] = new TH1D("h_dy1_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_dy1_ossf_kin_gen_l3[2] = new TH1D("h_dy1_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_dy1_ossf_gen[0] = new TH1D ("h_dy1_ossf_gen_met", "", nbin, 0, 100);
    histo_dy1_ossf_gen[1] = new TH1D ("h_dy1_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_dy1_ossf_gen[2] = new TH1D ("h_dy1_ossf_gen_lll", "", nbin, 0, 100);
    histo_dy1_ossf_gen[3] = new TH1D ("h_dy1_ossf_gen_ll", "", nbin, 0, 100);
    histo_dy1_ossf_gen[4] = new TH1D ("h_dy1_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_dy1_ossf_kin_rec_l1[i]->Sumw2();
        histo_dy1_ossf_kin_rec_l2[i]->Sumw2();
        histo_dy1_ossf_kin_rec_l3[i]->Sumw2();
        histo_dy1_ossf_kin_gen_l1[i]->Sumw2();
        histo_dy1_ossf_kin_gen_l2[i]->Sumw2();
        histo_dy1_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_dy1_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_dy1_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 dy1_n_ossf /////////////////////////
    static TH1D* histo_dy1_n_ossf_kin_rec_l1[4];
    static TH1D* histo_dy1_n_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_dy1_n_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_dy1_n_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_dy1_n_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_dy1_n_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_dy1_n_ossf_rec[num_histo];
    static TH1D* histo_dy1_n_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_dy1_n_ossf_kin_rec_l1[0] = new TH1D("h_dy1_n_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy1_n_ossf_kin_rec_l1[1] = new TH1D("h_dy1_n_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_dy1_n_ossf_kin_rec_l1[2] = new TH1D("h_dy1_n_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_dy1_n_ossf_kin_rec_l1[3] = new TH1D("h_dy1_n_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_dy1_n_ossf_kin_rec_l2[0] = new TH1D("h_dy1_n_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy1_n_ossf_kin_rec_l2[1] = new TH1D("h_dy1_n_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_dy1_n_ossf_kin_rec_l2[2] = new TH1D("h_dy1_n_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_dy1_n_ossf_kin_rec_l3[0] = new TH1D("h_dy1_n_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy1_n_ossf_kin_rec_l3[1] = new TH1D("h_dy1_n_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_dy1_n_ossf_kin_rec_l3[2] = new TH1D("h_dy1_n_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_dy1_n_ossf_rec[0] = new TH1D ("h_dy1_n_ossf_rec_met", "", nbin, 0, 100);
    histo_dy1_n_ossf_rec[1] = new TH1D ("h_dy1_n_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_dy1_n_ossf_rec[2] = new TH1D ("h_dy1_n_ossf_rec_lll", "", nbin, 0, 100);
    histo_dy1_n_ossf_rec[3] = new TH1D ("h_dy1_n_ossf_rec_ll", "", nbin, 0, 100);
    histo_dy1_n_ossf_rec[4] = new TH1D ("h_dy1_n_ossf_rec_nJet", "", 10, 0, 10);
    histo_dy1_n_ossf_rec[5] = new TH1D ("h_dy1_n_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_dy1_n_ossf_rec[6] = new TH1D ("h_dy1_n_ossf_rec_HT", "", nbin, 0, 100);
    histo_dy1_n_ossf_rec[7] = new TH1D ("h_dy1_n_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_dy1_n_ossf_rec[8] = new TH1D ("h_dy1_n_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_dy1_n_ossf_rec[9] = new TH1D ("h_dy1_n_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_dy1_n_ossf_rec[10] = new TH1D ("h_dy1_n_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_dy1_n_ossf_rec[11] = new TH1D ("h_dy1_n_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_dy1_n_ossf_kin_gen_l1[0] = new TH1D("h_dy1_n_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy1_n_ossf_kin_gen_l1[1] = new TH1D("h_dy1_n_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_dy1_n_ossf_kin_gen_l1[2] = new TH1D("h_dy1_n_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_dy1_n_ossf_kin_gen_l2[0] = new TH1D("h_dy1_n_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy1_n_ossf_kin_gen_l2[1] = new TH1D("h_dy1_n_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_dy1_n_ossf_kin_gen_l2[2] = new TH1D("h_dy1_n_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_dy1_n_ossf_kin_gen_l3[0] = new TH1D("h_dy1_n_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy1_n_ossf_kin_gen_l3[1] = new TH1D("h_dy1_n_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_dy1_n_ossf_kin_gen_l3[2] = new TH1D("h_dy1_n_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_dy1_n_ossf_gen[0] = new TH1D ("h_dy1_n_ossf_gen_met", "", nbin, 0, 100);
    histo_dy1_n_ossf_gen[1] = new TH1D ("h_dy1_n_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_dy1_n_ossf_gen[2] = new TH1D ("h_dy1_n_ossf_gen_lll", "", nbin, 0, 100);
    histo_dy1_n_ossf_gen[3] = new TH1D ("h_dy1_n_ossf_gen_ll", "", nbin, 0, 100);
    histo_dy1_n_ossf_gen[4] = new TH1D ("h_dy1_n_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_dy1_n_ossf_kin_rec_l1[i]->Sumw2();
        histo_dy1_n_ossf_kin_rec_l2[i]->Sumw2();
        histo_dy1_n_ossf_kin_rec_l3[i]->Sumw2();
        histo_dy1_n_ossf_kin_gen_l1[i]->Sumw2();
        histo_dy1_n_ossf_kin_gen_l2[i]->Sumw2();
        histo_dy1_n_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_dy1_n_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_dy1_n_ossf_gen[i]-> Sumw2();
    }
    
    
    
    /////////////////// 1 dy2_ossf /////////////////////////
    static TH1D* histo_dy2_ossf_kin_rec_l1[4];
    static TH1D* histo_dy2_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_dy2_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_dy2_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_dy2_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_dy2_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_dy2_ossf_rec[num_histo];
    static TH1D* histo_dy2_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_dy2_ossf_kin_rec_l1[0] = new TH1D("h_dy2_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy2_ossf_kin_rec_l1[1] = new TH1D("h_dy2_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_dy2_ossf_kin_rec_l1[2] = new TH1D("h_dy2_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_dy2_ossf_kin_rec_l1[3] = new TH1D("h_dy2_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_dy2_ossf_kin_rec_l2[0] = new TH1D("h_dy2_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy2_ossf_kin_rec_l2[1] = new TH1D("h_dy2_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_dy2_ossf_kin_rec_l2[2] = new TH1D("h_dy2_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_dy2_ossf_kin_rec_l3[0] = new TH1D("h_dy2_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy2_ossf_kin_rec_l3[1] = new TH1D("h_dy2_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_dy2_ossf_kin_rec_l3[2] = new TH1D("h_dy2_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_dy2_ossf_rec[0] = new TH1D ("h_dy2_ossf_rec_met", "", nbin, 0, 100);
    histo_dy2_ossf_rec[1] = new TH1D ("h_dy2_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_dy2_ossf_rec[2] = new TH1D ("h_dy2_ossf_rec_lll", "", nbin, 0, 100);
    histo_dy2_ossf_rec[3] = new TH1D ("h_dy2_ossf_rec_ll", "", nbin, 0, 100);
    histo_dy2_ossf_rec[4] = new TH1D ("h_dy2_ossf_rec_nJet", "", 10, 0, 10);
    histo_dy2_ossf_rec[5] = new TH1D ("h_dy2_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_dy2_ossf_rec[6] = new TH1D ("h_dy2_ossf_rec_HT", "", nbin, 0, 100);
    histo_dy2_ossf_rec[7] = new TH1D ("h_dy2_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_dy2_ossf_rec[8] = new TH1D ("h_dy2_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_dy2_ossf_rec[9] = new TH1D ("h_dy2_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_dy2_ossf_rec[10] = new TH1D ("h_dy2_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_dy2_ossf_rec[11] = new TH1D ("h_dy2_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_dy2_ossf_kin_gen_l1[0] = new TH1D("h_dy2_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy2_ossf_kin_gen_l1[1] = new TH1D("h_dy2_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_dy2_ossf_kin_gen_l1[2] = new TH1D("h_dy2_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_dy2_ossf_kin_gen_l2[0] = new TH1D("h_dy2_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy2_ossf_kin_gen_l2[1] = new TH1D("h_dy2_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_dy2_ossf_kin_gen_l2[2] = new TH1D("h_dy2_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_dy2_ossf_kin_gen_l3[0] = new TH1D("h_dy2_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy2_ossf_kin_gen_l3[1] = new TH1D("h_dy2_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_dy2_ossf_kin_gen_l3[2] = new TH1D("h_dy2_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_dy2_ossf_gen[0] = new TH1D ("h_dy2_ossf_gen_met", "", nbin, 0, 100);
    histo_dy2_ossf_gen[1] = new TH1D ("h_dy2_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_dy2_ossf_gen[2] = new TH1D ("h_dy2_ossf_gen_lll", "", nbin, 0, 100);
    histo_dy2_ossf_gen[3] = new TH1D ("h_dy2_ossf_gen_ll", "", nbin, 0, 100);
    histo_dy2_ossf_gen[4] = new TH1D ("h_dy2_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_dy2_ossf_kin_rec_l1[i]->Sumw2();
        histo_dy2_ossf_kin_rec_l2[i]->Sumw2();
        histo_dy2_ossf_kin_rec_l3[i]->Sumw2();
        histo_dy2_ossf_kin_gen_l1[i]->Sumw2();
        histo_dy2_ossf_kin_gen_l2[i]->Sumw2();
        histo_dy2_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_dy2_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_dy2_ossf_gen[i]-> Sumw2();
    }
    /////////////////// 1 dy2_n_ossf /////////////////////////
    static TH1D* histo_dy2_n_ossf_kin_rec_l1[4];
    static TH1D* histo_dy2_n_ossf_kin_rec_l2[num_histo_kin];
    static TH1D* histo_dy2_n_ossf_kin_rec_l3[num_histo_kin];
    static TH1D* histo_dy2_n_ossf_kin_gen_l1[num_histo_kin];
    static TH1D* histo_dy2_n_ossf_kin_gen_l2[num_histo_kin];
    static TH1D* histo_dy2_n_ossf_kin_gen_l3[num_histo_kin];
    static  TH1D* histo_dy2_n_ossf_rec[num_histo];
    static TH1D* histo_dy2_n_ossf_gen[5];
    //============== HISTOGRAMS RECO =================
    histo_dy2_n_ossf_kin_rec_l1[0] = new TH1D("h_dy2_n_ossf_rec_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy2_n_ossf_kin_rec_l1[1] = new TH1D("h_dy2_n_ossf_rec_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_dy2_n_ossf_kin_rec_l1[2] = new TH1D("h_dy2_n_ossf_rec_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_dy2_n_ossf_kin_rec_l1[3] = new TH1D("h_dy2_n_ossf_rec_L1_dR","#Delta R", 50, 0, 3.5); // electron deltaR
    histo_dy2_n_ossf_kin_rec_l2[0] = new TH1D("h_dy2_n_ossf_rec_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy2_n_ossf_kin_rec_l2[1] = new TH1D("h_dy2_n_ossf_rec_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_dy2_n_ossf_kin_rec_l2[2] = new TH1D("h_dy2_n_ossf_rec_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_dy2_n_ossf_kin_rec_l3[0] = new TH1D("h_dy2_n_ossf_rec_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy2_n_ossf_kin_rec_l3[1] = new TH1D("h_dy2_n_ossf_rec_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_dy2_n_ossf_kin_rec_l3[2] = new TH1D("h_dy2_n_ossf_rec_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_dy2_n_ossf_rec[0] = new TH1D ("h_dy2_n_ossf_rec_met", "", nbin, 0, 100);
    histo_dy2_n_ossf_rec[1] = new TH1D ("h_dy2_n_ossf_rec_sum_pT", "", nbin*2, 0, 200);
    histo_dy2_n_ossf_rec[2] = new TH1D ("h_dy2_n_ossf_rec_lll", "", nbin, 0, 100);
    histo_dy2_n_ossf_rec[3] = new TH1D ("h_dy2_n_ossf_rec_ll", "", nbin, 0, 100);
    histo_dy2_n_ossf_rec[4] = new TH1D ("h_dy2_n_ossf_rec_nJet", "", 10, 0, 10);
    histo_dy2_n_ossf_rec[5] = new TH1D ("h_dy2_n_ossf_rec_sum_pT_2l", "", nbin*2, 0, 200);
    histo_dy2_n_ossf_rec[6] = new TH1D ("h_dy2_n_ossf_rec_HT", "", nbin, 0, 100);
    histo_dy2_n_ossf_rec[7] = new TH1D ("h_dy2_n_ossf_rec_jetPt", "", nbin, 0, 100);
    histo_dy2_n_ossf_rec[8] = new TH1D ("h_dy2_n_ossf_rec_jetEta", "", nbin,-3, 3);
    histo_dy2_n_ossf_rec[9] = new TH1D ("h_dy2_n_ossf_rec_jetPhi", "", nbin,  -pigreco, pigreco);
    histo_dy2_n_ossf_rec[10] = new TH1D ("h_dy2_n_ossf_rec_jetFlavour", "", 10, 0, 10);
    histo_dy2_n_ossf_rec[11] = new TH1D ("h_dy2_n_ossf_rec_mll_pair", "", nbin, 0, 100);
    //============== HISTOGRAMS GEN =================
    histo_dy2_n_ossf_kin_gen_l1[0] = new TH1D("h_dy2_n_ossf_gen_L1_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy2_n_ossf_kin_gen_l1[1] = new TH1D("h_dy2_n_ossf_gen_L1_eta","#eta", nbin,  -3, 3); // electron pT
    histo_dy2_n_ossf_kin_gen_l1[2] = new TH1D("h_dy2_n_ossf_gen_L1_phi","#phi", nbin, -pigreco, pigreco); // electron phi
    histo_dy2_n_ossf_kin_gen_l2[0] = new TH1D("h_dy2_n_ossf_gen_l2_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy2_n_ossf_kin_gen_l2[1] = new TH1D("h_dy2_n_ossf_gen_l2_eta","#eta", nbin,  -3, 3); // electron eta
    histo_dy2_n_ossf_kin_gen_l2[2] = new TH1D("h_dy2_n_ossf_gen_l2_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_dy2_n_ossf_kin_gen_l3[0] = new TH1D("h_dy2_n_ossf_gen_l3_pt","p_{T}", nbin,  0, 100); // electron pT
    histo_dy2_n_ossf_kin_gen_l3[1] = new TH1D("h_dy2_n_ossf_gen_l3_eta","#eta", nbin,  -3, 3); // electron eta
    histo_dy2_n_ossf_kin_gen_l3[2] = new TH1D("h_dy2_n_ossf_gen_l3_phi","#phi", nbin,  -pigreco, pigreco); // electron phi
    histo_dy2_n_ossf_gen[0] = new TH1D ("h_dy2_n_ossf_gen_met", "", nbin, 0, 100);
    histo_dy2_n_ossf_gen[1] = new TH1D ("h_dy2_n_ossf_gen_sum_pT", "", nbin*2, 0, 200);
    histo_dy2_n_ossf_gen[2] = new TH1D ("h_dy2_n_ossf_gen_lll", "", nbin, 0, 100);
    histo_dy2_n_ossf_gen[3] = new TH1D ("h_dy2_n_ossf_gen_ll", "", nbin, 0, 100);
    histo_dy2_n_ossf_gen[4] = new TH1D ("h_dy2_n_ossf_gen_ll_pair", "", nbin, 0, 100);
    for (int i = 0; i <3; i++){
        histo_dy2_n_ossf_kin_rec_l1[i]->Sumw2();
        histo_dy2_n_ossf_kin_rec_l2[i]->Sumw2();
        histo_dy2_n_ossf_kin_rec_l3[i]->Sumw2();
        histo_dy2_n_ossf_kin_gen_l1[i]->Sumw2();
        histo_dy2_n_ossf_kin_gen_l2[i]->Sumw2();
        histo_dy2_n_ossf_kin_gen_l3[i]->Sumw2();
    }
    for (int i = 0; i <12; i++){
        histo_dy2_n_ossf_rec[i]-> Sumw2();
    }
    for (int i = 0; i <5; i++){
        histo_dy2_n_ossf_gen[i]-> Sumw2();
    }
    
    
    
    
    
    // *************************************************
    double xsection[6]= {117.864 ,87.31 ,4.42965, 489, 71310,1921.8*3 }; // Zgamma - TT - WZ - Wgamma, dy1, dy2
    double luminosity = 12900;
    
    //==========================================================================================
    Analysis_mc all("/Users/Martina/Desktop/CMS/file_bck/zg.root");
    all.analisi(num_histo_kin,
                num_histo,
                *&hs_ossf_rec_pt_l1,
                *&hs_ossf_rec_eta_l1,
                *&hs_ossf_rec_phi_l1,
                *&hs_ossf_rec_pt_l2,
                *&hs_ossf_rec_eta_l2,
                *&hs_ossf_rec_phi_l2,
                *&hs_ossf_rec_pt_l3,
                *&hs_ossf_rec_eta_l3,
                *&hs_ossf_rec_phi_l3,
                *&hs_ossf_gen_pt_l1,
                *&hs_ossf_gen_eta_l1,
                *&hs_ossf_gen_phi_l1,
                *&hs_ossf_gen_pt_l2,
                *&hs_ossf_gen_eta_l2,
                *&hs_ossf_gen_phi_l2,
                *&hs_ossf_gen_pt_l3,
                *&hs_ossf_gen_eta_l3,
                *&hs_ossf_gen_phi_l3,
                *&hs_ossf_rec_met,
                *&hs_ossf_rec_mT,
                *&hs_ossf_rec_mlll,
                *&hs_ossf_rec_mll,
                *&hs_ossf_gen_met,
                *&hs_ossf_gen_mT,
                *&hs_ossf_gen_mlll,
                *&hs_ossf_gen_mll,
                *&hs_ossf_rec_nJet,
                *&hs_ossf_rec_nbJet,
                *&hs_ossf_rec_HT,
                *&hs_ossf_rec_jetPt,
                *&hs_ossf_rec_jetEta,
                *&hs_ossf_rec_jetPhi,
                *&hs_ossf_rec_jetFlavour,
                *&hs_ossf_rec_mll_pair,
                *&hs_ossf_gen_mll_pair,
                *&hs_n_ossf_rec_pt_l1,
                *&hs_n_ossf_rec_eta_l1,
                *&hs_n_ossf_rec_phi_l1,
                *&hs_n_ossf_rec_pt_l2,
                *&hs_n_ossf_rec_eta_l2,
                *&hs_n_ossf_rec_phi_l2,
                *&hs_n_ossf_rec_pt_l3,
                *&hs_n_ossf_rec_eta_l3,
                *&hs_n_ossf_rec_phi_l3,
                *&hs_n_ossf_gen_pt_l1,
                *&hs_n_ossf_gen_eta_l1,
                *&hs_n_ossf_gen_phi_l1,
                *&hs_n_ossf_gen_pt_l2,
                *&hs_n_ossf_gen_eta_l2,
                *&hs_n_ossf_gen_phi_l2,
                *&hs_n_ossf_gen_pt_l3,
                *&hs_n_ossf_gen_eta_l3,
                *&hs_n_ossf_gen_phi_l3,
                *&hs_n_ossf_rec_met,
                *&hs_n_ossf_rec_mT,
                *&hs_n_ossf_rec_mlll,
                *&hs_n_ossf_rec_mll,
                *&hs_n_ossf_gen_met,
                *&hs_n_ossf_gen_mT,
                *&hs_n_ossf_gen_mlll,
                *&hs_n_ossf_gen_mll,
                *&hs_n_ossf_rec_nJet,
                *&hs_n_ossf_rec_nbJet,
                *&hs_n_ossf_rec_HT,
                *&hs_n_ossf_rec_jetPt,
                *&hs_n_ossf_rec_jetEta,
                *&hs_n_ossf_rec_jetPhi,
                *&hs_n_ossf_rec_jetFlavour,
                *&hs_n_ossf_rec_mll_pair,
                *&hs_n_ossf_gen_mll_pair,
                *&histo_signal_50_ossf_kin_rec_l1,
                *&histo_signal_50_ossf_kin_rec_l2,
                *&histo_signal_50_ossf_kin_rec_l3,
                *&histo_signal_50_ossf_kin_gen_l1,
                *&histo_signal_50_ossf_kin_gen_l2,
                *&histo_signal_50_ossf_kin_gen_l3,
                *&histo_signal_50_ossf_rec,
                *&histo_signal_50_ossf_gen,
                *&histo_signal_50_n_ossf_kin_rec_l1,
                *&histo_signal_50_n_ossf_kin_rec_l2,
                *&histo_signal_50_n_ossf_kin_rec_l3,
                *&histo_signal_50_n_ossf_kin_gen_l1,
                *&histo_signal_50_n_ossf_kin_gen_l2,
                *&histo_signal_50_n_ossf_kin_gen_l3,
                *&histo_signal_50_n_ossf_rec,
                *&histo_signal_50_n_ossf_gen,
                *&histo_signal_20_ossf_kin_rec_l1,
                *&histo_signal_20_ossf_kin_rec_l2,
                *&histo_signal_20_ossf_kin_rec_l3,
                *&histo_signal_20_ossf_kin_gen_l1,
                *&histo_signal_20_ossf_kin_gen_l2,
                *&histo_signal_20_ossf_kin_gen_l3,
                *&histo_signal_20_ossf_rec,
                *&histo_signal_20_ossf_gen,
                *&histo_signal_20_n_ossf_kin_rec_l1,
                *&histo_signal_20_n_ossf_kin_rec_l2,
                *&histo_signal_20_n_ossf_kin_rec_l3,
                *&histo_signal_20_n_ossf_kin_gen_l1,
                *&histo_signal_20_n_ossf_kin_gen_l2,
                *&histo_signal_20_n_ossf_kin_gen_l3,
                *&histo_signal_20_n_ossf_rec,
                *&histo_signal_20_n_ossf_gen,
                *&histo_signal_10_ossf_kin_rec_l1,
                *&histo_signal_10_ossf_kin_rec_l2,
                *&histo_signal_10_ossf_kin_rec_l3,
                *&histo_signal_10_ossf_kin_gen_l1,
                *&histo_signal_10_ossf_kin_gen_l2,
                *&histo_signal_10_ossf_kin_gen_l3,
                *&histo_signal_10_ossf_rec,
                *&histo_signal_10_ossf_gen,
                *&histo_signal_10_n_ossf_kin_rec_l1,
                *&histo_signal_10_n_ossf_kin_rec_l2,
                *&histo_signal_10_n_ossf_kin_rec_l3,
                *&histo_signal_10_n_ossf_kin_gen_l1,
                *&histo_signal_10_n_ossf_kin_gen_l2,
                *&histo_signal_10_n_ossf_kin_gen_l3,
                *&histo_signal_10_n_ossf_rec,
                *&histo_signal_10_n_ossf_gen,
                *&histo_signal_60_ossf_kin_rec_l1,
                *&histo_signal_60_ossf_kin_rec_l2,
                *&histo_signal_60_ossf_kin_rec_l3,
                *&histo_signal_60_ossf_kin_gen_l1,
                *&histo_signal_60_ossf_kin_gen_l2,
                *&histo_signal_60_ossf_kin_gen_l3,
                *&histo_signal_60_ossf_rec,
                *&histo_signal_60_ossf_gen,
                *&histo_signal_60_n_ossf_kin_rec_l1,
                *&histo_signal_60_n_ossf_kin_rec_l2,
                *&histo_signal_60_n_ossf_kin_rec_l3,
                *&histo_signal_60_n_ossf_kin_gen_l1,
                *&histo_signal_60_n_ossf_kin_gen_l2,
                *&histo_signal_60_n_ossf_kin_gen_l3,
                *&histo_signal_60_n_ossf_rec,
                *&histo_signal_60_n_ossf_gen,
                *&histo_signal_5_ossf_kin_rec_l1,
                *&histo_signal_5_ossf_kin_rec_l2,
                *&histo_signal_5_ossf_kin_rec_l3,
                *&histo_signal_5_ossf_kin_gen_l1,
                *&histo_signal_5_ossf_kin_gen_l2,
                *&histo_signal_5_ossf_kin_gen_l3,
                *&histo_signal_5_ossf_rec,
                *&histo_signal_5_ossf_gen,
                *&histo_signal_5_n_ossf_kin_rec_l1,
                *&histo_signal_5_n_ossf_kin_rec_l2,
                *&histo_signal_5_n_ossf_kin_rec_l3,
                *&histo_signal_5_n_ossf_kin_gen_l1,
                *&histo_signal_5_n_ossf_kin_gen_l2,
                *&histo_signal_5_n_ossf_kin_gen_l3,
                *&histo_signal_5_n_ossf_rec,
                *&histo_signal_5_n_ossf_gen,
                *&histo_signal_15_ossf_kin_rec_l1,
                *&histo_signal_15_ossf_kin_rec_l2,
                *&histo_signal_15_ossf_kin_rec_l3,
                *&histo_signal_15_ossf_kin_gen_l1,
                *&histo_signal_15_ossf_kin_gen_l2,
                *&histo_signal_15_ossf_kin_gen_l3,
                *&histo_signal_15_ossf_rec,
                *&histo_signal_15_ossf_gen,
                *&histo_signal_15_n_ossf_kin_rec_l1,
                *&histo_signal_15_n_ossf_kin_rec_l2,
                *&histo_signal_15_n_ossf_kin_rec_l3,
                *&histo_signal_15_n_ossf_kin_gen_l1,
                *&histo_signal_15_n_ossf_kin_gen_l2,
                *&histo_signal_15_n_ossf_kin_gen_l3,
                *&histo_signal_15_n_ossf_rec,
                *&histo_signal_15_n_ossf_gen,
                *&histo_signal_40_ossf_kin_rec_l1,
                *&histo_signal_40_ossf_kin_rec_l2,
                *&histo_signal_40_ossf_kin_rec_l3,
                *&histo_signal_40_ossf_kin_gen_l1,
                *&histo_signal_40_ossf_kin_gen_l2,
                *&histo_signal_40_ossf_kin_gen_l3,
                *&histo_signal_40_ossf_rec,
                *&histo_signal_40_ossf_gen,
                *&histo_signal_40_n_ossf_kin_rec_l1,
                *&histo_signal_40_n_ossf_kin_rec_l2,
                *&histo_signal_40_n_ossf_kin_rec_l3,
                *&histo_signal_40_n_ossf_kin_gen_l1,
                *&histo_signal_40_n_ossf_kin_gen_l2,
                *&histo_signal_40_n_ossf_kin_gen_l3,
                *&histo_signal_40_n_ossf_rec,
                *&histo_signal_40_n_ossf_gen,
                *&histo_zg_ossf_kin_rec_l1,
                *&histo_zg_ossf_kin_rec_l2,
                *&histo_zg_ossf_kin_rec_l3,
                *&histo_zg_ossf_kin_gen_l1,
                *&histo_zg_ossf_kin_gen_l2,
                *&histo_zg_ossf_kin_gen_l3,
                *&histo_zg_ossf_rec,
                *&histo_zg_ossf_gen,
                *&histo_zg_n_ossf_kin_rec_l1,
                *&histo_zg_n_ossf_kin_rec_l2,
                *&histo_zg_n_ossf_kin_rec_l3,
                *&histo_zg_n_ossf_kin_gen_l1,
                *&histo_zg_n_ossf_kin_gen_l2,
                *&histo_zg_n_ossf_kin_gen_l3,
                *&histo_zg_n_ossf_rec,
                *&histo_zg_n_ossf_gen,
                *&histo_tt_ossf_kin_rec_l1,
                *&histo_tt_ossf_kin_rec_l2,
                *&histo_tt_ossf_kin_rec_l3,
                *&histo_tt_ossf_kin_gen_l1,
                *&histo_tt_ossf_kin_gen_l2,
                *&histo_tt_ossf_kin_gen_l3,
                *&histo_tt_ossf_rec,
                *&histo_tt_ossf_gen,
                *&histo_tt_n_ossf_kin_rec_l1,
                *&histo_tt_n_ossf_kin_rec_l2,
                *&histo_tt_n_ossf_kin_rec_l3,
                *&histo_tt_n_ossf_kin_gen_l1,
                *&histo_tt_n_ossf_kin_gen_l2,
                *&histo_tt_n_ossf_kin_gen_l3,
                *&histo_tt_n_ossf_rec,
                *&histo_tt_n_ossf_gen,
                *&histo_wg_ossf_kin_rec_l1,
                *&histo_wg_ossf_kin_rec_l2,
                *&histo_wg_ossf_kin_rec_l3,
                *&histo_wg_ossf_kin_gen_l1,
                *&histo_wg_ossf_kin_gen_l2,
                *&histo_wg_ossf_kin_gen_l3,
                *&histo_wg_ossf_rec,
                *&histo_wg_ossf_gen,
                *&histo_wg_n_ossf_kin_rec_l1,
                *&histo_wg_n_ossf_kin_rec_l2,
                *&histo_wg_n_ossf_kin_rec_l3,
                *&histo_wg_n_ossf_kin_gen_l1,
                *&histo_wg_n_ossf_kin_gen_l2,
                *&histo_wg_n_ossf_kin_gen_l3,
                *&histo_wg_n_ossf_rec,
                *&histo_wg_n_ossf_gen,
                *&histo_wz_ossf_kin_rec_l1,
                *&histo_wz_ossf_kin_rec_l2,
                *&histo_wz_ossf_kin_rec_l3,
                *&histo_wz_ossf_kin_gen_l1,
                *&histo_wz_ossf_kin_gen_l2,
                *&histo_wz_ossf_kin_gen_l3,
                *&histo_wz_ossf_rec,
                *&histo_wz_ossf_gen,
                *&histo_wz_n_ossf_kin_rec_l1,
                *&histo_wz_n_ossf_kin_rec_l2,
                *&histo_wz_n_ossf_kin_rec_l3,
                *&histo_wz_n_ossf_kin_gen_l1,
                *&histo_wz_n_ossf_kin_gen_l2,
                *&histo_wz_n_ossf_kin_gen_l3,
                *&histo_wz_n_ossf_rec,
                *&histo_wz_n_ossf_gen,
                *&histo_dy1_ossf_kin_rec_l1,
                *&histo_dy1_ossf_kin_rec_l2,
                *&histo_dy1_ossf_kin_rec_l3,
                *&histo_dy1_ossf_kin_gen_l1,
                *&histo_dy1_ossf_kin_gen_l2,
                *&histo_dy1_ossf_kin_gen_l3,
                *&histo_dy1_ossf_rec,
                *&histo_dy1_ossf_gen,
                *&histo_dy1_n_ossf_kin_rec_l1,
                *&histo_dy1_n_ossf_kin_rec_l2,
                *&histo_dy1_n_ossf_kin_rec_l3,
                *&histo_dy1_n_ossf_kin_gen_l1,
                *&histo_dy1_n_ossf_kin_gen_l2,
                *&histo_dy1_n_ossf_kin_gen_l3,
                *&histo_dy1_n_ossf_rec,
                *&histo_dy1_n_ossf_gen,
                *&histo_dy2_ossf_kin_rec_l1,
                *&histo_dy2_ossf_kin_rec_l2,
                *&histo_dy2_ossf_kin_rec_l3,
                *&histo_dy2_ossf_kin_gen_l1,
                *&histo_dy2_ossf_kin_gen_l2,
                *&histo_dy2_ossf_kin_gen_l3,
                *&histo_dy2_ossf_rec,
                *&histo_dy2_ossf_gen,
                *&histo_dy2_n_ossf_kin_rec_l1,
                *&histo_dy2_n_ossf_kin_rec_l2,
                *&histo_dy2_n_ossf_kin_rec_l3,
                *&histo_dy2_n_ossf_kin_gen_l1,
                *&histo_dy2_n_ossf_kin_gen_l2,
                *&histo_dy2_n_ossf_kin_gen_l3,
                *&histo_dy2_n_ossf_rec,
                *&histo_dy2_n_ossf_gen,
                *&hs_ossf_flavor,
                *&hs_n_ossf_flavor,
                *&flavor_plot_signal_50_ossf,
                *&flavor_plot_signal_50_n_ossf,
                *&flavor_plot_signal_20_ossf,
                *&flavor_plot_signal_20_n_ossf,
                *&flavor_plot_signal_10_ossf,
                *&flavor_plot_signal_10_n_ossf,
                *&flavor_plot_signal_60_ossf,
                *&flavor_plot_signal_60_n_ossf,
                *&flavor_plot_signal_15_ossf,
                *&flavor_plot_signal_15_n_ossf,
                *&flavor_plot_signal_5_ossf,
                *&flavor_plot_signal_5_n_ossf,
                *&flavor_plot_signal_40_ossf,
                *&flavor_plot_signal_40_n_ossf,
                *&flavor_plot_zg_ossf,
                *&flavor_plot_zg_n_ossf,
                *&flavor_plot_tt_ossf,
                *&flavor_plot_tt_n_ossf,
                *&flavor_plot_wg_ossf,
                *&flavor_plot_wg_n_ossf,
                *&flavor_plot_wz_ossf,
                *&flavor_plot_wz_n_ossf,
                *&flavor_plot_dy1_ossf,
                *&flavor_plot_dy1_n_ossf,
                *&flavor_plot_dy2_ossf,
                *&flavor_plot_dy2_n_ossf,
                *&signal_5_2d_ossf,
                *&signal_40_2d_ossf,
                *&signal_15_2d_ossf,
                *&signal_60_2d_ossf,
                *&signal_40_2d_n_ossf,
                *&signal_5_2d_n_ossf,
                *&signal_15_2d_n_ossf,
                *&signal_60_2d_n_ossf,
                *&signal_10_2d_ossf,
                *&signal_20_2d_ossf,
                *&signal_50_2d_ossf,
                *&signal_10_2d_n_ossf,
                *&signal_20_2d_n_ossf,
                *&signal_50_2d_n_ossf,
                *&signal_5_2d_pt_ossf,
                *&signal_40_2d_pt_ossf,
                *&signal_15_2d_pt_ossf,
                *&signal_60_2d_pt_ossf,
                *&signal_40_2d_pt_n_ossf,
                *&signal_5_2d_pt_n_ossf,
                *&signal_15_2d_pt_n_ossf,
                *&signal_60_2d_pt_n_ossf,
                *&signal_10_2d_pt_ossf,
                *&signal_20_2d_pt_ossf,
                *&signal_50_2d_pt_ossf,
                *&signal_10_2d_pt_n_ossf,
                *&signal_20_2d_pt_n_ossf,
                *&signal_50_2d_pt_n_ossf,
                *&wg_2d_ossf,
                *&wz_2d_ossf,
                *&zg_2d_ossf,
                *&tt_2d_ossf,
                *&wg_2d_n_ossf,
                *&wz_2d_n_ossf,
                *&zg_2d_n_ossf,
                *&tt_2d_n_ossf,
                *&dy1_2d_ossf,
                *&dy2_2d_ossf,
                *&dy1_2d_n_ossf,
                *&dy2_2d_n_ossf
                );
    
    TCanvas *c_2d_delta_R_ossf= new TCanvas("c_2d_delta_R_ossf","c_2d_delta_R_ossf",10,10,700,700);
    c_2d_delta_R_ossf->Divide(4,3);
    c_2d_delta_R_ossf->cd(1);
    signal_5_2d_ossf->GetXaxis()->SetTitle("min_#Delta R");
    signal_5_2d_ossf->GetYaxis()->SetTitle("max_#Delta R");
    signal_5_2d_ossf->Draw("COLZ");
    c_2d_delta_R_ossf->cd(2);
    signal_10_2d_ossf->GetXaxis()->SetTitle("min_#Delta R");
    signal_10_2d_ossf->GetYaxis()->SetTitle("max_#Delta R");
    signal_10_2d_ossf->Draw("COLZ");
    c_2d_delta_R_ossf->cd(3);
    signal_15_2d_ossf->GetXaxis()->SetTitle("min_#Delta R");
    signal_15_2d_ossf->GetYaxis()->SetTitle("max_#Delta R");
    signal_15_2d_ossf->Draw("COLZ");
    c_2d_delta_R_ossf->cd(4);
    signal_20_2d_ossf->GetXaxis()->SetTitle("min_#Delta R");
    signal_20_2d_ossf->GetYaxis()->SetTitle("max_#Delta R");
    signal_20_2d_ossf->Draw("COLZ");
    c_2d_delta_R_ossf->cd(5);
    signal_40_2d_ossf->GetXaxis()->SetTitle("min_#Delta R");
    signal_40_2d_ossf->GetYaxis()->SetTitle("max_#Delta R");
    signal_40_2d_ossf->Draw("COLZ");
    c_2d_delta_R_ossf->cd(6);
    signal_50_2d_ossf->GetXaxis()->SetTitle("min_#Delta R");
    signal_50_2d_ossf->GetYaxis()->SetTitle("max_#Delta R");
    signal_50_2d_ossf->Draw("COLZ");
    c_2d_delta_R_ossf->cd(7);
    signal_60_2d_ossf->GetXaxis()->SetTitle("min_#Delta R");
    signal_60_2d_ossf->GetYaxis()->SetTitle("max_#Delta R");
    signal_60_2d_ossf->Draw("COLZ");
    c_2d_delta_R_ossf->cd(9);
    wg_2d_ossf->GetXaxis()->SetTitle("min_#Delta R");
    wg_2d_ossf->GetYaxis()->SetTitle("max_#Delta R");
    wg_2d_ossf->Draw("COLZ");
    c_2d_delta_R_ossf->cd(10);
    wz_2d_ossf->GetXaxis()->SetTitle("min_#Delta R");
    wz_2d_ossf->GetYaxis()->SetTitle("max_#Delta R");
    wz_2d_ossf->Draw("COLZ");
    c_2d_delta_R_ossf->cd(11);
    zg_2d_ossf->GetXaxis()->SetTitle("min_#Delta R");
    zg_2d_ossf->GetYaxis()->SetTitle("max_#Delta R");
    zg_2d_ossf->Draw("COLZ");
    c_2d_delta_R_ossf->cd(12);
    tt_2d_ossf->GetXaxis()->SetTitle("min_#Delta R");
    tt_2d_ossf->GetYaxis()->SetTitle("max_#Delta R");
    tt_2d_ossf->Draw("COLZ");
    c_2d_delta_R_ossf->Print("PLOT/c_2d_delta_R_ossf.root");
    delete c_2d_delta_R_ossf;
    
    
    TCanvas *c_2d_delta_R_n_ossf= new TCanvas("c_2d_delta_R_n_ossf","c_2d_delta_R_n_ossf",10,10,700,700);
    c_2d_delta_R_n_ossf->Divide(4,4);
    c_2d_delta_R_n_ossf->cd(1);
    signal_5_2d_n_ossf->GetXaxis()->SetTitle("min_#Delta R");
    signal_5_2d_n_ossf->GetYaxis()->SetTitle("max_#Delta R");
    signal_5_2d_n_ossf->Draw("COLZ");
    c_2d_delta_R_n_ossf->cd(2);
    signal_10_2d_n_ossf->GetXaxis()->SetTitle("min_#Delta R");
    signal_10_2d_n_ossf->GetYaxis()->SetTitle("max_#Delta R");
    signal_10_2d_n_ossf->Draw("COLZ");
    c_2d_delta_R_n_ossf->cd(3);
    signal_15_2d_n_ossf->GetXaxis()->SetTitle("min_#Delta R");
    signal_15_2d_n_ossf->GetYaxis()->SetTitle("max_#Delta R");
    signal_15_2d_n_ossf->Draw("COLZ");
    c_2d_delta_R_n_ossf->cd(4);
    signal_20_2d_n_ossf->GetXaxis()->SetTitle("min_#Delta R");
    signal_20_2d_n_ossf->GetYaxis()->SetTitle("max_#Delta R");
    signal_20_2d_n_ossf->Draw("COLZ");
    c_2d_delta_R_n_ossf->cd(5);
    signal_40_2d_n_ossf->GetXaxis()->SetTitle("min_#Delta R");
    signal_40_2d_n_ossf->GetYaxis()->SetTitle("max_#Delta R");
    signal_40_2d_n_ossf->Draw("COLZ");
    c_2d_delta_R_n_ossf->cd(6);
    signal_50_2d_n_ossf->GetXaxis()->SetTitle("min_#Delta R");
    signal_50_2d_n_ossf->GetYaxis()->SetTitle("max_#Delta R");
    signal_50_2d_n_ossf->Draw("COLZ");
    c_2d_delta_R_n_ossf->cd(7);
    signal_60_2d_n_ossf->GetXaxis()->SetTitle("min_#Delta R");
    signal_60_2d_n_ossf->GetYaxis()->SetTitle("max_#Delta R");
    signal_60_2d_n_ossf->Draw("COLZ");
    c_2d_delta_R_n_ossf->cd(9);
    wg_2d_n_ossf->GetXaxis()->SetTitle("min_#Delta R");
    wg_2d_n_ossf->GetYaxis()->SetTitle("max_#Delta R");
    wg_2d_n_ossf->Draw("COLZ");
    c_2d_delta_R_n_ossf->cd(10);
    wz_2d_n_ossf->GetXaxis()->SetTitle("min_#Delta R");
    wz_2d_n_ossf->GetYaxis()->SetTitle("max_#Delta R");
    wz_2d_n_ossf->Draw("COLZ");
    c_2d_delta_R_n_ossf->cd(11);
    zg_2d_n_ossf->GetXaxis()->SetTitle("min_#Delta R");
    zg_2d_n_ossf->GetYaxis()->SetTitle("max_#Delta R");
    zg_2d_n_ossf->Draw("COLZ");
    c_2d_delta_R_n_ossf->cd(12);
    tt_2d_n_ossf->GetXaxis()->SetTitle("min_#Delta R");
    tt_2d_n_ossf->GetYaxis()->SetTitle("max_#Delta R");
    tt_2d_n_ossf->Draw("COLZ");
    c_2d_delta_R_n_ossf->cd(13);
    dy1_2d_n_ossf->GetXaxis()->SetTitle("min_#Delta R");
    dy1_2d_n_ossf->GetYaxis()->SetTitle("max_#Delta R");
    dy1_2d_n_ossf->Draw("COLZ");
    c_2d_delta_R_n_ossf->cd(14);
    dy2_2d_n_ossf->GetXaxis()->SetTitle("min_#Delta R");
    dy2_2d_n_ossf->GetYaxis()->SetTitle("max_#Delta R");
    dy2_2d_n_ossf->Draw("COLZ");
    c_2d_delta_R_n_ossf->Print("PLOT/c_2d_delta_R_n_ossf.root");
    delete c_2d_delta_R_n_ossf;
    
    
    
    
    TCanvas *c_2d_pt_pT_ossf= new TCanvas("c_2d_pt_pT_ossf","c_2d_pt_pT_ossf",10,10,700,700);
    c_2d_pt_pT_ossf->Divide(4,2);
    c_2d_pt_pT_ossf->cd(1);
    signal_5_2d_pt_ossf->GetXaxis()->SetTitle("p_{T} soft lepton");
    signal_5_2d_pt_ossf->GetYaxis()->SetTitle("p_{T} leading lepton");
    signal_5_2d_pt_ossf->Draw("COLZ");
    c_2d_pt_pT_ossf->cd(2);
    signal_10_2d_pt_ossf->GetXaxis()->SetTitle("p_{T} soft lepton");
    signal_10_2d_pt_ossf->GetYaxis()->SetTitle("p_{T} leading lepton");
    signal_10_2d_pt_ossf->Draw("COLZ");
    c_2d_pt_pT_ossf->cd(3);
    signal_15_2d_pt_ossf->GetXaxis()->SetTitle("p_{T} soft lepton");
    signal_15_2d_pt_ossf->GetYaxis()->SetTitle("p_{T} leading lepton");
    signal_15_2d_pt_ossf->Draw("COLZ");
    c_2d_pt_pT_ossf->cd(4);
    signal_20_2d_pt_ossf->GetXaxis()->SetTitle("p_{T} soft lepton");
    signal_20_2d_pt_ossf->GetYaxis()->SetTitle("p_{T} leading lepton");
    signal_20_2d_pt_ossf->Draw("COLZ");
    c_2d_pt_pT_ossf->cd(5);
    signal_40_2d_pt_ossf->GetXaxis()->SetTitle("p_{T} soft lepton");
    signal_40_2d_pt_ossf->GetYaxis()->SetTitle("p_{T} leading lepton");
    signal_40_2d_pt_ossf->Draw("COLZ");
    c_2d_pt_pT_ossf->cd(6);
    signal_50_2d_pt_ossf->GetXaxis()->SetTitle("p_{T} soft lepton");
    signal_50_2d_pt_ossf->GetYaxis()->SetTitle("p_{T} leading lepton");
    signal_50_2d_pt_ossf->Draw("COLZ");
    c_2d_pt_pT_ossf->cd(7);
    signal_60_2d_pt_ossf->GetXaxis()->SetTitle("p_{T} soft lepton");
    signal_60_2d_pt_ossf->GetYaxis()->SetTitle("p_{T} leading lepton");
    signal_60_2d_pt_ossf->Draw("COLZ");
    
    c_2d_pt_pT_ossf->Print("PLOT/c_2d_pt_pT_ossf.root");
    delete c_2d_pt_pT_ossf;
    
    
    TCanvas *c_2d_pt_pT_n_ossf= new TCanvas("c_2d_pt_pT_n_ossf","c_2d_pt_pT_n_ossf",10,10,700,700);
    c_2d_pt_pT_n_ossf->Divide(4,2);
    c_2d_pt_pT_n_ossf->cd(1);
    signal_5_2d_pt_n_ossf->GetXaxis()->SetTitle("p_{T} soft lepton");
    signal_5_2d_pt_n_ossf->GetYaxis()->SetTitle("p_{T} leading lepton");
    signal_5_2d_pt_n_ossf->Draw("COLZ");
    c_2d_pt_pT_n_ossf->cd(2);
    signal_10_2d_pt_n_ossf->GetXaxis()->SetTitle("p_{T} soft lepton");
    signal_10_2d_pt_n_ossf->GetYaxis()->SetTitle("p_{T} leading lepton");
    signal_10_2d_pt_n_ossf->Draw("COLZ");
    c_2d_pt_pT_n_ossf->cd(3);
    signal_15_2d_pt_n_ossf->GetXaxis()->SetTitle("p_{T} soft lepton");
    signal_15_2d_pt_n_ossf->GetYaxis()->SetTitle("p_{T} leading lepton");
    signal_15_2d_pt_n_ossf->Draw("COLZ");
    c_2d_pt_pT_n_ossf->cd(4);
    signal_20_2d_pt_n_ossf->GetXaxis()->SetTitle("p_{T} soft lepton");
    signal_20_2d_pt_n_ossf->GetYaxis()->SetTitle("p_{T} leading lepton");
    signal_20_2d_pt_n_ossf->Draw("COLZ");
    c_2d_pt_pT_n_ossf->cd(5);
    signal_40_2d_pt_n_ossf->GetXaxis()->SetTitle("p_{T} soft lepton");
    signal_40_2d_pt_n_ossf->GetYaxis()->SetTitle("p_{T} leading lepton");
    signal_40_2d_pt_n_ossf->Draw("COLZ");
    c_2d_pt_pT_n_ossf->cd(6);
    signal_50_2d_pt_n_ossf->GetXaxis()->SetTitle("p_{T} soft lepton");
    signal_50_2d_pt_n_ossf->GetYaxis()->SetTitle("p_{T} leading lepton");
    signal_50_2d_pt_n_ossf->Draw("COLZ");
    c_2d_pt_pT_n_ossf->cd(7);
    signal_60_2d_pt_n_ossf->GetXaxis()->SetTitle("p_{T} soft lepton");
    signal_60_2d_pt_n_ossf->GetYaxis()->SetTitle("p_{T} leading lepton");
    signal_60_2d_pt_n_ossf->Draw("COLZ");
    
    c_2d_pt_pT_n_ossf->Print("PLOT/c_2d_pt_pT_n_ossf.root");
    delete c_2d_pt_pT_n_ossf;
    
    
    
    
    
    
    
    TLegend *leg_ossf_deltaR,*leg_n_ossf_deltaR;
    TCanvas *c_st_delta_r = new TCanvas("c_st_delta_r","c_st_delta_r",10,10,700,700);
    c_st_delta_r->Divide(2,1);
    c_st_delta_r->cd(1);
    histo_signal_50_ossf_kin_rec_l1[3]->Scale(1/histo_signal_50_ossf_kin_rec_l1[3]->Integral());
    histo_signal_20_ossf_kin_rec_l1[3]->Scale(1/histo_signal_20_ossf_kin_rec_l1[3]->Integral());
    histo_signal_10_ossf_kin_rec_l1[3]->Scale(1/histo_signal_10_ossf_kin_rec_l1[3]->Integral());
    histo_dy1_ossf_kin_rec_l1[3]->Scale(1/histo_dy1_ossf_kin_rec_l1[3]->Integral());
    histo_dy2_ossf_kin_rec_l1[3]->Scale(1/histo_dy2_ossf_kin_rec_l1[3]->Integral());
    histo_wg_ossf_kin_rec_l1[3]->Scale(1/histo_wg_ossf_kin_rec_l1[3]->Integral());
    histo_tt_ossf_kin_rec_l1[3]->Scale(1/histo_tt_ossf_kin_rec_l1[3]->Integral());
    histo_wz_ossf_kin_rec_l1[3]->Scale(1/histo_wz_ossf_kin_rec_l1[3]->Integral());
    histo_signal_50_ossf_kin_rec_l1[3]->SetLineStyle(21);
    histo_signal_20_ossf_kin_rec_l1[3]->SetLineStyle(7);
    histo_signal_10_ossf_kin_rec_l1[3]->SetLineStyle(3);
    histo_dy1_ossf_kin_rec_l1[3]->SetLineColor(kRed);
    histo_dy2_ossf_kin_rec_l1[3]->SetLineColor(kMagenta);
    histo_wg_ossf_kin_rec_l1[3]->SetLineColor(kOrange);
    histo_tt_ossf_kin_rec_l1[3]->SetLineColor(kBlue);
    histo_wz_ossf_kin_rec_l1[3]->SetLineColor(kGreen);
    histo_signal_50_ossf_kin_rec_l1[3]->Draw("hist");
    histo_signal_20_ossf_kin_rec_l1[3]->Draw("histsame");
    histo_signal_10_ossf_kin_rec_l1[3]->Draw("histsame");
    histo_dy1_ossf_kin_rec_l1[3]->Draw("histsame");
    histo_dy2_ossf_kin_rec_l1[3]->Draw("histsame");
    histo_wg_ossf_kin_rec_l1[3]->Draw("histsame");
    histo_tt_ossf_kin_rec_l1[3]->Draw("histsame");
    histo_wz_ossf_kin_rec_l1[3]->Draw("histsame");
    leg_ossf_deltaR = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_deltaR->SetHeader("OSSF #Delta R"); // option "C" al2ows to center the header
    leg_ossf_deltaR->AddEntry(histo_dy2_ossf_kin_rec_l1[3],"DY","f");
    leg_ossf_deltaR->AddEntry(histo_tt_ossf_kin_rec_l1[3],"ttbar","f");
    leg_ossf_deltaR->AddEntry(histo_wg_ossf_kin_rec_l1[3],"W#gamma","f");
    leg_ossf_deltaR->AddEntry(histo_wz_ossf_kin_rec_l1[3],"WZ","f");
    leg_ossf_deltaR->AddEntry(histo_signal_10_ossf_kin_rec_l1[3],"Majorana sample mN=10 GeV","l");
    leg_ossf_deltaR->AddEntry(histo_signal_20_ossf_kin_rec_l1[3],"Majorana sample mN=20 GeV","l");
    leg_ossf_deltaR->AddEntry(histo_signal_50_ossf_kin_rec_l1[3],"Majorana sample mN=50 GeV","l");
    leg_ossf_deltaR->Draw();
    histo_signal_50_ossf_kin_rec_l1[3]->GetXaxis()->SetTitle("#Delta R");
    histo_signal_50_ossf_kin_rec_l1[3]->GetYaxis()->SetTitle("Events");
    c_st_delta_r->cd(2);
    histo_signal_50_n_ossf_kin_rec_l1[3]->Scale(1/histo_signal_50_n_ossf_kin_rec_l1[3]->Integral());
histo_signal_20_n_ossf_kin_rec_l1[3]->Scale(1/histo_signal_20_n_ossf_kin_rec_l1[3]->Integral());
histo_signal_10_n_ossf_kin_rec_l1[3]->Scale(1/histo_signal_10_n_ossf_kin_rec_l1[3]->Integral());
histo_dy1_n_ossf_kin_rec_l1[3]->Scale(1/histo_dy1_n_ossf_kin_rec_l1[3]->Integral());
histo_dy2_n_ossf_kin_rec_l1[3]->Scale(1/histo_dy2_n_ossf_kin_rec_l1[3]->Integral());
histo_wg_n_ossf_kin_rec_l1[3]->Scale(1/histo_wg_n_ossf_kin_rec_l1[3]->Integral());
histo_tt_n_ossf_kin_rec_l1[3]->Scale(1/histo_tt_n_ossf_kin_rec_l1[3]->Integral());
histo_wz_n_ossf_kin_rec_l1[3]->Scale(1/histo_wz_n_ossf_kin_rec_l1[3]->Integral());
histo_signal_50_n_ossf_kin_rec_l1[3]->SetLineStyle(21);
histo_signal_20_n_ossf_kin_rec_l1[3]->SetLineStyle(7);
histo_signal_10_n_ossf_kin_rec_l1[3]->SetLineStyle(3);
histo_dy1_n_ossf_kin_rec_l1[3]->SetLineColor(kRed);
histo_dy2_n_ossf_kin_rec_l1[3]->SetLineColor(kMagenta);
histo_wg_n_ossf_kin_rec_l1[3]->SetLineColor(kOrange);
histo_tt_n_ossf_kin_rec_l1[3]->SetLineColor(kBlue);
histo_wz_n_ossf_kin_rec_l1[3]->SetLineColor(kGreen);
histo_signal_50_n_ossf_kin_rec_l1[3]->Draw("hist");
histo_signal_20_n_ossf_kin_rec_l1[3]->Draw("histsame");
histo_signal_10_n_ossf_kin_rec_l1[3]->Draw("histsame");
histo_dy1_n_ossf_kin_rec_l1[3]->Draw("histsame");
histo_dy2_n_ossf_kin_rec_l1[3]->Draw("histsame");
histo_wg_n_ossf_kin_rec_l1[3]->Draw("histsame");
histo_tt_n_ossf_kin_rec_l1[3]->Draw("histsame");
histo_wz_n_ossf_kin_rec_l1[3]->Draw("histsame");
leg_n_ossf_deltaR = new TLegend(0.54,0.50,0.90,0.9);
leg_n_ossf_deltaR->SetHeader("n_ossf #Delta R"); // option "C" al2ows to center the header
leg_n_ossf_deltaR->AddEntry(histo_dy2_n_ossf_kin_rec_l1[3],"DY","f");
leg_n_ossf_deltaR->AddEntry(histo_tt_n_ossf_kin_rec_l1[3],"ttbar","f");
leg_n_ossf_deltaR->AddEntry(histo_wg_n_ossf_kin_rec_l1[3],"W#gamma","f");
leg_n_ossf_deltaR->AddEntry(histo_wz_n_ossf_kin_rec_l1[3],"WZ","f");
leg_n_ossf_deltaR->AddEntry(histo_signal_10_n_ossf_kin_rec_l1[3],"Majorana sample mN=10 GeV","l");
leg_n_ossf_deltaR->AddEntry(histo_signal_20_n_ossf_kin_rec_l1[3],"Majorana sample mN=20 GeV","l");
leg_n_ossf_deltaR->AddEntry(histo_signal_50_n_ossf_kin_rec_l1[3],"Majorana sample mN=50 GeV","l");
leg_n_ossf_deltaR->Draw();
histo_signal_50_n_ossf_kin_rec_l1[3]->GetXaxis()->SetTitle("#Delta R");
histo_signal_50_n_ossf_kin_rec_l1[3]->GetYaxis()->SetTitle("Events");
    c_st_delta_r->Print("PLOT/c_st_delta_r.root");
    delete c_st_delta_r;
    
    
    
    //************************************** canvas just signal *******************************
    TLegend *leg_ossf_signal_sample_pt1,*leg_ossf_signal_sample_pt2,*leg_ossf_signal_sample_pt3, *leg_ossf_signal_sample_met,*leg_ossf_signal_sample_mT,*leg_ossf_signal_sample_mlll,*leg_ossf_signal_sample_mll,*leg_ossf_signal_sample_mll_pair,  *leg_ossf_signal_sample_nJet, *leg_ossf_signal_sample_nbJet, *leg_ossf_signal_sample_HT, *leg_ossf_signal_sample_jetPt, *leg_ossf_signal_sample_jetEta, *leg_ossf_signal_sample_jetPhi, *leg_ossf_signal_sample_jetFlavour, *leg_ossf_signal_sample_flavor;
    
    TCanvas *c_st_ossf_signal_sample_pt = new TCanvas("c_st_ossf_signal_sample_pt","c_st_ossf_signal_sample_pt",10,10,700,700);
    c_st_ossf_signal_sample_pt->Divide(3,1);
    c_st_ossf_signal_sample_pt->cd(1);
    histo_signal_50_ossf_kin_rec_l1[0]->SetMaximum(histo_signal_50_ossf_kin_rec_l1[0]-> GetBinContent(histo_signal_50_ossf_kin_rec_l1[0]->GetMaximumBin ()) * 2);
    cosmesi_sample(1,*&histo_signal_5_ossf_kin_rec_l1[0]);
    cosmesi_sample(2,*&histo_signal_10_ossf_kin_rec_l1[0]);
    cosmesi_sample(3,*&histo_signal_15_ossf_kin_rec_l1[0]);
    cosmesi_sample(4,*&histo_signal_20_ossf_kin_rec_l1[0]);
    cosmesi_sample(5,*&histo_signal_40_ossf_kin_rec_l1[0]);
    cosmesi_sample(6,*&histo_signal_50_ossf_kin_rec_l1[0]);
    cosmesi_sample(7,*&histo_signal_60_ossf_kin_rec_l1[0]);
    histo_signal_50_ossf_kin_rec_l1[0]->Draw("hist");
    histo_signal_5_ossf_kin_rec_l1[0]->Draw("histsame");
    histo_signal_10_ossf_kin_rec_l1[0]->Draw("histsame");
    histo_signal_15_ossf_kin_rec_l1[0]->Draw("histsame");
    histo_signal_20_ossf_kin_rec_l1[0]->Draw("histsame");
    histo_signal_40_ossf_kin_rec_l1[0]->Draw("histsame");
    histo_signal_60_ossf_kin_rec_l1[0]->Draw("histsame");
    leg_ossf_signal_sample_pt1 = new TLegend(0.54,0.50,0.90,0.9);
    //leg_ossf_signal_sample_pt1->SetHeader("OSSF p_{T} leading lepton"); // option "C" al2ows to center the header
    leg_ossf_signal_sample_pt1->AddEntry(histo_signal_5_ossf_kin_rec_l1[0],"mN=5 GeV","l");
    leg_ossf_signal_sample_pt1->AddEntry(histo_signal_10_ossf_kin_rec_l1[0],"mN=10 GeV","l");
    leg_ossf_signal_sample_pt1->AddEntry(histo_signal_15_ossf_kin_rec_l1[0],"mN=15 GeV","l");
    leg_ossf_signal_sample_pt1->AddEntry(histo_signal_20_ossf_kin_rec_l1[0],"mN=20 GeV","l");
    leg_ossf_signal_sample_pt1->AddEntry(histo_signal_40_ossf_kin_rec_l1[0],"mN=40 GeV","l");
    leg_ossf_signal_sample_pt1->AddEntry(histo_signal_50_ossf_kin_rec_l1[0],"mN=50 GeV","l");
    leg_ossf_signal_sample_pt1->AddEntry(histo_signal_60_ossf_kin_rec_l1[0],"mN=60 GeV","l");
    leg_ossf_signal_sample_pt1->Draw();
    histo_signal_50_ossf_kin_rec_l1[0]->GetXaxis()->SetTitle("p_{T} (GeV)");
    histo_signal_50_ossf_kin_rec_l1[0]->GetYaxis()->SetTitle("Events");
    
    c_st_ossf_signal_sample_pt->cd(2);
    histo_signal_50_ossf_kin_rec_l2[0]->SetMaximum(histo_signal_50_ossf_kin_rec_l2[0]-> GetBinContent(histo_signal_50_ossf_kin_rec_l2[0]->GetMaximumBin ()) * 2);
    cosmesi_sample(1,*&histo_signal_5_ossf_kin_rec_l2[0]);
    cosmesi_sample(2,*&histo_signal_10_ossf_kin_rec_l2[0]);
    cosmesi_sample(3,*&histo_signal_15_ossf_kin_rec_l2[0]);
    cosmesi_sample(4,*&histo_signal_20_ossf_kin_rec_l2[0]);
    cosmesi_sample(5,*&histo_signal_40_ossf_kin_rec_l2[0]);
    cosmesi_sample(6,*&histo_signal_50_ossf_kin_rec_l2[0]);
    cosmesi_sample(7,*&histo_signal_60_ossf_kin_rec_l2[0]);
    histo_signal_50_ossf_kin_rec_l2[0]->Draw("hist");
    histo_signal_5_ossf_kin_rec_l2[0]->Draw("histsame");
    histo_signal_10_ossf_kin_rec_l2[0]->Draw("histsame");
    histo_signal_15_ossf_kin_rec_l2[0]->Draw("histsame");
    histo_signal_20_ossf_kin_rec_l2[0]->Draw("histsame");
    histo_signal_40_ossf_kin_rec_l2[0]->Draw("histsame");
    histo_signal_60_ossf_kin_rec_l2[0]->Draw("histsame");
    leg_ossf_signal_sample_pt2 = new TLegend(0.54,0.50,0.90,0.9);
    //leg_ossf_signal_sample_pt2->SetHeader("OSSF p_{T} leading lepton"); // option "C" al2ows to center the header
    leg_ossf_signal_sample_pt2->AddEntry(histo_signal_5_ossf_kin_rec_l2[0],"mN=5 GeV","l");
    leg_ossf_signal_sample_pt2->AddEntry(histo_signal_10_ossf_kin_rec_l2[0],"mN=10 GeV","l");
    leg_ossf_signal_sample_pt2->AddEntry(histo_signal_15_ossf_kin_rec_l2[0],"mN=15 GeV","l");
    leg_ossf_signal_sample_pt2->AddEntry(histo_signal_20_ossf_kin_rec_l2[0],"mN=20 GeV","l");
    leg_ossf_signal_sample_pt2->AddEntry(histo_signal_40_ossf_kin_rec_l2[0],"mN=40 GeV","l");
    leg_ossf_signal_sample_pt2->AddEntry(histo_signal_50_ossf_kin_rec_l2[0],"mN=50 GeV","l");
    leg_ossf_signal_sample_pt2->AddEntry(histo_signal_60_ossf_kin_rec_l2[0],"mN=60 GeV","l");
    leg_ossf_signal_sample_pt2->Draw();
    histo_signal_50_ossf_kin_rec_l2[0]->GetXaxis()->SetTitle("p_{T} (GeV)");
    histo_signal_50_ossf_kin_rec_l2[0]->GetYaxis()->SetTitle("Events");
    
    c_st_ossf_signal_sample_pt->cd(3);
    histo_signal_50_ossf_kin_rec_l3[0]->SetMaximum(histo_signal_50_ossf_kin_rec_l3[0]-> GetBinContent(histo_signal_50_ossf_kin_rec_l3[0]->GetMaximumBin ()) * 2);
    cosmesi_sample(1,*&histo_signal_5_ossf_kin_rec_l3[0]);
    cosmesi_sample(2,*&histo_signal_10_ossf_kin_rec_l3[0]);
    cosmesi_sample(3,*&histo_signal_15_ossf_kin_rec_l3[0]);
    cosmesi_sample(4,*&histo_signal_20_ossf_kin_rec_l3[0]);
    cosmesi_sample(5,*&histo_signal_40_ossf_kin_rec_l3[0]);
    cosmesi_sample(6,*&histo_signal_50_ossf_kin_rec_l3[0]);
    cosmesi_sample(7,*&histo_signal_60_ossf_kin_rec_l3[0]);
    histo_signal_50_ossf_kin_rec_l3[0]->Draw("hist");
    histo_signal_5_ossf_kin_rec_l3[0]->Draw("histsame");
    histo_signal_10_ossf_kin_rec_l3[0]->Draw("histsame");
    histo_signal_15_ossf_kin_rec_l3[0]->Draw("histsame");
    histo_signal_20_ossf_kin_rec_l3[0]->Draw("histsame");
    histo_signal_40_ossf_kin_rec_l3[0]->Draw("histsame");
    histo_signal_60_ossf_kin_rec_l3[0]->Draw("histsame");
    leg_ossf_signal_sample_pt3 = new TLegend(0.54,0.50,0.90,0.9);
    //leg_ossf_signal_sample_pt3->SetHeader("OSSF p_{T} leading lepton"); // option "C" al3ows to center the header
    leg_ossf_signal_sample_pt3->AddEntry(histo_signal_5_ossf_kin_rec_l3[0],"mN=5 GeV","l");
    leg_ossf_signal_sample_pt3->AddEntry(histo_signal_10_ossf_kin_rec_l3[0],"mN=10 GeV","l");
    leg_ossf_signal_sample_pt3->AddEntry(histo_signal_15_ossf_kin_rec_l3[0],"mN=15 GeV","l");
    leg_ossf_signal_sample_pt3->AddEntry(histo_signal_20_ossf_kin_rec_l3[0],"mN=20 GeV","l");
    leg_ossf_signal_sample_pt3->AddEntry(histo_signal_40_ossf_kin_rec_l3[0],"mN=40 GeV","l");
    leg_ossf_signal_sample_pt3->AddEntry(histo_signal_50_ossf_kin_rec_l3[0],"mN=50 GeV","l");
    leg_ossf_signal_sample_pt3->AddEntry(histo_signal_60_ossf_kin_rec_l3[0],"mN=60 GeV","l");
    leg_ossf_signal_sample_pt3->Draw();
    histo_signal_50_ossf_kin_rec_l3[0]->GetXaxis()->SetTitle("p_{T} (GeV)");
    histo_signal_50_ossf_kin_rec_l3[0]->GetYaxis()->SetTitle("Events");
    c_st_ossf_signal_sample_pt->Modified();
    c_st_ossf_signal_sample_pt->Print("PLOT/c_st_ossf_signal_sample_pt.root");
    delete c_st_ossf_signal_sample_pt;
    //////////////////////////////////////////
    
    TCanvas *c_st_ossf_signal_sample_met = new TCanvas("c_st_ossf_signal_sample_met","c_st_ossf_signal_sample_met",10,10,700,700);
    c_st_ossf_signal_sample_met->cd();
    histo_signal_50_ossf_rec[0]->SetMaximum(histo_signal_50_ossf_rec[0]-> GetBinContent(histo_signal_50_ossf_rec[0]->GetMaximumBin ()) * 2);
    cosmesi_sample(1,*&histo_signal_5_ossf_rec[0]);
    cosmesi_sample(2,*&histo_signal_10_ossf_rec[0]);
    cosmesi_sample(3,*&histo_signal_15_ossf_rec[0]);
    cosmesi_sample(4,*&histo_signal_20_ossf_rec[0]);
    cosmesi_sample(5,*&histo_signal_40_ossf_rec[0]);
    cosmesi_sample(6,*&histo_signal_50_ossf_rec[0]);
    cosmesi_sample(7,*&histo_signal_60_ossf_rec[0]);
    histo_signal_50_ossf_rec[0]->Draw("hist");
    histo_signal_5_ossf_rec[0]->Draw("histsame");
    histo_signal_10_ossf_rec[0]->Draw("histsame");
    histo_signal_15_ossf_rec[0]->Draw("histsame");
    histo_signal_20_ossf_rec[0]->Draw("histsame");
    histo_signal_40_ossf_rec[0]->Draw("histsame");
    histo_signal_60_ossf_rec[0]->Draw("histsame");
    leg_ossf_signal_sample_met = new TLegend(0.54,0.50,0.90,0.9);
    //leg_ossf_signal_sample_met->SetHeader("OSSF MET leading lemeton"); // ometion "C" al2ows to center the header
    leg_ossf_signal_sample_met->AddEntry(histo_signal_5_ossf_rec[0],"mN=5 GeV","l");
    leg_ossf_signal_sample_met->AddEntry(histo_signal_10_ossf_rec[0],"mN=10 GeV","l");
    leg_ossf_signal_sample_met->AddEntry(histo_signal_15_ossf_rec[0],"mN=15 GeV","l");
    leg_ossf_signal_sample_met->AddEntry(histo_signal_20_ossf_rec[0],"mN=20 GeV","l");
    leg_ossf_signal_sample_met->AddEntry(histo_signal_40_ossf_rec[0],"mN=40 GeV","l");
    leg_ossf_signal_sample_met->AddEntry(histo_signal_50_ossf_rec[0],"mN=50 GeV","l");
    leg_ossf_signal_sample_met->AddEntry(histo_signal_60_ossf_rec[0],"mN=60 GeV","l");
    leg_ossf_signal_sample_met->Draw();
    histo_signal_50_ossf_rec[0]->GetXaxis()->SetTitle("MET");
    histo_signal_50_ossf_rec[0]->GetYaxis()->SetTitle("Events");
    c_st_ossf_signal_sample_met->Modified();
    c_st_ossf_signal_sample_met->Print("PLOT/c_st_ossf_signal_sample_met.root");
    delete c_st_ossf_signal_sample_met;
    
    //////////////////////////////////////////
    TCanvas *c_st_ossf_signal_sample_mT = new TCanvas("c_st_ossf_signal_sample_mT","c_st_ossf_signal_sample_mT",10,10,700,700);
    c_st_ossf_signal_sample_mT->cd();
    histo_signal_50_ossf_rec[1]->SetMaximum(histo_signal_50_ossf_rec[1]-> GetBinContent(histo_signal_50_ossf_rec[1]->GetMaximumBin ()) * 2);
    cosmesi_sample(1,*&histo_signal_5_ossf_rec[1]);
    cosmesi_sample(2,*&histo_signal_10_ossf_rec[1]);
    cosmesi_sample(3,*&histo_signal_15_ossf_rec[1]);
    cosmesi_sample(4,*&histo_signal_20_ossf_rec[1]);
    cosmesi_sample(5,*&histo_signal_40_ossf_rec[1]);
    cosmesi_sample(6,*&histo_signal_50_ossf_rec[1]);
    cosmesi_sample(7,*&histo_signal_60_ossf_rec[1]);
    histo_signal_50_ossf_rec[1]->Draw("hist");
    histo_signal_5_ossf_rec[1]->Draw("histsame");
    histo_signal_10_ossf_rec[1]->Draw("histsame");
    histo_signal_15_ossf_rec[1]->Draw("histsame");
    histo_signal_20_ossf_rec[1]->Draw("histsame");
    histo_signal_40_ossf_rec[1]->Draw("histsame");
    histo_signal_60_ossf_rec[1]->Draw("histsame");
    leg_ossf_signal_sample_mT = new TLegend(0.54,0.50,0.90,0.9);
    //leg_ossf_signal_sample_mT->SetHeader("OSSF mT leading lemTon"); // omTion "C" al2ows to center the header
    leg_ossf_signal_sample_mT->AddEntry(histo_signal_5_ossf_rec[1],"mN=5 GeV","l");
    leg_ossf_signal_sample_mT->AddEntry(histo_signal_10_ossf_rec[1],"mN=10 GeV","l");
    leg_ossf_signal_sample_mT->AddEntry(histo_signal_15_ossf_rec[1],"mN=15 GeV","l");
    leg_ossf_signal_sample_mT->AddEntry(histo_signal_20_ossf_rec[1],"mN=20 GeV","l");
    leg_ossf_signal_sample_mT->AddEntry(histo_signal_40_ossf_rec[1],"mN=40 GeV","l");
    leg_ossf_signal_sample_mT->AddEntry(histo_signal_50_ossf_rec[1],"mN=50 GeV","l");
    leg_ossf_signal_sample_mT->AddEntry(histo_signal_60_ossf_rec[1],"mN=60 GeV","l");
    leg_ossf_signal_sample_mT->Draw();
    histo_signal_50_ossf_rec[1]->GetXaxis()->SetTitle("m_{T}");
    histo_signal_50_ossf_rec[1]->GetYaxis()->SetTitle("Events");
    c_st_ossf_signal_sample_mT->Modified();
    c_st_ossf_signal_sample_mT->Print("PLOT/c_st_ossf_signal_sample_mT.root");
    delete c_st_ossf_signal_sample_mT;
    
    //////////////////////////////////////
    TCanvas *c_st_ossf_signal_sample_mlll = new TCanvas("c_st_ossf_signal_sample_mlll","c_st_ossf_signal_sample_mlll",10,10,700,700);
    c_st_ossf_signal_sample_mlll->cd();
    histo_signal_50_ossf_rec[2]->SetMaximum(histo_signal_50_ossf_rec[2]-> GetBinContent(histo_signal_50_ossf_rec[2]->GetMaximumBin ()) * 2);
    cosmesi_sample(1,*&histo_signal_5_ossf_rec[2]);
    cosmesi_sample(2,*&histo_signal_10_ossf_rec[2]);
    cosmesi_sample(3,*&histo_signal_15_ossf_rec[2]);
    cosmesi_sample(4,*&histo_signal_20_ossf_rec[2]);
    cosmesi_sample(5,*&histo_signal_40_ossf_rec[2]);
    cosmesi_sample(6,*&histo_signal_50_ossf_rec[2]);
    cosmesi_sample(7,*&histo_signal_60_ossf_rec[2]);
    histo_signal_50_ossf_rec[2]->Draw("hist");
    histo_signal_5_ossf_rec[2]->Draw("histsame");
    histo_signal_10_ossf_rec[2]->Draw("histsame");
    histo_signal_15_ossf_rec[2]->Draw("histsame");
    histo_signal_20_ossf_rec[2]->Draw("histsame");
    histo_signal_40_ossf_rec[2]->Draw("histsame");
    histo_signal_60_ossf_rec[2]->Draw("histsame");
    leg_ossf_signal_sample_mlll = new TLegend(0.54,0.50,0.90,0.9);
    //leg_ossf_signal_sample_mlll->SetHeader("OSSF mlll leading lemlllon"); // omlllion "C" al2ows to center the header
    leg_ossf_signal_sample_mlll->AddEntry(histo_signal_5_ossf_rec[2],"mN=5 GeV","l");
    leg_ossf_signal_sample_mlll->AddEntry(histo_signal_10_ossf_rec[2],"mN=10 GeV","l");
    leg_ossf_signal_sample_mlll->AddEntry(histo_signal_15_ossf_rec[2],"mN=15 GeV","l");
    leg_ossf_signal_sample_mlll->AddEntry(histo_signal_20_ossf_rec[2],"mN=20 GeV","l");
    leg_ossf_signal_sample_mlll->AddEntry(histo_signal_40_ossf_rec[2],"mN=40 GeV","l");
    leg_ossf_signal_sample_mlll->AddEntry(histo_signal_50_ossf_rec[2],"mN=50 GeV","l");
    leg_ossf_signal_sample_mlll->AddEntry(histo_signal_60_ossf_rec[2],"mN=60 GeV","l");
    leg_ossf_signal_sample_mlll->Draw();
    histo_signal_50_ossf_rec[2]->GetXaxis()->SetTitle("m_{lll} (GeV/c)");
    histo_signal_50_ossf_rec[2]->GetYaxis()->SetTitle("Events");
    c_st_ossf_signal_sample_mlll->Modified();
    c_st_ossf_signal_sample_mlll->Print("PLOT/c_st_ossf_signal_sample_mlll.root");
    delete c_st_ossf_signal_sample_mlll;
    ///////////////////////////
    TCanvas *c_st_ossf_signal_sample_mll = new TCanvas("c_st_ossf_signal_sample_mll","c_st_ossf_signal_sample_mll",10,10,700,700);
    c_st_ossf_signal_sample_mll->cd();
    histo_signal_50_ossf_rec[3]->SetMaximum(histo_signal_50_ossf_rec[3]-> GetBinContent(histo_signal_50_ossf_rec[3]->GetMaximumBin ()) * 2);
    cosmesi_sample(1,*&histo_signal_5_ossf_rec[3]);
    cosmesi_sample(2,*&histo_signal_10_ossf_rec[3]);
    cosmesi_sample(3,*&histo_signal_15_ossf_rec[3]);
    cosmesi_sample(4,*&histo_signal_20_ossf_rec[3]);
    cosmesi_sample(5,*&histo_signal_40_ossf_rec[3]);
    cosmesi_sample(6,*&histo_signal_50_ossf_rec[3]);
    cosmesi_sample(7,*&histo_signal_60_ossf_rec[3]);
    histo_signal_50_ossf_rec[3]->Draw("hist");
    histo_signal_5_ossf_rec[3]->Draw("histsame");
    histo_signal_10_ossf_rec[3]->Draw("histsame");
    histo_signal_15_ossf_rec[3]->Draw("histsame");
    histo_signal_20_ossf_rec[3]->Draw("histsame");
    histo_signal_40_ossf_rec[3]->Draw("histsame");
    histo_signal_60_ossf_rec[3]->Draw("histsame");
    leg_ossf_signal_sample_mll = new TLegend(0.54,0.50,0.90,0.9);
    //leg_ossf_signal_sample_mll->SetHeader("OSSF mll leading lemllon"); // omllion "C" al2ows to center the header
    leg_ossf_signal_sample_mll->AddEntry(histo_signal_5_ossf_rec[3],"mN=5 GeV","l");
    leg_ossf_signal_sample_mll->AddEntry(histo_signal_10_ossf_rec[3],"mN=10 GeV","l");
    leg_ossf_signal_sample_mll->AddEntry(histo_signal_15_ossf_rec[3],"mN=15 GeV","l");
    leg_ossf_signal_sample_mll->AddEntry(histo_signal_20_ossf_rec[3],"mN=20 GeV","l");
    leg_ossf_signal_sample_mll->AddEntry(histo_signal_40_ossf_rec[3],"mN=40 GeV","l");
    leg_ossf_signal_sample_mll->AddEntry(histo_signal_50_ossf_rec[3],"mN=50 GeV","l");
    leg_ossf_signal_sample_mll->AddEntry(histo_signal_60_ossf_rec[3],"mN=60 GeV","l");
    leg_ossf_signal_sample_mll->Draw();
    histo_signal_50_ossf_rec[3]->GetXaxis()->SetTitle("m_{ll} (GeV/c)");
    histo_signal_50_ossf_rec[3]->GetYaxis()->SetTitle("Events");
    c_st_ossf_signal_sample_mll->Modified();
    c_st_ossf_signal_sample_mll->Print("PLOT/c_st_ossf_signal_sample_mll.root");
    delete c_st_ossf_signal_sample_mll;
    /////////////////////////////////////
    TCanvas *c_st_ossf_signal_sample_mll_pair = new TCanvas("c_st_ossf_signal_sample_mll_pair","c_st_ossf_signal_sample_mll_pair",10,10,700,700);
    c_st_ossf_signal_sample_mll_pair->cd();
    histo_signal_50_ossf_rec[11]->SetMaximum(histo_signal_50_ossf_rec[11]-> GetBinContent(histo_signal_50_ossf_rec[11]->GetMaximumBin ()) * 2);
    cosmesi_sample(1,*&histo_signal_5_ossf_rec[11]);
    cosmesi_sample(2,*&histo_signal_10_ossf_rec[11]);
    cosmesi_sample(3,*&histo_signal_15_ossf_rec[11]);
    cosmesi_sample(4,*&histo_signal_20_ossf_rec[11]);
    cosmesi_sample(5,*&histo_signal_40_ossf_rec[11]);
    cosmesi_sample(6,*&histo_signal_50_ossf_rec[11]);
    cosmesi_sample(7,*&histo_signal_60_ossf_rec[11]);
    histo_signal_50_ossf_rec[11]->Draw("hist");
    histo_signal_5_ossf_rec[11]->Draw("histsame");
    histo_signal_10_ossf_rec[11]->Draw("histsame");
    histo_signal_15_ossf_rec[11]->Draw("histsame");
    histo_signal_20_ossf_rec[11]->Draw("histsame");
    histo_signal_40_ossf_rec[11]->Draw("histsame");
    histo_signal_60_ossf_rec[11]->Draw("histsame");
    leg_ossf_signal_sample_mll_pair = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_signal_sample_mll_pair->SetHeader("OSSF mll_pair leading lemll_pairon"); // omll_pairion "C" al2ows to center the header
    leg_ossf_signal_sample_mll_pair->AddEntry(histo_signal_5_ossf_rec[11],"mN=5 GeV","l");
    leg_ossf_signal_sample_mll_pair->AddEntry(histo_signal_10_ossf_rec[11],"mN=10 GeV","l");
    leg_ossf_signal_sample_mll_pair->AddEntry(histo_signal_15_ossf_rec[11],"mN=15 GeV","l");
    leg_ossf_signal_sample_mll_pair->AddEntry(histo_signal_20_ossf_rec[11],"mN=20 GeV","l");
    leg_ossf_signal_sample_mll_pair->AddEntry(histo_signal_40_ossf_rec[11],"mN=40 GeV","l");
    leg_ossf_signal_sample_mll_pair->AddEntry(histo_signal_50_ossf_rec[11],"mN=50 GeV","l");
    leg_ossf_signal_sample_mll_pair->AddEntry(histo_signal_60_ossf_rec[11],"mN=60 GeV","l");
    leg_ossf_signal_sample_mll_pair->Draw();
    histo_signal_50_ossf_rec[11]->GetXaxis()->SetTitle("m_{llpair} (GeV/c)");
    histo_signal_50_ossf_rec[11]->GetYaxis()->SetTitle("Events");
    c_st_ossf_signal_sample_mll_pair->Modified();
    c_st_ossf_signal_sample_mll_pair->Print("PLOT/c_st_ossf_signal_sample_mll_pair.root");
    delete c_st_ossf_signal_sample_mll_pair;
    
    //************************************** canvas just signal *******************************
    TLegend *leg_n_ossf_signal_sample_pt1,*leg_n_ossf_signal_sample_pt2,*leg_n_ossf_signal_sample_pt3, *leg_n_ossf_signal_sample_met,*leg_n_ossf_signal_sample_mT,*leg_n_ossf_signal_sample_mlll,*leg_n_ossf_signal_sample_mll,*leg_n_ossf_signal_sample_mll_pair,  *leg_n_ossf_signal_sample_nJet, *leg_n_ossf_signal_sample_nbJet, *leg_n_ossf_signal_sample_HT, *leg_n_ossf_signal_sample_jetPt, *leg_n_ossf_signal_sample_jetEta, *leg_n_ossf_signal_sample_jetPhi, *leg_n_ossf_signal_sample_jetFlavour, *leg_n_ossf_signal_sample_flavor;
    
    TCanvas *c_st_n_ossf_signal_sample_pt = new TCanvas("c_st_n_ossf_signal_sample_pt","c_st_n_ossf_signal_sample_pt",10,10,700,700);
    c_st_n_ossf_signal_sample_pt->Divide(3,1);
    c_st_n_ossf_signal_sample_pt->cd(1);
    histo_signal_50_n_ossf_kin_rec_l1[0]->SetMaximum(histo_signal_5_n_ossf_kin_rec_l1[0]-> GetBinContent(histo_signal_5_n_ossf_kin_rec_l1[0]->GetMaximumBin ()) * 2);
    cosmesi_sample(1,*&histo_signal_5_n_ossf_kin_rec_l1[0]);
    cosmesi_sample(2,*&histo_signal_10_n_ossf_kin_rec_l1[0]);
    cosmesi_sample(3,*&histo_signal_15_n_ossf_kin_rec_l1[0]);
    cosmesi_sample(4,*&histo_signal_20_n_ossf_kin_rec_l1[0]);
    cosmesi_sample(5,*&histo_signal_40_n_ossf_kin_rec_l1[0]);
    cosmesi_sample(6,*&histo_signal_50_n_ossf_kin_rec_l1[0]);
    cosmesi_sample(7,*&histo_signal_60_n_ossf_kin_rec_l1[0]);
    histo_signal_50_n_ossf_kin_rec_l1[0]->Draw("hist");
    histo_signal_5_n_ossf_kin_rec_l1[0]->Draw("histsame");
    histo_signal_10_n_ossf_kin_rec_l1[0]->Draw("histsame");
    histo_signal_15_n_ossf_kin_rec_l1[0]->Draw("histsame");
    histo_signal_20_n_ossf_kin_rec_l1[0]->Draw("histsame");
    histo_signal_40_n_ossf_kin_rec_l1[0]->Draw("histsame");
    histo_signal_60_n_ossf_kin_rec_l1[0]->Draw("histsame");
    leg_n_ossf_signal_sample_pt1 = new TLegend(0.54,0.50,0.90,0.9);
    //leg_n_ossf_signal_sample_pt1->SetHeader("n_ossf p_{T} leading lepton"); // option "C" al2ows to center the header
    leg_n_ossf_signal_sample_pt1->AddEntry(histo_signal_5_n_ossf_kin_rec_l1[0],"mN=5 GeV","l");
    leg_n_ossf_signal_sample_pt1->AddEntry(histo_signal_10_n_ossf_kin_rec_l1[0],"mN=10 GeV","l");
    leg_n_ossf_signal_sample_pt1->AddEntry(histo_signal_15_n_ossf_kin_rec_l1[0],"mN=15 GeV","l");
    leg_n_ossf_signal_sample_pt1->AddEntry(histo_signal_20_n_ossf_kin_rec_l1[0],"mN=20 GeV","l");
    leg_n_ossf_signal_sample_pt1->AddEntry(histo_signal_40_n_ossf_kin_rec_l1[0],"mN=40 GeV","l");
    leg_n_ossf_signal_sample_pt1->AddEntry(histo_signal_50_n_ossf_kin_rec_l1[0],"mN=50 GeV","l");
    leg_n_ossf_signal_sample_pt1->AddEntry(histo_signal_60_n_ossf_kin_rec_l1[0],"mN=60 GeV","l");
    leg_n_ossf_signal_sample_pt1->Draw();
    histo_signal_50_n_ossf_kin_rec_l1[0]->GetXaxis()->SetTitle("p_{T} (GeV)");
    histo_signal_50_n_ossf_kin_rec_l1[0]->GetYaxis()->SetTitle("Events");
    
    c_st_n_ossf_signal_sample_pt->cd(2);
    histo_signal_50_n_ossf_kin_rec_l2[0]->SetMaximum(histo_signal_5_n_ossf_kin_rec_l2[0]-> GetBinContent(histo_signal_5_n_ossf_kin_rec_l2[0]->GetMaximumBin ()) * 2);
    cosmesi_sample(1,*&histo_signal_5_n_ossf_kin_rec_l2[0]);
    cosmesi_sample(2,*&histo_signal_10_n_ossf_kin_rec_l2[0]);
    cosmesi_sample(3,*&histo_signal_15_n_ossf_kin_rec_l2[0]);
    cosmesi_sample(4,*&histo_signal_20_n_ossf_kin_rec_l2[0]);
    cosmesi_sample(5,*&histo_signal_40_n_ossf_kin_rec_l2[0]);
    cosmesi_sample(6,*&histo_signal_50_n_ossf_kin_rec_l2[0]);
    cosmesi_sample(7,*&histo_signal_60_n_ossf_kin_rec_l2[0]);
    histo_signal_50_n_ossf_kin_rec_l2[0]->Draw("hist");
    histo_signal_5_n_ossf_kin_rec_l2[0]->Draw("histsame");
    histo_signal_10_n_ossf_kin_rec_l2[0]->Draw("histsame");
    histo_signal_15_n_ossf_kin_rec_l2[0]->Draw("histsame");
    histo_signal_20_n_ossf_kin_rec_l2[0]->Draw("histsame");
    histo_signal_40_n_ossf_kin_rec_l2[0]->Draw("histsame");
    histo_signal_60_n_ossf_kin_rec_l2[0]->Draw("histsame");
    leg_n_ossf_signal_sample_pt2 = new TLegend(0.54,0.50,0.90,0.9);
    //leg_n_ossf_signal_sample_pt2->SetHeader("n_ossf p_{T} leading lepton"); // option "C" al2ows to center the header
    leg_n_ossf_signal_sample_pt2->AddEntry(histo_signal_5_n_ossf_kin_rec_l2[0],"mN=5 GeV","l");
    leg_n_ossf_signal_sample_pt2->AddEntry(histo_signal_10_n_ossf_kin_rec_l2[0],"mN=10 GeV","l");
    leg_n_ossf_signal_sample_pt2->AddEntry(histo_signal_15_n_ossf_kin_rec_l2[0],"mN=15 GeV","l");
    leg_n_ossf_signal_sample_pt2->AddEntry(histo_signal_20_n_ossf_kin_rec_l2[0],"mN=20 GeV","l");
    leg_n_ossf_signal_sample_pt2->AddEntry(histo_signal_40_n_ossf_kin_rec_l2[0],"mN=40 GeV","l");
    leg_n_ossf_signal_sample_pt2->AddEntry(histo_signal_50_n_ossf_kin_rec_l2[0],"mN=50 GeV","l");
    leg_n_ossf_signal_sample_pt2->AddEntry(histo_signal_60_n_ossf_kin_rec_l2[0],"mN=60 GeV","l");
    leg_n_ossf_signal_sample_pt2->Draw();
    histo_signal_50_n_ossf_kin_rec_l2[0]->GetXaxis()->SetTitle("p_{T} (GeV)");
    histo_signal_50_n_ossf_kin_rec_l2[0]->GetYaxis()->SetTitle("Events");
    
    c_st_n_ossf_signal_sample_pt->cd(3);
    histo_signal_50_n_ossf_kin_rec_l3[0]->SetMaximum(histo_signal_5_n_ossf_kin_rec_l3[0]-> GetBinContent(histo_signal_5_n_ossf_kin_rec_l3[0]->GetMaximumBin ()) * 2);
    cosmesi_sample(1,*&histo_signal_5_n_ossf_kin_rec_l3[0]);
    cosmesi_sample(2,*&histo_signal_10_n_ossf_kin_rec_l3[0]);
    cosmesi_sample(3,*&histo_signal_15_n_ossf_kin_rec_l3[0]);
    cosmesi_sample(4,*&histo_signal_20_n_ossf_kin_rec_l3[0]);
    cosmesi_sample(5,*&histo_signal_40_n_ossf_kin_rec_l3[0]);
    cosmesi_sample(6,*&histo_signal_50_n_ossf_kin_rec_l3[0]);
    cosmesi_sample(7,*&histo_signal_60_n_ossf_kin_rec_l3[0]);
    histo_signal_50_n_ossf_kin_rec_l3[0]->Draw("hist");
    histo_signal_5_n_ossf_kin_rec_l3[0]->Draw("histsame");
    histo_signal_10_n_ossf_kin_rec_l3[0]->Draw("histsame");
    histo_signal_15_n_ossf_kin_rec_l3[0]->Draw("histsame");
    histo_signal_20_n_ossf_kin_rec_l3[0]->Draw("histsame");
    histo_signal_40_n_ossf_kin_rec_l3[0]->Draw("histsame");
    histo_signal_60_n_ossf_kin_rec_l3[0]->Draw("histsame");
    leg_n_ossf_signal_sample_pt3 = new TLegend(0.54,0.50,0.90,0.9);
    //leg_n_ossf_signal_sample_pt3->SetHeader("n_ossf p_{T} leading lepton"); // option "C" al3ows to center the header
    leg_n_ossf_signal_sample_pt3->AddEntry(histo_signal_5_n_ossf_kin_rec_l3[0],"mN=5 GeV","l");
    leg_n_ossf_signal_sample_pt3->AddEntry(histo_signal_10_n_ossf_kin_rec_l3[0],"mN=10 GeV","l");
    leg_n_ossf_signal_sample_pt3->AddEntry(histo_signal_15_n_ossf_kin_rec_l3[0],"mN=15 GeV","l");
    leg_n_ossf_signal_sample_pt3->AddEntry(histo_signal_20_n_ossf_kin_rec_l3[0],"mN=20 GeV","l");
    leg_n_ossf_signal_sample_pt3->AddEntry(histo_signal_40_n_ossf_kin_rec_l3[0],"mN=40 GeV","l");
    leg_n_ossf_signal_sample_pt3->AddEntry(histo_signal_50_n_ossf_kin_rec_l3[0],"mN=50 GeV","l");
    leg_n_ossf_signal_sample_pt3->AddEntry(histo_signal_60_n_ossf_kin_rec_l3[0],"mN=60 GeV","l");
    leg_n_ossf_signal_sample_pt3->Draw();
    histo_signal_50_n_ossf_kin_rec_l3[0]->GetXaxis()->SetTitle("p_{T} (GeV)");
    histo_signal_50_n_ossf_kin_rec_l3[0]->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_signal_sample_pt->Modified();
    c_st_n_ossf_signal_sample_pt->Print("PLOT/c_st_n_ossf_signal_sample_pt.root");
    delete c_st_n_ossf_signal_sample_pt;
    //////////////////////////////////////////
    
    TCanvas *c_st_n_ossf_signal_sample_met = new TCanvas("c_st_n_ossf_signal_sample_met","c_st_n_ossf_signal_sample_met",10,10,700,700);
    c_st_n_ossf_signal_sample_met->cd();
    histo_signal_50_n_ossf_rec[0]->SetMaximum(histo_signal_5_n_ossf_rec[0]-> GetBinContent(histo_signal_5_n_ossf_rec[0]->GetMaximumBin ()) * 2);
    cosmesi_sample(1,*&histo_signal_5_n_ossf_rec[0]);
    cosmesi_sample(2,*&histo_signal_10_n_ossf_rec[0]);
    cosmesi_sample(3,*&histo_signal_15_n_ossf_rec[0]);
    cosmesi_sample(4,*&histo_signal_20_n_ossf_rec[0]);
    cosmesi_sample(5,*&histo_signal_40_n_ossf_rec[0]);
    cosmesi_sample(6,*&histo_signal_50_n_ossf_rec[0]);
    cosmesi_sample(7,*&histo_signal_60_n_ossf_rec[0]);
    histo_signal_50_n_ossf_rec[0]->Draw("hist");
    histo_signal_5_n_ossf_rec[0]->Draw("histsame");
    histo_signal_10_n_ossf_rec[0]->Draw("histsame");
    histo_signal_15_n_ossf_rec[0]->Draw("histsame");
    histo_signal_20_n_ossf_rec[0]->Draw("histsame");
    histo_signal_40_n_ossf_rec[0]->Draw("histsame");
    histo_signal_60_n_ossf_rec[0]->Draw("histsame");
    leg_n_ossf_signal_sample_met = new TLegend(0.54,0.50,0.90,0.9);
    //leg_n_ossf_signal_sample_met->SetHeader("n_ossf MET leading lemeton"); // ometion "C" al2ows to center the header
    leg_n_ossf_signal_sample_met->AddEntry(histo_signal_5_n_ossf_rec[0],"mN=5 GeV","l");
    leg_n_ossf_signal_sample_met->AddEntry(histo_signal_10_n_ossf_rec[0],"mN=10 GeV","l");
    leg_n_ossf_signal_sample_met->AddEntry(histo_signal_15_n_ossf_rec[0],"mN=15 GeV","l");
    leg_n_ossf_signal_sample_met->AddEntry(histo_signal_20_n_ossf_rec[0],"mN=20 GeV","l");
    leg_n_ossf_signal_sample_met->AddEntry(histo_signal_40_n_ossf_rec[0],"mN=40 GeV","l");
    leg_n_ossf_signal_sample_met->AddEntry(histo_signal_50_n_ossf_rec[0],"mN=50 GeV","l");
    leg_n_ossf_signal_sample_met->AddEntry(histo_signal_60_n_ossf_rec[0],"mN=60 GeV","l");
    leg_n_ossf_signal_sample_met->Draw();
    histo_signal_50_n_ossf_rec[0]->GetXaxis()->SetTitle("MET");
    histo_signal_50_n_ossf_rec[0]->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_signal_sample_met->Modified();
    c_st_n_ossf_signal_sample_met->Print("PLOT/c_st_n_ossf_signal_sample_met.root");
    delete c_st_n_ossf_signal_sample_met;
    
    //////////////////////////////////////////
    TCanvas *c_st_n_ossf_signal_sample_mT = new TCanvas("c_st_n_ossf_signal_sample_mT","c_st_n_ossf_signal_sample_mT",10,10,700,700);
    c_st_n_ossf_signal_sample_mT->cd();
    histo_signal_50_n_ossf_rec[1]->SetMaximum(histo_signal_5_n_ossf_rec[1]-> GetBinContent(histo_signal_5_n_ossf_rec[1]->GetMaximumBin ()) * 2);
    cosmesi_sample(1,*&histo_signal_5_n_ossf_rec[1]);
    cosmesi_sample(2,*&histo_signal_10_n_ossf_rec[1]);
    cosmesi_sample(3,*&histo_signal_15_n_ossf_rec[1]);
    cosmesi_sample(4,*&histo_signal_20_n_ossf_rec[1]);
    cosmesi_sample(5,*&histo_signal_40_n_ossf_rec[1]);
    cosmesi_sample(6,*&histo_signal_50_n_ossf_rec[1]);
    cosmesi_sample(7,*&histo_signal_60_n_ossf_rec[1]);
    histo_signal_50_n_ossf_rec[1]->Draw("hist");
    histo_signal_5_n_ossf_rec[1]->Draw("histsame");
    histo_signal_10_n_ossf_rec[1]->Draw("histsame");
    histo_signal_15_n_ossf_rec[1]->Draw("histsame");
    histo_signal_20_n_ossf_rec[1]->Draw("histsame");
    histo_signal_40_n_ossf_rec[1]->Draw("histsame");
    histo_signal_60_n_ossf_rec[1]->Draw("histsame");
    leg_n_ossf_signal_sample_mT = new TLegend(0.54,0.50,0.90,0.9);
    //leg_n_ossf_signal_sample_mT->SetHeader("n_ossf mT leading lemTon"); // omTion "C" al2ows to center the header
    leg_n_ossf_signal_sample_mT->AddEntry(histo_signal_5_n_ossf_rec[1],"mN=5 GeV","l");
    leg_n_ossf_signal_sample_mT->AddEntry(histo_signal_10_n_ossf_rec[1],"mN=10 GeV","l");
    leg_n_ossf_signal_sample_mT->AddEntry(histo_signal_15_n_ossf_rec[1],"mN=15 GeV","l");
    leg_n_ossf_signal_sample_mT->AddEntry(histo_signal_20_n_ossf_rec[1],"mN=20 GeV","l");
    leg_n_ossf_signal_sample_mT->AddEntry(histo_signal_40_n_ossf_rec[1],"mN=40 GeV","l");
    leg_n_ossf_signal_sample_mT->AddEntry(histo_signal_50_n_ossf_rec[1],"mN=50 GeV","l");
    leg_n_ossf_signal_sample_mT->AddEntry(histo_signal_60_n_ossf_rec[1],"mN=60 GeV","l");
    leg_n_ossf_signal_sample_mT->Draw();
    histo_signal_50_n_ossf_rec[1]->GetXaxis()->SetTitle("m_{T}");
    histo_signal_50_n_ossf_rec[1]->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_signal_sample_mT->Modified();
    c_st_n_ossf_signal_sample_mT->Print("PLOT/c_st_n_ossf_signal_sample_mT.root");
    delete c_st_n_ossf_signal_sample_mT;
    
    //////////////////////////////////////
    TCanvas *c_st_n_ossf_signal_sample_mlll = new TCanvas("c_st_n_ossf_signal_sample_mlll","c_st_n_ossf_signal_sample_mlll",10,10,700,700);
    c_st_n_ossf_signal_sample_mlll->cd();
    histo_signal_50_n_ossf_rec[2]->SetMaximum(histo_signal_5_n_ossf_rec[2]-> GetBinContent(histo_signal_5_n_ossf_rec[2]->GetMaximumBin ()) * 2);
    cosmesi_sample(1,*&histo_signal_5_n_ossf_rec[2]);
    cosmesi_sample(2,*&histo_signal_10_n_ossf_rec[2]);
    cosmesi_sample(3,*&histo_signal_15_n_ossf_rec[2]);
    cosmesi_sample(4,*&histo_signal_20_n_ossf_rec[2]);
    cosmesi_sample(5,*&histo_signal_40_n_ossf_rec[2]);
    cosmesi_sample(6,*&histo_signal_50_n_ossf_rec[2]);
    cosmesi_sample(7,*&histo_signal_60_n_ossf_rec[2]);
    histo_signal_50_n_ossf_rec[2]->Draw("hist");
    histo_signal_5_n_ossf_rec[2]->Draw("histsame");
    histo_signal_10_n_ossf_rec[2]->Draw("histsame");
    histo_signal_15_n_ossf_rec[2]->Draw("histsame");
    histo_signal_20_n_ossf_rec[2]->Draw("histsame");
    histo_signal_40_n_ossf_rec[2]->Draw("histsame");
    histo_signal_60_n_ossf_rec[2]->Draw("histsame");
    leg_n_ossf_signal_sample_mlll = new TLegend(0.54,0.50,0.90,0.9);
    //leg_n_ossf_signal_sample_mlll->SetHeader("n_ossf mlll leading lemlllon"); // omlllion "C" al2ows to center the header
    leg_n_ossf_signal_sample_mlll->AddEntry(histo_signal_5_n_ossf_rec[2],"mN=5 GeV","l");
    leg_n_ossf_signal_sample_mlll->AddEntry(histo_signal_10_n_ossf_rec[2],"mN=10 GeV","l");
    leg_n_ossf_signal_sample_mlll->AddEntry(histo_signal_15_n_ossf_rec[2],"mN=15 GeV","l");
    leg_n_ossf_signal_sample_mlll->AddEntry(histo_signal_20_n_ossf_rec[2],"mN=20 GeV","l");
    leg_n_ossf_signal_sample_mlll->AddEntry(histo_signal_40_n_ossf_rec[2],"mN=40 GeV","l");
    leg_n_ossf_signal_sample_mlll->AddEntry(histo_signal_50_n_ossf_rec[2],"mN=50 GeV","l");
    leg_n_ossf_signal_sample_mlll->AddEntry(histo_signal_60_n_ossf_rec[2],"mN=60 GeV","l");
    leg_n_ossf_signal_sample_mlll->Draw();
    histo_signal_50_n_ossf_rec[2]->GetXaxis()->SetTitle("m_{lll} (GeV/c)");
    histo_signal_50_n_ossf_rec[2]->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_signal_sample_mlll->Modified();
    c_st_n_ossf_signal_sample_mlll->Print("PLOT/c_st_n_ossf_signal_sample_mlll.root");
    delete c_st_n_ossf_signal_sample_mlll;
    ///////////////////////////
    TCanvas *c_st_n_ossf_signal_sample_mll = new TCanvas("c_st_n_ossf_signal_sample_mll","c_st_n_ossf_signal_sample_mll",10,10,700,700);
    c_st_n_ossf_signal_sample_mll->cd();
    histo_signal_50_n_ossf_rec[3]->SetMaximum(histo_signal_5_n_ossf_rec[3]-> GetBinContent(histo_signal_5_n_ossf_rec[3]->GetMaximumBin ()) * 2);
    cosmesi_sample(1,*&histo_signal_5_n_ossf_rec[3]);
    cosmesi_sample(2,*&histo_signal_10_n_ossf_rec[3]);
    cosmesi_sample(3,*&histo_signal_15_n_ossf_rec[3]);
    cosmesi_sample(4,*&histo_signal_20_n_ossf_rec[3]);
    cosmesi_sample(5,*&histo_signal_40_n_ossf_rec[3]);
    cosmesi_sample(6,*&histo_signal_50_n_ossf_rec[3]);
    cosmesi_sample(7,*&histo_signal_60_n_ossf_rec[3]);
    histo_signal_50_n_ossf_rec[3]->Draw("hist");
    histo_signal_5_n_ossf_rec[3]->Draw("histsame");
    histo_signal_10_n_ossf_rec[3]->Draw("histsame");
    histo_signal_15_n_ossf_rec[3]->Draw("histsame");
    histo_signal_20_n_ossf_rec[3]->Draw("histsame");
    histo_signal_40_n_ossf_rec[3]->Draw("histsame");
    histo_signal_60_n_ossf_rec[3]->Draw("histsame");
    leg_n_ossf_signal_sample_mll = new TLegend(0.54,0.50,0.90,0.9);
    //leg_n_ossf_signal_sample_mll->SetHeader("n_ossf mll leading lemllon"); // omllion "C" al2ows to center the header
    leg_n_ossf_signal_sample_mll->AddEntry(histo_signal_5_n_ossf_rec[3],"mN=5 GeV","l");
    leg_n_ossf_signal_sample_mll->AddEntry(histo_signal_10_n_ossf_rec[3],"mN=10 GeV","l");
    leg_n_ossf_signal_sample_mll->AddEntry(histo_signal_15_n_ossf_rec[3],"mN=15 GeV","l");
    leg_n_ossf_signal_sample_mll->AddEntry(histo_signal_20_n_ossf_rec[3],"mN=20 GeV","l");
    leg_n_ossf_signal_sample_mll->AddEntry(histo_signal_40_n_ossf_rec[3],"mN=40 GeV","l");
    leg_n_ossf_signal_sample_mll->AddEntry(histo_signal_50_n_ossf_rec[3],"mN=50 GeV","l");
    leg_n_ossf_signal_sample_mll->AddEntry(histo_signal_60_n_ossf_rec[3],"mN=60 GeV","l");
    leg_n_ossf_signal_sample_mll->Draw();
    histo_signal_50_n_ossf_rec[3]->GetXaxis()->SetTitle("m_{ll} (GeV/c)");
    histo_signal_50_n_ossf_rec[3]->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_signal_sample_mll->Modified();
    c_st_n_ossf_signal_sample_mll->Print("PLOT/c_st_n_ossf_signal_sample_mll.root");
    delete c_st_n_ossf_signal_sample_mll;
    /////////////////////////////////////
    TCanvas *c_st_n_ossf_signal_sample_mll_pair = new TCanvas("c_st_n_ossf_signal_sample_mll_pair","c_st_n_ossf_signal_sample_mll_pair",10,10,700,700);
    c_st_n_ossf_signal_sample_mll_pair->cd();
    histo_signal_50_n_ossf_rec[11]->SetMaximum(histo_signal_5_n_ossf_rec[11]-> GetBinContent(histo_signal_5_n_ossf_rec[11]->GetMaximumBin ()) * 2);
    cosmesi_sample(1,*&histo_signal_5_n_ossf_rec[11]);
    cosmesi_sample(2,*&histo_signal_10_n_ossf_rec[11]);
    cosmesi_sample(3,*&histo_signal_15_n_ossf_rec[11]);
    cosmesi_sample(4,*&histo_signal_20_n_ossf_rec[11]);
    cosmesi_sample(5,*&histo_signal_40_n_ossf_rec[11]);
    cosmesi_sample(6,*&histo_signal_50_n_ossf_rec[11]);
    cosmesi_sample(7,*&histo_signal_60_n_ossf_rec[11]);
    histo_signal_50_n_ossf_rec[11]->Draw("hist");
    histo_signal_5_n_ossf_rec[11]->Draw("histsame");
    histo_signal_10_n_ossf_rec[11]->Draw("histsame");
    histo_signal_15_n_ossf_rec[11]->Draw("histsame");
    histo_signal_20_n_ossf_rec[11]->Draw("histsame");
    histo_signal_40_n_ossf_rec[11]->Draw("histsame");
    histo_signal_60_n_ossf_rec[11]->Draw("histsame");
    leg_n_ossf_signal_sample_mll_pair = new TLegend(0.54,0.50,0.90,0.9);
    //leg_n_ossf_signal_sample_mll_pair->SetHeader("n_ossf mll_pair leading lemll_pairon"); // omll_pairion "C" al2ows to center the header
    leg_n_ossf_signal_sample_mll_pair->AddEntry(histo_signal_5_n_ossf_rec[11],"mN=5 GeV","l");
    leg_n_ossf_signal_sample_mll_pair->AddEntry(histo_signal_10_n_ossf_rec[11],"mN=10 GeV","l");
    leg_n_ossf_signal_sample_mll_pair->AddEntry(histo_signal_15_n_ossf_rec[11],"mN=15 GeV","l");
    leg_n_ossf_signal_sample_mll_pair->AddEntry(histo_signal_20_n_ossf_rec[11],"mN=20 GeV","l");
    leg_n_ossf_signal_sample_mll_pair->AddEntry(histo_signal_40_n_ossf_rec[11],"mN=40 GeV","l");
    leg_n_ossf_signal_sample_mll_pair->AddEntry(histo_signal_50_n_ossf_rec[11],"mN=50 GeV","l");
    leg_n_ossf_signal_sample_mll_pair->AddEntry(histo_signal_60_n_ossf_rec[11],"mN=60 GeV","l");
    leg_n_ossf_signal_sample_mll_pair->Draw();
    histo_signal_50_n_ossf_rec[11]->GetXaxis()->SetTitle("m_{llpair} (GeV/c)");
    histo_signal_50_n_ossf_rec[11]->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_signal_sample_mll_pair->Modified();
    c_st_n_ossf_signal_sample_mll_pair->Print("PLOT/c_st_n_ossf_signal_sample_mll_pair.root");
    delete c_st_n_ossf_signal_sample_mll_pair;
    
    
    
    
    
    
    TLegend *leg_ossf_pt1,*leg_ossf_pt2,*leg_ossf_pt3,*leg_ossf_pt1_gen,*leg_ossf_pt2_gen,*leg_ossf_pt3_gen, *leg_ossf_met,*leg_ossf_mT,*leg_ossf_mlll,*leg_ossf_mll,*leg_ossf_mll_pair, *leg_ossf_met_gen,*leg_ossf_mT_gen,*leg_ossf_mlll_gen,*leg_ossf_mll_gen, *leg_ossf_mll_pair_gen,
    *leg_ossf_nJet, *leg_ossf_nbJet, *leg_ossf_HT, *leg_ossf_jetPt, *leg_ossf_jetEta, *leg_ossf_jetPhi, *leg_ossf_jetFlavour, *leg_ossf_flavor;
    
    
    
    TCanvas *c_st_ossf_pt = new TCanvas("c_st_ossf_pt","c_st_ossf_pt",10,10,700,700);
    c_st_ossf_pt->Divide(3,2);
    c_st_ossf_pt->cd(1);
    hs_ossf_rec_pt_l1->SetMaximum(hs_ossf_rec_pt_l1->GetMaximum()*1.2);
    if (histo_signal_50_ossf_kin_rec_l1[0]-> GetBinContent(histo_signal_50_ossf_kin_rec_l1[0]->GetMaximumBin ()) > hs_ossf_rec_pt_l1-> GetMaximum()){
        hs_ossf_rec_pt_l1->SetMaximum(histo_signal_50_ossf_kin_rec_l1[0]-> GetBinContent(histo_signal_50_ossf_kin_rec_l1[0]->GetMaximumBin ()) * 2);
    }
    hs_ossf_rec_pt_l1->Draw("hist");
    histo_signal_50_ossf_kin_rec_l1[0]->SetLineColor(1);
    histo_signal_50_ossf_kin_rec_l1[0]->SetMarkerStyle(21);
    histo_signal_50_ossf_kin_rec_l1[0]->SetMarkerColor(1);
    histo_signal_50_ossf_kin_rec_l1[0]->Draw("histsame");
    histo_signal_20_ossf_kin_rec_l1[0]->SetLineColor(1);
    histo_signal_20_ossf_kin_rec_l1[0]->SetLineStyle(7);
    histo_signal_20_ossf_kin_rec_l1[0]->SetMarkerColor(1);
    histo_signal_20_ossf_kin_rec_l1[0]->Draw("histsame");
    histo_signal_5_ossf_kin_rec_l1[0]->SetLineStyle(3);
    histo_signal_5_ossf_kin_rec_l1[0]->SetMarkerColor(1);
    histo_signal_5_ossf_kin_rec_l1[0]->Draw("histsame");
    leg_ossf_pt1 = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_pt1->SetHeader("OSSF p_{T} leading lepton"); // option "C" al2ows to center the header
    leg_ossf_pt1->AddEntry(histo_dy2_ossf_kin_rec_l1[0],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_pt1->AddEntry(histo_tt_ossf_kin_rec_l1[0],"ttbar","f");
    leg_ossf_pt1->AddEntry(histo_wg_ossf_kin_rec_l1[0],"W#gamma","f");
    leg_ossf_pt1->AddEntry(histo_wz_ossf_kin_rec_l1[0],"WZ","f");
    leg_ossf_pt1->AddEntry(histo_signal_5_ossf_kin_rec_l1[0],"MN = 5 GeV","l");
    leg_ossf_pt1->AddEntry(histo_signal_20_ossf_kin_rec_l1[0],"MN = 20 GeV","l");
    leg_ossf_pt1->AddEntry(histo_signal_50_ossf_kin_rec_l1[0],"MN = 50 GeV","l");
    leg_ossf_pt1->Draw();
    hs_ossf_rec_pt_l1->GetXaxis()->SetTitle("p_{T} (GeV)");
    hs_ossf_rec_pt_l1->GetYaxis()->SetTitle("Events");
    c_st_ossf_pt->cd(2);
    hs_ossf_rec_pt_l2->SetMaximum(hs_ossf_rec_pt_l2->GetMaximum()*1.2);
    if (histo_signal_50_ossf_kin_rec_l2[0]-> GetBinContent(histo_signal_50_ossf_kin_rec_l2[0]->GetMaximumBin ()) > hs_ossf_rec_pt_l2-> GetMaximum()){
        hs_ossf_rec_pt_l2->SetMaximum(histo_signal_50_ossf_kin_rec_l2[0]-> GetBinContent(histo_signal_50_ossf_kin_rec_l2[0]->GetMaximumBin ()) * 2);
    }
    hs_ossf_rec_pt_l2->Draw("hist");
    histo_signal_50_ossf_kin_rec_l2[0]->SetLineColor(1);
    histo_signal_50_ossf_kin_rec_l2[0]->SetMarkerStyle(21);
    histo_signal_50_ossf_kin_rec_l2[0]->SetMarkerColor(1);
    histo_signal_50_ossf_kin_rec_l2[0]->Draw("histsame");
    histo_signal_20_ossf_kin_rec_l2[0]->SetLineColor(1);
    histo_signal_20_ossf_kin_rec_l2[0]->SetLineStyle(7);
    histo_signal_20_ossf_kin_rec_l2[0]->SetMarkerColor(1);
    histo_signal_20_ossf_kin_rec_l2[0]->Draw("histsame");
    histo_signal_5_ossf_kin_rec_l2[0]->SetLineColor(1);
    histo_signal_5_ossf_kin_rec_l2[0]->SetLineStyle(3);
    histo_signal_5_ossf_kin_rec_l2[0]->SetMarkerColor(1);
    histo_signal_5_ossf_kin_rec_l2[0]->Draw("histsame");
    leg_ossf_pt2 = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_pt2->SetHeader("OSSF p_{T} subleading lepton"); // option "C" al2ows to center the header
    leg_ossf_pt2->AddEntry(histo_dy2_ossf_kin_rec_l2[0],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_pt2->AddEntry(histo_tt_ossf_kin_rec_l2[0],"ttbar","f");
    leg_ossf_pt2->AddEntry(histo_wg_ossf_kin_rec_l2[0],"W#gamma","f");
    leg_ossf_pt2->AddEntry(histo_wz_ossf_kin_rec_l2[0],"WZ","f");
    leg_ossf_pt2->AddEntry(histo_signal_5_ossf_kin_rec_l2[0],"MN = 5 GeV","l");
    
    leg_ossf_pt2->AddEntry(histo_signal_20_ossf_kin_rec_l2[0],"MN = 20 GeV","l");
    
    leg_ossf_pt2->AddEntry(histo_signal_50_ossf_kin_rec_l2[0],"MN = 50 GeV","l");
    leg_ossf_pt2->Draw();
    hs_ossf_rec_pt_l2->GetXaxis()->SetTitle("p_{T} (GeV)");
    hs_ossf_rec_pt_l2->GetYaxis()->SetTitle("Events");
    
    c_st_ossf_pt->cd(3);
    hs_ossf_rec_pt_l3->SetMaximum(hs_ossf_rec_pt_l3->GetMaximum()*1.2);
    if (histo_signal_50_ossf_kin_rec_l3[0]-> GetBinContent(histo_signal_50_ossf_kin_rec_l3[0]->GetMaximumBin ()) > hs_ossf_rec_pt_l3-> GetMaximum()){
        hs_ossf_rec_pt_l3->SetMaximum(histo_signal_50_ossf_kin_rec_l3[0]-> GetBinContent(histo_signal_50_ossf_kin_rec_l3[0]->GetMaximumBin ()) * 2);
    }
    hs_ossf_rec_pt_l3->Draw("hist");
    histo_signal_50_ossf_kin_rec_l3[0]->SetLineColor(1);
    histo_signal_50_ossf_kin_rec_l3[0]->SetMarkerStyle(21);
    histo_signal_50_ossf_kin_rec_l3[0]->SetMarkerColor(1);
    histo_signal_50_ossf_kin_rec_l3[0]->Draw("histsame");
    histo_signal_20_ossf_kin_rec_l3[0]->SetLineColor(1);
    histo_signal_20_ossf_kin_rec_l3[0]->SetLineStyle(7);
    histo_signal_20_ossf_kin_rec_l3[0]->SetMarkerColor(1);
    histo_signal_20_ossf_kin_rec_l3[0]->Draw("histsame");
    histo_signal_5_ossf_kin_rec_l3[0]->SetLineColor(1);
    histo_signal_5_ossf_kin_rec_l3[0]->SetLineStyle(3);
    histo_signal_5_ossf_kin_rec_l3[0]->SetMarkerColor(1);
    histo_signal_5_ossf_kin_rec_l3[0]->Draw("histsame");
    leg_ossf_pt3 = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_pt3->SetHeader("OSSF p_{T} soft lepton"); // option "C" al3ows to center the header
    leg_ossf_pt3->AddEntry(histo_dy2_ossf_kin_rec_l3[0],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_pt3->AddEntry(histo_tt_ossf_kin_rec_l3[0],"ttbar","f");
    leg_ossf_pt3->AddEntry(histo_wg_ossf_kin_rec_l3[0],"W#gamma","f");
    leg_ossf_pt3->AddEntry(histo_wz_ossf_kin_rec_l3[0],"WZ","f");
    leg_ossf_pt3->AddEntry(histo_signal_5_ossf_kin_rec_l3[0],"MN = 5 GeV","l");
    
    leg_ossf_pt3->AddEntry(histo_signal_20_ossf_kin_rec_l3[0],"MN = 20 GeV","l");
    
    leg_ossf_pt3->AddEntry(histo_signal_50_ossf_kin_rec_l3[0],"MN = 50 GeV","l");
    leg_ossf_pt3->Draw();
    hs_ossf_rec_pt_l3->GetXaxis()->SetTitle("p_{T} (GeV)");
    hs_ossf_rec_pt_l3->GetYaxis()->SetTitle("Events");
    
    c_st_ossf_pt->cd(4);
    hs_ossf_gen_pt_l1->SetMaximum(hs_ossf_gen_pt_l1->GetMaximum()*1.2);
    if (histo_signal_50_ossf_kin_gen_l1[0]-> GetBinContent(histo_signal_50_ossf_kin_gen_l1[0]->GetMaximumBin ()) > hs_ossf_gen_pt_l1-> GetMaximum()){
        hs_ossf_gen_pt_l1->SetMaximum(histo_signal_50_ossf_kin_gen_l1[0]-> GetBinContent(histo_signal_50_ossf_kin_gen_l1[0]->GetMaximumBin ()) * 2);
    }
    hs_ossf_gen_pt_l1->Draw("hist");
    histo_signal_50_ossf_kin_gen_l1[0]->SetLineColor(1);
    histo_signal_50_ossf_kin_gen_l1[0]->SetMarkerStyle(21);
    histo_signal_50_ossf_kin_gen_l1[0]->SetMarkerColor(1);
    histo_signal_50_ossf_kin_gen_l1[0]->Draw("histsame");
    histo_signal_20_ossf_kin_gen_l1[0]->SetLineColor(1);
    histo_signal_20_ossf_kin_gen_l1[0]->SetLineStyle(7);
    histo_signal_20_ossf_kin_gen_l1[0]->SetMarkerColor(1);
    histo_signal_20_ossf_kin_gen_l1[0]->Draw("histsame");
    histo_signal_5_ossf_kin_gen_l1[0]->SetLineColor(1);
    histo_signal_5_ossf_kin_gen_l1[0]->SetLineStyle(3);
    histo_signal_5_ossf_kin_gen_l1[0]->SetMarkerColor(1);
    histo_signal_5_ossf_kin_gen_l1[0]->Draw("histsame");
    leg_ossf_pt1 = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_pt1->SetHeader("OSSF p_{T} leading lepton gen"); // option "C" al2ows to center the header
    leg_ossf_pt1->AddEntry(histo_dy2_ossf_kin_gen_l1[0],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_pt1->AddEntry(histo_tt_ossf_kin_gen_l1[0],"ttbar","f");
    leg_ossf_pt1->AddEntry(histo_wg_ossf_kin_gen_l1[0],"W#gamma","f");
    leg_ossf_pt1->AddEntry(histo_wz_ossf_kin_gen_l1[0],"WZ","f");
    leg_ossf_pt1->AddEntry(histo_signal_5_ossf_kin_gen_l1[0],"MN = 5 GeV","l");
    
    leg_ossf_pt1->AddEntry(histo_signal_20_ossf_kin_gen_l1[0],"MN = 20 GeV","l");
    leg_ossf_pt1->AddEntry(histo_signal_50_ossf_kin_gen_l1[0],"MN = 50 GeV","l");
    leg_ossf_pt1->Draw();
    hs_ossf_gen_pt_l1->GetXaxis()->SetTitle("p_{T} (GeV)");
    hs_ossf_gen_pt_l1->GetYaxis()->SetTitle("Events");
    c_st_ossf_pt->cd(5);
    hs_ossf_gen_pt_l2->SetMaximum(hs_ossf_gen_pt_l2->GetMaximum()*1.2);
    if (histo_signal_50_ossf_kin_gen_l2[0]-> GetBinContent(histo_signal_50_ossf_kin_gen_l2[0]->GetMaximumBin ()) > hs_ossf_gen_pt_l2-> GetMaximum()){
        hs_ossf_gen_pt_l2->SetMaximum(histo_signal_50_ossf_kin_gen_l2[0]-> GetBinContent(histo_signal_50_ossf_kin_gen_l2[0]->GetMaximumBin ()) * 2);
    }
    hs_ossf_gen_pt_l2->Draw("hist");
    histo_signal_50_ossf_kin_gen_l2[0]->SetLineColor(1);
    histo_signal_50_ossf_kin_gen_l2[0]->SetMarkerStyle(21);
    histo_signal_50_ossf_kin_gen_l2[0]->SetMarkerColor(1);
    histo_signal_50_ossf_kin_gen_l2[0]->Draw("histsame");
    histo_signal_20_ossf_kin_gen_l2[0]->SetLineColor(1);
    histo_signal_20_ossf_kin_gen_l2[0]->SetLineStyle(7);
    histo_signal_20_ossf_kin_gen_l2[0]->SetMarkerColor(1);
    histo_signal_20_ossf_kin_gen_l2[0]->Draw("histsame");
    histo_signal_5_ossf_kin_gen_l2[0]->SetLineColor(1);
    histo_signal_5_ossf_kin_gen_l2[0]->SetLineStyle(3);
    histo_signal_5_ossf_kin_gen_l2[0]->SetMarkerColor(1);
    histo_signal_5_ossf_kin_gen_l2[0]->Draw("histsame");
    leg_ossf_pt2 = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_pt2->SetHeader("OSSF p_{T} subleading lepton gen"); // option "C" al2ows to center the header
    leg_ossf_pt2->AddEntry(histo_dy2_ossf_kin_gen_l2[0],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_pt2->AddEntry(histo_tt_ossf_kin_gen_l2[0],"ttbar","f");
    leg_ossf_pt2->AddEntry(histo_wg_ossf_kin_gen_l2[0],"W#gamma","f");
    leg_ossf_pt2->AddEntry(histo_wz_ossf_kin_gen_l2[0],"WZ","f");
    leg_ossf_pt2->AddEntry(histo_signal_5_ossf_kin_gen_l2[0],"MN = 5 GeV","l");
    leg_ossf_pt2->AddEntry(histo_signal_20_ossf_kin_gen_l2[0],"MN = 20 GeV","l");
    leg_ossf_pt2->AddEntry(histo_signal_50_ossf_kin_gen_l2[0],"MN = 50 GeV","l");
    leg_ossf_pt2->Draw();
    hs_ossf_gen_pt_l2->GetXaxis()->SetTitle("p_{T} (GeV)");
    hs_ossf_gen_pt_l2->GetYaxis()->SetTitle("Events");
    
    c_st_ossf_pt->cd(6);
    hs_ossf_gen_pt_l3->SetMaximum(hs_ossf_gen_pt_l3->GetMaximum()*1.2);
    if (histo_signal_50_ossf_kin_gen_l3[0]-> GetBinContent(histo_signal_50_ossf_kin_gen_l3[0]->GetMaximumBin ()) > hs_ossf_gen_pt_l3-> GetMaximum()){
        hs_ossf_gen_pt_l3->SetMaximum(histo_signal_50_ossf_kin_gen_l3[0]-> GetBinContent(histo_signal_50_ossf_kin_gen_l3[0]->GetMaximumBin ()) * 2);
    }
    hs_ossf_gen_pt_l3->Draw("hist");
    histo_signal_50_ossf_kin_gen_l3[0]->SetLineColor(1);
    histo_signal_50_ossf_kin_gen_l3[0]->SetMarkerStyle(21);
    histo_signal_50_ossf_kin_gen_l3[0]->SetMarkerColor(1);
    histo_signal_50_ossf_kin_gen_l3[0]->Draw("histsame");
    histo_signal_20_ossf_kin_gen_l3[0]->SetLineColor(1);
    histo_signal_20_ossf_kin_gen_l3[0]->SetLineStyle(7);
    histo_signal_20_ossf_kin_gen_l3[0]->SetMarkerColor(1);
    histo_signal_20_ossf_kin_gen_l3[0]->Draw("histsame");
    histo_signal_5_ossf_kin_gen_l3[0]->SetLineColor(1);
    histo_signal_5_ossf_kin_gen_l3[0]->SetLineStyle(3);
    histo_signal_5_ossf_kin_gen_l3[0]->SetMarkerColor(1);
    histo_signal_5_ossf_kin_gen_l3[0]->Draw("histsame");
    leg_ossf_pt3 = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_pt3->SetHeader("OSSF p_{T} soft lepton gen"); // option "C" al3ows to center the header
    leg_ossf_pt3->AddEntry(histo_dy2_ossf_kin_gen_l3[0],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_pt3->AddEntry(histo_tt_ossf_kin_gen_l3[0],"ttbar","f");
    leg_ossf_pt3->AddEntry(histo_wg_ossf_kin_gen_l3[0],"W#gamma","f");
    leg_ossf_pt3->AddEntry(histo_wz_ossf_kin_gen_l3[0],"WZ","f");
    leg_ossf_pt3->AddEntry(histo_signal_5_ossf_kin_gen_l3[0],"MN = 5 GeV","l");
    
    leg_ossf_pt3->AddEntry(histo_signal_20_ossf_kin_gen_l3[0],"MN = 20 GeV","l");
    
    leg_ossf_pt3->AddEntry(histo_signal_50_ossf_kin_gen_l3[0],"MN = 50 GeV","l");
    leg_ossf_pt3->Draw();
    hs_ossf_gen_pt_l3->GetXaxis()->SetTitle("p_{T} (GeV)");
    hs_ossf_gen_pt_l3->GetYaxis()->SetTitle("Events");
    c_st_ossf_pt->Modified();
    c_st_ossf_pt->Print("PLOT/c_st_ossf_pt.root");
    delete c_st_ossf_pt;
    
    TCanvas *c_st_ossf_met = new TCanvas("c_st_ossf_met","c_st_ossf_met",10,10,700,700);
    c_st_ossf_met->Divide(1,2);
    c_st_ossf_met->cd(1);
    /*if (histo_signal_50_ossf_rec[0]-> GetBinContent(histo_signal_50_ossf_rec[0]->GetMaximumBin ()) > histo_dy2_ossf_rec[0]-> GetBinContent(histo_dy2_ossf_rec[0]->GetMaximumBin ())){
     hs_ossf_rec_met->SetMaximum(histo_signal_50_ossf_rec[0]-> GetBinContent(histo_signal_50_ossf_rec[0]->GetMaximumBin ()) * 1.1);
     }*/
    hs_ossf_rec_met->SetMaximum(hs_ossf_rec_met->GetMaximum()*1.2);
    if (histo_signal_50_ossf_rec[0]-> GetBinContent(histo_signal_50_ossf_rec[0]->GetMaximumBin ()) > hs_ossf_rec_met-> GetMaximum()){
        hs_ossf_rec_met->SetMaximum(histo_signal_50_ossf_rec[0]-> GetBinContent(histo_signal_50_ossf_rec[0]->GetMaximumBin ()) * 2);
    }
    hs_ossf_rec_met->Draw("hist");
    histo_signal_50_ossf_rec[0]->SetLineColor(1);
    histo_signal_50_ossf_rec[0]->SetMarkerStyle(21);
    histo_signal_50_ossf_rec[0]->SetMarkerColor(1);
    histo_signal_50_ossf_rec[0]->Draw("histsame");
    histo_signal_20_ossf_rec[0]->SetLineColor(1);
    histo_signal_20_ossf_rec[0]->SetLineStyle(7);
    histo_signal_20_ossf_rec[0]->SetMarkerColor(1);
    histo_signal_20_ossf_rec[0]->Draw("histsame");
    histo_signal_5_ossf_rec[0]->SetLineColor(1);
    histo_signal_5_ossf_rec[0]->SetLineStyle(3);
    histo_signal_5_ossf_rec[0]->SetMarkerColor(1);
    histo_signal_5_ossf_rec[0]->Draw("histsame");
    leg_ossf_met = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_met->SetHeader("OSSF MET"); // option "C" allows to center the header
    leg_ossf_met->AddEntry(histo_dy2_ossf_rec[0],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_met->AddEntry(histo_tt_ossf_rec[0],"ttbar","f");
    leg_ossf_met->AddEntry(histo_wg_ossf_rec[0],"W#gamma","f");
    leg_ossf_met->AddEntry(histo_wz_ossf_rec[0],"WZ","f");
    leg_ossf_met->AddEntry(histo_signal_5_ossf_rec[0],"MN = 5 GeV","l");
    
    leg_ossf_met->AddEntry(histo_signal_20_ossf_rec[0],"MN = 20 GeV","l");
    
    leg_ossf_met->AddEntry(histo_signal_50_ossf_rec[0],"MN = 50 GeV","l");
    leg_ossf_met->Draw();
    hs_ossf_rec_met->GetXaxis()->SetTitle("MET");
    hs_ossf_rec_met->GetYaxis()->SetTitle("Events");
    c_st_ossf_met->cd(2);
    hs_ossf_gen_met->SetMaximum(hs_ossf_gen_met->GetMaximum()*1.2);
    if (histo_signal_50_ossf_gen[0]-> GetBinContent(histo_signal_50_ossf_gen[0]->GetMaximumBin ()) > hs_ossf_gen_met-> GetMaximum()){
        hs_ossf_gen_met->SetMaximum(histo_signal_50_ossf_gen[0]-> GetBinContent(histo_signal_50_ossf_gen[0]->GetMaximumBin ()) * 2);
    }
    hs_ossf_gen_met->Draw("hist");
    histo_signal_50_ossf_gen[0]->SetLineColor(1);
    histo_signal_50_ossf_gen[0]->SetMarkerStyle(21);
    histo_signal_50_ossf_gen[0]->SetMarkerColor(1);
    histo_signal_50_ossf_gen[0]->Draw("histsame");
    histo_signal_20_ossf_gen[0]->SetLineColor(1);
    histo_signal_20_ossf_gen[0]->SetLineStyle(7);
    histo_signal_20_ossf_gen[0]->SetMarkerColor(1);
    histo_signal_20_ossf_gen[0]->Draw("histsame");
    histo_signal_5_ossf_gen[0]->SetLineColor(1);
    histo_signal_5_ossf_gen[0]->SetLineStyle(3);
    histo_signal_5_ossf_gen[0]->SetMarkerColor(1);
    histo_signal_5_ossf_gen[0]->Draw("histsame");
    leg_ossf_met_gen = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_met_gen->SetHeader("OSSF MET gen"); // option "C" allows to center the header
    leg_ossf_met_gen->AddEntry(histo_dy2_ossf_gen[0],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_met_gen->AddEntry(histo_tt_ossf_gen[0],"ttbar","f");
    leg_ossf_met_gen->AddEntry(histo_wg_ossf_gen[0],"W#gamma","f");
    leg_ossf_met_gen->AddEntry(histo_wz_ossf_gen[0],"WZ","f");
    leg_ossf_met_gen->AddEntry(histo_signal_5_ossf_gen[0],"MN = 5 GeV","l");
    
    leg_ossf_met_gen->AddEntry(histo_signal_20_ossf_gen[0],"MN = 20 GeV","l");
    
    leg_ossf_met_gen->AddEntry(histo_signal_50_ossf_gen[0],"MN = 50 GeV","l");
    leg_ossf_met_gen->Draw();
    hs_ossf_gen_met->GetXaxis()->SetTitle("MET gen");
    hs_ossf_gen_met->GetYaxis()->SetTitle("Events");
    c_st_ossf_met->Modified();
    c_st_ossf_met->Print("PLOT/c_st_ossf_met.root");
    delete c_st_ossf_met;
    
    TCanvas *c_st_ossf_mT = new TCanvas("c_st_ossf_mT","c_st_ossf_mT",10,10,700,700);
    c_st_ossf_mT->Divide(1,2);
    c_st_ossf_mT->cd(1);
    /*if (histo_signal_50_ossf_rec[1]-> GetBinContent(histo_signal_50_ossf_rec[1]->GetMaximumBin ()) > histo_dy2_ossf_rec[1]-> GetBinContent(histo_dy2_ossf_rec[1]->GetMaximumBin ())){
     hs_ossf_rec_mT->SetMaximum(histo_signal_50_ossf_rec[1]-> GetBinContent(histo_signal_50_ossf_rec[1]->GetMaximumBin ()) * 1.1);
     }*/
    hs_ossf_rec_mT->SetMaximum(hs_ossf_rec_mT->GetMaximum()*1.2);
    if (histo_signal_50_ossf_rec[1]-> GetBinContent(histo_signal_50_ossf_rec[1]->GetMaximumBin ()) > hs_ossf_rec_mT-> GetMaximum()){
        hs_ossf_rec_mT->SetMaximum(histo_signal_50_ossf_rec[1]-> GetBinContent(histo_signal_50_ossf_rec[1]->GetMaximumBin ()) * 2);
    }
    hs_ossf_rec_mT->Draw("hist");
    histo_signal_50_ossf_rec[1]->SetLineColor(1);
    histo_signal_50_ossf_rec[1]->SetMarkerStyle(21);
    histo_signal_50_ossf_rec[1]->SetMarkerColor(1);
    histo_signal_50_ossf_rec[1]->Draw("histsame");
    histo_signal_20_ossf_rec[1]->SetLineColor(1);
    histo_signal_20_ossf_rec[1]->SetLineStyle(7);
    histo_signal_20_ossf_rec[1]->SetMarkerColor(1);
    histo_signal_20_ossf_rec[1]->Draw("histsame");
    histo_signal_5_ossf_rec[1]->SetLineColor(1);
    histo_signal_5_ossf_rec[1]->SetLineStyle(3);
    histo_signal_5_ossf_rec[1]->SetMarkerColor(1);
    histo_signal_5_ossf_rec[1]->Draw("histsame");
    leg_ossf_mT = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_mT->SetHeader("OSSF mT"); // option "C" allows to center the header
    leg_ossf_mT->AddEntry(histo_dy2_ossf_rec[1],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_mT->AddEntry(histo_tt_ossf_rec[1],"ttbar","f");
    leg_ossf_mT->AddEntry(histo_wg_ossf_rec[1],"W#gamma","f");
    leg_ossf_mT->AddEntry(histo_wz_ossf_rec[1],"WZ","f");
    leg_ossf_mT->AddEntry(histo_signal_5_ossf_rec[1],"MN = 5 GeV","l");
    
    leg_ossf_mT->AddEntry(histo_signal_20_ossf_rec[1],"MN = 20 GeV","l");
    
    leg_ossf_mT->AddEntry(histo_signal_50_ossf_rec[1],"MN = 50 GeV","l");
    leg_ossf_mT->Draw();
    hs_ossf_rec_mT->GetXaxis()->SetTitle("mT");
    hs_ossf_rec_mT->GetYaxis()->SetTitle("Events");
    c_st_ossf_mT->cd(2);
    hs_ossf_gen_mT->SetMaximum(hs_ossf_gen_mT->GetMaximum()*1.2);
    if (histo_signal_50_ossf_gen[1]-> GetBinContent(histo_signal_50_ossf_gen[1]->GetMaximumBin ()) > hs_ossf_gen_mT-> GetMaximum()){
        hs_ossf_gen_mT->SetMaximum(histo_signal_50_ossf_gen[1]-> GetBinContent(histo_signal_50_ossf_gen[1]->GetMaximumBin ()) * 2);
    }
    hs_ossf_gen_mT->Draw("hist");
    histo_signal_50_ossf_gen[1]->SetLineColor(1);
    histo_signal_50_ossf_gen[1]->SetMarkerStyle(21);
    histo_signal_50_ossf_gen[1]->SetMarkerColor(1);
    histo_signal_50_ossf_gen[1]->Draw("histsame");
    histo_signal_20_ossf_gen[1]->SetLineColor(1);
    histo_signal_20_ossf_gen[1]->SetLineStyle(7);
    histo_signal_20_ossf_gen[1]->SetMarkerColor(1);
    histo_signal_20_ossf_gen[1]->Draw("histsame");
    histo_signal_5_ossf_gen[1]->SetLineColor(1);
    histo_signal_5_ossf_gen[1]->SetLineStyle(3);
    histo_signal_5_ossf_gen[1]->SetMarkerColor(1);
    histo_signal_5_ossf_gen[1]->Draw("histsame");
    leg_ossf_mT_gen = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_mT_gen->SetHeader("OSSF mT gen"); // option "C" allows to center the header
    leg_ossf_mT_gen->AddEntry(histo_dy2_ossf_gen[1],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_mT_gen->AddEntry(histo_tt_ossf_gen[1],"ttbar","f");
    leg_ossf_mT_gen->AddEntry(histo_wg_ossf_gen[1],"W#gamma","f");
    leg_ossf_mT_gen->AddEntry(histo_wz_ossf_gen[1],"WZ","f");
    leg_ossf_mT_gen->AddEntry(histo_signal_5_ossf_gen[1],"MN = 5 GeV","l");
    
    leg_ossf_mT_gen->AddEntry(histo_signal_20_ossf_gen[1],"MN = 20 GeV","l");
    
    leg_ossf_mT_gen->AddEntry(histo_signal_50_ossf_gen[1],"MN = 50 GeV","l");
    leg_ossf_mT_gen->Draw();
    hs_ossf_gen_mT->GetXaxis()->SetTitle("mT gen");
    hs_ossf_gen_mT->GetYaxis()->SetTitle("Events");
    c_st_ossf_mT->Modified();
    c_st_ossf_mT->Print("PLOT/c_st_ossf_mT.root");
    delete c_st_ossf_mT;
    
    TCanvas *c_st_ossf_mlll = new TCanvas("c_st_ossf_mlll","c_st_ossf_mlll",10,10,700,700);
    c_st_ossf_mlll->Divide(1,2);
    c_st_ossf_mlll->cd(1);
    /*if (histo_signal_50_ossf_rec[2]-> GetBinContent(histo_signal_50_ossf_rec[2]->GetMaximumBin ()) > histo_dy2_ossf_rec[2]-> GetBinContent(histo_dy2_ossf_rec[2]->GetMaximumBin ())){
     hs_ossf_rec_mlll->SetMaximum(histo_signal_50_ossf_rec[2]-> GetBinContent(histo_signal_50_ossf_rec[2]->GetMaximumBin ()) * 1.1);
     }*/
    hs_ossf_rec_mlll->SetMaximum(hs_ossf_rec_mlll->GetMaximum()*1.2);
    if (histo_signal_50_ossf_rec[2]-> GetBinContent(histo_signal_50_ossf_rec[2]->GetMaximumBin ()) > hs_ossf_rec_mlll-> GetMaximum()){
        hs_ossf_rec_mlll->SetMaximum(histo_signal_50_ossf_rec[2]-> GetBinContent(histo_signal_50_ossf_rec[2]->GetMaximumBin ()) * 2);
    }
    hs_ossf_rec_mlll->Draw("hist");
    histo_signal_50_ossf_rec[2]->SetLineColor(1);
    histo_signal_50_ossf_rec[2]->SetMarkerStyle(21);
    histo_signal_50_ossf_rec[2]->SetMarkerColor(1);
    histo_signal_50_ossf_rec[2]->Draw("histsame");
    histo_signal_20_ossf_rec[2]->SetLineColor(1);
    histo_signal_20_ossf_rec[2]->SetLineStyle(7);
    histo_signal_20_ossf_rec[2]->SetMarkerColor(1);
    histo_signal_20_ossf_rec[2]->Draw("histsame");
    histo_signal_5_ossf_rec[2]->SetLineColor(1);
    histo_signal_5_ossf_rec[2]->SetLineStyle(3);
    histo_signal_5_ossf_rec[2]->SetMarkerColor(1);
    histo_signal_5_ossf_rec[2]->Draw("histsame");
    leg_ossf_mlll = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_mlll->SetHeader("OSSF mlll"); // option "C" allows to center the header
    leg_ossf_mlll->AddEntry(histo_dy2_ossf_rec[2],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_mlll->AddEntry(histo_tt_ossf_rec[2],"ttbar","f");
    leg_ossf_mlll->AddEntry(histo_wg_ossf_rec[2],"W#gamma","f");
    leg_ossf_mlll->AddEntry(histo_wz_ossf_rec[2],"WZ","f");
    leg_ossf_mlll->AddEntry(histo_signal_5_ossf_rec[2],"MN = 5 GeV","l");
    
    leg_ossf_mlll->AddEntry(histo_signal_20_ossf_rec[2],"MN = 20 GeV","l");
    
    leg_ossf_mlll->AddEntry(histo_signal_50_ossf_rec[2],"MN = 50 GeV","l");
    leg_ossf_mlll->Draw();
    hs_ossf_rec_mlll->GetXaxis()->SetTitle("M_{lll}");
    hs_ossf_rec_mlll->GetYaxis()->SetTitle("Events");
    c_st_ossf_mlll->cd(2);
    hs_ossf_gen_mlll->SetMaximum(hs_ossf_gen_mlll->GetMaximum()*1.2);
    if (histo_signal_50_ossf_gen[2]-> GetBinContent(histo_signal_50_ossf_gen[2]->GetMaximumBin ()) > hs_ossf_gen_mlll-> GetMaximum()){
        hs_ossf_gen_mlll->SetMaximum(histo_signal_50_ossf_gen[2]-> GetBinContent(histo_signal_50_ossf_gen[2]->GetMaximumBin ()) * 2);
    }
    hs_ossf_gen_mlll->Draw("hist");
    histo_signal_50_ossf_gen[2]->SetLineColor(1);
    histo_signal_50_ossf_gen[2]->SetMarkerStyle(21);
    histo_signal_50_ossf_gen[2]->SetMarkerColor(1);
    histo_signal_50_ossf_gen[2]->Draw("histsame");
    histo_signal_20_ossf_gen[2]->SetLineColor(1);
    histo_signal_20_ossf_gen[2]->SetLineStyle(7);
    histo_signal_20_ossf_gen[2]->SetMarkerColor(1);
    histo_signal_20_ossf_gen[2]->Draw("histsame");
    histo_signal_5_ossf_gen[2]->SetLineColor(1);
    histo_signal_5_ossf_gen[2]->SetLineStyle(3);
    histo_signal_5_ossf_gen[2]->SetMarkerColor(1);
    histo_signal_5_ossf_gen[2]->Draw("histsame");
    leg_ossf_mlll_gen = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_mlll_gen->SetHeader("OSSF mlll gen"); // option "C" allows to center the header
    leg_ossf_mlll_gen->AddEntry(histo_dy2_ossf_gen[2],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_mlll_gen->AddEntry(histo_tt_ossf_gen[2],"ttbar","f");
    leg_ossf_mlll_gen->AddEntry(histo_wg_ossf_gen[2],"W#gamma","f");
    leg_ossf_mlll_gen->AddEntry(histo_wz_ossf_gen[2],"WZ","f");
    leg_ossf_mlll_gen->AddEntry(histo_signal_5_ossf_gen[2],"MN = 5 GeV","l");
    
    leg_ossf_mlll_gen->AddEntry(histo_signal_20_ossf_gen[2],"MN = 20 GeV","l");
    
    leg_ossf_mlll_gen->AddEntry(histo_signal_50_ossf_gen[2],"MN = 50 GeV","l");
    leg_ossf_mlll_gen->Draw();
    hs_ossf_gen_mlll->GetXaxis()->SetTitle("M_{lll} gen");
    hs_ossf_gen_mlll->GetYaxis()->SetTitle("Events");
    c_st_ossf_mlll->Modified();
    c_st_ossf_mlll->Print("PLOT/c_st_ossf_mlll.root");
    delete c_st_ossf_mlll;
    
    TCanvas *c_st_ossf_mll = new TCanvas("c_st_ossf_M_{ll}","c_st_ossf_M_{ll}",10,10,700,700);
    c_st_ossf_mll->Divide(1,2);
    c_st_ossf_mll->cd(1);
    /*if (histo_signal_50_ossf_rec[3]-> GetBinContent(histo_signal_50_ossf_rec[3]->GetMaximumBin ()) > histo_dy2_ossf_rec[3]-> GetBinContent(histo_dy2_ossf_rec[3]->GetMaximumBin ())){
     hs_ossf_rec_mll->SetMaximum(histo_signal_50_ossf_rec[3]-> GetBinContent(histo_signal_50_ossf_rec[3]->GetMaximumBin ()) * 1.1);
     }*/
    hs_ossf_rec_mll->SetMaximum(hs_ossf_rec_mll->GetMaximum()*1.2);
    if (histo_signal_5_ossf_rec[3]-> GetBinContent(histo_signal_5_ossf_rec[3]->GetMaximumBin ()) > hs_ossf_rec_mll-> GetMaximum()){
        hs_ossf_rec_mll->SetMaximum(histo_signal_5_ossf_rec[3]-> GetBinContent(histo_signal_5_ossf_rec[3]->GetMaximumBin ()) * 2);
    }
    hs_ossf_rec_mll->Draw("hist");
    histo_signal_50_ossf_rec[3]->SetLineColor(1);
    histo_signal_50_ossf_rec[3]->SetMarkerStyle(21);
    histo_signal_50_ossf_rec[3]->SetMarkerColor(1);
    histo_signal_50_ossf_rec[3]->Draw("histsame");
    histo_signal_20_ossf_rec[3]->SetLineColor(1);
    histo_signal_20_ossf_rec[3]->SetLineStyle(7);
    histo_signal_20_ossf_rec[3]->SetMarkerColor(1);
    histo_signal_20_ossf_rec[3]->Draw("histsame");
    histo_signal_5_ossf_rec[3]->SetLineColor(1);
    histo_signal_5_ossf_rec[3]->SetLineStyle(3);
    histo_signal_5_ossf_rec[3]->SetMarkerColor(1);
    histo_signal_5_ossf_rec[3]->Draw("histsame");
    leg_ossf_mll = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_mll->SetHeader("OSSF M_{ll}"); // option "C" allows to center the header
    leg_ossf_mll->AddEntry(histo_dy2_ossf_rec[3],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_mll->AddEntry(histo_tt_ossf_rec[3],"ttbar","f");
    leg_ossf_mll->AddEntry(histo_wg_ossf_rec[3],"W#gamma","f");
    leg_ossf_mll->AddEntry(histo_wz_ossf_rec[3],"WZ","f");
    leg_ossf_mll->AddEntry(histo_signal_5_ossf_rec[3],"MN = 5 GeV","l");
    
    leg_ossf_mll->AddEntry(histo_signal_20_ossf_rec[3],"MN = 20 GeV","l");
    
    leg_ossf_mll->AddEntry(histo_signal_50_ossf_rec[3],"MN = 50 GeV","l");
    leg_ossf_mll->Draw();
    hs_ossf_rec_mll->GetXaxis()->SetTitle("M_{ll}");
    hs_ossf_rec_mll->GetYaxis()->SetTitle("Events");
    c_st_ossf_mll->cd(2);
    hs_ossf_gen_mll->SetMaximum(hs_ossf_gen_mll->GetMaximum()*1.2);
    if (histo_signal_50_ossf_gen[3]-> GetBinContent(histo_signal_50_ossf_gen[3]->GetMaximumBin ()) > hs_ossf_gen_mll-> GetMaximum()){
        hs_ossf_gen_mll->SetMaximum(histo_signal_50_ossf_gen[3]-> GetBinContent(histo_signal_50_ossf_gen[3]->GetMaximumBin ()) * 2);
    }
    hs_ossf_gen_mll->Draw("hist");
    histo_signal_50_ossf_gen[3]->SetLineColor(1);
    histo_signal_50_ossf_gen[3]->SetMarkerStyle(21);
    histo_signal_50_ossf_gen[3]->SetMarkerColor(1);
    histo_signal_50_ossf_gen[3]->Draw("histsame");
    histo_signal_20_ossf_gen[3]->SetLineColor(1);
    histo_signal_20_ossf_gen[3]->SetLineStyle(7);
    histo_signal_20_ossf_gen[3]->SetMarkerColor(1);
    histo_signal_20_ossf_gen[3]->Draw("histsame");
    histo_signal_5_ossf_gen[3]->SetLineColor(1);
    histo_signal_5_ossf_gen[3]->SetLineStyle(3);
    histo_signal_5_ossf_gen[3]->SetMarkerColor(1);
    histo_signal_5_ossf_gen[3]->Draw("histsame");
    leg_ossf_mll_gen = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_mll_gen->SetHeader("OSSF mll gen"); // option "C" allows to center the header
    leg_ossf_mll_gen->AddEntry(histo_dy2_ossf_gen[3],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_mll_gen->AddEntry(histo_tt_ossf_gen[3],"ttbar","f");
    leg_ossf_mll_gen->AddEntry(histo_wg_ossf_gen[3],"W#gamma","f");
    leg_ossf_mll_gen->AddEntry(histo_wz_ossf_gen[3],"WZ","f");
    leg_ossf_mll_gen->AddEntry(histo_signal_5_ossf_gen[3],"MN = 5 GeV","l");
    
    leg_ossf_mll_gen->AddEntry(histo_signal_20_ossf_gen[3],"MN = 20 GeV","l");
    
    leg_ossf_mll_gen->AddEntry(histo_signal_50_ossf_gen[3],"MN = 50 GeV","l");
    leg_ossf_mll_gen->Draw();
    hs_ossf_gen_mll->GetXaxis()->SetTitle("M_{ll} gen");
    hs_ossf_gen_mll->GetYaxis()->SetTitle("Events");
    c_st_ossf_mll->Modified();
    c_st_ossf_mll->Print("PLOT/c_st_ossf_mll.root");
    delete c_st_ossf_mll;
    
    TCanvas *c_st_ossf_mll_pair = new TCanvas("c_st_ossf_M_{ll}","c_st_ossf_M_{ll}",10,10,700,700);
    c_st_ossf_mll_pair->Divide(1,2);
    c_st_ossf_mll_pair->cd(1);
    /*if (histo_signal_50_ossf_rec[11]-> GetBinContent(histo_signal_50_ossf_rec[11]->GetMaximumBin ()) > histo_dy2_ossf_rec[11]-> GetBinContent(histo_dy2_ossf_rec[11]->GetMaximumBin ())){
     hs_ossf_rec_mll_pair->SetMaximum(histo_signal_50_ossf_rec[11]-> GetBinContent(histo_signal_50_ossf_rec[11]->GetMaximumBin ()) * 1.1);
     }*/
    hs_ossf_rec_mll_pair->SetMaximum(hs_ossf_rec_mll_pair->GetMaximum()*1.2);
    if (histo_signal_50_ossf_rec[11]-> GetBinContent(histo_signal_50_ossf_rec[11]->GetMaximumBin ()) > hs_ossf_rec_mll_pair-> GetMaximum()){
        hs_ossf_rec_mll_pair->SetMaximum(histo_signal_50_ossf_rec[11]-> GetBinContent(histo_signal_50_ossf_rec[11]->GetMaximumBin ()) * 2);
    }
    hs_ossf_rec_mll_pair->Draw("hist");
    histo_signal_50_ossf_rec[11]->SetLineColor(1);
    histo_signal_50_ossf_rec[11]->SetMarkerStyle(21);
    histo_signal_50_ossf_rec[11]->SetMarkerColor(1);
    histo_signal_50_ossf_rec[11]->Draw("histsame");
    histo_signal_20_ossf_rec[11]->SetLineColor(1);
    histo_signal_20_ossf_rec[11]->SetLineStyle(7);
    histo_signal_20_ossf_rec[11]->SetMarkerColor(1);
    histo_signal_20_ossf_rec[11]->Draw("histsame");
    histo_signal_5_ossf_rec[11]->SetLineColor(1);
    histo_signal_5_ossf_rec[11]->SetLineStyle(3);
    histo_signal_5_ossf_rec[11]->SetMarkerColor(1);
    histo_signal_5_ossf_rec[11]->Draw("histsame");
    leg_ossf_mll_pair = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_mll_pair->SetHeader("OSSF M_{ll}"); // option "C" allows to center the header
    leg_ossf_mll_pair->AddEntry(histo_dy2_ossf_rec[11],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_mll_pair->AddEntry(histo_tt_ossf_rec[11],"ttbar","f");
    leg_ossf_mll_pair->AddEntry(histo_wg_ossf_rec[11],"W#gamma","f");
    leg_ossf_mll_pair->AddEntry(histo_wz_ossf_rec[11],"WZ","f");
    leg_ossf_mll_pair->AddEntry(histo_signal_5_ossf_rec[11],"MN = 5 GeV","l");
    
    leg_ossf_mll_pair->AddEntry(histo_signal_20_ossf_rec[11],"MN = 20 GeV","l");
    
    leg_ossf_mll_pair->AddEntry(histo_signal_50_ossf_rec[11],"MN = 50 GeV","l");
    leg_ossf_mll_pair->Draw();
    hs_ossf_rec_mll_pair->GetXaxis()->SetTitle("M_{ll} (OSSF pair) ");
    hs_ossf_rec_mll_pair->GetYaxis()->SetTitle("Events");
    c_st_ossf_mll_pair->cd(2);
    hs_ossf_gen_mll_pair->SetMaximum(hs_ossf_gen_mll_pair->GetMaximum()*1.2);
    if (histo_signal_50_ossf_gen[4]-> GetBinContent(histo_signal_50_ossf_gen[4]->GetMaximumBin ()) > hs_ossf_gen_mll_pair-> GetMaximum()){
        hs_ossf_gen_mll_pair->SetMaximum(histo_signal_50_ossf_gen[4]-> GetBinContent(histo_signal_50_ossf_gen[4]->GetMaximumBin ()) * 2);
    }
    hs_ossf_gen_mll_pair->Draw("hist");
    histo_signal_50_ossf_gen[4]->SetLineColor(1);
    histo_signal_50_ossf_gen[4]->SetMarkerStyle(21);
    histo_signal_50_ossf_gen[4]->SetMarkerColor(1);
    histo_signal_50_ossf_gen[4]->Draw("histsame");
    histo_signal_20_ossf_gen[4]->SetLineColor(1);
    histo_signal_20_ossf_gen[4]->SetLineStyle(7);
    histo_signal_20_ossf_gen[4]->SetMarkerColor(1);
    histo_signal_20_ossf_gen[4]->Draw("histsame");
    histo_signal_5_ossf_gen[4]->SetLineColor(1);
    histo_signal_5_ossf_gen[4]->SetLineStyle(3);
    histo_signal_5_ossf_gen[4]->SetMarkerColor(1);
    histo_signal_5_ossf_gen[4]->Draw("histsame");
    leg_ossf_mll_pair_gen = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_mll_pair_gen->SetHeader("OSSF mll_pair gen"); // option "C" allows to center the header
    leg_ossf_mll_pair_gen->AddEntry(histo_dy2_ossf_gen[4],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_mll_pair_gen->AddEntry(histo_tt_ossf_gen[4],"ttbar","f");
    leg_ossf_mll_pair_gen->AddEntry(histo_wg_ossf_gen[4],"W#gamma","f");
    leg_ossf_mll_pair_gen->AddEntry(histo_wz_ossf_gen[4],"WZ","f");
    leg_ossf_mll_pair_gen->AddEntry(histo_signal_5_ossf_gen[4],"MN = 5 GeV","l");
    
    leg_ossf_mll_pair_gen->AddEntry(histo_signal_20_ossf_gen[4],"MN = 20 GeV","l");
    
    leg_ossf_mll_pair_gen->AddEntry(histo_signal_50_ossf_gen[4],"MN = 50 GeV","l");
    leg_ossf_mll_pair_gen->Draw();
    hs_ossf_gen_mll_pair->GetXaxis()->SetTitle("M_{ll} (OSSF pair)  gen");
    hs_ossf_gen_mll_pair->GetYaxis()->SetTitle("Events");
    c_st_ossf_mll_pair->Modified();
    c_st_ossf_mll_pair->Print("PLOT/c_st_ossf_mll_pair.root");
    delete c_st_ossf_mll_pair;
    
    TCanvas *c_st_ossf_nJet = new TCanvas("c_st_ossf_njet","c_st_ossf_njet",10,10,700,700);
    c_st_ossf_nJet->Divide(1,2);
    c_st_ossf_nJet->cd(1);
    /*if (histo_signal_50_ossf_rec[4]-> GetBinContent(histo_signal_50_ossf_rec[4]->GetMaximumBin ()) > histo_dy2_ossf_rec[4]-> GetBinContent(histo_dy2_ossf_rec[4]->GetMaximumBin ())){
     hs_ossf_rec_nJet->SetMaximum(histo_signal_50_ossf_rec[4]-> GetBinContent(histo_signal_50_ossf_rec[4]->GetMaximumBin ()) * 1.1);
     }*/
    hs_ossf_rec_nJet->SetMaximum(hs_ossf_rec_nJet->GetMaximum()*1.2);
    if (histo_signal_50_ossf_rec[4]-> GetBinContent(histo_signal_50_ossf_rec[4]->GetMaximumBin ()) > hs_ossf_rec_nJet-> GetMaximum()){
        hs_ossf_rec_nJet->SetMaximum(histo_signal_50_ossf_rec[4]-> GetBinContent(histo_signal_50_ossf_rec[4]->GetMaximumBin ()) * 2);
    }
    hs_ossf_rec_nJet->Draw("hist");
    histo_signal_50_ossf_rec[4]->SetLineColor(1);
    histo_signal_50_ossf_rec[4]->SetMarkerStyle(21);
    histo_signal_50_ossf_rec[4]->SetMarkerColor(1);
    histo_signal_50_ossf_rec[4]->Draw("histsame");
    histo_signal_20_ossf_rec[4]->SetLineColor(1);
    histo_signal_20_ossf_rec[4]->SetLineStyle(7);
    histo_signal_20_ossf_rec[4]->SetMarkerColor(1);
    histo_signal_20_ossf_rec[4]->Draw("histsame");
    histo_signal_5_ossf_rec[4]->SetLineColor(1);
    histo_signal_5_ossf_rec[4]->SetLineStyle(3);
    histo_signal_5_ossf_rec[4]->SetMarkerColor(1);
    histo_signal_5_ossf_rec[4]->Draw("histsame");
    leg_ossf_nJet = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_nJet->SetHeader("OSSF njet"); // option "C" allows to center the header
    leg_ossf_nJet->AddEntry(histo_dy2_ossf_rec[4],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_nJet->AddEntry(histo_tt_ossf_rec[4],"ttbar","f");
    leg_ossf_nJet->AddEntry(histo_wg_ossf_rec[4],"W#gamma","f");
    leg_ossf_nJet->AddEntry(histo_wz_ossf_rec[4],"WZ","f");
    leg_ossf_nJet->AddEntry(histo_signal_5_ossf_rec[4],"MN = 5 GeV","l");
    
    leg_ossf_nJet->AddEntry(histo_signal_20_ossf_rec[4],"MN = 20 GeV","l");
    
    leg_ossf_nJet->AddEntry(histo_signal_50_ossf_rec[4],"MN = 50 GeV","l");
    leg_ossf_nJet->Draw();
    hs_ossf_rec_nJet->GetXaxis()->SetTitle("N Jet");
    c_st_ossf_nJet->Modified();
    c_st_ossf_nJet->Print("PLOT/c_st_ossf_nJet.root");
    delete c_st_ossf_nJet;
    
    
    TCanvas *c_st_ossf_nbJet = new TCanvas("c_st_ossf_M_{ll}","c_st_ossf_M_{ll}",10,10,700,700);
    c_st_ossf_nbJet->Divide(1,2);
    c_st_ossf_nbJet->cd(1);
    /*if (histo_signal_50_ossf_rec[5]-> GetBinContent(histo_signal_50_ossf_rec[5]->GetMaximumBin ()) > histo_dy2_ossf_rec[5]-> GetBinContent(histo_dy2_ossf_rec[5]->GetMaximumBin ())){
     hs_ossf_rec_nbJet->SetMaximum(histo_signal_50_ossf_rec[5]-> GetBinContent(histo_signal_50_ossf_rec[5]->GetMaximumBin ()) * 1.1);
     }*/
    hs_ossf_rec_nbJet->SetMaximum(hs_ossf_rec_nbJet->GetMaximum()*1.2);
    if (histo_signal_50_ossf_rec[5]-> GetBinContent(histo_signal_50_ossf_rec[5]->GetMaximumBin ()) > hs_ossf_rec_nbJet-> GetMaximum()){
        hs_ossf_rec_nbJet->SetMaximum(histo_signal_50_ossf_rec[5]-> GetBinContent(histo_signal_50_ossf_rec[5]->GetMaximumBin ()) * 2);
    }
    hs_ossf_rec_nbJet->Draw("hist");
    histo_signal_50_ossf_rec[5]->SetLineColor(1);
    histo_signal_50_ossf_rec[5]->SetMarkerStyle(21);
    histo_signal_50_ossf_rec[5]->SetMarkerColor(1);
    histo_signal_50_ossf_rec[5]->Draw("histsame");
    histo_signal_20_ossf_rec[5]->SetLineColor(1);
    histo_signal_20_ossf_rec[5]->SetLineStyle(7);
    histo_signal_20_ossf_rec[5]->SetMarkerColor(1);
    histo_signal_20_ossf_rec[5]->Draw("histsame");
    histo_signal_5_ossf_rec[5]->SetLineColor(1);
    histo_signal_5_ossf_rec[5]->SetLineStyle(3);
    histo_signal_5_ossf_rec[5]->SetMarkerColor(1);
    histo_signal_5_ossf_rec[5]->Draw("histsame");
    leg_ossf_nbJet = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_nbJet->SetHeader("OSSF M_{ll}"); // option "C" allows to center the header
    leg_ossf_nbJet->AddEntry(histo_dy2_ossf_rec[5],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_nbJet->AddEntry(histo_tt_ossf_rec[5],"ttbar","f");
    leg_ossf_nbJet->AddEntry(histo_wg_ossf_rec[5],"W#gamma","f");
    leg_ossf_nbJet->AddEntry(histo_wz_ossf_rec[5],"WZ","f");
    leg_ossf_nbJet->AddEntry(histo_signal_5_ossf_rec[5],"MN = 5 GeV","l");
    
    leg_ossf_nbJet->AddEntry(histo_signal_20_ossf_rec[5],"MN = 20 GeV","l");
    
    leg_ossf_nbJet->AddEntry(histo_signal_50_ossf_rec[5],"MN = 50 GeV","l");
    leg_ossf_nbJet->Draw();
    hs_ossf_rec_nbJet->GetXaxis()->SetTitle("N bJets");
    c_st_ossf_nbJet->Modified();
    c_st_ossf_nbJet->Print("PLOT/c_st_ossf_nbJet.root");
    delete c_st_ossf_nbJet;
    
    TCanvas *c_st_ossf_HT = new TCanvas("c_st_ossf_M_{ll}","c_st_ossf_M_{ll}",10,10,700,700);
    c_st_ossf_HT->Divide(1,2);
    c_st_ossf_HT->cd(1);
    /*if (histo_signal_50_ossf_rec[6]-> GetBinContent(histo_signal_50_ossf_rec[6]->GetMaximumBin ()) > histo_dy2_ossf_rec[6]-> GetBinContent(histo_dy2_ossf_rec[6]->GetMaximumBin ())){
     hs_ossf_rec_HT->SetMaximum(histo_signal_50_ossf_rec[6]-> GetBinContent(histo_signal_50_ossf_rec[6]->GetMaximumBin ()) * 1.1);
     }*/
    hs_ossf_rec_HT->SetMaximum(hs_ossf_rec_HT->GetMaximum()*1.2);
    if (histo_signal_50_ossf_rec[6]-> GetBinContent(histo_signal_50_ossf_rec[6]->GetMaximumBin ()) > hs_ossf_rec_HT-> GetMaximum()){
        hs_ossf_rec_HT->SetMaximum(histo_signal_50_ossf_rec[6]-> GetBinContent(histo_signal_50_ossf_rec[6]->GetMaximumBin ()) * 2);
    }
    hs_ossf_rec_HT->Draw("hist");
    histo_signal_50_ossf_rec[6]->SetLineColor(1);
    histo_signal_50_ossf_rec[6]->SetMarkerStyle(21);
    histo_signal_50_ossf_rec[6]->SetMarkerColor(1);
    histo_signal_50_ossf_rec[6]->Draw("histsame");
    histo_signal_20_ossf_rec[6]->SetLineColor(1);
    histo_signal_20_ossf_rec[6]->SetLineStyle(7);
    histo_signal_20_ossf_rec[6]->SetMarkerColor(1);
    histo_signal_20_ossf_rec[6]->Draw("histsame");
    histo_signal_5_ossf_rec[6]->SetLineColor(1);
    histo_signal_5_ossf_rec[6]->SetLineStyle(3);
    histo_signal_5_ossf_rec[6]->SetMarkerColor(1);
    histo_signal_5_ossf_rec[6]->Draw("histsame");
    leg_ossf_HT = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_HT->SetHeader("OSSF M_{ll}"); // option "C" allows to center the header
    leg_ossf_HT->AddEntry(histo_dy2_ossf_rec[6],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_HT->AddEntry(histo_tt_ossf_rec[6],"ttbar","f");
    leg_ossf_HT->AddEntry(histo_wg_ossf_rec[6],"W#gamma","f");
    leg_ossf_HT->AddEntry(histo_wz_ossf_rec[6],"WZ","f");
    leg_ossf_HT->AddEntry(histo_signal_5_ossf_rec[6],"MN = 5 GeV","l");
    
    leg_ossf_HT->AddEntry(histo_signal_20_ossf_rec[6],"MN = 20 GeV","l");
    
    leg_ossf_HT->AddEntry(histo_signal_50_ossf_rec[6],"MN = 50 GeV","l");
    leg_ossf_HT->Draw();
    hs_ossf_rec_HT->GetXaxis()->SetTitle("HT");
    c_st_ossf_HT->Modified();
    c_st_ossf_HT->Print("PLOT/c_st_ossf_HT.root");
    delete c_st_ossf_HT;
    
    
    TCanvas *c_st_ossf_jetPt = new TCanvas("c_st_ossf_M_{ll}","c_st_ossf_M_{ll}",10,10,700,700);
    c_st_ossf_jetPt->Divide(1,2);
    c_st_ossf_jetPt->cd(1);
    /*if (histo_signal_50_ossf_rec[7]-> GetBinContent(histo_signal_50_ossf_rec[7]->GetMaximumBin ()) > histo_dy2_ossf_rec[7]-> GetBinContent(histo_dy2_ossf_rec[7]->GetMaximumBin ())){
     hs_ossf_rec_jetPt->SetMaximum(histo_signal_50_ossf_rec[7]-> GetBinContent(histo_signal_50_ossf_rec[7]->GetMaximumBin ()) * 1.1);
     }*/
    hs_ossf_rec_jetPt->SetMaximum(hs_ossf_rec_jetPt->GetMaximum()*1.2);
    if (histo_signal_50_ossf_rec[7]-> GetBinContent(histo_signal_50_ossf_rec[7]->GetMaximumBin ()) > hs_ossf_rec_jetPt-> GetMaximum()){
        hs_ossf_rec_jetPt->SetMaximum(histo_signal_50_ossf_rec[7]-> GetBinContent(histo_signal_50_ossf_rec[7]->GetMaximumBin ()) * 2);
    }
    hs_ossf_rec_jetPt->Draw("hist");
    histo_signal_50_ossf_rec[7]->SetLineColor(1);
    histo_signal_50_ossf_rec[7]->SetMarkerStyle(21);
    histo_signal_50_ossf_rec[7]->SetMarkerColor(1);
    histo_signal_50_ossf_rec[7]->Draw("histsame");
    histo_signal_20_ossf_rec[7]->SetLineColor(1);
    histo_signal_20_ossf_rec[7]->SetLineStyle(7);
    histo_signal_20_ossf_rec[7]->SetMarkerColor(1);
    histo_signal_20_ossf_rec[7]->Draw("histsame");
    histo_signal_5_ossf_rec[7]->SetLineColor(1);
    histo_signal_5_ossf_rec[7]->SetLineStyle(3);
    histo_signal_5_ossf_rec[7]->SetMarkerColor(1);
    histo_signal_5_ossf_rec[7]->Draw("histsame");
    leg_ossf_jetPt = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_jetPt->SetHeader("OSSF M_{ll}"); // option "C" allows to center the header
    leg_ossf_jetPt->AddEntry(histo_dy2_ossf_rec[7],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_jetPt->AddEntry(histo_tt_ossf_rec[7],"ttbar","f");
    leg_ossf_jetPt->AddEntry(histo_wg_ossf_rec[7],"W#gamma","f");
    leg_ossf_jetPt->AddEntry(histo_wz_ossf_rec[7],"WZ","f");
    leg_ossf_jetPt->AddEntry(histo_signal_5_ossf_rec[7],"MN = 5 GeV","l");
    
    leg_ossf_jetPt->AddEntry(histo_signal_20_ossf_rec[7],"MN = 20 GeV","l");
    
    leg_ossf_jetPt->AddEntry(histo_signal_50_ossf_rec[7],"MN = 50 GeV","l");
    leg_ossf_jetPt->Draw();
    hs_ossf_rec_jetPt->GetXaxis()->SetTitle("jet p_{T} (GeV)");
    c_st_ossf_jetPt->Modified();
    c_st_ossf_jetPt->Print("PLOT/c_st_ossf_jetPt.root");
    delete c_st_ossf_jetPt;
    
    
    
    
    
    TCanvas *c_st_ossf_jetEta = new TCanvas("c_st_ossf_M_{ll}","c_st_ossf_M_{ll}",10,10,700,700);
    c_st_ossf_jetEta->Divide(1,2);
    c_st_ossf_jetEta->cd(1);
    /*if (histo_signal_50_ossf_rec[8]-> GetBinContent(histo_signal_50_ossf_rec[8]->GetMaximumBin ()) > histo_dy2_ossf_rec[8]-> GetBinContent(histo_dy2_ossf_rec[8]->GetMaximumBin ())){
     hs_ossf_rec_jetEta->SetMaximum(histo_signal_50_ossf_rec[8]-> GetBinContent(histo_signal_50_ossf_rec[8]->GetMaximumBin ()) * 1.1);
     }*/
    hs_ossf_rec_jetEta->SetMaximum(hs_ossf_rec_jetEta->GetMaximum()*1.2);
    if (histo_signal_50_ossf_rec[8]-> GetBinContent(histo_signal_50_ossf_rec[8]->GetMaximumBin ()) > hs_ossf_rec_jetEta-> GetMaximum()){
        hs_ossf_rec_jetEta->SetMaximum(histo_signal_50_ossf_rec[8]-> GetBinContent(histo_signal_50_ossf_rec[8]->GetMaximumBin ()) * 2);
    }
    hs_ossf_rec_jetEta->Draw("hist");
    histo_signal_50_ossf_rec[8]->SetLineColor(1);
    histo_signal_50_ossf_rec[8]->SetMarkerStyle(21);
    histo_signal_50_ossf_rec[8]->SetMarkerColor(1);
    histo_signal_50_ossf_rec[8]->Draw("histsame");
    histo_signal_20_ossf_rec[8]->SetLineColor(1);
    histo_signal_20_ossf_rec[8]->SetLineStyle(7);
    histo_signal_20_ossf_rec[8]->SetMarkerColor(1);
    histo_signal_20_ossf_rec[8]->Draw("histsame");
    histo_signal_5_ossf_rec[8]->SetLineColor(1);
    histo_signal_5_ossf_rec[8]->SetLineStyle(3);
    histo_signal_5_ossf_rec[8]->SetMarkerColor(1);
    histo_signal_5_ossf_rec[8]->Draw("histsame");
    leg_ossf_jetEta = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_jetEta->SetHeader("OSSF M_{ll}"); // oEtaion "C" allows to center the header
    leg_ossf_jetEta->AddEntry(histo_dy2_ossf_rec[8],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_jetEta->AddEntry(histo_tt_ossf_rec[8],"ttbar","f");
    leg_ossf_jetEta->AddEntry(histo_wg_ossf_rec[8],"W#gamma","f");
    leg_ossf_jetEta->AddEntry(histo_wz_ossf_rec[8],"WZ","f");
    leg_ossf_jetEta->AddEntry(histo_signal_5_ossf_rec[8],"MN = 5 GeV","l");
    
    leg_ossf_jetEta->AddEntry(histo_signal_20_ossf_rec[8],"MN = 20 GeV","l");
    
    leg_ossf_jetEta->AddEntry(histo_signal_50_ossf_rec[8],"MN = 50 GeV","l");
    leg_ossf_jetEta->Draw();
    hs_ossf_rec_jetEta->GetXaxis()->SetTitle("jet #eta");
    c_st_ossf_jetEta->Modified();
    c_st_ossf_jetEta->Print("PLOT/c_st_ossf_jetEta.root");
    delete c_st_ossf_jetEta;
    
    
    TCanvas *c_st_ossf_jetPhi = new TCanvas("c_st_ossf_M_{ll}","c_st_ossf_M_{ll}",10,10,700,700);
    c_st_ossf_jetPhi->Divide(1,2);
    c_st_ossf_jetPhi->cd(1);
    /*if (histo_signal_50_ossf_rec[9]-> GetBinContent(histo_signal_50_ossf_rec[9]->GetMaximumBin ()) > histo_dy2_ossf_rec[9]-> GetBinContent(histo_dy2_ossf_rec[9]->GetMaximumBin ())){
     hs_ossf_rec_jetPhi->SetMaximum(histo_signal_50_ossf_rec[9]-> GetBinContent(histo_signal_50_ossf_rec[9]->GetMaximumBin ()) * 1.1);
     }*/
    hs_ossf_rec_jetPhi->SetMaximum(hs_ossf_rec_jetPhi->GetMaximum()*1.2);
    if (histo_signal_50_ossf_rec[9]-> GetBinContent(histo_signal_50_ossf_rec[9]->GetMaximumBin ()) > hs_ossf_rec_jetPhi-> GetMaximum()){
        hs_ossf_rec_jetPhi->SetMaximum(histo_signal_50_ossf_rec[9]-> GetBinContent(histo_signal_50_ossf_rec[9]->GetMaximumBin ()) * 2);
    }
    hs_ossf_rec_jetPhi->Draw("hist");
    histo_signal_50_ossf_rec[9]->SetLineColor(1);
    histo_signal_50_ossf_rec[9]->SetMarkerStyle(21);
    histo_signal_50_ossf_rec[9]->SetMarkerColor(1);
    histo_signal_50_ossf_rec[9]->Draw("histsame");
    histo_signal_20_ossf_rec[9]->SetLineColor(1);
    histo_signal_20_ossf_rec[9]->SetLineStyle(7);
    histo_signal_20_ossf_rec[9]->SetMarkerColor(1);
    histo_signal_20_ossf_rec[9]->Draw("histsame");
    histo_signal_5_ossf_rec[9]->SetLineColor(1);
    histo_signal_5_ossf_rec[9]->SetLineStyle(3);
    histo_signal_5_ossf_rec[9]->SetMarkerColor(1);
    histo_signal_5_ossf_rec[9]->Draw("histsame");
    leg_ossf_jetPhi = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_jetPhi->SetHeader("OSSF M_{ll}"); // oPhiion "C" allows to center the header
    leg_ossf_jetPhi->AddEntry(histo_dy2_ossf_rec[9],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_jetPhi->AddEntry(histo_tt_ossf_rec[9],"ttbar","f");
    leg_ossf_jetPhi->AddEntry(histo_wg_ossf_rec[9],"W#gamma","f");
    leg_ossf_jetPhi->AddEntry(histo_wz_ossf_rec[9],"WZ","f");
    leg_ossf_jetPhi->AddEntry(histo_signal_5_ossf_rec[9],"MN = 5 GeV","l");
    
    leg_ossf_jetPhi->AddEntry(histo_signal_20_ossf_rec[9],"MN = 20 GeV","l");
    
    leg_ossf_jetPhi->AddEntry(histo_signal_50_ossf_rec[9],"MN = 50 GeV","l");
    leg_ossf_jetPhi->Draw();
    hs_ossf_rec_jetPhi->GetXaxis()->SetTitle("jet #phi");
    c_st_ossf_jetPhi->Modified();
    c_st_ossf_jetPhi->Print("PLOT/c_st_ossf_jetPhi.root");
    delete c_st_ossf_jetPhi;
    
    
    TCanvas *c_st_ossf_jetFlavour = new TCanvas("c_st_ossf_M_{ll}","c_st_ossf_M_{ll}",10,10,700,700);
    c_st_ossf_jetFlavour->Divide(1,2);
    c_st_ossf_jetFlavour->cd(1);
    /*if (histo_signal_50_ossf_rec[10]-> GetBinContent(histo_signal_50_ossf_rec[10]->GetMaximumBin ()) > histo_dy2_ossf_rec[10]-> GetBinContent(histo_dy2_ossf_rec[10]->GetMaximumBin ())){
     hs_ossf_rec_jetFlavour->SetMaximum(histo_signal_50_ossf_rec[10]-> GetBinContent(histo_signal_50_ossf_rec[10]->GetMaximumBin ()) * 1.1);
     }*/
    hs_ossf_rec_jetFlavour->SetMaximum(hs_ossf_rec_jetFlavour->GetMaximum()*1.2);
    if (histo_signal_50_ossf_rec[10]-> GetBinContent(histo_signal_50_ossf_rec[10]->GetMaximumBin ()) > hs_ossf_rec_jetFlavour-> GetMaximum()){
        hs_ossf_rec_jetFlavour->SetMaximum(histo_signal_50_ossf_rec[10]-> GetBinContent(histo_signal_50_ossf_rec[10]->GetMaximumBin ()) * 2);
    }
    hs_ossf_rec_jetFlavour->Draw("hist");
    histo_signal_50_ossf_rec[10]->SetLineColor(1);
    histo_signal_50_ossf_rec[10]->SetMarkerStyle(21);
    histo_signal_50_ossf_rec[10]->SetMarkerColor(1);
    histo_signal_50_ossf_rec[10]->Draw("histsame");
    histo_signal_20_ossf_rec[10]->SetLineColor(1);
    histo_signal_20_ossf_rec[10]->SetLineStyle(7);
    histo_signal_20_ossf_rec[10]->SetMarkerColor(1);
    histo_signal_20_ossf_rec[10]->Draw("histsame");
    histo_signal_5_ossf_rec[10]->SetLineColor(1);
    histo_signal_5_ossf_rec[10]->SetLineStyle(3);
    histo_signal_5_ossf_rec[10]->SetMarkerColor(1);
    histo_signal_5_ossf_rec[10]->Draw("histsame");
    leg_ossf_jetFlavour = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_jetFlavour->SetHeader("OSSF M_{ll}"); // oFlavourion "C" allows to center the header
    leg_ossf_jetFlavour->AddEntry(histo_dy2_ossf_rec[10],"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_jetFlavour->AddEntry(histo_tt_ossf_rec[10],"ttbar","f");
    leg_ossf_jetFlavour->AddEntry(histo_wg_ossf_rec[10],"W#gamma","f");
    leg_ossf_jetFlavour->AddEntry(histo_wz_ossf_rec[10],"WZ","f");
    leg_ossf_jetFlavour->AddEntry(histo_signal_5_ossf_rec[10],"MN = 5 GeV","l");
    
    leg_ossf_jetFlavour->AddEntry(histo_signal_20_ossf_rec[10],"MN = 20 GeV","l");
    
    leg_ossf_jetFlavour->AddEntry(histo_signal_50_ossf_rec[10],"MN = 50 GeV","l");
    leg_ossf_jetFlavour->Draw();
    hs_ossf_rec_jetFlavour->GetXaxis()->SetTitle("jet Flavour");
    c_st_ossf_jetFlavour->Modified();
    c_st_ossf_jetFlavour->Print("PLOT/c_st_ossf_jetFlavour.root");
    delete c_st_ossf_jetFlavour;
    
    
    TCanvas *c_st_ossf_lepton_flavor  = new TCanvas("c_st_ossf_lepton_flavor ","c_st_ossf_lepton_flavor ",10,10,700,700);
    c_st_ossf_lepton_flavor ->Divide(1,2);
    c_st_ossf_lepton_flavor ->cd(1);
    /*if (histo_signal_50_ossf_rec[10]-> GetBinContent(histo_signal_50_ossf_rec[10]->GetMaximumBin ()) > histo_dy2_ossf_rec[10]-> GetBinContent(histo_dy2_ossf_rec[10]->GetMaximumBin ())){
     hs_ossf_flavor->SetMaximum(histo_signal_50_ossf_rec[10]-> GetBinContent(histo_signal_50_ossf_rec[10]->GetMaximumBin ()) * 1.1);
     }*/
    hs_ossf_flavor->SetMaximum(hs_ossf_flavor->GetMaximum()*1.2);
    if (flavor_plot_signal_50_ossf-> GetBinContent(flavor_plot_signal_50_ossf->GetMaximumBin ()) >hs_ossf_flavor-> GetMaximum()){
        hs_ossf_flavor->SetMaximum(flavor_plot_signal_50_ossf-> GetBinContent(flavor_plot_signal_50_ossf->GetMaximumBin ()) * 2);
    }
    hs_ossf_flavor ->Draw("hist");
    flavor_plot_signal_50_ossf->SetLineColor(1);
    flavor_plot_signal_50_ossf->SetMarkerStyle(21);
    flavor_plot_signal_50_ossf->SetMarkerColor(1);
    flavor_plot_signal_50_ossf->Draw("histsame");
    flavor_plot_signal_20_ossf->SetLineColor(1);
    flavor_plot_signal_20_ossf->SetLineStyle(7);
    flavor_plot_signal_20_ossf->SetMarkerColor(1);
    flavor_plot_signal_20_ossf->Draw("histsame");
    flavor_plot_signal_5_ossf->SetLineColor(1);
    flavor_plot_signal_5_ossf->SetLineStyle(3);
    flavor_plot_signal_5_ossf->SetMarkerColor(1);
    flavor_plot_signal_5_ossf->Draw("histsame");
    leg_ossf_jetFlavour  = new TLegend(0.54,0.50,0.90,0.9);
    leg_ossf_jetFlavour ->SetHeader("OSSF lepton Flavors "); // option "C" allows to center the header
    leg_ossf_jetFlavour ->AddEntry(flavor_plot_dy2_ossf,"DY (M_{ll} >50 GeV/c)","f");
    leg_ossf_jetFlavour ->AddEntry(flavor_plot_tt_ossf,"ttbar","f");
    leg_ossf_jetFlavour ->AddEntry(flavor_plot_wg_ossf,"W#gamma","f");
    leg_ossf_jetFlavour ->AddEntry(flavor_plot_wz_ossf,"WZ","f");
    leg_ossf_jetFlavour ->AddEntry(flavor_plot_signal_5_ossf,"MN = 5 GeV","l");
    
    leg_ossf_jetFlavour ->AddEntry(flavor_plot_signal_20_ossf,"MN = 20 GeV","l");
    leg_ossf_jetFlavour ->AddEntry(flavor_plot_signal_50_ossf,"MN = 50 GeV","l");
    
    leg_ossf_jetFlavour ->Draw();
    hs_ossf_flavor->GetXaxis()->SetNdivisions(-414);
    hs_ossf_flavor->GetYaxis()->SetTitle("Events");
    hs_ossf_flavor->GetXaxis()->SetBinLabel(1,"TOT");
    hs_ossf_flavor->GetXaxis()->SetBinLabel(2,"eee");
    hs_ossf_flavor->GetXaxis()->SetBinLabel(3,"#mu #mu #mu");
    hs_ossf_flavor->GetXaxis()->SetBinLabel(4,"e#mu #mu");
    hs_ossf_flavor->GetXaxis()->SetBinLabel(5,"ee#mu");
    hs_ossf_flavor->GetXaxis()->SetBinLabel(6,"ee#tau");
    hs_ossf_flavor->GetXaxis()->SetBinLabel(7,"e #tau #tau");
    c_st_ossf_lepton_flavor->Modified();
    c_st_ossf_lepton_flavor ->Print("PLOT/c_st_ossf_lepton_flavor .root");
    delete c_st_ossf_lepton_flavor ;
    
    TLegend *leg_n_ossf_pt1,*leg_n_ossf_pt2,*leg_n_ossf_pt3,*leg_n_ossf_pt1_gen,*leg_n_ossf_pt2_gen,*leg_n_ossf_pt3_gen, *leg_n_ossf_met,*leg_n_ossf_mT,*leg_n_ossf_mlll,*leg_n_ossf_mll,*leg_n_ossf_mll_pair, *leg_n_ossf_met_gen,*leg_n_ossf_mT_gen,*leg_n_ossf_mlll_gen,*leg_n_ossf_mll_gen, *leg_n_ossf_mll_pair_gen,
    *leg_n_ossf_nJet, *leg_n_ossf_nbJet, *leg_n_ossf_HT, *leg_n_ossf_jetPt, *leg_n_ossf_jetEta, *leg_n_ossf_jetPhi, *leg_n_ossf_jetFlavour, *leg_n_ossf_flavor;
    
    
    
    TCanvas *c_st_n_ossf_pt = new TCanvas("c_st_n_ossf_pt","c_st_n_ossf_pt",10,10,700,700);
    c_st_n_ossf_pt->Divide(3,2);
    c_st_n_ossf_pt->cd(1);
    hs_n_ossf_rec_pt_l1->SetMaximum(hs_n_ossf_rec_pt_l1->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_kin_rec_l1[0]-> GetBinContent(histo_signal_5_n_ossf_kin_rec_l1[0]->GetMaximumBin ()) > hs_n_ossf_rec_pt_l1-> GetMaximum()){
        hs_n_ossf_rec_pt_l1->SetMaximum(histo_signal_5_n_ossf_kin_rec_l1[0]-> GetBinContent(histo_signal_5_n_ossf_kin_rec_l1[0]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_rec_pt_l1->Draw("hist");
    histo_signal_50_n_ossf_kin_rec_l1[0]->SetLineColor(1);
    histo_signal_50_n_ossf_kin_rec_l1[0]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_kin_rec_l1[0]->SetMarkerColor(1);
    histo_signal_50_n_ossf_kin_rec_l1[0]->Draw("histsame");
    histo_signal_20_n_ossf_kin_rec_l1[0]->SetLineColor(1);
    histo_signal_20_n_ossf_kin_rec_l1[0]->SetLineStyle(7);
    histo_signal_20_n_ossf_kin_rec_l1[0]->SetMarkerColor(1);
    histo_signal_20_n_ossf_kin_rec_l1[0]->Draw("histsame");
    histo_signal_5_n_ossf_kin_rec_l1[0]->SetLineStyle(3);
    histo_signal_5_n_ossf_kin_rec_l1[0]->SetMarkerColor(1);
    histo_signal_5_n_ossf_kin_rec_l1[0]->Draw("histsame");
    leg_n_ossf_pt1 = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_pt1->SetHeader("n_ossf p_{T} leading lepton"); // option "C" al2ows to center the header
    leg_n_ossf_pt1->AddEntry(histo_dy2_n_ossf_kin_rec_l1[0],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_pt1->AddEntry(histo_tt_n_ossf_kin_rec_l1[0],"ttbar","f");
    leg_n_ossf_pt1->AddEntry(histo_wg_n_ossf_kin_rec_l1[0],"W#gamma","f");
    leg_n_ossf_pt1->AddEntry(histo_wz_n_ossf_kin_rec_l1[0],"WZ","f");
    leg_n_ossf_pt1->AddEntry(histo_signal_5_n_ossf_kin_rec_l1[0],"MN = 5 GeV","l");
    leg_n_ossf_pt1->AddEntry(histo_signal_20_n_ossf_kin_rec_l1[0],"MN = 20 GeV","l");
    leg_n_ossf_pt1->AddEntry(histo_signal_50_n_ossf_kin_rec_l1[0],"MN = 50 GeV","l");
    leg_n_ossf_pt1->Draw();
    hs_n_ossf_rec_pt_l1->GetXaxis()->SetTitle("p_{T} (GeV)");
    hs_n_ossf_rec_pt_l1->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_pt->cd(2);
    hs_n_ossf_rec_pt_l2->SetMaximum(hs_n_ossf_rec_pt_l2->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_kin_rec_l2[0]-> GetBinContent(histo_signal_5_n_ossf_kin_rec_l2[0]->GetMaximumBin ()) > hs_n_ossf_rec_pt_l2-> GetMaximum()){
        hs_n_ossf_rec_pt_l2->SetMaximum(histo_signal_5_n_ossf_kin_rec_l2[0]-> GetBinContent(histo_signal_5_n_ossf_kin_rec_l2[0]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_rec_pt_l2->Draw("hist");
    histo_signal_50_n_ossf_kin_rec_l2[0]->SetLineColor(1);
    histo_signal_50_n_ossf_kin_rec_l2[0]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_kin_rec_l2[0]->SetMarkerColor(1);
    histo_signal_50_n_ossf_kin_rec_l2[0]->Draw("histsame");
    histo_signal_20_n_ossf_kin_rec_l2[0]->SetLineColor(1);
    histo_signal_20_n_ossf_kin_rec_l2[0]->SetLineStyle(7);
    histo_signal_20_n_ossf_kin_rec_l2[0]->SetMarkerColor(1);
    histo_signal_20_n_ossf_kin_rec_l2[0]->Draw("histsame");
    histo_signal_5_n_ossf_kin_rec_l2[0]->SetLineColor(1);
    histo_signal_5_n_ossf_kin_rec_l2[0]->SetLineStyle(3);
    histo_signal_5_n_ossf_kin_rec_l2[0]->SetMarkerColor(1);
    histo_signal_5_n_ossf_kin_rec_l2[0]->Draw("histsame");
    leg_n_ossf_pt2 = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_pt2->SetHeader("n_ossf p_{T} subleading lepton"); // option "C" al2ows to center the header
    leg_n_ossf_pt2->AddEntry(histo_dy2_n_ossf_kin_rec_l2[0],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_pt2->AddEntry(histo_tt_n_ossf_kin_rec_l2[0],"ttbar","f");
    leg_n_ossf_pt2->AddEntry(histo_wg_n_ossf_kin_rec_l2[0],"W#gamma","f");
    leg_n_ossf_pt2->AddEntry(histo_wz_n_ossf_kin_rec_l2[0],"WZ","f");
    leg_n_ossf_pt2->AddEntry(histo_signal_5_n_ossf_kin_rec_l2[0],"MN = 5 GeV","l");
    
    leg_n_ossf_pt2->AddEntry(histo_signal_20_n_ossf_kin_rec_l2[0],"MN = 20 GeV","l");
    
    leg_n_ossf_pt2->AddEntry(histo_signal_50_n_ossf_kin_rec_l2[0],"MN = 50 GeV","l");
    leg_n_ossf_pt2->Draw();
    hs_n_ossf_rec_pt_l2->GetXaxis()->SetTitle("p_{T} (GeV)");
    hs_n_ossf_rec_pt_l2->GetYaxis()->SetTitle("Events");
    
    c_st_n_ossf_pt->cd(3);
    hs_n_ossf_rec_pt_l3->SetMaximum(hs_n_ossf_rec_pt_l3->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_kin_rec_l3[0]-> GetBinContent(histo_signal_5_n_ossf_kin_rec_l3[0]->GetMaximumBin ()) > hs_n_ossf_rec_pt_l3-> GetMaximum()){
        hs_n_ossf_rec_pt_l3->SetMaximum(histo_signal_5_n_ossf_kin_rec_l3[0]-> GetBinContent(histo_signal_5_n_ossf_kin_rec_l3[0]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_rec_pt_l3->Draw("hist");
    histo_signal_50_n_ossf_kin_rec_l3[0]->SetLineColor(1);
    histo_signal_50_n_ossf_kin_rec_l3[0]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_kin_rec_l3[0]->SetMarkerColor(1);
    histo_signal_50_n_ossf_kin_rec_l3[0]->Draw("histsame");
    histo_signal_20_n_ossf_kin_rec_l3[0]->SetLineColor(1);
    histo_signal_20_n_ossf_kin_rec_l3[0]->SetLineStyle(7);
    histo_signal_20_n_ossf_kin_rec_l3[0]->SetMarkerColor(1);
    histo_signal_20_n_ossf_kin_rec_l3[0]->Draw("histsame");
    histo_signal_5_n_ossf_kin_rec_l3[0]->SetLineColor(1);
    histo_signal_5_n_ossf_kin_rec_l3[0]->SetLineStyle(3);
    histo_signal_5_n_ossf_kin_rec_l3[0]->SetMarkerColor(1);
    histo_signal_5_n_ossf_kin_rec_l3[0]->Draw("histsame");
    leg_n_ossf_pt3 = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_pt3->SetHeader("n_ossf p_{T} soft lepton"); // option "C" al3ows to center the header
    leg_n_ossf_pt3->AddEntry(histo_dy2_n_ossf_kin_rec_l3[0],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_pt3->AddEntry(histo_tt_n_ossf_kin_rec_l3[0],"ttbar","f");
    leg_n_ossf_pt3->AddEntry(histo_wg_n_ossf_kin_rec_l3[0],"W#gamma","f");
    leg_n_ossf_pt3->AddEntry(histo_wz_n_ossf_kin_rec_l3[0],"WZ","f");
    leg_n_ossf_pt3->AddEntry(histo_signal_5_n_ossf_kin_rec_l3[0],"MN = 5 GeV","l");
    
    leg_n_ossf_pt3->AddEntry(histo_signal_20_n_ossf_kin_rec_l3[0],"MN = 20 GeV","l");
    
    leg_n_ossf_pt3->AddEntry(histo_signal_50_n_ossf_kin_rec_l3[0],"MN = 50 GeV","l");
    leg_n_ossf_pt3->Draw();
    hs_n_ossf_rec_pt_l3->GetXaxis()->SetTitle("p_{T} (GeV)");
    hs_n_ossf_rec_pt_l3->GetYaxis()->SetTitle("Events");
    
    c_st_n_ossf_pt->cd(4);
    hs_n_ossf_gen_pt_l1->SetMaximum(hs_n_ossf_gen_pt_l1->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_kin_gen_l1[0]-> GetBinContent(histo_signal_5_n_ossf_kin_gen_l1[0]->GetMaximumBin ()) > hs_n_ossf_gen_pt_l1-> GetMaximum()){
        hs_n_ossf_gen_pt_l1->SetMaximum(histo_signal_5_n_ossf_kin_gen_l1[0]-> GetBinContent(histo_signal_5_n_ossf_kin_gen_l1[0]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_gen_pt_l1->Draw("hist");
    histo_signal_50_n_ossf_kin_gen_l1[0]->SetLineColor(1);
    histo_signal_50_n_ossf_kin_gen_l1[0]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_kin_gen_l1[0]->SetMarkerColor(1);
    histo_signal_50_n_ossf_kin_gen_l1[0]->Draw("histsame");
    histo_signal_20_n_ossf_kin_gen_l1[0]->SetLineColor(1);
    histo_signal_20_n_ossf_kin_gen_l1[0]->SetLineStyle(7);
    histo_signal_20_n_ossf_kin_gen_l1[0]->SetMarkerColor(1);
    histo_signal_20_n_ossf_kin_gen_l1[0]->Draw("histsame");
    histo_signal_5_n_ossf_kin_gen_l1[0]->SetLineColor(1);
    histo_signal_5_n_ossf_kin_gen_l1[0]->SetLineStyle(3);
    histo_signal_5_n_ossf_kin_gen_l1[0]->SetMarkerColor(1);
    histo_signal_5_n_ossf_kin_gen_l1[0]->Draw("histsame");
    leg_n_ossf_pt1 = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_pt1->SetHeader("n_ossf p_{T} leading lepton gen"); // option "C" al2ows to center the header
    leg_n_ossf_pt1->AddEntry(histo_dy2_n_ossf_kin_gen_l1[0],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_pt1->AddEntry(histo_tt_n_ossf_kin_gen_l1[0],"ttbar","f");
    leg_n_ossf_pt1->AddEntry(histo_wg_n_ossf_kin_gen_l1[0],"W#gamma","f");
    leg_n_ossf_pt1->AddEntry(histo_wz_n_ossf_kin_gen_l1[0],"WZ","f");
    leg_n_ossf_pt1->AddEntry(histo_signal_5_n_ossf_kin_gen_l1[0],"MN = 5 GeV","l");
    
    leg_n_ossf_pt1->AddEntry(histo_signal_20_n_ossf_kin_gen_l1[0],"MN = 20 GeV","l");
    leg_n_ossf_pt1->AddEntry(histo_signal_50_n_ossf_kin_gen_l1[0],"MN = 50 GeV","l");
    leg_n_ossf_pt1->Draw();
    hs_n_ossf_gen_pt_l1->GetXaxis()->SetTitle("p_{T} (GeV)");
    hs_n_ossf_gen_pt_l1->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_pt->cd(5);
    hs_n_ossf_gen_pt_l2->SetMaximum(hs_n_ossf_gen_pt_l2->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_kin_gen_l2[0]-> GetBinContent(histo_signal_5_n_ossf_kin_gen_l2[0]->GetMaximumBin ()) > hs_n_ossf_gen_pt_l2-> GetMaximum()){
        hs_n_ossf_gen_pt_l2->SetMaximum(histo_signal_5_n_ossf_kin_gen_l2[0]-> GetBinContent(histo_signal_5_n_ossf_kin_gen_l2[0]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_gen_pt_l2->Draw("hist");
    histo_signal_50_n_ossf_kin_gen_l2[0]->SetLineColor(1);
    histo_signal_50_n_ossf_kin_gen_l2[0]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_kin_gen_l2[0]->SetMarkerColor(1);
    histo_signal_50_n_ossf_kin_gen_l2[0]->Draw("histsame");
    histo_signal_20_n_ossf_kin_gen_l2[0]->SetLineColor(1);
    histo_signal_20_n_ossf_kin_gen_l2[0]->SetLineStyle(7);
    histo_signal_20_n_ossf_kin_gen_l2[0]->SetMarkerColor(1);
    histo_signal_20_n_ossf_kin_gen_l2[0]->Draw("histsame");
    histo_signal_5_n_ossf_kin_gen_l2[0]->SetLineColor(1);
    histo_signal_5_n_ossf_kin_gen_l2[0]->SetLineStyle(3);
    histo_signal_5_n_ossf_kin_gen_l2[0]->SetMarkerColor(1);
    histo_signal_5_n_ossf_kin_gen_l2[0]->Draw("histsame");
    leg_n_ossf_pt2 = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_pt2->SetHeader("n_ossf p_{T} subleading lepton gen"); // option "C" al2ows to center the header
    leg_n_ossf_pt2->AddEntry(histo_dy2_n_ossf_kin_gen_l2[0],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_pt2->AddEntry(histo_tt_n_ossf_kin_gen_l2[0],"ttbar","f");
    leg_n_ossf_pt2->AddEntry(histo_wg_n_ossf_kin_gen_l2[0],"W#gamma","f");
    leg_n_ossf_pt2->AddEntry(histo_wz_n_ossf_kin_gen_l2[0],"WZ","f");
    leg_n_ossf_pt2->AddEntry(histo_signal_5_n_ossf_kin_gen_l2[0],"MN = 5 GeV","l");
    leg_n_ossf_pt2->AddEntry(histo_signal_20_n_ossf_kin_gen_l2[0],"MN = 20 GeV","l");
    leg_n_ossf_pt2->AddEntry(histo_signal_50_n_ossf_kin_gen_l2[0],"MN = 50 GeV","l");
    leg_n_ossf_pt2->Draw();
    hs_n_ossf_gen_pt_l2->GetXaxis()->SetTitle("p_{T} (GeV)");
    hs_n_ossf_gen_pt_l2->GetYaxis()->SetTitle("Events");
    
    c_st_n_ossf_pt->cd(6);
    hs_n_ossf_gen_pt_l3->SetMaximum(hs_n_ossf_gen_pt_l3->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_kin_gen_l3[0]-> GetBinContent(histo_signal_5_n_ossf_kin_gen_l3[0]->GetMaximumBin ()) > hs_n_ossf_gen_pt_l3-> GetMaximum()){
        hs_n_ossf_gen_pt_l3->SetMaximum(histo_signal_5_n_ossf_kin_gen_l3[0]-> GetBinContent(histo_signal_5_n_ossf_kin_gen_l3[0]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_gen_pt_l3->Draw("hist");
    histo_signal_50_n_ossf_kin_gen_l3[0]->SetLineColor(1);
    histo_signal_50_n_ossf_kin_gen_l3[0]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_kin_gen_l3[0]->SetMarkerColor(1);
    histo_signal_50_n_ossf_kin_gen_l3[0]->Draw("histsame");
    histo_signal_20_n_ossf_kin_gen_l3[0]->SetLineColor(1);
    histo_signal_20_n_ossf_kin_gen_l3[0]->SetLineStyle(7);
    histo_signal_20_n_ossf_kin_gen_l3[0]->SetMarkerColor(1);
    histo_signal_20_n_ossf_kin_gen_l3[0]->Draw("histsame");
    histo_signal_5_n_ossf_kin_gen_l3[0]->SetLineColor(1);
    histo_signal_5_n_ossf_kin_gen_l3[0]->SetLineStyle(3);
    histo_signal_5_n_ossf_kin_gen_l3[0]->SetMarkerColor(1);
    histo_signal_5_n_ossf_kin_gen_l3[0]->Draw("histsame");
    leg_n_ossf_pt3 = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_pt3->SetHeader("n_ossf p_{T} soft lepton gen"); // option "C" al3ows to center the header
    leg_n_ossf_pt3->AddEntry(histo_dy2_n_ossf_kin_gen_l3[0],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_pt3->AddEntry(histo_tt_n_ossf_kin_gen_l3[0],"ttbar","f");
    leg_n_ossf_pt3->AddEntry(histo_wg_n_ossf_kin_gen_l3[0],"W#gamma","f");
    leg_n_ossf_pt3->AddEntry(histo_wz_n_ossf_kin_gen_l3[0],"WZ","f");
    leg_n_ossf_pt3->AddEntry(histo_signal_5_n_ossf_kin_gen_l3[0],"MN = 5 GeV","l");
    
    leg_n_ossf_pt3->AddEntry(histo_signal_20_n_ossf_kin_gen_l3[0],"MN = 20 GeV","l");
    
    leg_n_ossf_pt3->AddEntry(histo_signal_50_n_ossf_kin_gen_l3[0],"MN = 50 GeV","l");
    leg_n_ossf_pt3->Draw();
    hs_n_ossf_gen_pt_l3->GetXaxis()->SetTitle("p_{T} (GeV)");
    hs_n_ossf_gen_pt_l3->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_pt->Modified();
    c_st_n_ossf_pt->Print("PLOT/c_st_n_ossf_pt.root");
    delete c_st_n_ossf_pt;
    
    TCanvas *c_st_n_ossf_met = new TCanvas("c_st_n_ossf_met","c_st_n_ossf_met",10,10,700,700);
    c_st_n_ossf_met->Divide(1,2);
    c_st_n_ossf_met->cd(1);
    /*if (histo_signal_5_n_ossf_rec[0]-> GetBinContent(histo_signal_5_n_ossf_rec[0]->GetMaximumBin ()) > histo_dy2_n_ossf_rec[0]-> GetBinContent(histo_dy2_n_ossf_rec[0]->GetMaximumBin ())){
     hs_n_ossf_rec_met->SetMaximum(histo_signal_5_n_ossf_rec[0]-> GetBinContent(histo_signal_5_n_ossf_rec[0]->GetMaximumBin ()) * 1.1);
     }*/
    hs_n_ossf_rec_met->SetMaximum(hs_n_ossf_rec_met->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_rec[0]-> GetBinContent(histo_signal_5_n_ossf_rec[0]->GetMaximumBin ()) > hs_n_ossf_rec_met-> GetMaximum()){
        hs_n_ossf_rec_met->SetMaximum(histo_signal_5_n_ossf_rec[0]-> GetBinContent(histo_signal_5_n_ossf_rec[0]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_rec_met->Draw("hist");
    histo_signal_50_n_ossf_rec[0]->SetLineColor(1);
    histo_signal_50_n_ossf_rec[0]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_rec[0]->SetMarkerColor(1);
    histo_signal_50_n_ossf_rec[0]->Draw("histsame");
    histo_signal_20_n_ossf_rec[0]->SetLineColor(1);
    histo_signal_20_n_ossf_rec[0]->SetLineStyle(7);
    histo_signal_20_n_ossf_rec[0]->SetMarkerColor(1);
    histo_signal_20_n_ossf_rec[0]->Draw("histsame");
    histo_signal_5_n_ossf_rec[0]->SetLineColor(1);
    histo_signal_5_n_ossf_rec[0]->SetLineStyle(3);
    histo_signal_5_n_ossf_rec[0]->SetMarkerColor(1);
    histo_signal_5_n_ossf_rec[0]->Draw("histsame");
    leg_n_ossf_met = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_met->SetHeader("n_ossf MET"); // option "C" allows to center the header
    leg_n_ossf_met->AddEntry(histo_dy2_n_ossf_rec[0],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_met->AddEntry(histo_tt_n_ossf_rec[0],"ttbar","f");
    leg_n_ossf_met->AddEntry(histo_wg_n_ossf_rec[0],"W#gamma","f");
    leg_n_ossf_met->AddEntry(histo_wz_n_ossf_rec[0],"WZ","f");
    leg_n_ossf_met->AddEntry(histo_signal_5_n_ossf_rec[0],"MN = 5 GeV","l");
    
    leg_n_ossf_met->AddEntry(histo_signal_20_n_ossf_rec[0],"MN = 20 GeV","l");
    
    leg_n_ossf_met->AddEntry(histo_signal_50_n_ossf_rec[0],"MN = 50 GeV","l");
    leg_n_ossf_met->Draw();
    hs_n_ossf_rec_met->GetXaxis()->SetTitle("MET");
    hs_n_ossf_rec_met->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_met->cd(2);
    hs_n_ossf_gen_met->SetMaximum(hs_n_ossf_gen_met->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_gen[0]-> GetBinContent(histo_signal_5_n_ossf_gen[0]->GetMaximumBin ()) > hs_n_ossf_gen_met-> GetMaximum()){
        hs_n_ossf_gen_met->SetMaximum(histo_signal_5_n_ossf_gen[0]-> GetBinContent(histo_signal_5_n_ossf_gen[0]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_gen_met->Draw("hist");
    histo_signal_50_n_ossf_gen[0]->SetLineColor(1);
    histo_signal_50_n_ossf_gen[0]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_gen[0]->SetMarkerColor(1);
    histo_signal_50_n_ossf_gen[0]->Draw("histsame");
    histo_signal_20_n_ossf_gen[0]->SetLineColor(1);
    histo_signal_20_n_ossf_gen[0]->SetLineStyle(7);
    histo_signal_20_n_ossf_gen[0]->SetMarkerColor(1);
    histo_signal_20_n_ossf_gen[0]->Draw("histsame");
    histo_signal_5_n_ossf_gen[0]->SetLineColor(1);
    histo_signal_5_n_ossf_gen[0]->SetLineStyle(3);
    histo_signal_5_n_ossf_gen[0]->SetMarkerColor(1);
    histo_signal_5_n_ossf_gen[0]->Draw("histsame");
    leg_n_ossf_met_gen = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_met_gen->SetHeader("n_ossf MET gen"); // option "C" allows to center the header
    leg_n_ossf_met_gen->AddEntry(histo_dy2_n_ossf_gen[0],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_met_gen->AddEntry(histo_tt_n_ossf_gen[0],"ttbar","f");
    leg_n_ossf_met_gen->AddEntry(histo_wg_n_ossf_gen[0],"W#gamma","f");
    leg_n_ossf_met_gen->AddEntry(histo_wz_n_ossf_gen[0],"WZ","f");
    leg_n_ossf_met_gen->AddEntry(histo_signal_5_n_ossf_gen[0],"MN = 5 GeV","l");
    
    leg_n_ossf_met_gen->AddEntry(histo_signal_20_n_ossf_gen[0],"MN = 20 GeV","l");
    
    leg_n_ossf_met_gen->AddEntry(histo_signal_50_n_ossf_gen[0],"MN = 50 GeV","l");
    leg_n_ossf_met_gen->Draw();
    hs_n_ossf_gen_met->GetXaxis()->SetTitle("MET gen");
    hs_n_ossf_gen_met->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_met->Modified();
    c_st_n_ossf_met->Print("PLOT/c_st_n_ossf_met.root");
    delete c_st_n_ossf_met;
    
    TCanvas *c_st_n_ossf_mT = new TCanvas("c_st_n_ossf_mT","c_st_n_ossf_mT",10,10,700,700);
    c_st_n_ossf_mT->Divide(1,2);
    c_st_n_ossf_mT->cd(1);
    /*if (histo_signal_5_n_ossf_rec[1]-> GetBinContent(histo_signal_5_n_ossf_rec[1]->GetMaximumBin ()) > histo_dy2_n_ossf_rec[1]-> GetBinContent(histo_dy2_n_ossf_rec[1]->GetMaximumBin ())){
     hs_n_ossf_rec_mT->SetMaximum(histo_signal_5_n_ossf_rec[1]-> GetBinContent(histo_signal_5_n_ossf_rec[1]->GetMaximumBin ()) * 1.1);
     }*/
    hs_n_ossf_rec_mT->SetMaximum(hs_n_ossf_rec_mT->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_rec[1]-> GetBinContent(histo_signal_5_n_ossf_rec[1]->GetMaximumBin ()) > hs_n_ossf_rec_mT-> GetMaximum()){
        hs_n_ossf_rec_mT->SetMaximum(histo_signal_5_n_ossf_rec[1]-> GetBinContent(histo_signal_5_n_ossf_rec[1]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_rec_mT->Draw("hist");
    histo_signal_50_n_ossf_rec[1]->SetLineColor(1);
    histo_signal_50_n_ossf_rec[1]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_rec[1]->SetMarkerColor(1);
    histo_signal_50_n_ossf_rec[1]->Draw("histsame");
    histo_signal_20_n_ossf_rec[1]->SetLineColor(1);
    histo_signal_20_n_ossf_rec[1]->SetLineStyle(7);
    histo_signal_20_n_ossf_rec[1]->SetMarkerColor(1);
    histo_signal_20_n_ossf_rec[1]->Draw("histsame");
    histo_signal_5_n_ossf_rec[1]->SetLineColor(1);
    histo_signal_5_n_ossf_rec[1]->SetLineStyle(3);
    histo_signal_5_n_ossf_rec[1]->SetMarkerColor(1);
    histo_signal_5_n_ossf_rec[1]->Draw("histsame");
    leg_n_ossf_mT = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_mT->SetHeader("n_ossf mT"); // option "C" allows to center the header
    leg_n_ossf_mT->AddEntry(histo_dy2_n_ossf_rec[1],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_mT->AddEntry(histo_tt_n_ossf_rec[1],"ttbar","f");
    leg_n_ossf_mT->AddEntry(histo_wg_n_ossf_rec[1],"W#gamma","f");
    leg_n_ossf_mT->AddEntry(histo_wz_n_ossf_rec[1],"WZ","f");
    leg_n_ossf_mT->AddEntry(histo_signal_5_n_ossf_rec[1],"MN = 5 GeV","l");
    
    leg_n_ossf_mT->AddEntry(histo_signal_20_n_ossf_rec[1],"MN = 20 GeV","l");
    
    leg_n_ossf_mT->AddEntry(histo_signal_50_n_ossf_rec[1],"MN = 50 GeV","l");
    leg_n_ossf_mT->Draw();
    hs_n_ossf_rec_mT->GetXaxis()->SetTitle("mT");
    hs_n_ossf_rec_mT->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_mT->cd(2);
    hs_n_ossf_gen_mT->SetMaximum(hs_n_ossf_gen_mT->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_gen[1]-> GetBinContent(histo_signal_5_n_ossf_gen[1]->GetMaximumBin ()) > hs_n_ossf_gen_mT-> GetMaximum()){
        hs_n_ossf_gen_mT->SetMaximum(histo_signal_5_n_ossf_gen[1]-> GetBinContent(histo_signal_5_n_ossf_gen[1]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_gen_mT->Draw("hist");
    histo_signal_50_n_ossf_gen[1]->SetLineColor(1);
    histo_signal_50_n_ossf_gen[1]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_gen[1]->SetMarkerColor(1);
    histo_signal_50_n_ossf_gen[1]->Draw("histsame");
    histo_signal_20_n_ossf_gen[1]->SetLineColor(1);
    histo_signal_20_n_ossf_gen[1]->SetLineStyle(7);
    histo_signal_20_n_ossf_gen[1]->SetMarkerColor(1);
    histo_signal_20_n_ossf_gen[1]->Draw("histsame");
    histo_signal_5_n_ossf_gen[1]->SetLineColor(1);
    histo_signal_5_n_ossf_gen[1]->SetLineStyle(3);
    histo_signal_5_n_ossf_gen[1]->SetMarkerColor(1);
    histo_signal_5_n_ossf_gen[1]->Draw("histsame");
    leg_n_ossf_mT_gen = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_mT_gen->SetHeader("n_ossf mT gen"); // option "C" allows to center the header
    leg_n_ossf_mT_gen->AddEntry(histo_dy2_n_ossf_gen[1],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_mT_gen->AddEntry(histo_tt_n_ossf_gen[1],"ttbar","f");
    leg_n_ossf_mT_gen->AddEntry(histo_wg_n_ossf_gen[1],"W#gamma","f");
    leg_n_ossf_mT_gen->AddEntry(histo_wz_n_ossf_gen[1],"WZ","f");
    leg_n_ossf_mT_gen->AddEntry(histo_signal_5_n_ossf_gen[1],"MN = 5 GeV","l");
    
    leg_n_ossf_mT_gen->AddEntry(histo_signal_20_n_ossf_gen[1],"MN = 20 GeV","l");
    
    leg_n_ossf_mT_gen->AddEntry(histo_signal_50_n_ossf_gen[1],"MN = 50 GeV","l");
    leg_n_ossf_mT_gen->Draw();
    hs_n_ossf_gen_mT->GetXaxis()->SetTitle("mT gen");
    hs_n_ossf_gen_mT->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_mT->Modified();
    c_st_n_ossf_mT->Print("PLOT/c_st_n_ossf_mT.root");
    delete c_st_n_ossf_mT;
    
    TCanvas *c_st_n_ossf_mlll = new TCanvas("c_st_n_ossf_mlll","c_st_n_ossf_mlll",10,10,700,700);
    c_st_n_ossf_mlll->Divide(1,2);
    c_st_n_ossf_mlll->cd(1);
    /*if (histo_signal_5_n_ossf_rec[2]-> GetBinContent(histo_signal_5_n_ossf_rec[2]->GetMaximumBin ()) > histo_dy2_n_ossf_rec[2]-> GetBinContent(histo_dy2_n_ossf_rec[2]->GetMaximumBin ())){
     hs_n_ossf_rec_mlll->SetMaximum(histo_signal_5_n_ossf_rec[2]-> GetBinContent(histo_signal_5_n_ossf_rec[2]->GetMaximumBin ()) * 1.1);
     }*/
    hs_n_ossf_rec_mlll->SetMaximum(hs_n_ossf_rec_mlll->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_rec[2]-> GetBinContent(histo_signal_5_n_ossf_rec[2]->GetMaximumBin ()) > hs_n_ossf_rec_mlll-> GetMaximum()){
        hs_n_ossf_rec_mlll->SetMaximum(histo_signal_5_n_ossf_rec[2]-> GetBinContent(histo_signal_5_n_ossf_rec[2]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_rec_mlll->Draw("hist");
    histo_signal_50_n_ossf_rec[2]->SetLineColor(1);
    histo_signal_50_n_ossf_rec[2]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_rec[2]->SetMarkerColor(1);
    histo_signal_50_n_ossf_rec[2]->Draw("histsame");
    histo_signal_20_n_ossf_rec[2]->SetLineColor(1);
    histo_signal_20_n_ossf_rec[2]->SetLineStyle(7);
    histo_signal_20_n_ossf_rec[2]->SetMarkerColor(1);
    histo_signal_20_n_ossf_rec[2]->Draw("histsame");
    histo_signal_5_n_ossf_rec[2]->SetLineColor(1);
    histo_signal_5_n_ossf_rec[2]->SetLineStyle(3);
    histo_signal_5_n_ossf_rec[2]->SetMarkerColor(1);
    histo_signal_5_n_ossf_rec[2]->Draw("histsame");
    leg_n_ossf_mlll = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_mlll->SetHeader("n_ossf mlll"); // option "C" allows to center the header
    leg_n_ossf_mlll->AddEntry(histo_dy2_n_ossf_rec[2],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_mlll->AddEntry(histo_tt_n_ossf_rec[2],"ttbar","f");
    leg_n_ossf_mlll->AddEntry(histo_wg_n_ossf_rec[2],"W#gamma","f");
    leg_n_ossf_mlll->AddEntry(histo_wz_n_ossf_rec[2],"WZ","f");
    leg_n_ossf_mlll->AddEntry(histo_signal_5_n_ossf_rec[2],"MN = 5 GeV","l");
    
    leg_n_ossf_mlll->AddEntry(histo_signal_20_n_ossf_rec[2],"MN = 20 GeV","l");
    
    leg_n_ossf_mlll->AddEntry(histo_signal_50_n_ossf_rec[2],"MN = 50 GeV","l");
    leg_n_ossf_mlll->Draw();
    hs_n_ossf_rec_mlll->GetXaxis()->SetTitle("M_{lll}");
    hs_n_ossf_rec_mlll->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_mlll->cd(2);
    hs_n_ossf_gen_mlll->SetMaximum(hs_n_ossf_gen_mlll->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_gen[2]-> GetBinContent(histo_signal_5_n_ossf_gen[2]->GetMaximumBin ()) > hs_n_ossf_gen_mlll-> GetMaximum()){
        hs_n_ossf_gen_mlll->SetMaximum(histo_signal_5_n_ossf_gen[2]-> GetBinContent(histo_signal_5_n_ossf_gen[2]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_gen_mlll->Draw("hist");
    histo_signal_50_n_ossf_gen[2]->SetLineColor(1);
    histo_signal_50_n_ossf_gen[2]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_gen[2]->SetMarkerColor(1);
    histo_signal_50_n_ossf_gen[2]->Draw("histsame");
    histo_signal_20_n_ossf_gen[2]->SetLineColor(1);
    histo_signal_20_n_ossf_gen[2]->SetLineStyle(7);
    histo_signal_20_n_ossf_gen[2]->SetMarkerColor(1);
    histo_signal_20_n_ossf_gen[2]->Draw("histsame");
    histo_signal_5_n_ossf_gen[2]->SetLineColor(1);
    histo_signal_5_n_ossf_gen[2]->SetLineStyle(3);
    histo_signal_5_n_ossf_gen[2]->SetMarkerColor(1);
    histo_signal_5_n_ossf_gen[2]->Draw("histsame");
    leg_n_ossf_mlll_gen = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_mlll_gen->SetHeader("n_ossf mlll gen"); // option "C" allows to center the header
    leg_n_ossf_mlll_gen->AddEntry(histo_dy2_n_ossf_gen[2],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_mlll_gen->AddEntry(histo_tt_n_ossf_gen[2],"ttbar","f");
    leg_n_ossf_mlll_gen->AddEntry(histo_wg_n_ossf_gen[2],"W#gamma","f");
    leg_n_ossf_mlll_gen->AddEntry(histo_wz_n_ossf_gen[2],"WZ","f");
    leg_n_ossf_mlll_gen->AddEntry(histo_signal_5_n_ossf_gen[2],"MN = 5 GeV","l");
    
    leg_n_ossf_mlll_gen->AddEntry(histo_signal_20_n_ossf_gen[2],"MN = 20 GeV","l");
    
    leg_n_ossf_mlll_gen->AddEntry(histo_signal_50_n_ossf_gen[2],"MN = 50 GeV","l");
    leg_n_ossf_mlll_gen->Draw();
    hs_n_ossf_gen_mlll->GetXaxis()->SetTitle("M_{lll} gen");
    hs_n_ossf_gen_mlll->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_mlll->Modified();
    c_st_n_ossf_mlll->Print("PLOT/c_st_n_ossf_mlll.root");
    delete c_st_n_ossf_mlll;
    
    TCanvas *c_st_n_ossf_mll = new TCanvas("c_st_n_ossf_M_{ll}","c_st_n_ossf_M_{ll}",10,10,700,700);
    c_st_n_ossf_mll->Divide(1,2);
    c_st_n_ossf_mll->cd(1);
    /*if (histo_signal_5_n_ossf_rec[3]-> GetBinContent(histo_signal_5_n_ossf_rec[3]->GetMaximumBin ()) > histo_dy2_n_ossf_rec[3]-> GetBinContent(histo_dy2_n_ossf_rec[3]->GetMaximumBin ())){
     hs_n_ossf_rec_mll->SetMaximum(histo_signal_5_n_ossf_rec[3]-> GetBinContent(histo_signal_5_n_ossf_rec[3]->GetMaximumBin ()) * 1.1);
     }*/
    hs_n_ossf_rec_mll->SetMaximum(hs_n_ossf_rec_mll->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_rec[3]-> GetBinContent(histo_signal_5_n_ossf_rec[3]->GetMaximumBin ()) > hs_n_ossf_rec_mll-> GetMaximum()){
        hs_n_ossf_rec_mll->SetMaximum(histo_signal_5_n_ossf_rec[3]-> GetBinContent(histo_signal_5_n_ossf_rec[3]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_rec_mll->Draw("hist");
    histo_signal_50_n_ossf_rec[3]->SetLineColor(1);
    histo_signal_50_n_ossf_rec[3]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_rec[3]->SetMarkerColor(1);
    histo_signal_50_n_ossf_rec[3]->Draw("histsame");
    histo_signal_20_n_ossf_rec[3]->SetLineColor(1);
    histo_signal_20_n_ossf_rec[3]->SetLineStyle(7);
    histo_signal_20_n_ossf_rec[3]->SetMarkerColor(1);
    histo_signal_20_n_ossf_rec[3]->Draw("histsame");
    histo_signal_5_n_ossf_rec[3]->SetLineColor(1);
    histo_signal_5_n_ossf_rec[3]->SetLineStyle(3);
    histo_signal_5_n_ossf_rec[3]->SetMarkerColor(1);
    histo_signal_5_n_ossf_rec[3]->Draw("histsame");
    leg_n_ossf_mll = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_mll->SetHeader("n_ossf M_{ll}"); // option "C" allows to center the header
    leg_n_ossf_mll->AddEntry(histo_dy2_n_ossf_rec[3],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_mll->AddEntry(histo_tt_n_ossf_rec[3],"ttbar","f");
    leg_n_ossf_mll->AddEntry(histo_wg_n_ossf_rec[3],"W#gamma","f");
    leg_n_ossf_mll->AddEntry(histo_wz_n_ossf_rec[3],"WZ","f");
    leg_n_ossf_mll->AddEntry(histo_signal_5_n_ossf_rec[3],"MN = 5 GeV","l");
    
    leg_n_ossf_mll->AddEntry(histo_signal_20_n_ossf_rec[3],"MN = 20 GeV","l");
    
    leg_n_ossf_mll->AddEntry(histo_signal_50_n_ossf_rec[3],"MN = 50 GeV","l");
    leg_n_ossf_mll->Draw();
    hs_n_ossf_rec_mll->GetXaxis()->SetTitle("M_{ll}");
    hs_n_ossf_rec_mll->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_mll->cd(2);
    hs_n_ossf_gen_mll->SetMaximum(hs_n_ossf_gen_mll->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_gen[3]-> GetBinContent(histo_signal_5_n_ossf_gen[3]->GetMaximumBin ()) > hs_n_ossf_gen_mll-> GetMaximum()){
        hs_n_ossf_gen_mll->SetMaximum(histo_signal_5_n_ossf_gen[3]-> GetBinContent(histo_signal_5_n_ossf_gen[3]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_gen_mll->Draw("hist");
    histo_signal_50_n_ossf_gen[3]->SetLineColor(1);
    histo_signal_50_n_ossf_gen[3]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_gen[3]->SetMarkerColor(1);
    histo_signal_50_n_ossf_gen[3]->Draw("histsame");
    histo_signal_20_n_ossf_gen[3]->SetLineColor(1);
    histo_signal_20_n_ossf_gen[3]->SetLineStyle(7);
    histo_signal_20_n_ossf_gen[3]->SetMarkerColor(1);
    histo_signal_20_n_ossf_gen[3]->Draw("histsame");
    histo_signal_5_n_ossf_gen[3]->SetLineColor(1);
    histo_signal_5_n_ossf_gen[3]->SetLineStyle(3);
    histo_signal_5_n_ossf_gen[3]->SetMarkerColor(1);
    histo_signal_5_n_ossf_gen[3]->Draw("histsame");
    leg_n_ossf_mll_gen = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_mll_gen->SetHeader("n_ossf mll gen"); // option "C" allows to center the header
    leg_n_ossf_mll_gen->AddEntry(histo_dy2_n_ossf_gen[3],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_mll_gen->AddEntry(histo_tt_n_ossf_gen[3],"ttbar","f");
    leg_n_ossf_mll_gen->AddEntry(histo_wg_n_ossf_gen[3],"W#gamma","f");
    leg_n_ossf_mll_gen->AddEntry(histo_wz_n_ossf_gen[3],"WZ","f");
    leg_n_ossf_mll_gen->AddEntry(histo_signal_5_n_ossf_gen[3],"MN = 5 GeV","l");
    
    leg_n_ossf_mll_gen->AddEntry(histo_signal_20_n_ossf_gen[3],"MN = 20 GeV","l");
    
    leg_n_ossf_mll_gen->AddEntry(histo_signal_50_n_ossf_gen[3],"MN = 50 GeV","l");
    leg_n_ossf_mll_gen->Draw();
    hs_n_ossf_gen_mll->GetXaxis()->SetTitle("M_{ll} gen");
    hs_n_ossf_gen_mll->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_mll->Modified();
    c_st_n_ossf_mll->Print("PLOT/c_st_n_ossf_mll.root");
    delete c_st_n_ossf_mll;
    
    TCanvas *c_st_n_ossf_mll_pair = new TCanvas("c_st_n_ossf_M_{ll}","c_st_n_ossf_M_{ll}",10,10,700,700);
    c_st_n_ossf_mll_pair->Divide(1,2);
    c_st_n_ossf_mll_pair->cd(1);
    /*if (histo_signal_5_n_ossf_rec[11]-> GetBinContent(histo_signal_5_n_ossf_rec[11]->GetMaximumBin ()) > histo_dy2_n_ossf_rec[11]-> GetBinContent(histo_dy2_n_ossf_rec[11]->GetMaximumBin ())){
     hs_n_ossf_rec_mll_pair->SetMaximum(histo_signal_5_n_ossf_rec[11]-> GetBinContent(histo_signal_5_n_ossf_rec[11]->GetMaximumBin ()) * 1.1);
     }*/
    hs_n_ossf_rec_mll_pair->SetMaximum(hs_n_ossf_rec_mll_pair->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_rec[11]-> GetBinContent(histo_signal_5_n_ossf_rec[11]->GetMaximumBin ()) > hs_n_ossf_rec_mll_pair-> GetMaximum()){
        hs_n_ossf_rec_mll_pair->SetMaximum(histo_signal_5_n_ossf_rec[11]-> GetBinContent(histo_signal_5_n_ossf_rec[11]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_rec_mll_pair->Draw("hist");
    histo_signal_50_n_ossf_rec[11]->SetLineColor(1);
    histo_signal_50_n_ossf_rec[11]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_rec[11]->SetMarkerColor(1);
    histo_signal_50_n_ossf_rec[11]->Draw("histsame");
    histo_signal_20_n_ossf_rec[11]->SetLineColor(1);
    histo_signal_20_n_ossf_rec[11]->SetLineStyle(7);
    histo_signal_20_n_ossf_rec[11]->SetMarkerColor(1);
    histo_signal_20_n_ossf_rec[11]->Draw("histsame");
    histo_signal_5_n_ossf_rec[11]->SetLineColor(1);
    histo_signal_5_n_ossf_rec[11]->SetLineStyle(3);
    histo_signal_5_n_ossf_rec[11]->SetMarkerColor(1);
    histo_signal_5_n_ossf_rec[11]->Draw("histsame");
    leg_n_ossf_mll_pair = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_mll_pair->SetHeader("n_ossf M_{ll}"); // option "C" allows to center the header
    leg_n_ossf_mll_pair->AddEntry(histo_dy2_n_ossf_rec[11],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_mll_pair->AddEntry(histo_tt_n_ossf_rec[11],"ttbar","f");
    leg_n_ossf_mll_pair->AddEntry(histo_wg_n_ossf_rec[11],"W#gamma","f");
    leg_n_ossf_mll_pair->AddEntry(histo_wz_n_ossf_rec[11],"WZ","f");
    leg_n_ossf_mll_pair->AddEntry(histo_signal_5_n_ossf_rec[11],"MN = 5 GeV","l");
    
    leg_n_ossf_mll_pair->AddEntry(histo_signal_20_n_ossf_rec[11],"MN = 20 GeV","l");
    
    leg_n_ossf_mll_pair->AddEntry(histo_signal_50_n_ossf_rec[11],"MN = 50 GeV","l");
    leg_n_ossf_mll_pair->Draw();
    hs_n_ossf_rec_mll_pair->GetXaxis()->SetTitle("M_{ll} (n_ossf pair) ");
    hs_n_ossf_rec_mll_pair->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_mll_pair->cd(2);
    hs_n_ossf_gen_mll_pair->SetMaximum(hs_n_ossf_gen_mll_pair->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_gen[4]-> GetBinContent(histo_signal_5_n_ossf_gen[4]->GetMaximumBin ()) > hs_n_ossf_gen_mll_pair-> GetMaximum()){
        hs_n_ossf_gen_mll_pair->SetMaximum(histo_signal_5_n_ossf_gen[4]-> GetBinContent(histo_signal_5_n_ossf_gen[4]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_gen_mll_pair->Draw("hist");
    histo_signal_50_n_ossf_gen[4]->SetLineColor(1);
    histo_signal_50_n_ossf_gen[4]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_gen[4]->SetMarkerColor(1);
    histo_signal_50_n_ossf_gen[4]->Draw("histsame");
    histo_signal_20_n_ossf_gen[4]->SetLineColor(1);
    histo_signal_20_n_ossf_gen[4]->SetLineStyle(7);
    histo_signal_20_n_ossf_gen[4]->SetMarkerColor(1);
    histo_signal_20_n_ossf_gen[4]->Draw("histsame");
    histo_signal_5_n_ossf_gen[4]->SetLineColor(1);
    histo_signal_5_n_ossf_gen[4]->SetLineStyle(3);
    histo_signal_5_n_ossf_gen[4]->SetMarkerColor(1);
    histo_signal_5_n_ossf_gen[4]->Draw("histsame");
    leg_n_ossf_mll_pair_gen = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_mll_pair_gen->SetHeader("n_ossf mll_pair gen"); // option "C" allows to center the header
    leg_n_ossf_mll_pair_gen->AddEntry(histo_dy2_n_ossf_gen[4],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_mll_pair_gen->AddEntry(histo_tt_n_ossf_gen[4],"ttbar","f");
    leg_n_ossf_mll_pair_gen->AddEntry(histo_wg_n_ossf_gen[4],"W#gamma","f");
    leg_n_ossf_mll_pair_gen->AddEntry(histo_wz_n_ossf_gen[4],"WZ","f");
    leg_n_ossf_mll_pair_gen->AddEntry(histo_signal_5_n_ossf_gen[4],"MN = 5 GeV","l");
    
    leg_n_ossf_mll_pair_gen->AddEntry(histo_signal_20_n_ossf_gen[4],"MN = 20 GeV","l");
    
    leg_n_ossf_mll_pair_gen->AddEntry(histo_signal_50_n_ossf_gen[4],"MN = 50 GeV","l");
    leg_n_ossf_mll_pair_gen->Draw();
    hs_n_ossf_gen_mll_pair->GetXaxis()->SetTitle("M_{ll} (n_ossf pair)  gen");
    hs_n_ossf_gen_mll_pair->GetYaxis()->SetTitle("Events");
    c_st_n_ossf_mll_pair->Modified();
    c_st_n_ossf_mll_pair->Print("PLOT/c_st_n_ossf_mll_pair.root");
    delete c_st_n_ossf_mll_pair;
    
    TCanvas *c_st_n_ossf_nJet = new TCanvas("c_st_n_ossf_njet}","c_st_n_ossf_njet",10,10,700,700);
    c_st_n_ossf_nJet->Divide(1,2);
    c_st_n_ossf_nJet->cd(1);
    /*if (histo_signal_5_n_ossf_rec[4]-> GetBinContent(histo_signal_5_n_ossf_rec[4]->GetMaximumBin ()) > histo_dy2_n_ossf_rec[4]-> GetBinContent(histo_dy2_n_ossf_rec[4]->GetMaximumBin ())){
     hs_n_ossf_rec_nJet->SetMaximum(histo_signal_5_n_ossf_rec[4]-> GetBinContent(histo_signal_5_n_ossf_rec[4]->GetMaximumBin ()) * 1.1);
     }*/
    hs_n_ossf_rec_nJet->SetMaximum(hs_n_ossf_rec_nJet->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_rec[4]-> GetBinContent(histo_signal_5_n_ossf_rec[4]->GetMaximumBin ()) > hs_n_ossf_rec_nJet-> GetMaximum()){
        hs_n_ossf_rec_nJet->SetMaximum(histo_signal_5_n_ossf_rec[4]-> GetBinContent(histo_signal_5_n_ossf_rec[4]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_rec_nJet->Draw("hist");
    histo_signal_50_n_ossf_rec[4]->SetLineColor(1);
    histo_signal_50_n_ossf_rec[4]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_rec[4]->SetMarkerColor(1);
    histo_signal_50_n_ossf_rec[4]->Draw("histsame");
    histo_signal_20_n_ossf_rec[4]->SetLineColor(1);
    histo_signal_20_n_ossf_rec[4]->SetLineStyle(7);
    histo_signal_20_n_ossf_rec[4]->SetMarkerColor(1);
    histo_signal_20_n_ossf_rec[4]->Draw("histsame");
    histo_signal_5_n_ossf_rec[4]->SetLineColor(1);
    histo_signal_5_n_ossf_rec[4]->SetLineStyle(3);
    histo_signal_5_n_ossf_rec[4]->SetMarkerColor(1);
    histo_signal_5_n_ossf_rec[4]->Draw("histsame");
    leg_n_ossf_nJet = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_nJet->SetHeader("n_ossf njet"); // option "C" allows to center the header
    leg_n_ossf_nJet->AddEntry(histo_dy2_n_ossf_rec[4],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_nJet->AddEntry(histo_tt_n_ossf_rec[4],"ttbar","f");
    leg_n_ossf_nJet->AddEntry(histo_wg_n_ossf_rec[4],"W#gamma","f");
    leg_n_ossf_nJet->AddEntry(histo_wz_n_ossf_rec[4],"WZ","f");
    leg_n_ossf_nJet->AddEntry(histo_signal_5_n_ossf_rec[4],"MN = 5 GeV","l");
    
    leg_n_ossf_nJet->AddEntry(histo_signal_20_n_ossf_rec[4],"MN = 20 GeV","l");
    
    leg_n_ossf_nJet->AddEntry(histo_signal_50_n_ossf_rec[4],"MN = 50 GeV","l");
    leg_n_ossf_nJet->Draw();
    hs_n_ossf_rec_nJet->GetXaxis()->SetTitle("N Jet");
    c_st_n_ossf_nJet->Modified();
    c_st_n_ossf_nJet->Print("PLOT/c_st_n_ossf_nJet.root");
    delete c_st_n_ossf_nJet;
    
    
    TCanvas *c_st_n_ossf_nbJet = new TCanvas("c_st_n_ossf_M_{ll}","c_st_n_ossf_M_{ll}",10,10,700,700);
    c_st_n_ossf_nbJet->Divide(1,2);
    c_st_n_ossf_nbJet->cd(1);
    /*if (histo_signal_5_n_ossf_rec[5]-> GetBinContent(histo_signal_5_n_ossf_rec[5]->GetMaximumBin ()) > histo_dy2_n_ossf_rec[5]-> GetBinContent(histo_dy2_n_ossf_rec[5]->GetMaximumBin ())){
     hs_n_ossf_rec_nbJet->SetMaximum(histo_signal_5_n_ossf_rec[5]-> GetBinContent(histo_signal_5_n_ossf_rec[5]->GetMaximumBin ()) * 1.1);
     }*/
    hs_n_ossf_rec_nbJet->SetMaximum(hs_n_ossf_rec_nbJet->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_rec[5]-> GetBinContent(histo_signal_5_n_ossf_rec[5]->GetMaximumBin ()) > hs_n_ossf_rec_nbJet-> GetMaximum()){
        hs_n_ossf_rec_nbJet->SetMaximum(histo_signal_5_n_ossf_rec[5]-> GetBinContent(histo_signal_5_n_ossf_rec[5]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_rec_nbJet->Draw("hist");
    histo_signal_50_n_ossf_rec[5]->SetLineColor(1);
    histo_signal_50_n_ossf_rec[5]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_rec[5]->SetMarkerColor(1);
    histo_signal_50_n_ossf_rec[5]->Draw("histsame");
    histo_signal_20_n_ossf_rec[5]->SetLineColor(1);
    histo_signal_20_n_ossf_rec[5]->SetLineStyle(7);
    histo_signal_20_n_ossf_rec[5]->SetMarkerColor(1);
    histo_signal_20_n_ossf_rec[5]->Draw("histsame");
    histo_signal_5_n_ossf_rec[5]->SetLineColor(1);
    histo_signal_5_n_ossf_rec[5]->SetLineStyle(3);
    histo_signal_5_n_ossf_rec[5]->SetMarkerColor(1);
    histo_signal_5_n_ossf_rec[5]->Draw("histsame");
    leg_n_ossf_nbJet = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_nbJet->SetHeader("n_ossf M_{ll}"); // option "C" allows to center the header
    leg_n_ossf_nbJet->AddEntry(histo_dy2_n_ossf_rec[5],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_nbJet->AddEntry(histo_tt_n_ossf_rec[5],"ttbar","f");
    leg_n_ossf_nbJet->AddEntry(histo_wg_n_ossf_rec[5],"W#gamma","f");
    leg_n_ossf_nbJet->AddEntry(histo_wz_n_ossf_rec[5],"WZ","f");
    leg_n_ossf_nbJet->AddEntry(histo_signal_5_n_ossf_rec[5],"MN = 5 GeV","l");
    
    leg_n_ossf_nbJet->AddEntry(histo_signal_20_n_ossf_rec[5],"MN = 20 GeV","l");
    
    leg_n_ossf_nbJet->AddEntry(histo_signal_50_n_ossf_rec[5],"MN = 50 GeV","l");
    leg_n_ossf_nbJet->Draw();
    hs_n_ossf_rec_nbJet->GetXaxis()->SetTitle("N bJets");
    c_st_n_ossf_nbJet->Modified();
    c_st_n_ossf_nbJet->Print("PLOT/c_st_n_ossf_nbJet.root");
    delete c_st_n_ossf_nbJet;
    
    TCanvas *c_st_n_ossf_HT = new TCanvas("c_st_n_ossf_M_{ll}","c_st_n_ossf_M_{ll}",10,10,700,700);
    c_st_n_ossf_HT->Divide(1,2);
    c_st_n_ossf_HT->cd(1);
    /*if (histo_signal_5_n_ossf_rec[6]-> GetBinContent(histo_signal_5_n_ossf_rec[6]->GetMaximumBin ()) > histo_dy2_n_ossf_rec[6]-> GetBinContent(histo_dy2_n_ossf_rec[6]->GetMaximumBin ())){
     hs_n_ossf_rec_HT->SetMaximum(histo_signal_5_n_ossf_rec[6]-> GetBinContent(histo_signal_5_n_ossf_rec[6]->GetMaximumBin ()) * 1.1);
     }*/
    hs_n_ossf_rec_HT->SetMaximum(hs_n_ossf_rec_HT->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_rec[6]-> GetBinContent(histo_signal_5_n_ossf_rec[6]->GetMaximumBin ()) > hs_n_ossf_rec_HT-> GetMaximum()){
        hs_n_ossf_rec_HT->SetMaximum(histo_signal_5_n_ossf_rec[6]-> GetBinContent(histo_signal_5_n_ossf_rec[6]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_rec_HT->Draw("hist");
    histo_signal_50_n_ossf_rec[6]->SetLineColor(1);
    histo_signal_50_n_ossf_rec[6]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_rec[6]->SetMarkerColor(1);
    histo_signal_50_n_ossf_rec[6]->Draw("histsame");
    histo_signal_20_n_ossf_rec[6]->SetLineColor(1);
    histo_signal_20_n_ossf_rec[6]->SetLineStyle(7);
    histo_signal_20_n_ossf_rec[6]->SetMarkerColor(1);
    histo_signal_20_n_ossf_rec[6]->Draw("histsame");
    histo_signal_5_n_ossf_rec[6]->SetLineColor(1);
    histo_signal_5_n_ossf_rec[6]->SetLineStyle(3);
    histo_signal_5_n_ossf_rec[6]->SetMarkerColor(1);
    histo_signal_5_n_ossf_rec[6]->Draw("histsame");
    leg_n_ossf_HT = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_HT->SetHeader("n_ossf M_{ll}"); // option "C" allows to center the header
    leg_n_ossf_HT->AddEntry(histo_dy2_n_ossf_rec[6],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_HT->AddEntry(histo_tt_n_ossf_rec[6],"ttbar","f");
    leg_n_ossf_HT->AddEntry(histo_wg_n_ossf_rec[6],"W#gamma","f");
    leg_n_ossf_HT->AddEntry(histo_wz_n_ossf_rec[6],"WZ","f");
    leg_n_ossf_HT->AddEntry(histo_signal_5_n_ossf_rec[6],"MN = 5 GeV","l");
    
    leg_n_ossf_HT->AddEntry(histo_signal_20_n_ossf_rec[6],"MN = 20 GeV","l");
    
    leg_n_ossf_HT->AddEntry(histo_signal_50_n_ossf_rec[6],"MN = 50 GeV","l");
    leg_n_ossf_HT->Draw();
    hs_n_ossf_rec_HT->GetXaxis()->SetTitle("HT");
    c_st_n_ossf_HT->Modified();
    c_st_n_ossf_HT->Print("PLOT/c_st_n_ossf_HT.root");
    delete c_st_n_ossf_HT;
    
    
    TCanvas *c_st_n_ossf_jetPt = new TCanvas("c_st_n_ossf_M_{ll}","c_st_n_ossf_M_{ll}",10,10,700,700);
    c_st_n_ossf_jetPt->Divide(1,2);
    c_st_n_ossf_jetPt->cd(1);
    /*if (histo_signal_5_n_ossf_rec[7]-> GetBinContent(histo_signal_5_n_ossf_rec[7]->GetMaximumBin ()) > histo_dy2_n_ossf_rec[7]-> GetBinContent(histo_dy2_n_ossf_rec[7]->GetMaximumBin ())){
     hs_n_ossf_rec_jetPt->SetMaximum(histo_signal_5_n_ossf_rec[7]-> GetBinContent(histo_signal_5_n_ossf_rec[7]->GetMaximumBin ()) * 1.1);
     }*/
    hs_n_ossf_rec_jetPt->SetMaximum(hs_n_ossf_rec_jetPt->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_rec[7]-> GetBinContent(histo_signal_5_n_ossf_rec[7]->GetMaximumBin ()) > hs_n_ossf_rec_jetPt-> GetMaximum()){
        hs_n_ossf_rec_jetPt->SetMaximum(histo_signal_5_n_ossf_rec[7]-> GetBinContent(histo_signal_5_n_ossf_rec[7]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_rec_jetPt->Draw("hist");
    histo_signal_50_n_ossf_rec[7]->SetLineColor(1);
    histo_signal_50_n_ossf_rec[7]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_rec[7]->SetMarkerColor(1);
    histo_signal_50_n_ossf_rec[7]->Draw("histsame");
    histo_signal_20_n_ossf_rec[7]->SetLineColor(1);
    histo_signal_20_n_ossf_rec[7]->SetLineStyle(7);
    histo_signal_20_n_ossf_rec[7]->SetMarkerColor(1);
    histo_signal_20_n_ossf_rec[7]->Draw("histsame");
    histo_signal_5_n_ossf_rec[7]->SetLineColor(1);
    histo_signal_5_n_ossf_rec[7]->SetLineStyle(3);
    histo_signal_5_n_ossf_rec[7]->SetMarkerColor(1);
    histo_signal_5_n_ossf_rec[7]->Draw("histsame");
    leg_n_ossf_jetPt = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_jetPt->SetHeader("n_ossf M_{ll}"); // option "C" allows to center the header
    leg_n_ossf_jetPt->AddEntry(histo_dy2_n_ossf_rec[7],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_jetPt->AddEntry(histo_tt_n_ossf_rec[7],"ttbar","f");
    leg_n_ossf_jetPt->AddEntry(histo_wg_n_ossf_rec[7],"W#gamma","f");
    leg_n_ossf_jetPt->AddEntry(histo_wz_n_ossf_rec[7],"WZ","f");
    leg_n_ossf_jetPt->AddEntry(histo_signal_5_n_ossf_rec[7],"MN = 5 GeV","l");
    
    leg_n_ossf_jetPt->AddEntry(histo_signal_20_n_ossf_rec[7],"MN = 20 GeV","l");
    
    leg_n_ossf_jetPt->AddEntry(histo_signal_50_n_ossf_rec[7],"MN = 50 GeV","l");
    leg_n_ossf_jetPt->Draw();
    hs_n_ossf_rec_jetPt->GetXaxis()->SetTitle("jet p_{T} (GeV)");
    c_st_n_ossf_jetPt->Modified();
    c_st_n_ossf_jetPt->Print("PLOT/c_st_n_ossf_jetPt.root");
    delete c_st_n_ossf_jetPt;
    
    
    
    
    
    TCanvas *c_st_n_ossf_jetEta = new TCanvas("c_st_n_ossf_M_{ll}","c_st_n_ossf_M_{ll}",10,10,700,700);
    c_st_n_ossf_jetEta->Divide(1,2);
    c_st_n_ossf_jetEta->cd(1);
    /*if (histo_signal_5_n_ossf_rec[8]-> GetBinContent(histo_signal_5_n_ossf_rec[8]->GetMaximumBin ()) > histo_dy2_n_ossf_rec[8]-> GetBinContent(histo_dy2_n_ossf_rec[8]->GetMaximumBin ())){
     hs_n_ossf_rec_jetEta->SetMaximum(histo_signal_5_n_ossf_rec[8]-> GetBinContent(histo_signal_5_n_ossf_rec[8]->GetMaximumBin ()) * 1.1);
     }*/
    hs_n_ossf_rec_jetEta->SetMaximum(hs_n_ossf_rec_jetEta->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_rec[8]-> GetBinContent(histo_signal_5_n_ossf_rec[8]->GetMaximumBin ()) > hs_n_ossf_rec_jetEta-> GetMaximum()){
        hs_n_ossf_rec_jetEta->SetMaximum(histo_signal_5_n_ossf_rec[8]-> GetBinContent(histo_signal_5_n_ossf_rec[8]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_rec_jetEta->Draw("hist");
    histo_signal_50_n_ossf_rec[8]->SetLineColor(1);
    histo_signal_50_n_ossf_rec[8]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_rec[8]->SetMarkerColor(1);
    histo_signal_50_n_ossf_rec[8]->Draw("histsame");
    histo_signal_20_n_ossf_rec[8]->SetLineColor(1);
    histo_signal_20_n_ossf_rec[8]->SetLineStyle(7);
    histo_signal_20_n_ossf_rec[8]->SetMarkerColor(1);
    histo_signal_20_n_ossf_rec[8]->Draw("histsame");
    histo_signal_5_n_ossf_rec[8]->SetLineColor(1);
    histo_signal_5_n_ossf_rec[8]->SetLineStyle(3);
    histo_signal_5_n_ossf_rec[8]->SetMarkerColor(1);
    histo_signal_5_n_ossf_rec[8]->Draw("histsame");
    leg_n_ossf_jetEta = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_jetEta->SetHeader("n_ossf M_{ll}"); // oEtaion "C" allows to center the header
    leg_n_ossf_jetEta->AddEntry(histo_dy2_n_ossf_rec[8],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_jetEta->AddEntry(histo_tt_n_ossf_rec[8],"ttbar","f");
    leg_n_ossf_jetEta->AddEntry(histo_wg_n_ossf_rec[8],"W#gamma","f");
    leg_n_ossf_jetEta->AddEntry(histo_wz_n_ossf_rec[8],"WZ","f");
    leg_n_ossf_jetEta->AddEntry(histo_signal_5_n_ossf_rec[8],"MN = 5 GeV","l");
    
    leg_n_ossf_jetEta->AddEntry(histo_signal_20_n_ossf_rec[8],"MN = 20 GeV","l");
    
    leg_n_ossf_jetEta->AddEntry(histo_signal_50_n_ossf_rec[8],"MN = 50 GeV","l");
    leg_n_ossf_jetEta->Draw();
    hs_n_ossf_rec_jetEta->GetXaxis()->SetTitle("jet #eta");
    c_st_n_ossf_jetEta->Modified();
    c_st_n_ossf_jetEta->Print("PLOT/c_st_n_ossf_jetEta.root");
    delete c_st_n_ossf_jetEta;
    
    
    TCanvas *c_st_n_ossf_jetPhi = new TCanvas("c_st_n_ossf_M_{ll}","c_st_n_ossf_M_{ll}",10,10,700,700);
    c_st_n_ossf_jetPhi->Divide(1,2);
    c_st_n_ossf_jetPhi->cd(1);
    /*if (histo_signal_5_n_ossf_rec[9]-> GetBinContent(histo_signal_5_n_ossf_rec[9]->GetMaximumBin ()) > histo_dy2_n_ossf_rec[9]-> GetBinContent(histo_dy2_n_ossf_rec[9]->GetMaximumBin ())){
     hs_n_ossf_rec_jetPhi->SetMaximum(histo_signal_5_n_ossf_rec[9]-> GetBinContent(histo_signal_5_n_ossf_rec[9]->GetMaximumBin ()) * 1.1);
     }*/
    hs_n_ossf_rec_jetPhi->SetMaximum(hs_n_ossf_rec_jetPhi->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_rec[9]-> GetBinContent(histo_signal_5_n_ossf_rec[9]->GetMaximumBin ()) > hs_n_ossf_rec_jetPhi-> GetMaximum()){
        hs_n_ossf_rec_jetPhi->SetMaximum(histo_signal_5_n_ossf_rec[9]-> GetBinContent(histo_signal_5_n_ossf_rec[9]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_rec_jetPhi->Draw("hist");
    histo_signal_50_n_ossf_rec[9]->SetLineColor(1);
    histo_signal_50_n_ossf_rec[9]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_rec[9]->SetMarkerColor(1);
    histo_signal_50_n_ossf_rec[9]->Draw("histsame");
    histo_signal_20_n_ossf_rec[9]->SetLineColor(1);
    histo_signal_20_n_ossf_rec[9]->SetLineStyle(7);
    histo_signal_20_n_ossf_rec[9]->SetMarkerColor(1);
    histo_signal_20_n_ossf_rec[9]->Draw("histsame");
    histo_signal_5_n_ossf_rec[9]->SetLineColor(1);
    histo_signal_5_n_ossf_rec[9]->SetLineStyle(3);
    histo_signal_5_n_ossf_rec[9]->SetMarkerColor(1);
    histo_signal_5_n_ossf_rec[9]->Draw("histsame");
    leg_n_ossf_jetPhi = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_jetPhi->SetHeader("n_ossf M_{ll}"); // oPhiion "C" allows to center the header
    leg_n_ossf_jetPhi->AddEntry(histo_dy2_n_ossf_rec[9],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_jetPhi->AddEntry(histo_tt_n_ossf_rec[9],"ttbar","f");
    leg_n_ossf_jetPhi->AddEntry(histo_wg_n_ossf_rec[9],"W#gamma","f");
    leg_n_ossf_jetPhi->AddEntry(histo_wz_n_ossf_rec[9],"WZ","f");
    leg_n_ossf_jetPhi->AddEntry(histo_signal_5_n_ossf_rec[9],"MN = 5 GeV","l");
    
    leg_n_ossf_jetPhi->AddEntry(histo_signal_20_n_ossf_rec[9],"MN = 20 GeV","l");
    
    leg_n_ossf_jetPhi->AddEntry(histo_signal_50_n_ossf_rec[9],"MN = 50 GeV","l");
    leg_n_ossf_jetPhi->Draw();
    hs_n_ossf_rec_jetPhi->GetXaxis()->SetTitle("jet #phi");
    c_st_n_ossf_jetPhi->Modified();
    c_st_n_ossf_jetPhi->Print("PLOT/c_st_n_ossf_jetPhi.root");
    delete c_st_n_ossf_jetPhi;
    
    
    TCanvas *c_st_n_ossf_jetFlavour = new TCanvas("c_st_n_ossf_M_{ll}","c_st_n_ossf_M_{ll}",10,10,700,700);
    c_st_n_ossf_jetFlavour->Divide(1,2);
    c_st_n_ossf_jetFlavour->cd(1);
    /*if (histo_signal_5_n_ossf_rec[10]-> GetBinContent(histo_signal_5_n_ossf_rec[10]->GetMaximumBin ()) > histo_dy2_n_ossf_rec[10]-> GetBinContent(histo_dy2_n_ossf_rec[10]->GetMaximumBin ())){
     hs_n_ossf_rec_jetFlavour->SetMaximum(histo_signal_5_n_ossf_rec[10]-> GetBinContent(histo_signal_5_n_ossf_rec[10]->GetMaximumBin ()) * 1.1);
     }*/
    hs_n_ossf_rec_jetFlavour->SetMaximum(hs_n_ossf_rec_jetFlavour->GetMaximum()*1.2);
    if (histo_signal_5_n_ossf_rec[10]-> GetBinContent(histo_signal_5_n_ossf_rec[10]->GetMaximumBin ()) > hs_n_ossf_rec_jetFlavour-> GetMaximum()){
        hs_n_ossf_rec_jetFlavour->SetMaximum(histo_signal_5_n_ossf_rec[10]-> GetBinContent(histo_signal_5_n_ossf_rec[10]->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_rec_jetFlavour->Draw("hist");
    histo_signal_50_n_ossf_rec[10]->SetLineColor(1);
    histo_signal_50_n_ossf_rec[10]->SetMarkerStyle(21);
    histo_signal_50_n_ossf_rec[10]->SetMarkerColor(1);
    histo_signal_50_n_ossf_rec[10]->Draw("histsame");
    histo_signal_20_n_ossf_rec[10]->SetLineColor(1);
    histo_signal_20_n_ossf_rec[10]->SetLineStyle(7);
    histo_signal_20_n_ossf_rec[10]->SetMarkerColor(1);
    histo_signal_20_n_ossf_rec[10]->Draw("histsame");
    histo_signal_5_n_ossf_rec[10]->SetLineColor(1);
    histo_signal_5_n_ossf_rec[10]->SetLineStyle(3);
    histo_signal_5_n_ossf_rec[10]->SetMarkerColor(1);
    histo_signal_5_n_ossf_rec[10]->Draw("histsame");
    leg_n_ossf_jetFlavour = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_jetFlavour->SetHeader("n_ossf M_{ll}"); // oFlavourion "C" allows to center the header
    leg_n_ossf_jetFlavour->AddEntry(histo_dy2_n_ossf_rec[10],"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_jetFlavour->AddEntry(histo_tt_n_ossf_rec[10],"ttbar","f");
    leg_n_ossf_jetFlavour->AddEntry(histo_wg_n_ossf_rec[10],"W#gamma","f");
    leg_n_ossf_jetFlavour->AddEntry(histo_wz_n_ossf_rec[10],"WZ","f");
    leg_n_ossf_jetFlavour->AddEntry(histo_signal_5_n_ossf_rec[10],"MN = 5 GeV","l");
    
    leg_n_ossf_jetFlavour->AddEntry(histo_signal_20_n_ossf_rec[10],"MN = 20 GeV","l");
    
    leg_n_ossf_jetFlavour->AddEntry(histo_signal_50_n_ossf_rec[10],"MN = 50 GeV","l");
    leg_n_ossf_jetFlavour->Draw();
    hs_n_ossf_rec_jetFlavour->GetXaxis()->SetTitle("jet Flavour");
    c_st_n_ossf_jetFlavour->Modified();
    c_st_n_ossf_jetFlavour->Print("PLOT/c_st_n_ossf_jetFlavour.root");
    delete c_st_n_ossf_jetFlavour;
    
    
    TCanvas *c_st_n_ossf_lepton_flavor  = new TCanvas("c_st_n_ossf_lepton_flavor ","c_st_n_ossf_lepton_flavor ",10,10,700,700);
    c_st_n_ossf_lepton_flavor ->Divide(1,2);
    c_st_n_ossf_lepton_flavor ->cd(1);
    /*if (histo_signal_5_n_ossf_rec[10]-> GetBinContent(histo_signal_5_n_ossf_rec[10]->GetMaximumBin ()) > histo_dy2_n_ossf_rec[10]-> GetBinContent(histo_dy2_n_ossf_rec[10]->GetMaximumBin ())){
     hs_n_ossf_flavor->SetMaximum(histo_signal_5_n_ossf_rec[10]-> GetBinContent(histo_signal_5_n_ossf_rec[10]->GetMaximumBin ()) * 1.1);
     }*/
    hs_n_ossf_flavor->SetMaximum(hs_n_ossf_flavor->GetMaximum()*1.2);
    if (flavor_plot_signal_50_n_ossf-> GetBinContent(flavor_plot_signal_50_n_ossf->GetMaximumBin ()) >hs_n_ossf_flavor-> GetMaximum()){
        hs_n_ossf_flavor->SetMaximum(flavor_plot_signal_50_n_ossf-> GetBinContent(flavor_plot_signal_50_n_ossf->GetMaximumBin ()) * 2);
    }
    hs_n_ossf_flavor ->Draw("hist");
    flavor_plot_signal_50_n_ossf->SetLineColor(1);
    flavor_plot_signal_50_n_ossf->SetMarkerStyle(21);
    flavor_plot_signal_50_n_ossf->SetMarkerColor(1);
    flavor_plot_signal_50_n_ossf->Draw("histsame");
    flavor_plot_signal_20_n_ossf->SetLineColor(1);
    flavor_plot_signal_20_n_ossf->SetLineStyle(7);
    flavor_plot_signal_20_n_ossf->SetMarkerColor(1);
    flavor_plot_signal_20_n_ossf->Draw("histsame");
    flavor_plot_signal_5_n_ossf->SetLineColor(1);
    flavor_plot_signal_5_n_ossf->SetLineStyle(3);
    flavor_plot_signal_5_n_ossf->SetMarkerColor(1);
    flavor_plot_signal_5_n_ossf->Draw("histsame");
    leg_n_ossf_jetFlavour  = new TLegend(0.54,0.50,0.90,0.9);
    leg_n_ossf_jetFlavour ->SetHeader("n_ossf lepton Flavors "); // option "C" allows to center the header
    leg_n_ossf_jetFlavour ->AddEntry(flavor_plot_dy2_n_ossf,"DY (M_{ll} >50 GeV/c)","f");
    leg_n_ossf_jetFlavour ->AddEntry(flavor_plot_tt_n_ossf,"ttbar","f");
    leg_n_ossf_jetFlavour ->AddEntry(flavor_plot_wg_n_ossf,"W#gamma","f");
    leg_n_ossf_jetFlavour ->AddEntry(flavor_plot_wz_n_ossf,"WZ","f");
    leg_n_ossf_jetFlavour ->AddEntry(flavor_plot_signal_5_n_ossf,"MN = 5 GeV","l");
    
    leg_n_ossf_jetFlavour ->AddEntry(flavor_plot_signal_20_n_ossf,"MN = 20 GeV","l");
    leg_n_ossf_jetFlavour ->AddEntry(flavor_plot_signal_50_n_ossf,"MN = 50 GeV","l");
    
    leg_n_ossf_jetFlavour ->Draw();
    hs_n_ossf_flavor->GetXaxis()->SetNdivisions(-414);
    hs_n_ossf_flavor->GetYaxis()->SetTitle("Events");
    hs_n_ossf_flavor->GetXaxis()->SetBinLabel(1,"TOT");
    hs_n_ossf_flavor->GetXaxis()->SetBinLabel(2,"eee");
    hs_n_ossf_flavor->GetXaxis()->SetBinLabel(3,"#mu #mu #mu");
    hs_n_ossf_flavor->GetXaxis()->SetBinLabel(4,"e#mu #mu");
    hs_n_ossf_flavor->GetXaxis()->SetBinLabel(5,"ee#mu");
    hs_n_ossf_flavor->GetXaxis()->SetBinLabel(6,"ee#tau");
    hs_n_ossf_flavor->GetXaxis()->SetBinLabel(7,"e #tau #tau");
    c_st_n_ossf_lepton_flavor->Modified();
    c_st_n_ossf_lepton_flavor ->Print("PLOT/c_st_n_ossf_lepton_flavor .root");
    delete c_st_n_ossf_lepton_flavor ;
    
    
}// end analisi

