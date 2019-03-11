#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 100;
const int MAX_LOG = 10;
const int INF = 0x3f3f3f3f;

/* LCA最近公共祖先 */
/* 基于二分搜索的算法*/
/*
vector<int>G[MAX];
int root;

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
		if ((depth[v] - depth[u]) >> k & 1){
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

/* 基于RMQ的算法*/
/*
vector<int> G[MAX];
int root;

int vs[MAX * 2 - 1];
int depth[MAX * 2 - 1];
int id[MAX];

void dfs(int v, int p, int d, int &k) {
	id[v] = k;
	vs[k] = v;
	depth[k++] = d;
	for (int i = 0; i < G[v].size(); i++) {
		if (G[v][i] != p) {
			dfs(G[v][i], v, d + 1, k);
			vs[k] = v;
			depth[k++] = d;
		}
	}
}

void init(int V) {
	int k = 0;
	dfs(root, -1, 0, k);
	req_init(depth, V * 2 - 1);
}

int lca(int u,int v) {
	return vs[query(min(id[u], id[v]), max(id[u], id[v]) + 1)];
}
*/

/* 强连通分量分解 */
/*
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
*/

/* 最大流Ford Fulkerson */
/*
 
*/

/* 最大流Dinic算法*/
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
}
*/

/* 最大流Dinic算法 手动邻接表实现*/
/*
struct node1
{
	int v, next, flow;
} edge[MAX*MAX];

int n, m, cnt, head[MAX], layer[MAX];


void Init ()
{
memset (head, -1, sizeof (head));
cnt = 0;
}

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


/*最小生成树问题Kruskal算法*/
/*
int par[MAX];
int Rank[MAX];

void init_union_find(int n) {
	for (int i = 0; i < n; i++) {
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
bool same(int x, int y) {
	return find(x) == find(y);
}

struct edge { int u, v, cost; };
bool comp(const edge &e1, const edge &e2) {
	return e1.cost < e2.cost;
}
edge es[MAX];
int V, E;

int kruskal() {
	sort(es, es + E, comp);
	init_union_find(V);
	int res = 0;
	for (int i = 0; i < E; i++) {
		edge e = es[i];
		if (!same(e.u, e.v)) {
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}
*/

/*最小生成树Prim算法*/
/*
int cost[MAX][MAX];
int mincost[MAX];
bool used[MAX];
int V;
int prim() {
	for (int i = 0; i < V; i++) {
		mincost[i] = INF;
		used[i] = false;
	}
	mincost[0] = 0;
	int res = 0;
	
	while (true) {
		int v = -1;

		for (int u = 0; u < V; u++) {
			if (!used[u] && (v == -1 || mincost[u] < mincost[v]))v = u;
		}
		if (v == -1)break;
		used[v] = true;
		res += mincost[v];

		for (int u = 0; u < V; u++) {
			mincost[u] = min(mincost[u], cost[v][u]);
		}
	}
	return res;
}
*/


/*最小费用最大流*/
/*
struct edge {
	int to, cap, cost, rev;
};
int V;
vector<edge> G[MAX];
int dist[MAX];
int prevv[MAX], preve[MAX];

void add_edge(int from, int to, int cap, int cost) {
	G[from].push_back(edge{ to,cap,cost,G[to].size() });
	G[to].push_back(edge{ from, 0, -cost, G[from].size() - 1 });
}

int min_cost_flow(int s, int t, int f) {
	int res = 0;
	while (f > 0) {
		fill(dist, dist + V, INF);
		dist[s] = 0;
		bool update = true;
		while (update) {
			update = false;
			for (int v = 0; v < V; v++) {
				if (dist[v] == INF)continue;
				for (int i = 0; i < G[v].size(); i++) {
					edge &e = G[v][i];
					if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
						dist[e.to] = dist[v] + e.cost;
						prevv[e.to] = v;
						preve[e.to] = i;
						update = true;
					}
				}
			}
		}

		if (dist[t] == INF) {
			return -1;
		}

		int d = f;
		for (int v = t; v != s; v = prevv[v]) {
			d = min(d, G[prevv[v]][preve[v]].cap);
		}
		f -= d;
		res += d*dist[t];
		for (int v = t; v != s; v = prevv[v]) {
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}
*/

