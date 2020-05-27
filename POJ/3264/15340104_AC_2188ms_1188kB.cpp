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
const int maxn = 5e4 + 10;
#define ls u<<1
#define rs u<<1|1
#define lson l,mid,u<<1
#define rson mid+1,r,u<<1|1
#define INF 0x3f3f3f3f

int maxx[maxn << 2], minn[maxn << 2];

void pushup(int u)
{
	maxx[u] = max(maxx[ls], maxx[rs]);
	minn[u] = min(minn[ls], minn[rs]);
}

void build(int l,int r,int u)
{
	if (l == r){
		scanf("%d", &maxx[u]);
		minn[u] = maxx[u];
	}
	else {
		int mid = (l + r) >> 1;
		build(lson);
		build(rson);
		pushup(u);
	}
}

int query(int L,int R,int l,int r,int u,int flag)
{
	int mid = (l + r) >> 1;
	if (L <= l && R >= r)
		return flag ? maxx[u] : minn[u];
	int res;
	if (flag) {
		res = 0;
		if (L <= mid)
			res = max(query(L, R, lson, flag), res);
		if (R > mid)
			res = max(query(L,R,rson,flag), res);
	}
	else {
		res = INF;
		if (L <= mid)
			res = min(query(L,R,lson,flag),res);
		if (R > mid)
			res = min(query(L,R,rson,flag),res);
	}
	return res;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	build(1,n,1);
	while (m--)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		printf("%d\n",query(x,y,1,n,1,1)-query(x,y,1,n,1,0));
	}
	return 0;
}