/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-18 18:38:49 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-18 19:28:45
 */
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <deque>
using namespace std;
const int maxn=2e5+50;
int a[maxn],b[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
    char c;
    int number;
    cin>>t;
    int l=0,r=0;
    while(t--){
        cin>>c>>number;
        if(c=='L')
            a[number]=++l;
        else if(c=='R')
            b[number]=++r;
        else{
            if(a[number])
            {
                cout<<min(l-a[number],r+a[number]-1)<<endl;
            }else{
                cout<<min(r-b[number],l+b[number]-1)<<endl;
            }
        }
    }
    
	return 0;
}