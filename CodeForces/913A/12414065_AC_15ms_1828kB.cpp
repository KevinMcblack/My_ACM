#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<vector>
#include<set>
#include<math.h>
#include<algorithm>
using namespace std;
int main() {
	long long n, m;
	while (scanf("%lld%lld", &n, &m) != EOF)
	{
		if (n >=27)
			printf("%lld\n", m);
		else
		{
			long long p = pow(2, n);
			long long k = m % p;
			printf("%lld\n", k);
		}
	}
	return 0;
}
