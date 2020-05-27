#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, b;
		cin >> n >> b;
		int a[105];
		int flag = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if ((a[i] + b) % 7 == 0)
				flag = 1;
		}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}