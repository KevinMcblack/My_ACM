#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	long long num;
	cin >> n;
	while (n--)
	{
		cin >> num;
		int count = 0;
		for (int i = num; i > 0; i /= 2)
			count++;
		cout << count << endl;
	}
}