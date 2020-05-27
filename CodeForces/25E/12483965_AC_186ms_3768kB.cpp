#include <iostream> 
#include <string.h> 
#include <string> 
#include <algorithm> 
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
using namespace std;
#define MAX 100000 
int _next[3][MAX + 5];
string a[3];
int b[3][3];
int c[3];
void get_next(string P, int pos)
{
       int  j = -1, i = 0;
       int len = P.length();
       _next[pos][0] = -1;
       while (i < len)
       {
              if (j == -1 || P[i] == P[j])
              {
                     i++;
                     j++;
                     _next[pos][i] = j;
              }
              else
                     j = _next[pos][j];
       }
}
int kmp(string T, string P, int pos)
{
       int pLen = P.length();
       int tLen = T.length();
       int i = 0, j = 0;
       while (i<pLen&&j<tLen)
       {
              if (i == -1 || P[i] == T[j])
              {
                     i++, j++;//若是j与该字符串的长度相同 即没有与另一个字符串相包含
              }
              else
                     i = _next[pos][i];
       }
       //cout<<i<<endl; 
       //printf("%d\n", j);
       return i;
}
int main()
{
   while(cin>>a[0]>>a[1]>>a[2])
	   {
	   c[0] = a[0].length();
       c[1] = a[1].length();
       c[2] = a[2].length();
       memset(_next, 0, sizeof(_next));
       get_next(a[0], 0); get_next(a[1], 1); get_next(a[2], 2);
       for (int i = 0; i<3; i++)
              for (int j = 0; j<3; j++)
                     if (i != j)//为了区分与另外的字符串的联系 即0 与 1 2的差别
                           b[i][j] = kmp(a[i], a[j], j);
       int ans = 0;
       for (int i = 0; i<3; i++)
       {
              for (int j = 0; j<3; j++)
              {
                     if (i == j)
                           continue;
                     for (int k = 0; k<3; k++)
                     {
                           if (k == i || k == j)
                                  continue;
                           if (b[i][j] == c[j])
                                  ans = max(ans, b[i][j] + b[i][k]);
                           else
                                  ans = max(ans, b[i][j] + b[j][k]);
                     }
              }
       }
       printf("%d\n", c[0] + c[1] + c[2] - ans);
		} 
       return 0;
}
