#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>
#include<stdio.h>
#include<vector>
using namespace std;

const int MAX = 110;
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
	int m, n;
	scanf("%d%d", &m, &n);
	int pigs[1005];
	int frist[1005];
	int last[1005];
	int buy[MAX];
	int flag = 0;
	memset(frist, 0, sizeof(frist));
	memset(last, 0, sizeof(last));
	for (int i = 1; i <= m; i++) {
		scanf("%d", &pigs[i]);
	}
	for (int i = 1; i <= n; i++) {
		int key_num, key;
		flag = 1;
		scanf("%d", &key_num);
		for (int j = 0; j < key_num; j++) {
			scanf("%d", &key);
			if (!frist[key])frist[key] = i;
			if (!last[key])last[key] = i;
			else {
				add_edge(last[key], i, INF);
				last[key] = i;
				flag = 0;
			}
		}
		scanf("%d", &buy[i]);
	}
	for (int i = 1; i <= n; i++) {
		int cap = 0;
		for (int j = 1; j <=m; j++) {
			if (frist[j] == i) {
				cap += pigs[j];
			}
		}
		add_edge(0, i, cap);
	}
	for (int i = 1; i <= n; i++) {
		add_edge(i, n + 1, buy[i]);
	}
	int ans = max_flow(0, n + 1);
	printf("%d\n", ans);
	return 0;
}