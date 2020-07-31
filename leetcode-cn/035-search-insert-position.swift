class Solution {
    func searchInsert(_ nums: [Int], _ target: Int) -> Int {
        var lo = 0, hi = nums.count
        while lo < hi {
            var mi = lo + (hi - lo) / 2
            if nums[mi] == target {
                return mi
            }
            if nums[mi] > target {
                hi = mi
            } else {
                lo = mi + 1
            }
        }
        return lo
    }
}
