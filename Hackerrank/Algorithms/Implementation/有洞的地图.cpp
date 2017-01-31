#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<string> v(n);
	vector<string> r(n);
	string s;
	for (int i = 0;i < n;++i)
	{
		cin >> s;
		v[i] = s;
		r[i] = s;
	}
	for (int row = 1;row < n - 1;++row)
	{
		for (int col = 1;col < n - 1;++col)
		{
			int hole = v[row][col] - '0';
			int up = v[row - 1][col] - '0';
			int down = v[row + 1][col] - '0';
			int left = v[row][col - 1] - '0';
			int right = v[row][col + 1] - '0';
			if (hole > up && hole > down)
			{
				if (hole > left && hole > right)
					r[row][col] = 'X';
			}
		}
	}
	for (int row = 0;row < n;++row)
	{
		for (int col = 0;col < n;++col)
			cout << r[row][col];
		cout << endl;
	}
	return 0;
}
