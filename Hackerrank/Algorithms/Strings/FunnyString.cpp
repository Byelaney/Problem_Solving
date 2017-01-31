#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   ios::sync_with_stdio(0);
	int t;
	cin >> t;
	string s, j;
	while (t--)
	{
		cin >> s;
		j = s;
		reverse(s.begin(), s.end());
		bool funny = true;
		for (int i = 1;i < j.size();++i)
		{
			int left = j[i] - j[i - 1];
			int right = s[i] - s[i - 1];
			if (left == right || (left + right == 0))
				continue;
			else
			{
				funny = false;
				break;
			}
		}
		if (funny)
			cout << "Funny" << endl;
		else
			cout << "Not Funny" << endl;
	}
	return 0;
}
