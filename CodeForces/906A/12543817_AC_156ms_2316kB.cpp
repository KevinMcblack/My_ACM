#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <stdlib.h> 
#include <math.h>
using namespace std;
const int N = 1e5 + 10;
char c, s[N];
bool safe[N], temp[N];//safe里面存合法字符，temp存！发言后的话  
int main()
{
	int n, ans, cnt, flag;
	ans = flag = 0;
	cin >> n;
	while (n--)
	{
		cin >> c >> s;
		if (c == '!')
		{
			memset(temp, 0, sizeof(temp));
			for (int i = 0; s[i]; i++) //把！包含非法字母的话语每个字母全部标记1  
				temp[s[i]] = 1;
			for (int i = 'a'; i <= 'z'; i++) //26个字母除开！发言后的，全部存入safe字符组里面  
				if (!temp[i])  //判断只要不是！里面的字母全是合法的  
					safe[i] = 1;
			if (flag) ans++;  //当flag=1，说明已经确定非法字母，如果还有！，就要电击，没有确定就不电击  
		}
		else if (c == '.') //.发言的话语，不含非法字母，全部存入safe字符组  
			for (int i = 0; s[i]; i++)
				safe[s[i]] = 1;
		else if (c == '?')       //猜测字符  
		{
			if (flag&&safe[s[0]])//如果确定非法字母，并且没有猜到非法字母，就要电击  
				ans++;
			else safe[s[0]] = 1;//其余情况就要把猜的这个字母存入safe字符组  
		}
		cnt = 0;       //每次cnt初始化，不然重复累加cnt一定会超过26，不符合题意  
		for (int i = 'a'; i <= 'z'; i++)//对26个字母扫一遍，当合法字母达到25个的时候，就一定确定了，唯一的那个非法字符。  
			if (safe[i])
				cnt++;
		if (cnt == 25)   //合法字符25的时候。非法字母唯一确定，flag=1；  
			flag = 1;
	}
	cout << ans << endl;
	return 0;
}
