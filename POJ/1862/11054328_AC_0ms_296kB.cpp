#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool cmp(double a,double b)
{
	return a>b;
}
int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);
	int i;
	double a[10050];
	for(i=0;i<n;i++)
		scanf("%lf",&a[i]);	
	sort(a,a+n,cmp);
	for(i=0;i<n;i++)
	{
		a[i+1]=2*sqrt(a[i]*a[i+1]);
		if(i==n-1) 
			printf("%.3lf\n",a[i]); 
	}
	return 0;
}