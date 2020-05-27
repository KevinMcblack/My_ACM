#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <stack>
#include <map>

using namespace std;
int t;
int num;
map <int,int> m;
int vis[1005];
int a[1005];

int dfs(int len) 
{
	while (len&&vis[len])
		len--;
	if (len <= 0)
		return 1;
	if (len == 1)
		return 0;
	int i, j;
	i = 0, j = len - 1;
	for (; i <= 5;)
	{
		if (j <= 0)
			return 0;
		if (vis[j])
		{
			j--;
			continue;
		}
		if (a[len] == a[j])
		{
			vis[j] = 1;
			if (dfs(len - 1))
				return 1;
			vis[j] = 0;
		}
		i++, j--;
	}
	return 0;
}
int main()
{
	while (scanf("%d",&t)!=EOF)
	{
		m.clear();
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= t; i++)
		{
			scanf("%d", &a[i]);
			m[a[i]]++;
			vis[i] = 0;
		}	
		if (t & 1)
		{
			printf("0\n");
			continue;
		}
		int flag = 1;
		map<int, int>::iterator it;
		for (it = m.begin(); it != m.end(); it++)
		{
			if (it->second % 2 == 1)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
		{
			printf("0\n");
			continue;
		}
		printf("%d\n", dfs(t));
	}
	return 0;
}