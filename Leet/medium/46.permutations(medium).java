Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

class Solution {
    private List<List<Integer>> permute(int[] nums, int start) {
        List<List<Integer>> permutation = new ArrayList<>();
        if (start == nums.length - 1) {
            List<Integer> permu = new ArrayList<>();
            permu.add(nums[start]);
            permutation.add(permu);
        }
        else if (start < nums.length) {
            for (int i = start; i < nums.length; ++i) {
                int tmp = nums[start];
                nums[start] = nums[i];
                nums[i] = tmp;

                List<List<Integer>> post = permute(nums, start + 1);
                for (List<Integer> permutes : post) {
                    permutes.add(0, nums[start]);
                }
                tmp = nums[i];
                nums[i] = nums[start];
                nums[start] = tmp;

                permutation.addAll(post);
            }
        }
        return permutation;
    }

    public List<List<Integer>> permute(int[] nums) {
        return permute(nums, 0);
    }
}
