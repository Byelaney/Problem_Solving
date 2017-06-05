Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
	int boomerangs = 0;
	unordered_map<int, int> distance;
	int x = 0, y = 0, d_square = 0;
	for (int i = 0; i < points.size(); ++i) {
		for (int j = 0; j < points.size(); ++j) {
			if (i != j) {
				x = points[i].first - points[j].first;
				y = points[i].second - points[j].second;
				d_square = x * x + y * y;
				if (distance.count(d_square))
					distance[d_square] += 1;
				else
					distance[d_square] = 1;
			}
		}
		for (unordered_map<int, int>::iterator it = distance.begin(); it != distance.end(); ++it) {
			boomerangs += it->second * (it->second - 1);
		}
		distance.clear();
	}
	return boomerangs;
}
};
