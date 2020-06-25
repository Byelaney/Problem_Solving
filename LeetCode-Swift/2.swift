/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var carry = 0
        var t1: ListNode? = l1
        var t2: ListNode? = l2
        let head: ListNode? = ListNode(-1)
        var tmp = head

        while t1 != nil && t2 != nil {
            let sum = t1!.val + t2!.val + carry
            tmp?.next = ListNode(sum % 10)
            carry = sum / 10

            t1 = t1?.next
            t2 = t2?.next
            tmp = tmp?.next
        }

        if t1 != nil {
            tmp = traverse(result: tmp, tNode: t1, carry: &carry)
        }
        else if t2 != nil {
            tmp = traverse(result: tmp, tNode: t2, carry: &carry)
        }

        if carry > 0 {
            tmp?.next = ListNode(carry)
        }

        return head?.next
    }

    func traverse(result: ListNode?, tNode: ListNode?, carry: inout Int) -> ListNode? {
        var t = tNode
        var r = result

        while t != nil {
            let sum = t!.val + carry
            r?.next = ListNode(sum % 10)
            carry = sum / 10

            t = t?.next
            r = r?.next
        }

        return r
    }
}
