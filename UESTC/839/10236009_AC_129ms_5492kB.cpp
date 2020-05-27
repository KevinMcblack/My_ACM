#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 200010
typedef long long LL;

LL bit[2][N], sum[N], a[N], maxn;
 // bit[0]???delta[x]. bit[1]???delta[x]*x
 // sum[i] = a[1]+...+a[i] + delta[1]*i + delta[2]*(i - 1) + delta[3]*(i - 2)+...+delta[i]*1   // a[i]???????
 //       = sigma( a[x] ) + sigma( delta[x]  *  (i + 1 - x) )
 //       = sigma( a[x] ) + (i + 1) * sigma( delta[x] ) - sigma( delta[x] * x )
int lowbit(int x)
{
	return x & (-x);
}
void update(int i, int x, int w)
{ 
	while(x <= maxn)
	bit[i][x] += w, x += lowbit(x);
}
LL query(int i, int x)
{ 	LL ans = 0;
	while(x)
	ans += bit[i][x], x -= lowbit(x);
	return ans; }
void Add(int l, int r, int w)
{
    update(0, l, w);
	update(0, r + 1, -w);
    update(1, l, w * l);
	update(1, r + 1, -w * (r + 1));
}
LL Sum(int l, int r)
{
    LL suml = sum[l - 1] + l * query(0, l - 1) - query(1, l - 1);
    LL sumr = sum[r] + (r + 1) * query(0, r) - query(1, r);
//    printf("sum : %d, %d\n", suml, sumr);
    return sumr - suml;
}

int main()
{
    int n, q;
    scanf("%d", &n);
	scanf("%d", &q); 
	maxn = n;
    for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), sum[i] = sum[i-1] + a[i], Add(i, i, a[i]);
    memset(bit, 0, sizeof(bit));
    while(q--)
	{
        int a, b, c, d;
        scanf("%d", &a);
        if(a == 1)
		{
            scanf("%d%d%d", &b, &c, &d);
            Add(b, c, d);
        } 
		else
		{
            scanf("%d%d", &b, &c);
            printf("%lld\n", Sum(b, c));
        }
    }
    return 0;
}