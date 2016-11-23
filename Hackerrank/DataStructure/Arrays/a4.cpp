#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	vector<vector<int>> v(n);
	int type, x, y;
	int lastAns = 0;
	for (int i = 0; i < q; ++i)
	{
		cin >> type >> x >> y;
		if (type == 1)
			v[(x^lastAns) % n].push_back(y);
		else
		{
			vector<int> seq = v[(x^lastAns) % n];
			lastAns = seq[y%seq.size()];
			cout << lastAns << endl;
		}
	}
	return 0;
}
