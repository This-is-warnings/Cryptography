#include <iostream>
#include <Windows.h>
#include <string>
#include <string.h>
using namespace std;

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
			t = a_i + b_i + c;
			w.insert(0, to_string(t%B));
			if (t < B) c = 0;
			else c = 1;
			//	c = t % B;
			//	cout << "t = " << t << " a_i= " << a_i << " b_i = " << b_i << " c=" << c<<endl;
			//	w += to_string(c);
		}
		if (c != 0)w.insert(0, to_string(c));
		cout << w << endl;

	
	
	system("pause");
	return 0;
}