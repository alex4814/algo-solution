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

int a[4], o[3], p[3];
char ops[] = "+-*/";

string int_to_string(int x) {
	char d[3];
	sprintf(d, "%d", x);
	return string(d);
}

bool equal24(string &e) {
	vector<int> data, op, pri;
	vector<string> expr;
	data.push_back(a[0]);
	expr.push_back(int_to_string(a[0]));
	for (int i = 0; i < 3; ++i) {
		data.push_back(a[i + 1]);
		expr.push_back(int_to_string(a[i + 1]));
		op.push_back(o[i]);
		pri.push_back(p[i]);
		while (!pri.empty() && (i == 2 || pri.back() < p[i + 1])) {
			int y = data.back(); data.pop_back();
			int x = data.back(); data.pop_back();
			int f = op.back(); op.pop_back();
			int r = -1;
			if (f == 0) {
				r = x + y;
			} else if (f == 1) {
				r = x - y;
			} else if (f == 2) {
				r = x * y;
			} else {
				if (y == 0 || x % y) return false;
				r = x / y;
			}
			string e2 = expr.back(); expr.pop_back();
			string e1 = expr.back(); expr.pop_back();
			string er = "(" + e1 + string(1, ops[f]) + e2 + ")";
			data.push_back(r);
			expr.push_back(er);
			pri.pop_back();
		}
	}
	e = expr[0].substr(1, expr[0].length() - 2);
	return data.back() == 24;
}

int main() {
	for (int i = 0; i < 4; ++i) {
		scanf("%d", a + i);
	}
	sort(a, a + 4);
	string expression;
	do {
		for (o[0] = 0; o[0] < 4; ++o[0]) {
			for (o[1] = 0; o[1] < 4; ++o[1]) {
				for (o[2] = 0; o[2] < 4; ++o[2]) {
					for (int i = 0; i < 3; ++i) {
						p[i] = i + 1;
					}
					do {
						if (equal24(expression)) {
							printf("%s\n", expression.c_str());
							return 0;
						}
					} while (next_permutation(p, p + 3));
				}
			}
		}
	} while (next_permutation(a, a + 4));
	printf("-1\n");
	return 0;
}


