Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseNode(ListNode* head) {
    if (!head) return head;
    ListNode* prev = head;
    ListNode* cur = prev->next;
    prev->next = NULL;
    ListNode* next;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
        if (!fast) break;
        fast = fast->next;
    }
    ListNode* r = reverseNode(slow);
    while (r) {
        if (head->val != r->val) return false;
        head = head->next;
        r = r->next;
    }
    return true;
}
};
