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
	int a, b;
	scanf("%d %d", &a, &b);
	int t = round((b - a) / 100.0);
	int hh = t / 3600;
	int mm = (t - hh * 3600) / 60;
	int ss = t - hh * 3600 - mm * 60;
	printf("%02d:%02d:%02d\n", hh, mm, ss);
	return 0;
}


