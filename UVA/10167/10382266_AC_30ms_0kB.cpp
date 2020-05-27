#include <stdio.h>
struct carry{
	int x;
	int y;
}point[150];
int main(int argc, char *argv[])
{
	int n;
	int i,j,a,b,num=0;
	while(scanf("%d",&n)!=EOF&&n)
	{
		j=0;
		for(i=0;i<2*n;i++)
			scanf("%d%d",&point[i].x,&point[i].y);
		for(a=-500;a<=500;a++)
		{
			for(b=-500;b<=500;b++)
			{
				num=0;
				for(i=0;i<2*n;i++)
				{
					if((a*point[i].x+b*point[i].y)>0)
						num++;
					if((a*point[i].x+b*point[i].y)==0)
						break;
				}
				if(num==n&&i==2*n)
				{
					j=1;
					break;
				}	
			}
			if(j==1)
				break;
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}