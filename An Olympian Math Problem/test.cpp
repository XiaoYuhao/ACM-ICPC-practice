#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

int dfs(int n) {
	if (n == 1) {
		return 1;
	}
	else return n*dfs(n - 1);
}

int main() {
	int tt;
	scanf("%d", &tt);
	long long n;
	while (tt--) {
		scanf("%lld", &n);
		printf("%lld\n", n - 1);
	}
	return 0;
}