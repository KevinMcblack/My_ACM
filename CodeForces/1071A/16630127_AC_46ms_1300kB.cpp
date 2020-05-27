#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    long long a, b;
    
    while (cin >> a >> b)
    {
        vector <long long> A,B;
        long long sum=a+b;
        long long n=sqrt(2*sum);
        long long l=1;
        long long r=n;
        while(l<=r){
            int mid=(l+r)>>1;
            if((mid*(mid+1))>>1<=sum){
                n=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        while(n>0)
        {
            if(a>=n){
                A.push_back(n);
                a-=n;
                n--;
            }else{
                B.push_back(n);
                b-=n;
                n--;
            }
        }
        cout<<A.size()<<endl;
        for(int i=0;i<A.size();i++)
            cout<<A[i]<<" ";
        cout<<endl;
        cout<<B.size()<<endl;
        for(int i=0;i<B.size();i++)
            cout<<B[i]<<" ";
        cout<<endl;
    }
    return 0;
}
