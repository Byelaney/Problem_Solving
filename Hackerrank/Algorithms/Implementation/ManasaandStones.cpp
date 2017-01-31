#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	int T, n, a, b;
	cin >> T;
	while (T--)
	{
		cin >> n >> a >> b;
		int l = min(a, b)*(n - 1);
		int r = max(a, b)*(n - 1);
		int diff = abs(a - b);
		unordered_set<int> uset;
		uset.insert(l);
		uset.insert(r);
		while (l < r)
		{
			l += diff;
			uset.insert(l);
		}
		vector<int> v;
		for (unordered_set<int>::iterator it = uset.begin(); it != uset.end(); ++it)
			v.push_back(*it);
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); ++i)
			cout << v[i] << " ";
		cout << endl;
	}
	return 0;
}
