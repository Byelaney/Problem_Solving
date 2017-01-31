#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
   ios::sync_with_stdio(0);
	int n, num;
	cin >> n;
	unordered_map<int, int> ump;
	int max_count = 0;
	for (int i = 0;i < n; ++ i)
	{
		cin >> num;
		if (ump.count(num))
			ump[num]++;
		else
			ump[num] = 1;
		if (ump[num] > max_count)
			max_count = ump[num];
	}
	cout << n - max_count << endl;
	return 0;
}
