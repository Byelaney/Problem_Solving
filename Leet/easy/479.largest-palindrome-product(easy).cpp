Find the largest palindrome made from the product of two n-digit numbers.

Since the result could be very large, you should return the largest palindrome mod 1337.

Example:

Input: 2

Output: 987

Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

Note:

The range of n is [1,8].

class Solution {
public:
    long buildPalindrome(int half) {
    string left = to_string(half);
    string right = to_string(half);
    reverse(right.begin(), right.end());
    return stol(left + right);
}

    int largestPalindrome(int n) {
    if (n == 1) return 9;
    int upper = pow(10, n) - 1;
    int lower = pow(10, n-1);
    for (int i = upper; i >= lower; --i) {
        long cand = buildPalindrome(i);
        for (long j = upper; j*j > cand; --j) {
            if (cand%j == 0 && cand/j >= lower) return cand%1337;
        }
    }
    return -1;
}
};
