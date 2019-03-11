#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

typedef long long ll;
const int MAX = 100;
const int MOD = 1;

/*
//素性测试，假设输入都是正数
bool is_prime(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}

//约数枚举
vector<int> divisor(int n) {
	vector<int> res;
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			res.push_back(i);
			if (i != n / i)res.push_back(n / i);
		}
	}
	return res;
}

//整数分解
map<int, int> prime_factor(int n) {
	map<int, int> res;
	for (int i = 2; i*i <= n; i++) {
		while (n%i == 0) {
			++res[i];
			n /= i;
		}
	}
	if (n != 1)res[n] = 1;
	return res;
}
*/
//筛法素数打表,返回n以内素数的个数
/*
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
*/

/* 快速幂运算 */
/*
ll pow(ll x, ll n) {
	ll res = 1;
	while (n > 1) {
		if (n & 1)res = res*x;
		x = x*x;
		n >>= 1;
	}
	return res;
}
*/

/* 矩阵快速幂 */
/*
const int N = 10;
int tmp[N][N];
void multi(int a[][N], int b[][N], int n) {
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				tmp[i][j] = a[i][k] * b[k][j];
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
*/

/*
#include<cstdio>
const int N = 200000 + 5;
const int MOD = (int)1e9 + 7;
int F[N], Finv[N], inv[N];//F是阶乘，Finv是逆元的阶乘
void init() {
	inv[1] = 1;
	for (int i = 2; i < N; i++) {
		inv[i] = (MOD - MOD / i) * 1ll * inv[MOD % i] % MOD;
	}
	F[0] = Finv[0] = 1;
	for (int i = 1; i < N; i++) {
		F[i] = F[i - 1] * 1ll * i % MOD;
		Finv[i] = Finv[i - 1] * 1ll * inv[i] % MOD;
	}
}
int comb(int n, int m) {//comb(n, m)就是C(n, m)
	if (m < 0 || m > n) return 0;
	return F[n] * 1ll * Finv[n - m] % MOD * Finv[m] % MOD;
}
int main() {
	init();
}
*/

/*
辗转相除法求最大公约数
int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
*/

/* 扩展欧几里得算法
int extgcd(int a, int b, int &x, int &y) {
	int d = a;
	if (b != 0) {
		d = extgcd(b, a%b, y, x);
		y -= (a / b)*x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}

// 求逆元
int mod_inverse(int a, int m) {
	int x, y;
	extgcd(a, m, x, y);
	return (m + x%m) % m;
}
*/

//素数筛选和合数分解
/*
int prime[MAX + 1];
void getPrime()
{
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= MAX; i++)
	{
		if (!prime[i])prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && prime[j] <= MAX / i; j++)
		{
			prime[prime[j] * i] = 1;
			if (i%prime[j] == 0) break;
		}
	}
}
long long factor[100][2];
int fatCnt;
int getFactors(long long x)
{
	fatCnt = 0;
	long long tmp = x;
	for (int i = 1; prime[i] <= tmp / prime[i]; i++)
	{
		factor[fatCnt][1] = 0;
		if (tmp%prime[i] == 0)
		{
			factor[fatCnt][0] = prime[i];
			while (tmp%prime[i] == 0)
			{
				factor[fatCnt][1]++;
				tmp /= prime[i];
			}
			fatCnt++;
		}
	}
	if (tmp != 1)
	{
		factor[fatCnt][0] = tmp;
		factor[fatCnt++][1] = 1;
	}
	return fatCnt;
}
*/
/*
//快速模幂运算
long long pow_m(long long a, long long n)
{
	long long res = 1;
	long long tmp = a%MOD;
	while (n)
	{
		if (n & 1) { res *= tmp; res %= MOD; }
		n >>= 1;
		tmp *= tmp;
		tmp %= MOD;
	}
	return res;
}
*/

/*求大数组合数--卢卡斯定理*/
/*
typedef long long LL;
const int mod = 1e9 + 7;

LL power_mod(LL a, LL b)
{
	LL base = a%mod;
	a = a%mod;
	LL res = 1LL;
	while (b)
	{
		if (b & 1)
			res = base*res%mod;
		base = base*base%mod;
		b = b >> 1;
	}
	return res%mod;
}

LL C(LL n, LL m)
{
	if (m > n) return 0;
	LL ans = 1;
	for (int i = 1; i <= m; i++)
	{
		LL a = (n + i - m) % mod;
		LL b = i % mod;
		ans = ans * (a * power_mod(b, mod - 2) % mod) % mod;
	}
	return ans;
}

LL Lucas(LL n, LL m)
{
	if (m == 0) return 1;
	return C(n % mod, m % mod) * Lucas(n / mod, m / mod) % mod;
}
*/

