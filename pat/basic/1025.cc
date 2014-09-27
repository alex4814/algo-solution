#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 100005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

struct Node {
	int data;
	int prio;
	int next;
};

Node ln[MAXN];

int link_reverse(int head) {
	int n = 0;
	int cur = head, pri = -1;
	while (cur != -1) {
		n++;
		ln[cur].prio = pri;
		cur = ln[pri = cur].next;
	}
	return n;
}

int main() {
	int head, n, k;
	scanf("%d %d %d", &head, &n, &k);
	for (int i = 0; i < n; ++i) {
		int addr, data, next;
		scanf("%d %d %d", &addr, &data, &next);
		ln[addr].data = data;
		ln[addr].next = next;
	}
	n = link_reverse(head);
	int pri = head;
 	int cur = head;
	for (int i = 0; i < n / k; ++i) {
		int cnt = 1;
		while (cnt++ < k) {
			cur = ln[cur].next;
		}
		int h = ln[pri].prio;
		int t = ln[cur].next;
		int p = cur;
		h == -1 ? head = p : ln[h].next = p;
		for (int i = 1; i < k; ++i) {
			ln[p].next = ln[p].prio;
			p = ln[p].next;
		}
		ln[cur].prio = h;
		ln[p].next = t;
		ln[t].prio = p;
		pri = cur = t;
	}
	cur = head;
	while (cur != -1) {
		printf("%05d %d ", cur, ln[cur].data);
		if (ln[cur].next == -1) {
			printf("-1\n");
		} else {
			printf("%05d\n", ln[cur].next);
		}
		cur = ln[cur].next;
	}
	return 0;
}


