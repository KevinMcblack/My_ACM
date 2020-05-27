#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#define INF 0x3f3f3f3f3f
#define eps 1e-6
typedef long long LL;
using namespace std;
const int maxn = 1e5+10;
int n, c, f;

struct MyStruct
{
	int score, aid;
}a[maxn];

bool cmp(MyStruct a, MyStruct b) { return a.score < b.score; }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> c >> f;
	priority_queue <int> q1, q2;
	for (int i = 1; i <= c; i++)
		cin >> a[i].score >> a[i].aid;
	sort(a+1, a + c+1, cmp);
	int mid = n / 2;
	int sum = 0;
	int before[maxn], after[maxn];

	for (int i = 1; i <= c; i++)
	{
		sum += a[i].aid;
		q1.push(a[i].aid);
		if (q1.size() > mid)
		{
			sum -= q1.top();
			q1.pop();
		}
		if (mid == q1.size())
			before[i] = sum;
	}

	sum = 0;
	for (int i = c; i >= 1; i--)
	{
		sum += a[i].aid;
		q2.push(a[i].aid);
		if (q2.size() > mid)
		{
			sum -= q2.top();
			q2.pop();
		}
		if (mid == q2.size())
			after[i] = sum;
	}

	for (int i = c-mid ; i >mid; i--)
	{
		if (before[i-1] + a[i].aid + after[i+1] <= f)
		{
			cout << a[i].score << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}