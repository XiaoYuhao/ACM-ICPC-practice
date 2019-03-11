#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;

const int MAX = 100005;
char s[MAX];
int num[30];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	if (n == 1) {
		printf("Yes\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		num[s[i] - 'a']++;
		if (num[s[i] - 'a'] >= 2) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}