#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX = 100010;
const int INF = 0x3f3f3f3f;

int fa[MAX], total[MAX], a[MAX];
struct edge {
	int x, y;
	long long v;
}e[MAX];

void init(int n) {
	for (int i = 0; i <= n; i++) {
		fa[i] = i;
		total[i] = 1;
	}
}

int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	else return fa[x] = find(fa[x]);
}

bool cmp(const edge &a, const edge &b) {
	return a.v > b.v;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	init(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &e[i].x, &e[i].y);
		e[i].v = min(a[e[i].x], a[e[i].y]);
	}
	sort(e, e + m, cmp);
	int x, y, v;
	double sum = 0;
	for (int i = 0; i < m; i++) {
		x = find(e[i].x);
		y = find(e[i].y);
		v = e[i].v;
		if (x==y)continue;
		sum += (double)total[x] * total[y] * v;
		fa[y] = x;
		total[x] += total[y];
		total[y] = 1;
	}
	double ans = (sum*2.0) / (1.0*n*(n - 1));
	printf("%.6f\n", ans);
	return 0;
}