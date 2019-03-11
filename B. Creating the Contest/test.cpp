#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX = 200010;
int a[MAX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = 0;
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] * 2 >= a[i + 1]) {
			cnt++;
			if (ans < cnt) {
				ans = cnt;
			}
		}
		else {
			cnt = 0;
		}
		
	}
	ans++;
	printf("%d\n", ans);
	return 0;
}