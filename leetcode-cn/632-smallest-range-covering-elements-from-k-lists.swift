class Solution {
    func smallestRange(_ nums: [[Int]]) -> [Int] {
        let numberArrays = arraysWhichNumbersIn(nums)
        let sortedNumbers = numberArrays.keys.sorted()
        
        var arraysHit = [Int: Int]()
        
        // Index range of arrays
        var currentRange = (0, -1)
        var range = (-1, -1)
        while true {
            if arraysHit.count != nums.count {
                currentRange.1 += 1
                if currentRange.1 == sortedNumbers.count {
                    break
                }
                let n = sortedNumbers[currentRange.1]
                for arrayIndex in numberArrays[n]! {
                    arraysHit[arrayIndex, default: 0] += 1
                }
            } else {
                // Update range if it is smaller or not initiated
                if range.0 == -1 || range.1 == -1 {
                    range = currentRange
                } else {
                    let a = sortedNumbers[currentRange.0]
                    let b = sortedNumbers[currentRange.1]
                    let c = sortedNumbers[range.0]
                    let d = sortedNumbers[range.1]
                    if (b - a < d - c) || (b - a == d - c && a < c) {
                        range = currentRange
                    }
                }
                // Remove
                let n = sortedNumbers[currentRange.0]
                for arrayIndex in numberArrays[n]! {
                    arraysHit[arrayIndex]! -= 1
                    if arraysHit[arrayIndex]! == 0 {
                        arraysHit[arrayIndex] = nil
                    }
                }
                currentRange.0 += 1
            }
        }
        return [sortedNumbers[range.0], sortedNumbers[range.1]]
    }
    
    func arraysWhichNumbersIn(_ nums: [[Int]]) -> [Int: [Int]] {
        var arrays = [Int: [Int]]()
        for (arrayIndex, numbers) in nums.enumerated() {
            for number in numbers {
                arrays[number, default: []].append(arrayIndex)
            }
        }
        return arrays
    }
}

