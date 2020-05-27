#include <stdio.h>
#include <iostream>
#include<algorithm>
#include <string.h>
using namespace std;
typedef long long ll;
int main()
{
       char a[20], b[20], c[20];
       while (cin >> a >> b)
       {
              sort(a, a + strlen(a));
              if (strlen(a) < strlen(b))
              {
                     for (int i = strlen(a) - 1; i >= 0; i--)
                           cout << a[i];
                     cout << endl;
                     continue;
              }
              strcpy(c, a);
              for (int i = 0; i < strlen(a); i++)
              {
                     strcpy(a, c);
                     for (int j = i; j < strlen(a); j++)
                     {
                           swap(a[i], a[j]);//从小到大排完序后 每次与第i个数字交换
                           if (strcmp(a, b) <= 0)//如果a<=b的话 把每次a的变化都给c 因为c保留了a的值 当a的变化比b大的时候
                                  strcpy(c, a);//（因为忽略掉了比b大的数，这样比到最后能够找到不大于b的a的最大可能排列数）
                     }
              }
              cout << a;
              cout << endl;
       }
       return 0;
}