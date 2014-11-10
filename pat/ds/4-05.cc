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
#define MAXN 105
#define MAXL 80

typedef pair<int, int> pii;
typedef long long ll;

struct Node {
	int parent;
	int child, sibling;
};

int n, m;
char line[MAXN][MAXL];
int depth[MAXN];
Node node[MAXN];

int index(char *s) {
	for (int i = 0; i < n; ++i) {
		if (strcmp(s, line[i]) == 0) return i;
	}
	return -1;
}

int spaces(char *s) {
	int r = 0;
	while (*s++ == ' ') ++r;
	return r;
}

void build(int c) {
	int p = c - 1;
	node[c].sibling = node[c].child = -1;
	if (depth[p] == depth[c]) {
		node[c].parent = node[p].parent;
		node[p].sibling = c;
	} else if (depth[p] < depth[c]) {
		node[c].parent = p;
		node[p].child = c;
	} else {
		int d = depth[p] - depth[c];
		int t = p;
		while (d--) {
			t = node[t].parent;
		}
		node[c].parent = node[t].parent;
		node[t].sibling = c;
	}
}

bool is_child(int a, int b) {
	return node[a].parent == b;
}
bool is_sibling(int a, int b) {
	return node[a].parent == node[b].parent;
}
bool is_descendant(int a, int b) {
	int c = a;
	while (c != -1) {
		if (c == b) return true;
		c = node[c].parent;
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &m);
	getchar();
	node[0].parent = -1;
	node[0].child = node[0].sibling = -1;
	for (int i = 0; i < n; ++i) {
		fgets(line[i], MAXL, stdin);
		depth[i] = spaces(line[i]) / 2;
		if (i) build(i);
	}
	for (int i = 0; i < n; ++i) {
		char *s = line[i];
		char *t = line[i] + depth[i] * 2;
		while (*s++ = *t++);
		*(s - 2) = '\0';
	}
	char n1[11], n2[11];
	char relation[11];
	for (int i = 0; i < m; ++i) {
		scanf("%s", n1);
		for (int k = 0; k < 3; ++k) scanf("%s", relation);
		for (int k = 0; k < 2; ++k) scanf("%s", n2);
		int ix1 = index(n1);
		int ix2 = index(n2);
		if (relation[0] == 'p' || relation[0] == 'a') {
			swap(ix1, ix2);
		}
		bool ret;
		if (relation[0] == 'c' || relation[0] == 'p') {
			ret = is_child(ix1, ix2);
		} else if (relation[0] == 's') {
			ret = is_sibling(ix1, ix2);
		} else {
			ret = is_descendant(ix1, ix2);
		}
		puts(ret ? "True" : "False");
	}
	return 0;
}


