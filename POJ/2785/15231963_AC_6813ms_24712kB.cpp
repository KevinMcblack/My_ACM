#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
typedef long long LL;
using namespace std;
const int maxn = 4000+5;
int n;
int A[maxn], B[maxn], C[maxn], D[maxn];
int CD[maxn*maxn];
LL sovle()
{
	int p = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			CD[p++] = C[i] + D[j];
	sort(CD, CD + p);
	LL res = 0;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			int cd = -(A[i]+B[j]);
			res += upper_bound(CD,CD+p,cd) - lower_bound(CD, CD + p, cd);
		}
	return res;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
	}
	printf("%lld\n", sovle());
	return 0;
}
