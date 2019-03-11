#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX = 100005;
int a[MAX];


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (n < 3) {
		printf("0\n");
		return 0;
	}
	int b = 1;
	int c, d;
	int flag = 0;
	while (a[1] == a[b] && b <= n)b++;
	if (a[b] > a[1]) {
		for (int i = b+1; i <= n; i++) {
			if (a[i] < a[i-1]) {
				flag = 1;
				c = i-1;
				d = i;
				break;
			}
		}
	}
	else {
		for (int i = b + 1; i <= n; i++) {
			if (a[i] > a[i-1]) {
				flag = 1;
				c = i-1;
				d = i;
				break;
			}
		}
	}
	if (!flag) {
		printf("0\n");
	}
	else {
		printf("3\n");
		printf("%d %d %d\n", 1, c, d);
	}
	return 0;
}