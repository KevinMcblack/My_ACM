#include<iostream>
#include<string>
#include<cstdlib>
#include<map>
using namespace std;
map< string, int > m;
int main()
{
	string str;
	char a;
	while (1)
	{
		scanf("%c", &a);
		if (a == '\n')
		{
			scanf("%c", &a);
			str.clear();
			if (a == '\n')
				break;
		}
		str += a;
		m[str]++;
	}
	while (cin >> str)
	{
		cout << m[str] << endl;
	}
	return 0;
}