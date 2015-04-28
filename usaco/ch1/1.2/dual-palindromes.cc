/*
ID: alex4814
PROG: dualpal
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

#define MAXN 20
#define EPS 1e-8

ifstream fin("dualpal.in");
ofstream fout("dualpal.out");

int n, s;

string convert(int x, int b) {
    string n;
    while (x > 0) {
        n += x % b;
        x /= b;
    }
    string ret;
    int l = n.size();
    for (int i = 0; i < l; ++i) {
        ret += n[l - 1 - i];
    }
    return ret;
}

bool is_palindromic(string s) {
    int l = s.size();
    for (int i = 0; i < l; ++i) {
        if (s[i] != s[l - 1 - i]) return false;
    }
    return true;
}

int ret[MAXN];

int main() {
    cin >> n >> s;

    int k = 0;
    for (int x = s + 1; k < n; ++x) {
        int cnt = 0;
        for (int b = 2; b <= 10; ++b) {
            string n = convert(x, b);
            if (is_palindromic(n)) {
                cnt += 1;
                if (cnt >= 2) {
                    ret[k++] = x;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << ret[i] << endl;
    }

    return 0;
}