/*最小费用最大流*/
/*
struct Edge {
	int to;
	int vol;
	int cost;
	int next;
};
Edge gEdges[MAX];

int gHead[MAX];
int gPre[MAX];
int gPath[MAX];
int gDist[MAX];

int gEdgeCount;
void InsertEdge(int u, int v, int vol, int cost) {
	gEdges[gEdgeCount].to = v;
	gEdges[gEdgeCount].vol = vol;
	gEdges[gEdgeCount].cost = cost;
	gEdges[gEdgeCount].next = gHead[u];
	gHead[u] = gEdgeCount++;

	gEdges[gEdgeCount].to = u;
	gEdges[gEdgeCount].vol = 0;         //vol为0，表示开始时候，该边的反向不通
	gEdges[gEdgeCount].cost = -cost;    //cost 为正向边的cost相反数，这是为了
	gEdges[gEdgeCount].next = gHead[v];
	gHead[v] = gEdgeCount++;
}

//假设图中不存在负权和环,SPFA算法找到最短路径/从源点s到终点t所经过边的cost之和最小的路径
bool Spfa(int s, int t) {
	memset(gPre, -1, sizeof(gPre));
	memset(gDist, 0x7F, sizeof(gDist));
	gDist[s] = 0;
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()) {//由于不存在负权和环，因此一定会结束
		int u = Q.front();
		Q.pop();

		for (int e = gHead[u]; e != -1; e = gEdges[e].next) {
			int v = gEdges[e].to;
			if (gEdges[e].vol > 0 && gDist[u] + gEdges[e].cost < gDist[v]) {
				gDist[v] = gDist[u] + gEdges[e].cost;
				gPre[v] = u; //前一个点
				gPath[v] = e;//该点连接的前一个边
				Q.push(v);
			}
		}
	}

	if (gPre[t] == -1)  //若终点t没有设置pre，说明不存在到达终点t的路径
		return false;
	return true;
}

int MinCostFlow(int s, int t) {
	int cost = 0;
	int flow = 0;
	while (Spfa(s, t)) {
		int f = INF;
		for (int u = t; u != s; u = gPre[u]) {
			if (gEdges[gPath[u]].vol < f)
				f = gEdges[gPath[u]].vol;
		}
		flow += f;
		cost += gDist[t] * f;
		for (int u = t; u != s; u = gPre[u]) {
			gEdges[gPath[u]].vol -= f;   //正向边容量减少
			gEdges[gPath[u] ^ 1].vol += f; //反向边容量增加
		}
	}
	return cost;
}
*/

/*第k短路模板
//#include<bits/stdc++.h>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int
	Point=1005,
	Edges=100005;
int n,m,start,end,kth;
int dist[Point],times[Point];
bool vis[Point];
struct Edge{
	int to,next,val;
}E[Edges],Eopp[Edges];      //Eopp means Eopposite
int head[Point],head_opp[Point];
struct A_Star_node{
	int p,g,h;
	bool operator < (A_Star_node x)const{
		return x.g+x.h<g+h;
	}
};         //means point  and a_Star:f(x)=g(x)+h(x);
priority_queue<A_Star_node>Q;
inline void add(int Ecnt,int u,int v,int w){
	E[Ecnt].next=head[u];
	E[Ecnt].to=v;
	E[Ecnt].val=w;
	head[u]=Ecnt;
}
inline void add_opposite(int EoppCnt,int u,int v,int w){
	Eopp[EoppCnt].next=head_opp[u];
	Eopp[EoppCnt].to=v;
	Eopp[EoppCnt].val=w;
	head_opp[u]=EoppCnt;
}
void dijkstra(int s,int e){
	memset(vis,0,sizeof(vis));
	memset(dist,127,sizeof(dist));
	int mini;	dist[e]=0;
	for (int i=1;i<=n;i++){
		mini=0;
		for (int j=1;j<=n;j++)
			if (!vis[j] && dist[mini]>dist[j])	mini=j;
		vis[mini]=1;
		for (int x=head_opp[mini];x;x=Eopp[x].next)
			dist[Eopp[x].to]=min(dist[Eopp[x].to],dist[mini]+Eopp[x].val);
	}
}
int A_Star(int s,int e){
	A_Star_node t1,tmp;
	memset(times,0,sizeof(times));
	t1.g=t1.h=0; t1.p=s;
	Q.push(t1);
	while (!Q.empty()){
		t1=Q.top();	Q.pop();
		times[t1.p]++;
		if (times[t1.p]==kth && t1.p==e) return t1.h+t1.g;
		if (times[t1.p]>kth) continue;
		for (int i=head[t1.p];i;i=E[i].next){
			tmp.p=E[i].to;
			tmp.g=dist[E[i].to];
			tmp.h=E[i].val+t1.h;
			Q.push(tmp);
		}
	}
	return -1;
}
int main(){
	n=read(),m=read(),kth=read(),start=read(),end=read();
	int x,y,z;
	memset(head,0,sizeof(head));
	memset(head_opp,0,sizeof(head_opp));
	for (int i=1;i<=m;i++){
		x=read(),y=read(),z=read();
		add(i,x,y,z);
		add_opposite(i,y,x,z);
	}
	dijkstra(start,end);
	if (start==end) kth++;
	int ans=A_Star(start,end);
	if (ans==-1) puts("No");
		else	printf("%d\n",ans);
	return 0;
}

*/