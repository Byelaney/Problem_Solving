Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.



Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false


Note:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letters.

class Solution {
public:
    bool buddyStrings(string A, string B) {
    if (A.size() != B.size()) return false;
    int i = -1, j = -1;
    unordered_map<char, int> dict;
    bool swp = false;
    for (int k = 0; k < B.size(); ++k) {
        if (A[k] != B[k]) {
            if (i == -1) i = k;
            else if (j == -1) j = k;
            else return false;
        }
        if (dict.count(A[k]) >= 1) {
            swp = true;
            continue;
        }
        if (dict.count(A[k])) dict[A[k]]++;
        else dict[A[k]] = 1;
    }
    if (i == -1 || j == -1) {
        return swp;
    }
    return (A[i] == B[j] && A[j] == B[i]);
}
};
