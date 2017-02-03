#ifndef ANALYSIS_H
#define ANALYSIS_H
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


    
    
class Analysis : public TObject {
        
 public:
        
        
  Analysis();
  Analysis(string FileNameTree_in);
  virtual ~Analysis();
        
  void   selection_ossf(  int num_histo_kin,
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
			  TH2D* wg_2d_ossf,
			  TH2D *wz_2d_ossf,
			  TH2D* zg_2d_ossf,
			  TH2D* tt_2d_ossf,
			  TH2D* wg_2d_n_ossf,
			  TH2D* wz_2d_n_ossf,
			  TH2D* zg_2d_n_ossf,
			  TH2D* tt_2d_n_ossf,
			  TH2D* dy1_2d_ossf,
			  TH2D* dy2_2d_ossf,
			  TH2D* dy1_2d_n_ossf,
			  TH2D* dy2_2d_n_ossf);
  



		
        
 private:
        

        
        
  ClassDef(Analysis,1) 
};
    
#endif
    
    
    
