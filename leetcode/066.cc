#include <vector>
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    for (int i = n - 1; ~i; --i) {
      digits[i] += 1;
      if (digits[i] < 10) {
        return digits;
      }
      digits[i] = 0;
    }
    vector<int> ret(n + 1, 0);
    ret[0] = 1;
    return ret;
  }
};


int main() {
  return 0;
}
