Implement int sqrt(int x).

Compute and return the square root of x.


class Solution {
public:
    int mySqrt(int x) {
    long long lo = 1, hi = x;
    long long mid = 0;
    while (lo <= hi) {
        mid = (hi - lo)/2 + lo;
        if (mid * mid == x) return (int)mid;
        else if (mid * mid < x) lo = mid + 1;
        else if (mid * mid > x) hi = mid - 1;
    }
    return (int)((mid * mid > x)? mid - 1:mid);
}
};
