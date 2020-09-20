#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char alp[33] = { 'à','á','â', 'ã','ä','å','¸','æ','ç','è', 'é','ê','ë', 'ì','í','î', 'ï','ð','ñ', 'ò','ó','ô', 'õ','ö','÷', 'ø','ù','ú', 'û','ü','ý', 'þ','ÿ' };
char alpUp[33] = { 'À','Á','Â', 'Ã','Ä','Å','¨','Æ','Ç','È', 'É','Ê','Ë', 'Ì','Í','Î', 'Ï','Ð','Ñ', 'Ò','Ó','Ô', 'Õ','Ö','×', 'Ø','Ù','Ú', 'Û','Ü','Ý', 'Þ','ß' };
int poiskInMas(char a)
{
	for (int i=0; i < 33; i++)
	{
		if (a == alp[i]) return i;
	}
	for (int i=0; i < 33; i++)
	{
		if (a == alpUp[i]) return i+33;
	}
	return -1;
}

void perevod(string s)
{
	int k = -1;
	for (int i = 0; i < s.length(); i++)
	{
		k = poiskInMas(s[i]);
		if (k >= 0)
		{
			if (k < 33) {
				if (k > 2)
				{
					s[i] = alp[k - 3];
				}
				else if (k == 0) s[i] = alp[33 - 3];
				else if (k == 1) s[i] = alp[33 - 2];
				else if (k == 2) s[i] = alp[33 - 1];
			}
			else
			{
				k -= 33;
				if (k > 2)
				{
					s[i] = alpUp[k - 3];
				}
				else if (k == 0) s[i] = alpUp[33 - 3];
				else if (k == 1) s[i] = alpUp[33 - 2];
				else if (k == 2) s[i] = alpUp[33 - 1];
			}
		}		
	}
	cout << s;	
}


int main()
{
	
	setlocale(0, "RUS");
	ifstream file("Zad1T.txt");
	
	string str;                                     
	while (getline(file, str))  
	{                        
		perevod(str);	
		cout << endl;
	}
	
	system("pause");
	return 0;
}