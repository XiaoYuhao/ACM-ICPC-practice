#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

const int MAX = 205;
const int INF = 99999999;

double cost[MAX][MAX];
double d[MAX];
bool used[MAX];
int V;
struct Point {
	int x;
	int y;
}P[MAX];
double Len(Point a, Point b) {
	return sqrt(1.0*(a.x - b.x)*(a.x - b.x) + 1.0*(a.y - b.y)*(a.y - b.y));
}

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
			d[u] = min(d[u], max(d[v], cost[v][u]));
		}
	}
}

int main() {
	int n;
	int count = 1;
	while (1) {
		scanf("%d", &n);
		V = n;
		if (n == 0)break;
		int a, b;
		memset(cost, 0x7f, sizeof(cost));
		memset(P, 0, sizeof(P));
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			P[i].x = a;
			P[i].y = b;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cost[i][j] = cost[j][i] = Len(P[i], P[j]);
			}
		}
		dijkstra(0);
		printf("Scenario #%d\n", count++);
		printf("Frog Distance = %.3lf\n", d[1]);
		printf("\n");
	}
	return 0;
}