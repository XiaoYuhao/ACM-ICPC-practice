#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<queue>
const int MAX = 200005;
int a[MAX], b[MAX];
using namespace std;

vector<int> e[MAX];
queue<int> q, ans;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int v, u;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &v, &u);
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int flag = 0, k;
	while (1) {
		flag = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i] == b[i]) {
				k = i;
				q.push(k);
				flag = 0;
			}
		}
		if (flag)break;
		while (!q.empty()) {
			k = q.front();
			q.pop();
			ans.push(k);
			b[k]++;
			for (int i = 0; i < e[k].size(); i++) {
				int j = e[k][i];
				b[j]++;
			}
		}
	}
	printf("%d\n", ans.size());
	while (!ans.empty()) {
		printf("%d ", ans.front());
		ans.pop();
	}
	printf("\n");
	return 0;
}