#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int MAX = 1000005;
int x[MAX];
int dp[MAX];
int mx[MAX];

int main() {
	int m, n;
	while (~scanf("%d %d", &m, &n)) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x[i]);
		}
		for (int i = 0; i <= n; i++) {
			dp[i] = 0;
			mx[i] = 0;
		}
		int mmax = 0;
		for (int i = 1; i <= m; i++) {
			mmax = -999999999;
			for (int j = i; j <= n; j++) {
				dp[j] = max(dp[j - 1] + x[j], mx[j - 1] + x[j]);
				mx[j - 1] = mmax;
				mmax = max(mmax, dp[j]);
			}
		}
		printf("%d\n", mmax);
	}
	return 0;
}