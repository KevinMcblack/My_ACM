#include <algorithm>
#include <queue>
#include <functional>
#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
int main()
{
	int n, q;
	vector<int>v,v1;
	cin >> n >> q;
	int t;
	int sum1 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		v.push_back(t);
		v1.push_back(t);
	}
	sum1 += v[0];
	int len1 = v.size();
	for (int i = 1; i < len1 - 1; i = i + 2)
		sum1 += (v[i + 1] - v[i]);
	if ((len1) % 2 == 0)
		sum1 += (q - v[len1 - 1]);
	int maxx = -1;
	int k = 1, k1 = 1;
	vector<int>::iterator it;
	for (int p = 0; p<v.size(); p++)
	{
		if ((p<v.size()-1&&p>0)&&((v[p] - v[p-1]) == (v[p + 1] - v[p])))
			continue;
		int sum = 0,sum2=0;
		k = v[p] - 1;
		it = find(v.begin(), v.end(), v[p]);
		v.insert(it, k);
		k1 = v1[p] + 1;
		it = find(v1.begin(), v1.end(), v1[p]);
		v1.insert(it+1, k1);
		int len = v.size();
		sum += v[0];
		sum2 += v1[0];
		for (int i = 1; i < len - 1; i = i + 2)
		{
			sum += (v[i + 1] - v[i]);
			sum2 += (v1[i + 1] - v1[i]);
		}
		if ((len) % 2 == 0)
		{
			sum += (q - v[len - 1]);
			sum2 += (q - v1[len - 1]);
		}
		maxx = max(maxx, max(sum,sum2));
		it = find(v.begin(), v.end(), k);
		v.erase(it);
		it = find(v1.begin(), v1.end(), k1);
		v1.erase(it);
	}
	cout << max(maxx, sum1) << endl;
	return 0;
}
