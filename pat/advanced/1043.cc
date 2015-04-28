
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
#define MAXN 1005
#define MAXM 105

struct Node {
	int key;
	Node *lch, *rch;
};

Node node[MAXN];
int n, rt, cnt;
int a[MAXN];
int b[MAXN];

void insert(Node *&rt, int key) {
	if (rt == NULL) {
		rt = &node[cnt++];
		rt->key = key;
		rt->lch = rt->rch = NULL;
		return;
	}
	insert((key < rt->key ? rt->lch : rt->rch), key);
}

void preorder(Node *rt, int d) {
	if (rt == NULL) {
		return;
	}
	b[cnt++] = rt->key;
	preorder(d ? rt->rch : rt->lch, d);
	preorder(d ? rt->lch : rt->rch, d);
}

void postorder(Node *rt, int d) {
	if (rt == NULL) {
		return;
	}
	postorder(d ? rt->rch : rt->lch, d);
	postorder(d ? rt->lch : rt->rch, d);
	printf("%d", rt->key);
	putchar(++cnt == n ? '\n' : ' ');
}

bool same(int *a, int *b, int n) {
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d", &n);
	Node *root = NULL;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		insert(root, a[i]);
	}
	for (int i = 0; i < 2; ++i) {
		cnt = 0;
		preorder(root, i);	// 0 for left first, 1 otherwise
		if (same(a, b, n)) {
			puts("YES");
			cnt = 0;
			postorder(root, i);
			return 0;
		}
	}
	puts("NO");
	return 0;
}
