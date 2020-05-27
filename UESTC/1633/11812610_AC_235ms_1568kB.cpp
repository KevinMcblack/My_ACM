#include <iostream> 
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 2e3 + 10;
const int INF = 1e9 + 7;
int n, a[MAXN];
int d[50005];
int vis[50005];
void dij(int w) {
    priority_queue<int, vector<int>, greater<int> > q;
    fill(d, d + w, INF);
    q.push(0);
    d[0] = 0;
    while(!q.empty()) {
        int now = q.top(); q.pop();
        if(vis[now % w]) continue;
        vis[now % w] = 1;
        for(int i = 0; i < n; i++) {
            int dist = now + a[i];
            if(dist < d[dist % w]) {
                d[dist % w] = dist;
                q.push(dist);
            }
        }
    }
}
int main() {
    scanf("%d", &n);
    int w = INF;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        w = min(w, a[i]);
    }
    dij(w);
    int q;
    scanf("%d", &q);
    while(q--) {
        int m;
        scanf("%d", &m);
        puts(m >= d[m % w] ? "YES" : "NO");
    }
    return 0;
}