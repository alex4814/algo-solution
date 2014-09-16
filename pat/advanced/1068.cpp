#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

#define MAXN 10000
int a[MAXN], n, m, sum;
bool vis[MAXN];
bool found;
deque<int> path;

bool dfs(int s) {
	if (found) return true;
	if (sum > m) return false;
	if (sum == m) {
		found = true;
		return true;
	}
	for (int i = s + 1; i < n; ++i) {
		if (a[i] == a[i - 1] && !vis[i - 1]) continue;
		sum += a[i];
		path.push_back(i);
		vis[i] = true;
		if (dfs(i)) return true;
		vis[i] = false;
		path.pop_back();
		sum -= a[i];
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	
	for (int i = 0; i < n; ++i) {
		path.push_back(i);
		sum += a[i];
		vis[i] = true;
		if (dfs(i)) break;
		vis[i] = false;
		sum -= a[i];
		path.pop_back();
	}
	
	if (found) {
		for (int i = 0; i < path.size(); ++i) {
			if (i) putchar(' ');
			printf("%d", a[path[i]]);
		}
		puts("");
	} else {
		puts("No Solution");	
	}
	return 0;
}
