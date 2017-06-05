You are given a string representing an attendance record for a student. The record only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False

class Solution {
public:
    bool checkRecord(string s) {
	int count_A = 0, count_L = 0, l_max = 0;
	char last = 'F';
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'A') {
		    count_A++;
		    count_L = 0;
		}
		if (s[i] == 'L' && last == 'L') {
		    count_L++;
		    l_max = max(l_max, count_L);
		}
		else count_L = 0;
		last = s[i];
	}
	if (count_A > 1 || l_max >= 2) return false;
	return true;
}
};
