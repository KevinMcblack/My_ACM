#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int lowbit(int i)
{
    return i & (-i);
}
int main()
{
    int t;
    int n;
    cin>>t;
    while (t--)
    {
        cin >> n;
        cout << n - lowbit(n) + 1 << " " << n + lowbit(n) - 1 << endl;
    }
    return 0;
}
