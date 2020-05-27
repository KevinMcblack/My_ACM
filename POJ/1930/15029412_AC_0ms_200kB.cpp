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
#define INF 0x3f3f3f3f3f3f
LL gcd(LL a, LL b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int point;
	while (cin >> s && s != "0")
	{
		int len = s.size();
		for (int i = 2; i < len; i++)
		{
			if (s[i] == '.')
			{
				point = i;
				break;
			}
		}
		LL temp = 0;
		for (int i = 2; i < point; i++)
			temp = temp * 10 + s[i]-'0';
		LL ans_num = INF, ans_cnt;
		for (int i = 2; i < point; i++)
		{
			LL cnt = 0, num = 0;
			for (int k = i; k < point; k++)
			{
				num = num * 10 + 9;
			}
			cnt = temp;
			LL temp_cnt = 0;
			for (int k = 2; k < i; k++)
			{
				temp_cnt = temp_cnt * 10 + s[k] - '0';
				num *= 10;
			}
			cnt -= temp_cnt;
			LL res = gcd(num,cnt);
			cnt /= res;
			num /= res;
			if (num < ans_num)
			{
				ans_num = num;
				ans_cnt = cnt;
			}
		}
		cout << ans_cnt << "/" << ans_num << endl;
	}
	return 0;
}