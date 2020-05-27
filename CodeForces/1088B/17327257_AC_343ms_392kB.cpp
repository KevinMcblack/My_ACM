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
const int maxn = 1e5 + 5;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    int a[maxn];
    while (cin >> n >> k)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int count = 0;
        int i = 1;
        cout<<a[0]<<endl;
        for (int j = 1; j < k; j++)
        {
            for (; i < n; i++)
            {
                if (a[i] == a[i - 1])
                {
                    continue;
                }
                else
                {
                    j++;
                    cout << a[i] - a[i - 1] << endl;
                    if (j == k)
                    {
                        break;
                    }
                }
            }
            if(i==n){
                cout<<0<<endl;
            }
        }
    }
    return 0;
}