#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<string>

const int MAX = 1400;
const int INF = 99999999;
/*
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
}*/

struct edge {
	int to;//终点
	int cap;//容量
	int rev;//反向边
};

vector<edge> G[MAX];
bool used[MAX];

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

int dfs(int v, int t, int f) {
	if (v == t)return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
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
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, INF);
		if (f == 0)return flow;
		flow += f;
	}
}
/*
struct node1
{
	int v, next, flow;
} edge[MAX*MAX];

int n, m, cnt, head[MAX], layer[MAX];

void add_edge(int u, int v, int flow)
{
	edge[cnt].v = v;
	edge[cnt].next = head[u];
	edge[cnt].flow = flow;
	head[u] = cnt++;

	swap(u, v);

	edge[cnt].v = v;
	edge[cnt].next = head[u];
	edge[cnt].flow = 0;
	head[u] = cnt++;
}

bool BFS(int sa, int en)
{
	memset(layer, 0, sizeof(layer));
	queue <int> que;
	que.push(sa);
	layer[sa] = 1;

	while (que.size())
	{
		sa = que.front();
		que.pop();

		if (sa == en) return true;

		for (int i = head[sa]; i != -1; i = edge[i].next)
		{
			int v = edge[i].v;
			if (edge[i].flow && !layer[v])
			{
				layer[v] = layer[sa] + 1;
				que.push(v);
			}
		}
	}
	return false;
}

int DFS(int sa, int maxflow, int en)
{
	if (sa == en) return maxflow;

	int uflow = 0;

	for (int i = head[sa]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;

		if (edge[i].flow && layer[v] == layer[sa] + 1)
		{
			int flow = min(maxflow - uflow, edge[i].flow);
			flow = DFS(v, flow, en);

			edge[i].flow -= flow;
			edge[i ^ 1].flow += flow;
			uflow += flow;

			if (uflow == maxflow) break;///当达到最大流时不再遍历
		}
	}
	if (!uflow) layer[sa] = 0;
	return uflow;
}

int dinic(int sa, int en)
{
	int maxflow = 0;
	while (BFS(sa, en))
		maxflow += DFS(sa, INF, en);
	return maxflow;
}*/

int food[205];
int drink[205];
int main() {
	int n, f, d;
	while (scanf("%d%d%d", &n, &f, &d) != EOF) {
		memset(food, 0, sizeof(food));
		memset(drink, 0, sizeof(drink));
		for (int i = 1; i <= f; i++) {
			scanf("%d", &food[i]);
			add_edge(0, i, food[i]);
		}
		for (int i = 1; i <= d; i++) {
			scanf("%d", &drink[i]);
			add_edge(2 * n + f + i, 2 * n + f + d + 1, drink[i]);
		}
		char c[MAX];
		for (int i = 1; i <= n; i++) {
			scanf("%s", &c);
			for (int j = 1; j <= f; j++) {
				if (c[j-1] == 'Y') {
					add_edge(j, f + i, 1);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			scanf("%s", &c);
			for (int j = 1; j <= d; j++) {
				if (c[j-1] == 'Y') {
					add_edge(n + f + i, 2 * n + f + j, 1);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			add_edge(f + i, n + f + i, 1);
		}
		int ans = max_flow(0, 2 * n + f + d + 1);
		printf("%d\n", ans);
	}
	return 0;
}