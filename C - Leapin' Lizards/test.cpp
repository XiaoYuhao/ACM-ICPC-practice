#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

const int MAX = 1000;
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

char pillar[25][25], lizard[25][25];
int id[25][25], pnum, lnum;
int main() {
	int tt, count = 1;
	scanf("%d", &tt);
	while (tt--) {
		int n, d;
		scanf("%d%d", &n, &d);
		memset(id, 0, sizeof(id));
		pnum = 0;
		lnum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s", pillar[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%s", lizard[i]);
		}
		int m = strlen(pillar[0]);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (pillar[i][j] - '0') id[i][j] = pnum++;
				if (lizard[i][j] == 'L')lnum++;
			}
		}
		int s, t;
		s = 2 * pnum;
		t = 2 * pnum + 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int cap = pillar[i][j] - '0';
				if (cap) {
					if (lizard[i][j] == 'L') {
						add_edge(s, id[i][j], 1);
					}
					add_edge(id[i][j], pnum + id[i][j], cap);
					int flag = 0;
					for (int xd = -d; xd <= d; xd++) {
						for (int yd = abs(xd) - d; yd <= d - abs(xd); yd++) {
							if ((i + xd >= 0 && i + xd < n&&j + yd >= 0 && j + yd < m) && (pillar[i + xd][j + yd] - '0')) {
								add_edge(pnum + id[i][j], id[i + xd][j + yd], cap);
							}
							if (!(i + xd >= 0 && i + xd < n&&j + yd >= 0 && j + yd < m)) {
								flag = 1;
							}
						}
					}
					if (flag) {
						add_edge(pnum + id[i][j], t, cap);
					}
				}
			}
		}
		int ans = lnum - max_flow(s, t);
		if (ans == 0) {
			printf("Case #%d: no lizard was left behind.\n", count++);
		}
		else if (ans == 1) {
			printf("Case #%d: 1 lizard was left behind.\n", count++);
		}
		else {
			printf("Case #%d: %d lizards were left behind.\n", count++, ans);
		}
		for (int i = 0; i <= 2 * pnum + 1; i++) {
			G[i].clear();
		}
	}
	return 0;
}