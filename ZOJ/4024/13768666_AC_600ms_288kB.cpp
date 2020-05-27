#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--){
		int m;
		int a[100005];
		int maxx = 0;
		int k = 0;
		cin >> m;
		for (int i = 0; i < m; i++){
			cin >> a[i];
			if (maxx < a[i])
			{
				maxx = a[i];
				k = i;
			}
		}
		if (k == (m - 1) || k == 0) {
			cout << "No" << endl;
			continue;
		}
		int flag = 0;
		for (int i = 0; i < k; i++) {
			if (a[i + 1] <= a[i]){
				flag = 1;
				break;
			}
		}
		if(flag) {
			cout << "No" << endl;
			continue;
		}
		for (int i = k; i < m-1; i++) {
			if (a[i + 1] >= a[i]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;
	}
	return 0;
}