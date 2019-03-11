#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAX = 1000;

int prime[MAX];
bool is_prime[MAX + 1];

int sieve(int n) {
	int p = 0;
	for (int i = 0; i <= n; i++) {
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			prime[p++] = i;
			for (int j = 2 * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
	return p;
}

int main() {
	int n;
	while (cin >> n) {
		int num = 0;
		memset(prime, 0, sizeof(prime));
		memset(is_prime, 0, sizeof(is_prime));
		num = sieve(n);
		int ans = 0;
		for (int i = 0; i < num; i++) {
			for (int j = i; j < num; j++) {
				if (prime[i] + prime[j] == n)ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}