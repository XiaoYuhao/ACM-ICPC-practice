#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
using namespace std;

const int MAX = 1010;
const int MAX_E = 100010;
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

struct Edge {
	int from, to, w, next;
}E1[MAX_E], E2[MAX_E];
int head1[MAX];
int head2[MAX];
int vis[MAX];
int d1[MAX];
int d2[MAX];
int V, m, t1, t2;
void add1(int i, int j, int w) {
	E1[t1].from = i;
	E1[t1].to = j;
	E1[t1].w = w;
	E1[t1].next = head1[i];
	head1[i] = t1++;
}
void add2(int i, int j, int w) {
	E2[t2].from = i;
	E2[t2].to = j;
	E2[t2].w = w;
	E2[t2].next = head2[i];
	head2[i] = t2++;
}
void spfa1(int s) {
	queue<int> q;
	for (int i = 1; i <= V; i++) {
		d1[i] = INF;
	}
	memset(vis, false, sizeof(vis));
	q.push(s);
	d1[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head1[u]; i != -1; i = E1[i].next) {
			int v = E1[i].to;
			if (d1[v] > d1[u] + E1[i].w) {
				d1[v] = d1[u] + E1[i].w;
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
}
void spfa2(int s) {
	queue<int> q;
	for (int i = 1; i <= V; i++) {
		d2[i] = INF;
	}
	memset(vis, false, sizeof(vis));
	q.push(s);
	d2[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head2[u]; i != -1; i = E2[i].next) {
			int v = E2[i].to;
			if (d2[v] > d2[u] + E2[i].w) {
				d2[v] = d2[u] + E2[i].w;
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
}

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int a, b, c;
		memset(head1, -1, sizeof(head1));
		memset(head2, -1, sizeof(head2));
		t1 = 0;
		t2 = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			if (a == b)continue;
			add1(a, b, c);
			add2(b, a, c);
		}
		int s, t;
		scanf("%d%d", &s, &t);
		V = n;
		spfa1(s);
		spfa2(t);
		if (d1[t] == INF) {
			printf("0\n");
			continue;
		}
		for (int i = 0; i < t1; i++) {
			if (d1[E1[i].from] + d2[E1[i].to] + E1[i].w == d1[t]) {
				add_edge(E1[i].from, E1[i].to, 1);
			}
		}
		int ans = max_flow(s, t);
		printf("%d\n", ans);
		for (int i = 0; i <= n; i++) {
			G[i].clear();
		}
	}
	return 0;
}
/*
1
6 7
1 2 1
2 3 1
1 3 3
3 4 1
3 5 1
4 4 1
5 5 1
1 6

*/