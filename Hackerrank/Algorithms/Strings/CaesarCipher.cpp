#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int n, k;
	cin >> n;
	string s;
	cin >> s;
	cin >> k;
	for (int i = 0;i < n;++i)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			// 65 - 90
			char c = s[i] + k % 26;
			if (s[i] + k % 26 > 90)
				c -= 26;
			cout << c;
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			// 97 - 122
			char c = s[i] + k % 26;
			if (s[i] + k % 26 > 122)
				c -= 26;
			cout << c;
		}
		else
			cout << s[i];
	}
	cout << endl;
	return 0;
}
