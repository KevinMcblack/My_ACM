/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-17 19:02:07 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-17 19:03:47
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
//l/v为1-l的灯笼数量 r/v为1-r的灯笼数量 相减则为l-r的灯笼数量
//总数减去l-r区间内的 则为区间外的数量
//如果l也是端点 则还要减一
int main()
{
	int t;
	int L,v,l,r;
	cin>>t;
	while(t--)
	{
		cin>>L>>v>>l>>r;
		int res=r/v-l/v;
		if(l%v==0)
			res+=1;
		cout<<L/v-res<<endl;
	}
	return 0;
}