#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	int n, pos, l, r;
	scanf("%d%d%d%d", &n, &pos, &l, &r);
	if (l == 1 && r == n)//没有需要关闭的网页
		printf("0");
	else if (l == 1) {
		int a = abs(r - pos);
		printf("%d", a + 1);
	}//只需要关闭右边的网页，两步，移到右边，关闭右边所有网页

	else if (r == n) {
		int a = abs(pos - l);
		printf("%d", a + 1);
	}//只需要关闭左边的网页，两步，移到左边，关闭左边所有网页

	else {
		int a = abs(pos - l);
		int b = abs(r - pos);
		printf("%d", min(a, b) + 2 + (r - l));
	}

	//第一步移到所花费的时间最少的一边，删去所有网页，然后再去另一边，需要经过一次l-r再删去另一边
	return 0;
}