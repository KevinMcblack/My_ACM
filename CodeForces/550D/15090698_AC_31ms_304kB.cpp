#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, k, i, j;
	while (~scanf("%d", &k))
	{
		if (k == 1)
		{
			printf("YES\n2 1\n1 2\n");
			continue;
		}
		if (k % 2 == 0)//偶数不行
		{
			printf("NO\n");
			continue;
		}
		n = k + 2;//我们要增加两个节点
		printf("YES\n");
		printf("%d %d\n", n * 2, n*k);//有两边，每个节点有k个度
		printf("%d %d\n", n - 1, n - 2);//让新增加的节点相连接
		printf("%d %d\n", 2 * n - 1, 2 * n - 2);//对称
		for (i = 1; i <= n - 3; i++)
		{
			//让n,n-1,n-2与k-1个节点相连接
			printf("%d %d\n", n, i);
			printf("%d %d\n", n - 1, i);
			printf("%d %d\n", n - 2, i);
			//对称
			printf("%d %d\n", 2 * n, n + i);
			printf("%d %d\n", 2 * n - 1, n + i);
			printf("%d %d\n", 2 * n - 2, n + i);
		}
		for (i = 1; i <= n - 3; i++)//k-1个节点相互连接
		{
			if (i % 2) j = i + 2;//奇数跳过一个与后面的相连
			else j = i + 1;//偶数直接与后面相连
			while (j <= n - 3)
			{
				printf("%d %d\n", i, j);
				printf("%d %d\n", n + i, n + j);
				j++;
			}
		}
		printf("%d %d\n", n, n + n);//连接两块

	}

	return 0;
}
