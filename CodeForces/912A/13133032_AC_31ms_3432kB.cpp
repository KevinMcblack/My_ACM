#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
typedef  long long ll;
using namespace std;
int main()
{
	long long a, b, x, y, z, ans;
	while (cin >> a >> b >> x >> y >> z)
	{
		ans = 0;
		if (y <= a) a -= y;
		else    ans += y - a, a = 0;
		if (y <= b)  b -= y;
		else ans += y - b, b = 0;
		if (x * 2 <= a) a -= x * 2;
		else ans += x * 2 - a, a = 0;
		if (z * 3 <= b) b -= z * 3;
		else ans += z * 3 - b, b = 0;
		cout << ans << endl;
	}
	return 0;
}