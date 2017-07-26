#include "TFile.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TString.h"
#include "TTree.h"
#include "TEntryList.h"
#include "Riostream.h"
#include "TCut.h"
#include "TH1.h"
#include "TVector.h"
#include "TVector3.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <sstream>
#include <cmath>
#include <signal.h>
#include <string.h>

#include "Math/Vector3D.h"
#include "Math/Vector4D.h"


#include "AIDA_packed.h"

using namespace std;

int main( int argv, char* argc[]){

	TString fin;
	char fi[128];
	const int maxasic=196*2;
	const int maxmult=32;	
	const int maxpix =10000;
	if(argv==4){
		int mode=atoi(argc[3]);
		if(mode==0){
			string name=argc[1];
			strcpy(fi,name.c_str());
			//	sprintf(fi,"$AIDADIR/R%4d_%d_packed.root",mainnum,subnum);	
			fin=argc[2];
		}
		else{std::cout<<"USAGE of name assigning mode: ./newevent inputname outputname 0"<<std::endl; return -1;}
	}else if(argv==3){

		int mainnum= atoi(argc[1]);
		int subnum = atoi(argc[2]);
		sprintf(fi,"$AIDADIR/R%4d_%d_packed.root",mainnum,subnum);	
		fin=Form("$AIDADIR/R%4d_%d_packed_eventbuild.root",mainnum,subnum);

	}else {std::cout<<"USAGE: ./newevent AIDARUN# AIDASUBRUN# "<<endl; return -1;}

	AIDA_packed aidapa(fi);
	std::cout<<"File output : "<<fin<<std::endl;

	TFile* fo = new TFile(fin,"RECREATE");

	int mulpix,pixelx[maxpix],pixely[maxpix],pixelz[maxpix];
	int vx[6][maxmult],vy[6][maxmult];
	double pixelEX[maxpix],pixelEY[maxpix];
	double adcEX[6][maxmult],adcEY[6][maxmult];
	//Long64_t pixelts[maxpix];

	Long64_t tstart, tstop, extTstart, extTstop, t_del, extT_del;
	Long64_t timestamp[maxasic][maxmult],extTimestamp[maxasic][maxmult];
	Int_t mulasic,multitot;
	Int_t fire_flag[6][2],asicNo[maxasic],dssdNo[maxasic],multi[maxasic];
	Int_t stripNo[maxasic][maxmult],adcData[maxasic][maxmult],rangeType[maxasic][maxmult];
	Int_t hitX[6],hitY[6];
	Double_t EX[6],EY[6],X[6],Y[6];
	Double_t adcE[maxasic][maxmult];
	Double_t tempx[6],tempy[6];
	Int_t flag_beta_x,flag_beta_y,flag_pulser,goodness;
	Double_t stop_x,stop_y, start_x,start_y;
	Int_t stop_z,emptyz,start_z;
	//	std::vector<ROOT::Math::XYZVector>* hitpixel = new std::vector<ROOT::Math::XYZVector>(10000);
	//	ROOT::Math::XYZVector a;
	//	std::vector<double>* vx=new std::vector<double>();
	//	std::vector<double>* vy=new std::vector<double>();

	TTree* ion = new TTree("ion","ion");
	ion->Branch("tstart",&tstart,"tstart/L");
	ion->Branch("tstop",&tstop,"tstop/L");
	ion->Branch("extTstart",&extTstart,"extTstart/L");
	ion->Branch("extTstop",&extTstop,"extTstop/L");
	ion->Branch("t_del",&t_del,"t_del/L");
	ion->Branch("extT_del",&extT_del,"extT_del/L");
	ion->Branch("mulasic",&mulasic,"mulasic/I");
	ion->Branch("multitot",&multitot,"multitot/I");
	ion->Branch("stop_x",&stop_x,"stop_x/D");
	ion->Branch("stop_y",&stop_y,"stop_y/D");
	ion->Branch("stop_z",&stop_z,"stop_z/I");
	ion->Branch("goodness",&goodness,"goodness/I");

	ion->Branch("fire_flag",fire_flag,"fire_flag[6][2]/I");
	ion->Branch("EX",EX,"EX[6]/D");
	ion->Branch("EY",EY,"EY[6]/D");
	ion->Branch("X",X,"X[6]/D");
	ion->Branch("Y",Y,"Y[6]/D");
	ion->Branch("hitX",hitX,"hitX[6]/I");
	ion->Branch("hitY",hitY,"hitY[6]/I");

	ion->Branch("asicNo",asicNo,"asicNo[mulasic]/I");
	ion->Branch("dssdNo",dssdNo,"dssdNo[mulasic]/I");
	ion->Branch("multi",multi,"multi[mulasic]/I");

	ion->Branch("timestamp",timestamp,"timestamp[mulasic][16]/L");
	ion->Branch("extTimestamp",extTimestamp,"extTimestamp[mulasic][16]/L");
	ion->Branch("stripNo",stripNo,"stripNo[mulasic][16]/I");
	ion->Branch("adcData",adcData,"adcData[mulasic][16]/I");
	ion->Branch("rangeType",rangeType,"rangeType[mulasic][16]/I");
	ion->Branch("adcE",adcE,"adcE[mulasic][16]/D");


	TTree* beta = new TTree("beta","beta");

	beta->Branch("tstart",&tstart,"tstart/L");
	beta->Branch("tstop",&tstop,"tstop/L");
	beta->Branch("extTstart",&extTstart,"extTstart/L");
	beta->Branch("extTstop",&extTstop,"extTstop/L");
	beta->Branch("t_del",&t_del,"t_del/L");
	beta->Branch("extT_del",&extT_del,"extT_del/L");
	beta->Branch("mulasic",&mulasic,"mulasic/I");
	beta->Branch("multitot",&multitot,"multitot/I");
	beta->Branch("start_x",&start_x,"start_x/D");
	beta->Branch("start_y",&start_y,"start_y/D");
	beta->Branch("start_z",&start_z,"start_z/I");
	beta->Branch("flag_pulser",&flag_pulser,"flag_pulser/I");
	beta->Branch("goodness",&goodness,"goodness/I");

	beta->Branch("fire_flag",fire_flag,"fire_flag[6][2]/I");
	beta->Branch("EX",EX,"EX[6]/D");
	beta->Branch("EY",EY,"EY[6]/D");
	beta->Branch("X",X,"X[6]/D");
	beta->Branch("Y",Y,"Y[6]/D");
	beta->Branch("hitX",hitX,"hitX[6]/I");
	beta->Branch("hitY",hitY,"hitY[6]/I");
	//beta->Branch("hitpixel",&hitpixel); 					//vector for all cross point

	beta->Branch("mulpix",&mulpix,"mulpix/I");
	beta->Branch("pixelx",pixelx,"pixelx[mulpix]/I");
	beta->Branch("pixely",pixely,"pixely[mulpix]/I");
	beta->Branch("pixelz",pixelz,"pixelz[mulpix]/I");
	beta->Branch("pixelEX",pixelEX,"pixelEX[mulpix]/D");
	beta->Branch("pixelEY",pixelEY,"pixelEY[mulpix]/D");
//	beta->Branch("pixelts",pixelts,"pixelts[mulpix]/L");

	beta->Branch("asicNo",asicNo,"asicNo[mulasic]/I");
	beta->Branch("dssdNo",dssdNo,"dssdNo[mulasic]/I");
	beta->Branch("multi",multi,"multi[mulasic]/I");

	beta->Branch("timestamp",timestamp,"timestamp[mulasic][16]/L");
	beta->Branch("extTimestamp",extTimestamp,"extTimestamp[mulasic][16]/L");
	beta->Branch("stripNo",stripNo,"stripNo[mulasic][16]/I");
	beta->Branch("adcData",adcData,"adcData[mulasic][16]/I");
	beta->Branch("rangeType",rangeType,"rangeType[mulasic][16]/I");
	beta->Branch("adcE",adcE,"adcE[mulasic][16]/D");


	double cal0[6][256],cal1[6][256],thresh[6][256],c0,c1,tempEX,tempEY;
	int dssd_index, strip_index;	
	int i,j,ii,iii,premulasic,ilast,testi;
	int ttt;
	time_t tm;
	double E_prev=0,E_prev_sub=0;
	int sub_start_z=-1;
	std::ifstream calf("/media/bae/data1/NP1306/AIDA/aidaanalysis/aidaeventbuilder/cal_table_BiCocal_R17.txt"); // only for beta

	while(calf.good()){
		calf>>dssd_index>>strip_index>>c0>>c1;
		cal0[dssd_index][strip_index]=c0; //offset
		cal1[dssd_index][strip_index]=c1; //slope
	}
	std::cout<<fixed<<setprecision(4)<<"The last strip has offset : "<<c0<<" and slope "<<c1<<std::endl;
	if(cal1[0][0]!=0) {std::cout<<"cal table is loaded"<<std::endl;}
	std::ifstream thrf("/media/bae/data1/NP1306/AIDA/aidaanalysis/aidaeventbuilder/threshold_table_fix_7xicma.txt");

	for(i=0;i<6;i++){
		for(j=0;j<256;j++){
			thresh[i][j]=560;
		}
	}

	while(thrf.good()){
		thrf>>dssd_index>>strip_index>>c0;
		thresh[dssd_index][strip_index]=c0;
	}
	if(thresh[0][0]!=0) {std::cout<<"thresh table is loaded"<<std::endl;}
	std::cout<<fixed<<setprecision(4)<<"The last strip has threshold : "<<c0<<std::endl;

	map<Long64_t, Long64_t> fakemap;
	map<Long64_t, Long64_t>::iterator ifakemap;



	std::cout<<"Initialization Done"<<std::endl;

	Long64_t nlist = aidapa.GetEntriesFast();
	Long64_t indi;
	std::cout<<"number of entries of parsed data is "<<nlist<<std::endl;

	//----------------------------------------------------------------------------------------------//

	std::cout<<"Start building ion events"<<std::endl;
	Long64_t ion_w = 4000; //40us window between asic fired
	Long64_t beta_w = 4000; //40us window between asic fired
	i=0;
	premulasic=0;
	tstop=0;
	extTstop=0;
	ttt=time(&tm);

	while(i<nlist){

		aidapa.GetEntry(i);
		if(aidapa.extT0 < extTstart+20000){
			i++;
		}else if(aidapa.ion_flag==1){

			//Initialize and reset the parameters

			tstart=aidapa.t0;
			t_del=tstart-tstop;
			extTstart=aidapa.extT0;
			extT_del=extTstart-extTstop;
			mulasic=0;
			multitot=0;
			goodness=0;
			stop_x=-1;
			stop_y=-1;
			stop_z=-1;
			emptyz=-1;
			for(ii=0;ii<6;ii++){
				EX[ii]=0;
				EY[ii]=0;
				fire_flag[ii][0]=0;
				fire_flag[ii][1]=0;
				X[ii]=-1;
				Y[ii]=-1;
				hitX[ii]=0;
				hitY[ii]=0;
				tempx[ii]=0;
				tempy[ii]=0;
			}

			for(ii=0;ii<premulasic;ii++){
				asicNo[ii]=0;
				dssdNo[ii]=0;
				multi[ii]=0;
				for(iii=0;iii<maxmult;iii++){
					timestamp[ii][iii]		=0; 
					extTimestamp[ii][iii]	=0;
					stripNo[ii][iii]		=0;
					adcData[ii][iii]		=0;
					rangeType[ii][iii]		=-1;
					adcE[ii][iii]		=0;
				}
			}


			//Start veto looping for beta from ion input.
			int iveto=i;
			while( aidapa.extT0>=extTstart && aidapa.extT0*4 < extTstart*4 +20000 && iveto<nlist){
				ifakemap=fakemap.find(iveto);
				if(aidapa.ion_flag==0 && ifakemap==fakemap.end() ){
					fakemap.insert(std::make_pair(iveto,1));
				}
				iveto++;
				if(iveto<nlist) aidapa.GetEntry(iveto);
			}
			aidapa.GetEntry(i);

			//Start looping for an event	
			//while( aidapa.extT0>= extTstart && aidapa.extT0*4<extTstart*4+ion_w && i< nlist){
			while( aidapa.extT0>= extTstart && aidapa.extT0*4<extTstart*4+ion_w && i< nlist){
				if(aidapa.ion_flag==1){
					asicNo[mulasic]=aidapa.asicNo;
					dssdNo[mulasic]=aidapa.dssdNo[0];
					multi[mulasic]=aidapa.multinum;				
					if(fire_flag[aidapa.dssdNo[0]][1]==0 && aidapa.stripNo[0]>127) {fire_flag[aidapa.dssdNo[0]][1]=1;}
					else if(fire_flag[aidapa.dssdNo[0]][0]==0 && aidapa.stripNo[0]<127) {fire_flag[aidapa.dssdNo[0]][0]=1;}

					for(iii=0;iii<aidapa.multinum;iii++){
						timestamp[mulasic][iii]		=  aidapa.timestamp[iii];
						extTimestamp[mulasic][iii]	=  aidapa.extTimestamp[iii];
						stripNo[mulasic][iii]		=  aidapa.stripNo[iii];
						adcData[mulasic][iii]		=  aidapa.adcData[iii];
						rangeType[mulasic][iii]		=  aidapa.rangeType[iii];
						if(rangeType[mulasic][iii]==1){adcE[mulasic][iii]=aidapa.adcData[iii];}
						else if (rangeType[mulasic][iii]==0){adcE[mulasic][iii]=0.001*(aidapa.adcData[iii]*cal1[aidapa.dssdNo[0]][aidapa.stripNo[iii]]+cal0[aidapa.dssdNo[0]][aidapa.stripNo[iii]]);}
					}
				ilast=i;
				mulasic++;
				multitot+=aidapa.multinum;

				}else if(aidapa.ion_flag==0){
					//			ifakemap=fakemap.find(i);
					//				if(ifakemap==fakemap.end()){
					//				fakemap.insert(std::make_pair(i,1));
					//				}
				/*	asicNo[mulasic]=aidapa.asicNo;
					dssdNo[mulasic]=aidapa.dssdNo[0];
					multi[mulasic]=aidapa.multinum;				
					if(fire_flag[aidapa.dssdNo[0]][1]==0 && aidapa.stripNo[0]>127) {fire_flag[aidapa.dssdNo[0]][1]=1;}
					else if(fire_flag[aidapa.dssdNo[0]][0]==0 && aidapa.stripNo[0]<127) {fire_flag[aidapa.dssdNo[0]][0]=1;}

					for(iii=0;iii<aidapa.multinum;iii++){
						timestamp[mulasic][iii]		=  aidapa.timestamp[iii];
						extTimestamp[mulasic][iii]	=  aidapa.extTimestamp[iii];
						stripNo[mulasic][iii]		=  aidapa.stripNo[iii];
						adcData[mulasic][iii]		=  aidapa.adcData[iii];
						rangeType[mulasic][iii]		=  aidapa.rangeType[iii];
						adcE[mulasic][iii] = 0.001*(aidapa.adcData[iii]*cal1[aidapa.dssdNo[0]][aidapa.stripNo[iii]]+cal0[aidapa.dssdNo[0]][aidapa.stripNo[iii]]);
					}
				*/
				}

				i++;

				if(i<nlist) {aidapa.GetEntry(i);}
			}

			//Start calculate ESum and E_weighted_position
			for(ii=0;ii<mulasic;ii++){
				for(iii=0;iii<multi[ii];iii++){
					//if((adcE[ii][iii]>150 && rangeType[ii][iii]==0) || rangeType[ii][iii]==1){
					if((adcE[ii][iii]*1000 > 150 && rangeType[ii][iii]==0) || rangeType[ii][iii]==1){ 		//test for calibration effect
						if(stripNo[ii][iii]<128 && stripNo[ii][iii]>-1){
							EX[dssdNo[ii]]	  +=  adcE[ii][iii];
							tempx[dssdNo[ii]] +=  stripNo[ii][iii]*adcE[ii][iii];
							hitX[dssdNo[ii]]+=1;
						}else if(stripNo[ii][iii]>127 && stripNo[ii][iii]<256){
							EY[dssdNo[ii]]	  +=  adcE[ii][iii];
							tempy[dssdNo[ii]] +=  (stripNo[ii][iii]-128)*adcE[ii][iii];
							hitY[dssdNo[ii]]+=1;
						}else {std::cout<<"The strip No is wrong"<<std::endl; return -1;}
					}
				}
			}
			for(ii=0;ii<6;ii++){
				if(EX[ii]!=0) X[ii]=1.0*tempx[ii]/EX[ii];
				if(EY[ii]!=0) Y[ii]=1.0*tempy[ii]/EY[ii];
			}
			stop_z=-1;
			emptyz=-1;
			for(ii=0;ii<6;ii++){
				if( X[ii]>-1 || Y[ii]>-1)
				{
					stop_z=ii;
					if(X[ii]>-1) {stop_x=X[ii];}
					if(Y[ii]>-1) {stop_y=Y[ii];}
				}else if(emptyz<0){
					emptyz=ii;
				}
			}
			if(stop_z>emptyz && stop_z>-1 && stop_x>-1 && stop_y>-1) goodness=1;
			//			emptyz=0;
			aidapa.GetEntry(ilast);
			premulasic=mulasic;
			extTstop=aidapa.extT0;
			tstop=aidapa.t0;
			//		extTstop=aidapa.extT0;

			//for(ii=0;ii<6;ii++){
			//		}

			ion->Fill();
		}else i++;

		indi++;
		if(indi%10000==0) {std::cout<<"\rThe event building progress : "<<fixed<<setprecision(4)<<100.0*i/nlist<<"\%"<<". Elapsed time : "<<time(&tm)-ttt<<"s"; std::cout.flush();}

		}

		std::cout<<std::endl<<"Ion event building is finished. "<<ion->GetEntriesFast()<<" filled tree"<<std::endl;

		//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------//

		std::cout<<"Start building beta events"<<std::endl;
		i=0;
		ilast=0;
		premulasic=0;
		indi=0;	
		tstop=0;
		extTstop=0;
		testi=0;
		while(i<nlist){
			testi=aidapa.GetEntry(i);
			if(testi==0){ cout<<"wrong entry input here "<<i<<"entry is not exist"<<endl; return -1;}

			ifakemap=fakemap.find(i);		

			if(aidapa.ion_flag==0 && ifakemap==fakemap.end()){
				//Initialize and reset the parameters
				flag_pulser=0;
				tstart=aidapa.t0;
				t_del=tstart-tstop;
				extTstart=aidapa.extT0;
				extT_del=extTstart-extTstop;
				//start_z=aidapa.dssdNo[0];
				start_z = -1;
				start_x = -1;
				start_y = -1;
				goodness=0;
				mulasic=0;
				multitot=0;
				for(ii=0;ii<6;ii++){
					EX[ii]=0;
					EY[ii]=0;
					fire_flag[ii][0]=0;
					fire_flag[ii][1]=0;
					X[ii]=-1;
					Y[ii]=-1;
					hitX[ii]=0;
					hitY[ii]=0;
					tempx[ii]=0;
					tempy[ii]=0;
				}

				for(ii=0;ii<premulasic;ii++){
					asicNo[ii]=0;
					dssdNo[ii]=0;
					multi[ii]=0;
					for(iii=0;iii<maxmult;iii++){
						timestamp[ii][iii]		=0; 
						extTimestamp[ii][iii]		=0;
						stripNo[ii][iii]		=-1;
						adcData[ii][iii]		=-1;
						rangeType[ii][iii]		=-1;
						adcE[ii][iii]			=0;
					}
				}
				for(ii=0;ii<6;ii++){
					for(iii=0;iii<maxmult;iii++){
						vx[ii][iii] 			=-1;
						vy[ii][iii] 			=-1;
					}
				}
				//hitpixel->clear();

				//Start looping for an event	
				while( aidapa.extT0 >= extTstart && aidapa.extT0*4 < extTstart*4+beta_w && i<nlist && ifakemap==fakemap.end()){
					if(aidapa.ion_flag==0){
						if(fire_flag[aidapa.dssdNo[0]][1]==0 && aidapa.stripNo[0]>127) {fire_flag[aidapa.dssdNo[0]][1]=1;}
						else if(fire_flag[aidapa.dssdNo[0]][0]==0 && aidapa.stripNo[0]<127) {fire_flag[aidapa.dssdNo[0]][0]=1;}

						for(iii=0;iii<aidapa.multinum;iii++){
							timestamp[mulasic][iii]		=  aidapa.timestamp[iii];
							extTimestamp[mulasic][iii]	=  aidapa.extTimestamp[iii];
							stripNo[mulasic][iii]		=  aidapa.stripNo[iii];
							adcData[mulasic][iii]		=  aidapa.adcData[iii];
							adcE[mulasic][iii]		=  aidapa.adcData[iii]*cal1[aidapa.dssdNo[0]][aidapa.stripNo[iii]]+cal0[aidapa.dssdNo[0]][aidapa.stripNo[iii]];
							rangeType[mulasic][iii]		=  aidapa.rangeType[iii];
						}
						asicNo[mulasic]=aidapa.asicNo;
						dssdNo[mulasic]=aidapa.dssdNo[0];
						multi[mulasic]=aidapa.multinum;				

						mulasic++;
						multitot+=aidapa.multinum;
						ilast=i;
					}
					i++;
					ifakemap=fakemap.find(i);
					if(i<nlist) testi=aidapa.GetEntry(i);
					if(testi==0){ cout<<"wrong entry input here "<<i<<"entry is not exist"<<endl; return -1;}

				}

				//Start calculate ESum and E_weighted_position
				for(ii=0;ii<mulasic;ii++){
					flag_beta_x=0;
					flag_beta_y=0;

					for(iii=0;iii<multi[ii];iii++){
						if(multi[ii]<maxmult){
							if(adcE[ii][iii]>150){			

								if(stripNo[ii][iii]<128 && stripNo[ii][iii]>-1){
									EX[dssdNo[ii]]+=adcE[ii][iii];
									tempx[dssdNo[ii]]+=stripNo[ii][iii]*adcE[ii][iii];
									vx[dssdNo[ii]][iii]=stripNo[ii][iii];
									adcEX[dssdNo[ii]][iii]=adcE[ii][iii];
									flag_beta_x=1;
									hitX[dssdNo[ii]]+=1;
								}else if(stripNo[ii][iii]>127 && stripNo[ii][iii]<256){
									EY[dssdNo[ii]]+=adcE[ii][iii];
									tempy[dssdNo[ii]]+=(stripNo[ii][iii]-128)*adcE[ii][iii];
									vy[dssdNo[ii]][iii]=stripNo[ii][iii]-128;
									adcEY[dssdNo[ii]][iii]=adcE[ii][iii];
									flag_beta_y=1;
									hitY[dssdNo[ii]]+=1;
								}else {std::cout<<"The strip No is wrong"<<std::endl; return -1;}
							}
						}else {std::cout<<"multi over maxmult. It is "<<multi[ii]<<std::endl; return -1;}
					}
				}

				E_prev=0,E_prev_sub=0;
				sub_start_z=-1;

				if(multitot>64) flag_pulser=1;
				for(ii=0;ii<6;ii++){
					if(EX[ii] > E_prev) {start_z=ii; E_prev=EX[ii]; } // Since layer 1 has bad y strip, Only compare the EX. Here the most of energy is supposed to be deposited in the first layer.
					if(EY[ii] > E_prev_sub) {sub_start_z=ii; E_prev_sub=EY[ii];}
					if(EX[ii]>0) X[ii]=1.0*tempx[ii]/EX[ii];
					if(EY[ii]>0) Y[ii]=1.0*tempy[ii]/EY[ii];
				}

				if(start_z>-1){
					start_x=X[start_z];
					start_y=Y[start_z];
					if(start_x>-1 && start_y>-1 && flag_pulser==0) {goodness=1;}
					if(start_z==1 && start_y==-1 && start_x>-1 && flag_pulser==0)
					{
						if(sub_start_z>-1) {
						start_y=Y[sub_start_z];
						if(start_y>-1){
						goodness=2;
						}}
					}
				}
				aidapa.GetEntry(ilast);
				premulasic=mulasic;
				//		preextTstop=extTstop;
				tstop=aidapa.t0;
				extTstop=aidapa.extT0;
				mulpix=0;
				if(flag_pulser==0){
					for(ii=0;ii<6;ii++){
						if(hitX[ii]>0 && hitY[ii]>0){
							for(int ix=0;ix<hitX[ii];ix++){
								for(int iy=0;iy<hitY[ii];iy++){
									if(vx[ii][ix]>-1 && vy[ii][iy]>-1){
										pixelx[mulpix]=vx[ii][ix];
										pixely[mulpix]=vy[ii][iy];
										pixelz[mulpix]=ii;
										pixelEX[mulpix]=adcEX[ii][ix];
										pixelEY[mulpix]=adcEY[ii][iy];
										mulpix+=1;
									}
								}
							}
						}
					}
				}

				beta->Fill();

			}else i++;

			indi++;
			if(indi%10000==0) {std::cout<<"\rThe event building progress : "<<fixed<<setprecision(4)<<100.0*i/nlist<<"\%"<<". Elapsed time : "<<time(&tm)-ttt<<"s"; std::cout.flush();}

		}
		std::cout<<std::endl<<"Beta event building is finished. "<<beta->GetEntriesFast()<<" filled tree"<<std::endl;

		fo->WriteTObject(ion);
		fo->WriteTObject(beta);
		fo->Close();
		return 1;
	}
