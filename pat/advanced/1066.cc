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

struct AvlNode {
	int key;
	int height;
	AvlNode *ch[2];
	
	AvlNode(const int &key, AvlNode *lc, AvlNode *rc, int h = 0)
		:key(key), height(h) { ch[0] = lc, ch[1] = rc; }
};

inline int height(AvlNode *rt) {
	return rt == NULL ? -1 : rt->height;
}

// d = 0 for left rotate
void rotate(AvlNode * &rt, int d) {
	AvlNode *k0 = rt->ch[d ^ 1];
	rt->ch[d ^ 1] = k0->ch[d]; k0->ch[d] = rt;
	rt->height = max(height(rt->ch[d]), height(rt->ch[d ^ 1])) + 1;
	k0->height = max(height(k0->ch[d]), rt->height) + 1;
	rt = k0;
}

void insert(AvlNode * &rt, int &x) {
	if (rt == NULL) {
		rt = new AvlNode(x, NULL, NULL);
	} else if (x < rt->key) {
		insert(rt->ch[0], x);
		if (height(rt->ch[0]) - height(rt->ch[1]) == 2) {
			if (x < rt->ch[0]->key) {
				rotate(rt, 1);
			} else {
				rotate(rt->ch[0], 0);
				rotate(rt, 1);
			}
		}
	} else if (x > rt->key) {
		insert(rt->ch[1], x);
		if (height(rt->ch[1]) - height(rt->ch[0]) == 2) {
			if (x > rt->ch[1]->key) {
				rotate(rt, 0);
			} else {
				rotate(rt->ch[1], 1);
				rotate(rt, 0);
			}
		}
	}
	rt->height = max(height(rt->ch[0]), height(rt->ch[1])) + 1;
}

AvlNode *root;
int n;

int main() {
	root = NULL;
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++i) {
		scanf("%d", &x);
		insert(root, x);
	}
	printf("%d\n", root->key);
	return 0;
}

