#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 105;
int v[MAX];
int w[MAX];
int dp[MAX][MAX];

int main() {
	int n, m, k, s;
	int a, b;
	while (cin >> n >> m >> k >> s) {
		for (int i = 0; i < MAX; i++) {
			v[i] = 0;
			w[i] = 0;
		}
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				dp[i][j] = 0;
			}
		}
		for (int i = 1; i <= k; i++) {
			cin >> a >> b;
			v[i] = a;
			w[i] = b;
		}
		for (int i = 1; i <= k; i++) {
			for (int j = w[i]; j <= m; j++) {
				for (int g = 1; g <= s; g++)
				{
					dp[j][g] = max(dp[j][g], dp[j - w[i]][g - 1] + v[i]);
				}
			}
		}
		/*		for (int i = 0; i <= m; i++) {
					for (int j = 0; j <= s; j++) {
						cout << dp[i][j] << " ";
					}
					cout << endl;
				}*/
		if (dp[m][s] < n) {
			cout << "-1" << endl;
			continue;
		}
		int max = 0;
		for (int i = 0; i <= m; i++) {
			if (dp[i][s] >= n) {
				max = m - i;
				break;
			}
		}
		cout << max << endl;
	}
	return 0;
}