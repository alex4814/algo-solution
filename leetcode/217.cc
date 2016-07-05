
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, bool> hm;
    for (int x: nums) {
      if (hm.find(x) != hm.end()) return true;
      hm.insert({x, true});
    }
    return false;
  }
};
