#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 10000000 + 5;
const int MOD = 998244353;
long long int F[N], Finv[N], inv[N];//F是阶乘，Finv是逆元的阶乘
void init() {
	inv[1] = 1;
	for (int i = 2; i < N; i++) {
		inv[i] = (MOD - MOD / i) * 1ll * inv[MOD % i] % MOD;
	}
	F[0] = Finv[0] = 1;
	for (int i = 1; i < N; i++) {
		F[i] = F[i - 1] * 1ll * i % MOD;
		Finv[i] = Finv[i - 1] * 1ll * inv[i] % MOD;
	}
}
long long int comb(long long int n, long long int m) {//comb(n, m)就是C(n, m)
	if (m < 0 || m > n) return 0;
	return F[n] * 1ll * Finv[n - m] % MOD * Finv[m] % MOD;
}

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
	init();
	long long a, b, c, d, ans;
	int tt;
	long long ans1 = 0, ans2 = 0, ans3 = 0;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		ans = 0;
		for (int i = 0; i <= b; i++) {
			ans = (ans + comb(b, i)) % MOD;
		}
		for (int i = 0; i <= c; i++) {
			ans = (ans + comb(c, i)*b%MOD) % MOD;
		}
		for (int i = 0; i <= c; i++) {
			ans = (ans + comb(c, i)*d%MOD) % MOD;
		}
		ans = ans*pow_m(2, a) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}