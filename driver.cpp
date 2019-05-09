#include "work.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){

	string line;
	string correct;
	string temporary = argv[1];
//	string input = "../../traces/";
	string input = argv[1];
	string output = argv[2];
//	input.append(temporary);
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


	ofstream myfile;
	myfile.open(output);
//	cout <<"taken: " << gottems << " + " << totals << endl;
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



//	cout << "nontaken: " << gottems << " + " << totals << endl;
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


//	cout << "single bit 4: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";


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

//	cout << "single bit 5: " << gottems << " + " << totals << endl;
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

//	cout << "single bit 7: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

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

//	cout << "single bit 8: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

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

//	cout << "single bit 9: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

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

//	cout <<"single bit 10: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

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

//	cout << "single bit 11: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << ";\n";

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

		if(greg.bimodal(greg.hex2bi(line), correct, 4)){
			gottems += 1;
		}
		totals += 1;
	}



//	cout << "bimodal 4: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

	gottems = 0;
	totals = 0;


	ifstream infile4b(input);

	for(int i = 0; i < 2048; i++){
		greg.dubTable[i]=0;
	}

	while(infile4b >> std::hex >> line >> correct){

		if(greg.bimodal(greg.hex2bi(line), correct, 5)){
			gottems+= 1;
		}
		totals += 1;
	}

//	cout << "bimodal 5: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

	gottems = 0;
	totals = 0;


	ifstream infile4c(input);

	for(int i = 0; i < 2048; i++){
		greg.dubTable[i] = 0;
	}

	while(infile4c >> std::hex >> line >> correct){

		if(greg.bimodal(greg.hex2bi(line), correct, 7)){
			gottems += 1;
		}
		totals += 1;
	}

//	cout << "bimodal 7: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

	gottems = 0;
	totals = 0;


	ifstream infile4d(input);

	for(int i = 0; i < 2048; i++){
		greg.dubTable[i] = 0;
	}

	while(infile4d >> std::hex >> line >> correct){
		if(greg.bimodal(greg.hex2bi(line), correct, 8)){
			gottems += 1;
		}
		totals += 1;
	}

	myfile << gottems << "," << totals << "; ";

	gottems = 0;
	totals = 0;


	ifstream infile4e(input);

	for(int i = 0; i < 2048; i++){
		greg.dubTable[i] = 0;
	}

	while(infile4e >> std::hex >> line >> correct){
		if(greg.bimodal(greg.hex2bi(line), correct, 9)){
			gottems += 1;
		}
		totals += 1;
	}

//	cout << "bimodal 9: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

	gottems = 0;
	totals = 0;


	ifstream infile4f(input);

	for(int i = 0; i < 2048; i++){
		greg.dubTable[i] = 0;
	}

	while(infile4f >> std::hex >> line >> correct){
		if(greg.bimodal(greg.hex2bi(line), correct, 10)){
			gottems += 1;
		}
		totals += 1;
	}

//	cout << "bimodal 10: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

	gottems = 0;
	totals = 0;


	ifstream infile4g(input);

	for(int i = 0; i < 2048; i++){
		greg.dubTable[i] = 0;
	}

	while(infile4g >> std::hex >> line >> correct){
		if(greg.bimodal(greg.hex2bi(line), correct, 11)){
			gottems += 1;
		}
		totals += 1;
	}

//	cout << "bimodal 11: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << ";\n";

	gottems = 0;
	totals = 0;

	infile4.close();
	infile4b.close();
	infile4c.close();
	infile4d.close();
	infile4e.close();
	infile4f.close();
	infile4g.close();












	//g share

	for(int i = 0; i < 2048; i++){
		greg.gTable.push_back(0);
	}

	ifstream infile5(input);

	greg.ghr = 0;
//	int i = 0;
	greg.ghrSize = 3;

	while(infile5 >> std::hex >> line >> correct){
		if(greg.gShare(greg.hex2bi(line), correct, 3)){
			gottems += 1;
		}
		totals += 1;

/*		if(i < 10){
			cout << correct <<endl;
			printf("%d\n", greg.ghr);
		}
		i++;
*/	}

//	cout << "gshare 3: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

	gottems = 0;
	totals = 0;




	for(int i = 0; i < 2048; i++){
		greg.gTable[i] = 0;
	}
	greg.ghrSize = 4;
	greg.ghr = 0;

	ifstream infile5b(input);

	while(infile5b >> std::hex >> line >> correct){
		if(greg.gShare(greg.hex2bi(line), correct, 4)){
		gottems += 1;
		}
		totals += 1;
	}

