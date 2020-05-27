#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <stdlib.h> 
typedef long long ll;
#define mod 1000000007
#define N 5005
using namespace std;
int main()
{
	char a[100];
	while (scanf("%s", a) != EOF)
	{
		int len = strlen(a);
		int i;
		int sum = 0;
		for (i = 0; i < len; i++)
		{
			if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == '1' || a[i] == '3' || a[i] == '5' || a[i] == '7' || a[i] == '9')
				sum++;
		}
		printf("%d\n", sum);
	}
    return 0;
}