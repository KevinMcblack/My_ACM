#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;

int main()
{
	long long n,r,avr,s=0,x=0; 
    cin>>n>>r>>avr;
	pair <long long, long long> a[100005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i].second>>a[i].first;
		s+=a[i].second;
	}
    x=n*avr-s;
    if (x<=0)
    {
    cout<<0; 
    return 0;
    }
	sort(a,a+n);
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		long long kol=min(x, r-a[i].second);
		x-=kol;
		ans+=kol*a[i].first;
		if (x==0)
		{	
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}