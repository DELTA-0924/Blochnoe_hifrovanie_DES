#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Key_code
{
public:
	string stobin(string s, short x);
	string del_bit(string s);
	void sdvig_bit(string& s, bool flag = false);
	void P_box(string& s);
};

