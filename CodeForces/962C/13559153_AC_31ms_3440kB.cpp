#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;
int le, i, j, k, e;
char c[100];

void dfs(int x, int val, int step) {
	int b = c[x] - '0';
	if (x == le - 1) {
		if (sqrt(val) == (int)sqrt(val)&&val!=0) 
			e = min(step + 1, e);
		val = val * 10 + b;
		if (sqrt(val) == (int)sqrt(val) && val != 0)
			e = min(step, e);
		return;
	}
	if (b != 0 || val != 0) {
		dfs(x + 1, val * 10 + b, step);
	}
	dfs(x + 1, val, step + 1);
}

int main()
{
	cin >> c;
	le = strlen(c);
	e = INF;
	dfs(0, 0, 0);
	if (e == INF) {
		cout << -1 << endl;
		return 0;
	}
	cout << e << endl;
}
