#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin>>t;
    string a,b;
    while (t--)
    {
        cin>>a>>b;
        b[0]-=32;
        cout<<b+a<<endl;
    }
    
    return 0;
}