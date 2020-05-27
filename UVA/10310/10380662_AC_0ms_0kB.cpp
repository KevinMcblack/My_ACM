#include <stdio.h>
#include <math.h>
struct escape{
	double hole_x;
	double hole_y;
}count[1050];
int main(int argc, char *argv[])
{
	int n,i,k=0,j;
	struct escape temp;
	double gopher_x,gopher_y,dog_x,dog_y,dis1,dis2,zuobiao_x,zuobiao_y;
	while(scanf("%d",&n)!=EOF)
	{
	k=0;
	scanf("%lf%lf%lf%lf",&gopher_x,&gopher_y,&dog_x,&dog_y);
	for(i=0;i<n;i++)
		scanf("%lf%lf",&count[i].hole_x,&count[i].hole_y);
//	for(i=0;i<n;i++)
//		for(j=0;j<n-1;j++)
//		{
//			if(pow(gopher_x-count[j].hole_x,2)+pow(gopher_y-count[j].hole_y,2)>pow(gopher_x-count[j+1].hole_x,2)+pow(gopher_y-count[j+1].hole_y,2))
//			{
//				temp=count[j];
//				count[j]=count[j+1];
//				count[j+1]=temp;
//			}
//		}
	for(i=0;i<n;i++)
		{
			dis1=pow(dog_x-count[i].hole_x,2)+pow(dog_y-count[i].hole_y,2);
			dis2=pow(gopher_x-count[i].hole_x,2)+pow(gopher_y-count[i].hole_y,2);
			if(4.0*dis2>dis1)
			{
				k=1;
			}	
			else
			{
				k=0;
				zuobiao_x=count[i].hole_x;
				zuobiao_y=count[i].hole_y;
				break;
			}	
		}
	if(k==0)
		printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",zuobiao_x,zuobiao_y);
	else
		printf("The gopher cannot escape.\n");	
	}
	return 0;
}