#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int MAX = 1010;
const int MAX_E = 20010;
const int INF = 99999999;
struct edge {
	int from;
	int to;
	int cost;
};

edge es[MAX_E];
int d[MAX];
int V, E;

int short_path(int s) {
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
	if (d[V - 1] == INF) {
		return -2;
	}
	else return d[V - 1];
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

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);
		V = n;
		E = x + y;
		int a, b, c;
		for (int i = 0; i < x; i++) {
			scanf("%d%d%d", &a, &b, &c);
			es[i].from = a - 1;
			es[i].to = b - 1;
			es[i].cost = c;
		}
		for (int i = x; i < E; i++) {
			scanf("%d%d%d", &a, &b, &c);
			es[i].from = b - 1;
			es[i].to = a - 1;
			es[i].cost = -c;
		}
		if (find_negative_loop()) {
			printf("-1\n");
		}
		else {
			printf("%d\n", short_path(0));
		}
	}
	return 0;
}