You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    vector<int> v1, v2;
    while(l1) {
        v1.push_back(l1->val);
        l1 = l1->next;
    }
    while(l2) {
        v2.push_back(l2->val);
        l2 = l2->next;
    }
    vector<int> v(1 + max(v1.size(), v2.size()));
    int offsets = 0, i = (int) v1.size() - 1, j = (int) v2.size() - 1;
    int cursor = (int) v.size() - 1;
    while (i >= 0 && j >= 0) {
        v[cursor--] = (offsets + v1[i] + v2[j]) % 10;
        offsets = (offsets + v1[i] + v2[j]) / 10;
        i--;j--;
    }
    while (i >= 0) {
        v[cursor--] = (offsets + v1[i]) % 10;
        offsets = (offsets + v1[i]) / 10;
        i--;
    }
    while (j >= 0) {
        v[cursor--] = (offsets + v2[j]) % 10;
        offsets = (offsets + v2[j]) / 10;
        j--;
    }
    v[cursor] = offsets;
    ListNode* head = new ListNode(-1);
    ListNode* tmp = head;
    for (int i = (offsets == 0)? 1:0; i < v.size(); ++i) {
        ListNode* node = new ListNode(v[i]);
        tmp->next = node;
        tmp = node;
    }
    return head->next;
}
};
