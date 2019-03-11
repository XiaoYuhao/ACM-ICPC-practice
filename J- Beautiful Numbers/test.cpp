#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int mod;
long long n;
int a[22];
long long dp[22][109][150];

long long dfs(int pos, int sum, int remind, int limit)
{
	if (pos == -1)
		return sum == 0 && remind == 0;
	if (!limit&&dp[pos][sum][remind] != -1) return dp[pos][sum][remind];
	int to;
	if (limit)
		to = a[pos];
	else to = 9;
	long long ans = 0;
	for (int i = 0; i <= to; i++)
		if (i>sum)break;
		else
			ans += dfs(pos - 1, sum - i, (remind * 10 + i) % mod, limit&&i == a[pos]);
	if (!limit) dp[pos][sum][remind] = ans;
	return ans;
}

long long  solve(long long x)
{
	int cnt = 0;
	while (x)
	{
		a[cnt++] = x % 10;
		x /= 10;
	}
	long long  ans = 0;
	for (int i = 1; i <= 9 * cnt; i++)
	{
		mod = i;
		memset(dp, -1, sizeof(dp));
		ans += dfs(cnt - 1, i, 0, 1);
	}
	return ans;
}

int main()
{
	int tt, count = 1;
	cin >> tt;
	while (tt--) {
		long long n;
		cin >> n;
		printf("Case %d: %lld\n",count++, solve(n));
	}
	return 0;
}