//	cout << "gshare 4: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

	gottems =0;
	totals = 0;



	for(int i = 0; i < 2048; i++){
		greg.gTable[i] = 0;
	}
	greg.ghrSize = 5;
	greg.ghr =0;

	ifstream infile5c(input);

	while(infile5c >> std::hex >> line >> correct){
		if(greg.gShare(greg.hex2bi(line), correct, 5)){
			gottems += 1;
		}
		totals += 1;
	}

//	cout << "gshare 5: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

	gottems = 0;
	totals = 0;


	for(int i = 0; i < 2048; i++){
		greg.gTable[i] = 0;
	}
	greg.ghrSize = 6;
	greg.ghr = 0;

	ifstream infile5d(input);

	while(infile5d >> std::hex >> line >> correct){
		if(greg.gShare(greg.hex2bi(line), correct, 6)){
			gottems += 1;
		}
		totals += 1;
	}

//	cout << "gshare 6: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

	gottems = 0;
	totals = 0;


	for(int i = 0; i < 2048; i++){
		greg.gTable[i] = 0;
	}
	greg.ghrSize = 7;
	greg.ghr = 0;

	ifstream infile5e(input);

	while(infile5e >> std::hex >> line >> correct){
		if(greg.gShare(greg.hex2bi(line), correct, 7)){
			gottems += 1;
		}
		totals += 1;
	}

//	cout << "gshare 7: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

	gottems = 0;
	totals = 0;


	for(int i = 0; i < 2048; i++){
		greg.gTable[i] = 0;
	}

	greg.ghrSize = 8;
	greg.ghr = 0;

	ifstream infile5f(input);

	while(infile5f >> std::hex >> line >> correct){
		if(greg.gShare(greg.hex2bi(line), correct, 8)){
			gottems += 1;
		}
		totals += 1;
	}

//	cout << "gshare 8: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

	gottems = 0;
	totals = 0;

	for(int i = 0; i < 2048; i++){
		greg.gTable[i] = 0;
	}

	greg.ghrSize = 9;
	greg.ghr = 0;

	ifstream infile5g(input);

	while(infile5g >> std::hex >> line >> correct){
		if(greg.gShare(greg.hex2bi(line), correct, 9)){
			gottems += 1;
		}
		totals += 1;
	}

//	cout << "gshare 9: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

	gottems =0;
	totals = 0;

	for(int i = 0; i < 2048; i++){
		greg.gTable[i] = 0;
	}

	greg.ghrSize = 10;
	greg.ghr =0;

	ifstream infile5h(input);

	while(infile5h >> std::hex >> line >> correct){
		if(greg.gShare(greg.hex2bi(line), correct, 10)){
			gottems += 1;
		}
		totals += 1;
	}
	
//	cout << "gshare 10: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << "; ";

	gottems =0;
	totals = 0;


	for(int i = 0; i < 2048; i++){
		greg.gTable[i] = 0;
	}

	greg.ghrSize = 11;
	greg.ghr =0;

	ifstream infile5i(input);

	while(infile5i >> std::hex >> line >> correct){
		if(greg.gShare(greg.hex2bi(line), correct, 11)){
			gottems+=1;
		}
		totals += 1;
	}

//	cout << "gshare 11: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << ";\n";

	gottems = 0;
	totals = 0;
//	cout << "before closing 5" << endl;

	



/*



	ifstream infile6(input);


	//tour time

	greg.ghr = 0;
	for(int i = 0; i < 2048; i++){
		greg.gTable[i] = 0;
		greg.dubTable[i] = 0;
		greg.tTable.push_back(10);
	}

//	cout << "Do we get here?" << endl;
	
	while(infile6 >> std::hex >> line >> correct){
		if(greg.tour(greg.hex2bi(line), correct)){
			gottems += 1;
		}
		totals += 1;
	}
*/
	//	printf("\ngottems: %d\n", gottems);
	//printf("totals: %d\n", totals);

//	cout << "tour: " << gottems << " + " << totals << endl;
	myfile << gottems << "," << totals << ";";
//	cout << "right before closing output" << endl;
	myfile.close();
	exit(0);
	
	
	infile5.close();
	cout << "a" << endl;
	infile5b.close();
	cout << "b" << endl;

	infile5c.close();
	cout << "c" << endl;

	infile5d.close();
	cout << "d" << endl;

	infile5e.close();
	cout << "e" << endl;

	infile5f.close();
	cout << "f" << endl;

	infile5g.close();
	cout << "g" << endl;

	infile5h.close();
	cout << "h" << endl;

	infile5i.close();
	cout << "i" << endl;

	cout << "after closing 5" << endl;
	return 0;








}
