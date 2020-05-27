#include <stdio.h>
void exchage(int a[],int i,int j)
{  
	int temp;
    while(i<j)
	{  
        temp=a[i];  
        a[i]=a[j];  
        a[j]=temp;  
        i++;  
        j--;  
    }  
}
int main(int argc, char *argv[])
{
	int a[35],b[35];
	int i=0,count,j,temp;
	while(scanf("%d",&a[0])!=EOF)
	{
		count=1;
		if(getchar()!='\n')
			while(scanf("%d",&a[count++]))  
                if(getchar()=='\n') 
					break;
		for (i=0;i<count;i++)
		{  
            b[i]=a[i];  
            printf("%d ",a[i]);  
        }  
        printf("\n"); 
        for(i=0;i<count;i++)
        	for(j=0;j<count-1;j++)
        		if(b[j]>b[j+1])
        		{
		        	temp=b[j];
		        	b[j]=b[j+1];
		        	b[j+1]=temp;
		        }
        for(i=count-1;i>0;i--)
        {
        	if(a[i]==b[i])
        		continue;
       		for(j=i-1;j>=0;j--)
       		{
		    	if(b[i]==a[j])
				{
					if(j==0)
					{
						printf("%d ",count-i);
						exchage(a,0,i);
					}
					else
					{
						printf("%d ",count-j);  
                        exchage(a,0,j);
                        printf("%d ",count-i);  
                       	exchage(a,0,i);
					}	
				}  	
	       	}	
        }
        printf("0\n");	
	}
	return 0;
}