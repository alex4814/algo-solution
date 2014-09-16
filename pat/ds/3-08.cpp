#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

char op[10];
int n, n1, n2, d;
stack<int> s1, s2;

int main() {
	scanf("%d%d", &n1, &n2);
	n = min(n1, n2);
	while (scanf("%s", op), op[0] != 'T') {
		if (op[0] == 'A') {
			scanf("%d", &d);
			if (s1.size() == n && !s2.empty()) {
				printf("ERROR:Full\n");
			} else if (s1.size() == n) {
				while (!s1.empty()) {
					s2.push(s1.top());
					s1.pop();
				}
				s1.push(d);
			} else {
				s1.push(d);
			}
		} else {
			if (!s2.empty()) {
				printf("%d\n", s2.top());
				s2.pop();
			} else if (!s1.empty()) {
				while (!s1.empty()) {
					s2.push(s1.top());
					s1.pop();
				}
				printf("%d\n", s2.top());
				s2.pop();
			} else {
				printf("ERROR:Empty\n");
			}
		}
	}
	return 0;
}
