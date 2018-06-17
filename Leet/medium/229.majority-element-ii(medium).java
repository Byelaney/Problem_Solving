Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]

class Solution {
    public List<Integer> majorityElement(int[] nums) {
        if (nums == null || nums.length == 0)
            return new ArrayList<Integer>();
        int m1 = nums[0], m2 = nums[0], c1 = 0, c2 = 0;
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == m1) c1++;
            else if (nums[i] == m2) c2++;
            else if (c1 == 0) {
                m1 = nums[i];
                c1 = 1;
            }
            else if (c2 == 0) {
                m2 = nums[i];
                c2 = 1;
            }
            else {
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == m1) c1++;
            else if (nums[i] == m2) c2++;
        }
        if (c1 > nums.length / 3)
            result.add(m1);
        if (c2 > nums.length / 3)
            result.add(m2);
        return result;
    }
}
