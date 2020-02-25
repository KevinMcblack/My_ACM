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
	int n;
    long long a[100]; 
    a[1]=0;
    a[2]=1;
    a[3]=4;
    a[4]=11;
    for(int i=5;i<=30;i++){
        a[i]=i-1+2+(i-2)*3+i-1+i+1;
        //cout<<a[i]<<endl;
    }
    while(cin>>n){
        cout<<a[n]<<endl;
    }
	return 0;
}