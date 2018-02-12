Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first
4
 to
1
 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].

class Solution {
public:
    bool isSorted(vector<int>& nums, int l, int r) {
    if (l > r) return false;
    for (int i = l + 1; i <= r; ++i)
        if (nums[i - 1] > nums[i]) return false;
    return true;
}

bool checkPossibility(vector<int>& nums) {
    //[.... , x , ....]
    int x = -1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] > nums[i]) {
            x = i;
            break;
        }
    }
    if (x != -1) {
        vector<int> candiates {x, max(x-1, 0)};
        bool r = false;
        for (auto num : candiates) {
            int leftMax = (num == 0)? INT_MIN : nums[num-1];
            int rightMin = (num == nums.size()-1)? INT_MAX : nums[num+1];
            r |= (leftMax <= rightMin && isSorted(nums, min(num+1, (int)nums.size()-1), (int)nums.size()-1));
        }
        return r;
    }
    return true;
}

};

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
    int cnt = 0;                                                                    //the number of
    for(int i = 1; i < nums.size() && cnt<=1 ; i++){
        if(nums[i-1] > nums[i]){
            cnt++;
            if(i-2<0 || nums[i-2] <= nums[i])nums[i-1] = nums[i];                    //modify nums[i-1]
            else nums[i] = nums[i-1];                                                //have to modify
        }
    }
    return cnt<=1;
}

};

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for (int i=0; i < nums.size()-1; i++){
            if (nums[i] > nums[i+1]){

                int temp = nums[i];
                //
                // "erase" nums[i], then check if nums is sorted without nums[i]
                //
                nums[i] = nums[i+1];
                if (is_sorted(nums.begin(), nums.end())) { return true; }

                //
                // "erase" nums[i+1], then check if nums is sorted without nums[i+1]
                //
                nums[i+1] = nums[i] = temp;
                if (is_sorted(nums.begin(), nums.end())) { return true; }

                //
                // nums is NOT sorted (without nums[i] XOR without nums[i+1])
                //
                return false;
            }
        }
        return true;
    }

};
