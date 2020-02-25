/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-15 18:57:07 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-17 19:04:23
 */
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int cnt;
//翻转策略一定从外往里翻转最优，复杂度O(N) 
//翻转的时候不要真的在字符串上操作，不要去swap，
//只需要一个变量time记录已经翻了多少次，
//当time为偶数的时候，当前子串就是原来的样子，time为奇数的时候当前字串是已经翻转过一次的 
int main()
{
	int t;
	cin>>t;
	string s1,s2;
	while(t--)
	{
		cin>>s1>>s2;
		int len=s1.size();
		cnt=0;
		int flag=0;
		if(s1[len/2]!=s2[len/2])
			{
				cout<<-1<<endl;
				continue;
			}
		for(int i=0;i<len/2;i++)
		{
			if(s1[i]!=s2[i]&&s1[i]!=s2[len-1-i])
			{
				flag=1;
				break;
			}
			if(s1[i]!=s2[i]&&cnt%2==0)
			{
				if(s1[i]==s2[len-1-i]&&s2[i]==s1[len-1-i])
					cnt++;
			}else if(s1[i]!=s2[len-1-i]&&cnt%2!=0)
			{
				if(s1[i]==s2[i]&&s1[len-1-i]==s2[len-1-i])
					cnt++;
			}
		}
		if(flag)
			cout<<-1<<endl;
		else
			cout<<cnt<<endl;
	}
	return 0;
}