class Solution {
    func isPowerOfTwo(_ n: Int) -> Bool {
        var x = 1;
        while x < n {
            x <<= 1;
        }
        return x == n
    }
}
