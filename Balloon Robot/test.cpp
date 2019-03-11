#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int MAX = 100010;
long long s[MAX], pos[MAX];

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n, m, p;
		scanf("%d%d%d", &n, &m, &p);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &pos[i]);
			pos[i]--;
		}
		int ta, tb;
		for (int i = 1; i <= p; i++) {
			scanf("%d%d", &ta, &tb);
			s[i] = (pos[ta] - tb%m + m) % m;
		}
		long long ans, cost;
		cost = 0;
		sort(s + 1, s + p + 1);
		for (int i = 1; i <= p; i++) {
			cost += s[i] - s[1];
		}
		ans = cost;
		for (int i = 2; i <= p; i++) {
			cost = cost + m - p*(s[i] - s[i - 1]);
			ans = min(cost, ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}