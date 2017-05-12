Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row1 {'q', 'w', 'e', 'r', 't', 'y','u', 'i', 'o', 'p'};
        unordered_set<char> row2 {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        unordered_set<char> row3 {'z', 'x', 'c', 'v', 'b' ,'n', 'm'};
        vector<unordered_set<char>> rows {row1, row2, row3};

        vector<string> res;
        for(string& word : words){
            int row = -1;
            for(int i=0; i<3; i++)
                if(rows[i].count(tolower(word[0])) > 0)
                    row = i;

            if (row==-1) continue;

            bool valid = true;
            for(int j=1,sz=word.size();j<sz;j++){
                if(rows[row].count(tolower(word[j])) == 0){
                    valid = false;
                    break;
                }
            }
            if (valid) res.push_back(word);
        }
        return res;
    }
};
