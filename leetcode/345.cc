/*
 * Creation Date: 2016-06-12
 * Created By: alex4814
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;

class Solution {
public:
  inline bool isVowel(const char letter) {
    static const char *vowels = "aeiou";
    static const int n = strlen(vowels);
    for (int i = 0; i < n; ++i) {
      if (tolower(letter) == vowels[i]) {
        return true;
      }
    }
    return false;
  }
  string reverseVowels(string s) {
    int n = s.size();
    int lo = 0;
    int hi = n - 1;
    while (lo < hi) {
      while (lo < n && !isVowel(s[lo])) { ++lo; }
      while (hi >= 0 && !isVowel(s[hi])) { --hi; }
      if (lo >= hi) { break; }
      swap(s[lo++], s[hi--]);
    }
    return s;
  }
};

int main() {
  Solution s;
  cout << s.reverseVowels("hello") << endl;
  return 0;
}
