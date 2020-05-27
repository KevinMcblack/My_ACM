#include <stdio.h>
int main(int argc, char *argv[])
{
	int m,i,k;
	double a[1100],sum,ave,sum1,ave1,ave2,b,c;
	while(scanf("%d",&m),m>0)
	{
		sum=0;	
		for(i=0;i<m;i++)
		{
			scanf("%lf",&a[i]);
			sum+=a[i];
		}
		ave=sum/m;
		ave2=ave1=ave;
		/*k=(int)(ave1*1000)%10;
		if(k!=0)
			ave2=(ave2*1000-k+10)/1000;
		else
			ave2=(ave2*1000-k)/1000;*/
		ave2=((int)((ave2+0.005)*100))/100.0;  
		b=c=0;
		for(i=0;i<m;i++)
		{
			if(a[i]>ave)
				b+=(a[i]-ave2);
			else
				c+=(ave2-a[i]);
		}
		printf("$%.2lf\n",b>c? c:b);	
	}
	return 0;
}