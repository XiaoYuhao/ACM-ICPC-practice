#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<vector>
using namespace std;

const int MAX = 100010;
const int MAXK = 2000100;
int a[MAX];
int flag[MAXK];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		flag[a[i]]++;
	}
	int x, y;
	for (int i = 1; i <= n; i++) {
		x = a[i];
		y = 0;
		for (int j = i + 1; j <= n; j++) {
			x = x | a[j];
			y = y | a[j];
			flag[x]++;
			if (x == y)break;
		}
	}
	int ans = 0;
	for (int i = 0; i <= MAXK; i++) {
		if (flag[i])ans++;
	}
	printf("%d\n", ans);
	return 0;
}