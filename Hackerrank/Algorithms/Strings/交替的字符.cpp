#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   ios::sync_with_stdio(0);
	int T;
	cin >> T;
	string s;
	while (T--)
	{
		cin >> s;
		if (s == "")
		{
			cout << "" << endl;
			continue;
		}
		char last = s[0];
		int least = 0;
		for (int i = 1;i < s.size();++i)
		{
			if (s[i] == last)
				least++;
			else
				last = s[i];
		}
		cout << least << endl;
	}
	return 0;
}
