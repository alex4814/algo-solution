/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */
class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        let head = ListNode(0)
        var p = l1, q = l2, curr = head
        var c = 0
        while (p != nil || q != nil) {
            let a = (p != nil ? p!.val : 0)
            let b = (q != nil ? q!.val : 0)
            let sum = a + b + c
            curr.next = ListNode(sum % 10)
            curr = curr.next!
            c = sum / 10
            p = (p != nil ? p!.next : nil)
            q = (q != nil ? q!.next : nil)
        }
        if c > 0 {
            curr.next = ListNode(c)
        }
        return head.next
    }
}
