#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
long long a[10005], b[10005];
int main()
{
	int n, s;
	while (cin >> n >> s)
	{
		long long sum = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		for (int i = 0; i < n; i++)
			a[i + 1] = min(a[i] + s, a[i + 1]);
		for (int i = 0; i < n; i++)
			sum += a[i]*b[i];
		cout << sum << endl;
	}
	return 0;
}