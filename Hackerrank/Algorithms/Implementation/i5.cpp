#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int arr_i = 0; arr_i < n; arr_i++) {
		cin >> arr[arr_i];
	}

	sort(arr.begin(), arr.end());
	int i = 0;
	while (i < n)
	{
		int sum = 0;
		int min = arr[i];
		for (int j = i; j < n; ++j)
		{
			arr[j] -= min;
			sum += 1;
		}
		cout << sum << endl;
		while (i < n && arr[i] == 0)
			++i;
	}

	return 0;
}
