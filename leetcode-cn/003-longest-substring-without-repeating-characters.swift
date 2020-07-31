class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var characterToIndex = [Character: String.Index]()
        var lengthAtIndex = 0, length = 0
        for i in s.indices {
            let j = characterToIndex[s[i]] ?? i
            characterToIndex[s[i]] = i
            if i == j {
                lengthAtIndex = lengthAtIndex + 1
            } else {
                lengthAtIndex = min(lengthAtIndex + 1, s.distance(from: j, to: i))
            }
            length = max(length, lengthAtIndex)
        }
        return length
    }
}
