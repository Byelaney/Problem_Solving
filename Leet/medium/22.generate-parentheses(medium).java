Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

class Solution {
    private void backtracking(String s, int l, int r, List<String> paras, int max) {
        if (s.length() == 2 * max) {
            paras.add(s);
            return;
        }
        if (l < max) backtracking(s + "(", l + 1, r, paras, max);
        if (l > r) backtracking(s + ")", l, r + 1, paras, max);
    }

    public List<String> generateParenthesis(int n) {
        List<String> paras = new ArrayList<>();
        backtracking("", 0, 0, paras, n);
        return paras;
    }
}
