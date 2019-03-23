#ifndef WORK_H
#define WORK_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class work{
private:

public:
//	int hits;

	int ghrSize;
	int tableSize;
	int ghr;
	std::vector<int> gTable;
	std::vector<int> singTable;
	std::vector<int> dubTable;
	std::vector<int> tTable;

	int correct;
	int total;

	void addone();
	void hit();

	bool taken(string line, string correct);
	bool nontaken(string line, string correct);
	bool singBit(string line, string correct, double tS);
	bool bimodal(string line, string correct, int tS);
	bool gShare(string line, string correct, int ghrL);
	bool tour(string line, string correct);
	string hex2bi(string line);

};

#endif
