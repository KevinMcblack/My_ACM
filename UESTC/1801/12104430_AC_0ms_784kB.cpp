#include <stdio.h>
int main(int argc, char *argv[])
{
	int hh,m; 
	scanf("%d:%d",&hh,&m);
	int h=hh;
	if(h==23&&m>32)
	{
		printf("%d\n",60-m);
	}
	else
	{
		int k=0;
		if(h<10)
			k=10*h;
		else
		{
			while(h)
			{
				k=k*10+h%10;
				h/=10;
			}
		}
		//printf("%d\n",k);
		if(hh>=16&&hh<=19||(hh==15&&m>51))
		{
			printf("%d\n",(20-hh-1)*60+2+60-m);
		}
		else if(hh>=6&&hh<=9||(hh==5&&m>50))
		{
			printf("%d\n",(10-hh-1)*60+1+60-m);
		}
		else
		{
			if(k-m>=0) 
				printf("%d\n",k-m);
			else
			{
				k+=10;
				printf("%d\n",k+60-m);	
			}	
		}
		
	}
	return 0;
}