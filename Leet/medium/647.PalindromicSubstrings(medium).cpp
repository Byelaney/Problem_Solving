Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.

class Solution {
public:
    int countSubstrings(string s) {
    int n = (int)s.size();
    int res = 0;
    bool dp[n][n];
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            dp[i][j] = s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1]);
            if(dp[i][j]) ++res;
        }
    }
    return res;
}
};

class Solution {
public:
    bool palindromic(string s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;r--;
    }
    return true;
}

int countSubstrings(string s) {
    int counts = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i; j < s.size(); ++j) {
            if (palindromic(s, i, j)) counts++;
        }
    }
    return counts;
}
};
