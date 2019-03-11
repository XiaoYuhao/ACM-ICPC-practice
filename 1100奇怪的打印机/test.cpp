#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long LL;
const int MAX = 5000010;
char num[MAX];
int n, MOD;
int dp[MAX][21];
const int MODD = 1000000007;

LL dfs(int pos, int mod) {
	if (pos >= n)return mod == 0;
	if (dp[pos][mod] != -1) {
		return dp[pos][mod];
	}
	int ans = 0;
	if (num[pos] == 'X') {
		for (int i = 0; i <= 9; i++) {
			ans = (ans + dfs(pos + 1, (mod * 10 + i) % MOD)) % MODD;
		}
	}
	else {
		int kk = num[pos] - '0';
		ans = (ans + dfs(pos + 1, (mod * 10 + kk) % MOD)) % MODD;
	}
	dp[pos][mod] = ans;
	return ans;
}

int main() {
	int tt, count = 1;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d%d", &n, &MOD);
		scanf("%s", num);
		memset(dp, -1, sizeof(dp));
		printf("Case #%d:\n%lld\n", count++, dfs(0, 0));
	}
	return 0;
}