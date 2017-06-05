Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5


class Solution {
public:
    int countSegments(string s) {
	int segments = 0;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == ' ' && s[i - 1] != ' ')
			segments++;
		else if (s[i] != ' ' && i == s.size() - 1)
			segments++;
	}
	return (s.size() == 1 && s[s.size() - 1] != ' ')? 1 : segments;
}
};
