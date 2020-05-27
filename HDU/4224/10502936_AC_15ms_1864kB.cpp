#include <stdio.h>
int main(int argc, char *argv[])
{
	int t,k,o,p,casee=0;
	scanf("%d",&t);
	while(t--)
	{
		int up1,up2,up3,down1,down2,down3;
		scanf("%d%d%d%d%d%d",&up1,&down1,&up2,&down2,&up3,&down3);
		if(up1>down1)
			k=1;
		else if(up1==down1)
			k=0;
		else if(up1<down1)
			k=-1;
		if(up2>down2)
			o=1;
		else if(up2==down2)
			o=0;
		else if(up2<down2)
			o=-1;
		if(up3>down3)
			p=1;
		else if(up3==down3)
			p=0;
		else if(up3<down3)
			p=-1;
		if( ((k+o+p)==3)||((k+o+p)==-3)||((k*o*p==0)&&((k+o+p==1)||(k+o+p==-1)))||(k+o+p==2)||(k+o+p)==-2)  
            printf("Case %d: No\n",++casee);  
        else  
            printf("Case %d: Yes\n",++casee); 
		//if(k==o&&o==p&&p!=0)
//			printf("Case %d: NO\n",++casee);
//		else if(k==o&&o!=p&&k==1||k==-1&&p!=0)
//			printf("Case %d: YES\n",++casee);
//		else if(k==p&&p!=o&&k==1||k==-1&&p!=0)
//			printf("Case %d: YES\n",++casee);
//		else if(o==p&&k!=o&&o==1&&o==-1&&p!=0)
//			printf("Case %d: YES\n",++casee);
//		else if(k==p&&p==o&&p==0)
//			printf("Case %d: YES\n",++casee);
//		else
//			printf("Case %d: NO\n",++casee);	
	}
	return 0;
}