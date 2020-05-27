/*
 * @Author: KevinMcblack 
 * @Date: 2019-01-17 20:02:04 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2019-01-17 20:27:49
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+5;

struct poem{
    string word;
    int mul;
}a[105];

bool cmp(struct poem aa,struct poem bb){
    if(aa.mul==bb.mul){
        return aa.word<bb.word;
    }
    return aa.mul>bb.mul;
}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        long long int sum=0;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>a[i].word>>a[i].mul;
        }
        sort(a,a+n,cmp);
        string res="";
        for(long long i=0;i<m;i++){
            sum+=a[i].mul*(m-i);
            if(i==0){
                res+=a[i].word;
            }else{
                res+=" "+a[i].word;
            }
        }
        cout<<sum<<" "<<res<<endl;
    }
    return 0;
}
