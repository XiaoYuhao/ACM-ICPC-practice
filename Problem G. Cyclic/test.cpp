#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX = 100005;
const int MOD = 998244353;
long long a[MAX];

void init() {
	a[0] = 1;
	a[1] = 0;
	for (int i = 2; i < MAX; i++) {
		if (i % 2 == 1)
			a[i] = ((i - 2)*a[i - 1] % MOD + (i - 1)*a[i - 2] % MOD + 1 + MOD) % MOD;
		else
			a[i] = ((i - 2)*a[i - 1] % MOD + (i - 1)*a[i - 2] % MOD - 1 + MOD) % MOD;
	}
}

int main() {
	long long tt, n;
	scanf("%lld", &tt);
	init();
	while (tt--) {
		scanf("%lld", &n);
		printf("%lld\n", a[n]);
	}
	return 0;
}