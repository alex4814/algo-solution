#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n2 < n1) {
      return findMedianSortedArrays(nums2, nums1);
    }
    if (n1 == 0) {
      return (nums2[(n2 - 1) / 2] + nums2[n2 / 2]) / 2.0;
    }
    int low = 0, high = (n1 << 1 | 1);
    while (low < high) {
      int k1 = low + (high - low) / 2;
      int k2 = n1 + n2 - k1;
      int l1 = k1 == 0 ? INT_MIN : nums1[(k1 - 1) / 2];
      int r1 = k1 == 2 * n1 ? INT_MAX : nums1[k1 / 2];
      int l2 = k2 == 0 ? INT_MIN : nums2[(k2 - 1) / 2];
      int r2 = k2 == 2 * n2 ? INT_MAX : nums2[k2 / 2];
      if (l1 <= r2 && l2 <= r1) {
        return (max(l1, l2) + min(r1, r2)) / 2.0;
      } else if (l1 > r2) {
        high = k1;
      } else {
        low = k1 + 1;
      }
    }
    return -1;
  }
};

int main() {
  return 0;
}
