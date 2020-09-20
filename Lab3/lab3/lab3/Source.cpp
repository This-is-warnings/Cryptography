#include <Windows.h>
#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	while (true) {
	

		cout << "Выберите задание: ";
		int choise;
		cin >> choise;
		//Lab3 c(a, b);
		if (choise == 1)
		{
			cout << "Введите А: ";
			int a, b;
			cin >> a;
			cout << "Введите B: ";
			cin >> b;
			Lab3 c(a, b);
			c.Zadanie1();
		}
		else if (choise == 2)
		{
			cout << "Введите А: ";
			int a, b;
			cin >> a;
			cout << "Введите B: ";
			cin >> b;
			Lab3 c(a, b);
			c.Zadanie2();
		}
		else if (choise == 3)
		{
			cout << "Введите А: ";
			int a, b;
			cin >> a;
			cout << "Введите B: ";
			cin >> b;
			Lab3 c(a, b);
			c.Zadanie3();
		}
		else if (choise == 4)
		{
			cout << "Введите основание: ";
			int a, b, s;
			cin >> a;
			cout << "Введите модуль: ";
			cin >> b;
			cout << "Введите степень: ";
			cin >> s;
			Lab3 c(a, b);
			c.Zadanie4(s);
		}
		cout << endl;
	}

	system("pause");
	return 0;
}