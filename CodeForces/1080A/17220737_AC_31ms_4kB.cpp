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
	int n,k;
    int r,g,b;
    while(cin>>n>>k){
        r=n*2;
        g=n*5;
        b=n*8;
        int sum=0;
        sum+=ceil((double)r/k*1.0);
        sum+=ceil((double)g/k*1.0);
        sum+=ceil((double)b/k*1.0);
        cout<<sum<<endl;
    }
    
	return 0;
}