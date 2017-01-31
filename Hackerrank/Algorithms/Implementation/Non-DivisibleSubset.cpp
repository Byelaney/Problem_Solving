#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	unordered_map<int, int> ump1;
	unordered_map<int, int> ump2;
	int num = 0;
	int divide_zero = 0;
	int result = 0;
	int half = 0;
	while (n--)
	{
		cin >> num;
		if (num%k == 0)
			divide_zero++;
		else
		{
			int remainder = num%k;
			if (k % 2 == 0 && remainder * 2 == k)
			{
				half++;
				continue;
			}
			if (ump1.count(k - remainder) == 1)
			{
				// shoud be put in map2
				if (ump2.count(remainder) == 1)
					ump2[remainder]++;
				else
					ump2[remainder] = 1;
			}
			else
			{
				if (ump1.count(remainder) == 1)
					ump1[remainder]++;
				else
					ump1[remainder] = 1;
			}
		}
	}
	if (divide_zero != n && divide_zero > 0)
		result++;
	for (unordered_map<int, int>::iterator it = ump1.begin(); it != ump1.end(); ++it)
	{
		if (ump2.count(k - it->first) == 0)
			result += it->second;
		else
			result += (it->second > ump2[k - it->first]) ? (it->second) : (ump2[k - it->first]);
	}
	if (half)
		result++;
	cout << result << endl;
	return 0;
}
