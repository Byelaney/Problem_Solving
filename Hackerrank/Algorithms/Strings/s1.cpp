#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
	string s;
	cin >> s;
	int upper = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] <= 'Z')
			upper++;
	}
	cout << upper + 1 << endl;
	return 0;
}
