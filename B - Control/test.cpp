#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<stdio.h>
#include<string.h>
using namespace std;

const int MAX = 500;
const int INF = 99999999;

struct edge {
	int to;
	int cap;
	int rev;
};

vector<edge> G[MAX];
int level[MAX];
int iter[MAX];

void add_edge(int from, int to, int cap) {
	edge e;
	e.to = to;
	e.cap = cap;
	e.rev = G[to].size();
	G[from].push_back(e);
	e.to = from;
	e.cap = 0;
	e.rev = G[from].size() - 1;
	G[to].push_back(e);
}

void bfs(int s) {
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while (!que.empty()) {
		int v = que.front();
		que.pop();
		for (int i = 0; i < G[v].size(); i++) {
			edge &e = G[v][i];
			if (e.cap > 0 && level[e.to] < 0) {
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

int dfs(int v, int t, int f) {
	if (v == t)return f;
	for (int &i = iter[v]; i < G[v].size(); i++) {
		edge &e = G[v][i];
		if (e.cap > 0 && level[v] < level[e.to]) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t) {
	int flow = 0;
	while (1) {
		bfs(s);
		if (level[t] < 0)return flow;
		memset(iter, 0, sizeof(iter));
		int f;
		while ((f = dfs(s, t, INF)) > 0) {
			flow += f;
		}
	}
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		int s, d, x;
		scanf("%d%d", &s, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x);
			add_edge(i, i + n, x);
		}
		int a, b;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b);
			add_edge(a + n, b, INF);
			add_edge(b + n, a, INF);
		}
		int ans = max_flow(s, d + n);
		printf("%d\n", ans);
		for (int i = 0; i <=2*n; i++) {
			G[i].clear();
		}
	}
	return 0;
}