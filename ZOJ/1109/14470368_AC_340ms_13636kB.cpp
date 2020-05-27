#include <algorithm>
#include <queue>
#include <functional>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <map>
using namespace std;
map<string, int>m;
char s1[20], s2[20], s3[20];
char s[100007][15];
int main()
{
	int e = 1;
	while (scanf("%c", &s1[0]) && s1[0] != '\n')
	{
		scanf("%s %s", s1 + 1, s2);
		getchar();
		m[s2] = e++;
		strcpy(s[e - 1], s1);
	}
	while (scanf("%s", s3) != EOF)
	{
		if (m[s3] >= 1)
			printf("%s\n", s[m[s3]]);
		else
			printf("eh\n");
	}
	return 0;
}
