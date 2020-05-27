#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		double a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		if (a == c)
			cout << "circle" << endl;
		else if (a*c > 0)
			cout << "ellipse" << endl;
		else if (a*c == 0)
			cout << "parabola" << endl;
		else
			cout << "hyperbola" << endl;
	}
}