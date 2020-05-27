#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
using namespace std;
const int maxn = 1e3 + 5;
#define IO ios::sync_with_stdio(false);\
    cin.tie(0);\
    cout.tie(0);
#define INF 0x3f3f3f3f
const int fx[10]={1,0,0,0,1,0,1,0,2,1};

int f(int x){
    int res=0;
    do{
        res+=fx[x%10];
        x/=10;
    }while(x);
    return res;
}

int g(int k,int x){
    while(k--){
        x=f(x);
        if(x==0){
            return k%2;
        }
        if(x==1){
            return 1-k%2;
        }
    }
    return x;
}

int main()
{
    int x,k;
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&x,&k);
        printf("%d\n",g(k,x));
    }
    return 0;
}