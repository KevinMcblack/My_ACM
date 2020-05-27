#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
struct node
{
	unsigned long long v;
	int p;
};
struct cmp
{
	bool operator ()(node a, node b)
	{
		if (a.v != b.v)
			return a.v > b.v;
		else
			return a.p > b.p;
	}
};
priority_queue<node, vector<node>, cmp> q;
node in[150000];
node res[150000];
bool CMP(node a, node b) {
	return a.p < b.p;
}
int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		while (!q.empty())
			q.pop();
		memset(res, 0, sizeof(res));
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &in[i].v);
			in[i].p = i;
			q.push(in[i]);
		}	
		while (!q.empty())
		{
			node t = q.top();
			q.pop();
			if (!q.empty() && t.v == q.top().v)
			{
				node m = { t.v * 2ll,q.top().p };
				q.pop();
				q.push(m);
			}
			else
			{
				res[flag++] = t;
			}
		}
		sort(res, res + flag, CMP);
		printf("%d\n", flag);
		for (int i = 0; i < flag; i++)
		{
			printf("%lld ", res[i].v);
		}
		printf("\n");
	}
	return 0;
}
