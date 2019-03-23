#include "work.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

	string line;
	string correct;

	string input = "../traces/short_trace1.txt";
	string output;
	int gottems = 0;
	int totals = 0;

	work greg;

	//open 
	ifstream infile(input);
	
	while(infile >> std::hex >> line >> correct){
		if(greg.taken(greg.hex2bi(line), correct)){
			gottems += 1;
		}
		totals += 1;
	}

//	printf("%s", line);
//	printf("\n");
//	printf("%s", correct);
//	printf("\n\n");

	printf("gottems: %d\n" , gottems);
	printf("totals: %d\n", totals);

	ofstream myfile;
	myfile.open(output);
	myfile << gottems << "," << totals << ";\n" ;

	gottems = 0;
	totals = 0;

	infile.close();
	//OH BOY! I really hope this works

	ifstream infile2(input);

	while(infile2 >> std::hex >> line >>correct){
		if(greg.nontaken(greg.hex2bi(line), correct)){
			gottems += 1;
		}
		totals += 1;
	}

	printf("\ngottems: %d\n" , gottems);
	printf("totals: %d\n", totals);

	myfile << gottems << "," << totals << ";\n" ;

	gottems = 0;
	totals = 0;

	infile2.close();
	// Prepare for single bit bimodal!!! (part 1: size 16)

	for(int i = 0; i < 2048; i++){
		greg.singTable.push_back(00);
	}

	ifstream infile3(input);

	while(infile3 >> std::hex >> line >> correct){
//		printf("grig grog\n");
		if(greg.singBit(greg.hex2bi(line), correct, 4)){
			gottems += 1;
		}
		totals += 1;
		//printf("ooga booga\n");
	}

//	printf("%d", greg.correct);
	printf("\ngottems: %d\n" , gottems);
	printf("totals: %d\n", totals);

	myfile << gottems << "," << totals << ";";


	gottems = 0;
	totals = 0;


	for(int i = 0; i < 2048; i++){
		greg.singTable[i] = 0;
	}

	ifstream infile3b(input);

	while(infile3b >> std::hex >> line >> correct){
		if(greg.singBit(greg.hex2bi(line), correct, 5)){
			gottems += 1;
		}
		totals += 1;
	}

	myfile << gottems << "," << totals << ";";

	gottems = 0;
	totals = 0;


	for(int i = 0; i < 2048; i++){
		greg.singTable[i] = 0;
	}

	ifstream infile3c(input);

	while(infile3c >> std::hex >> line >> correct){
		if(greg.singBit(greg.hex2bi(line), correct, 7)){
			gottems += 1;
		}
		totals += 1;
	}

	myfile << gottems << "," << totals << ";";

	gottems = 0;
	totals = 0;


	for(int i = 0; i < 2048; i++){
		greg.singTable[i] = 0;
	}

	ifstream infile3d(input);

	while(infile3d >> std::hex >> line >> correct){
		if(greg.singBit(greg.hex2bi(line), correct, 8)){
			gottems += 1;
		}
		totals += 1;
	}

	myfile << gottems << "," << totals << ";";

	gottems =0;
	totals = 0;


	for(int i = 0; i < 2048; i++){
		greg.singTable[i] = 0;
	}

	ifstream infile3e(input);

	while(infile3e >> std::hex >> line >> correct){
		if(greg.singBit(greg.hex2bi(line), correct, 9)){
			gottems += 1;
		}
		totals += 1;
	}

	myfile << gottems << "," << totals << ";";

	gottems = 0;
	totals = 0;

	for(int i = 0; i < 2048; i++){
		greg.singTable[i] = 0;
	}

	ifstream infile3f(input);

	while(infile3f >> std::hex >> line >>correct){
		if(greg.singBit(greg.hex2bi(line), correct, 10)){
			gottems += 1;
		}
		totals += 1;
	}

	myfile << gottems << "," << totals << ";";

	gottems = 0;
	totals = 0;

	for(int i = 0; i < 2048; i++){
		greg.singTable[i] = 0;
	}

	ifstream infile3g(input);

	while(infile3g >> std::hex >> line >> correct){
		if(greg.singBit(greg.hex2bi(line), correct, 11)){
			gottems += 1;
		}
		totals += 1;
	}

	myfile << gottems << "," << totals << ";";

	gottems =0;
	totals = 0;
















	infile3.close();
	infile3b.close();
	infile3c.close();
	infile3d.close();
	infile3e.close();
	infile3f.close();
	infile3g.close();
	// Lets try gShare

//	for(int i = 0;  i < 2048; i++){
//		greg.gTable.push_back(0);
//	}

	ifstream infile4(input);

//	greg.ghrSize = 3;
//	greg.ghr = 0;

	for(int i = 0; i < 2048; i++){
		greg.dubTable.push_back(00);
	}

	greg.total = 0;

//	string mom;

	while(infile4 >> std::hex >> line >> correct){
//		printf("Do I get here?\n");
//		mom = greg.hex2bi(line);
//		printf("mom: %s\n", mom);
//		printf("correct: %s\n", correct);

		if(greg.bimodal(greg.hex2bi(line), correct, 4)){
			gottems += 1;
		}
		totals += 1;

//		cout << line << endl;
//		cout << mom << endl;
//		cout << correct << endl;



//		bool ahhh = greg.gShare(mom, correct, 3);
//		printf("ahhh?\n");
//		if(ahhh){
//			gottems += 1;
//		}
//		totals += 1;
//		correct = "";
	}

	printf("\ngottems: %d\n", gottems);
	printf("totals: %d\n", totals);

	gottems = 0;
	totals = 0;



	//g share

	for(int i = 0; i < 2048; i++){
		greg.gTable.push_back(0);
	}

	ifstream infile5("../traces/short_trace1.txt");

	greg.ghr = 0;
//	int i = 0;

	while(infile5 >> std::hex >> line >> correct){
		if(greg.gShare(greg.hex2bi(line), correct, 4)){
			gottems += 1;
		}
		totals += 1;

/*		if(i < 10){
			cout << correct <<endl;
			printf("%d\n", greg.ghr);
		}
		i++;
*/	}

	printf("\ngottems: %d\n", gottems);
	printf("totals: %d\n", totals);

	gottems = 0;
	totals = 0;


	//tour time

	greg.ghr = 0;
	for(int i = 0; i < 2048; i++){
		greg.gTable[i] = 0;
		greg.dubTable[i] = 0;
		greg.tTable.push_back(10);
	}

	ifstream infile6("../traces/short_trace1.txt");


	while(infile6 >> std::hex >> line >> correct){
		if(greg.tour(greg.hex2bi(line), correct)){
			gottems += 1;
		}
		totals += 1;
	}

	printf("\ngottems: %d\n", gottems);
	printf("totals: %d\n", totals);

	return 0;








}
