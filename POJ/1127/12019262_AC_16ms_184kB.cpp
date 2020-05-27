#include <cstdio>  
#include <cstring>  
#include <cmath>  
using namespace std;  
double EPS = 1e-10;  
  
//考虑误差的加法运算  
double add(double a, double b)  
{  
    if (abs(a + b) < EPS * (abs(a) + abs(b)))  
        return 0;  
    return a + b;  
}  
  
//二维向量结构体  
struct P  
{  
    double x, y;  
    P(){}  
    P(double x, double y) : x(x), y(y){}  
    P operator + (P p){  
        return P(add(x, p.x), add(y, p.y));  
    }  
    P operator - (P p){  
        return P(add(x, -p.x), add(y, -p.y));  
    }  
    P operator * (double d){  
        return P(x * d, y * d);  
    }  
    double dot(P p){    //内积  
        return add(x * p.x, y * p.y);  
    }  
    double det(P p){    //外积  
        return add(x * p.y, -y * p.x);  
    }  
};  
  
//判断dianq是否在线段p1-p2上  
bool on_seg(P p1, P p2, P q)  
{  
    return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;  
}  
  
//计算直线p1-p2与直线q1-q2的交点  
P intersection(P p1, P p2, P q1, P q2)  
{  
    return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));  
}  
  
//输入  
int n;  
P p[15], q[15];  
int m;  
int a, b;  
bool g[15][15];    //相连关系图  
  
void solve()  
{  
    memset(g, false, sizeof(g));  
    for (int i = 0; i < n; i++){  
        g[i][i] = true;  
        for (int j = 0; j < i; j++){  
            //判断木棍i和木棍j是否有公共点  
            if ((p[i] - q[i]).det(p[j] - q[j]) == 0){  
                //平行时  
                g[i][j] = g[j][i] = on_seg(p[i], q[i], p[j])  
                                 || on_seg(p[i], q[i], q[j])  
                                 || on_seg(p[j], q[j], p[i])  
                                 || on_seg(p[j], q[j], q[i]);  
            }  
            else{  
                //非平行时  
                P r = intersection(p[i], q[i], p[j], q[j]);  
                g[i][j] = g[j][i] = on_seg(p[i], q[i], r) && on_seg(p[j], q[j], r);  
            }  
        }  
    }  
    //通过Floyd-Warshall算法判断任意两点间是否相连  
    for (int k = 0; k < n; k++){  
        for (int i = 0; i < n; i++){  
            for (int j = 0; j < n; j++){  
                g[i][j] |= g[i][k] && g[k][j];  
            }  
        }  
    }  
    while (scanf("%d%d", &a, &b) != EOF){  
        if (a == 0 && b == 0){  
            break;  
        }  
        puts(g[a - 1][b - 1] ? "CONNECTED" : "NOT CONNECTED");  
    }  
}  
  
int main()  
{  
    while (scanf("%d", &n), n){  
        for (int i = 0; i < n; i++){  
            scanf("%lf%lf%lf%lf", &p[i].x, &p[i].y, &q[i].x, &q[i].y);  
        }  
        solve();  
    }  
    return 0;  
} 