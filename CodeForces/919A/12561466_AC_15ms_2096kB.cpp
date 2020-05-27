#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <stdlib.h> 
#include <math.h>
using namespace std;
struct market {
	double a;
	double b;
}arr[5050];
int main()
{
	int n, kg;
	while (scanf("%d%d", &n, &kg) != EOF)
	{
		int i;
		for (i = 0; i < n; i++)
			scanf("%lf%lf", &arr[i].a, &arr[i].b);
		double min = arr[0].a / arr[0].b;
		for (i = 0; i < n; i++)
			if ((arr[i].a / arr[i].b) < min)
				min = arr[i].a / arr[i].b;
		printf("%.8lf\n", min*kg);
	}
	return 0;
}
