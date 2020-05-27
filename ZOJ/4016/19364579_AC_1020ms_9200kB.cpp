#include <iostream>
#include <list>
#include <cstdio>
#include <algorithm>
using namespace std;
list<int> l[3*100005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<3*100005;i++) l[i].clear();
        int n,q;
        int op;
        scanf("%d%d",&n,&q);
        while (q--)
        {
            int s,v,t;
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d%d",&s,&v);
                l[s].push_back(v);
            }else if(op==2)
            {
                scanf("%d",&s);
                
                if(l[s].empty())
                {
                    printf("EMPTY\n");
                }else{
                    printf("%d\n",l[s].back());
                    l[s].pop_back();
                }
            }else if(op==3)
            {
                scanf("%d%d",&s,&t);
                l[s].splice(l[s].end(),l[t]);
            }
        }
        
    }
    return 0;
}