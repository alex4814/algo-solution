#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 105
#define MAXM 105

char dig[][10] = {
	"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};
char n[MAXN];
int len, sum;

void print(int x) {
	if (x / 10 == 0) { printf("%s", dig[x]); return; }
	print(x / 10);
	printf(" %s", dig[x % 10]);
}

int main() {
	scanf("%s", n);
	len = strlen(n);
	for (int i = 0; i < len; ++i) {
		sum += n[i] - '0';
	}
	print(sum);
	printf("\n");
	return 0;
}
