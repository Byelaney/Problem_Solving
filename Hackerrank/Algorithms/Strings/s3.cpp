#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool isBeautiful(string s)
{
	if (s.size() <= 2) return true;
	for (int i = 0; i < s.size() - 2; ++i)
	{
		if ((s[i] == '0' && s[i + 1] == '1') && s[i + 2] == '0')
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	int n;
	string s;
	cin >> n;
	cin >> s;
	int nums = 0;
	while (!isBeautiful(s))
	{
		for (int i = 0; i < s.size() - 2; ++i)
		{
			if ((s[i] == '0' && s[i + 1] == '1') && s[i + 2] == '0')
			{
				s[i + 2] = '1';
				nums++;
				break;
			}
		}
	}
	cout << nums << endl;
	return 0;
}
