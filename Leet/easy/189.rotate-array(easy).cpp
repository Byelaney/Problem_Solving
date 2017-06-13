Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    int l = (int)nums.size() - (k % nums.size());
    int r = (int)nums.size() - 1;
    vector<int> tmp;
    for (int i = l; i <= r; ++i)
        tmp.push_back(nums[i]);
    for (int i = 0; i < l; ++i)
        tmp.push_back(nums[i]);
    for (int i = 0; i < nums.size(); ++i)
        nums[i] = tmp[i];
}
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};
