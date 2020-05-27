/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-10 18:22:58 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-10 18:51:13
 */
#include <iostream>
#include <algorithm>
#include <vector>
typedef long long LL;
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int> arr;
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            int minn1=min(a,min(b,c));
            int minn2;
            if(a==minn1)
                minn2=min(b,c);
            else if(b==minn1)
                minn2=min(a,c);
            else if(c==minn1)
                minn2=min(a,b);
            //cout<<minn1<<" "<<minn2<<endl;
            arr.push_back(minn1);
            arr.push_back(minn2);
        }
        sort(arr.begin(),arr.end());
        LL sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=arr[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
