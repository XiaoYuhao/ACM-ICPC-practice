#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
using namespace std;

const int MAX = 1000010;

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n;
		char z[2];
		char s[MAX];
		scanf("%d %s", &n, z);
		scanf("%s", s);
		int ans = 0;
		int k, now;
		for (int i = 0; i < n; i++) {
			k = abs(int(z[0]) - int(s[i]));
			now = i;
			if (k == 0)continue;
			else {
				break;
			}
		}
		if (k == 0)ans = 1;
		else if (k > 0 && k < 10)ans = (n - now - 1) * 2 + 1;
		else ans = (n - now) * 2;
		printf("%d\n", ans);
	}
	return 0;
}

/*
2
3 z
zMl
6 A
aaaaaa
*/