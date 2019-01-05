{

  int i,ii,j,jj,k,kk,xx;

  gROOT->ProcessLine("#include <vector>");

  onehalf = 5;
  string tag="~/Dropbox/School/Y3S2/CERN_FYP/Simulations/Scripts/Files/dy_20000/tag_13TeV1/";

  string geotag="default";
  //string geotag="maximal";
  //string geotag="minimal";

  int kmin=0;
  int kmax=6;
  int kkmin=0; 
  int kkmax=10; 

  int nexclude=0;
  int kkkexclude[1000][2];
  kkkexclude[0][0]=4;kkkexclude[0][1]=1;

  int kmaxmax=6;   /// value it has normally if all jobs succeeded
  int kkmaxmax=10; /// value it has normally if all jobs succeeded

  gROOT->LoadMacro("MoEDALStyle.C");
  SetMoEDALStyle();

  ///// load files

  TFile *ff[kmaxmax][kkmaxmax];

  string charge[kmaxmax]={"_q10","_q20","_q30","_q40","_q50","_q60"};
  string mass[kkmaxmax]={"_m200","_m500","_m1000","_m1500","_m2000","_m2500","_m3000","_m4000","_m5000","_m6000"};
  string filename;
  string name[kmaxmax][kkmaxmax];

  for(k=kmin;k<kmax;k++) {
    for(kk=kkmin;kk<kkmax;kk++) {
      name[k][kk]=charge[k]+mass[kk];
      bool exclude=0;
      for(xx=0;xx<nexclude;xx++) 
          if(kkkexclude[xx][0]==k && kkkexclude[xx][1]==kk) 
              exclude=1;
          
      if(!exclude) {
	if(onehalf == 0) {
	  filename=tag+geotag+"/SpinHalf/DY"+charge[k]+mass[kk]+"/MonopoleData.root";
	}	
	else if (onehalf == 1) {
	  filename=tag+geotag+"/SpinZero/DY"+charge[k]+mass[kk]+"/MonopoleData.root";
	}	
	else if(onehalf == 2) {
	  filename=tag+geotag+"/SpinOne/DY"+charge[k]+mass[kk]+"/MonopoleData.root";
	} 
	else if (onehalf == 3) {
	  filename=tag+geotag+"/SpinHalfBeta/DY"+charge[k]+mass[kk]+"/MonopoleData.root";
	} 
	else if (onehalf == 4) {
	  filename=tag+geotag+"/SpinZeroBeta/DY"+charge[k]+mass[kk]+"/MonopoleData.root";
	} 
	else if (onehalf == 5) {
	  filename=tag+geotag+"/SpinOneBeta/DY"+charge[k]+mass[kk]+"/MonopoleData.root";
	} 
	ff[k][kk]=new TFile(filename.c_str());   
      }
    }  
  } 

  ///// fill ntuples

  vector<float> *MMT_hit_z;
  int events[kmaxmax][kkmaxmax];
  int MMT[kmaxmax][kkmaxmax];
  for(k=kmin;k<kmax;k++) {
    for(kk=kkmin;kk<kkmax;kk++) {  
      events[k][kk]=0; 
      MMT[k][kk]=0; 
    }
  }    
  TTree *tt;
  bool atleastoneMMThitthisevent;
  for(k=kmin;k<kmax;k++) {
    for(kk=kkmin;kk<kkmax;kk++) {  
      bool exclude=0;
      for(xx=0;xx<nexclude;xx++) 
          if(kkkexclude[xx][0]==k && kkkexclude[xx][1]==kk) 
              exclude=1;
      if(!exclude) {
	tt=(TTree*) ff[k][kk]->Get("MonopoleNtuple");     
	tt->SetBranchAddress("mmthit_hit_z",&MMT_hit_z);
      
	cout << " k=" << k << " kk=" << kk << endl;
	for (int ievt=0;ievt<tt->GetEntries();ievt++) {    ///// event loop
	  tt->GetEntry(ievt);
	  events[k][kk]++;
	  atleastoneMMThitthisevent=0;
	  for(ii=0;ii<MMT_hit_z->size();ii++) {     ///// MMT hit loop
	    if((*MMT_hit_z)[ii]<-1000) atleastoneMMThitthisevent=1; 
	  }  
	  if(atleastoneMMThitthisevent) MMT[k][kk]++;
	}  
      }
    }
  }    

  float acc[kmaxmax][kkmaxmax];
  float accerr[kmaxmax][kkmaxmax];
  for(k=kmin;k<kmax;k++) {
    for(kk=kkmin;kk<kkmax;kk++) {  
      bool exclude=0;
      for(xx=0;xx<nexclude;xx++) 
          if(kkkexclude[xx][0]==k && kkkexclude[xx][1]==kk) 
              exclude=1;
      if(!exclude) {
	acc[k][kk]=(float) MMT[k][kk]/events[k][kk];
	if(MMT[k][kk]>0) accerr[k][kk]=(float) acc[k][kk]*sqrt(MMT[k][kk])/MMT[k][kk];
      }
    }
  }  

  ///// save to file

  string outfilename;

  if(onehalf == 0) {
    outfilename="SpinHalf_"+geotag+".txt";
  }
  else if (onehalf == 1) {
    outfilename="SpinZero_"+geotag+".txt";
  } 
  else if(onehalf == 2) {
    outfilename="SpinOne_"+geotag+".txt";
  } 
  else if (onehalf == 3) {
    outfilename="SpinHalfBeta_"+geotag+".txt";
  } 
  else if (onehalf == 4) {
    outfilename="SpinZeroBeta_"+geotag+".txt";
  } 
  else if (onehalf == 5) {
    outfilename="SpinOneBeta_"+geotag+".txt";
  } 

  ofstream fout(outfilename.c_str());

  string c[kmaxmax]={"1","2","3","4","5","6"};
  string m[kkmaxmax]={"200","500","1000","1500","2000","2500","3000","4000","5000","6000"};

  for(k=kmin;k<kmax;k++) {
    for(kk=kkmin;kk<kkmax;kk++) {  
      fout << c[k] << " " << m[kk] << " " << acc[k][kk] << " " << accerr[k][kk] << endl;
    }  
  }



}
