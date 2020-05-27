#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 200005;

int n;
int a[maxn];

int main()
{
	while (cin >> n) {
		int tmp, sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		a[0] = 0;
		for (int i = 1; i <= n; i++) {
			a[i] += a[i - 1];
			if (sum % 2) {
				if (a[i] >= sum / 2 + 1) { cout << i << endl; break; }
			}
			else {
				if (a[i] >= sum / 2) { cout << i << endl; break; }
			}
		}
	}
	return 0;
}