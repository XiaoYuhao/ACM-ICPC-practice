#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N = 20010;
int par[MAX_N];
int length[MAX_N];

void init(int n) {
	for (int i = 0; i <= n; i++) {
		par[i] = i;
		length[i] = 0;
	}
}
int find(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}
int updateLen(int x) {
	int i = x;
	length[x] = 0;
	while (i != par[i]) {
		length[x] += (abs(i - par[i]) % 1000);
		i = par[i];
	}
	return length[x];
}
void unite(int x, int y) {
	if (x == y)return;
	par[x] = y;
	return;
}
bool same(int x, int y) {
	return find(x) == find(y);
}
int main() {
	int tt;
	cin >> tt;
	
	while (tt--) {
		int n;
		cin >> n;
		char ch;
		int I, J;
		init(n);
		while (1) {		
			cin >> ch;
			if (ch == 'E') {
				cin >> I;
				cout << updateLen(I) << endl;
			}
			else if (ch == 'I') {
				cin >> I >> J;
				unite(I, J);
			}
			else if (ch == 'O') {
				break;
			}
		}
	}
	return 0;
}