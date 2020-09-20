#include <iostream>
#include <Windows.h>
#include <string>
#include <string.h>
using namespace std;
int mod(int a, int b)
{
	if(a!=0)
	return b - abs(a);
	else return 0;

}

int main()
{
	setlocale(0, "rus");
	//cout << 1 % 8 << endl;
	cout << "¬ведите систему счислени€\n";
	int B;
	cin >> B;
	cout << "¬ведите два числа\n";
	string a, b;
	cin >> a;
	cin >> b;
	
	int n;
	if (a.length() > b.length()) {
		n = a.length();
		string temp = "";
		for (int i = 0; i < a.length() - b.length(); i++)
		{
			temp += "0";
		}
		temp += b;
		b = temp;
		//cout << b << endl;
		}
	else {
		n = b.length();
		string temp = "";
		for (int i = 0; i < b.length() - a.length(); i++)
			{
				temp += "0";
			}
			temp += a;
			a = temp;
			//cout << a << endl;
		}
		int c = 0;
		int t;
		string w = "";

		for (int i = n - 1; i >= 0; i--)
		{
			int a_i = a[i] - 48;
			int b_i = b[i] - 48;
			t = a_i - b_i - c;
			if (t >= 0)
			{
				w.insert(0, to_string(t));
				c = 0;
			}
			else
			{
				w.insert(0, to_string(mod(t, B)));
				c = 1;
			}
			
		}
		bool k = false;
		for (int i = 0; i < w.length(); i++)
		{
			if (!k)
			{
				if (w[i] != '0') {
					cout << w[i];
					k = true;
				}
			}
			else cout << w[i];
		}
		cout << endl;

	
	system("pause");
	return 0;
}