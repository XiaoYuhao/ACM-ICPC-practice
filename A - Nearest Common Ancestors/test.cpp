#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;

const int MAX = 10010;
const int MAX_LOG = 50;

/* LCA最近公共祖先 */
/* 基于二分搜索的算法*/
vector<int>G[MAX];
vector<int>T[MAX];
int root;
/*
int parent[MAX_LOG][MAX];
int depth[MAX];

void dfs(int v, int p, int d) {
	parent[0][v] = p;
	depth[v] = d;
	for (int i = 0; i < G[v].size(); i++) {
		if (G[v][i] != p)dfs(G[v][i], v, d + 1);
	}
}

void init(int V) {
	dfs(root, -1, 0);
	for (int k = 0; k + 1 < MAX_LOG; k++) {
		for (int v = 0; v < V; v++) {
			if (parent[k][v] < 0)parent[k + 1][v] = -1;
			else parent[k + 1][v] = parent[k][parent[k][v]];
		}
	}
}

int lca(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v);
	for (int k = 0; k < MAX_LOG; k++) {
		if ((depth[v] - depth[u]) >> k & 1) {
			v = parent[k][u];
		}
	}
	if (u == v)return u;
	for (int k = MAX_LOG - 1; k >= 0; k--) {
		if (parent[k][u] != parent[k][v]) {
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	return parent[0][u];
}*/

int parent[MAX];
int depth[MAX];

void dfs(int v, int p, int d) {
	parent[v] = p;
	depth[v] = d;
	for (int i = 0; i < G[v].size(); i++) {
		if (G[v][i] != p)dfs(G[v][i], v, d + 1);
	}
}
void init() {
	dfs(root, -1, 0);
}
int lca(int u, int v) {
	while (depth[u] > depth[v])u = parent[u];
	while (depth[v] > depth[u])v = parent[v];
	while (v != u) {
		u = parent[u];
		v = parent[v];
	}
	return u;
}

int find_root(int v) {
	if (T[v].size() == 0)return v;
	else return find_root(T[v][0]);
}

int main() {
	int  tt;
	scanf("%d", &tt);
	int n;
	while (tt--) {
		scanf("%d", &n);
		int a, b;
		for (int i = 0; i < n-1; i++) {
			scanf("%d%d", &a, &b);
			G[a-1].push_back(b-1);
			G[b-1].push_back(a-1);
			T[b - 1].push_back(a - 1);
		}
		root = find_root(0);
//		cout << "          " << root << endl;
		init();
		scanf("%d%d", &a, &b);
		int ans;
		ans = lca(a - 1, b - 1) + 1;
		printf("%d\n", ans);
		for (int i = 0; i <n; i++) {
			G[i].clear();
			T[i].clear();
		}
	}
	return 0;
}