#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int MAX = 1010;
int map[MAX][MAX];

int main() {
	int n;
	scanf("%d", &n);
	int x, y;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1) {
				x = i;
				y = j;
			}
		}
	}
	int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0, ans = 0;
	if (x > 1 && x < n&&y>1 && y < n) {
		ans = map[x - 1][y] + map[x][y + 1] - map[x - 1][y + 1];
	}
	else if (x > 1 && x < n&&y==1) {
		y = y + 1;
		ans = map[x - 1][y-1] + map[x][y + 1] - map[x - 1][y + 1];
	}
	else if (x > 1 && x < n&&y == n) {
		y = y - 1;
		ans = map[x][y] + map[x - 1][y + 1] - map[x - 1][y];
	}
	else if (x == 1 && y > 1 && y < n) {
		x = x + 1;
		ans = map[x][y] + map[x - 1][y + 1] - map[x][y + 1];
	}
	else if (x == n && y > 1 && y < n) {
		x = x - 1;
		ans = map[x + 1][y - 1] + map[x - 1][y] - map[x - 1][y - 1];
	}
	else if (x == 1 && y == 1) {
		x = x + 1;
		y = y + 1;
		ans = map[x + 1][y - 1] + map[x - 1][y] - map[x + 1][y];
	}
	else if (x == 1 && y == n) {
		x = x + 1;
		y = y - 1;
		ans = map[x - 1][y] + map[x][y + 1] - map[x][y];
	}
	else if (x == n&&y == 1) {
		x = x - 1;
		y = y + 1;
		ans = map[x + 1][y] + map[x - 1][y - 1] - map[x - 1][y];
	}
	else if (x == n&&y == n) {
		x = x - 1;
		y = y - 1;
		ans = map[x - 1][y + 1] + map[x + 1][y] - map[x - 1][y];
	}
	printf("%d\n", ans);
	return 0;
}