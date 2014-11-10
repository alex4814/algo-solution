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
#define MAXN 1005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

struct Node {
	int x;
	Node *l, *r;
};

Node node[MAXN];
int a[MAXN], n;
int r1[MAXN], r2[MAXN];
int t;

void insert(Node *&rt, int x) {
	if (rt == NULL) {
		rt = &node[t++];
		rt->x = x;
		rt->l = rt->r = NULL;
	} else {
		if (x < rt->x) {
			insert(rt->l, x);
		} else {
			insert(rt->r, x);
		}
	}
}

void pre_order(Node *rt, int w) {
	if (rt == NULL) return;
	int *b = (w == 0 ? r1 : r2);
	b[t++] = rt->x;
	if (w == 0) {
		pre_order(rt->l, w);
		pre_order(rt->r, w);
	} else {
		pre_order(rt->r, w);
		pre_order(rt->l, w);
	}
}

void post_order(Node *rt, int w) {
	if (rt == NULL) return;
	int *b = (w == 0 ? r1 : r2);
	if (w == 0) {
		post_order(rt->l, w);
		post_order(rt->r, w);
	} else {
		post_order(rt->r, w);
		post_order(rt->l, w);
	}
	b[t++] = rt->x;
}

bool equal(int *b) {
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

int *valid(Node *rt) {
	t = 0; pre_order(rt, 0);
	t = 0; pre_order(rt, 1);
	if (equal(r1)) {
		t = 0; post_order(rt, 0);
		return r1;
	} else if (equal(r2)) {
		t = 0; post_order(rt, 1);
		return r2;
	} else {
		return NULL;
	}
}

int main() {
  Node *rt = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		insert(rt, a[i]);
	}
	int *ret;
	if ((ret = valid(rt)) != NULL) {
		printf("YES\n");
		for (int i = 0; i < n; ++i) {
			printf("%d%c", ret[i], i + 1 == n ? '\n' : ' ');
		}
	} else {
		printf("NO\n");
	}
	return 0;
}


