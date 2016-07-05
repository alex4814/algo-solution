#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
  typedef pair<int, int> pii;
public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ret;
    int start = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (i + 1 == n || (i + 1 < n && nums[i] + 1 < nums[i+1])) {
        string r = to_string(nums[start]);
        if (i - start) {
          r += "->" + to_string(nums[start] + i - start);
        }
        ret.push_back(r);
        start = i + 1;
      }
    }
    return ret;
  }
};

int main() {
  return 0;
}
