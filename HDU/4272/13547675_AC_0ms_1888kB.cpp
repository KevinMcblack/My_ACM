#include <iostream>  
#include <cstdio>  
#include <map>  
#include <cstring>  
  
using namespace std;  
  
map<int ,int> m;  
int a[1100];  
int vis[1100];  
  
int dfs(int n)  
{  
      while(n && vis[n])  
            n--;  
      if(n <= 0)  
            return 1;  
      if(n == 1)  
            return 0;  
      int i=0, j = n-1;  
      for(;i<=5;)  
      {  
            if(j <= 0)  
                  return 0;  
            if(vis[j]){  
                  j--;  
                  continue;  
            }  
            if(a[n] == a[j])  
            {  
                  vis[j] = 1;  
                  if(dfs(n-1))  
                        return 1;  
                  vis[j] = 0;  
            }  
            i++;  
            j--;  
      }  
      return 0;  
}  
  
int main()  
{  
      int n;  
      while(scanf("%d",&n)!=EOF)  
      {  
            m.clear();  
            memset(vis,0,sizeof(vis));  
            for(int i=1;i<=n;i++)  
            {  
                  scanf("%d",&a[i]);  
                  vis[i] = 0;  
                  m[a[i]]++;  
            }  
            if(n & 1)  
            {  
                  printf("0\n");  
                  continue;  
            }  
            int flag = 1;  
            map<int ,int>::iterator it;  
            for(it = m.begin();it != m.end();it++)  
            {  
                  if(it->second % 2==1)  
                  {  
                        flag = 0;  
                        break;  
                  }  
            }  
            if(flag == 0){  
                  printf("0\n");  
                  continue;  
            }  
            printf("%d\n",dfs(n));  
      }  
      return 0;  
}