#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
const int MAX = 1010;
const int MOD = 998244353;

int h[MAX];
int main() {
	long long a = MOD;
	a++;
	a = a / 2;
	a = a * 3;
	a %= MOD;
	cout << a << endl;
	return 0;
}