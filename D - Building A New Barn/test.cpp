#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX = 10010;
const int INF = 99999999;
int x[MAX];
int y[MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
struct Point {
	int x;
	int y;
}p[MAX];

int main() {
	int n;
	scanf("%d", &n);
	int a, b;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		p[i].x = x[i];
		p[i].y = y[i];
	}
	sort(x+1, x + n+1);
	sort(y+1, y + n+1);
	int min = 0;
	int sum = 0;
	int plan = 0;
	
	if (n % 2 == 1) {
		int temp;
		temp = n / 2 + 1;
		int flag = 0;
		for (int i = 1; i <= n; i++) {
			if (p[i].x == x[temp] && p[i].y == y[temp]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			for (int i = 1; i <= n; i++) {
				sum += abs(x[temp] - p[i].x) + abs(y[temp] - p[i].y);
			}
			min = sum;
			plan = 1;
		}
		else {
			min = INF;
			plan = 0;
			for (int k = 0; k < 4; k++) {
				int xx = x[temp] + dx[k];
				int yy = y[temp] + dy[k];
				sum = 0;
				for (int i = 1; i <= n; i++) {
					sum += abs(xx - p[i].x) + abs(yy - p[i].y);
				}
				if (min > sum) {
					min = sum;
					plan = 1;
				}
				else if (sum == min) {
					plan++;
				}
			}
		}
	}
	else {
		int temp1, temp2;
		temp1 = n / 2;
		temp2 = n / 2 + 1;
		plan = (x[temp2] - x[temp1] + 1)*(y[temp2] - y[temp1] + 1);
		for (int i = 1; i <= n; i++) {
			min += abs(p[i].x - x[temp1]) + abs(p[i].y - y[temp1]);
			int x0 = p[i].x;
			int y0 = p[i].y;
			if (x[temp1] <= x0&&x0 <= x[temp2] && y[temp1] <= y0&&y0 <= y[temp2]) {
				plan--;
			}
		}
	}
	printf("%d %d\n", min, plan);
	return 0;
}

/* 
5
-2 2
2 2
2 0
-2 -2
2 -2
*/