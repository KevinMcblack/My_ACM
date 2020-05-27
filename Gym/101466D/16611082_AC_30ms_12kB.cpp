/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-23 20:10:08 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-23 20:13:17
 */
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;

    while (cin >> n)
    {
        string s = "";
        while (n)
        {
            if (n & 1)
            {
                n /= 2;
                s = 'A' + s;
            }
            else
            {
                n /= 2;
                n--;
                s = 'B' + s;
            }
        }
        cout << s << endl;
    }
    return 0;
}
