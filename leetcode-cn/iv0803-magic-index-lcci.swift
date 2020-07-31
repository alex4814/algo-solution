class Solution {
    func findMagicIndex(_ nums: [Int]) -> Int {
        return findMagicIndex(nums, between: (0, nums.count)) ?? -1
    }

    func findMagicIndex(_ nums: [Int], between range: (Int, Int)) -> Int? {
        if range.0 >= range.1 || range.0 > nums[range.1 - 1] || range.1 - 1 < nums[range.0] {
            return nil
        }
        if range.0 == nums[range.0] {
            return range.0
        }
        let middleIndex = range.0 + (range.1 - range.0) >> 1
        let leftRange = (range.0, middleIndex)
        if let magicIndex = findMagicIndex(nums, between: leftRange) {
            return magicIndex
        }
        let rightRange = (middleIndex, range.1)
        return findMagicIndex(nums, between: rightRange)
    }
}
