#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 100005
#define MAXM 105

int n;
char head[10];

struct Node {
	char addr[10], next[10];
	int key;
	bool operator < (const Node &b) const {
		return key < b.key;
	}
};
Node node[MAXN], list[MAXN], test, cp;

bool addr(Node a, Node b) {
	return strcmp(a.addr, b.addr) < 0;
}

int bins(char *s) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		int ret = strcmp(node[m].addr, s);
		if (ret == 0) return m;
		ret > 0 ? r = m - 1 : l = m + 1;
	}
	return -1;
}

int main() {
	scanf("%d%s", &n, head);
	for (int i = 0; i < n; ++i) {
		scanf("%s%d%s", node[i].addr, &node[i].key, node[i].next);
	}
	sort(node, node + n, addr);

	char *cur = head;
	int m = 0;
	while (strcmp(cur, "-1") != 0) {
		int ix = bins(cur);
		strcpy(list[m].addr, node[ix].addr);
		list[m].key = node[ix].key;
		cur = node[ix].next;
		m++;
	}
	
	if (m == 0) {
		printf("0 -1\n");
		return 0;
	}
	sort(list, list + m);
	printf("%d %s\n", m, list[0].addr);
	for (int i = 0; i < m; ++i) {
		printf("%s %d ", list[i].addr, list[i].key);
		i == m - 1 ? printf("-1\n") : printf("%s\n", list[i + 1].addr);
	}
	return 0;
}
