Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (auto num : nums) m[num]++;
    vector<vector<int>> bucket(nums.size()+1);
    for (auto it : m) {
        int ith = it.second;
        bucket[ith].push_back(it.first);
    }
    vector<int> v;
    for (int i = (int)bucket.size()-1; i >= 0; --i) {
        vector<int> ith = bucket[i];
        for (auto num : ith) {
            v.push_back(num);
            k--;
            if (k == 0) return v;
        }
    }
    return v;
}
};
