#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

#define IO ios::sync_with_stdio(false);\
    cin.tie(0);\
    cout.tie(0);

using namespace std;

const int maxn=(1<<16)+5;
int n;
queue <int> q;
pair<int,int> ans[maxn];
int degree[maxn],xor_sum[maxn];
int cnt;

void sovle(){
    cnt=0;
    while(!q.empty()){
        int from=q.front();
        q.pop();
        if(degree[from]==1){
            int to=xor_sum[from];
            ans[cnt].first=from;
            ans[cnt].second=to;
            cnt++;
            degree[to]--;
            xor_sum[to]^=from;
            if(degree[to]==1){
                q.push(to);
            }
        }
    }
}

void input(){
    while(!q.empty()){
        q.pop();
    }
    for(int i=0;i<n;i++){
        cin>>degree[i]>>xor_sum[i];
        if(degree[i]==1){
            q.push(i);
        }
    }
    sovle();
}

int main(int argc, char const *argv[])
{
    IO;
    while(cin>>n){
        input();
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
    }
    return 0;
}
