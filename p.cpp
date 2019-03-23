#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main(int argc, char* argv[]){
	ofstream outfile;
	outfile.open(argv[2]);


	/* Branch Counter */
	int branchCount = 0;


	
	/* Variables for Gshare Predictor */
	int dg[2048];
	int game[2048];
	int predictorTable[2048];
	int prediction = 0;
	int gCount = 0;

	// Counter for Tournament Predictor
	int tCount;

	unsigned long long addr;
	string behavior;
	ifstream infile(argv[1]);
	
	for(int i = 0; i<2048;i++){
		dg[i] = 1;
		game[i] = 3;
		predictorTable[i] = 1;
	}
	while(infile >> hex >> addr >> behavior){
		int g = 0;
		int b = 0;
		int res = (((int)addr)&((int)(pow(2,11)-1)))^prediction;
		prediction = (prediction<<1)&((int)(pow(2,11))-1);
		if(behavior == "T"){
			if(game[addr%2048] > 2){
				if(dg[addr%2048] > 1){
					tCount++;
					b = 1;
				}
				if(predictorTable[res] > 1){
					//prediction++;
					g = 1;
				}
				//prediction++;
			}else{
				if(predictorTable[res] > 1){
					tCount++;
					//prediction++;
					g = 1;
				}
				if(dg[addr%2048] > 1){
					b = 1;
				}
			}
			prediction++;
			predictorTable[res] = min(3,predictorTable[res]+1);
			dg[addr%2048] = min(3,dg[addr%2048] + 1);
		}else{
			if(game[addr%2048] > 2){
				if(dg[addr%2048] < 2){
					tCount++;
					b = 1;
				}
				if(predictorTable[res] < 2){
					g = 1;
				}
			}else{
				if(predictorTable[res] < 2){
					tCount++;
					g = 1;
				}
				if(dg[addr%2048] < 2){
					b = 1;
				}
			}
			predictorTable[res] = max(0,predictorTable[res]-1);
			dg[addr%2048] = max(0,dg[addr%2048] - 1);

		}
		if(b>g){
			game[addr%2048] = min(7,game[addr%2048] + 1);
		}else if(g>b){
			game[addr%2048] = max(0,game[addr%2048] - 1);
		}
		branchCount++;
	}
	outfile<<tCount<<","<<branchCount<<"; "<<endl;


	return 0;
}


