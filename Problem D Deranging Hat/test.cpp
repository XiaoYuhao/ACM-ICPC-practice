#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

const int MAX = 1010;
char s[MAX];
vector <pair< int, int >> sque;

void mysort(int len) {
	for (int i = 0; i < len; i++) {
		int k = i;
		char ch = s[i];
		for (int j = i + 1; j < len; j++) {
			if (s[j] < ch) {
				k = j;
				ch = s[j];
			}
		}
		if (i != k) {
			swap(s[i], s[k]);
			sque.push_back(make_pair(k + 1, i + 1));
		}
	}
}

int main() {
	scanf("%s", s);
	int len = strlen(s);
	mysort(len);
	for (int i = sque.size() - 1; i >= 0; i--) {
		printf("%d %d\n", sque[i].first, sque[i].second);
	}
	return 0;
}