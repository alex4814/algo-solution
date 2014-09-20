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

int main() {
	int a = 4, b = 5;
	printf("before, a = %d, b = %d\n", a, b);
	a ^= b ^= a ^= b;
	printf("after , a = %d, b = %d\n", a, b);
	return 0;
}


