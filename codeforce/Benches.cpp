/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-13 13:17:11 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-13 16:13:50
 */
#include <iostream>
#include <algorithm>
using namespace std;
//n把椅子已经有初始值 在加进来m个人 求出每把椅子的最大可能k和最小可能k
//把椅子上已有的人数和新加进来的人数求和 求出平均值
//主要是最后不要忘记max(已有人数最大，新加入平均)
int main()
{
	int n, m;
	while (cin >> n)
	{
		int sum = 0;
		int maxx = -1;
		cin >> m;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			sum += a;
			maxx = max(maxx, a);
		}
		sum += m;
		int res = sum / n;
		if (sum % n != 0) //如果不整除 +1
			cout << max(res + 1, maxx) << " " << maxx + m << endl;
		else
			cout << max(res, maxx) << " " << maxx + m << endl;
	}
	return 0;
}