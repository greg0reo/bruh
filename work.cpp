#include "work.h"
#include <math.h>


using namespace std;

void work::hit(){
	this->correct += 1;
}

void work::addone(){
	this->total += 1;
}

bool work::taken(string line, string correct){
	addone();
	if(correct == "T"){
		hit();
		return true;

	}else{
		return false;
	}
}

bool work::nontaken(string line, string correct){
	addone();
	if(correct == "NT"){
		hit();
		return true;

	}else{
		return false;
	}
}

bool work::singBit(string line, string correct, double tS){
	addone();
	string temp;
	int index = 0;
	//temp = line.substr(line.size()-tS, tS); //takes tS right most bits

	string car;
/*	for(int i = 1; i <= tS; i++){ //converts temp from binary to decimal
//		printf("%d\n", i);
		if(temp.substr(temp.size()-i, 1) == "1"){
			index += (2^(i-1));
		}
	}
*/

	for(int i = 0; i < tS; i++){
		car = line.at(31-i);
		if(car == "1"){
//			index += (2^i);
			index += pow(2, i);
		}
	}

	if(correct == "T"){
		if(singTable[index] == 1){
			hit();
			return true;
		}
		if(singTable[index] == 0){
			singTable[index] = 1;
			return false;
		}else{
			printf("its not working");
		}
	}
	if(correct == "NT"){
		if(singTable[index] == 0){
			hit();
			return true;
		}
		if(singTable[index] == 1){
			singTable[index] = 0;
			return false;
		}else{
			printf("its not working");
		}
	}
	return true;
}

bool work::bimodal(string line, string correct, int tS){
	addone();
	string temp;
	int index = 0;
/*	temp = line.substr(line.size()-tS, tS); //takes tS right most bits

	for(int i = 1; i <= tS; i++){ //converts temp from binary to decimal
		if(temp.substr(temp.size()-i, 1) == "1"){
			index += (2^(i-1));
		}
	}
*/
	string car;

	for(int i = 0; i < tS; i++){
		car = line.at(31-i);
		if(car == "1"){
//			index += (2^i);
			index += pow(2, i);
		}
	}


	if(correct == "T"){
		if(dubTable[index] == 11){
			hit();
			return true;
		}
		if(dubTable[index] == 10){
			hit();
			dubTable[index] = 11;
			return true;
		}
		if(dubTable[index] == 01){
			dubTable[index] = 10;
			return false;
		}
		if(dubTable[index] == 00){
			dubTable[index] = 01;
			return false;
		}else{
			printf("wrong values in dubTable\n");
		}
	}
	if(correct == "NT"){
		if(dubTable[index] == 11){
			dubTable[index] = 10;
			return false;
		}
		if(dubTable[index] == 10){
			dubTable[index] = 01;
			return false;
		}
		if(dubTable[index] == 01){
			hit();
			dubTable[index] = 00;
			return true;
		}
		if(dubTable[index] == 00){
			hit();
			return true;
		}else{
			printf("wrong valuse in dubTable\n");
		}
	}
	printf("bimodal() not working properly\n");
	return false;

}


bool work::gShare(string line, string correct, int ghrL){
//	addone();
//	printf("g-Unit!");
	addone();
	unsigned int index = 0;
	int hor;
	string car;

	for(int i = 0 ; i < 14 ; i++){
		car = line.at(31-i);

		if(car == "1"){
			index += pow(2, i);
		}
	}

	int mo = pow(2, 11);
	index = index % mo;

	hor = index^(this->ghr);

	bool answer;

	if(correct == "T"){
		if(gTable[hor] == 11){
			hit();
			answer =  true;
		}
		if(gTable[hor] == 10){
			hit();
			gTable[hor] = 11;
			answer = true;
		}
		if(gTable[hor] == 01){
			gTable[hor] = 10;
			answer = false;
		}
		if(gTable[hor] == 00){
			gTable[hor] = 01;
			answer = false;
		}

		ghr = ghr<<1;
		int modu = (pow(2, ghrL)-1);
		ghr = ghr & modu;
		ghr += 1;

		return answer;
	}
	if(correct == "NT"){
		if(gTable[hor] == 11){
			gTable[hor] = 10;
			answer =  false;
		}
		if(gTable[hor] == 10){
			gTable[hor] = 01;
			answer = false;
		}
		if(gTable[hor] == 01){
			hit();
			gTable[hor] = 00;
			answer = true;
		}
		if(gTable[hor] == 00){
			hit();
			answer = true;
		}

		ghr = ghr<<1;
		int modu = (pow(2, ghrL)-1);
		ghr = ghr & modu;

		return answer;

	}else{
		printf("something is wrong with gShare/n");
	}
}

bool work::tour(string line, string correct){
	addone();

	string temp;
	temp = line.substr(line.size()-11, line.size()); //takes ghrL right most bits

	int index;
/*	for(int i = 0; i < 11; i++){
		if(temp.substr(temp.size()-i, 1) == "1"){
			index += (2^(i-1));
		}
	}
*/
	string car;
	for(int i = 0; i < 11; i++){
		car = line.at(31-i);
		if(car == "1"){
			index += pow(2, i);
		}
	}


//	int tempest = stoi(temp);

	int hor;
	hor = index^ghr;

	int selector = tTable[index];
	if(correct == "T"){
		if(gTable[hor] > 9 && dubTable[index] < 9){
			if(tTable[index] == 01){
				tTable[index] = 00;
			}
			if(tTable[index] == 10){
				tTable[index] = 01;
			}
			if(tTable[index] == 11){
				tTable[index] = 10;
			}
		}
		if(gTable[hor] < 9 && dubTable[index] > 9){
			if(tTable[index] == 00){
				tTable[index] = 01;
			}
			if(tTable[index] == 01){
				tTable[index] = 10;
			}
			if(tTable[index] == 10){
				tTable[index] = 11;
			}
		}
	}

	if(correct == "NT"){
		if(gTable[hor] < 9 && dubTable[index] > 9){
			if(tTable[index] == 01){
				tTable[index] = 00;
			}
			if(tTable[index] == 10){
				tTable[index] = 01;
			}
			if(tTable[index] == 11){
				tTable[index] = 10;
			}
		}
		if(gTable[hor] >9 && dubTable[index] < 9){
			if(tTable[index] == 00){
				tTable[index] = 01;
			}
			if(tTable[index] == 01){
				tTable[index] = 10;
			}
			if(tTable[index] == 10){
				tTable[index] = 11;
			}
		}
	}

	if(selector > 9){
		return bimodal(line, correct, 11);
	}
	if(selector < 9){
		return gShare(line, correct, 11);
	}



}

string work::hex2bi(string line){
	string temp;
	string car;
	string answer;
//	printf("bruh if this is the problem i swear\n\n");
	for(int i=2; i< 10 ; i++){
//		printf("%d\n", i);
		car = line.at(i);
		if(car == "0") answer.append("0000");
		if(car == "1") answer.append("0001");
		if(car == "2") answer.append("0010");
		if(car == "3") answer.append("0011");
		if(car == "4") answer.append("0100");
		if(car == "5") answer.append("0101");
		if(car == "6") answer.append("0110");
		if(car == "7") answer.append("0111");
		if(car == "8") answer.append("1000");
		if(car == "9") answer.append("1001");
		if(car == "a") answer.append("1010");
		if(car == "b") answer.append("1011");
		if(car == "c") answer.append("1100");
		if(car == "d") answer.append("1101");
		if(car == "e") answer.append("1110");
		if(car == "f") answer.append("1111");
	}
//	printf("swag daddy purrple\n");

	return answer;
}

