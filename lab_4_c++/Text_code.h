#pragma once
#include"Key_code.h"
#include"Blocks.h"
class Text_code
{
public:
	void IP(string& s);
	void IP_1(string& s);
	void P_box_update(string &s);
	void P_box(string &s);
	string S_box(string s[8]);
	int btod(string ch);
	short Action(string s,short S[4][16]);
	void BinDec(char* bin, int size);
};

