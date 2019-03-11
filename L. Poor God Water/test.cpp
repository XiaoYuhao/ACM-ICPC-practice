#include<iostream>
#include<algorithm>

using namespace std;
int dp[10000];

int main() {
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 3;
	dp[2] = 9;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] * 3 - dp[i - 2] - (i + 1);
		cout << dp[i] << endl;
	}
	return 0;
}