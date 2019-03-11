#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	long long int n, q;
	scanf("%lld%lld", &n, &q);
	long long int x, y;
	long long ans;
	for (int i = 0; i < q; i++) {
		scanf("%lld%lld", &x, &y);
		if (x % 2 && y % 2) {
			ans = (n)*((x - 1) / 2) + (y / 2) + 1;
		}
		else if (x % 2 == 0 && y % 2 == 0) {
			ans = (n)*((x - 1) / 2) + (n / 2+ n % 2) + y / 2;
		}
		else if (x % 2 == 1 && y % 2 == 0) {
			ans = (n)*((x - 1) / 2) + y / 2 + (n % 2) + ((n*n) / 2);
		}
		else {
			ans = (n)*((x - 1) / 2) + (n / 2) + y / 2 + 1 + (n % 2) + ((n*n) / 2);
		}
		printf("%lld\n", ans);
	}
	return 0;
}