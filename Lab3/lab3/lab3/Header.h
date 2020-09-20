#pragma once
#include <Windows.h>
#include <iostream>
#include<vector>
#include <set>
#include<iterator>

using namespace std;


class Lab3
{
private:
	int a;
	int b;
	vector<int> KanonRazloj(int n) // ФУНКЦИЯ КАНОНИЧЕСКОГО РАЗЛОЖЕНИЯ ЧИСЛА
	{
		vector<int> v;
		int p = n;
		int z = 2;
		cout << "Простые множители числа " << n << " : ";
		while (p > 1)
		{
			while (p % z == 0) // пока z - простое с p
			{
				v.push_back(z);
				cout << z << " ";
				p /= z; // делим p на z
			}
			z++;// идем к следующему числу
		}
		return v;

	}
	int AlgoritmEvklida(int a, int b)
	{
		if (a > b) {// переставляем в а большее число
			int tmp = a;
			a = b;
			b = tmp;
		}
		int q, r = b;
		while (true)
		{
			q = a / b;
			if (a - b * q != 0) {
				r = a - b * q;
				a = b;
				b = r;
			}
			else break;
		}
		return r;
	}

	void vivod(vector<int> v)
	{
		vector<int>::iterator i = v.begin();
		cout << "vec\n";
		while (i != v.end())
		{
			cout << *i << " ";
			i++;
		}
		cout << endl;
	}
	vector<int> v1;
	vector<int> v2;
	bool number_in_vec(vector<int> c, int a)// есть ли число в векторе

	{
		for (int i = 0; i < c.size(); i++)
		{
			if (a == c[i]) {
				v2.erase(v2.begin() + i);
				//vivod(c);
				//cout << a << " есть в обоих\n";
				return true; 
			}

		}
		return false;
	}
	int NOD_RAZLOJENIE(int a, int b)
	{
		v1 = KanonRazloj(a);
		cout << endl;
		v2 = KanonRazloj(b);
		cout << endl;
		vector<int> res;
		res.push_back(1);
		for (int i = 0; i < v1.size(); i++)
		{
			if (number_in_vec(v2, v1[i])) res.push_back(v1[i]);
		}
		int nod = 1;
		vector<int>::iterator i = res.begin();
		while (i != res.end())
		{
			nod *= *i;
			i++;
		}
		return nod;
		/*set<int> s;		// используем множества чтобы не было повторений
		s.insert(1);
		for (int i = 0; i < v1.size(); i++)
		{
			if (number_in_vec(v2, v1[i])) s.insert(v1[i]);
		}
		int nod = 1;
		set<int>::iterator i = s.begin();
		while (i != s.end())	// идем по всему сету
		{
			nod *= *i;
			++i;
		}
		return nod;*/

	}
	void Bezu(int a, int b, int *d, int *x, int *y)// разложение безу
	{
		int s;
		if (b == 0)
		{
			*d = a; *x = 1; *y = 0;
			return;
		}
		Bezu(b, a % b, d, x, y);
		s = *y;
		*y = *x - (a / b) * (*y);
		*x = s;
	}
public:
	Lab3(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	
	void Zadanie1()  // ПЕРВОЕ ЗАДАНИЕ
	{
		cout << endl<< "Разложение числа A: " << endl;
		int aT = a, bT = b;
		KanonRazloj(aT);
		cout << endl << "Разложение числа B: " << endl;
		KanonRazloj(bT);
	}
	void Zadanie2()
	{
		int aT = a, bT = b;
		cout << "Нод по алгоритму Евклида: " << AlgoritmEvklida(aT, bT) << endl;
		aT = a; bT = b;
		cout << "НОД с помощью разложения: " << NOD_RAZLOJENIE(aT, bT) << endl;
	}
	void Zadanie3()
	{
		int d, x, y;
		int aT = a, bT = b;
		Bezu(aT, bT, &d, &x, &y);
		cout << d << " = " << a << " * " << x << " + " << b << " * " << y << endl;
	}
	void Zadanie4(int s)
	{
		int m = b;
		int res = a%m;
		for (int i = 1; i < s; i++)
		{
			res = (res*a) % m;// остаток по умножению к предыдущему остатку

		}
		cout << a << "^" << s << " mod(" << m << ") = " << res << endl;
	}
};
