#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 30010;

int par[MAX];
int deep[MAX];
int num[MAX];

void init() {
	for (int i = 0; i<MAX; i++) {
		par[i] = i;
		deep[i] = 1;
		num[i] = 0;
	}
}
int find(int x) {
	if (x == par[x]) {
		return x;
	}
	else {
		int temp;
		temp = par[x];
		par[x] = find(par[x]);
		num[x] += num[temp];
		return par[x];
	}
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	par[x] = y;
	num[x] = deep[y];
	deep[y] += deep[x];
	deep[x] = 0;
}


int main() {
	int p;
	cin >> p;
	char ch;
	int x, y;
	init();
	while (p--) {
		cin >> ch;
		if (ch == 'M') {
			cin >> x >> y;
			unite(x, y);
		}
		else if (ch == 'C') {
			cin >> x;
			find(x);
			cout << num[x] << endl;
		}
	}
	return 0;
}
/*
6
M 1 2
M 1 3
M 1 4
M 1 5
M 1 6
C 1
*/