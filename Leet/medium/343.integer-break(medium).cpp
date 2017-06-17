Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.

class Solution {
public:
    int integerBreak(int n) {
    vector<int> v(n+1);
    v[1] = 1;
    int max_pro = 0;
    for (int i = 2; i <= n; ++i) {
        max_pro = 0;
        for (int j = 1; j <= i/2+1; ++j) {
            int t_max = max(j * v[i-j], j * (i-j));
            max_pro = max(max_pro, t_max);
        }
        v[i] = max_pro;
    }
    return v[n];
}
};
