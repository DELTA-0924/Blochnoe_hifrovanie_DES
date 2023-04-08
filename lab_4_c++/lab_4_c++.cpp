#include"Key_code.h"
#include"Text_code.h"
int main() {
	setlocale(LC_ALL, "RUSSIAN");
	Key_code key;
	Text_code text;
	string start_key,bin_key,line,bin_line;
	cout << "Введите слово ";
	cin >> line;
	bin_line = key.stobin(line,8);
	cout << "Введите ключ (8 символов)";
	cin >> start_key;
	if (start_key.length() != 8)
	{
		cout << "Длина ключа несоответствует требованиям";
		exit(0);
	}
	bin_key = key.stobin(start_key,8);
	cout << "Бинарной код ключа\n" << bin_key;
	bin_key= key.del_bit(bin_key);
	cout << "Сжатый бинарной код ключа\n" << bin_key;
	string Bloks[16];
	text.IP(bin_line);
	string Lt = bin_line.substr(0, bin_line.length() / 2),
		Rt = bin_line.substr(bin_line.length() / 2, bin_line.length()),temp_text,temp_key,temp_str;
		cout << "\nСдвинутый бинарной код левой части ключа\tСдвинутый бинарной код правой части ключа\tПодключ\t\tТекст";
	for (short i = 0; i < 15; i++) {
		string Vec_str[8];
		string Ls = bin_key.substr(0, bin_key.length() / 2),
			Rs = bin_key.substr(bin_key.length() / 2, bin_key.length());
		if (i == 0 || i == 1 || i == 8 || i == 15) {
			key.sdvig_bit(Ls,false);
			key.sdvig_bit(Rs,false);
			cout << "\n1 бит\t";
		}
		else
		{
			key.sdvig_bit(Ls,true);
			key.sdvig_bit(Rs,true);
			cout << "\n2 бита\t";
		}
		cout << Ls << "\t\t\t" << Rs << "\t";
		Bloks[i] = Ls + Rs;
		bin_key = Bloks[i];
		key.P_box(Bloks[i]);
		temp_key = Bloks[i];
		text.P_box_update(Rt);
		temp_text = Rt;
		short n=0, l=0;
		Rt.clear();
		cout << i + 1 << "\t" << Bloks[i] <<"\t"<<temp_text<<endl;
		for (short i = 0; i < 48; i++)
			Rt += temp_key[i] == temp_text[i] ? '0' : '1';
		cout << "\nОтвет " << Rt << endl;
		for (short i = 0; i < 8; i++)
		{
			n += 6;
			while (l < n) {
				Vec_str[i] += Rt[l];
				l++;
			}
			/*cout << Vec_str[i] << endl;*/
		}
		n = 0;
		l = 0;
		bin_line=text.S_box(Vec_str);
		//cout <<" \nДлина " << bin_line.length();
		text.P_box(bin_line);

		temp_str = Rt;
		Rt = Lt;
		Lt = temp_str;
		cout << "\n  Раунд " << i + 1 << endl;
	}
	string rez;
	rez = Lt + Rt;
	text.IP_1(rez);
	cout << "Результат\n" << rez;
	system("pause");
	return 0;
}