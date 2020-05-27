#include <algorithm>
#include <queue>
#include <functional>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main()
{
	map<string, string>m;
	string s;
	string p;
	cin >> s;
	while (cin >> s&&s!= "END")
	{
		cin >> p;
		m[p] = s;
	}
	cin >> s;
	getchar();
	char ch[3005];
	while (1)
	{
		gets_s(ch);
		if (strcmp(ch, "END") == 0)
			break;
		int len = strlen(ch);
		string a = "";
		for (int i = 0; i < len; i++)
		{
			if (ch[i]<'a'||ch[i]>'z')
			{
				if (m[a] != "")
					cout << m[a];
				else
					cout << a;
				a = "";
				cout << ch[i];
			}
			else
				a += ch[i];
		}
		cout << endl;
	}
	return 0;
}
