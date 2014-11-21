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
#define MAXN 100003
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

struct Node {
	char id[19];
	ll mile;
	Node *next;
};

Node *ht[MAXN];	// hash table (linked list)
Node node[MAXN];
int nn;

// BKDR Hash Function
int BKDRHash(char *str) {
	int seed = 131; // 31 131 1313 13131 131313 etc.. 
 	int hash = 0;
	while (*str) {
		hash = (hash * seed + (*str++)) % MAXN;
	}
	return hash;
}

void insert(Node *&p, char *id, int mile) {
	node[nn].next = p;
	p = &node[nn++];
	strcpy(p->id, id);
	p->mile = mile;
}

Node *search(int hash, char *id) {
	if (ht[hash] == NULL) return NULL;
	Node *p = ht[hash];
	while (p != NULL) {
		if (strcmp(id, p->id) == 0) return p;
		p = p->next;
	}
	return NULL;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int mile;
	char id[19];
	for (int i = 0; i < n; ++i) {
		scanf("%s %d", id, &mile);
		int h = BKDRHash(id);
		Node *p = search(h, id);
		if (p == NULL) {
			insert(ht[h], id, max(k, mile));
		} else {
			p->mile += max(k, mile);
		}
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%s", id);
		int h = BKDRHash(id);
		Node *p = search(h, id);
		if (p == NULL) {
			printf("No Info\n");
		} else {
			printf("%lld\n", p->mile);
		}
	}
	return 0;
}


