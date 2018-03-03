#pragma once
#include <vector>

typedef unsigned char uchar;
typedef unsigned long WORD;

using namespace std;

class CharCodeBuilder {
	vector<uchar> charcodes;

public:
	vector<uchar> build();

	CharCodeBuilder ldNeg();
	CharCodeBuilder ld0();
	CharCodeBuilder ldi8(WORD);
	CharCodeBuilder ldi16(WORD);
	CharCodeBuilder ldi32(WORD);
	CharCodeBuilder add();
	CharCodeBuilder sub();
	CharCodeBuilder mul();
	CharCodeBuilder div();

};