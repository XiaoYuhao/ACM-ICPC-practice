#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

const int MAX = 200010;
const int MAX_N = 25;

struct Day {
	int h;
	int t;
	int r;
	int len;
}d[MAX_N];
int flag[MAX][MAX_N];

int main() {
	int n;
	scanf("%d", &n);
	int maxh = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &d[i].h, &d[i].r, &d[i].t);
		d[i].len = d[i].h;
		maxh = max(d[i].h, maxh);
	}

	for (int i = 0; i < 1825 * maxh; i++) {
		for (int j = 1; j <= n; j++) {
			if (i > d[j].h - 1) {
				d[j].r += d[j].len;
				d[j].t += d[j].len;
				d[j].h += d[j].len;
			}
			if (d[j].r < d[j].t) {
				if (i > d[j].r&&i < d[j].t) {
					flag[i][j] = 0;
				}
				else {
					flag[i][j] = 1;
				}
			}
			else {
				if (i >= d[j].t&&i <= d[j].r) {
					flag[i][j] = 1;
				}
				else {
					flag[i][j] = 0;
				}
			}
		}
	}
	int ans = -1;
	for (int i = 0; i < 1825 * maxh; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (flag[i][j])sum++;
		}
		if (sum >= n) {
			ans = i;
			break;
		}
	}
	if (ans != -1) {
		printf("%d\n", ans);
	}
	else {
		printf("impossible\n");
	}
	return 0;
}