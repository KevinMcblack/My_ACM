/*
 * @Author: KevinMcblack 
 * @Date: 2019-01-18 14:34:16 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2019-01-18 20:15:48
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (((n * (n + 1)) / 2) & 1)
        {
            cout << -1 << endl;
            continue;
        }
        if (n & 1){
            if(s[0]=='1'){
                cout<<3;
            }else{
                cout<<1;
            }
            for(int i=1;i<n;i++){
                int tmp=i-1;
                if(tmp%4==0||tmp%4==3){
                    if(s[i]=='1'){
                        cout<<3;
                    }else{
                        cout<<1;
                    }
                }
                if(tmp%4==1||tmp%4==2){
                    if(s[i]=='1'){
                        cout<<4;
                    }else{
                        cout<<2;
                    }
                }
            }
        }else{
            for(int i=0;i<n;i++){
                if(i%4==0||i%4==3){
                    if(s[i]=='1'){
                        cout<<3;
                    }else{
                        cout<<1;
                    }
                }
                if(i%4==1||i%4==2){
                    if(s[i]=='1'){
                        cout<<4;
                    }else{
                        cout<<2;
                    }
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
