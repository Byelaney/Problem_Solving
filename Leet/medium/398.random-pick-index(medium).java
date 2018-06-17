Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);

import java.util.concurrent.ThreadLocalRandom;

class Solution {
    Map<Integer, List<Integer>> dict;
    public Solution(int[] nums) {
        dict = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (dict.containsKey(nums[i])) {
                List<Integer> val = dict.get(nums[i]);
                val.add(i);
            }
            else {
                List<Integer> val = new ArrayList<>();
                val.add(i);
                dict.put(nums[i], val);
            }
        }
    }

    public int pick(int target) {
        List<Integer> list = dict.get(target);
        int randomNum = ThreadLocalRandom.current().nextInt(0, list.size());
        return list.get(randomNum);
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
