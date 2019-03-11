#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;

const int MOD = 1000000007;
const int MAX = 50000;

long long int gcd(long long int a, long long int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}

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

int main() {
	int n, m;
	getPrime();
	while (scanf("%d%d", &n, &m) != EOF) {

		fatCnt = 0;
		memset(factor, 0, sizeof(factor));
		fatCnt = getFactors(m);

		long long ans = 0;
		for (long long int i = 1; i <= n; i++) {
			int flag = 0;
			for (int j = 0; j < fatCnt; j++) {
				if (factor[j][0] % i == 0 || i %factor[j][0] == 0) {
					flag = 1;
					break;
				}
			}
			if (flag)continue;
			ans = (ans + (i + 1)*i) % MOD;
			
		}
		if(m!=1)ans = (ans + 2) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}