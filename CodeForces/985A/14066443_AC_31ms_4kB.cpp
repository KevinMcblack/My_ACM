#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
static int xx = []() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}();
int main() {
	int n, p[1007], sum[2] = { 0 }, cur[2] = { 1, 2 };
	cin >> n;
	for (int i = 1; i <= n / 2; i++) 
		cin >> p[i];
	sort(p + 1, p + 1 + n / 2);
	for (int i = 1; i <= n / 2; i++, cur[0] += 2, cur[1] += 2) {
		sum[0] += abs(cur[0] - p[i]);
		sum[1] += abs(cur[1] - p[i]);
	}
	cout << min(sum[0], sum[1]) << endl;
	return 0;
}