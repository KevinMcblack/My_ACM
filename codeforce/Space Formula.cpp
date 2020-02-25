#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=2e5+5;
int s[maxn];
int p[maxn];
int main(int argc, char const *argv[])
{
    int n,d;
    while(cin>>n>>d){
       for(int i=0;i<n;i++){
           cin>>s[i];
       }
       for(int i=0;i<n;i++){
           cin>>p[i];
       }
       s[d-1]+=p[0];
       int temp=s[d-1];
       int l,r;
       l=1,r=n-1;
       
       for(int i=0;i<n;i++){
           if(i!=d-1){
               if(s[i]<temp){
                   s[i]+=p[r];
                   r--;
                   if(r==d-1)
                        r--;
                   
               }else{
                   s[i]+=p[l];
                   l++;
                   if(l==d-1)
                        l++;
               }
           }
       }
       sort(s,s+n);
       int cnt=0;
       for(int i=n-1;i>=0;i--){
           cnt++;
           if(s[i]==temp)
           {
               cout<<cnt<<endl;
                break;
           }
       }
    }
    return 0;
}
