S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.

Return any permutation of T (as a string) that satisfies this property.

Example :
Input:
S = "cba"
T = "abcd"
Output: "cbad"
Explanation:
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a".
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.


Note:

S has length at most 26, and no character is repeated in S.
T has length at most 200.
S and T consist of lowercase letters only.

class Solution {
    public String duplicate(char c, int counts) {
        String s = "";
        for (int i = 0; i < counts; ++i) s += c;
        return s;
    }

    public String customSortString(String S, String T) {
        Map<Character, Integer> table = new HashMap<>();
        for (int i = 0; i < S.length(); ++i) table.put(S.charAt(i), i);
        char[] res = new char[Math.max(S.length(), T.length())];
        for (int i = 0; i < res.length; ++i) res[i] = ' ';
        for (Map.Entry<Character, Integer> entry : table.entrySet())
            res[entry.getValue()] = entry.getKey();
        Map<Character, Integer> counts = new HashMap<>();
        for (int i = 0; i < T.length(); ++i) {
            if (table.containsKey(T.charAt(i))) {
                if (counts.containsKey(T.charAt(i)))
                    counts.put(T.charAt(i), 1+counts.get(T.charAt(i)));
                else counts.put(T.charAt(i), 1);
            }
        }
        String result = "";
        for (int i = 0; i < res.length; ++i) {
            if (res[i] != ' ')
                result += duplicate(res[i], counts.getOrDefault(res[i], 0));
        }
        for (int i = 0; i < T.length(); ++i) {
            if (!table.containsKey(T.charAt(i)))
                result += T.charAt(i);
        }
        return result;
    }
}
