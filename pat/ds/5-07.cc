#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 100003
#define MAXL 145

typedef pair<int, int> pii;
typedef long long ll;

struct Node {
	char topic[MAXL];
	int cnt;
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

void insert(Node *&p, char *topic) {
	node[nn].next = p;
	p = &node[nn++];
	strcpy(p->topic, topic);
	p->cnt = 1;
}

Node *search(int hash, char *topic) {
	if (ht[hash] == NULL) return NULL;
	Node *p = ht[hash];
	while (p != NULL) {
		if (strcmp(topic, p->topic) == 0) return p;
		p = p->next;
	}
	return NULL;
}

int main() {
int n;
	scanf("%d", &n);
	char line[MAXL], t[MAXL];
	getchar();
	for (int i = 0; i < n; ++i) {
		fgets(line, MAXL, stdin);
		int sz = strlen(line);
		set<int> hs;
		for (int j = 0; j < sz; ++j) {
			if (line[j] == '#') {
				int k = j;
				char *s = line + k + 1;
				while (line[++k] != '#') {
					if (isalpha(line[k])) {
						line[k] = tolower(line[k]);
					} else if (!isalnum(line[k])) {
						line[k] = ' ';
					}
				}
				// trim, nonalpha processing
				int tn = 0;
				for (int u = 0; u < k - j - 1; ++u) {
					if (s[u] == ' ') {
						if (tn == 0) continue;
						if (t[tn - 1] == ' ') continue;
						t[tn++] = ' ';
					} else {
						t[tn++] = s[u];
					}
				}
				t[tn] = '\0';
				j = k;
				if (tn != 0) {
					while (t[tn - 1] == ' ') {
						t[--tn] = '\0';
					}
					//printf("t = %s\n", t);
					int h = BKDRHash(t); 
					if (hs.find(h) != hs.end()) continue;
					// hash and update or insert
					hs.insert(h);
					Node *p = search(h, t);
					if (p == NULL) {
						insert(ht[h], t);
					} else {
						p->cnt += 1;
					}
				}
			}
		}
	}
	char *r_topic = NULL;
	int r_cnt = -1;
	int n_max = 0;
	for (int i = 0; i < MAXN; ++i) {
		Node *p = ht[i];
		while (p != NULL) {
			if (p->cnt > r_cnt) {
				r_cnt = p->cnt;
				r_topic = p->topic;
				n_max = 0;
			} else if (p->cnt == r_cnt) {
				if (strcmp(p->topic, r_topic) < 0) {
					r_topic = p->topic;
				}
				n_max += 1;
			}
			p = p->next;
		}
	}
	printf("%c%s\n%d\n", toupper(r_topic[0]), r_topic + 1, r_cnt);
	if (n_max) printf("And %d more ...\n", n_max);
	return 0;
}


