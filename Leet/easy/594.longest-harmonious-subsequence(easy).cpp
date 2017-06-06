We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.

class Solution {
public:
    int findLHS(vector<int>& nums) {
    unordered_map<int, int> ump;
    for (int i = 0; i < nums.size(); ++i) {
        if (ump.count(nums[i]))
            ump[nums[i]]++;
        else
            ump[nums[i]] = 1;
    }
    int maxHS = 0;
    for (unordered_map<int, int>::iterator it = ump.begin(); it != ump.end(); ++it) {
        if (ump.count(it->first + 1))
            maxHS = max(maxHS, it->second + ump[it->first + 1]);
        if (ump.count(it->first - 1))
            maxHS = max(maxHS, it->second + ump[it->first - 1]);
    }
    return maxHS;
}
};
