#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
using namespace std;
typedef long long ll;
const int maxn = 100005;//题目描述n
struct node {
	int l, r;//节点表示范围l~r
	ll sum, lazy;//sum节点属性,lazy跟新延迟标记
	inline int len() {
		return r - l + 1;
	}
	inline void update(int val) {
		lazy += val;
		sum += 1LL * len()*val;//1LL防止int溢出，转为ll
	}
}tr[maxn * 4];
int a[maxn];
//回溯跟新
void push_up(int id) {
	tr[id].sum = tr[id << 1].sum + tr[id << 1 | 1].sum;
}
//下放标记
void push_down(int id) {
	ll lazy = tr[id].lazy;
	if (lazy == 0) return;
	tr[id << 1].update(lazy);
	tr[id << 1 | 1].update(lazy);
	tr[id].lazy = 0;
}
//建立线段树
void build(int id, int l, int r) {
	tr[id].l = l; tr[id].r = r;
	tr[id].lazy = tr[id].sum = 0;
	if (l == r) {
		tr[id].sum = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	push_up(id);//建立的过程中顺带区间统计
}
//跟新线段树
void update(int id, int l, int r, int val) {
	if (tr[id].l == l && tr[id].r == r) {
		tr[id].update(val);
		return;
	}
	push_down(id);
	int mid = (tr[id].l + tr[id].r) >> 1;
	if (r <= mid) update(id << 1, l, r, val);
	else if (l>mid) update(id << 1 | 1, l, r, val);
	else {
		update(id << 1, l, mid, val);
		update(id << 1 | 1, mid + 1, r, val);
	}
	push_up(id);
}
ll query(int id, int l, int r) {
	if (tr[id].l == l && tr[id].r == r) {
		return tr[id].sum;
	}
	push_down(id);
	int mid = (tr[id].l + tr[id].r) >> 1;
	if (r <= mid) return query(id << 1, l, r);
	else if (l>mid) return query(id << 1 | 1, l, r);
	else return query(id << 1, l, mid) + query(id << 1 | 1, mid + 1, r);
}
int main() {
	int n, q;
	char op[10];
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	build(1, 1, n);
	for (int i = 1; i <= q; ++i) {
		scanf("%s", op);
		if (op[0] == 'Q') {
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%lld\n", query(1, l, r));
		}
		else {
			int l, r, val;
			scanf("%d %d %d", &l, &r, &val);
			update(1, l, r, val);
		}
	}
	return 0;
}