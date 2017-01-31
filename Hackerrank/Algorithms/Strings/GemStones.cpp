#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
   ios::sync_with_stdio(0);
	int n;
	cin >> n;
	unordered_set<char> uds, ucds;
	string s;
	cin >> s;n--;
	for (int i = 0;i < s.size();++i)
		uds.insert(s[i]);
	while (n--)
	{
		cin >> s;
		for (int i = 0;i < s.size();++i)
		{
			if (uds.count(s[i]))
				ucds.insert(s[i]);
		}
		uds = ucds;
		ucds.clear();
	}
	cout << uds.size() << endl;
	return 0;
}
