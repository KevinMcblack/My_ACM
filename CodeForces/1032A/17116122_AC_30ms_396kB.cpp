/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-18 18:38:49 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-11-21 18:40:34
 */
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
    while(cin>>n>>k){
        map<int,int> m;
        int maxx=-1;
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            m[temp]++;
            maxx=max(maxx,m[temp]);
        }
        int cnt=ceil((double)maxx/(double)k);
        int size=m.size();
        cout<<k*size*cnt-n<<endl;
    }
	return 0;
}