#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int binary_search(vector<int> v, int aim)
{
	int l = 0;
	int r = v.size() - 1;
	int mid = 0;
	while (l <= r)
	{
		mid = (r - l) / 2 + l;
		if (v[mid] == aim) return mid;
		else if (v[mid] > aim)
			r = mid-1;
		else
			l = mid+1;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	int v, n;
	cin >> v >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << binary_search(arr, v) << endl;
	return 0;
}
