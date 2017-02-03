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
#include <THStack.h>


using namespace std;
const int num_histo_kin= 3;
const int num_histo= 12;


const Int_t nDati=100;

//__________________________________________________________
void cosmesi(Int_t numero,TGraphErrors *histo_positive,char nameassex[] = "asse x",char nameassey[] = "asse y"){
    
    //histo_positive->GetXaxis()->SetLimits(min_x,max_x);
    histo_positive->GetYaxis()->SetNdivisions(506);
    histo_positive->GetXaxis()->SetNdivisions(506);
    histo_positive->SetMinimum( 0);
    histo_positive->SetMaximum( 1.2);
    histo_positive->SetTitle("");
    histo_positive->GetXaxis()->SetTitle(nameassex);
    histo_positive->GetXaxis()->SetTitleOffset(0.75);
    histo_positive->GetXaxis()->SetTitleSize(0.05);
    histo_positive->GetXaxis() ->SetTitleFont(132);
    histo_positive->GetXaxis()->SetLabelSize(0.04);
    histo_positive->GetXaxis()->SetLabelOffset(0.005);
    histo_positive->GetXaxis()->SetLabelFont(132);
    
    histo_positive->GetYaxis()->SetLabelFont(132);
    
    histo_positive->GetYaxis()->SetNdivisions(506);
    histo_positive->GetYaxis()->SetTitle(nameassey);
    histo_positive->	GetYaxis ()->SetTitleOffset(0.75);
    histo_positive->	GetYaxis()->SetTitleSize(0.06);
    histo_positive->	GetYaxis() ->SetTitleFont(132);
    histo_positive->GetYaxis()->SetLabelOffset(0.005);
    histo_positive->GetYaxis()->SetLabelSize(0.04);
    histo_positive->GetYaxis()-> CenterTitle();
    if (numero == 1){
        histo_positive->SetMarkerStyle(21);
        histo_positive->SetMarkerColor(kRed);
        histo_positive->SetMarkerSize(0.5);
    }
    if (numero == 2 ){
        histo_positive->SetMarkerStyle(21);
        histo_positive->SetMarkerColor(kBlue);
        histo_positive->SetMarkerSize(0.5);
    }
    if (numero == 3){
        histo_positive->SetMarkerStyle(21);
        histo_positive->SetMarkerColor(8);
        histo_positive->SetMarkerSize(0.5);
    }
    if (numero == 4 ){
        histo_positive->SetMarkerStyle(21);
        histo_positive->SetMarkerColor(kOrange);
        histo_positive->SetMarkerSize(0.5);
    }
    if (numero == 5){
        histo_positive->SetMarkerStyle(20);
        histo_positive->SetMarkerColor(kBlack);
        histo_positive->SetMarkerSize(0.5);
    }
    if (numero == 6){
        histo_positive->SetMarkerStyle(4);
        histo_positive->SetMarkerColor(kBlack);
        histo_positive->SetMarkerSize(0.5);
    }
}//end cosmesi




void lett (string inputRootFile= "file_mva_gen1.root");


