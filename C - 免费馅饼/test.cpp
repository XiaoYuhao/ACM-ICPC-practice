#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX = 100005;
int dp[MAX][11];
//int b[MAX][11];
int max(int a, int b, int c) {
	if (a >= b&&a >= c) {
		return a;
	}
	if (b >= a&&b >= c) {
		return b;
	}
	else return c;
}
int main() {
	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0) break;
		int x, t;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < 11; j++) {
				//				b[i][j] = 0;
				dp[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &t);
			//			b[t][x]++;
			dp[t][x]++;
		}
		for (int j = 0; j < 11; j++) {
			if (j != 4 && j != 5 && j != 6) {
				dp[1][j] = 0;
			}
		}
		
		for (int i = 2; i < MAX; i++) {
			for (int j = 0; j < 11; j++) {
				if (j > 0 && j < 10) {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1], dp[i - 1][j - 1]) + dp[i][j];
				}
				else if (j == 0) {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]) + dp[i][j];
				}
				else if (j == 10) {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + dp[i][j];
				}
			}

		}
		int max = 0;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < 11; j++) {
				if (dp[i][j] > max) {
					max = dp[i][j];
				}
			}
		}
		printf("%d\n", max);
	}
	return 0;
}