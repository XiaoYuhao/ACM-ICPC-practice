#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

typedef long long ll;
const int MAX = 100;
const int MOD = 1;

//Ê÷×´Êý×é
/*
int bit[MAX + 1], n;
int sum(int i) {
	int s = 0;
	while (i > 0) {
		s += bit[i];
		i -= i&-i;
	}
	return s;
}
void add(int i, int x) {
	while (i <= n) {
		bit[i] += x;
		i += i&-i;
	}
}
*/