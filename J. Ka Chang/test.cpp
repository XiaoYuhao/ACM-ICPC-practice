#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;
const int MAX = 100010;

struct Node {
	int p;
	int par;
	int len;
}node[MAX];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int x, y;
	node[1].par = 0;
	node[1].len = 0;
	node[1].p = 0;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		node[y].par = x;
		node[y].p = 0;
	}
	vector<int> vec[50000];
	for (int i = 1; i <= n; i++) {
		int len = 0;
		int k = node[i].par;
		while (k) {
			k = node[k].par;
			len++;
		}
		node[i].len = len;
		vec[len].push_back(i);
	}

	int op, L, X;
	for (int i = 0; i < m; i++) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &L, &X);
			for (int j = 0; j < vec[L].size(); j++) {
				int k = vec[L][j];
				while (k) {
					node[k].p += X;
					k = node[k].par;
				}
			}
		}
		else if (op == 2) {
			scanf("%d", &X);
			printf("%d\n", node[X].p);
		}
	}
	return 0;
}

