/*
Dijkstra求最短路加01背包问题
Runtime Error：数组开得太小
Memory Limit：01背包开了2维数组，爆掉
Time Limit：01背包循环次数上限太大
Wrong Answer：没有考虑到可能会输入多条边
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX = 105;
const int INF = 99999999;
int cost[MAX][MAX];
int d[MAX];
bool used[MAX];
int V;
int w[MAX];
int dp[1000010];

void dijkstra(int s) {
	fill(d, d + V, INF);
	fill(used, used + V, false);
	d[s] = 0;

	while (true) {
		int v = -1;
		for (int u = 0; u < V; u++) {
			if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}
		if (v == -1)break;
		used[v] = true;

		for (int u = 0; u < V; u++) {
			d[u] = min(d[u], d[v] + cost[v][u]);
		}
	}
}
int main() {
	int tt;
	int n, m;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d%d", &n, &m);
		int a, b, c;
		V = n + 1;
		for (int i = 0; i <= n; i++) {
			w[i] = 0;
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				cost[i][j] = INF;
//				if (i == j) cost[i][j] = 0;
			}
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			if (cost[a][b] > c) {
				cost[a][b] = c;
				cost[b][a] = c;
			}
		}
		int pow_sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &w[i]);
			pow_sum += w[i];
		}
		dijkstra(0);
		int cost_sum = 0;
		for (int i = 0; i <= n; i++) {
			if (d[i] != INF) {
				cost_sum += d[i];
			}
		}

		memset(dp, 0, sizeof(dp));
		for (int i = 0; i <= n; i++) {
			for (int j = cost_sum; j >= d[i]; j--) {
				dp[j] = max(dp[j], dp[j - d[i]] + w[i]);
			}
		}
		int ans = INF;
		for (int i = 0; i <= cost_sum; i++) {
			if (dp[i] > pow_sum / 2) {
				ans = i;
				break;
			}
		}
		if (ans == INF) {
			printf("impossible\n");
		}
		else {
			printf("%d\n", ans);
		}
	}
	return 0;
}