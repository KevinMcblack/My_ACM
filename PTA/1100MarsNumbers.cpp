#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	string a[13] = { "tret",
		"jan",
		"feb",
		"mar",
		"apr",
		"may",
		"jun",
		"jly",
		"aug",
		"sep",
		"oct",
		"nov",
		"dec" };
	string b[13] = {
		" ",
		"tam",
		"hel",
		"maa",
		"huh",
		"tou",
		"kes",
		"hei",
		"elo",
		"syy",
		"lok",
		"mer",
		"jou" };
	string s;
	int n;
	cin >> n;
	getchar();
	while (n--)
	{
		
		getline(cin, s);
		int len = s.size();
		int number = -1;
		if (s[0] - '0' <= 9)
			number = stoi(s);
		if (number != -1)
		{
			int k = number / 13;
			if(k==0)
			{
				cout << a[number] << endl;
			}
			else if(number%13==0)
			{
				cout<<b[k]<<endl;
			}
			else if (k != 0)
			{
				cout << b[k] << " " << a[number - k * 13] << endl;
			}
		
		}
		else
		{
			if (len>3)
			{
				string s1 = s.substr(0, 3);
				string s2 = s.substr(4);
				int sum = 0;
				for (int i = 0; i<13; i++)
				{
					if (b[i] == s1)
					{
						sum += (i * 13);
					}
					if (a[i] == s2)
					{
						sum += i;
					}
				}
				cout << sum << endl;
			}
			else
			{
				string s1 = s.substr(0,3);
				for (int i = 0; i<13; i++)
				{
					if (b[i] == s1)
					{
						cout << i * 13 << endl;
						break;
					}
					if (a[i] == s1)
					{
						cout << i << endl;
						break;
					}
				}
			}

		}
	}
	return 0;
}
