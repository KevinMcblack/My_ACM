#include <iostream>  
#include <cmath>  
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	char a[50], b[50];
	while (cin >> n)
	{
		while (n--)
		{
			cin >> a >> b;
			b[0] -= 32;
			cout << b << a << endl;
		}
	}
	return 0;
}