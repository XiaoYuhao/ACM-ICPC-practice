#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 41;
//int dp[MAX][3];
long long int dp[MAX];

int main() {

	/*		for (int i = 0; i <= n; i++) {
				dp[i][0] = 0;
				dp[i][1] = 0;
				dp[i][2] = 0;
			}
			dp[0][0] = 1;
			for (int i = 1; i <= n; i++) {
				dp[i][0] = dp[i - 1][0] * 3 - dp[i - 1][1];
				dp[i][1] = dp[i - 1][0];
				dp[i][2] = dp[i - 1][2] * 3 + dp[i - 1][1];
			}
			cout << dp[n][0] << endl;
		}*/
	for (int i = 0; i <= 40; i++) {
		dp[i] = 0;
	}
	dp[0] = 1;
	dp[1] = 3;
	dp[2] = 8;
	for (int i = 3; i <= 40; i++) {
		dp[i] = 2 * dp[i - 1] + 2 * dp[i - 2];
	}
	int n;
	while (cin >> n) {
		cout << dp[n] << endl;
	}

	return 0;
}