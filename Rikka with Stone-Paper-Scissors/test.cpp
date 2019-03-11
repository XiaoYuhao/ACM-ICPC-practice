#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

long long int gcd(long long int a, long long int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
} 

int main() {
	int tt;
	scanf("%d", &tt);
	long long int a, b, c, a1, b1, c1;
	while (tt--) {
		scanf("%lld%lld%lld", &a, &b, &c);
		scanf("%lld%lld%lld", &a1, &b1, &c1);
		long long ans1, ans2;
		ans1 = a1*(c - b) + c1*(b - a) + b1*(a - c);
		ans2 = a + b + c;
		if (ans1%ans2==0) {
			printf("%lld\n", ans1 / ans2);
		}
		else { 
			long long d = gcd(ans1, ans2);
			d = abs(d);
			printf("%lld/%lld\n", ans1/d, ans2/d); 
		}
	}
	return 0;
}