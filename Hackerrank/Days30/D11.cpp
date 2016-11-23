#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
	vector<vector<int>> ary(6);
	for (int row = 0; row < 6; ++row)
	{
		vector<int> v_row(6);
		for (int col = 0; col < 6; ++col)
		{
			cin >> v_row[col];
		}
		ary[row] = v_row;
	}
	int max = -100000;
	for (int row = 0; row < 4; ++row)
	{
		for (int col = 0; col < 4; ++col)
		{
			int tmp = ary[row][col] + ary[row][col + 1] + ary[row][col + 2];
			tmp += ary[row + 1][col + 1];
			tmp += ary[row + 2][col] + ary[row + 2][col + 1] + ary[row + 2][col + 2];
			if (tmp > max)
				max = tmp;
		}
	}
	cout << max << endl;
	return 0;
}
