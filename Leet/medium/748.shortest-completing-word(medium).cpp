Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate. Such a word is said to complete the given string licensePlate

Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.

It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.

The license plate might have the same letter occurring multiple times. For example, given a licensePlate of "PP", the word "pair" does not complete the licensePlate, but the word "supper" does.

Example 1:
Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
Output: "steps"
Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
Note that the answer is not "step", because the letter "s" must occur in the word twice.
Also note that we ignored case for the purposes of comparing whether a letter exists in the word.
Example 2:
Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
Output: "pest"
Explanation: There are 3 smallest length words that contains the letters "s".
We return the one that occurred first.
Note:
licensePlate will be a string with length in range [1, 7].
licensePlate will contain digits, spaces, or letters (uppercase or lowercase).
words will have a length in the range [10, 1000].
Every words[i] will consist of lowercase letters, and have length in range [1, 15].

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
    string s;
    unordered_map<char, int> ump, wd;
    for (auto c : licensePlate) {
        char key = c;
        if (c >= 'A' && c <= 'Z') key = tolower(c);
        if (key >= 'a' && key <= 'z') {
            if (ump.count(key)) ump[key]++;
            else ump[key] = 1;
        }
    }
    int minimum = INT_MAX, id = 0;
    for (int i = 0; i < words.size(); ++i) {
        bool cand = true;
        wd.clear();
        for (auto c : words[i]) {
            if (wd.count(c)) wd[c]++;
            else wd[c] = 1;
        }
        unordered_map<char, int>::iterator it = ump.begin();
        while (it != ump.end()) {
            if ((!wd.count(it->first)) || wd[it->first] < it->second) {
                cand = false;
                break;
            }
            it++;
        }
        if (cand) {
            if (words[i].size() < minimum) {
                minimum = words[i].size();
                id = i;
            }
        }
    }
    return words[id];
}
};
