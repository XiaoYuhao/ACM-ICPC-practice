#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<functional>
using namespace std;
const int MAX = 1010;
int a[MAX], b[MAX], c[MAX];
int n, m, k, L;
struct Node {
	int score;
	int len;
};
bool operator ==(Node a, Node b) {
	return a.score == b.score;
}
bool operator >(Node a, Node b) {
	return a.score > b.score;
}
bool operator <(Node a, Node b) {
	return a.score < b.score;
}

int flag = 0;

void bfs() {
	priority_queue<Node, vector<Node>, less<Node> > q1;
	priority_queue<Node, vector<Node>, greater<Node> > q2;
	Node nd;
	nd.score = m;
	nd.len = 0;
	q1.push(nd);
	q2.push(nd);
	Node n1, n2;
	int play = n % 2;
	while(!q1.empty()||!q2.empty()) {
		if (!q1.empty()) {
			n1 = q1.top();
			q1.pop();
			int len = n1.len;
			int score = n1.score;
			if (len == n&&play==1) {
				if (score >= k) {
					flag = 1;
					break;
				}
				else if (score > L) {
					flag = 0;
					break;
				}
				else if (score <= L) {
					flag = 2;
					break;
				}
			}
			if (a[len] != 0) {
				Node na;
				na.len = len + 1;
				na.score = score + a[len];
				if (na.score > 100)na.score = 100;
				q1.push(na);
			}
			if (b[len] != 0) {
				Node na;
				na.len = len + 1;
				na.score = score - b[len];
				if (na.score < -100)na.score = -100;
				q1.push(na);
			}
			if (c[len] != 0) {
				Node na;
				na.len = len + 1;
				na.score = score*(-1);
				if (na.score > 100) na.score = 100;
				if (na.score < -100)na.score = -100;
				q1.push(na);
			}
		}
		if (!q2.empty()) {
			n2 = q2.top();
			q2.pop();
			int len = n2.len;
			int score = n2.score;
			if (len == n&&play==0) {
				if (score <= L) {
					flag = 2;
					break;
				}
				else if (score < k) {
					flag = 0;
					break;
				}
				else if (score >= k) {
					flag = 1;
					break;
				}
			}
			if (a[len] != 0) {
				Node na;
				na.len = len + 1;
				na.score = score + a[len];
				if (na.score > 100)na.score = 100;
				q2.push(na);
			}
			if (b[len] != 0) {
				Node na;
				na.len = len + 1;
				na.score = score - b[len];
				if (na.score < -100)na.score = -100;
				q2.push(na);
			}
			if (c[len] != 0) {
				Node na;
				na.len = len + 1;
				na.score = score*(-1);
				if (na.score > 100) na.score = 100;
				if (na.score < -100)na.score = -100;
				q2.push(na);
			}
		}
	}
}

int main() {

	scanf("%d%d%d%d", &n, &m, &k, &L);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}
	bfs();
	if (flag == 1) {
		printf("Good Ending\n");
		return 0;
	}
	else if (flag == 2) {
		printf("Bad Ending\n");
		return 0;
	}
	else {
		printf("Normal Ending\n");
		return 0;
	}
}