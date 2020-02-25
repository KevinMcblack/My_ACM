/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-09 18:43:05 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-09 19:18:45
 */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct wifi{
    int x,y,r,speed;
}ali[105];
bool cmp(wifi aa,wifi bb)
{
    return aa.speed>bb.speed;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        int cnt=0;
        long long maxx=-1;
        for(int i=0;i<a;i++)
        {
            cin>>ali[i].x>>ali[i].y>>ali[i].r>>ali[i].speed;
        }
        sort(ali,ali+a,cmp);
        if(b==1)
        {
            cout<<ali[0].speed<<endl;
            continue;
        }
        for(int i=0;i<a;i++)
        {
            long long sum=0;
            cnt=0;
            sum+=ali[i].speed;
            for(int j=i+1;j<a;j++)
            {
                double temp=sqrt(pow(ali[i].x-ali[j].x,2)+pow(ali[i].y-ali[j].y,2));
                if(temp<=max(ali[i].r,ali[j].r))
                {
                    cnt++;
                    sum+=ali[j].speed;
                }
                if(cnt>=b)
                    break;
            }
            maxx=max(maxx,sum);
        }
        cout<<maxx<<endl;
    }
    return 0;
}