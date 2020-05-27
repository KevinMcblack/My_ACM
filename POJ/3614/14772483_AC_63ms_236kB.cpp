#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include <algorithm>
#define LL  long long
const int mod = 1e9 + 7;
const int  maxn = 2000000 + 10;
using namespace std;
struct cow
{
	int low, high;
}a[2600];
struct bottle
{
	int spf, cover;
}b[2600];
bool cmp1(struct cow aa, struct cow bb)
{
	return aa.high  < bb.high ;
}
bool cmp2(struct bottle aa, struct bottle bb)
{
	return aa.spf < bb.spf;
}
int main()
{
	int c, l;
	while (~scanf("%d%d",&c,&l))
	{
		for (int i = 0; i < c; i++)
			scanf("%d%d", &a[i].low, &a[i].high);
		for (int i = 0; i < l; i++)
			scanf("%d%d", &b[i].spf, &b[i].cover);
		sort(a, a + c, cmp1);
		sort(b, b + l, cmp2);
		int ans = 0;
		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < l; j++)
			{
				if (b[j].spf >= a[i].low&&b[j].spf <= a[i].high&&b[j].cover > 0) {
					b[j].cover--; 
					ans++;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
