#include<stdio.h>  
#include<string.h>  
#include<math.h>  
#define N 105  
double coord[N][2], w[N][N], minCost[N];  
int n, pre[N], hash[N];   
double getDist(double x1,double y1,double x2,double y2){  
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));   
}  
/*prim算法 */ 
double Prim(){  
	int i,j;
    memset(hash, 0, sizeof(hash));  
    hash[1] = 1;  
    for(i=1; i<=n; i++){  
        minCost[i] = w[1][i];  
        pre[i] = 1;  
    }  
    double sum=0;  
    for(i=1; i<n; i++){  
        int u=-1;  
        for(j=1; j<=n; j++)
			if(!hash[j])
			{  
	            if(u==-1||minCost[j]<minCost[u])  
	                u=j;  
        	}  
        sum += w[pre[u]][u];  
        hash[u] = 1;  
        for(j=1; j<=n; j++)
			if(!hash[j])
			{  
	            if(minCost[j]>w[u][j]){  
	                minCost[j] = w[u][j];  
	                pre[j] = u;  
            }  
        }  
    }  
    return sum;  
}  
int main(){ 
    int T,i,j;  
    scanf("%d",&T);  
    while(T--){  
        scanf("%d",&n);  
        for(i=1; i<=n; i++)  
            scanf("%lf%lf",&coord[i][0],&coord[i][1]);  
        memset(w, 0, sizeof(w));  
        for(i=1; i<=n; i++)  
            for(j=1; j<=n; j++)
				if(i!=j)  
                	w[i][j] = getDist(coord[i][0],coord[i][1],coord[j][0],coord[j][1]);  
        printf("%.2f\n", Prim());  
        if(T)
			printf("\n");  
    }   
    return 0;  
} 