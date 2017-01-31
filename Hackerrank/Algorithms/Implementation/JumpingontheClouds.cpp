#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0;i < n;++i)
	{
		cin >> v[i];
	}
	int steps = 0;
	int i = 0;
	for (;i < n - 2;)
	{
		if (v[i + 2] != 1)
		{
			i = i + 2;
			steps++;
			continue;
		}
		steps++;i++;
	}
	if (i == n - 2)
		steps++;
	cout << steps << endl;
	return 0;
}
