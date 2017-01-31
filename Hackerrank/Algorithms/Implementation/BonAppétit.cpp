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
		cin >> v[i];
	int sum = 0;
	for (int i = 0;i < k;++i)
		sum += v[i];
	for (int i = k + 1;i < n;++i)
		sum += v[i];
	sum /= 2;
	int bill;
	cin >> bill;
	if (bill <= sum)
		cout << "Bon Appetit" << endl;
	else
		cout << bill - sum << endl;
	return 0;
}
