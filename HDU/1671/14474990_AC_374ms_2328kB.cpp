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
	int t;
	cin >> t;
	while (t--)
	{
		vector<string>v;
		int n;
		cin >> n;
		string s;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end(), less<string>());
		bool flag = false;
		for (int i = 0; i < n-1; i++)
		{
			
			if (v[i].compare(0,v[i].size(),v[i + 1], 0, v[i].size())==0)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}