Alice is a kindergarten teacher. She wants to give some candies to the children in her class.  All the children sit in a line (their positions are fixed), and each  of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. Alice wants to save money, so she needs to minimize the total number of candies given to the children.

Input Format

The first line of the input is an integer , the number of children in Alice's class. Each of the following  lines contains an integer that indicates the rating of each child.

Constraints

Output Format

Output a single line containing the minimum number of candies Alice must buy.

Sample Input 0

3
1
2
2
Sample Output 0

4
Explanation 0

Here 1, 2, 2 is the rating. Note that when two children have equal rating, they are allowed to have different number of candies. Hence optimal distribution will be 1, 2, 1.

Sample Input 1

10
2
4
2
6
1
7
8
9
2
1
Sample Output 1

19
Explanation 1

Optimal distribution will be

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ULL unsigned long long

ULL candies(ULL N, ULL rating[]) {
    if (N == 1) return 1;
    ULL dp[N];
    for (int i = 0; i < N; ++i) dp[i] = 1;
    for (int i = 1; i < N; ++i) {
        // forward iter
        if (rating[i] > rating[i-1]) dp[i] += dp[i-1];
    }
    for (int i = N-2; i >= 0; --i) {
        // backward iter
        if (rating[i] > rating[i+1] && dp[i] <= dp[i+1])
            dp[i] = dp[i+1] + 1;
    }
    ULL sum = 0;
    for (int i = 0; i < N; ++i) {
        // cout << dp[i] << " ";
        sum += dp[i];
    }
    return sum;
}

int main() {
    ULL N;
    cin >> N;
    ULL rating[N];
    for (int i = 0; i < N; ++i) cin >> rating[i];
    cout << candies(N, rating) << endl;
    return 0;
}
