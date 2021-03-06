Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.

public class Solution {
    public String[] findRelativeRanks(int[] nums) {
    String[] res = new String[nums.length];
    for (int i = 0; i < nums.length; i++) {
        res[i] = String.valueOf(nums[i]);
    }

    Arrays.sort(nums);

    for (int i = 0; i < res.length; i++) {
        int n = Integer.valueOf(res[i]);
        int rank = res.length - Arrays.binarySearch(nums, n);
        if (rank == 1) {
            res[i] = "Gold Medal";
        } else if (rank == 2) {
            res[i] = "Silver Medal";
        } else if (rank == 3) {
            res[i] = "Bronze Medal";
        } else {
            res[i] = String.valueOf(rank);
        }
    }
    return res;
}
}
