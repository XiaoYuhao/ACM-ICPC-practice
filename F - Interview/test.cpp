#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

const int MOD = 1e9 + 7;

long long pow_m(long long a, long long n)
{
	long long res = 1;
	long long tmp = a%MOD;
	while (n)
	{
		if (n & 1) { res *= tmp; res %= MOD; }
		n >>= 1;
		tmp *= tmp;
		tmp %= MOD;
	}
	return res;
}

int main() {
	int tt;
	scanf("%d", &tt);
	int n, d;
	long long ans;
	while (tt--) {
		scanf("%d%d", &n, &d);
		if (d == 1) {
			ans = (2LL * n + 4LL) % MOD*pow_m(8, MOD - 2) % MOD;
		}
		else {
			ans = (3LL * n + 6LL) % MOD*pow_m(8, MOD - 2) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}