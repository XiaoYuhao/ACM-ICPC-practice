#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX = 100005;
const int INF = 99999999;

long long bit[MAX + 1];
int n;
void init() {
	memset(bit, 0, sizeof(bit));
}
long long int sum(int i) {
	long long int s = 0;
	while (i > 0) {
		s += bit[i];
		i -= i&-i;
	}
	return s;
}

void add(int i, int x) {
	while (i <= n) {
		bit[i] += x;
		i += i&-i;
	}
}

struct node {
	int num;
	int id;
}a[MAX+1];
int Hash[MAX + 1];

bool camp(node a, node b) {
	return a.num < b.num;
}

int main() {
	int k;
	while (scanf("%d%d", &n, &k) != EOF) {
		memset(a, 0, sizeof(a));
		memset(Hash, 0, sizeof(Hash));
		init();
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i].num);
			a[i].id = i;
		}
		sort(a + 1, a + n + 1, camp);
		int j = 1, cnt = 0;
		a[0].num =-1; //Ï¸½ÚÎÊÌâ
		for (int i = 1; i <= n; i++) {
			if (a[i].num != a[i - 1].num) {
				cnt++;
			}
			Hash[a[i].id] = cnt;
		}
		long long ans = 0;
		for (int j = 0; j < n; j++) {
			ans += j - sum(Hash[j+1]);
			add(Hash[j+1], 1);
		}
		ans -= k;
		if (ans < 0)ans = 0;
		printf("%lld\n", ans);
	}
	return 0;
}