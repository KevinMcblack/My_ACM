#include <iostream>
#include <map>
using namespace std;

map<long long,int> m;
int main()
{   
    int n;
    while(cin>>n)
    {
        m.clear();
        char c;
        long long num;
        for(int i=0;i<n;i++)
        {
            cin>>c>>num;
            long long temp=1;
            long long res=0;
            while(num)
            {
                res+=(num%10%2)*temp;
                temp*=10;
                num/=10;
            }
            if(c=='+')
            {
                m[res]++;
            }else if(c=='-')
            {
                m[res]--;
            }else{
                cout<<m[res]<<endl;
            }
        }
    }
    return 0;
}