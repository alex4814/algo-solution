/*
ID: alex4814
PROG: palsquare
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

#define MAXN 100005
#define EPS 1e-8

ifstream fin("palsquare.in");
ofstream fout("palsquare.out");

string dig = "0123456789ABCDEFGHIJK";
int b;

string convert(int x, int b) {
    string n;
    while (x > 0) {
        n += dig[ x % b ];
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

int main() {
    cin >> b;
    for (int x = 1; x <= 300; ++x) {
        string n = convert(x, b);
        string n2 = convert(x * x, b);
        if (is_palindromic(n2)) {
            cout << n << " " << n2 << endl;
        }
    }
    return 0;
}

