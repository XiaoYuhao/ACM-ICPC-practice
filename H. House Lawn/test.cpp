#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
const int MAX = 105;
const int T = 10080;
const int INF = 0x3f3f3f3f;
struct robot {
	string name;
	int p, c, t, r;
	int flag;
}R[MAX];
int L, m;
struct pt {
	int flag;
	long long int time;
	int w;
};
bool operator > (const pt &a, const pt &b) {
	return a.time > b.time;
}

int check2(int n) {
	priority_queue<pt, vector<pt>, greater<pt> >q;
	pt temp;
	long long tt = 0;
	for (int i = 1; i <= 10; i++) {
		tt += R[n].t;
		temp.flag = 1;
		temp.time = tt;
		q.push(temp);
		tt += R[n].r;
		temp.flag = 2;
		temp.time = tt;
		q.push(temp);
		temp.flag = 3;
		temp.time = 10080 * i;
		temp.w = i;
		q.push(temp);
	}
	long long sum = 0;
	int w = 0;
	while (!q.empty()) {
		temp = q.top();
		q.pop();
		if (temp.flag == 1) {
			sum += R[n].t*R[n].c;
		}
		else if (temp.flag == 2)continue;
		else if (temp.flag == 3) {
			if (temp.w > sum / L)return 0;
		}
	}
	return 1;
}

void fenjie(string s, string &name, int &p, int &c, int &t, int &r) {
	string temp;
	int k = 0, begin = 0;
	while (s[k] != ',') {
		name += s[k++];
	}
	k++;
	begin = 0;
	while (s[k] != ',') {
		temp += s[k++];
	}
	p = stoi(temp);
	k++;
	begin = 0;
	temp.clear();
	while (s[k] != ',') {
		temp += s[k++];
	}
	c = stoi(temp);
	k++;
	begin = 0;
	temp.clear();
	while (s[k] != ',') {
		temp += s[k++];
	}
	t = stoi(temp);
	k++;
	begin = 0;
	temp.clear();
	while (k<s.size()) {
		temp += s[k++];
	}
	r = stoi(temp);
}

int check(int i) {
	int tt = R[i].t + R[i].r;
	int ctt = R[i].c*R[i].t;
	long long LL = 10080LL * ctt;
	long long temp = L;
	temp *= tt;
	if (LL >= temp) {
		return 1;
	}
	else return 0;
}


vector<int> ansn;
int main() {
	scanf("%d %d", &L, &m);
	getchar();
	int ans = INF;
	for (int i = 0; i < m; i++) {
		string s;
		getline(cin, s);
		fenjie(s, R[i].name, R[i].p, R[i].c, R[i].t, R[i].r);
		if (check(i)) {
			ans = min(ans, R[i].p);
			R[i].flag = 1;
		}
	}
	for (int i = 0; i < m; i++) {
		if (ans == R[i].p&&R[i].flag) {
			ansn.push_back(i);
		}
	}
	if (ansn.size() == 0) {
		cout << "no such mower" << endl;
	}
	else {
		for (int i = 0; i < ansn.size(); i++) {
			cout << R[ansn[i]].name << endl;
		}
	}
	return 0;
}

/*
5040 1
xiao,520,1,10800,10800
5040 4
a,520,1,10800,10800
b,500,2,10800,10800
c,422,3,10800,10800
d,412,1,10800,10900
a
*/