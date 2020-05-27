#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
int main()
{
	priority_queue<double,vector<double>,less<double> >q;
	int n;
	double a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		q.push(a);
	}
	double temp, q1, q2;
	while (q.size()>1)
	{
		q1=q.top();
		q.pop();
		q2 = q.top();
		q.pop();
		temp = 2 * sqrt(q1*q2);
		q.push(temp);
	}
	printf("%.3lf\n", q.top());
	return 0;
}