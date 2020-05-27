/*
 * @Author: KevinMcblack 
 * @Date: 2019-01-17 10:49:26 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2019-01-17 14:11:11
 */
#include <iostream>
#include <algorithm>
using namespace std;

int m,n;
int a[105][105];
int b[105][105];
int c[105][105];

bool judge(){

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(b[i][j]==0){
                for(int k=0;k<m;k++){
                    a[k][j]=0;
                }
                for(int k=0;k<n;k++){
                    a[i][k]=0;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1){
                for(int k=0;k<m;k++){
                    c[k][j]=1;
                }
                for(int k=0;k<n;k++){
                    c[i][k]=1;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(b[i][j]!=c[i][j]){
                return false;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<m;i++){
        cout<<a[i][0];
        for(int j=1;j<n;j++){
            cout<<" "<<a[i][j];
        }
        cout<<endl;
    }
    return true;

}

int main(int argc, char const *argv[])
{  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            a[i][j]=1;
            cin>>b[i][j];
        }
    }
    if(!judge()){
        cout<<"NO"<<endl;
    }
    return 0;
}
