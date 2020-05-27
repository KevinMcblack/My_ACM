#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <stdlib.h>
using namespace std;
int main()
{
	string s1, s2, s = "zzzzzzzzzz";
	while (cin >> s1 >> s2)
	{
		s = "zzzzzzzzzz";
		for (int i = 0; i < s1.size(); i++)
			for (int j = 0; j < s2.size(); j++)
				s = min(s, s1.substr(0, i + 1) + s2.substr(0, j + 1));
		cout << s << endl;
	}
	return 0;
}