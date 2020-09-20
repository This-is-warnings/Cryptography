#include <Windows.h>
#include <iostream>
#include<list>
#include <string>
using namespace std;

// возведение в степень и сравнение по модулю
long long vozv_v_st(long long a, long long x, long long m)
{
	//cout << "vozv\t a = " << a << " x = " << x << " m = " << m;
	cout << x << endl;
	long long xt = x;
	list<int> dvoich;
	while (xt > 0)				// здесь переводим Х в двоичную систему счисления и записываем наоборот
	{
		dvoich.push_back(xt % 2);
			cout << xt % 2;
		xt /= 2;
	}
	cout << endl;
	long long n = dvoich.size();
	long long * masA = new long long[n];
	masA[0] = a % m;
	for (long long i = 1; i < n; i++)
	{
		masA[i] = (masA[i - 1]*masA[i-1]) % m;			// заполняем массив чисел А
		cout << masA[i] << "    ";
	}
	long long sum = 1;
	long long i = 0;

	while (!dvoich.empty())
	{

		if (dvoich.front() == 1)		// Перемножаем те a[i]-ые между собой, у которых в двоичной записи степени
										//на соответствующих позициях стоят единицы:
		{
			sum *= masA[i];
		}
		dvoich.pop_front();
		i++;
	}
	cout << " ret = " << sum % m << endl;
	return sum % m;

}
// Соотношение безу 
long long int Bezu(long long int  a, long long int  b) {
	long long int  p = 1, q = 0, r = 0, s = 1, k, x, y;
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
// сравнение по модулю
static long modexp(long x, long y, long N) {
	if (y == 0) {
		return 1;
	}
	long z = modexp(x, y / 2, N);
	if (y % 2 == 0) {
		return ((z*z) % N);
	}
	else {
		return ((x*z*z) % N);
	}
}
void finalDecoder(long long int message) { // и по нему уже восстанавливаем необходимое нам слово
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

	
}

int main()
{
	setlocale(LC_ALL, "RUS");
	long n = 4116037, e=451737, w = 833207;
	long nt = n;
	int div = 2;
	list<long> deliteli;
	while (n > 1)
	{
		while (n % div == 0)
		{
			deliteli.push_back(div);
			n = n / div;
		}
		if (div == 2) div++;
		else div += 2;
	}
	n = nt;
	long fi = 1;
	while (!deliteli.empty())
	{
		fi *= (deliteli.front()-1);
		deliteli.pop_front();
	}
	int d;
	cout << fi << endl;
	for (long i = 1; i < fi; i++) {
		if (modexp((e*i), 1,fi) == 1) {
			d = i;
			break;
		}
	}
	cout << d << endl;
	long c= vozv_v_st(w, d, n);
	cout << c << endl;
	finalDecoder(c);

	system("pause");
	return 0;
}