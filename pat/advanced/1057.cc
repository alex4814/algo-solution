#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 100005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

vector<int> sk;
char op[15];
priority_queue<int> max_heap;
priority_queue< int, vector<int>, greater<int> > min_heap;

void insert(int x) {
	if (max_heap.empty() && min_heap.empty()) {
		min_heap.push(x);
	} else if (max_heap.empty()) {
	
	} else if (min_heap.empty()) {
	
	} else {
		
	}
}

void remove(int x) {

}

void adjust() {
	
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", op);
		if (op[1] == 'o') {
			if (sk.empty()) {
				printf("Invalid\n");
			} else {
				int x = sk.back();
				printf("%d\n", x);
				sk.pop_back();
				remove(x);
				adjust()
			}
		} else if (op[1] == 'e') {
			if (sk.empty()) {
				printf("Invalid\n");
			} else {
				printf("%d\n", min_heap.top());
			}
		} else {
			int x;
			scanf("%d", &x);
			sk.push_back(x);
			insert(x);
			adjust();
		}
	}
	return 0;
}


