#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0;i < n;++i)
	{
		cin >> v[i];
	}
	int energy = 100;
	int i = k % n;
	energy -= 2 * v[i] + 1;
	while (i != 0)
	{
		i = (i + k) % n;
		energy -= 2 * v[i] + 1;
	}
	cout << energy << endl;
	return 0;
}
