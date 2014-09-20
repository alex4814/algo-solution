/*
ID: alex4814
PROG: namenum
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

struct Dictionary {
    string name;
    string number;
};

int to[26] = {
    2, 2, 2,
    3, 3, 3,
    4, 4, 4,
    5, 5, 5,
    6, 6, 6,
    7, 0, 7, 7,
    8, 8, 8,
    9, 9, 9, 0,
};

ifstream fin("namenum.in");
ofstream fout("namenum.out");

Dictionary dict[MAXN];
string s;
int n;

string number_of(string s) {
    string ret;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        ret += to[s[i] - 'A'] + '0';
    }
    return ret;
}

int main() {
    ifstream din("dict.txt");

    while (din >> s) {
        dict[n++] = (Dictionary){ s, number_of(s) };
    }

    cin >> s;
    bool none = true;
    for (int i = 0; i < n; ++i) {
        if (dict[i].number == s) {
            cout << dict[i].name << endl;
            none = false;
        }
    }
    if (none) cout << "NONE" << endl;

    return 0;
}

