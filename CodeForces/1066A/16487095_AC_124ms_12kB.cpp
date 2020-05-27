#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int t;
    int L,v,l,r;
    cin>>t;
    while(t--)
    {
        cin>>L>>v>>l>>r;
        int res=r/v-l/v;
        if(l%v==0)
            res+=1;
        cout<<L/v-res<<endl;
    }
	return 0;
}