#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX = 1005;
const int INF = 99999999;
int cost[MAX][MAX];
int d[MAX];
bool used[MAX];
int V;

void dijkstra(int s) {
	
	fill(used, used + V, false);
	for (int i = 0; i < V; i++) {
		d[i] = cost[s][i];
	}
	d[s] = INF;
	used[s] = 1;
	while (true) {
		int v = -1;
		int maxx = 0;
		for (int u = 0; u < V; u++) {
			if (!used[u] && d[u] > maxx) { 
				v = u;
				maxx = d[u];
			}
		}
		if (v == -1)break;
		used[v] = true;

		for (int u = 0; u < V; u++) {
			d[u] = max(d[u], min(d[v], cost[v][u]));
		}
	}
}



int main() {
	int tt, count = 1;
	scanf("%d", &tt);
	int n, m;
	while (tt--) {
		scanf("%d%d", &n, &m);
		int a, b, c;
		V = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cost[i][j] = 0;
			}
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			cost[a - 1][b - 1] = c;
			cost[b - 1][a - 1] = c;
		}
/*		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (k != i&&k != j&&i != j) {
						if (cost[i][j] < min(cost[i][k], cost[k][j])) {
							cost[i][j] = min(cost[i][k], cost[k][j]);
						}
					}
				}
			}
		}*/
		dijkstra(0);
		printf("Scenario #%d:\n", count++);
		printf("%d\n", d[n - 1]);
		printf("\n");
	}
	return 0;
}