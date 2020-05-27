#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int per[50010];
struct node
{
	int start, end, pos;
}cow[50010], now;

bool operator < (const node &a, const node &b)//产奶结束越早的越优先 
{
	if (a.end == b.end)
		return a.start>b.start;
	return a.end>b.end;
}
bool cmp(node aa, node bb)
{
	if (aa.start == bb.start)
		return aa.end < bb.end;
	else
		return aa.start < bb.start;
}
int main()
{
	int n, i, k, cnt;
	while (scanf("%d", &n) != EOF)
	{
		priority_queue<node>q;
		for (i = 0; i<n; ++i)
		{
			scanf("%d%d", &cow[i].start, &cow[i].end);
			cow[i].pos = i;//记录给出数据时的编号 
		}
		sort(cow, cow + n, cmp);
		memset(per, 0, sizeof(per));
		per[cow[0].pos] = 1;
		k = 1;
		q.push(cow[0]);
		for (i = 1; i<n; ++i)
		{
			now = q.top();
			if (cow[i].start>now.end)//同用一个挤奶机器 
			{
				per[cow[i].pos] = per[now.pos];
				q.pop();
			}
			else//增加一个挤奶机器 
				per[cow[i].pos] = ++k;
			q.push(cow[i]);
		}
		printf("%d\n", k);
		for (i = 0; i<n; ++i)
			printf("%d\n", per[i]);
	}
	return 0;
}
