#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
static int xx = []() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}();

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		while (k--)
		{
			if (n % 10 != 0)
				n--;
			else
				n /= 10;
		}
		cout << n << endl;
	}
	return 0;
}
