#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

const int MAX = 200010;
const int INF = 0x3f3f3f3f;
struct edge {
	int from, to, w, next;
}E[MAX];
int head[MAX];
int vis[MAX];
int dist[MAX][11];
int n, m, t, k;
void add(int i, int j, int w) {
	E[t].from = i;
	E[t].to = j;
	E[t].w = w;
	E[t].next = head[i];
	head[i] = t++;
}
void spfa(int s) {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 10; j++)
			dist[i][j] = INF;
	}
	memset(vis, false, sizeof(vis));
	q.push(s);
	dist[s][k] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; i != -1; i = E[i].next) {
			int v = E[i].to;
			int flag = 0;
			for (int j = k; j > 0; j--) {
				if (dist[v][j - 1] > dist[u][j]) {
					dist[v][j - 1] = dist[u][j];
					flag = 1;
				}
				else if (dist[v][j-1] > dist[u][j-1] + E[i].w) {
					dist[v][j - 1] = dist[u][j - 1] + E[i].w;
					flag = 1;
				}
			}
			if (flag) {
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
		scanf("%d%d%d", &n, &m, &k);
		t = 0;
		memset(head, 0, sizeof(head));
		memset(E, 0, sizeof(E));
		int a, b, c;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			add(a, b, c);
		}
		spfa(0);
		int ans = 0x7fffffff;
		for (int i = 0; i <= k; i++) {
			ans = min(ans, dist[n-1][i]);
		}
		printf("%d\n", ans);
	}
}