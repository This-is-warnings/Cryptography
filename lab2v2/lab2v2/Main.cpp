#include <iostream>
#include <Windows.h>
#include <string>
#include "BigNumberOperation.h"
using namespace std;

int main()
{
	setlocale(0, "rus");
	cout << "������� ������� ���������\n";
	int B;
	cin >> B;
	cout << "������� ��� �����\n";
	string a, b;
	cin >> a;
	cin >> b;
	BigNumberOperation Op(a, b, B);
	Op.Ymnojenie();
	
	cout << Op.Ymnojenie() << endl;

	system("pause");
	return 0;
}