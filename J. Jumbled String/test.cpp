#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
using namespace std;
int main()
{
	long long count_0;
	long long count_1;
	long long a, b, c, d;
	map<long long, long long> k;
	for (int i = 0; i <= sqrt(9e9) + 1; ++i) {
		k[i*i] = i;
	}
	cin >> a >> b >> c >> d;
	auto temp = k.find(a * 8 + 1);
	if (a == 0 && b == 0 && c == 0 && d == 0) {
		printf("1\n");
	}
	else {
		if (temp == k.end() || (1 + temp->second) % 2) {
			printf("impossible\n");
		}
		else {
			count_0 = (1 + temp->second) / 2;
			temp = k.find(d * 8 + 1);
			if (temp == k.end() || (1 + temp->second) % 2) {
				printf("impossible\n");
			}
			else {
				count_1 = (1 + temp->second) / 2;
				if (a == 0 && c == 0 && b == 0) {
					while (count_1) {
						putchar('1');
						--count_1;
					}
					putchar('\n');
				}
				else if (d == 0 && c == 0 && b == 0) {
					while (count_0) {
						putchar('0');
						--count_0;
					}
					putchar('\n');
				}
				else {
					if (count_0*count_1 != c + b) {
						printf("impossible\n");
					}
					else {
						while (c != 0 || count_0 != 0) {
							if (c >= count_0) {
								putchar('1');
								--count_1;
								c -= count_0;
							}
							else {
								putchar('0');
								--count_0;
							}
						}
						while (count_1) {
							putchar('1');
							--count_1;
						}
						putchar('\n');
					}
				}

			}
		}
	}
	return 0;
}