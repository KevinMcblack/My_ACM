#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include <algorithm>
#define LL  long long
#define eps 1e-6
const int mod = 1e9 + 7;
const int  maxn = 1005;
using namespace std;

int father[maxn], n;
int COUNT[maxn], num;
struct point
{
	double x, y;
}pt[maxn];

void init() {
	int i;
	num = 0;
	memset(COUNT, 0, sizeof(COUNT));
	for (int i = 0; i < maxn; i++)
		father[i] = i;
}

int find(int p)
{
	if (father[p] == p)
		return p;
	return father[p] = find(father[p]);
}

double dis(point a, point b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void Union(int a, int b)
{
	int x, y;
	x = find(a);
	y = find(b);
	if (x != y)
		father[y] = x;
}
int main()
{
	double d;
	char control[2];
	scanf("%d%lf", &n, &d);
	init();
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &pt[i].x, &pt[i].y);
	int xx, yy;
	while (~scanf("%s", control))
	{
		if (control[0] == 'O')
		{
			scanf("%d", &xx);
			for (int i = 0; i < num; i++)
				if (dis(pt[COUNT[i]], pt[xx]) <= d + eps)
					Union(COUNT[i], xx);
			COUNT[num++] = xx;
		}
		if (control[0] == 'S')
		{
			scanf("%d%d", &xx, &yy);
			if (find(xx) == find(yy))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
	}
	return 0;
}
