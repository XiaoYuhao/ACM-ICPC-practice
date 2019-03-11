#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX = 100010;
int n;
long long int bit[MAX + 1];
long long int bits[MAX + 1];
int a[MAX + 1];
long long int sum(long long int i) {
	long long int s = 0;
	while (i > 0) {
		s += bit[i];
		i -= i&-i;
	}
	return s;
}
long long int sums(long long int i) {
	long long int s = 0;
	while (i > 0) {
		s += bits[i];
		i -= i&-i;
	}
	return s;
}
void add(int i, long long int x) {
	while (i <= n) {
		bit[i] += x;
		i += i&-i;
	}
}
void adds(int i, long long int x) {
	while (i <= n) {
		bits[i] += x;
		i += i&-i;
	}
}
int main() {
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		add(i, a[i]);
		adds(i, a[i]* (n - i + 1));
	}
	int op, x, y;
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &x, &y);
			ans = (sums(y) - sums(x-1)) - ((sum(y) - sum(x-1))*(n - y));
			printf("%lld\n", ans);
		}
		else if (op == 2) {
			scanf("%d%d", &x, &y);
			long long int dx = y - a[x];
			add(x, dx);
			adds(x, dx*(n - x + 1));
			a[x] = y;
		}
	}
	return 0;
}