/*
 * Creation Date: 2016-07-07
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
  int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int l = digits(n - 1);
    int dup = 0;
    for (int i = 0; i < l; ++i) {
      int s = 1 << i, t = s << 1;
      int a = n / t * s;
      int b = max(0, n % t - s);
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
        cnt += nums[j] & s ? 1 : 0;
      }
      dup |= (cnt > a + b ? s : 0);
    }
    return dup;
  }
  int digits(int n) {
    int ret = 0;
    while (n > 0) {
      n >>= 1;
      ret += 1;
    }
    return ret;
  }
};

int main() {
  Solution s;
  vector<int> a = {1,1,1};
  vector<int> b = {3,2,1,4,3};
  vector<int> c = {1,2,2,2,2,2,2,2,2};
  vector<int> d = {1,1,1,4,3,5,6,7};
  cout << s.findDuplicate(a) << endl;
  cout << s.findDuplicate(b) << endl;
  cout << s.findDuplicate(c) << endl;
  cout << s.findDuplicate(d) << endl;
  return 0;
}
