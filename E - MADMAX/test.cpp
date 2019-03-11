#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int n, m;
char G[105][105];
int dp[105][105][30];
int dfs(int u, int v, int last)
{
	if (dp[u][v][last]) return dp[u][v][last];
	for (int i = 1; i <= n; i++)
	{
		if (G[u][i] - 'a' >= last && dfs(v, i, G[u][i] - 'a') == 2)
			return dp[u][v][G[u][i] - 'a'] = 1;
	}
	return dp[u][v][last] = 2;
}
int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		int u, v;
		char c[2];
		memset(G, 0, sizeof G);
		memset(dp, 0, sizeof dp);
		for (int i = 0; i<m; i++)
		{
			scanf("%d%d%s", &u, &v, c);
			G[u][v] = c[0];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dfs(i, j, 0) == 1) printf("A");
				else printf("B");
			}
			printf("\n");
		}
	}
	return 0;
}