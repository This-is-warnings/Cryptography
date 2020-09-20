#include <iostream>	
#include<Windows.h>
#include <list>
#include <string>
// 12 000 000
using namespace std;
unsigned long long sss = 9000000;
// возведение в степень и сравнение по модулю
unsigned long long vozv_v_st(unsigned long long a, unsigned long long xt, unsigned long long m)
{
	//cout << "vozv\t a = " << a << " x = " << x << " m = " << m << endl;
	if (xt == sss)
	{
		cout << sss << endl;
		sss+= 100000;
	}
	//unsigned long long xt = x;
	list<int> dvoich;
	while (xt > 0)				// здесь переводим Х в двоичную систему счисления и записываем наоборот
	{
		dvoich.push_back(xt % 2);
//		cout << xt % 2;
		xt /= 2;
	}
//cout << endl;
	int n = dvoich.size();
	unsigned long long *masA = new unsigned long long[n];
	masA[0] = a%m;
//	cout << masA[0] << "    ";
	for (int i = 1; i < n; i++)
	{
		masA[i] =  (masA[i - 1] * masA[i-1]) %m;			// заполняем массив чисел А
//		cout << masA[i] << "    ";
	}
//	cout << endl;
	unsigned long long sum = 1;
	int i = 0;

	while (!dvoich.empty())
	{
		
		if (dvoich.front() == 1)		// Перемножаем те a[i]-ые между собой, у которых в двоичной записи степени
										//на соответствующих позициях стоят единицы:
		{
			sum =sum * masA[i];
		}
		dvoich.pop_front();
		i++;
	}
	//cout << " ret = " << sum % m << endl;
	delete[] masA;
	return sum%m;

}
//------------------------------------------
// находим Х
unsigned long long findX(unsigned long long p, unsigned long long y, unsigned long long g)
{
	cout << "FindX\n";
	for (unsigned long long i = 9000000; i < p; i++)
	{										// ищем степень, в которой g по модулю p будет равняться y
		if (vozv_v_st(g, i, p) == y)
			return i;
	}
	return 0;
}
//-----------------------------------
// Соотношение безу 
unsigned long long int Bezu(unsigned long long a, unsigned long long b) {
	unsigned long long p = 1, q = 0, r = 0, s = 1, k, x, y;
	while (a && b) // пока a и b одновременно ненулевые
	{
		if (a >= b)
		{
			a = a - b; // Это нахождение НОД по алгоритму Евклида
			p = p - r; 
			q = q - s; 
		}
		else
		{
			b = b - a; // Это тоже нахождение НОД
			r = r - p;
			s = s - q;
		}
	}

	if (a)
	{
		k = a;
		x = p;
		y = q;
	}
	else
	{
		k = b;
		x = r;
		y = s;
	}
	cout << x << " " << y << endl;
	return y;
}
unsigned long long in_length(unsigned long long m)
{
	unsigned long long n = 0;
	while (m != 0)
	{
		m /= 10;
		n++;
	}
	return n;
}
int* long_to_mas(unsigned long long m, unsigned long long length)
{
	int*mas = new int[length];
	for (unsigned long long i = length - 1; i >= 0; i--)
	{
		mas[i] = m % 10;
		m /= 10;
	}
	/*for (int i = 0; i <length; i++)
	{
		cout << mas[i];
	}*/
	return mas;
}
void finalDecoder(unsigned long long message) { // и по нему уже восстанавливаем необходимое нам слово
	string result = "";
	char mass[33] = { 'а','б', 'в', 'г',
	'д', 'е', 'ё', 'ж',
	'з', 'и', 'й', 'к',
	'л', 'м', 'н', 'о',
	'п', 'р', 'с', 'т',
	'у', 'ф', 'х', 'ц',
	'ч', 'ш', 'щ', 'ъ',
	'ы', 'ь', 'э', 'ю',
	'я' };

	bool chet;
	unsigned long long length = in_length(message);
	if ((length% 2) == 0) chet = true;
	else chet = false;
	int*mas = long_to_mas(message, length);
	unsigned long long temp;
	int i = 0;
	int m;
	while (i<= length - 2)
	{
		if (!chet)
		{
			result += mass[mas[i]-1];
			i++;
			chet = true;
		}
		else
		{
			m = mas[i] * 10 + mas[i + 1];
			result += mass[m-1];
			i += 2;
		}
	}
	for (int i = 0; i < result.length(); i++)
	{
		cout << result[i];
	}
	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "RUS");
	unsigned long long p = 218012117, g = 2, y = 44618890, w = 125176846, O = 93916858;
//	long long int  p = 218012117, g = 2, y = 44618890, w = 125176846, O = 93916858;
	unsigned long long pt = p, yt = y, gt = g, wt = w, Ot = O;
	unsigned long long x = findX(pt, yt, gt);
	cout << "x = " << x << endl;
	pt = p; yt = y; gt = g;
	unsigned long long xt = x;

	unsigned long long K = vozv_v_st(Ot, xt, pt);
	Ot = O; xt = x; pt = p;
	cout << "k = " << K << endl;
	unsigned long long KvMinus = Bezu(pt, K);
	cout << "K^(-1) = " << KvMinus << endl;
	cout << (w * KvMinus) % p << endl;
	finalDecoder((w * KvMinus) % p);
	cout << endl;
	system("pause");
	return 0;
}