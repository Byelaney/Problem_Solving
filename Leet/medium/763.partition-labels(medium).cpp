A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.

vector<int> partitionLabels(string S) {
    vector<int> partion;
    vector<int> s(26, S.size());
    vector<int> e(26, 0);
    vector<bool> checked(26, false);
    for (int i = 0; i < S.size(); ++i) {
        s[S[i]-'a'] = min(i, s[S[i]-'a']);
        e[S[i]-'a'] = max(i, e[S[i]-'a']);
    }
    int l = s[S[0]-'a'], r = e[S[0]-'a'];
    for (int i = 1; i < S.size(); ++i) {
        if (checked[S[i]-'a']) continue;
        checked[S[i]-'a'] = true;
        int cl = s[S[i]-'a'];
        int cr = e[S[i]-'a'];
        if (cl >= l && cr <= r) continue;
        else if (cl > r) {
            partion.push_back(r-l+1);
            l = cl;
            r = cr;
        }
        else {
            l = min(l, cl);
            r = max(r, cr);
        }
        if (r == S.size()-1) {
            partion.push_back(r-l+1);
            break;
        }
    }
    if (r == S.size()-1 && partion.empty()) partion.push_back(r-l+1);
    return partion;
}
