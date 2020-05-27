#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n,r;
    int a[1005];
    while(cin>>n>>r)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int last=0;
        int cnt=0;
        int flag=0;
        while(last<n)
        {
            int index=min(last+r-1,n-1);
            while(index>=0&&index>=last-r+1)
            {
                if(a[index]==1)
                {
                    cnt++;
                    break;
                }
                index--;
            }
            if(index==-1||index==last-r)
            {
                flag=1;
                break;
            }
            last=index+r;
        }
        if(flag)
        {
            cout<<-1<<endl;
        }else{
            cout<<cnt<<endl;
        }
    }
	return 0;
}