#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
map<int,int> m;
int main()
{
    int n;

    while(~scanf("%d",&n))
    {
        m.clear();
        int temp;
        int maxx=-1;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            m[temp]++;
            maxx=max(maxx,m[temp]);
        }
        printf("%d\n",maxx);
    }
    return 0;
}