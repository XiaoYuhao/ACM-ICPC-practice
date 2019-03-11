#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
#include<queue>
#include<cstdio>
#include<vector>
#include<functional>
const int MAX = 50000;
int a[MAX];
int u[MAX];


int main() {
	int num;
	scanf("%d", &num);
	while (num--) {
		priority_queue<int, vector<int>, less<int> > q1;
		priority_queue<int, vector<int>, greater<int> > q2;
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", &u[i]);
		}
		q1.push(0x7fffffff);
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < q1.top()) {
				q1.push(a[i]);
				q2.push(q1.top());
				q1.pop();
			}
			else q2.push(a[i]);
			for (; j < m&&u[j] <= i+1; j++) {
				printf("%d\n", q1.top());
				q1.push(q2.top());
				q2.pop();
			}
		}
		if (num > 0) {
			printf("\n");
		}
	}
	return 0;
}

/*
2

7 4
3 1 -4 2 8 -1000 2
1 2 6 6

7 4
3 1 -4 2 8 -1000 2
1 2 6 6
*/