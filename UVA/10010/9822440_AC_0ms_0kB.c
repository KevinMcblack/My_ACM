#include <stdio.h>
#include <string.h>
int search(char a[][50], char word[], int row, int col, int m, int n, int len) /*二维数组转一维数组 b[][]->word[]*/
{
	int i, j, k;
	/*以从左到右 左上 右上 左下 右下排列 */
	for (i = row, k = 0; i >= 0 && k < len && a[i][col] == word[k]; --i, ++k) ;  /* up */  
    if (k == len) return 1;
	for (i = row, j = col, k = 0; i >= 0 && j >= 0 && k < len                    /* up-left */  
         && a[i][j] == word[k]; i--, j--, ++k) ;  
    if (k == len) return 1; 
	for (j = col, k = 0; j >= 0 && k < len && a[row][j] == word[k]; --j, ++k) ;  /* left */  
    if (k == len) return 1;  
    for (i = row, j = col, k = 0; i >= 0 && j < n && k < len                     /* up-right */  
         && a[i][j] == word[k]; i--, j++, ++k) ;  
    if (k == len) return 1;  
    for (j = col, k = 0; j < n  && k < len && a[row][j] == word[k]; ++j, ++k) ;  /* right */  
    if (k == len) return 1;  
    for (i = row, k = 0; i < m && k < len && a[i][col] == word[k]; ++i, ++k) ;   /* down */  
    if (k == len) return 1;  
    for (i = row, j = col, k = 0; i < m && j >= 0 && k < len   
         && a[i][j] == word[k]; i++, j--, ++k) ;                                 /* down-left */  
    if (k == len) return 1;  
    for (i = row, j = col, k = 0; i < m && j < n && k < len   
         && a[i][j] == word[k]; i++, j++, ++k) ;                                 /* down-right */  
    return k == len;   /*若一轮未找到则返回0*/ 
}
int main(int argc, char *argv[])
{
	int t,k,m,n,i,j,o,p;
	char a[50][50],b[20][50],c[50][50];
	char bb[20][50]; 
	scanf("%d",&t);
	while(t--)
	{
		int found[60]={0};
		scanf("%d%d",&m,&n);
		for(i=0;i<m;i++)
			scanf("%s",a[i]); 
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				{
					if(a[i][j]>='A'&&a[i][j]<='Z') 
						a[i][j]+=32; 
				}
		}
		
		/*for(i=0;i<m;i++)   a 行列互换 

			for(j=0;j<n;j++)
				c[j][i]=a[i][j];*/
						
		scanf("%d",&k);	
		for(i=0;i<k;i++)
			scanf("%s",&b[i]);
		for(i=0;i<k;i++)
			for(j=0;j<strlen(b[i]);j++)
			{
				if(b[i][j]>='A'&&b[i][j]<='Z') 
						b[i][j]+=32; 
			}
			
		/*for(i=0;i<k;i++)  b 反序 
			for(j=strlen(b[i])-1,o=0;j>=0,o<strlen(b[i]);j--,o++)
				bb[i][o]=b[i][j];*/
			
		for(i=0;i<k;i++)
		{	
			for (o = 0; o < m; ++o)  
                for (p = 0; p < n; ++p)  
                    if (!found[i] && search(a, b[i], o, p, m, n, strlen(b[i]))) 
					{  
                            printf("%d %d\n", o+1, p+1);  
                            found[i] = 1;
					}
			/*
				for(o=0;o<m;o++)
				{
					if(strstr(a[o],b[i])!=NULL)
						{
							printf("%d %d\n",o+1,strstr(a[o],b[i])-a[o]+1);
							break;
						}
					if(strstr(a[o],bb[i])!=NULL)
						{
							printf("%d %d\n",o+1,strstr(a[o],bb[i])-a[o]+strlen(bb[i]));
							break; 
						}
				}
			for(p=0;p<n;p++)
				{
					if(strstr(c[p],b[i])!=NULL)
						{
							printf("%d %d\n",strstr(c[p],b[i])-c[p]+1,p+1);
							break;
						}
					if(strstr(c[p],bb[i])!=NULL)
						{
							printf("%d %d\n",strstr(c[p],bb[i])-c[p]+strlen(bb[i]),p+1);
							break;
						}
				}*/
		
		}
		if(t)
			printf("\n");/*每两个测试之间留有空格 也就是最后的测试不会有空格*/ 
	}
	return 0;

}