#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<random>
using namespace std;

const int MAX = 10010;
int x[MAX], y[MAX];

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n;
		double k;
		scanf("%d%lf", &n, &k);
		int flag = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x[i], &y[i]);
		}
		for (int i = 0; i < 200; i++) {
			int a, b;
			a = rand() % n;
			b = rand() % n;
			if (a == b)continue;
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if ((y[j] - y[a])*(x[j] - x[b]) == (y[j] - y[b])*(x[j] - x[a])) {
					cnt++;
				}
				if (cnt >= n*k) {
					flag = 1;
					break;
				}
			}
			if (flag == 1)break;
		}
		if (flag == 1)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}