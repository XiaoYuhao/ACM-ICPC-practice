#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstring>
using namespace std;

const int MAX = 100010;
const int MAX_N = 505;
const int INF = 99999999;
struct Change {
	char a;
	char b;
	int cost;
}change[MAX_N];

char s[MAX];
char t[MAX];
char h[MAX];

int d[26][26];
int V;

void warshall_floyd() {
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

bool camp(Change a, Change b) {
	return a.cost < b.cost;
}


int main() {
	int n;
	scanf("%s", &s);
	scanf("%s", &t);
	scanf("%d", &n);

	char a[2], b[2];
	int c;
	int aa, bb, cc;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			d[i][j] = INF;
			if (i == j) {
				d[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%s%s%d", &a, &b, &c);
		aa = a[0] - 'a';
		bb = b[0] - 'a';
		if (d[aa][bb] > c) {
			d[aa][bb] = c;
		}
	}
	//	sort(change, change + n, camp);
	int lens = strlen(s);
	int lent = strlen(t);
	if (lens != lent) {
		printf("-1\n");
		return 0;
	}
	if (strcmp(s, t) == 0) {
		printf("0\n");
		printf("%s\n", s);
		return 0;
	}
	V = 26;
	warshall_floyd();
	int cost_sum = 0;
	int flag = 0;
	for (int i = 0; i < lens; i++) {
		if (s[i] != t[i]) {
			int min = 99999999;
			int index;
			for (int j = 0; j < 26; j++) {
				if (min > d[s[i] - 'a'][j] + d[t[i] - 'a'][j]) {
					min = d[s[i] - 'a'][j] + d[t[i] - 'a'][j];
					index = j;
				}
			}
			h[i] = index + 'a';
			cost_sum += min;
/*			if (d[s[i] - 'a'][t[i] - 'a'] >= d[t[i] - 'a'][s[i] - 'a']) {
				cost_sum += d[t[i] - 'a'][s[i] - 'a'];
				t[i] = s[i];
			}
			else {
				cost_sum += d[s[i] - 'a'][t[i] - 'a'];
				s[i] = t[i];
			}
*/

		}
		else {
			h[i] = s[i];
		}
	}
	if (cost_sum >= INF) {
		printf("-1\n");
	}
	else {
		printf("%d\n", cost_sum);
		for (int i = 0; i < lens; i++) {
			printf("%c", h[i]);
		}
		printf("\n");
	}
	return 0;
}