/*
 * @Author: KevinMcblack 
 * @Date: 2019-01-16 10:09:02 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2019-01-16 11:47:56
 */

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+5;
struct node{
    int a,b;
}exam[maxn];
bool cmp(struct node aa,struct node bb){
    return aa.b<bb.b;
}
int main(int argc, char const *argv[])
{
    long long n,r,avg;
    while(cin>>n>>r>>avg){
        long long sum=0;
        
        for(int i=0;i<n;i++){
            cin>>exam[i].a>>exam[i].b;
            sum+=exam[i].a;
        }
		long long need=avg*n-sum;
        if(need<=0){
            cout<<0<<endl;
            continue;
        }
        long long cnt=0;
        sort(exam,exam+n,cmp);
        int flag=0;
        for(int i=0;i<n;i++){
            if(exam[i].a==r){
                continue;
            }
            long long some=min(need,r-exam[i].a);
            cnt+=some*exam[i].b;
			need-=some;
            if(need<=0){
                break;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}