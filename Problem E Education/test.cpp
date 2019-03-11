#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
const int MAX=5010;

struct Build {
	int p;
	int r;
	int id;
}b[MAX];
int dep[MAX];

bool cmp(Build a, Build b) {
	if (a.p == b.p) {
		return a.r < b.r;
	}
	else return a.p < b.p;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dep[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i].p);
		b[i].id = i;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i].r);
	}
	for (int i = 1; i <= n; i++) {

	}
}