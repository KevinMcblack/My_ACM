#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

const int maxn = 200 + 10;
int tot;
int n,m;
int C[maxn],res[92][8],cnt=0;

void search(int cur){
    if(cur==8){
        // for(int i=0;i<8;i++){
        //     cout<<C[i]+1<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<8;i++){
            res[cnt][i]=C[i]+1;
        }
        cnt++;
    }else{
        for(int i=0;i<8;i++){
            int ok=1;
            C[cur]=i;
            for(int j=0;j<cur;j++){
                if(C[cur]==C[j]||C[cur]+cur==C[j]+j||cur-C[cur]==j-C[j]){
                    ok=0;break;
                }
            }
            if(ok){
                search(cur+1);
            }
        }
    }
}

int main(int argc, char const *argv[])
{ 
    memset(C,0,sizeof(C));
    search(0);
    int t;
    cin>>t;
    int x,y;
    while (t--)
    {
        cin>>x>>y;
        printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
        int count=1;
        for(int i=0;i<92;i++){
            if(res[i][y-1]==x){
                printf("%2d     ",count ++);
                for(int j=0;j<8;j++){
                    cout<<" "<<res[i][j];
                }
                cout<<endl;
            }
        }
        if (t) printf("\n");
    }
    return 0;
}
