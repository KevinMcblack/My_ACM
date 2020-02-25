#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
#define tim(t) int t;scanf("%d",&t);while(t--)
#define ll long long
const int maxn = 1000010;
const int MAXN = 100000+10;				//定义 MAXM 为线段最大长度
ll bit[MAXN*4], n, a[MAXN*4], bit1[MAXN*4];
int lowbit(int x)
{
	return x & (-x);
}

void add(ll *bit,int i, ll x)
{
	while (i <= n)
	{
		bit[i] += x;
		i += lowbit(i);
	}
}

void sub(ll *bit, int i, ll x)
{
	while (i <= n)
	{
		bit[i] -= x;
		i += lowbit(i);
	}
}
ll sum(ll bit[], int i)
{
	ll s = 0;
	while (i>0)
	{
		s += bit[i];
		i -= lowbit(i);
	}
	return s;
}
int main()
{
	int q;
	scanf("%lld%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		add(bit, i, a[i] * (n - i + 1));
		add(bit1, i, a[i]);
	}
	int type;
	while (q--)
	{
		scanf("%d", &type);
		if (type == 1)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			ll ans1 = sum(bit, b) - sum(bit, a - 1);
			ll ans2 = (sum(bit1, b) - sum(bit1, a - 1))*(n - b);
			printf("%lld\n", ans1-ans2);
		}	
		else
		{
			int ind, ans;
			scanf("%d%d", &ind, &ans);
			if (ans - a[ind] > 0)
			{
				add(bit, ind, (ans - a[ind])*(n - ind + 1));
				add(bit1, ind, ans - a[ind]);
			}	
			else
			{
				sub(bit, ind, (a[ind] - ans) * (n - ind + 1));
				sub(bit1, ind, a[ind] - ans);
			}
			a[ind] = ans;
		}
	}
	return 0;
}