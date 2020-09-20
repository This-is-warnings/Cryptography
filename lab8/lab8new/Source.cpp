#include <iostream>	
#include<Windows.h>
#include <list>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
// 12 000 000
using namespace std;
unsigned long long sss = 73000000;

// возведение в степень и сравнение по модулю
void reverseM(int*mas, int size)
{
	    int temp = 0;
		int start = 0;
		int end = size - 1;
		while (start < end)
		{
			temp = mas[start];
			mas[start] = mas[end];
			mas[end] = temp;
			start++; end--;
		}
	
	
}
unsigned long long vozv_v_st(unsigned long long a, unsigned long long xt, unsigned long long m)
{
	int dvoich[100];
	unsigned int mt = m;
	int k = 0;
	while (mt > 0)
	{
		k++;
		mt /= 2;
	}
	 long long *masA = new long long[k];
	masA[0] =a % m;

	for (int i = 1; i < k; i++)
	{
		masA[i] = (masA[i - 1] * masA[i - 1]) % m;

	}
	//masA.push_back(g % p);
	int n;
	unsigned long long sum;
	int i;
	int size = 0;

		i = 0;
		size = 0;
		while (xt > 0)				// здесь переводим Х в двоичную систему счисления и записываем наоборот
		{
			dvoich[i] = xt % 2;
			i++;
			size++;
			xt /= 2;
		}
	
	//	reverseM(dvoich, size);
		sum = 1;
		i = 0;
		while (i != size)
		{

			if (dvoich[i] == 1)		// Перемножаем те a[i]-ые между собой, у которых в двоичной записи степени
											//на соответствующих позициях стоят единицы:
			{
				sum = sum * masA[i];
			}
			i++;
		}

		return sum % m;
	
	

}
//------------------------------------------
// находим Х
unsigned int findX(unsigned int p, unsigned int y, unsigned int g)
{
	cout << "FindX\n";
	int dvoich[30];
	unsigned int pt = p;
	int k = 0;
	while (pt > 0)				
	{
		k++;
		pt /= 2;
	}
	unsigned long long *masA = new unsigned long long[k];
	masA[0] = g % p;
	cout << masA[0] << "  ";
	for (int i = 1; i < k; i++)
	{
		masA[i] = (masA[i - 1] * masA[i - 1]) % p;	
		cout << masA[i] << "  ";
	//	masA[i] *= masA[i - 1] % p;// заполняем массив чисел А
	
	}
	cout << endl;
	//masA.push_back(g % p);
	int n;
	unsigned long long sum;
	int i;
	int size = 0;
	unsigned int xt;

	for (unsigned int x = 72000000; x < p; x++)
	{				
		xt = x;
		if (xt == sss)
		{
			
			//cout << sss << " " << s2-s1 << endl;
			cout << xt << endl;
			sss += 10000000;
		}
		i = 0;
		size = 0;
		
		while (xt > 0)				// здесь переводим Х в двоичную систему счисления и записываем наоборот
		{
			dvoich[i] =xt % 2; 
			if (x == 72102673) cout << xt % 2;
			size++;
			i++;
			xt /= 2;
		}
	
		sum = 1;
		i = 0;
		while (i != size)
		{

			if (dvoich[i] == 1)		// Перемножаем те a[i]-ые между собой, у которых в двоичной записи степени
											//на соответствующих позициях стоят единицы:
			{
				sum = sum * masA[i];
			}
			i++;
		}
		//dvoich.clear();
	
		//dvoich.clear();
		//cout << sum % p << endl;
		if ((sum % p) == y) { cout << endl << sum << endl; return x; }
	}
	return 0;
}
//-----------------------------------
// Соотношение безу 
unsigned long long int Bezu(unsigned long long a, unsigned long long b) {
	long long p = 1, q = 0, r = 0, s = 1, k, x, y;
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
	for (long long i = length - 1; i >= 0; i--)
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
	if ((length % 2) == 0) chet = true;
	else chet = false;
	int*mas = long_to_mas(message, length);
	int i = 0;
	int m;
	while (i <= length - 2)
	{
		if (!chet)
		{
			result += mass[mas[i] - 1];
			i++;
			chet = true;
		}
		else
		{
			m = mas[i] * 10 + mas[i + 1];
			result += mass[m - 1];
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

	//unsigned int p = 206181067, g = 7, y = 57348448, w = 160936053, O = 1449464;

	unsigned int p = 218012117, g = 2, y = 44618890, w = 125176846, O = 93916858;
	unsigned int pt = p, yt = y, gt = g, wt = w, Ot = O;
	//unsigned int x = findX(pt, yt, gt); // 72102673
	unsigned int x = 69999076;
	if (x == 0)
	{
		cout << "x не нашлось :(" << endl;
		system("pause"); return 0;
	}
	cout << "x = " << x << endl;
	pt = p; yt = y; gt = g;
	unsigned int xt = x;

	unsigned int K = vozv_v_st(Ot, xt, pt);
	Ot = O; xt = x; pt = p;
	cout << "k = " << K << endl;
	unsigned int KvMinus = Bezu(pt, K);
	cout << "K^(-1) = " << KvMinus << endl;
	cout << (w * KvMinus) % p << endl;
	system("pause");
	finalDecoder((w * KvMinus) % p);
	cout << endl;
	system("pause");
	return 0;
}