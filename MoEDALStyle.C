//
// MoEDAL Style, based on a style file from ATLAS/BaBar
//

#include <iostream>

#include "MoEDALStyle.h"

#include "TROOT.h"

void SetMoEDALStyle ()
{
  static TStyle* MoEDALStyle = 0;
  std::cout << "\nApplying MoEDAL style settings...\n" << std::endl ;
  if ( MoEDALStyle==0 ) MoEDALStyle = MoEDALStyle();
  gROOT->SetStyle("MoEDAL");
  gROOT->ForceStyle();
}

TStyle* MoEDALStyle() 
{
  TStyle *MoEDALStyle = new TStyle("MoEDAL","MoEDAL style");

  // use plain black on white colors
  Int_t icol=0; // WHITE
  MoEDALStyle->SetFrameBorderMode(icol);
  MoEDALStyle->SetFrameFillColor(icol);
  MoEDALStyle->SetCanvasBorderMode(icol);
  MoEDALStyle->SetCanvasColor(icol);
  MoEDALStyle->SetPadBorderMode(icol);
  MoEDALStyle->SetPadColor(icol);
  MoEDALStyle->SetStatColor(icol);
  //MoEDALStyle->SetFillColor(icol); // don't use: white fill color for *all* objects

  // set the paper & margin sizes
  MoEDALStyle->SetPaperSize(20,26);

  // set margin sizes
  MoEDALStyle->SetPadTopMargin(0.05);
  MoEDALStyle->SetPadRightMargin(0.05);
  MoEDALStyle->SetPadBottomMargin(0.16);
  MoEDALStyle->SetPadLeftMargin(0.16);

  // set title offsets (for axis label)
  MoEDALStyle->SetTitleXOffset(1.4);
  MoEDALStyle->SetTitleYOffset(1.4);

  // use large fonts
  //Int_t font=72; // Helvetica italics
  Int_t font=42; // Helvetica
  Double_t tsize=0.05;
  MoEDALStyle->SetTextFont(font);

  MoEDALStyle->SetTextSize(tsize);
  MoEDALStyle->SetLabelFont(font,"x");
  MoEDALStyle->SetTitleFont(font,"x");
  MoEDALStyle->SetLabelFont(font,"y");
  MoEDALStyle->SetTitleFont(font,"y");
  MoEDALStyle->SetLabelFont(font,"z");
  MoEDALStyle->SetTitleFont(font,"z");
  
  MoEDALStyle->SetLabelSize(tsize,"x");
  MoEDALStyle->SetTitleSize(tsize,"x");
  MoEDALStyle->SetLabelSize(tsize,"y");
  MoEDALStyle->SetTitleSize(tsize,"y");
  MoEDALStyle->SetLabelSize(tsize,"z");
  MoEDALStyle->SetTitleSize(tsize,"z");

  // use bold lines and markers
  MoEDALStyle->SetMarkerStyle(20);
  MoEDALStyle->SetMarkerSize(1.2);
  MoEDALStyle->SetHistLineWidth(2.);
  MoEDALStyle->SetLineWidth(2.);
  MoEDALStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes

  // get rid of X error bars 
  //MoEDALStyle->SetErrorX(0.001);
  // get rid of error bar caps
  MoEDALStyle->SetEndErrorSize(0.);

  // do not display any of the standard histogram decorations
  MoEDALStyle->SetOptTitle(1);
  MoEDALStyle->SetTitleFillColor(0);
  MoEDALStyle->SetTitleBorderSize(0);
  MoEDALStyle->SetTitleFontSize(0.045);
  MoEDALStyle->SetTitleX(0.16);
  MoEDALStyle->SetTitleY(1.0);
  //MoEDALStyle->SetOptStat(1111);
  MoEDALStyle->SetOptStat(0);
  //MoEDALStyle->SetOptFit(1111);
  MoEDALStyle->SetOptFit(0);

  // put tick marks on top and RHS of plots
  MoEDALStyle->SetPadTickX(1);
  MoEDALStyle->SetPadTickY(1);

  return MoEDALStyle;

}

