#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
//const int N=2e4+10;
priority_queue<ll,vector<ll>,greater<ll> > gg;
int main()
{
	int n,a,i,b,len;
	ll ans;
  	while(scanf("%d",&n)!=EOF)
  	{
	  	ans=0;
	  	len=0;
		for(i=0;i<n;i++)
	   	{
	    	scanf("%d",&a);
			gg.push(a);
			len++;
	    }
   		//printf("%d\n",len);
	    while(len>=2)
		{
	        a=gg.top();gg.pop();
	        b=gg.top();gg.pop();
	        a+=b;
			ans+=a;
	        gg.push(a);
			len--;
	    }
	    printf("%lld\n",ans);  	
	}
    return 0;
}