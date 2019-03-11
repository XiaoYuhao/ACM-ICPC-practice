#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;
typedef long long ll;
#define scand1(e) scanf("%d",&e)
#define scanl1(e) scanf("%I64d",&e)
#define scand2(e1,e2) scanf("%d%d",&e1,&e2)
#define scanl2(e1,e2) scanf("%I64d%I64d",&e1,&e2)
#define maxn 500
#define maxk 500
#define INF 0x3f3f3f3f
const ll mod = 1000000007;
ll divMod(char* ch)
{
	ll s = 0;
	for (int i = 0; ch[i] != '\0'; i++)
		s = (s * 10 + ch[i] - '0') % (mod - 1);
	return s;
}
ll pow(ll x, ll n, ll mod)
{
	ll res = 1;
	while (n>0)
	{
		if (n % 2 == 1)
		{
			res = res*x;
			res = res%mod;
		}
		x = x*x;
		x = x%mod;
		n >>= 1;
	}
	return res;
}

char ch[100010];
int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%s", ch);
		ll bi = divMod(ch);
		bi = (bi - 1 + (mod - 1)) % (mod - 1);
		printf("%lld\n", pow(2, bi, mod));
	}
	return 0;
}