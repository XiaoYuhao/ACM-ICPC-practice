#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	long long int n, m, ans, a, p;
	while (scanf("%lld", &n) != EOF) {
		m = floor(sqrt(1.0*n));
		ans = n;
		for (int i = 2; i <= m; i++) {
			if (n%i == 0) {
				a = 0;
				p = i;
				while (n%p == 0) {
					a++;
					n /= p;
				}
				ans += ans*a*(p - 1) / p;
			}
		}
		if (n != 1) {
			ans += ans*(n - 1) / n;
		}
		printf("%lld\n", ans);
	}
	return 0;
}