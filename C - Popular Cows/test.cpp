#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<string>
using namespace std;

const int MAX = 10005;

int V;
vector<int> G[MAX];
vector<int> rG[MAX];
vector<int> vs;
bool used[MAX];
int cmp[MAX];

void add_edge(int from, int to) {
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		if (!used[G[v][i]])dfs(G[v][i]);
	}
	vs.push_back(v);
}

void rdfs(int v, int k) {
	used[v] = true;
	cmp[v] = k;
	for (int i = 0; i < rG[v].size(); i++) {
		if (!used[rG[v][i]])rdfs(rG[v][i], k);
	}
}

int scc() {
	memset(used, 0, sizeof(used));
	vs.clear();
	for (int v = 0; v < V; v++) {
		if (!used[v])dfs(v);
	}
	memset(used, 0, sizeof(used));
	int k = 0;
	for (int i = vs.size() - 1; i >= 0; i--) {
		if (!used[vs[i]])rdfs(vs[i], k++);
	}
	return k;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	V = n;
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		add_edge(a - 1, b - 1);
	}
	int num = scc();
	int u = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (cmp[i] == num - 1) {
			u = i;
			ans++;
		}
	}

	memset(used, 0, sizeof(used));
	rdfs(u, 0);
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			ans = 0;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}