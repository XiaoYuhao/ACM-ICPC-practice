#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;

const int MAX = 10005;
int dp[MAX][2];
int belong[MAX][2];
struct computer {
	int v;
	int len;
};
vector<computer> edge[MAX];

void DFS1(int t, int p) {
	int k;
	dp[t][0] = 0;
	dp[t][1] = 0;
	for (int i = 0; i < edge[t].size(); i++) {
		k = edge[t][i].v;
		if (k == p)continue;
		DFS1(k, t);
		if (dp[k][0] + edge[t][i].len > dp[t][0]) {
			dp[t][1] = dp[t][0];
			belong[t][1] = belong[t][0];
			dp[t][0] = dp[k][0] + edge[t][i].len;
			belong[t][0] = k;
		}
		else if (dp[k][0] + edge[t][i].len > dp[t][1]) {
			dp[t][1] = dp[k][0] + edge[t][i].len;
			belong[t][1] = k;
		}
	}
}
void DFS2(int t, int p, int length) {
	int i, k;
	if (t != 1) {
		if (belong[p][0] == t) {
			if (dp[t][0] < dp[p][1] + length) {
				dp[t][1] = dp[t][0];
				belong[t][1] = belong[t][0];
				dp[t][0] = dp[p][1] + length;
				belong[t][0] = p;
			}
			else if (dp[t][1] < dp[p][1] + length) {
				dp[t][1] = dp[p][1] + length;
				belong[t][1] = p;
			}
		}
		else {
			if (dp[t][0] < dp[p][0] + length) {
				dp[t][1] = dp[t][0];
				belong[t][1] = belong[t][0];
				dp[t][0] = dp[p][0] + length;
				belong[t][0] = p;
			}
			else if (dp[t][1] < dp[p][0] + length) {
				dp[t][1] = dp[p][0] + length;
				belong[t][0] = p;
			}
		}
	}
	for (int i = 0; i < edge[t].size(); i++) {
		k = edge[t][i].v;
		if (k == p)continue;
		DFS2(k, t, edge[t][i].len);
	}
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i <= n; i++) {
			edge[i].clear();
		}
		computer c;
		int x, y;
		for (int i = 2; i <= n; i++) {
			scanf("%d%d", &x, &y);
			c.len = y;
			c.v = x;
			edge[i].push_back(c);
			c.v = i;
			edge[x].push_back(c);
		}
		DFS1(1, -1);
		DFS2(1, -1, 0);
		for (int i = 1; i <= n; i++) {
			printf("%d\n", max(dp[i][0], dp[i][1]));
		}
	}
	return 0;
}
