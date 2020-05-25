#pragma once

#include <string>

using namespace std;

class TextPosition {
public:
	size_t const NPOS = string::npos;
	size_t line = NPOS;
	size_t col = NPOS;

	TextPosition() {};

	TextPosition(size_t line, size_t col) {
		this->line = line;
		this->col = col;
	}

	friend bool operator< (const TextPosition& first, const TextPosition& sec);

	friend bool operator> (const TextPosition& first, const TextPosition& sec);

	friend bool operator<= (const TextPosition& first, const TextPosition& sec);

	friend bool operator>= (const TextPosition& first, const TextPosition& sec);

	TextPosition& operator= (const TextPosition& sec) {
		line = sec.line;
		col = sec.col;

		return *this;
	}
};