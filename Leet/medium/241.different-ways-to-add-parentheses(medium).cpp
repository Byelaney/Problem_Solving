Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]


class Solution {
public:
    // Memoization
    unordered_map<string, vector<int>> memo;
    int operate(int a, int b, char opt) {
    if (opt == '+') return a+b;
    else if(opt == '-') return a-b;
    else return a*b;
}

vector<int> diffWaysToCompute(string input) {
    vector<int> v;
    if (memo.count(input)) return memo[input];
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i+1, input.size()-i-1));
            for (auto a : left) {
                for (auto b : right) {
                    v.push_back(operate(a, b, input[i]));
                }
            }
        }
    }
    if (v.empty() && (!input.empty())) v.push_back(stoi(input));
    memo[input] = v;
    return v;
}
};
