#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;

const int MAX = 300;
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

int par[MAX];
int Rank[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		par[i] = i;
		Rank[i] = 0;
	}
}
int find(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (Rank[x] < Rank[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (Rank[x] == Rank[y])Rank[x]++;
	}
}

int bg[105][105];

int solve(int n,int mid) {
	for (int i = 0; i <= 2 * n + 1; i++) {
		G[i].clear();
	}
	int s, t;
	s = 0;
	t = 2 * n + 1;
	for (int i = 1; i <= n; i++) {
		add_edge(s, i, mid);
		add_edge(n + i, t, mid);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (bg[i][j]) {
				add_edge(i, n + j, 1);
			}
		}
	}
	int ans = max_flow(s, t);
	return ans;
}
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n, m, f;
		scanf("%d%d%d", &n, &m, &f);
		int a, b;
		memset(bg, 0, sizeof(bg));
		init();
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			bg[a][b] = 1;
//			unite(a, b + n);
		}
		for (int i = 0; i < f; i++) {
			scanf("%d%d", &a, &b);
			unite(a, b);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					if (bg[i][j]) {
						if (find(i) == find(k)) {
							bg[k][j] = 1;
						}
					}
				}
			}
		}
/*		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << bg[i][j] << " ";
			}
			cout << endl;
		}*/
		int l = 0, r = n, mid = 0, res = 0, ans = 0;
		while (r >= l) {
			mid = (r + l) / 2;
			res = solve(n, mid);
			if (res == mid*n) {
				l = mid + 1;
				ans = mid;
			}
			else {
				r = mid - 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}