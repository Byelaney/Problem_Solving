Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
Note:

0 < s1.length, s2.length <= 1000.
All elements of each string will have an ASCII value in [97, 122].

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
    // dp[i][j] means answer of s1[0, i] : s2[0, j]
    int dp[s1.size()+1][s2.size()+1];
    dp[0][0] = 0;
    for (int col = 0; col < s2.size(); ++col)
        dp[0][col+1] = dp[0][col] + (s2[col]);
    for (int row = 0; row < s1.size(); ++row)
        dp[row+1][0] = dp[row][0] + (s1[row]);
    for (int i = 0; i < s1.size(); ++i) {
        for (int j = 0; j < s2.size(); ++j) {
            // omit the same char, then dp[i][j] = dp[i-1][j-1]
            if (s1[i] == s2[j]) dp[i+1][j+1] = dp[i][j];
            else dp[i+1][j+1] = min(dp[i][j+1]+s1[i], dp[i+1][j]+s2[j]);
        }
    }
    return dp[s1.size()][s2.size()];
}
};
