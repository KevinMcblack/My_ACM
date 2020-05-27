#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<set>
#include<string>
#include<map>
using namespace std;
const int mod = 1e9;
int dp[1000005];
int main()
{
	int n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	dp[4] = 4;
	dp[5] = 4;
	for (int i = 6; i <= 1000000; i = i + 2)
	{
		dp[i] = (dp[i - 2] + dp[i /2])%mod;
		dp[i + 1] = dp[i]%mod;
	}
	while (cin >> n)
	{
		cout << dp[n]%mod << endl;
	}
	return 0;
}
/*
1 2 3 4 5 6 7 8
1 2 2 4 4 6 6 10

1
1

2
1 1
2

3
1 1 1
1 2

4
1 1 1 1
1 1 2
2 2
4

5
1 1 1 1 1
1 1 1 2
1 4
1 2 2 

6
1 1 1 1 1 1
1 1 1 1 2
1 1 4
2 4
2 2 2
1 1 2 2

7

8
1 1 1 1 1 1 1 1
1 1 1 1 1 1 2
1 1 1 1 2 2
1 1 2 2 2
2 2 2 2
2 2 4
1 1 1 1 4
4 4
1 1 2 4
8
*/