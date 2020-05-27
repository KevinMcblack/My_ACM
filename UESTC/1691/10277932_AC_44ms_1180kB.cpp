/** 
*  多重背包模板： 
*          有N种物品和一个容量为V的背包。第i种物品最多有Mi件可用， 
*          每件耗费的空间是Ci，价值是Wi。 
*          求解将哪些物品装入背包可使这些物品的耗费的空间总和不超过背包容量，且价值总和最大。 
*/  
#include <stdio.h>  
#include <string.h>  
int max(int a, int b)
{  
    if (a > b)return a;  
    return b;  
}  
#define maxn 100005  
int c[maxn], w[maxn], num[maxn];//c:费用 w:价值 num:数量  
int dp[maxn];             
int V;               //V:容量 V1:容量2  
  
//01背包  
void ZeroOnePack(int c, int w)  
{  
    for (int v = V; v >= c; v--)  
    {  
        dp[v] = max(dp[v], dp[v - c] + w);  
    }  
}  
//完全背包  
void CompletePack(int c, int w)  
{  
    for (int v = c; v <= V; v++)  
    {  
        dp[v] = max(dp[v], dp[v - c] + w);  
    }  
}  
//多重背包  
void MultiplePack(int c, int w, int num)  
{  
//如果总容量比这个物品的容量要小，那么这个物品可以直接取完，相当于完全背包
    if (c * num >= V)  
    {  
        CompletePack(c, w);  
    }  
    else  //否则就将多重背包转化为01背包
    {  
        int k = 1;  
        while (k < num)  
        {  
            ZeroOnePack(k*c, k*w);  
            num -= k;  
            k <<= 1;  
        }  
        ZeroOnePack(num*c, num*w);  
    }  
}  
int main()  
{  
    int t;  
    //scanf("%d", &t);  
   // while (t--)  
//    {  
        int n;  
        scanf("%d%d",&n,&V);  
        for (int i = 1; i <= n; i++)  
            scanf("%d%d%d", &c[i], &w[i], &num[i]);  
        memset(dp, 0, sizeof(dp));  
        for (int i = 1; i <= n; i++)  
            MultiplePack(c[i], w[i], num[i]);  
        printf("%d\n", dp[V]);  
    //}  
    return 0;  
}  