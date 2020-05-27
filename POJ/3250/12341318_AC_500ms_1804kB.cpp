#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	scanf("%d", &n);
	ll a[100005];
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	ll count = 0;
	stack<int>s;
	for (int i = 0; i < n; i++)
	{
		while (!s.empty() && s.top() <= a[i])
		{
			//printf("%d\n", s.top());
			s.pop();
		}
		count += s.size();
		//printf("%d %lld\n",s.size(),count);
		s.push(a[i]);
	}
	printf("%lld\n", count);
	return 0;
}
