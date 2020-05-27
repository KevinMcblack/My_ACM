#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string a;
	cin >> a;
	int ans = 0;
	for (int i = 0; i<a.length(); i++) {
		int l = 0, r = 0;//左括号的数量跟?的数量

		for (int j = i; j<a.length(); j++) {
			if (a[j] == '(')
				l++;
			else if (a[j] == ')')
				l--;//相当于跟一个左括号抵消
			else {
				l--;//暂时把?当成右括号，跟左括号抵消。
				r++;
			}

			if (l == 0)
				ans++;//当前区间成功匹配

			if (l<0) {
				if (r == 0)//如果没有?，那么在这之后的所有区间，肯定都不成立
					break;
				else {
					if (r>0) {
						l += 2;//把?重新当成左括号来匹配掉右括号
						r--;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;

}
