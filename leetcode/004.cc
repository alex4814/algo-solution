#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int x = INT_MAX, y = INT_MIN;
    if (!nums1.empty()) {
      x = min(x, nums1.front());
      y = max(y, nums1.back());
    }
    if (!nums2.empty()) {
      x = min(x, nums2.front());
      y = max(y, nums2.back());
    }
    int l = x, r = y + 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      int l1 = lower_bound(nums1.begin(), nums1.end(), m) - nums1.begin();
      int u1 = upper_bound(nums1.begin(), nums1.end(), m) - nums1.begin();
      int l2 = lower_bound(nums2.begin(), nums2.end(), m) - nums2.begin();
      int u2 = upper_bound(nums2.begin(), nums2.end(), m) - nums2.begin();
      int ll = l1 + l2 + 1;
      int uu = u1 + u2;
    }
  }
};

int main() {
  return 0;
}
