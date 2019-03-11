#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAX = 50;
int card1[MAX][MAX];
int card2[MAX][MAX];
int n;

void turn(int card1[][MAX]) {
	int temp[MAX][MAX];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[j][n - i-1] = card1[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			card1[i][j] = temp[i][j];
		}
	}
}

int fun(int a[][MAX], int b[][MAX]) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == b[i][j]) {
				res++;
			}
		}
	}
	return res;
}

int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0)break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &card1[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &card2[i][j]);
			}
		}
		int ans = 0;
		ans = max(ans, fun(card1, card2));
		turn(card1);
		ans = max(ans, fun(card1, card2));
		turn(card1);
		ans = max(ans, fun(card1, card2));
		turn(card1);
		ans = max(ans, fun(card1, card2));
		printf("%d\n", ans);
	}
	return 0;
}