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
    while (cin >> n)
    {
        long long l, r;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            long long sum;
            cin>>a>>b;
            if (a % 2 == 1 && b % 2 == 1)
            {
                sum = -1 * ((a + b) / 2);
            }
            else if (a % 2 == 1 && b % 2 == 0)
            {
                sum = (b - a + 1) / 2;
            }
            else if (a % 2 == 0 && b % 2 == 1)
            {
                sum = -1 * (b - a + 1) / 2;
            }
            else
            {
                sum = (a + b) / 2 ;
            }
            cout<<sum<<endl;
        }
    }

    return 0;
}