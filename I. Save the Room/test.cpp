#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main() {
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) != EOF) {
		int v = a*b*c;
		if (v % 2 == 0) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}