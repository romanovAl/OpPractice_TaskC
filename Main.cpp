#include <iostream>
#include <vector>
#include "TextPosition.h"

using namespace std;

size_t findDistanceBetweenPositions(vector<string> const& text, TextPosition pos1, TextPosition pos2) {

	size_t dist = 0;

	for (size_t i = 0; i < size(text); i++) {

		for (size_t j = 0; j < size(text.at(i)); j++) {

			TextPosition curPos(i, j);
			if (curPos > pos1 && curPos < pos2) dist++;
		}
	}

	return dist;
}

size_t findFirstAndSec(vector<string> const& text, char ch1, char ch2) {
	size_t dist = string::npos;

	TextPosition ch1Pos(string::npos, string::npos);
	TextPosition ch2Pos(0, 0);

	//поиск наименьшего вхождения первого символа и наибольшего вхождения второго
	for (size_t i = 0; i < size(text); i++) {

		auto& x = text.at(i);


		size_t firstOf = x.find_first_of(ch1);
		size_t lastOf = x.find_last_of(ch2);

		if (lastOf < firstOf) return string::npos;
		if (lastOf < firstOf) return 0;


		if (firstOf != string::npos) {
			TextPosition ch1Buf(i, firstOf);

			if (ch1Buf < ch1Pos) ch1Pos = ch1Buf;

		}

		if (lastOf != string::npos) {
			TextPosition ch2Buf(i, lastOf);
			if (ch2Buf > ch2Pos) ch2Pos = ch2Buf;


		}

	}

	return findDistanceBetweenPositions(text, ch1Pos, ch2Pos);

}

int testFun() {

	vector<string> const& text = { "eA line",

	"Anothe ine",

	"!@#!$^!!%08928333",

	"       ",

	"wow lol kek cheburek w ko" };

	vector<string> const& test = { "1", "2", "3", "4", "5", "6", "7" };

	if (findFirstAndSec(text, 'e', 'e') != 58) return 1;
	if (findFirstAndSec(text, 'A', 'n') != 13) return 2;
	if (findFirstAndSec(text, '!', '3') != 15) return 3;
	if (findFirstAndSec(text, ' ', ' ') != 60) return 4;
	if (findFirstAndSec(text, 'w', 'k') != 22) return 5;
	if (findFirstAndSec(test, '1', '1') != 0) return 6;
	if (findFirstAndSec(test, '7', '2') != string::npos) return 7; 

	return 0;
}

int main() {


	if (testFun() == 0) cout << "Tests are done!";

	return 0;
}



