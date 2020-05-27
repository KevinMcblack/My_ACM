#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
#include <cstring>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f3f3f
#define maxn 10010
LL mod_pow(LL x,LL n,LL mod)
{
	if (n == 0)return 1;
	LL res = mod_pow(x*x%mod,n/2,mod);
	if (n & 1)
		res = res * x%mod;
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (n--)
	{
		int m;
		cin >> m;
		int k;
		int a, b;
		LL sum=0;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> a >> b;
			sum += mod_pow(a, b, m);
		}
		cout << sum%m << endl;
	}
	return 0;
}