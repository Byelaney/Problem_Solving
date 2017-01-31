#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	string a, b;
	while (t--)
	{
		vector<bool> a1(26), b1(26);
		bool two_string = false;
		cin >> a >> b;
		for (auto c : a)
			a1[c - 'a'] = true;
		for (auto c : b)
			b1[c - 'a'] = true;
		for (int i = 0; i < a1.size(); ++i)
		{
			if (a1[i] == true && b1[i] == true)
			{
				two_string = true;
				break;
			}
		}
		if (two_string) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
