#ifndef ANALYSIS_SIGNAL_H
#define ANALYSIS_SIGNAL_H
#include "TObject.h"



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




class Analysis_signal : public TObject {
    
public:
    
    
  Analysis_signal();
  Analysis_signal(string FileNameTree_in);
  virtual ~Analysis_signal();
  void selection_ossf(  int massa,
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
TH2D *signal_60_2d_pt_n_ossf);

    
private:
    
    
    
    
    ClassDef(Analysis_signal,1) 
};

#endif



