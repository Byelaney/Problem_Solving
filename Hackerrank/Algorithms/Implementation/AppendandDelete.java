import java.util.*;

class Solution {

    public static boolean solve(char[] s, char[] t, int k) {
        // We have more operations than we need to delete and rewrite the string
        if (s.length + t.length < k) {
            return true;
        }

        // Iterate through string matching characters
        int i = -1;
        while(i++ < Math.min(s.length, t.length) - 1) {
            if (s[i] != t[i]) {
                break;
            }
        }

        // The strings are the same
        if (i == s.length && s.length == t.length) {
            // if k is odd, there will always be 1 operation left over
            // else, you can delete and re-append last character to use up k operations
            return ((k & 1) == 1) ? false : true;
        }

        // Else
        // Reduce k by number of necessary deletions and insertions
        k = k - (s.length - i) - (t.length - i);

        // If k < 0 or there is an odd number of operations left over, false
        // else we need exactly k operations or the number of extra ops is even, true
        return (k < 0 || (k & 1) == 1) ? false : true;

    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        String t = in.next();
        int k = in.nextInt();
        in.close();

        System.out.println( (solve(s.toCharArray(), t.toCharArray(), k))
                           ? "Yes"
                           : "No"
                           );
    }
}
