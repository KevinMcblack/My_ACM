#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int w1,h1,w2,h2;
    while(cin>>w1>>h1>>w2>>h2)
    {
        cout<<2*(h1+h2)+2*max(w1,w2)+4<<endl;
    }
    return 0;
}