/*
 * Creation Date: 2016-04-16
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
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    nums1.resize(n + m);
    for (int i = m - 1; i >= 0; --i) {
      nums1[i + n] = nums1[i];
    }
    int i = n, j = 0, k = 0;
    while (i < m + n && j < n) {
      if (nums1[i] < nums2[j]) {
        nums1[k++] = nums1[i++];
      } else {
        nums1[k++] = nums2[j++];
      }
    }
    while (i < m + n) {
      nums1[k++] = nums1[i++];
    }
    while (j < n) {
      nums1[k++] = nums2[j++];
    }
  }
};

int main() {
  Solution s;
  vector<int> n1 { 1, 3, 4, 7 };
  vector<int> n2 { 2, 3, 5 };
  s.merge(n1, 4, n2, 3);
  for (const auto x: n1) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
