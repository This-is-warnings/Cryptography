#include <Windows.h>
#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	while (true) {
	

		cout << "�������� �������: ";
		int choise;
		cin >> choise;
		//Lab3 c(a, b);
		if (choise == 1)
		{
			cout << "������� �: ";
			int a, b;
			cin >> a;
			cout << "������� B: ";
			cin >> b;
			Lab3 c(a, b);
			c.Zadanie1();
		}
		else if (choise == 2)
		{
			cout << "������� �: ";
			int a, b;
			cin >> a;
			cout << "������� B: ";
			cin >> b;
			Lab3 c(a, b);
			c.Zadanie2();
		}
		else if (choise == 3)
		{
			cout << "������� �: ";
			int a, b;
			cin >> a;
			cout << "������� B: ";
			cin >> b;
			Lab3 c(a, b);
			c.Zadanie3();
		}
		else if (choise == 4)
		{
			cout << "������� ���������: ";
			int a, b, s;
			cin >> a;
			cout << "������� ������: ";
			cin >> b;
			cout << "������� �������: ";
			cin >> s;
			Lab3 c(a, b);
			c.Zadanie4(s);
		}
		cout << endl;
	}

	system("pause");
	return 0;
}