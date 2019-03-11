#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX = 1005;

int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
long long int num[MAX];

int main() {
	int tt, count = 1;
	scanf("%d", &tt);
	int n;
	long long ans = 2;
	int i, j;
	for (int k = 1; k <= 1000; k++) {
		for (int i = 1; i <= k; i++) {
			if (gcd(i, k) == 1)ans++;
		}
		for (int i = 1; i < k; i++) {
			if (gcd(k, i) == 1)ans++;
		}
		num[k] = ans;
	}
	while (tt--) {
		scanf("%d", &n);
		ans = num[n];
		printf("%d %d %d\n", count++, n, ans);
	}
	return 0;
}