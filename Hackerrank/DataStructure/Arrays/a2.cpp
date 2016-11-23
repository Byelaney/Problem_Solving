#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	unordered_map<string, int> ump;
	string s = "";
	while (n--)
	{
		cin >> s;
		if (ump.count(s))
			ump[s]++;
		else
			ump[s] = 1;
	}
	int q;
	cin >> q;
	string qs = "";
	while (q--)
	{
		cin >> qs;
		if (ump.count(qs))
			cout << ump[qs] << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
