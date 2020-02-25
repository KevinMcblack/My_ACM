/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-11 16:28:11 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-13 16:20:29
 */
//二分图的最大团=补图的最大独立集=补图的顶点数-补图的最大匹配
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int map[450][450];
int pre[450];
bool use[450];
int p,n;
//最大匹配用匈牙利算法求
int dfs(int u)//u为当前正在匹配的左边元素
{
	for(int i=1;i<=p;i++)
	{
		if(!use[i]&&map[u][i]==0)
		{
			use[i]=true;//标记已经访问过了
			if(pre[i]==0||dfs(pre[i]))
			{
				pre[i]=u;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{   
	int t;
	int a,b;
	cin>>t;
	while(t--)
	{
		cin>>p>>n;
		memset(map,0,sizeof(map));//初始化地图为0 
		memset(pre,0,sizeof(pre));//初始化为和每个点连接的点都是0 
		while(n--)
		{
			cin>>a>>b;
			map[a][b]=1;
		}
		int cnt=0;
		for(int i=1;i<=p;i++)
		{
			memset(use,false,sizeof(use));//每次搜索前都要清空标记
			if(dfs(i)){
				cnt++;//寻找增广路，如果找到，配对数加一
			}
		}
		cout<<2*p-cnt<<endl;
	}
	return 0;
}