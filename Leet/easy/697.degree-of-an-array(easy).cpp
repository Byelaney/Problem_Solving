Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, int> ump;
    int max_count = 0;
    for (auto num : nums) {
        if (ump.count(num)) {
            ump[num]++;
        }
        else ump[num] = 1;
        max_count = max(max_count, ump[num]);
    }
    vector<int> v;
    for (auto entry : ump) {
        if (entry.second == max_count)
            v.push_back(entry.first);
    }
    int shortest = (int) nums.size();
    for (auto num : v) {
        int i = 0, j = (int) nums.size() - 1;
        while (i < nums.size()) {
            if (nums[i] == num) break;
            else i++;
        }
        while (j >= 0) {
            if (nums[j] == num) break;
            else j--;
        }
        shortest = min(shortest, j - i + 1);
    }
    return shortest;
}
};
