#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

const int N = 2;
const int mod = 10000;
int tmp[N][N];
void multi(int a[][N], int b[][N], int n) {
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				tmp[i][j] += (a[i][k] * b[k][j]) % mod;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}
int res[N][N];
void Pow(int a[][N], int n) {
	memset(res, 0, sizeof(res));
	for (int i = 0; i < N; i++)res[i][i] = 1;
	while (n) {
		if (n & 1) multi(res, a, N);
		multi(a, a, N);
		n >>= 1;
	}
}
int main() {
	int n;
	while (cin >> n) {
		if (n == -1)break;
		if (n == 0) {
			cout << 0 << endl;
			continue;
		}
		int t[2][2];
		t[0][0] = 1;
		t[0][1] = 1;
		t[1][0] = 1;
		t[1][1] = 0;
		Pow(t, n - 1);
		int ans = res[0][0] % mod;
		cout << ans << endl;
	}
	return 0;
}