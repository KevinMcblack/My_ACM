#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n){
        vector<int>v;
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            v.push_back(temp);
        }
        int maxx=-1;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
          if(v[i]>maxx)
          {
              maxx=v[i];
              cnt++;
          }
        }
        if(n==1)
            cout<<1<<endl;
        else
            cout<<cnt<<endl;
    }
    return 0;
}
