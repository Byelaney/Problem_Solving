You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, new Comparator<int[]>(){
            public int compare(int[] arr1, int[] arr2){
                if(arr1[0] == arr2[0])
                    return arr2[1] - arr1[1];
                else
                    return arr1[0] - arr2[0];
            }
        });
        int[] dp = new int[envelopes.length];
        int len = 0;
        for (int i = 0; i < envelopes.length; ++i) {
            int index = Arrays.binarySearch(dp, 0, len, envelopes[i][1]);
            if (index < 0) {
                index = -(index + 1);
            }
            dp[index] = envelopes[i][1];
            if (index == len) len++;
        }
        return len;
    }
}
