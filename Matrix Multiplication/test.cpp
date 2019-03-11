#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

const int MAX = 25;
int a[MAX][MAX];
int b[MAX][MAX];
int c[MAX][MAX];

int fun(int a[][MAX], int b[][MAX], int m, int n, int p, int q) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < q; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return 0;
}

int main() {
	int tt, count = 1;
	cin >> tt;
	int m, n, p, q;
	while (tt--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		cin >> m >> n >> p >> q;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < q; j++) {
				cin >> b[i][j];
			}
		}
		if (n != p) {
			cout << "Case " << count++ << ":" << endl;
			cout << "ERROR" << endl;
		}
		else {
			fun(a, b, m, n, p, q);
			cout << "Case " << count++ << ":" << endl;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < q; j++) {
					cout << c[i][j] << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}