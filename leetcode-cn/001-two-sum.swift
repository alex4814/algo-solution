class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var numsToIndex = [Int: Int]();
        for (u, num) in nums.enumerated() {
            let r = target - num
            if let v = numsToIndex[r] {
                return [u, v]
            }
            numsToIndex[num] = u
        }
        return []
    }
}
