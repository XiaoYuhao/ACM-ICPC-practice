#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX = 10010;
int dp[MAX];
int x[MAX];
struct E {
	int h;
	int w;
	int no;
}e[MAX];


bool cmap(E a, E b) {
	return a.w == b.w ? a.h<b.h : a.w<b.w;
}
int main() {
	int n, ch, cw;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		scanf("%d%d", &e[i].w, &e[i].h);
		e[i].no = i;
	}
	sort(e+1, e + n + 1, cmap);
	
/*	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (e[i].h > e[j].h&&e[i].w > e[j].w) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					x[i] = j;
				}
			}
		}
	}
	printf("%d\n", dp[n]);
	for (int i = 0; x[i]; i=x[i]) 
		printf("%d ", e[x[i]].no);*/

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j <= n; j++) {
			if (e[i].w < e[j].w&&e[i].h < e[j].h) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					x[i] = j;
				}
			}
		}
	}
	printf("%d\n", dp[0]-1);
	for (int i = 0; x[i]; i = x[i]) {
		printf("%d ", e[x[i]].no);
	}
	printf("\n");
	return 0;
}