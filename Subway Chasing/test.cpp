#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
const int MAX = 20010;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

struct edge {
	int from, to, w, next;
}E[MAX];
int head[MAX];
int vis[MAX];
long long int dist[MAX];
int du[MAX];
int n, m, t;
void init() {
	memset(E, 0, sizeof(E));
	memset(head, -1, sizeof(head));
	memset(du, 0, sizeof(du));
	t = 0;
}
void add(int i, int j, int w) {
	E[t].from = i;
	E[t].to = j;
	E[t].w = w;
	E[t].next = head[i];
	head[i] = t++;
}
int spfa(int s) {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	memset(vis, false, sizeof(vis));
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; i != -1; i = E[i].next) {
			int v = E[i].to;
			if (dist[v] > dist[u] + E[i].w) {
				dist[v] = dist[u] + E[i].w;
				if ((++du[v])>n) {
					return 0;//´æÔÚ¸º»·
				}
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	return 1;
}

int main() {
	int tt, count = 1;
	scanf("%d", &tt);
	while (tt--) {
		int nn, m, x;
		scanf("%d%d%d", &nn, &m, &x);
		int a, b, c, dd;
		init();
		n = nn + 1;
		for (int i = 1; i <= nn; i++) {
			add(n, i, 0);
		}
		for (int i = 1; i < nn; i++) {
			add(i + 1, i, -1);
		}
		int flag = 0;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d%d", &a, &b, &c, &dd);
			if (a == b&&b == c&&c == dd) {
				flag = 1;
				continue;
			}
			else if (a == b&&c == dd) {
				add(a, c, x);
				add(c, a, -x);
			}
			else if (a == b&&c != dd) {
				add(a, c, x - 1);
				add(dd, a, -x - 1);
			}
			else {
				add(b, c, x - 1);
				add(dd, a, -x - 1);
			}
		}
		if (flag||spfa(n)==0) {
			printf("Case #%d: IMPOSSIBLE\n", count++);
			continue;
		}
		else {
			printf("Case #%d: ", count++);
			for (int i = 2; i <= nn; i++) {
				if (i == nn) {
					printf("%lld\n", dist[i] - dist[i - 1]);
				}
				else printf("%lld ", dist[i] - dist[i - 1]);
			}
		}
	}

	return 0;
}

/*
6
4 3 2
1 1 2 3
2 3 2 3
2 3 3 4
4 2 2
1 2 3 4
2 3 2 3
4 3 2
1 1 2 3
2 3 2 3
2 3 3 4
4 2 2
1 2 3 4
2 3 2 3
4 3 2
1 1 2 3
2 3 2 3
2 3 3 4
4 2 2
1 2 3 4
2 3 2 3
*/