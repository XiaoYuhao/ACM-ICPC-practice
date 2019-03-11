#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;

const int MAX = 105;

int V;
vector<int> G[MAX];
vector<int> rG[MAX];
vector<int> vs;
int in[MAX];
int out[MAX];
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
	int n;
	scanf("%d", &n);
	V = n;
	int a;
	for (int i = 0; i < n; i++) {
		while (1) {
			scanf("%d", &a);
			if (a == 0)break;
			G[i].push_back(a - 1);
			rG[a - 1].push_back(i);
		}
	}
	int num = scc();
	if (num == 1) {
		printf("1\n0\n");
		return 0;
	}
	memset(used, 0, sizeof(used));
	for (int i = 0; i < n; i++) {
		int k = cmp[i];
		for (int j = 0; j < G[i].size(); j++) {
			if (cmp[G[i][j]] != k) {
				out[cmp[i]]++;
				in[cmp[G[i][j]]]++;
			}
		}
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < num; i++) {
		if (in[i] == 0)ans1++;
	}
	int inn = 0, outn = 0;
	for (int i = 0; i < num; i++) {
		if (in[i] == 0)inn++;
		if (out[i] == 0)outn++;
	}
	ans2 = max(inn, outn);
	printf("%d\n", ans1);
	printf("%d\n", ans2);
	return 0;
}