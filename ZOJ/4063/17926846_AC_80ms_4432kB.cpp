#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 5;
typedef long long ll;
#define INF 0x3f3f3f3f

int a[1030][1030];

void init(){
    for(int i=1;i<=1024;i++){
        a[1][i]=i;
    }
    for(int i=2;i<=1024;i*=2){
        int tmp=i/2;
        for(int j=tmp+1;j<=i;j++){
            for(int k=1;k<=1024;k++){
                if(((k-1)/tmp)%2!=0){
                    a[j][k]=a[j-tmp][k-tmp];
                }else{
                    a[j][k]=a[j-tmp][k+tmp];
                }
            }
        }
    }
}

int main()
{
    init();
    int t;
    scanf("%d",&t);
    int n,k;
    while(t--){
        scanf("%d%d",&n,&k);
        if(k>=(n&-n)){
            printf("Impossible\n");
            continue;
        }
        for(int i=2;i<=k+1;i++){
            printf("%d",a[i][1]);
            for(int j=2;j<=n;j++){
                printf(" %d",a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}