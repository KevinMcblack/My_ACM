#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#include <deque>
#include <math.h>
using namespace std;
typedef long long ll;
int a[100005],cnt[100005];
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		memset(cnt, 0, sizeof(cnt));
		int i;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		int flag = 0;
		for (i = 100000; i >= 0; i--)
		{
			if (cnt[i] % 2)
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
			printf("Agasa\n");
		else
			printf("Conan\n");
	}
	return 0;
}
