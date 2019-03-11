#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<cstring>
#define MAXN 220020
using namespace std;
#define MOD 1000000009
int f[MAXN] = { 1,2,4 };
long long quick_pow(long long base, long long exp, long long mod_value)
{
	long long k = base;
	long long result = 1;
	while (exp != 0) {
		if (exp % 2) {
			result *= k;
			result %= mod_value;
		}
		k *= k;
		k %= mod_value;
		exp /= 2;
	}
	return result;
}
int main()
{
	long long a, b, c;
	a = quick_pow(2, MOD - 2, MOD);
	b = quick_pow(24, MOD - 2, MOD);
	int t;
	scanf("%d", &t);
	for (int j = 1; j <= t; ++j) {
		long long int n;
		scanf("%lld", &n);
		long long result = 0;
		result = 1;
		long long temp;
		temp = 1;
		for (int i = 0; i<2; ++i) {
			temp *= n - i;
			temp %= MOD;
		}
		temp *= a;
		temp %= MOD;
		result = (result + temp) % MOD;

		temp = 1;
		for (int i = 0; i<4; ++i) {
			temp *= n - i;
			temp %= MOD;
		}
		temp *= b;
		temp %= MOD;
		result = (result + temp) % MOD;
		result %= MOD;
		printf("Case #%d: %lld\n", j, result);
	}
	return 0;
}