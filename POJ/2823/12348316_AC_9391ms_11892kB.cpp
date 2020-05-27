#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;
int a[1000050], maxx[1000050], minn[1000050];
int main()
{
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		int i;
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		deque<int> q1, q2;
		q1.clear();
		q2.clear();
		for (i = 0; i < n; i++)
		{
			while (!q1.empty() && a[i]>a[q1.back()])
			{
				q1.pop_back();
			}
			while (!q1.empty()&&i - k + 1 > q1.front())
			{
				q1.pop_front();
			}
			q1.push_back(i);
			maxx[i] = a[q1.front()];

			while (!q2.empty() && a[i]<a[q2.back()])
			{
				q2.pop_back();
			}
			while (!q2.empty()&&i - k + 1 > q2.front())
			{
				q2.pop_front();
			}
			q2.push_back(i);
			minn[i] = a[q2.front()];
		}
		for (i = k - 1; i<n - 1; i++)
		{
			printf("%d ", minn[i]);
		}
		printf("%d\n", minn[i]);
		for (i = k - 1; i< n - 1; i++)
		{
			printf("%d ", maxx[i]);
		}
		printf("%d\n", maxx[i]);
	}
	return 0;
}
