#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 2005;
int w[MAX];
int dp[MAX][MAX];

int main() {
	int n, k;
	while (cin >> n >> k) {
		for (int i = 1; i <= n; i++) {
			cin >> w[i];
		}
		w[0] = 0;
		sort(w, w + n + 1);
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				dp[i][j] = 99999999;
			}
		}
		for (int i = 0; i <= n; i++) {
			dp[i][0] = 0;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i/2; j++) {
				dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + (w[i] - w[i - 1])*(w[i] - w[i - 1]));
			}
		}
		cout << dp[n][k] << endl;
	}
	return 0;
}