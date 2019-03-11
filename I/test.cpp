#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
const int MAX = 100;

int a[MAX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int sum;
	scanf("%d", &sum);
	int min = 0x3f3f3f3f;
	int ans;
	for (int i = 0; i < n; i++) {
		int mod = sum%a[i];
		if (mod < min) {
			min = mod;
			ans = a[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}