#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char alp[33] = { 'а','б','в', 'г','д','е','ё','ж','з','и', 'й','к','л', 'м','н','о', 'п','р','с', 'т','у','ф', 'х','ц','ч', 'ш','щ','ъ', 'ы','ь','э', 'ю','я' };
int m, n;
char **mas;
int kolvo_bykv;
int poiskInMas(char a)
{
	for (int i = 0; i < 33; i++)
	{
		if (a == alp[i]) return i;
	}
	
	return -1;
}

string DelProbel(string s)
{
	string s1;
	for (int i = 0; i < s.length(); i++)
	{
		if (poiskInMas(s[i]) != -1)
		{
			s1 += s[i];
		}
	}
	return s1;
}

void zapol(string s)
{	
	mas = new char*[m];
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		mas[i] = new char[n];
		for (int j = 0; j < n; j++)
		{
			if (count < s.length()) {
				mas[i][j] = s[count];
				count++;
			}
			else mas[i][j] = ' ';
		}
	}
}

void vivod()
{
	for (int i = 0; i < m; i++)
	{
		
		for (int j = 0; j < n; j++)
		{
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
}

void code()
{
	for (int j = 0; j < n; j++)
	{

		for (int i = 0;i < m; i++)
		{
			if (mas[i][j] != ' ')
			cout << mas[i][j];
		}
		cout << " ";
		
	}
}

int count_probel(string str)
{
	kolvo_bykv = 0;
	int temp = 0;
	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ') {
			count++;
			temp = -1;
		}
		else if (temp != -1)  kolvo_bykv++;
	}
	return count;
}

void Decode(string str, int n)
{
	//for (int j = 1; j < ; j++) {
	    int count = 0;
		for (int j = 0; j < n + 1; j++) {
			count = 0;
			for (int i = j; i + count < str.length(); i += kolvo_bykv)
			{
				cout << str[i + count];
				count++;
			}
		}
		cout << endl;
	//}
}

int main()
{

	setlocale(0, "RUS");
	

	string str;
	
	int choise;
	cout << "1 - Зашифровать\n2 - Расшифровать" << endl;
	cin >> choise;
	if (choise == 1)
	{
		ifstream file("Zad3.txt");
		while (getline(file, str))
		{

			cout << "Введите размер прямоугольника\nстрок: ";
			int n1, m1;
			cin >> m1;
			cout << "столбцов: ";
			cin >> n1;
			n = n1; m = m1;
			str = DelProbel(str);
			zapol(str);
			vivod();
			cout << "Закодированный текст: \n";
			code();
		}
	}
	if (choise == 2) {
		ifstream file("Zad4.txt");
		while (getline(file, str))
		{
			cout << "Раскодированный текст: " << endl;

			Decode(str, count_probel(str));

			
			
		}
	}
	

	system("pause");
	return 0;
}