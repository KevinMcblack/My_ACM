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
	while (n--) {
		int m;
		char a[100005];
		cin >> m;
		cin >> a;
		if (((m + 1)*m / 2 % 2) & 1) {
			cout << -1 << endl;
			continue;
		}
		if ((m % 2 & 1) == 0){
			for (int i = 0; i < m; i++) {
				if (i % 4 == 0 || i % 4 == 3) {
					if (a[i] == '1')
						cout << 3;
					else
						cout << 1;
				}
				else if (i % 4 == 1 || i % 4 == 2) {
					if (a[i] == '1')
						cout << 4;
					else
						cout << 2;
				}
			}
			cout << endl;
		}
		else {
			if (a[0] == '1')
				cout << 3;
			else
				cout << 1;
			for (int i = 1; i < m; i++) {
				if ((i-1) % 4 == 0 || (i - 1) % 4 == 3) {
					if (a[i] == '1')
						cout << 3;
					else
						cout << 1;
				}
				else if ((i - 1) % 4 == 1 || (i - 1) % 4 == 2) {
					if (a[i] == '1')
						cout << 4;
					else
						cout << 2;
				}
			}
			cout << endl;
		}
	}
	return 0;
}