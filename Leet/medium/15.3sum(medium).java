Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int target = -nums[i];
                int front = i+1, back = nums.length - 1;
                while (front < back) {
                    if (nums[front] + nums[back] == target) {
                        res.add(Arrays.asList(nums[i], nums[front], nums[back]));
                        while (front < back && (nums[front] == nums[front+1])) front++;
                        while (front < back && (nums[back] == nums[back-1])) back--;
                        front++; back--;
                    }
                    else if (nums[front] + nums[back] > target) back--;
                    else front++;
                }
            }
        }
        return res;
    }
}
