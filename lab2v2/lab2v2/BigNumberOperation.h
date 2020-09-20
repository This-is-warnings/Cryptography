#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

class BigNumberOperation
{
private:
	string a;
	string b;
	int osn;
public:
	BigNumberOperation(string A, string B, int Osn)
	{
		a = A; b = B; osn = Osn;
	}
	int mod(int a, int b)
	{
		if (a != 0)
			return b - abs(a);
		else return 0;

	}
	string Slojenie()
	{
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

		}
		int c = 0;
		int t;
		string w = "";
		for (int i = n - 1; i >= 0; i--)
		{
			int a_i = a[i] - 48;
			int b_i = b[i] - 48;
			t = a_i + b_i + c;
			w.insert(0, to_string(t%osn));
			if (t < osn) c = 0;
			else c = 1;
			
		}
		if (c != 0)w.insert(0, to_string(c));
		return w;
	}

	string Slojenie(string a, string b)
	{
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

		}
		int c = 0;
		int t;
		string w = "";
		for (int i = n - 1; i >= 0; i--)
		{
			int a_i = a[i] - 48;
			int b_i = b[i] - 48;
			t = a_i + b_i + c;
			w.insert(0, to_string(t%osn));
			if (t < osn) c = 0;
			else c = 1;

		}
		if (c != 0)w.insert(0, to_string(c));
		return w;
	}


	string Vichitanie()
	{
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
				w.insert(0, to_string(mod(t, osn)));
				c = 1;
			}

		}
		while (w[0] == '0')
		{
			w.erase(0, 1);
		}
		return w;
	}
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
	string Ymnojenie()
	{
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
			for (int j = 0; j <= k - 1; j++)
			{
				int t = (int)(w[i + j] - 48) + (int)(a[j] - 48) * (int)(b[i] - 48) + c;
				t = perevod(t, osn);
				w[i + j] = '0' + (t % 10);
				c = t / 10;
			}
			w[i + k] = '0' + c;
		}
		reverse(w.begin(), w.end());

		while (w[0] == '0')
		{
			w.erase(0, 1);
		}
		return w;
	}

	string Ymnojenie(string a,string b)
	{
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
			for (int j = 0; j <= k - 1; j++)
			{
				int t = (int)(w[i + j] - 48) + (int)(a[j] - 48) * (int)(b[i] - 48) + c;
				t = perevod(t, osn);
				w[i + j] = '0' + (t % 10);
				c = t / 10;
			}
			w[i + k] = '0' + c;
		}
		reverse(w.begin(), w.end());

		while (w[0] == '0')
		{
			w.erase(0, 1);
		}
		return w;
	}

	int compare(string s1, string s2)
	{
		if (s1.length() > s2.length()) return 1;
		else if (s1.length() < s2.length()) return -1;
		else
		{
			int c = 0;
			while (c != s1.length())
			{
				if (s1[c] > s2[c]) return 1;
				else if (s1[c] < s2[c]) return -1;
				c++;
			}
			return 0;
		}
	}
	string fromIntToString(int n)
	{
		string str = "";
		int c = 0;
		while (n != 0)
		{
			str[c] = '0' + n % 10;
			n /= 10;
			c++;
		}
		reverse(str.begin(), str.end());
		return str;
	}
	string step(string b, int k)
	{
		int c = 1;
		while (c != k)
		{
			b = Ymnojenie(b, b);
			c++;
		}
		return b;
	}
	string Delenie()
	{
		string u = a;
		string v = b;
		int k = b.length();
		int l = a.length - k;
		// FIND D
		int d = (osn / ((int)(b[0] - 48) + 1));
		
		u = Ymnojenie(u, fromIntToString(perevod(d, osn)));
		v = Ymnojenie(v, fromIntToString(perevod(d, osn)));
		for (int i = k + l; i >= k; i--)
		{
			
			int y = (int)(u[i] - 48) * osn;
			int sV = y + (int)(u[i - 1] - 48);
			int minF = sV / ((int)(v[k - 1] - 48));
			int minS = osn - 1;
			if(mifS<min)
		}

	}

};
