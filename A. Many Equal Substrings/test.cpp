#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;

const int MAX = 60;
char s[MAX], t[MAX];
char ss[MAX];
char tt[MAX];
char temp[MAX];
char sss[MAX];
char ttt[MAX];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", t);
	int pl = 0, pr = n - 1;
	int cnt = 0;
	int flag = 0;
	while (pl < n&&pr>0) {
		temp[0] = t[pl];
		strcat(ss, temp);
		strcpy(tt, &t[pr]);
		if (strcmp(ss, tt) == 0) {
			strcpy(sss, ss);
			strcpy(ttt, tt);
			cnt = pl;
			flag = 1;
		}
		pl++;
		pr--;
	}
	if (!flag) {
		for (int i = 0; i < k; i++) {
			printf("%s", t);
		}
		printf("\n");
	}
	else {
		printf("%s", sss);
		int kk = 0;
		for (int i = cnt+1; i < n; i++) {
			tt[kk++] = t[i];
		}
		tt[kk] = '\0';
		for (int i = 0; i < k; i++) {
			printf("%s", tt);
		}
		printf("\n");
	}
	return 0;
}