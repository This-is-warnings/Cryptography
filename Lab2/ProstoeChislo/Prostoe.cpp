#include <iostream>
#include <Windows.h>

using namespace std;

int modexp(int x, int y, int N)
{
	if (y == 0) return 1;
	int z = modexp(x, y / 2, N);
	if (y % 2 == 0)
		return (z*z) % N;
	else
		return (x*z*z) % N;
}

int mod(int b, int m)
{
	int a = 0;
	while (true)
	{
		if ((a - b) % m == 0)
			return a;
		a++;
	}
}
int main()
{
	setlocale(0, "rus");
	cout << "Введите нечетное число n, большее либо равное 5: ";
	int n, T;
	cin >> n;
	cout << "Введите число итераций Т: ";
	cin >> T;
	int r = 0, s = 0;
	bool a = false;
	for (int s1 = 0;  ; s1++)
	{
		for (int r1 = 1; r1 < n; r1 += 2)
		{
			if (pow(2, s1)*r1 == n - 1)
			{
				r = r1; s = s1; goto m;
				break;
			}
		}
	}
m:
	cout << "n = (2^" << s << ")*" << r << " + 1" << endl;
	int lol = 0;
	int u,v;
	for (int t = 1; t <= T; t++)
	{
		u = 2 + rand() % (n - 2);
		//v = mod(pow(u, r), n);
		v = modexp(u, r, n);
		cout << "u: "<<  u <<
			", v: " <<v << endl;
		if (v == 1 || v == n - 1) goto k;
		for (int i = 1; i < s; i++)
		{
			// v = mod(pow(v, 2), n);
			v = modexp(v, 2, n);
			if (v == 1) {
				cout << "Число n составное" << endl;
				system("pause");
				return 0;
			}
			if (v == n - 1) goto k;
		}
		cout << "Число n составное " << endl;
		system("pause");
		return 0;
k:
		lol++;

	}
	cout << "Число n, вероятно, простое" << endl;
	system("pause");
	return 0;
}