#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX = 100010;
int a[MAX];
int dp[MAX][4];
int ans[MAX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
	}
	dp[1][1] = a[1];
	dp[1][2] = a[1];
/*	dp[2][1] = a[2];
	dp[2][2] = a[1];*/
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (j == 1) {
				if (dp[i][0] < dp[j][0] + 1) {
					dp[i][0] = dp[j][0] + 1;
					dp[i][1] = a[i];
					dp[i][2] = a[j];
					dp[i][3] = j;
				}
			}
			else if (dp[j][1] > dp[j][2] && a[i] < a[j]) {
				if (dp[i][0] < dp[j][0] + 1) {
					dp[i][0] = dp[j][0] + 1;
					dp[i][1] = a[i];
					dp[i][2] = a[j];
					dp[i][3] = j;
				}
			}
			else if (dp[j][1]<dp[j][2] && a[i]>a[j]) {
				if (dp[i][0] < dp[j][0] + 1) {
					dp[i][0] = dp[j][0] + 1;
					dp[i][1] = a[i];
					dp[i][2] = a[j];
					dp[i][3] = j;
				}
			}
		}
	}
	int maxx = 0, k, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i][0]>maxx) {
			maxx = dp[i][0];
			k = i;
		}
	}
	while (1) {
		ans[cnt++] = k;
		k = dp[k][3];
		if (!k)break;
	}
	if (maxx > 2) {
		printf("3\n");
		for (int i = cnt - 1; i >=cnt-3; i--) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	else printf("0\n");
	return 0;
}