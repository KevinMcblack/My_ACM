#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
	char a[4][20];
	int i,j,n,k,o,p,z,x,g;
	scanf("%d",&n);
 	for(k=0;k<n;k++)
 	{
		for(i=0;i<4;i++)
		{
			scanf("%s",&a[i]);
			for(j=0;j<8;j++)
 				{
				 	if(a[i][j]=='.')
				 		{
		 					o=i;
		 					p=j;
		 				}	
	 				if(a[i][j]=='*')
	 					{
					 		z=i;
					 		x=j;
					 	}
			 	}
		}	
		 	g=fabs(o-z+p-x);
		 	if(g%2==0)
		 		printf("Black win\n");
	 		else
	 			printf("Red win\n");
 	}
	return 0;
}