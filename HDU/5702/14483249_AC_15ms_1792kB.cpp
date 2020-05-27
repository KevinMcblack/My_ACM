#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
struct MyStruct
{
	int num;
	string s;
}a[100];
bool cmp(MyStruct aa, MyStruct bb)
{
	return aa.num > bb.num;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{	
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i].s >> a[i].num;
		sort(a, a + n, cmp);
		cout << a[0].s;
		for (int i = 1; i < n; i++)
			cout << " " << a[i].s;
		cout << endl;
	}
	return 0;
}