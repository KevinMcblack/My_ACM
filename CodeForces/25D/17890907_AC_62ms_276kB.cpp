#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
using namespace std;
const int maxn = 1e3 + 5;

#define INF 0x3f3f3f3f
typedef pair<int,int> P;
int n;
int father[maxn];
vector<P> p;
vector<int> q;

void init()
{
    int i;
    for (int i = 1; i <= n; i++)
        father[i] = i;
}
int find(int p)
{
    if (father[p] == p)
        return p;
    return father[p] = find(father[p]);
}
int unite(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x != y)
    {
        father[y] = x;
        return 1;
    }
    return 0;
}
int main()
{
        cin>>n;
        init();
        int a,b;
        for(int i=1;i<n;i++){
            cin>>a>>b;
            if(!unite(a,b)){
                p.push_back(make_pair(a,b));
            }
        }
        for(int i=1;i<=n;i++){
            if(find(i)==i){
                q.push_back(i);
            }
        }
        cout<<q.size()-1<<endl;
        for(int i=1;i<q.size();i++){
            cout<<p[i-1].first<<" "<<p[i-1].second<<" "<<q[i-1]<<" "<<q[i]<<endl;
        }
    
    return 0;
}