#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX = 100000000;
char c[MAX];

void dfs(int i, int j) {
	if (i == j-1) {
		cout << c << endl;
	}
	else {
		for (int k = i; k < j; k++) {
			swap(c[i], c[k]);
			dfs(i + 1, j);
			swap(c[i], c[k]);
		}
	}
}
bool cmap(char &a, char &b) {
	int k;
	double as, bs;
	k = 'a' - 'A';
	if (a >= 'A'&&a <= 'Z') {
		as = double(a);
	}
	else if (a >= 'a'&&a <= 'z') {
		as = double(a) - k + 0.5;
	}
	if (b >= 'A'&&b <= 'Z') {
		bs = double(b);
	}
	else if (b >= 'a'&&b <= 'z') {
		bs = double(b) - k + 0.5;
	}
	return as < bs;
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		cin >> c;
		int len;
		len = strlen(c);
		sort(c, c + len, cmap);
//		dfs(0, len - 1);
		while (next_permutation(c, c + len,cmap)) {}
		do {
			cout << c << endl;
		} while (next_permutation(c, c + len,cmap));
	}
/*	char a, b;
	cin >> a >> b;
	cout << cmap(a, b) << endl;
	cin >> c;
	int len = strlen(c);
	sort(c, c + len, cmap);
	cout << c << endl;
	cin >> c;
	int len = strlen(c);
	dfs(0, len);*/
	return 0;
}