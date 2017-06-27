Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < nums.size(); ++i) {
        if (mp.count(nums[i])) {
            mp[nums[i]].push_back(i);
        }
        else {
            vector<int> v{i};
            mp[nums[i]] = v;
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (mp[nums[i]].size() > 1) {
            vector<int> v = mp[nums[i]];
            for (int j = 0; j < v.size(); ++j) {
                if (i == v[j]) continue;
                else {
                    if (abs(v[j] - i) <= k) return true;
                }
            }
        }
    }
    return false;
}
};
