#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 210;
int cost[MAX][MAX];
int vis[MAX];
int mincost[MAX];
int used[MAX][MAX];
int max_edge[MAX][MAX];
int father[MAX];
int mst;
int n;

int prim() {
	for (int i = 0; i < n; i++) {
		mincost[i] = 99999999;
		vis[i] = 0;
		father[i] = 0;
	}
	mincost[0] = 0;
	father[0] = -1;
	int res = 0;

	while (1) {
		int v = -1;
		for (int u = 0; u < n; u++) {
			if (!vis[u] && (v == -1 || mincost[v] > mincost[u])) v = u;
		}
		if (v == -1)break;
		vis[v] = 1;
		res += mincost[v];
		used[v][father[v]] = 0;
		used[father[v]][v] = 0;

		for (int u = 0; u < n; u++) {
			if (vis[u]) {
				max_edge[v][u] = max_edge[u][v] = max(max_edge[u][father[v]], mincost[v]);
			}
			else {
				if (cost[v][u] < mincost[u]) {
					mincost[u] = cost[v][u];
					father[u] = v;
				}
			}
		}
	}
	return res;
}

int second_prim() {
	int ans = 99999999;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (used[i][j])ans = min(ans, mst + cost[i][j] - max_edge[i][j]);
		}
	}
	return ans;
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int e;
		cin >> n >> e;
		int a, b, c;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				cost[i][j] = 99999999;
				used[i][j] = 0;
				max_edge[i][j] = -1;
			}
		}
		for (int i = 0; i < e; i++) {
			cin >> a >> b >> c;
			cost[a - 1][b - 1] = c;
			cost[b - 1][a - 1] = c;
			used[a - 1][b - 1] = 1;
			used[b - 1][a - 1] = 1;
		}
		int mst2;
		mst = prim();
		mst2 = second_prim();
		if (mst == mst2) {
			cout << "Not Unique!" << endl;
		}
		else {
			cout << mst << endl;
		}
	}
	return 0;
}