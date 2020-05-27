#include <stdio.h>
struct shoe
{
	int num;
	int day;
	int money;
	double rent;
}a[1005];
int main(int argc, char *argv[])
{
	int t,number,i,j;
	struct shoe temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&number);
		for(i=0;i<number;i++)
		{	
			a[i].num=i+1;
			scanf("%d%d",&a[i].day,&a[i].money);
			a[i].rent=(double)a[i].money/a[i].day;
		}
		for(i=0;i<number;i++)
			for(j=0;j<number-1;j++)
			{
				if(a[j].rent<a[j+1].rent)
				{
					temp=a[j+1];
					a[j+1]=a[j];
					a[j]=temp;
				}
			}
		printf("%d",a[0].num);
		for(i=1;i<number;i++)
			printf(" %d",a[i].num);
		if(t)
			printf("\n");
		printf("\n");
	} 
	return 0;
}