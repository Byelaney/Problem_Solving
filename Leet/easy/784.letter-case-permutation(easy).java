Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length at most 12.
S will consist only of letters or digits.

class Solution {
    public List<String> letterCasePermutation(String S) {
        List<String> l = new ArrayList<>();
        if (S.isEmpty()) l.add("");
        else if (S.length() == 1) {
            if (S.charAt(0) >= '0' && S.charAt(0) <= '9')
                l.add(S);
            else {
                l.add(S.toLowerCase());
                l.add(S.toUpperCase());
            }
        }
        else {
            List<String> all = letterCasePermutation(S.substring(1, S.length()));
            for (String perm : all) {
                String s1 = "";
                if (S.charAt(0) >= '0' && S.charAt(0) <= '9') {
                    s1 = S.charAt(0) + perm;
                    l.add(s1);
                }
                else {
                    s1 = S.substring(0, 1).toLowerCase() + perm;
                    l.add(s1);
                    s1 = S.substring(0, 1).toUpperCase() + perm;
                    l.add(s1);
                }
            }
        }
        return l;
    }
}
