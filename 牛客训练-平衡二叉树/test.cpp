#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main() {
	long long n, d;
	long long ans = 0;
	while (scanf("%lld%lld", &n, &d) != EOF) {
		if (n == 0) {
			printf("0\n");
			continue;
		}
		if (n <= d) {
			ans = ((long long)1 << n - 1) - 1;
		}
		else {
			ans = ((long long)1 << n - 1) - 1 - (n - 1 - d);
		}
		printf("%lld\n", ans);
	}
	return 0;
}