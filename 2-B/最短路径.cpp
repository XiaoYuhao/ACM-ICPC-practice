#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std; 

const int MAX = 10005;
const int INF = 99999999;

/*
Dijkstra队列优化版本，时间复杂度为O（ElogV）

const int MAX = 105;
const int INF = 99999999;
struct edge {
	int to;
	int cost;
};
typedef pair<int, int> P;
int V;
vector<edge> G[MAX];
int d[MAX];

void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d + V + 1, INF);
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first)continue;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

*/

/*
Dijkstra求最短路，时间复杂度为O(V^2)

int cost[MAX][MAX];
int d[MAX];
bool used[MAX];
int V;

void dijkstra(int s) {
	fill(d, d + V, INF);
	fill(used, used + V, false);
	d[s] = 0;

	while (true) {
		int v = -1;
		for (int u = 0; u < V; u++) {
			if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}
		if (v == -1)break;
		used[v] = true;

		for (int u = 0; u < V; u++) {
			d[u] = min(d[u], d[v] + cost[v][u]);
		}
	}
}

*/

/*
以下为Floyd求最短路算法，时间复杂度为O（n^3）

int d[MAX][MAX];
int V;

void warshall_floyd() {
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}
*/

/*
以下是Bellman-Ford算法，时间复杂度为O(VE)

const int MAX = 110;
const int INF = 99999999;
struct edge {
	int from;
	int to;
	int cost;
};

edge es[MAX];
int d[MAX];
int V, E;

void short_path(int s) {
	for (int i = 0; i < V; i++) {
		d[i] = INF;
	}
	d[s] = 0;
	while (true) {
		bool update = false;
		for (int i = 0; i < E; i++) {
			edge e = es[i];
			if (d[e.from] != INF&&d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if (!update)break;
	}
}
//判断是否有负环
bool find_negative_loop() {
	memset(d, 0, sizeof(d));
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < E; j++) {
			edge e = es[j];
			if (d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				if (i == V - 1)return true;
			}
		}
	}
	return false;
}
*/

/* 邻接表SPFA */
/*
struct edge {
	int from, to, w, next;
}E[MAX];
int head[MAX];
int vis[MAX];
int dist[MAX];
int n, m, t;

void init() {
	memset(E, 0, sizeof(E));
	memset(head, -1, sizeof(head));
}
void add(int i, int j, int w) {
	E[t].from = i;
	E[t].to = j;
	E[t].w = w;
	E[t].next = head[i];
	head[i] = t++;
}
int du[MAX];
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
				if((++du[v])>n){
					return 0;//存在负环
				}
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
}
*/


