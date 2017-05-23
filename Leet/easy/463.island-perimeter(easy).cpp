You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
    int perimeter = 0;
    vector<int> v(4);
    for (int i = 0 ; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j]) {
                v.clear();
                v[0] = (j == 0) ? 0 : grid[i][j-1];
                v[1] = (i == 0) ? 0 : grid[i-1][j];
                v[2] = (j == grid[i].size() - 1) ? 0 : grid[i][j+1];
                v[3] = (i == grid.size() - 1) ? 0 : grid[i+1][j];
                perimeter += (4 - v[0] - v[1] - v[2] - v[3]);
            }
        }
    }
    return perimeter;
}
};
