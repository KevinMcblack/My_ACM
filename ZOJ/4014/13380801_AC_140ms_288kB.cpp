#include <iostream>  
#include <cmath>  
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int matrix[105][105];
	while (n--)
	{
		int n, m, a, b;
		while (cin >> n >> m >> a >> b)
		{
			int count = 0;
			int flag[10005];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					cin >> matrix[i][j];
					if (matrix[i][j]<a || matrix[i][j]>b)
					{
						flag[count] = matrix[i][j];
						count++;
					}
				}
			if (a > b)
			{
				cout << "No Solution" << endl;
				break;
			}
			cout << count << endl;		
		}
	}
	return 0;
}