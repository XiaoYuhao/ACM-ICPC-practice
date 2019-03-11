#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define LL unsigned long long
void exgcd(LL a, LL b, LL& d, LL& x, LL& y)
{
	if (!b) { d = a; x = 1; y = 0; }
	else
	{
		exgcd(b, a%b, d, y, x);
		y -= x*(a / b);
	}
}
int main()
{
	LL A, B, C, k;
	while (scanf("%llu%llu%llu%llu", &A, &B, &C, &k), (A + B + C + k))
	{
		LL a, b, c, d, x, y, dm;
		c = B - A;
		if (c == 0) { printf("0\n"); continue; }
		a = C;
		b = (LL)1 << k;
		exgcd(a, b, d, x, y);
		if (c%d) { printf("FOREVER\n"); continue; }
		dm = b / d;
		x = (((x*c / d) % dm) + dm) % dm;

		printf("%llu\n", x);
	}
	return 0;
}