#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
int a[7];
int num[4] = { 0,5,3,1 };
int main()
{
	while (cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] && (a[1] + a[2] + a[3] + a[4] + a[5] + a[6]) != 0)
	{
		int ans = a[6] + a[5] + a[4] + (a[3] + 3) / 4;  //a6,a5,a4,每个物品占有一个箱子(a3 + 3 ) / 4 代表a3的物品需要占
		int a2 = a[4] * 5 + num[a[3] % 4];  //统计所有的大物品放进箱子中后a2物品的空位子有多少
		if (a[2]>a2)
			ans += (a[2] - a2 + 8) / 9;
		int a1 = ans * 36 - a[6] * 36 - a[5] * 25 - a[4] * 16 - a[3] * 9 - a[2] * 4;
		if (a[1]>a1)   //求a1的空位子，只需要统计剩余的面积即可
			ans += (a[1] - a1 + 35) / 36;
		printf("%d\n", ans);
	}
	return 0;
}
