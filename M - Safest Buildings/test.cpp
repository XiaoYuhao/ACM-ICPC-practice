#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
const int MAX = 5010;

struct point {
	int x, y, no;
	double length;
}P[MAX];

bool cmp(point a, point b) {
	return a.length < b.length;
}

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n, R, r;
		scanf("%d%d%d", &n, &R, &r);
		memset(P, 0, sizeof(P));
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &P[i].x, &P[i].y);
			P[i].length = abs(r - sqrt(P[i].x*P[i].x + P[i].y*P[i].y));
			P[i].no = i + 1;
		}
		sort(P, P + n, cmp);
		double min = P[0].length;
		int num = 0;
/*		if (min > R + r) {
			printf("0\n");
			continue;
		}*/
		for (int i = 0; i < n; i++) {
			if (min == P[i].length) {
				num++;
			}
			else break;
		}
		printf("%d\n", num);
		for (int i = 0; i < num; i++) {
			if (i == num - 1) {
				printf("%d\n", P[i].no);
			}
			else printf("%d ", P[i].no);	
		}
	}
	return 0;
}

/*
2
3 10 5
3 4
3 5
3 6
3 10 4
-7 -6
4 5
5 4
3 5 2
0 1
0 3
3 0
*/