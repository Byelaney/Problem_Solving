#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++) {
		int n;
		int k;
		cin >> n >> k;
		vector<int> a(n);
		int arrived = 0;
		for (int a_i = 0; a_i < n; a_i++) {
			cin >> a[a_i];
			if (a[a_i] <= 0)
				arrived++;
		}
		if (arrived >= k)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
    return 0;
}
