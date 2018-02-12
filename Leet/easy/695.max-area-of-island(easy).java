Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.

class Solution {
    boolean isLegal(int m, int n, int i, int j) {
        return ((i >= 0 && j >= 0)&&(i < m && j < n));
    }

    int maxAreaOfIsland(int[][] grid) {
        int max_area = 0;
        Stack<Integer> row = new Stack<>();
        Stack<Integer> col = new Stack<>();
        int[] r = {-1,1,0,0};
        int[] c = {0,0,-1,1};
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[i].length; ++j) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    row.push(i);
                    col.push(j);
                    while (!row.empty()) {
                        int row_i = row.pop();
                        int col_j = col.pop();
                        if (grid[row_i][col_j] == 1) {
                            grid[row_i][col_j] = 0;
                            area++;
                        }
                        for (int cur = 0; cur < r.length; ++ cur) {
                            if (isLegal(grid.length, grid[row_i].length, row_i+r[cur], col_j+c[cur]) && (grid[row_i+r[cur]][col_j+c[cur]] == 1)) {
                                row.push(row_i+r[cur]);
                                col.push(col_j+c[cur]);
                            }
                        }
                    }
                    max_area = Math.max(max_area, area);
                }
            }
        }
        return max_area;
    }
}

class Solution {
    int[][] grid;
    boolean[][] seen;

    public int area(int r, int c) {
        if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length ||
                seen[r][c] || grid[r][c] == 0)
            return 0;
        seen[r][c] = true;
        return (1 + area(r+1, c) + area(r-1, c)
                  + area(r, c-1) + area(r, c+1));
    }

    public int maxAreaOfIsland(int[][] grid) {
        this.grid = grid;
        seen = new boolean[grid.length][grid[0].length];
        int ans = 0;
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                ans = Math.max(ans, area(r, c));
            }
        }
        return ans;
    }
}
