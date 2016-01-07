#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

#define MAXN 10005
#define MAXM 105
#define PI acos(-1.0)
#define EPS 1e-8

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
  }
};

int main() {
  Solution s = Solution();
  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {0,77,7,0};
  vector<int> a(myints, myints + sizeof(myints) / sizeof(int) );
  vector<int> r = s.twoSum(a, 0);
  cout << r[0] << " " << r[1] << endl;
  return 0;
}
