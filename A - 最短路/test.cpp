#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stdio.h>
#include<functional>
using namespace std;

const int MAX = 105;
const int INF = 99999999;

int cost[MAX][MAX];
int d[MAX];
bool used[MAX];
int V;

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
	int n, m;
	while (1) {
		scanf("%d%d", &n, &m);
		if (n == 0)break;
		V = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cost[i][j] = INF;
			}
		}
		int a, b, c;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			cost[a - 1][b - 1] = c;
			cost[b - 1][a - 1] = c;
		}
		dijkstra(0);
		printf("%d\n", d[n - 1]);
	}
	return 0;
}

