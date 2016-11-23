#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int d_pos(int n, int d, int i)
{
	if (i - d >= 0)
		return i - d;
	else
		return n - (d - i);
}

int main()
{
	ios::sync_with_stdio(0);
	int n, d;
	cin >> n >> d;
	vector<int> v(n);
	int num;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		v[d_pos(n, d%n, i)] = num;
	}

	for (int i = 0; i < n; ++i)
		cout << v[i] << " ";
	return 0;
}
