#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
char str[50];
int num[50];
int main()
{
	int t;
	cin >> t;
	getchar();
	while (t--)
	{
		int minn = 999999999;
		int k = 0;
		gets_s(str);
		int len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
				num[k++] = str[i] - '0';
		}
		if (k == 2)
		{
			cout << abs(num[0] - num[1]) << endl;
			continue;
		}
		while (num[0] == 0)//第一个数不能以零开头 
			next_permutation(num, num + k);
		do {
			int mid = (k + 1) / 2;
			if (num[mid])//第二个数不能以零开头
			{
				int a = 0, b = 0;
				for (int i = 0; i<mid; ++i)
					a = a * 10 + num[i];
				for (int i = mid; i < k; ++i)
					b = b * 10 + num[i];
				minn = min(abs(a - b), minn);
			}
				
		} while (next_permutation(num, num + k));
		cout << minn << endl;
	}
	return 0;
}