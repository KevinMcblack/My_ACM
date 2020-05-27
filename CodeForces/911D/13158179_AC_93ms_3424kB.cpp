//ori^=1 运算一次奇偶变一次  
#include<iostream>  
#include<string>  
#include<cstdio>  
#include<algorithm>  
#include<cmath>  
#include<iomanip>  
#include<queue>  
#include<cstring>  
#include<map>  
using namespace std;
typedef long long ll;
#define pi acos(-1.0)  
#define inf 0x3f3f3f  
#define M 1505  

int n, m, ans;
int a[M];

int main()
{
	int i, j, l, r;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ans = 0;
	for (i = 1; i <= n; i++)  //先求出所有逆序数，并判断奇偶  
		for (j = i + 1; j <= n; j++)
		{
			if (a[i]>a[j])
				ans ^= 1;   //ans=1 -> odd, ans=0 -> even  
		}
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d%d", &l, &r);
		int t = r - l +1;
		t = t * (t - 1) / 2; //[L,R]之间这t个数，在反转排列之后，任意两个数之间都相当于交换了位置，
		//有因为任意两个数是不相等的，所以有一次交换ans的奇偶改变一次，又因为只要判断奇偶所以不用管数之间的大小 
		//这个式子其实不过是为了特判r==l的时候 因为有加了1 现在乘以一个数-1来判断
		//如果反转的区间有奇数个二元组数对，那么逆序数的奇偶性就改变。因为1=1+0=0+1。
		if (t & 1)
			ans ^= 1;
		if (ans)
			printf("odd\n");
		else
			printf("even\n");
	}
	return 0;
}