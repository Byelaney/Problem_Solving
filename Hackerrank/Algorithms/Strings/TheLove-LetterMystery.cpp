#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   ios::sync_with_stdio(0);
	int t;
	string s;
	cin >> t;
	while (t--)
	{
		cin >> s;
		int l = 0;
		int r = (int)s.size() - 1;
		int steps = 0;
		while (l < r)
		{
			if (s[l] != s[r])
				steps += abs(s[l] - s[r]);
			l++;r--;
		}
		cout << steps << endl;
	}
	return 0;
}
