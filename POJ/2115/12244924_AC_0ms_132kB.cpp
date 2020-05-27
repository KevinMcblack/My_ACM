#include <stdio.h>  
typedef long long ll;
//题意：for(i = A; i != B; i += C) { i % (2 ^ k) }; 问你循环执行几次？
//思路：先假设等式成立：(A + x*C) % (2 ^ k) = B
//变形(2 ^ k)*y + B = A + C*x == >        C*x + (-(2 ^ k)*y) = B - A;
//ax + by = c
//扩展欧几里德算法是用来在已知a, b求解一组p，q使得p * a+q * b = Gcd(a, b) (解一定存在，根据数论中的相关定理)。
int  exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b==0)
	{
		x = 1, y = 0;
		return a;
	}
	ll d,t;
	d = exgcd(b, a%b, x, y);
	t = x; x = y; y = t - (a / b)*y;
	return d;
}
ll mabs(ll x) { return x>0 ? x : -x; }
int main()
{
	ll A, B, C, K;
	while (scanf("%I64d%I64d%I64d%I64d", &A, &B, &C, &K) && (A + B + C + K))
	{
		ll a = C, b = (ll)1 << K, c = B - A,p=(ll)1 << K;
		ll d, x, y;
		d = exgcd(a, b, x, y);
		if (c == 0)
		{
			printf("0\n");
		}
		else if (c%d != 0)
			printf("FOREVER\n");
		else
		{
			x = (x*(c / d)) % p;//ax+by=c(mod p)的解
			ll t = mabs(b / d);
			x = (x%t + t) % t;//最小非负整数解
			if (!x) x += t;//为0时要调整
			printf("%I64d\n", x);
		}
	}
	return 0;
}