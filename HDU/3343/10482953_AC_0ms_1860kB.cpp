#include<stdio.h>
int main()
{
  int t,l,v,m;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d%d",&l,&v,&m);
    if (v>0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}