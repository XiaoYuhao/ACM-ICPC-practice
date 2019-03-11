#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 105;
int dp[MAX][MAX];
int a[MAX];
int sum[MAX];

int main() {
	int tt;
	int count = 1;
	cin >> tt;
	if (tt == 0)return 0;
	while (tt--) {
		int n;
		cin >> n;
		sum[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum[i] = sum[i - 1] + a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i+1; j <= n; j++) {
				dp[i][j] = 99999999;
			}
		}
		for (int i = n - 1; i > 0; i--) {
			for (int j = i + 1; j <= n; j++) {
				for (int k = i; k <= j; k++) {
					dp[i][j] = min(dp[i][j], dp[i + 1][k] + dp[k + 1][j] + (k - i)*a[i] + (sum[j] - sum[k])*(k - i + 1));
				}
			}
		}
		cout << "Case #" << count++ << ": " << dp[1][n] << endl;
	}
	return 0;
}