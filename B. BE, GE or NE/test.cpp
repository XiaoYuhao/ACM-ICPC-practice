#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<cstring>

using namespace std;
const int MAX = 1010;
int a[MAX], b[MAX], c[MAX];
int down, up;
int n, m, R, L;
int dp[MAX][305];
map<int, int> id;
int dfs(int pos, int now) {
	if (pos == n + 1) {
		if (now >= R)return 2;
		else if (now > L)return 1;
		return 0;
	}
	if (dp[pos][id[now]] != -1)return dp[pos][id[now]];

	if (pos % 2) {
		int f = 0;
		if (a[pos])f = max(f, dfs(pos + 1, min(now + a[pos], up)));
		if (b[pos])f = max(f, dfs(pos + 1, max(now + b[pos], down)));
		if (c[pos])f = max(f, dfs(pos + 1, -now));
		dp[pos][id[now]] = f;
		return f;
	}
	else {
		int f = 2;
		if (a[pos])f = min(f, dfs(pos + 1, min(now + a[pos], up)));
		if (b[pos])f = min(f, dfs(pos + 1, max(now + b[pos], down)));
		if (c[pos])f = min(f, dfs(pos + 1, -now));
		dp[pos][id[now]] = f;
		return f;
	}
}

int main() {
	up = 100;
	down = -100;
	int tot = 0;
	for (int i = -100; i <= 100; i++)id[i] = ++tot;
	scanf("%d%d%d%d", &n, &m, &R, &L);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		b[i] = -b[i];
	}
	memset(dp, -1, sizeof(dp));
	int flag = dfs(1, m);
	if (flag == 2) {
		printf("Good Ending\n");
		return 0;
	}
	else if (flag == 1) {
		printf("Normal Ending\n");
		return 0;
	}
	else {
		printf("Bad Ending\n");
		return 0;
	}
}