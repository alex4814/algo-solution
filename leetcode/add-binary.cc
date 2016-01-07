#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAXN 100005
#define EPS 1e-8

class Solution {
public:
  string addBinary(string a, string b) {
    string::reverse_iterator rita = a.rbegin();
    string::reverse_iterator ritb = b.rbegin();
    string sum;
    int cf = 0;
    while (rita != a.rend() && ritb != b.rend()) {
      int s = (*rita - '0') + (*ritb - '0') + cf;
      sum = string(1, ((s & 1) + '0')) + sum;
      cf = s / 2;
      ++rita;
      ++ritb;
    }
    while (rita != a.rend()) {
      int s = (*rita - '0') + cf;
      sum = string(1, ((s & 1) + '0')) + sum;
      cf = s / 2;
      ++rita;
    }
    while (ritb != b.rend()) {
      int s = (*ritb - '0') + cf;
      sum = string(1, ((s & 1) + '0')) + sum;
      cf = s / 2;
      ++ritb;
    }
    if (cf > 0) {
      sum = "1" + sum;
    }
    return sum;
  }
};

int main() {
  Solution s = Solution();
  string a, b;
  cin >> a >> b;
  string r = s.addBinary(a, b);
  cout << r << endl;
  return 0;
}

