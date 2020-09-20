#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


char alp[33] = { 'à','á','â', 'ã','ä','å','¸','æ','ç','è', 'é','ê','ë', 'ì','í','î', 'ï','ð','ñ', 'ò','ó','ô', 'õ','ö','÷', 'ø','ù','ú', 'û','ü','ý', 'þ','ÿ' };
char alpUp[33] = { 'À','Á','Â', 'Ã','Ä','Å','¨','Æ','Ç','È', 'É','Ê','Ë', 'Ì','Í','Î', 'Ï','Ð','Ñ', 'Ò','Ó','Ô', 'Õ','Ö','×', 'Ø','Ù','Ú', 'Û','Ü','Ý', 'Þ','ß' };
char tabl[33][33];


int poiskInMas(char a)
{
	for (int i = 0; i < 33; i++)
	{
		if (a == alp[i]) return i;
	}
	for (int i = 0; i < 33; i++)
	{
		if (a == alpUp[i]) return i + 33;
	}
	return -1;
}


int poiskInMas2(char a,int stolb)
{
	for (int i = 0; i < 33; i++)
	{
		if (a == tabl[stolb][i]) return i;
	}
	
	return -1;
}

string perevod(string s)
{
	string s1;
	for (int i = 0; i < s.length(); i++)
	{
		if (poiskInMas(s[i]) != -1 )
		{
			s1 += s[i];
		}
	}
	return s1;
}

string shifr(string s,int n)
{
	int k = 0;
	string s1;
	for (int i = 0; i < n; i++)
	{
		s1 += s[k];
		k++;
		if (k == s.length()) k = 0;
	}
	return s1;
}

void Vijner(string str, string shifr, string temp)
{
	int i1 = 0, i2 = 0;
	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		i1 = poiskInMas(str[i]);
		while(poiskInMas(temp[count]) == -1)
		{
			cout << temp[count];
			count++;
		}
		i2 = poiskInMas(shifr[i]);
		i1 = poiskInMas2(str[i], i2);
		cout << tabl[i1][0];
		count++;
	}
	cout << endl;
}

int main()
{

	setlocale(0, "RUS");

	
	for (int i = 0; i < 33; i++)
	{
		tabl[i][0] = alp[i];
		tabl[0][i] = alp[i];
	}
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if ((j + 2) != 33) {
				tabl[i + 1][j + 1] = tabl[i][j + 2];
			}
			else tabl[i + 1][j + 1] = tabl[i][0];
		}
	}
	for (int i = 0; i < 33; i++)
	{
		for (int j = 0; j < 33; j++)
		{
			cout << tabl[i][j] << " ";
		}
		cout << endl;
	}


	ifstream file("Zad2.txt");

	string str;
	while (getline(file, str))
	{	
		string temp = str;
		str = perevod(str);
		cout << str << endl;
		string s = shifr("øèôð", str.length());
		cout << s << endl;
		Vijner(str, s,temp);
	}

	system("pause");
	return 0;
}