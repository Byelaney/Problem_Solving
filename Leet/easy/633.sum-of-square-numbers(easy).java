Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False

class Solution {
    public boolean judgeSquareSum(int c) {
        int r = (int)Math.sqrt(c);
        for (int i = r; i >= 0; --i) {
            int left = c - i*i;
            int root = (int)Math.sqrt(left);
            if (root*root == left) return true;
        }
        return false;
    }
}
