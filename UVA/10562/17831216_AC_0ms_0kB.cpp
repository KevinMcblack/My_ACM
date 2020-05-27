#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

const int maxn=200+10;
char buf[maxn][maxn];
int n;

void dfs(int x,int y){
    cout<<buf[x][y]<<'(';
    if(x<n-1&&buf[x+1][y]=='|'){
        int i=y;
        while(buf[x+2][i-1]=='-'&&i-1>=0){
            i--;
        }
        while(buf[x+2][i]=='-'&&buf[x+3][i]!='\0'){
            if(!isspace(buf[x+3][i])){
                dfs(x+3,i);
            }
            i++;
        }
    }
    cout<<')';
}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    getchar();
    while(t--){
        n=0;
        while(1){
            gets(buf[n]);
            if(buf[n][0]=='#'){
                break;
            }
            n++;
        }
        cout<<'(';
        if(n)
	    {
        for(int i=0;i<strlen(buf[0]);i++){
            if(buf[0][i]!=' '){
                dfs(0,i);
                break;
            }
        }
        }
        cout<<')'<<endl;
    }
    return 0;
}
