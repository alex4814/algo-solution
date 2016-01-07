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
  int compareVersion(string version1, string version2) {
    vector<int> numbers1 = integerComponentsOf(version1);
    vector<int> numbers2 = integerComponentsOf(version2);
    int sz1 = numbers1.size();
    int sz2 = numbers2.size();
    int len = abs(sz1 - sz2);
    vector<int> &less = sz1 < sz2 ? numbers1 : numbers2;
    for (int i = 0; i < len; ++i) {
      less.push_back(0);
    }

    int sz = max(sz1, sz2);
    for (int i = 0; i < sz; ++i) {
      if (numbers1[i] > numbers2[i]) {
        return 1;
      } else if (numbers1[i] < numbers2[i]) {
        return -1;
      }
    }
    return 0;
  }

private:
  vector<int> integerComponentsOf(string version) {
    vector<int> numbers;
    size_t start = 0;
    size_t period = version.find_first_of(".");
    while (period != string::npos) {
      string number = version.substr(start, period - start);
      numbers.push_back(stoi(number));
      start = period + 1;
      period = version.find_first_of(".", start);
    }
    numbers.push_back(stoi(version.substr(start)));
    return numbers;
  }
};

int main() {
  Solution s = Solution();
  printf("%d\n", s.compareVersion("02.3", "2.3"));
  printf("%d\n", s.compareVersion("0.3", "1.3"));
  printf("%d\n", s.compareVersion("0.30", "0.3"));
  printf("%d\n", s.compareVersion("1.0", "1.0"));
  printf("%d\n", s.compareVersion("01", "1"));
  printf("%d\n", s.compareVersion("1.2", "1.10"));
  printf("%d\n", s.compareVersion("1.0", "1"));
  return 0;
}

