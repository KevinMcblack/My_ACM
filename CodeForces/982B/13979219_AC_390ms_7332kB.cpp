#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
static int xx = []() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}();
struct node {
	int id;
	int w;
}p[200005], temp;
bool cmp(struct node aa, struct node bb) {
	return aa.w < bb.w;
}
int b[400010];
struct cmp1
{
	bool operator ()(const node &a, const node &b)
	{
		return a.w<b.w;     
	}
};
priority_queue<node, vector<node>, cmp1> q;
int main()
{
	string str;
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> p[i].w;
			p[i].id = i;
		}
		cin >> str;
		int k = 1;
		sort(p+1, p + n+1, cmp);
		for (int i = 0; i < 2 * n; i++)
		{
			if (str[i] == '0')
			{
				b[i] = p[k].id;
				q.push(p[k]);
				k++;
			}
			else
			{
				temp= q.top();
				q.pop();
				b[i] = temp.id;
			}
		}
		cout << b[0];
		for (int i = 1; i < 2 * n; i++)
			cout << " " << b[i];
		cout << endl;
	}
	return 0;
}