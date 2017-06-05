Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False

class Solution {
public:
    bool isPerfectSquare(int num) {
	int lo = 1, hi = num;
	while (lo <= hi) {
		long mi = (hi - lo) / 2 + lo;
		if (mi * mi == num) return true;
		else if (mi * mi < num) lo = mi + 1;
		else hi = mi - 1;
	}
	return false;
}
};
