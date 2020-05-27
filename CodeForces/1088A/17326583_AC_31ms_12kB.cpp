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
    int x;
    while (cin >> x)
    {
        int a=1,b=1;
        for(;b<=x;b++){
            for(a=b;a<=x;a+=b){
                if((a*1.0/b*1.0)<(x*1.0)&&a*b>x){
                    cout<<a<<" "<<b<<endl;
                    return 0;
                }
            }
        }
        cout<<-1<<endl;
    }

    return 0;
}