#include "Text_code.h"
void Text_code::P_box(string &s) {
	short pr_arr[32] = { 16,7,20,21,29,12,28,17,
						1,15,23,26,5,18,31,10
						,2,8,24,14,32,27,3,9,
						19,13,30,6,22,11,4,25 };
	string s1;
	for (short i = 0; i < 32; i++)
		s1 += s[pr_arr[i] - 1];
	s = s1;
}
void Text_code::P_box_update(string& s) {
	short pr_arr[48] = { 32,1,2,3,4,5,
						4,5,6,7,8,9,
						8,9,10,11,12,13,
						12,13,14,15,16,17,
						16,17,18,19,20,21,
						20,21,22,23,24,25,
						24,25,26,27,28,29,
						28,29,30,31,32,1
	};
	string s1;
	for (short i = 0; i < 48; i++)
		s1 += s[pr_arr[i] - 1];
	s = s1;
}
string Text_code::S_box(string s[8]) {
	Blocks S;
	Key_code key;
	short rez[8];
	string rez_str[8], bin_line;
	//for (int i = 0; i < 8; i++)
	//	cout << s[i] << endl;
	rez[0] = Action(s[0], S.S1);
	rez[1] = Action(s[1], S.S2);
	rez[2] = Action(s[2], S.S3);
	rez[3] = Action(s[3], S.S4);
	rez[4] = Action(s[4], S.S5);
	rez[5] = Action(s[5], S.S6);
	rez[6] = Action(s[6], S.S7);
	rez[7] = Action(s[7], S.S8);
	for (short i = 0; i < 8; i++) {
		rez_str[i] = to_string(rez[i]);
		//cout << "\n Число " << rez_str[i] << endl;
		if (rez_str[i].length() > 1) {
			int dec, bin = 0, j;
			dec = rez[i];
			for (j = 0; dec > 0; j++)
			{
				bin += (dec % 2) * pow(10.0, j);
				dec /= 2;
			}
			/*cout << bin << endl;*/
			bin_line += to_string(bin);
		}
		else {
		/*cout << key.stobin(rez_str[i], 4) << endl;*/
		bin_line += key.stobin(rez_str[i], 4);
	}
		/*cout<<bin_line<<endl;*/
		}
	return bin_line;
}
void Text_code::IP(string& s) {
	Blocks S;
	string s1;
	for (short i = 0; i < 64; i++) {
		s1 += s[S.pr_arr[i] - 1];
	}
	s = s1;
}
void Text_code::IP_1(string& s) {
	Blocks S;
	string s1;
	short pr_arr[64];
	for (short i = 0; i < 64; i++) {
		pr_arr[S.pr_arr[i]-1] =i+1;
	}
	for (short i = 0; i < 64; i++) {
		s1 += s[pr_arr[i] - 1];
	}
	s = s1;
}
int Text_code::btod(string ch) {
	int sum=0;
	for (short i = ch.length() - 1; i > -1; i--)//    пошли по строке бит
		if (ch[i] == '1')   // если i-й бит в строке = 1 ,
			sum += pow(2, i);// то прибавить к общей сумме 2 в степени i
	return sum;
}
short Text_code::Action(string s, short S[4][16]) {
	short x, y, rez;
	string line = s, temp_line, temp_line1 = s.substr(1, s.length() - 2);
	temp_line = line[0] + line[line.length() - 1];
	x = btod(temp_line);
	y = btod(temp_line1);
	rez = S[x][y];
	return rez;
}
void BinDec(char* bin, int size)
{
	int rez(0), i;
	std::cout << "\nДесятичное число:\n< ";
	for (i = size - 1; i >= 0; --i)
		rez += (bin[i] - 48) << i;
	std::cout << rez << std::endl;
}
char* DecBin(int chislo, int size)
{
	int i;
	char* bin = new char[size];
	std::cout << "Двоичный код:\n< ";
	for (i = size - 1; i >= 0; --i)
	{
		if (!((i + 1) % 8))
			std::cout << ' ';
		std::cout << (bin[i] = ((chislo >> i) & 1) + 48);
	}
	return bin;
}