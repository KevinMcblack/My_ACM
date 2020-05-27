#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
struct MyStruct
{
	double x, y;
}a[1050];
bool cmp(MyStruct aa, MyStruct bb)
{
		return aa.x < bb.x;
}
int main()
{
	int n, d;
	int t = 1;
	while(cin>>n>>d&&n&&d)
	{ 
		int k = 0;
		int x, y;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			if (k == 1)
				continue;
			if (y > d)
				k = 1;
			else
			{
				a[i].x = (double)x - sqrt((double)d*d - y * y);//勾股定理
				a[i].y = (double)x + sqrt((double)d*d - y * y);
			}
		}
		if (k == 1)
		{
			cout << "Case "<<t++<<": "<< -1 << endl;
			continue;
		}
		if (n == 1)
		{
			cout << "Case " << t++ << ": " << 1 << endl;
			continue;
		}
		sort(a, a + n, cmp);
		int ans = 1;
		double now = a[0].y;
		for (int i = 1; i < n; i++)
		{
			if (now>a[i].y)
				now = a[i].y;
			else if (now < a[i].x)
			{
				now = a[i].y;
				ans++;
			}
		}
		cout << "Case " << t++ << ": " << ans << endl;
	}
	return 0;
}