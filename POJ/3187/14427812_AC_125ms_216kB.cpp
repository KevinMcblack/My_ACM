#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
int n, sum;
int a[15], v[15];
int getsum()
{
	for (int i = 1; i<n; i++)
		for (int j = 0; j < n; j++)
		{
			a[j] += a[j + 1];
		}
	return a[0];
}
int main()
{
	cin >> n >> sum;
	for (int i = 0; i < n; i++) v[i] = i + 1;
	do
	{
		memcpy(a,v,sizeof(int)*n);
		if (getsum() == sum) break;
	} while (next_permutation(v, v + n));
	for (int i = 0; i < n - 1; i++)
		cout << v[i] << " ";
	cout << v[n - 1] << endl;
	return 0;
}
