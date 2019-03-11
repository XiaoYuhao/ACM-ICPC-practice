#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define ls (r<<1)
#define rs (r<<1|1)
#define debug(a) cout << #a << " " << a << endl
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 10;
const ll mod = 2e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-8;
ll f(vector<ll> e) {
	ll sz = e.size(), ans = 0;
	set<ll> s;
	for (ll i = sz - 1; i >= 0; i--) {
		set<ll>::iterator it = s.lower_bound(e[i]);
		if (it == s.begin()) {
			ans += e[i];
		}
		else {
			it--;
			ans += e[i] - *it;
		}
		s.insert(e[i]);
	}
	return ans;
}
int main() {
	ll x, y, n;
	vector<ll> e1, e2;
	scanf("%lld", &n);
	while (n--) {
		scanf("%lld%lld", &x, &y);
		e1.push_back(x), e2.push_back(y);
	}
	printf("%lld\n", f(e1) + f(e2));
	return 0;
}