#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<stdio.h>
using namespace std;

const int MAX = 200010;
int num[MAX], col[MAX];
int pre[MAX], nxt[MAX];

struct cmp {
	template<typename T,typename U>
	bool operator()(T const & left, U const & right) {
		if (left.first == right.first) {
			return left.second > right.second;
		}
		else if (left.first < right.first) {
			return true;
		}
		else return false;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp > q, del;

int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	int x;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if (x == col[cnt])num[cnt]++;
		else {
			col[++cnt] = x;
			num[cnt] = 1;
		}
	}
	for (int i = 1; i <= cnt; i++) {
		pre[i] = i - 1;     
		nxt[i] = i + 1;
		q.push(make_pair(num[i], i));
	}
	int f, s, ans = 0;
	int a, t, _t;
	while (cnt) {
		while (!del.empty() && del.top() == q.top()) {
			del.pop();
			q.pop();
		}
		a = q.top().second;
		q.pop();
		t = pre[a];
		_t = nxt[a];
		nxt[t] = _t;
		pre[_t] = t;
		if (t&&col[t] == col[_t]) {
			del.push(make_pair(num[t], t));
			del.push(make_pair(num[_t], _t));
			nxt[t] = nxt[_t];
			pre[nxt[_t]] = t;
			num[t] += num[_t];
			f = num[t];
			s = t;
			q.push(make_pair(f, s));
			cnt--;
		}
		cnt--;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
