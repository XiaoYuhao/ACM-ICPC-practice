#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 1010;
const int INF = 99999999;

int cost[MAX][MAX];
int d[MAX];
bool used[MAX];
int V;
int ss[MAX];
int ddd[MAX];

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
	int t, s, dd;
	while (scanf("%d%d%d", &t, &s, &dd) != EOF) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cost[i][j] = INF;
			}
		}
		int a, b, c;
		for (int i = 0; i < t; i++) {
			scanf("%d%d%d", &a, &b, &c);
			if (cost[a - 1][b - 1] > c) {
				cost[a - 1][b - 1] = c;
				cost[b - 1][a - 1] = c;
			}
		}
/*		int sum = 0;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (cost[i][j] != INF) {
					sum++;
				}
			}
		}
		V = sum / 2;*/
		V = MAX;
		for (int i = 0; i < s; i++) {
			scanf("%d", &a);
			ss[i] = a - 1;
		}
		for (int i = 0; i < dd; i++) {
			scanf("%d", &a);
			ddd[i] = a - 1;
		}
		int min = INF;
		for (int i = 0; i < s; i++) {
			dijkstra(ss[i]);
			for (int j = 0; j < dd; j++) {
				if (d[ddd[j]] < min) {
					min = d[ddd[j]];
				}
			}
		}
		printf("%d\n", min);
	}
	return 0;
}