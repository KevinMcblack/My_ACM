#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
const int B = 1000;

int A[maxn];
int I[maxn], J[maxn], K[maxn];
int num[maxn];
vector<int>backet[maxn / B];
int n, m;

void solve()
{
	for (int i = 0; i < n; i++)
	{
		backet[i / B].push_back(A[i]);
		num[i] = A[i];
	}
	sort(num, num + n);
	for (int i = 0; i < n / B; i++)
		sort(backet[i].begin(), backet[i].end());

	for (int i = 0; i < m; i++)
	{
		int L = I[i]-1, R = J[i], k = K[i];
		int lb = -1, rb = n - 1;

		while (rb-lb>1)
		{
			int mid = (lb+rb)/2;
			int x = num[mid];
			int tl = L, tr = R, c = 0;

			while (tl < tr&&tl%B != 0)
				if (A[tl++] <= x)
					c++;
			while (tl < tr&&tr%B != 0)
				if (A[--tr] <= x)
					c++;
			while (tl < tr)
			{
				int b = tl / B;
				c += upper_bound(backet[b].begin(),backet[b].end(),x) - backet[b].begin();
				tl += B;
			}
			if (c >= k)
				rb = mid;
			else
				lb = mid;
		}
		printf("%d\n", num[rb]);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < m; i++)
		scanf("%d%d%d", &I[i], &J[i], &K[i]);
	solve();
	return 0;
}