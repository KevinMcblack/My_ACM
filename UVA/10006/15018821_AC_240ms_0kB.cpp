#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 6e4 + 6000;
const int maxv = 5e4 + 7;
const int maxe = 2e5 + 7;
typedef long long LL;
#define INF 0x3f3f3f3f
int prime[maxn];
bool is[maxn];
void getPrime()
{
	memset(is,true,sizeof(is));
	for (int i = 2; i <= maxn; i++)
	{
		if (is[i])
		{
			for (int j = 2 * i; j < maxn; j += i)
				is[j] = false;
		}
	}
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
	getPrime();
	int n;
	while (cin >> n && n)
	{
		if (is[n])
		{
			cout << n<<" is normal." << endl;
			continue;
		}
		bool flag = true;
		for (int i = 2; i < n; i++)
		{
			if (mod_pow(i, n, n) != i)
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "The number "<<n<<" is a Carmichael number." << endl;
		else
			cout << n << " is normal." << endl;
	}
	return 0;
}