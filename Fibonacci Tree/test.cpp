#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int MAX = 100010;
const int INF = 0x3f3f3f3f;

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
bool comp1(const edge &e1, const edge &e2) {
	return e1.cost < e2.cost;
}
bool comp2(const edge &e1, const edge &e2) {
	return e1.cost > e2.cost;
}
edge es[MAX];
int V, E;

int kruskal1() {
	sort(es, es + E, comp1);
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
int kruskal2() {
	sort(es, es + E, comp2);
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

bool fibo[MAX];
void init_fibo(int n) {
	for (int i = 0; i < n; i++) {
		fibo[i] = false;
	}
	int k1 = 1, k2 = 2;
	int k3 = 1;
	fibo[k1] = true;
	fibo[k2] = true;
	while (k3 < n) {
		fibo[k3] = true;
		k3 = k1 + k2;
		k1 = k2;
		k2 = k3;		
	}
}

int main() {
	int tt, count = 1;
	scanf("%d", &tt);
	int n, m;
	while (tt--) {
		scanf("%d%d", &n, &m);
		V = n;
		E = 0;
		int a, b, c;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
//			if (c == 1) {
				es[E].u = a;
				es[E].v = b;
				es[E++].cost = c;
//			}
		}
		init_fibo(V);
		
		int ans1 = kruskal1();
		int ans2 = kruskal2();
		bool ff = true;
		for (int i = 1; i <= n; i++) {
			if (find(1) != find(i)) {
				ff = false;
				break;
			}
		}
		if (!ff) {//一开始要判断是否为连通分量
			printf("Case #%d: No\n", count++);
			continue;
		}
		int flag = 0;
		for (int i = ans1; i <= ans2; i++) {
			if (fibo[i]) {
				printf("Case #%d: Yes\n", count++);
				flag = 1;
				break;
			}
		}
		if(flag==0) {
			printf("Case #%d: No\n", count++);
		}
	}
	return 0;
}