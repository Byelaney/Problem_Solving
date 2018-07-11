Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums, int start) {
    vector<vector<int>> subset;
    if (nums.empty()) {
        vector<int> empty;
        subset.push_back(empty);
    }
    else {
        if (start < nums.size()) {
            if (nums.size() - start == 1) {
                vector<int> empty;
                vector<int> selfV{nums[start]};
                subset.push_back(empty);
                subset.push_back(selfV);
            }
            else {
                vector<vector<int>> postfix = subsets(nums, start+1);
                for (auto innerV : postfix) {
                    subset.push_back(innerV);
                    vector<int> wanted(innerV);
                    wanted.push_back(nums[start]);
                    subset.push_back(wanted);
                }
            }
        }
    }
    return subset;
}

vector<vector<int>> subsets(vector<int>& nums) {
    return subsets(nums, 0);
}
};
