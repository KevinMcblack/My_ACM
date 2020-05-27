#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
#define MAXM 500000
const int maxn = 100010;
int main()
{
	int t; 
	scanf("%d", &t); 
	while (t--)
	{
		int n, q;
		int in[maxn];
		map<int, int> m;
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &in[i]);
			if (in[i])
				m[in[i]]++;
		}
		while (q--)
		{
			int type;
			scanf("%d", &type);
			if (type == 1)
			{
				int a, b;
				scanf("%d%d", &a, &b);
				if (in[a])
				{
					m[in[a]]--;
					if (m[in[a]] == 0)
						m.erase(in[a]);
				}
				if (b)
					m[b]++;
				in[a] = b;
			}
			else
			{
				printf("%d\n", m.size());
			}
		}
	}
	return 0;
}
