Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]

class Solution {
public:
    string reverseStr(string s, int k) {
	string result = "", tmp = "", tmp2 = "";
	int left = 0;
	for (int i = 0; i < s.size(); i += 2 * k) {
		left = s.size() - i;
		if (left < k) {
			tmp = s.substr(i, left);
			tmp2 = "";
		}
		else if (left < 2 * k && left >= k) {
		    tmp = s.substr(i, k);
		    tmp2 = s.substr(i + k, left - k);
		}
		else {
		    tmp = s.substr(i, k);
		    tmp2 = s.substr(i + k, k);
		}

		reverse(tmp.begin(), tmp.end());
		result += tmp + tmp2;
	}
	return result;
}
};
