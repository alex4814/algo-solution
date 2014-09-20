/*
ID: alex4814
PROG: milk
LANG: C++
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define FILEIO

#ifdef FILEIO
#define cin fin
#define cout fout
#endif

typedef pair<int, int> pii;
typedef long long ll;

#define MAXN 5005
#define EPS 1e-8

ifstream fin("milk.in");
ofstream fout("milk.out");

struct Seller {
    int amt, p;
    bool operator < (const Seller &b) const {
        return p < b.p;
    }
};

Seller s[MAXN];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s[i].p >> s[i].amt;
    }

    int tot = 0;
    sort(s, s + m);
    for (int i = 0; i < m; ++i) {
        if (n >= s[i].amt) {
            tot += s[i].amt * s[i].p;
            n -= s[i].amt;
        } else {
            tot += n * s[i].p;
            break;
        }
    }
    cout << tot << endl;

    return 0;
}

