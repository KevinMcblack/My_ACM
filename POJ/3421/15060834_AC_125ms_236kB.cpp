#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f3f3f
const int maxn = 1e6 + 10;
vector<int>v;
vector<int>::iterator it;
void prime_factor_time(int n)
{
	v.clear();
	for (int i = 2; i*i <= n; i++)
	{
		int time = 0;
		while (n%i == 0)
		{
			n /= i;
			time++;
		}
		v.push_back(time);
	}
	if (n != 1)
		v.push_back(1);
}
LL factor(int n)
{
	LL res=1;
	for (int i = 1; i <= n; i++)
		res *= i;
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> n && n)
	{
		prime_factor_time(n);
		int sum = 0;
		for (it = v.begin(); it != v.end(); it++)
			sum += *it;
		LL ans = factor(sum);
		for (it = v.begin(); it != v.end(); it++)
			ans /= factor(*it);
		cout << sum << " " << ans << endl;
	}
	return 0;
}