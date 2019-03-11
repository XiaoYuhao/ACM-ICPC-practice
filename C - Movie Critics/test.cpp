#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstring>
using namespace std;

const int MAX = 100010;
int nn[MAX];
int kk[MAX];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	memset(nn, 0, sizeof(nn));
	memset(kk, 0, sizeof(kk));
	int temp;
	int j = 1;
	nn[0] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (temp != nn[j - 1]) {
			nn[j++] = temp;
		}
	}
	nn[j] = 0;
	for (int i = 1; i <j; i++) {
		if (nn[i - 1] == nn[i + 1])kk[nn[i]] += 2;
		else kk[nn[i]] += 1;
	}
	int maxk = 1;
	for (int i = 1; i <= k; i++) {
		if (kk[i] > kk[maxk])maxk = i;
	}
	printf("%d\n", maxk);
	return 0;
}