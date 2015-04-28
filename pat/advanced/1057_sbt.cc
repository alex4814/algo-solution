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

struct SbtNode {
	SbtNode *lc, *rc;
	int key;
	int size;

	SbtNode(const int &key, int s = 1)
		:key(key), size(s) { this->lc = NULL; this->rc = NULL; }
};

void left_rotate(SbtNode * &rt) {
	SbtNode *k0 = rt->rc;
	rt->rc = k0->lc;
	k0->lc = rt;
	k0->size = rt->size;
	rt->size = rt->lc->size + rt->rc->size + 1;
	rt = k0;
}

void right_rotate(SbtNode * &rt) {
	SbtNode *k0 = rt->lc;
	rt->lc = k0->rc;
	k0->rc = rt;
	k0->size = rt->size;
	rt->size = rt->lc->size + rt->rc->size + 1;
	rt = k0;
}

void maintain(SbtNode * &rt, bool flag) {
	if (!flag) {
		if (rt->lc == NULL) {
			return;
		}
		if (rt->lc->lc->size > rt->rc->size) {
			left_rotate(rt->lc);
			right_rotate(rt);
		} else {
			return;
		}
	} else {
		if (rt->rc == NULL) {
			return;
		}
		if (rt->rc->rc->size > rt->lc->size) {
			left_rotate(rt);
		} else if (rt->rc->lc->size > rt->lc->size) {
			right_rotate(rt->rc);
			left_rotate(rt);
		} else {
			return;
		}
	}
	maintain(rt->lc, false);
	maintain(rt->rc, true);
	maintain(rt, false);
	maintain(rt, true);
}

void insert_sbt(SbtNode * &rt, int key) {
	if (rt == NULL) {
		rt = new SbtNode(key);
		return;
	}
	rt->size += 1;
	insert_sbt(key < rt->key ? rt->lc : rt->rc, key);
	maintain(rt, key >= rt->key);
}

int delete_sbt(SbtNode * &rt, int key) {
	int rk = 0;
	rt->size -= 1;
	if ((rt->key == key) || 
			(rt->key > key && rt->lc == NULL) ||
			(rt->key < key && rt->rc == NULL)) {
		rk = rt->key;
		if (rt->lc == NULL || rt->rc == NULL) {
			rt = rt->lc ? rt->lc : rt->rc;
		} else {
			rt->key = delete_sbt(rt->lc, key + 1);
		} 
	} else {
		delete_sbt(rt->key > key ? rt->lc : rt->rc, key);
	}
	return rk;
}

int select_sbt(SbtNode * rt, int rank) {
	if (rt->lc && rank == rt->lc->size + 1) {
		return rt->key;
	}
	if (rt->rc && rank <= rt->lc->size) {
		return select_sbt(rt->lc, rank);
	} else {
		return select_sbt(rt->rc, rank - 1 - rt->lc->size);
	}
}

int main() {
	SbtNode *root = NULL;
	insert_sbt(root, 23);
	insert_sbt(root, 2);
	insert_sbt(root, 3);
	insert_sbt(root, 199);
	//delete_sbt(root, 3);
	printf("%d\n", select_sbt(root, 1));
	return 0;
}


