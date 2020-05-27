#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
using namespace std;
struct input {
	string a;
	int b;
}k[150];
bool cmp(struct input aa, struct input bb) {
	if (aa.b == bb.b)
		return aa.a < bb.a;
	return aa.b > bb.b;
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		for (int i = 0; i < m; i++)
			cin >> k[i].a >> k[i].b;
		sort(k, k + m, cmp);
		long long sum = 0;
		for (long i = 0; i < n; i++)
		{
			sum += (n - i)*k[i].b;
		}
		cout << sum << " ";
		for (int i = 0; i < n; i++)
			if(i==0)
				cout << k[i].a;
			else
			cout << " "<<k[i].a;
		cout << endl;
	}
	return 0;
}