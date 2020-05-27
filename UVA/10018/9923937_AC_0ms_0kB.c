#include <stdio.h>
int main(int argc, char *argv[])
{
	unsigned long long int n,o,p[10000],sum,huiwen,temp,pp,oo;
	int number,i,j,bit,k,count;
	scanf("%d",&number);
	for(i=0;i<number;i++)
	{
		scanf("%lld",&n);
		o=n;
		count=0;
		do
		{ 
		bit=0;
		oo=o;
		while(o>0)
		{
			p[bit]=o%10;
			o=o/10;
			bit++;
		}
		k=1;
		sum=0;
		for(j=bit-1;j>=0;j--)
		{
			sum+=k*p[j];
			k=k*10;
		}
		huiwen=sum+oo;
		temp=huiwen;
		pp=0;
		while(temp)
		{
			pp=pp*10+temp%10;
			temp/=10;
		}
		o=huiwen;
		count++;
		if(pp==huiwen)
			printf("%d %lld\n",count,huiwen);
		}while(pp!=huiwen); 
	}
	return 0;
}