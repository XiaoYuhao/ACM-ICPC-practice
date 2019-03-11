#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main() {
	int tt, count = 1;
	scanf("%d", &tt);
	while (tt--) {
		int n, m, k;
		double ans = 0;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < k; i++) {
			ans += double(n - i) / double(m - i);
		}
		printf("Case #%d: %.12f\n", count++, ans);
	}
	return 0;
}