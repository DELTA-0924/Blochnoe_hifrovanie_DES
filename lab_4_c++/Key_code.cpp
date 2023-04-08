#include "Key_code.h"

string Key_code:: stobin(string s,short x) {
	string rez = "";
	for (size_t i = 0; i < s.length(); i++)
	{
		unsigned char ch = s[i];
		string b = "";
		for (int k = 0; k < x; k++, ch >>= 1)
			b = char('0' + ch % 2) + b;
		rez += b;
	}
	return rez;
}
string Key_code::del_bit(string s) {
	string sl, rez;
	for (int i = 0; i < s.length(); i++)
	{
		if ((i + 1) % 8 != 0)
			sl += s[i];
	}
	short pr_arr[57] = { 57,49,41,33,25,17,9,1,58,50,42,34,26,18,
						10,2,59,51,43,35,27,19,11,3,60,52,44,36,
						63,55,47,39,31,23,15,7,62,54,46,38,30,22,
						14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
	short in;
	for (short i = 0; i < 56; i++) {
		in = pr_arr[i] - 1;
		rez += s[in];
	}
	return rez;
}
void  Key_code:: sdvig_bit(string& s, bool flag) {
	char temp = s[1], temp1;
	s[1] = s[0];
	s[0] = s[s.length() - 1];
	for (int i = 1; i < s.length() - 1; i++)
	{
		temp1 = s[i + 1];
		s[i + 1] = temp;
		temp = temp1;
	}
	if (flag)
		sdvig_bit(s);
}
void Key_code::P_box(string& s) {
	short pr_arr[48] = {
		14,17,11,24,1,5,3,28,
		15,6,21,10,23,19,12,4,
		26,8,16,7,27,20,13,2,
		41,52,31,37,47,55,30,40,
		51,45,33,48,44,49,39,56,
		34,53,46,42,50,36,29,32
	};
	string s1;
	for (short i = 0; i < 48; i++)
		s1 += s[pr_arr[i] - 1];
	s = s1;
}