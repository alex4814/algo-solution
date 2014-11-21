#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 35
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int node[MAXN][3]; 	// 1 for lchild, 2 for rchild
deque<int> s;
int cnt, n, t = 1;

void print(int rt) {
	if (rt == 0) return;
	print(node[rt][1]);
	print(node[rt][2]);
	printf("%d", node[rt][0]);
	putchar(++cnt == n ? '\n' : ' ');
}

int main() {
	char op[5];
	scanf("%d", &n);
	int p = 0, q = 0;
	for (int i = 0, x; i < n << 1; ++i) {
		scanf("%s", op);
		if (op[1] == 'u') {
			scanf("%d", &x);
			if (p) {
				node[p][2] = t;
				p = 0;
			} else {
				node[q][1] = t;
			}
			node[q = t][0] = x;
			s.push_back(t++);
		} else {
			p = s.back();
			s.pop_back();
		}
	}
	print(1);
	return 0;
}


