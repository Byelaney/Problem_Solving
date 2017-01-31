#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   ios::sync_with_stdio(0);
	int n, d;
	cin >> n >> d;
	vector<int> v(n);
	for (int i = 0;i < n;++i)
		cin >> v[i];
	int triplets = 0;
	for (int i = 0;i < n - 2;++i)
	{
		for (int j = i + 1;j < n - 1;++j)
		{
			if (v[i] + d > v[j]) continue;
			else if (v[i] + d == v[j])
			{
				for (int k = j + 1;k < n;++k)
				{
					if (v[j] + d > v[k]) continue;
					else if (v[j] + d == v[k])
						triplets++;
					else
						break;
				}
			}
			else
				break;
		}
	}
	cout << triplets << endl;
	return 0;
}
