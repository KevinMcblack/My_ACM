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
bool isPrime(int num)
{
	for (int i = 2; i*i<num; i++)
		if (num%i == 0)
			return false;
	return true;
}
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
	int m, n;
	while (cin >> m >> n && m&&n)
	{
		if (isPrime(m))
		{
			cout << "no" << endl;
			continue;
		}
		int k=mod_pow(n, m, m);
		if (k == n%m)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}