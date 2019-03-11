#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<algorithm>

const int MAX = 100010;
using namespace std;

int a[MAX];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int k = 2;
	int ans1, ans2, flag = 0;
	while (a[k] == a[1]) {
		k++;
	}
	if (a[k] > a[1]) {
		for (int i = k; i < n; i++) {
			if (a[i + 1] < a[i]) {
				flag = 1;
				ans1 = i;
				ans2 = i + 1;
				break;
			}
		}
	}
	if (a[k] < a[1]) {
		for (int i = k; i < n; i++) {
			if (a[i + 1] > a[i]) {
				flag = 1;
				ans1 = i;
				ans2 = i + 1;
				break;
			}
		}
	}
	if (!flag) {
		printf("0\n");
	}
	else {
		printf("3\n");
		printf("%d %d %d\n", 1, ans1, ans2);
	}
	return 0;
}