#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

const int MAX = 200010;
const int INF = 99999999;
struct edge {
	int to;
	int cost;
};
typedef pair<int, int> P;
int V;
vector<edge> G[MAX];
int d[MAX];
int lay[MAX];
int flag[MAX];

void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d + V+1, INF);
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first)continue;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
		
	}
}
void addedge(int a, int b, int c) {
	edge e;
	e.to = b;
	e.cost = c;
	G[a].push_back(e);
}

int main() {
	int tt, count = 1;
	scanf("%d", &tt);
	while (tt--) {
		int n, m, c;
		scanf("%d%d%d", &n, &m, &c);
		V = 2 * n;
		edge e;
		int k;
		memset(flag, 0, sizeof(flag));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &lay[i]);
			flag[lay[i]] = 1;
		}
		for (int i = 1; i < n; i++) {
			if (flag[i] && flag[i + 1]) {
				addedge(n + i, n + i + 1, c);
				addedge(n + i + 1, n + i, c);
			}
		}
		for (int i = 1; i <= n; i++) {
			addedge(lay[i] + n, i, 0);
			if (lay[i] > 1)addedge(i, lay[i] - 1 + n, c);
			if (lay[i] < n)addedge(i, lay[i] + 1 + n, c);
		}
		int a, b, w;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &w);
			addedge(a, b, w);
			addedge(b, a, w);
		}
		dijkstra(1);
		if (d[n] >= INF) {
			printf("Case #%d: -1\n", count++);
		}
		else {
			printf("Case #%d: %d\n", count++, d[n]);
		}
		for (int i = 0; i < MAX; i++) {
			G[i].clear();
		}
	}
	return 0;
}