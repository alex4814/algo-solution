#include <vector>

using namespace std;

class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> ret = { 0 };
    int l = 1, u = 2;
    for (int i = 1; i <= num; ++i) {
      if (i >= u) {
        l <<= 1;
        u <<= 1;
      }
      ret.push_back(ret[i - l] + 1);
    }
    return ret;
  }
};

int main() {
  return 0;
}
