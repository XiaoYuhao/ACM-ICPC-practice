#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;

const int MAX = 200010;
vector<int> edge[MAX];
vector<int> point;

int num[MAX];


int n, k;
int nn = 0;
int ans;

void dfs(int u,int fa) {
	num[u] = 1;
	for (int i = 0; i < edge[u].size(); i++) {
		int v = edge[u][i];
		if (v == fa)continue;
		dfs(v, u);
		num[u] += num[v];
		if (num[v] >= k&&n - num[v] >= k)ans++;
	}
}



int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d %d", &n, &k);
		int x, y;
		nn = 0;
		memset(num, 0, sizeof(num));
		for (int i = 0; i <=n; i++) {
			edge[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			scanf("%d%d", &x, &y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		ans = 0;
		dfs(1, -1);
		printf("%d\n", ans);
	}
	return 0;
}