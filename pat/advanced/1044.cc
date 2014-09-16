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
#define INF 0x7fffffff
#define MAXN 100005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int n, m;
int v[MAXN];
vector<pii> e, ne;

void print(vector<pii> r) {
	int tot = r.size();
	for (int i = 0; i < tot; ++i) {
		printf("%d-%d\n", r[i].first + 1, r[i].second + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", v + i);
	}
	
	bool exactly = false;
	int l = 0, r = 0;
	int sum = 0, minc = INF;
	while (l < n && r < n) {
		sum += v[r];
		if (sum == m) {
			exactly = true;
			e.push_back(make_pair(l, r));
			sum -= v[l++];
		} else if (sum > m) {
			if (!exactly && sum - m <= minc) {
				if (sum - m < minc) ne.clear();
				ne.push_back(make_pair(l, r));
				minc = sum - m;
			} 
			sum -= v[l++] + v[r--];
		}
		r++;
	}
	print(exactly ? e : ne);

	return 0;
}


