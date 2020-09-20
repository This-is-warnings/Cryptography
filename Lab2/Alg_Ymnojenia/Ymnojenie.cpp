#include <iostream>
#include <Windows.h>
#include <string>
#include <string.h>
using namespace std;


int perevod(int t, int B)
{
	int s = 0;
	int l = 1;
	do {
		s += (t % B)*l;
		t /= B;
		l *= 10;
	} while (t != 0);
	return s;

}

int main()
{
	setlocale(0, "rus");
	cout << "¬ведите систему счислени€\n";
	int B;
	cin >> B;
	cout << "¬ведите два числа\n";
	string a, b;
	
	cin >> a;
	cin >> b;

	int k = a.length();
	int l = b.length();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int c = 0;
	string w = "";
	for (int i = 0; i <= k + l - 1; i++)
		w += '0';
	
	for (int i = 0; i <= l - 1; i++)
	{
		c = 0;
		for (int j = 0; j <= k - 1;j++)
		{
			int t = (int)(w[i + j]-48) + (int)(a[j]-48) * (int)(b[i]-48) + c;
			t = perevod(t, B);
			w[i + j] = '0' + (t % 10);
			c = t / 10;
		}
		w[i + k] = '0' + c;
	}
	reverse(w.begin(), w.end());

	bool m = false;
	for (int i = 0; i < w.length(); i++)
	{
		if (!m)
		{
			if (w[i] != '0') {
				cout << w[i];
				m = true;
			}
		}
		else cout << w[i];
	}
	cout << endl;



	system("pause");
	return 0;
}