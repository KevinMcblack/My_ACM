#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<vector>
#include<functional>
using namespace std;

int main()
{
	int n;
	int t;
	map<int, int>m;
	while (~scanf("%d", &n))
	{
		m.clear();
		int maxx = -1;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &t);
			m[t]++;
			maxx = max(m[t], maxx);
		}
		printf("%d\n", maxx);
	}
	return 0;
}
