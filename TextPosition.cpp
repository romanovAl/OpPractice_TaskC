#include "TextPosition.h";

using namespace std;

bool operator< (const TextPosition& first, const TextPosition& sec) {
	if (first.line < sec.line) return true;
	else if (first.line > sec.line) return false;
	else if (first.line == sec.line) return first.col < sec.col;
}

bool operator> (const TextPosition& first, const TextPosition& sec) {
	if (first.line > sec.line) return true;
	else if (first.line < sec.line) return false;
	else if (first.line == sec.line) return first.col > sec.col;
}

bool operator<= (const TextPosition& first, const TextPosition& sec) {
	if (first.line < sec.line) return true;
	else if (first.line > sec.line) return false;
	else if (first.line == sec.line) return first.col <= sec.col;
}

bool operator>= (const TextPosition& first, const TextPosition& sec) {
	if (first.line > sec.line) return true;
	else if (first.line < sec.line) return false;
	else if (first.line == sec.line) return first.col >= sec.col;
}