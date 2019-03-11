#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 10010;
const int INF = 0x3f3f3f3f;

struct edge {
	int to, cap, cost, rev;
};
int V;
vector<edge> G[MAX];
int dist[MAX];
int prevv[MAX], preve[MAX];

void add_edge(int from, int to, int cap, int cost) {
	G[from].push_back(edge{ to,cap,cost,G[to].size() });
	G[to].push_back(edge{ from, 0, -cost, G[from].size() - 1 });
}

int min_cost_flow(int s, int t, int f) {
	int res = 0;
	while (f > 0) {
		fill(dist, dist + V, INF);
		dist[s] = 0;
		bool update = true;
		while (update) {
			update = false;
			for (int v = 0; v < V; v++) {
				if (dist[v] == INF)continue;
				for (int i = 0; i < G[v].size(); i++) {
					edge &e = G[v][i];
					if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
						dist[e.to] = dist[v] + e.cost;
						prevv[e.to] = v;
						preve[e.to] = i;
						update = true;
					}
				}
			}
		}

		if (dist[t] == INF) {
//			return -1;
			return res;
		}

		int d = f;
		for (int v = t; v != s; v = prevv[v]) {
			d = min(d, G[prevv[v]][preve[v]].cap);
		}
		f -= d;
		res += d*dist[t];
		for (int v = t; v != s; v = prevv[v]) {
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}




int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int fac[MAX];
	for (int i = 1; i <= n; i++) {
		fac[i] = i*i;
	}
	fac[0] = 0;
	for (int i = n; i >=1; i--) {
		fac[i] = fac[i] - fac[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		add_edge(0, i, 1, 0);
	}

	int x, y;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		add_edge(i, n + x, 1, 0);
		add_edge(i, n + y, 1, 0);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			add_edge(i+n, m + n + 1, 1, fac[j]);
		}
	}
	V = m + n + 2;
	int ans = min_cost_flow(0, m + n + 1, INF);
	printf("%d\n", ans);
	return 0;
}
