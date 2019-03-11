#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
const int MAX = 10010;

int main() {
	int n;
	cin >> n;
	int x;
	double ans = 0;
	double num[MAX];
	num[0] = 2.0;
	num[1] = 1.0;
	num[2] = 1.0/2;
	num[4] = 1.0/4;
	num[8] = 1.0/8;
	num[16] = 1.0 / 16;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		ans += num[x];
	}
	printf("%.6f\n", ans);
	return 0;
}