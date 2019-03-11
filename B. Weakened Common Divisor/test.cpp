#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<vector>
#include<functional>
#include<string.h>
using namespace std;

const int MAXN = 150005;
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
long long factors[100];
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
	getPrime();
	int n, m;
	scanf("%d", &n);
	long long int a, b;
	long long c, d;
	map<int, int> mapint;
	map<int, int> mapi;
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &a, &b);
		memset(factor, 0, sizeof(factor));
		mapi.clear();
		m = getFactors(a);
		for (int j = 0; j < m; j++) {
			mapi[factor[j][0]]++;
		}
		memset(factor, 0, sizeof(factor));
		m = getFactors(b);
		for (int j = 0; j < m; j++) {
			mapi[factor[j][0]]++;
		}
		map<int, int>::iterator iter;
		for (iter = mapi.begin(); iter != mapi.end(); iter++) {
			mapint[iter->first]++;
		}
	}

/*	vector<pair<int, int> > map_vec(mapint.begin(), mapint.end());
	for (int i = 0; i < map_vec.size(); i++) {
		if (map_vec[i].second >= n) {
			printf("%d\n", map_vec[i].first);
			return 0;
		}
		sum++;
	}*/
	map<int, int>::iterator iter;
	for (iter = mapint.begin(); iter != mapint.end(); iter++) {
		if (iter->second >= n) {
			printf("%d\n", iter->first);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}