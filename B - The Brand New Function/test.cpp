#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
#include<stdio.h>
#include<set>
const int MAXN = 100005;
int board[MAXN];
set<int> S;

int main() {
	int N;
	scanf("%d", &N);
	S.clear();
	for (int i = 0; i < N; i++) {
		scanf("%d", &board[i]);
	}
	for (int i = 0; i < N; i++) {
		int a = board[i];
		int b = 0;
		S.insert(a);
		for (int j = i + 1; j < N; j++) {
			a |= board[j];
			b |= board[j];
			S.insert(a);
			if (a == b)break;
		}
	}
	printf("%d\n", S.size());

	return 0;
}