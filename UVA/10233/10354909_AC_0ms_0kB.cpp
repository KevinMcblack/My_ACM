#include <stdio.h>  
#include <math.h>  
 
struct point  
{  
    double x,y;  
};  
//将（0，0）位置作为原点 作中垂线 来确立坐标系  
struct point getpoint(int n)  
{  
    int i;  
    long long t,t1;  
    struct point pos;  
    t=sqrt(n);          //t表示该数字所在的行
    pos.y=t*sqrt(3)/2;  
    if((t+n)%2==1)              //如果是倒三角，就进行处理 
        pos.y=pos.y-sqrt(3)/6;  
        //到这里已经算出y坐标相对于编号0的相对距离 
    t++;			//这里计算的是该数字所在行数的下一行，
    t=t*t;          //最左边的数，便于求位于当前行最中间的那个值，利用它来求出该行相对于编号0三角形x坐标的距离  
    t1=0;  
    for(i=1;t>=t1+2*i;i++)  
        t1=t1+2*i;  //t1=2 i=2 t1=6 i=3 
		//n=4 4-6=-2 n=5 5-6=-1 
    pos.x=(n-t1)*0.5;       //计算在x轴上与编号0三角形的相对位置
    return pos;  
}  
double dis(struct point a,struct point b)  
{  
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));  
	//那么也就是相当于转化成计算坐标之间距离了 
}  
int main()  
{  
    int n,m;  
    while(scanf("%d %d",&n,&m)!=EOF)  
    {  
        printf("%.3lf\n",dis(getpoint(n),getpoint(m)));  
    }  
    return 0;  
}