// ********************************************************************
void lett(string inputRootFile){
    Double_t pigreco= TMath::ACos(-1);
    cout<<"in analisi"<<endl;
    cout<<"---------------------------"<<endl;
    const int npoint=100;
    static TGraphErrors* g_pt_wg_ossf;
    static TGraphErrors* g_pt_wz_ossf;
    static TGraphErrors* g_pt_tt_ossf;
    static TGraphErrors* g_pt_zg_ossf;
    static TGraphErrors* g_pt_signal_50_ossf;
    static TGraphErrors* g_pt_signal_20_ossf;
    static TGraphErrors* g_pt_signal_10_ossf;
    Double_t num_wg_ossf[npoint];
    Double_t den_wg_ossf[npoint];
    Double_t num_wz_ossf[npoint];
    Double_t den_wz_ossf[npoint];
    Double_t num_zg_ossf[npoint];
    Double_t den_zg_ossf[npoint];
    Double_t num_tt_ossf[npoint];
    Double_t den_tt_ossf[npoint];
    Double_t num_signal_20_ossf[npoint];
    Double_t den_signal_20_ossf[npoint];
    Double_t num_signal_10_ossf[npoint];
    Double_t den_signal_10_ossf[npoint];
    Double_t num_signal_50_ossf[npoint];
    Double_t den_signal_50_ossf[npoint];
    Double_t wg_ossf[npoint];
    Double_t wz_ossf[npoint];
    Double_t tt_ossf[npoint];
    Double_t zg_ossf[npoint];
    Double_t signal_50_ossf[npoint];
    Double_t signal_20_ossf[npoint];
    Double_t signal_10_ossf[npoint];
    
    static TGraphErrors* g_pt_wg_n_ossf;
    static TGraphErrors* g_pt_wz_n_ossf;
    static TGraphErrors* g_pt_tt_n_ossf;
    static TGraphErrors* g_pt_zg_n_ossf;
    static TGraphErrors* g_pt_signal_50_n_ossf;
    static TGraphErrors* g_pt_signal_20_n_ossf;
    static TGraphErrors* g_pt_signal_10_n_ossf;
    
    Double_t num_wg_n_ossf[npoint];
    Double_t den_wg_n_ossf[npoint];
    Double_t num_wz_n_ossf[npoint];
    Double_t den_wz_n_ossf[npoint];
    Double_t num_zg_n_ossf[npoint];
    Double_t den_zg_n_ossf[npoint];
    Double_t num_tt_n_ossf[npoint];
    Double_t den_tt_n_ossf[npoint];
    Double_t num_signal_20_n_ossf[npoint];
    Double_t den_signal_20_n_ossf[npoint];
    Double_t num_signal_10_n_ossf[npoint];
    Double_t den_signal_10_n_ossf[npoint];
    Double_t num_signal_50_n_ossf[npoint];
    Double_t den_signal_50_n_ossf[npoint];
    Double_t wg_n_ossf[npoint];
    Double_t wz_n_ossf[npoint];
    Double_t tt_n_ossf[npoint];
    Double_t zg_n_ossf[npoint];
    Double_t signal_50_n_ossf[npoint];
    Double_t signal_20_n_ossf[npoint];
    Double_t signal_10_n_ossf[npoint];
    
    
    double back_sum_ossf[npoint];
    double back_sum_n_ossf[npoint];
    double back_den_ossf[npoint];
    double back_den_n_ossf[npoint];
    double back_value_ossf[npoint];
    double back_value_n_ossf[npoint];
    
    
    static TGraphErrors* g_pt_roc_50_ossf;
    static TGraphErrors* g_pt_roc_50_n_ossf;
    static TGraphErrors* g_pt_roc_20_ossf;
    static TGraphErrors* g_pt_roc_20_n_ossf;
    static TGraphErrors* g_pt_roc_10_ossf;
    static TGraphErrors* g_pt_roc_10_n_ossf;
    
    
    
    
    
    double x_point[npoint];
    for (int i =0; i< npoint; i++){
        x_point[i] = i;
        back_sum_ossf[i]= 0;
        back_sum_n_ossf[i]= 0;
        back_den_ossf[i]= 0;
        back_den_n_ossf[i]= 0;
        back_value_ossf[i]= 0;
        back_value_n_ossf[i]= 0;
        num_wg_ossf[i] = 0;
        den_wg_ossf[i] = 0;
        num_wz_ossf[i] = 0;
        den_wz_ossf[i] = 0;
        num_zg_ossf[i] = 0;
        den_zg_ossf[i] = 0;
        num_tt_ossf[i] = 0;
        den_tt_ossf[i] = 0;
        num_signal_20_ossf[i] = 0;
        den_signal_20_ossf[i] = 0;
        num_signal_10_ossf[i] = 0;
        den_signal_10_ossf[i] = 0;
        num_signal_50_ossf[i] = 0;
        den_signal_50_ossf[i] = 0;
        wg_ossf[i] = 0;
        wz_ossf[i] = 0;
        tt_ossf[i] = 0;
        zg_ossf[i] = 0;
        signal_20_ossf[i] = 0;
        signal_10_ossf[i] = 0;
        
        signal_50_ossf[i] = 0;
        num_wg_n_ossf[i] = 0;
        den_wg_n_ossf[i] = 0;
        num_wz_n_ossf[i] = 0;
        den_wz_n_ossf[i] = 0;
        num_zg_n_ossf[i] = 0;
        den_zg_n_ossf[i] = 0;
        num_tt_n_ossf[i] = 0;
        den_tt_n_ossf[i] = 0;
        num_signal_20_n_ossf[i] = 0;
        den_signal_20_n_ossf[i] = 0;
        num_signal_10_n_ossf[i] = 0;
        den_signal_10_n_ossf[i] = 0;
        num_signal_50_n_ossf[i] = 0;
        den_signal_50_n_ossf[i] = 0;
        wg_n_ossf[i] = 0;
        wz_n_ossf[i] = 0;
        tt_n_ossf[i] = 0;
        zg_n_ossf[i] = 0;
        signal_20_n_ossf[i] = 0;
        signal_10_n_ossf[i] = 0;
        
        signal_50_n_ossf[i] = 0;
    }
    
    
    ifstream wgn("txt_file/wg_ptcut_eem_max.txt");
    if(!wgn){
        cout<<"Il file non esiste "<<endl;
        return;
    }
    int wg = 0;
    while((wgn>>x_point[wg]>>num_wg_ossf[wg] >>num_wg_n_ossf[wg]>>den_wg_ossf[wg] >>den_wg_n_ossf[wg])){
        wg++;
    }
    wgn.close();
    
    ifstream wzn("txt_file/wz_ptcut_eem_max.txt");
    if(!wzn){
        cout<<"Il file non esiste "<<endl;
        return;
    }
    int wz = 0;
    while((wzn>>x_point[wz]>>num_wz_ossf[wz] >>num_wz_n_ossf[wz]>>den_wz_ossf[wz] >>den_wz_n_ossf[wz])){
        wz++;
    }
    wzn.close();
    ifstream ttn("txt_file/tt_ptcut_eem_max.txt");
    if(!ttn){
        cout<<"Il file non esiste "<<endl;
        return;
    }
    int tt = 0;
    while((ttn>>x_point[tt]>>num_tt_ossf[tt] >>num_tt_n_ossf[tt]>>den_tt_ossf[tt] >>den_tt_n_ossf[tt])){
        tt++;
    }
    ttn.close();
    ifstream zgn("txt_file/zg_ptcut_eem_max.txt");
    if(!zgn){
        cout<<"Il file non esiste "<<endl;
        return;
    }
    int zg = 0;
    while((zgn>>x_point[zg]>>num_zg_ossf[zg] >>num_zg_n_ossf[zg]>>den_zg_ossf[zg] >>den_zg_n_ossf[zg])){
        zg++;
    }
    zgn.close();
    ifstream signal_50n("txt_file/signal_ptcut_50_eem_max.txt");
    if(!signal_50n){
        cout<<"Il file non esiste "<<endl;
        return;
    }
    int signal_50 = 0;
    while((signal_50n>>x_point[signal_50]>>num_signal_50_ossf[signal_50] >>num_signal_50_n_ossf[signal_50]>>den_signal_50_ossf[signal_50] >>den_signal_50_n_ossf[signal_50])){
        signal_50++;
    }
    signal_50n.close();
    ifstream signal_20n("txt_file/signal_ptcut_20_eem_max.txt");
    if(!signal_20n){
        cout<<"Il file non esiste "<<endl;
        return;
    }
    int signal_20 = 0;
    while((signal_20n>>x_point[signal_20]>>num_signal_20_ossf[signal_20] >>num_signal_20_n_ossf[signal_20]>>den_signal_20_ossf[signal_20] >>den_signal_20_n_ossf[signal_20])){
        signal_20++;
    }
    signal_20n.close();
    ifstream signal_10n("txt_file/signal_ptcut_10_eem_max.txt");
    if(!signal_10n){
        cout<<"Il file non esiste "<<endl;
        return;
    }
    int signal_10 = 0;
    while((signal_10n>>x_point[signal_10]>>num_signal_10_ossf[signal_10] >>num_signal_10_n_ossf[signal_10]>>den_signal_10_ossf[signal_10] >>den_signal_10_n_ossf[signal_10])){
        signal_10++;
    }
    signal_10n.close();
    
    
    
    
    // =============== ROC curves =============
    for (int i =0; i< npoint; i++){
        back_den_ossf[i]=den_wg_ossf[i]+den_wz_ossf[i]+den_tt_ossf[i]+den_zg_ossf[i];
        back_sum_ossf[i]=num_wg_ossf[i]+num_wz_ossf[i]+num_tt_ossf[i]+num_zg_ossf[i];
        back_den_n_ossf[i]=den_wg_n_ossf[i]+den_wz_n_ossf[i]+den_tt_n_ossf[i]+den_zg_n_ossf[i];
        back_sum_n_ossf[i]=num_wg_n_ossf[i]+num_wz_n_ossf[i]+num_tt_n_ossf[i]+num_zg_n_ossf[i];
        if(back_den_ossf[i]==0) back_value_ossf[i]=0;
        else {
            back_value_ossf[i] = back_sum_ossf[i]/back_den_ossf[i];
        }
        if(back_den_n_ossf[i]==0) back_value_n_ossf[i]=0;
        else {
            back_value_n_ossf[i] = back_sum_n_ossf[i]/back_den_n_ossf[i];
        }
    }
    
    
    
    
    
    for (int i =0; i< npoint; i++){
        if (den_wg_ossf[i] == 0 ) wg_ossf[i]=0;
        else {
            wg_ossf[i] = num_wg_ossf[i]/den_wg_ossf[i];
        }
        if (den_wz_ossf[i] == 0 ) wz_ossf[i]=0;
        else {
            wz_ossf[i] = num_wz_ossf[i]/den_wz_ossf[i];
        }
        if (den_tt_ossf[i] == 0 ) tt_ossf[i]=0;
        else {
            tt_ossf[i] = num_tt_ossf[i]/den_tt_ossf[i];
        }
        if (den_zg_ossf[i] == 0 ) zg_ossf[i]=0;
        else {
            zg_ossf[i] = num_zg_ossf[i]/den_zg_ossf[i];
        }
        if (den_signal_50_ossf[i] == 0 ) signal_50_ossf[i]=0;
        else {
            signal_50_ossf[i] = num_signal_50_ossf[i]/den_signal_50_ossf[i];
        }
        if (den_signal_20_ossf[i] == 0 ) signal_20_ossf[i]=0;
        else {
            signal_20_ossf[i] = num_signal_20_ossf[i]/den_signal_20_ossf[i];
        }
        if (den_signal_10_ossf[i] == 0 ) signal_10_ossf[i]=0;
        else {
            signal_10_ossf[i] = num_signal_10_ossf[i]/den_signal_10_ossf[i];
        }
        if (den_wg_n_ossf[i] == 0 ) wg_n_ossf[i]=0;
        else {
            wg_n_ossf[i] = num_wg_n_ossf[i]/den_wg_n_ossf[i];
        }
        if (den_wz_n_ossf[i] == 0 ) wz_n_ossf[i]=0;
        else {
            wz_n_ossf[i] = num_wz_n_ossf[i]/den_wz_n_ossf[i];
        }
        if (den_tt_n_ossf[i] == 0 ) tt_n_ossf[i]=0;
        else {
            tt_n_ossf[i] = num_tt_n_ossf[i]/den_tt_n_ossf[i];
        }
        if (den_zg_n_ossf[i] == 0 ) zg_n_ossf[i]=0;
        else {
            zg_n_ossf[i] = num_zg_n_ossf[i]/den_zg_n_ossf[i];
        }
        if (den_signal_50_n_ossf[i] == 0 ) signal_50_n_ossf[i]=0;
        else {
            signal_50_n_ossf[i] = num_signal_50_n_ossf[i]/den_signal_50_n_ossf[i];
        }
        if (den_signal_20_n_ossf[i] == 0 ) signal_20_n_ossf[i]=0;
        else {
            signal_20_n_ossf[i] = num_signal_20_n_ossf[i]/den_signal_20_n_ossf[i];
        }
        
        if (den_signal_10_n_ossf[i] == 0 ) signal_10_n_ossf[i]=0;
        else {
            signal_10_n_ossf[i] = num_signal_10_n_ossf[i]/den_signal_10_n_ossf[i];
        }
        
    }// end for
    
    
    for (int i =0; i< npoint; i++){
        
        
        cout<<num_wz_ossf[i] <<endl;
        cout<<den_wz_ossf[i] <<endl;
        
        
        cout<<wz_ossf[i]<<endl;
        
        // cout<<signal_10_ossf[i] <<endl;
        
    }
    
    g_pt_roc_50_ossf = new TGraphErrors(npoint,back_value_ossf , signal_50_ossf,  0, 0);
    g_pt_roc_20_ossf = new TGraphErrors(npoint,back_value_ossf , signal_20_ossf,  0, 0);
    g_pt_roc_10_ossf = new TGraphErrors(npoint,back_value_ossf , signal_10_ossf,  0, 0);
    g_pt_roc_50_n_ossf = new TGraphErrors(npoint,back_value_n_ossf , signal_50_n_ossf,  0, 0);
    g_pt_roc_20_n_ossf = new TGraphErrors(npoint,back_value_n_ossf , signal_20_n_ossf,  0, 0);
    g_pt_roc_10_n_ossf = new TGraphErrors(npoint,back_value_n_ossf , signal_10_n_ossf,  0, 0);
    cosmesi(1,*&g_pt_roc_50_ossf , "Efficiency Total Background  ","Efficiency Signal" );
    cosmesi(2,*&g_pt_roc_20_ossf ,"Efficiency Total Background  ","Efficiency Signal" );
    cosmesi(3,*&g_pt_roc_10_ossf , "Efficiency Total Background  ","Efficiency Signal" );
    cosmesi(1,*&g_pt_roc_50_n_ossf , "Efficiency Total Background  ","Efficiency Signal" );
    cosmesi(2,*&g_pt_roc_20_n_ossf ,"Efficiency Total Background  ","Efficiency Signal" );
    cosmesi(3,*&g_pt_roc_10_n_ossf , "Efficiency Total Background  ","Efficiency Signal" );
    
    
    g_pt_wg_ossf = new TGraphErrors(npoint, x_point, wg_ossf,  0, 0);
    g_pt_wz_ossf = new TGraphErrors(npoint, x_point, wz_ossf,  0, 0);
    g_pt_zg_ossf = new TGraphErrors(npoint, x_point, zg_ossf,  0, 0);
    g_pt_tt_ossf = new TGraphErrors(npoint, x_point, tt_ossf,  0, 0);
    g_pt_signal_50_ossf = new TGraphErrors(npoint, x_point, signal_50_ossf,  0, 0);
    g_pt_signal_20_ossf = new TGraphErrors(npoint, x_point, signal_20_ossf,  0, 0);
    g_pt_signal_10_ossf = new TGraphErrors(npoint, x_point, signal_10_ossf,  0, 0);
    
    g_pt_wg_n_ossf = new TGraphErrors(npoint, x_point, wg_n_ossf,  0, 0);
    g_pt_wz_n_ossf = new TGraphErrors(npoint, x_point, wz_n_ossf,  0, 0);
    g_pt_zg_n_ossf = new TGraphErrors(npoint, x_point, zg_n_ossf,  0, 0);
    g_pt_tt_n_ossf = new TGraphErrors(npoint, x_point, tt_n_ossf,  0, 0);
    g_pt_signal_50_n_ossf = new TGraphErrors(npoint, x_point, signal_50_n_ossf,  0, 0);
    g_pt_signal_20_n_ossf = new TGraphErrors(npoint, x_point, signal_20_n_ossf,  0, 0);
    g_pt_signal_10_n_ossf = new TGraphErrors(npoint, x_point, signal_10_n_ossf,  0, 0);
    
    
    cosmesi(1,*&g_pt_zg_ossf, "p_{T} (GeV)  ","Efficiency" );
    cosmesi(2,*&g_pt_tt_ossf, "p_{T} (GeV)  ","Efficiency" );
    cosmesi(3,*&g_pt_wz_ossf, "p_{T} (GeV)  ","Efficiency" );
    cosmesi(4,*&g_pt_wg_ossf, "p_{T} (GeV)  ","Efficiency" );
    cosmesi(5,*&g_pt_signal_50_ossf, "p_{T} (GeV)  ","Efficiency" );
    cosmesi(6,*&g_pt_signal_20_ossf, "p_{T} (GeV)  ","Efficiency" );
    cosmesi(6,*&g_pt_signal_10_ossf, "p_{T} (GeV)  ","Efficiency" );
    
    cosmesi(1,*&g_pt_zg_n_ossf, "p_{T} (GeV)  ","Efficiency" );
    cosmesi(2,*&g_pt_tt_n_ossf, "p_{T} (GeV)  ","Efficiency" );
    cosmesi(3,*&g_pt_wz_n_ossf, "p_{T} (GeV)  ","Efficiency" );
    cosmesi(4,*&g_pt_wg_n_ossf, "p_{T} (GeV)  ","Efficiency" );
    cosmesi(5,*&g_pt_signal_50_n_ossf, "p_{T} (GeV)  ","Efficiency" );
    cosmesi(6,*&g_pt_signal_20_n_ossf, "p_{T} (GeV)  ","Efficiency" );
    cosmesi(6,*&g_pt_signal_10_n_ossf, "p_{T} (GeV)  ","Efficiency" );
    
    
    TLegend *leg_n_ossf_pt_eff, *leg_ossf_pt_eff,*leg_n_ossf_pt_eff_2d, *leg_ossf_pt_eff_2d;
    
    TCanvas *c_pt_eff= new TCanvas("c_pt_eff","c_pt_eff");
    c_pt_eff->Divide(2,1);
    c_pt_eff->cd(1);
    g_pt_signal_50_ossf->Draw("ap");
    g_pt_signal_20_ossf->Draw("psame");
    g_pt_signal_10_ossf->Draw("psame");
    
    g_pt_zg_ossf->Draw("psame");
    g_pt_wg_ossf->Draw("psame");
    g_pt_wz_ossf->Draw("psame");
    g_pt_tt_ossf->Draw("psame");
    leg_ossf_pt_eff  = new TLegend(0.1,0.77,0.56,0.98);
    //leg_ossf_pt_eff->SetTextSize(0.3);
    leg_ossf_pt_eff ->SetHeader("OSSF pt_eff "); // option "C" allows to center the header
    leg_ossf_pt_eff ->AddEntry(g_pt_zg_ossf,"Z#gamma","p");
    leg_ossf_pt_eff ->AddEntry(g_pt_tt_ossf,"ttbar","p");
    leg_ossf_pt_eff ->AddEntry(g_pt_wg_ossf,"W#gamma","p");
    leg_ossf_pt_eff ->AddEntry(g_pt_wz_ossf,"WZ","p");
    leg_ossf_pt_eff ->AddEntry(g_pt_signal_50_ossf,"Majorana sample mN=50 GeV","p");
    leg_ossf_pt_eff ->AddEntry(g_pt_signal_20_ossf,"Majorana sample mN=20 GeV","p");
    leg_ossf_pt_eff ->AddEntry(g_pt_signal_10_ossf,"Majorana sample mN=10 GeV","p");
    
    leg_ossf_pt_eff ->Draw();
    c_pt_eff->cd(2);
    
    g_pt_signal_50_n_ossf->Draw("ap");
    g_pt_signal_20_n_ossf->Draw("psame");
    g_pt_signal_10_n_ossf->Draw("psame");
    
    g_pt_zg_n_ossf->Draw("psame");
    //g_pt_wg_n_ossf->Draw("psame");
    g_pt_wz_n_ossf->Draw("psame");
    g_pt_tt_n_ossf->Draw("psame");
    leg_n_ossf_pt_eff  = new TLegend(0.1,0.77,0.56,0.98);
    //leg_n_ossf_pt_eff->SetTextSize(0.05);
    leg_n_ossf_pt_eff ->SetHeader("n_ossf pt_eff "); // option "C" allows to center the header
    leg_n_ossf_pt_eff ->AddEntry(g_pt_zg_n_ossf,"Z#gamma","p");
    leg_n_ossf_pt_eff ->AddEntry(g_pt_tt_n_ossf,"ttbar","p");
    //leg_n_ossf_pt_eff ->AddEntry(g_pt_wg_n_ossf,"W#gamma","p");
    leg_n_ossf_pt_eff ->AddEntry(g_pt_wz_n_ossf,"WZ","p");
    leg_n_ossf_pt_eff ->AddEntry(g_pt_signal_50_n_ossf,"Majorana sample mN=50 GeV","p");
    leg_n_ossf_pt_eff ->AddEntry(g_pt_signal_20_n_ossf,"Majorana sample mN=20 GeV","p");
    leg_n_ossf_pt_eff ->AddEntry(g_pt_signal_10_n_ossf,"Majorana sample mN=10 GeV","p");
    
    leg_n_ossf_pt_eff ->Draw();
    c_pt_eff->Print("PLOT_PT/c_pt_eff_eem_max.root");
    delete  c_pt_eff ;
    
    
    TCanvas *c_pt_eff_2d= new TCanvas("c_pt_eff_2d","c_pt_eff_2d");
    c_pt_eff_2d->Divide(2,1);
    c_pt_eff_2d->cd(1);
    g_pt_roc_50_ossf->Draw("ap");
    g_pt_roc_20_ossf->Draw("psame");
    g_pt_roc_10_ossf->Draw("psame");
    leg_ossf_pt_eff_2d  = new TLegend(0.1,0.77,0.56,0.98);
    leg_ossf_pt_eff_2d ->AddEntry(g_pt_roc_50_ossf,"Majorana sample mN=50 GeV","p");
    leg_ossf_pt_eff_2d ->AddEntry(g_pt_roc_20_ossf,"Majorana sample mN=20 GeV","p");
    leg_ossf_pt_eff_2d ->AddEntry(g_pt_roc_10_ossf,"Majorana sample mN=10 GeV","p");
    leg_ossf_pt_eff_2d ->Draw();
    c_pt_eff_2d->cd(2);
    
    g_pt_roc_50_n_ossf->Draw("ap");
    g_pt_roc_20_n_ossf->Draw("psame");
    g_pt_roc_10_n_ossf->Draw("psame");
    leg_n_ossf_pt_eff_2d  = new TLegend(0.1,0.77,0.56,0.98);
    leg_n_ossf_pt_eff_2d ->AddEntry(g_pt_roc_50_n_ossf,"Majorana sample mN=50 GeV","p");
    leg_n_ossf_pt_eff_2d ->AddEntry(g_pt_roc_20_n_ossf,"Majorana sample mN=20 GeV","p");
    leg_n_ossf_pt_eff_2d ->AddEntry(g_pt_roc_10_n_ossf,"Majorana sample mN=10 GeV","p");
    
    leg_n_ossf_pt_eff_2d ->Draw();
    c_pt_eff_2d->Print("PLOT_PT/c_pt_eff_2d_eem_max.root");
    delete  c_pt_eff_2d ;    
    
    
}// end analisi
