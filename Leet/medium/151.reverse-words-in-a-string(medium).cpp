Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

class Solution {
public:
    void reverseWord(string &s, int l, int r) {
    while (l < r)
        swap(s[l++], s[r--]);
}

void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    int l = 0, r = 0;
    while (r < s.size() && s[r] == ' ') r++;
    while (l < s.size()) {
        while (r < s.size() && s[r] != ' ') r++;
        reverseWord(s, l, r - 1);
        while(l < s.size() && s[l] != ' ') l++;
        l++;
        while (r < s.size() && s[r] == ' ') r++;
    }
    int space = (int) s.size() - 1;
    while (space >= 0 && s[space] == ' ') space--;
    s.resize(space + 1);
}
};
