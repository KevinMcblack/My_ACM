#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
#include<string>
using namespace std;
long long unsigned mod;
map <string, long long unsigned>m;
void init()
{
	mod = 1;
	for (int i = 1; i <= 47; i++)
		mod *= 2;
}
int main()
{
	init();
	string op;
	string s,s1;
	long long unsigned a;
	while (cin >> op)
	{
		if (op == "def")
		{
			cin >> s >> a;
			m[s] = a % mod;
		}
		if (op == "add")
		{
			cin >> s >> s1;
			m[s] = (m[s] + m[s1]) % mod;
		}
		if (op == "div")
		{
			cin >> s >> s1;
			m[s] = (m[s] / m[s1]) % mod;
		}
		if (op == "mul")
		{
			cin >> s >> s1;
			m[s] = (m[s] * m[s1]) % mod;
		}
		if (op == "sub")
		{
			cin >> s >> s1;
			m[s] = (m[s] - m[s1]) % mod;
		}
		if (op == "mod")
		{
			cin >> s >> s1;
			m[s] = (m[s] % m[s1]) % mod;
		}
		cout << s << " = " << m[s] << endl;
	}
	return 0;
}
