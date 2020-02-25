/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-18 18:38:49 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-11-21 19:32:47
 */
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
    while(cin>>s){
        int len=s.size();
        int a=ceil((double)len/20*1.0);
        int b=ceil((double)len/a*1.0);
        int p=a*b-len;
        cout<<a<<" "<<b<<endl;
        int q=0;
        for(int i=0;i<a;i++){
            if(p>0){
                p--;
                cout<<"*";
                for(int j=0;j<b-1;j++){
                    cout<<s[q++];
                }
            }else{
                for(int j=0;j<b;j++){
                    cout<<s[q++];
                }
            }
            cout<<endl;
        }
        
    }
	return 0;
}