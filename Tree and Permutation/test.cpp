#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
const int MAX = 100010;
const int MOD = 1e9 + 7;

const int INF = 99999999;

long long num[MAX];

void init() {
	num[1] = 1;
	num[2] = 2;
	for (int i = 3; i < MAX; i++) {
		num[i] = (num[i - 1] * (i - 1)) % MOD;
	}
}

int main() {
	int n;
	long long ans, len = 0;
	int a, b, c;
	init();
	while (scanf("%d", &n) != EOF) {
		ans = 0;
		len = 0;
		for (int i = 1; i < n; i++) {
			scanf("%d%d%d", &a, &b, &c);
			len = (len + c) % MOD;
		}
		len = len*(n - 1) % MOD;
		ans = len*num[n] % MOD;
		printf("%lld\n", ans);
	}
}