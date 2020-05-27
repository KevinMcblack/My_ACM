#include <stdio.h>
int main(int argc, char *argv[])
{
	int m,mm,n,l,p;
	int count,a[10001],max,temp;
	while(scanf("%d%d",&m,&n)!=EOF) 
	{	
		max=0;
		if(m>n)
		{
			for(l=n;l<=m;l++)
			{
				p=l;
				count=1;
				while(p!=1)
				{
					if(p%2==0)
						p=p/2;
					else 
						p=3*p+1;
					count++;	
				}
				a[l]=count;
				if(max<a[l])
					max=a[l];
			}
			printf("%d %d %d\n",m,n,max);		
		}
		if(m==n)
		{
			mm=m;
			count=1;
			while(mm!=1)
			{
				if(mm%2==0)
					mm=mm/2;
				else 
					mm=3*mm+1;
				count++;	
			}
			max=count;
			printf("%d %d %d\n",m,n,max);
		}
		if(m<n)
		{
		for(l=m;l<=n;l++)
			{
				p=l;
				count=1;
				while(p!=1)
				{
					if(p%2==0)
						p=p/2;
					else 
						p=3*p+1;
					count++;	
				}
				a[l]=count;
				if(max<a[l])
					max=a[l];
			}
			printf("%d %d %d\n",m,n,max);		
		}	
	}
	return 0;
}