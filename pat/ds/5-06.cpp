#include <cstdio>
#include <string>
#include <map>
using namespace std;

int n, k, m;
char id[20];
string s;
map<string, int> flight;

int main() {
	int mile;

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%s %d", id, &mile);
		flight[s = id] += (mile < k ? k : mile);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%s", id);
		int ret = flight[s = id];
		ret ? printf("%d\n", ret) : printf("No Info\n");
	}
	return 0;
}
