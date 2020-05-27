#include <iostream>
using namespace std;
long long big[15];
void getEdge()
{
    long long num=1;
    for(int i=0;i<=11;i++)
    {
        num=num*10;
        big[i]=num-1;
    }
}
int main(int argc, char const *argv[])
{
    long long n;
    long long a;
    long long b;
    getEdge();
    while(cin>>n)
    {
        long long temp=n;
        int len=0;
        while(temp)
        {
            temp/=10;
            len++;
        }
        //cout<<len<<endl;
        a=big[len-2];
        b=n-a;
        int sum=0;
         while(a)
        {
            sum+=(a%10);
            a/=10;
        }
        while(b)
        {
            sum+=(b%10);
            b/=10;
        }
        cout<<sum<<endl;
    }
    return 0;
}
