In this problem you will be given a list of coin denominations and a target amount. Determine the number of ways the target amount can be arrived at using the denominations available.

Input Format

2 space-separated integers

 and : target amount, number of denominations
 space-separated integers

: unique coin denominations
Hints

Solve overlapping subproblems using Dynamic Programming (DP):
You can solve this problem recursively but will not pass all the test cases without optimizing to eliminate the overlapping subproblems. Think of a way to store and reference previously computed solutions to avoid solving the same subproblem multiple times.
Consider the degenerate cases:
How many ways can you make change for  cents?
How many ways can you make change for  cents if you have no coins?
If you're having trouble defining your solutions store, then think about it in terms of the base case .
The answer may be larger than a -bit integer.
Output Format

Print a long integer denoting the number of ways we can get a sum of  from the given infinite supply of  types of coins.

Sample Input 0

4 3
1 2 3
Sample Output 0

4
Explanation 0

Given coins of denominations [1, 2, 3] and a target amount of 4, the following 4 sets of coins meet the goal:
[1, 1, 1, 1], [1, 1, 2], [2, 2] and [1, 3].

Sample Input 1

10 4
2 5 3 6
Sample Output 1

5
Explanation 1

Given coins of denominations [2, 5, 3, 6] and a target amount of , the following  sets of coins meet the goal:
[2, 2, 2, 2, 2], [2, 2, 3, 3], [ 2, 2, 6], [2, 3, 5], [5, 5]

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ULL unsigned long long

/**

 C(S[], n, m) = C(S[], n, m-1) + C(S[], n - S[m-1], m)

 C(n, m) = C(n, m-1) + C(n - S[m-1], m)

 C(1, 0) = C(1, 0-1) + C(1 - S[-1], 0)
 C(1, 1) = C(1, 1-1) + C(1 - S[0], 1) = C(1, 0) + C(0, 1)


 example : n = 4, m = 3
 S[] = {1, 2, 3}
    0 1  2 3
 0: 1 1  1 1
 1: 0 烫 烫 烫
 2: 0 烫 烫 烫
 3: 0 烫 烫 烫
 4: 0 烫 烫 烫


**/

ULL count(ULL S[], ULL m, ULL n) {
    ULL dp[n+1][m+1];
    // if amount = 0, m >= 0, always has 1 count(empty change)
    for (ULL col = 0; col < m+1; ++col)
        dp[0][col] = 1;
    // no coin then 0 count
    for (ULL row = 1; row < n+1; ++row)
        dp[row][0] = 0;

    for (ULL i = 1; i < n+1; ++i) {
        for (ULL j = 1; j < m+1; ++j) {
            if (i < S[j-1])
                dp[i][j] = dp[i][j-1];
            else
                dp[i][j] = dp[i][j-1] + dp[i-S[j-1]][j];
        }
    }
    return dp[n][m];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ULL n, m;
    cin >> n >> m;
    ULL S[m];
    for (ULL i = 0; i < m; ++i) cin >> S[i];
    cout << count(S, m, n) << endl;
    return 0;
}
