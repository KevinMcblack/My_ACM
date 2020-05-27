#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	char name[1050][15], ip[1050][50];
	char com[1050][15], ipp[1050][50];
	while (cin >> n >> m)
	{
		for(int i=0;i<n;i++)
			cin >> name[i] >> ip[i];
		for (int i = 0; i < m; i++)
		{
			cin >> com[i] >> ipp[i];
			int len = strlen(ipp[i]);
			ipp[i][len - 1] = NULL;
			for(int j=0;j<n;j++)
				if (strcmp(ipp[i], ip[j])==0)
				{
					printf("%s %s; #%s\n", com[i], ip[j], name[j]);
					break;
				}
		}
	}
	return 0;
}
