#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
const int N = 220005;  
char str[N];  
int p[N];  
  
void manacher(char *s, int len)  
{  
    p[0] = 1;  
    int mmax = 0, id = 0;  
    for(int i = 1; i < len; i++) {  
        p[i] = mmax > i ? min(p[id*2-i], mmax - i) : 1;  
        while(s[i+p[i]] == s[i-p[i]]) p[i]++;  
        if(i + p[i] > id + p[id]) {  
            id = i;  
            mmax = i + p[i];  
        }  
    }  
}  
  
int main()  
{  
    while(~scanf("%s",str)) {  
        int len = strlen(str);  
        for(int i = len; i >= 0; i--) {  
            str[(i<<1) + 1] = '#';  
            str[(i<<1) + 2] = str[i];  
        }  
        str[0] = '*'; //防止数组越界  
        len = len * 2 + 2;  
        manacher(str, len);  
        int ans = 0;  
        for(int i = 0; i < len; i++)  
            ans = max(ans, p[i]-1);  
        printf("%d\n", ans);  
    }  
    return 0;  
}