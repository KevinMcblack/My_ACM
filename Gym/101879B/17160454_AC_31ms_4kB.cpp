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
    int temp;
    int a[2005];
    while (cin >> n)
    {
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int i, j;
        for (i = 2; i <= n; i++)
        {
            if (n % i != 0)
                continue;
            m.clear();
            for (j = 0; j < n; j++)
            {
                m[a[j] % i]++;
                if (m[a[j] % i] > n / i)
                    break;
            }
            if (j == n)
                break;
        }
        if (i == n + 1)
            cout << -1 << endl;
        else
            cout << i << endl;
    }
    return 0;
}