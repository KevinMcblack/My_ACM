/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-23 20:15:17 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-23 20:38:37
 */
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        int len = 2 * n + 1;
        for (int i = 0; i < n; i++)
        {

            if (i == 0)
            {
                cout << "*";
                for (int j = 0; j < n - 2; j++)
                    cout << " ";
                cout << "* ";
                for (int j = 0; j < len / 2; j++)
                    cout << "*";
            }else if(i!=0&&i!=n-1){
                cout << "*";
                for (int j = 0; j < n - 2; j++)
                    cout << " ";
                cout << "* ";
                cout << "*";
                for (int j = 0; j < n - 2; j++)
                    cout << " ";
                cout<<"*";
            }else{
                for (int j = 0; j < len / 2; j++)
                    cout << "*";
                cout<<" ";
                cout << "*";
                for (int j = 0; j < n - 2; j++)
                    cout << " ";
                cout<<"*";
            }
            cout << endl;
        }
    }
    return 0;
}
