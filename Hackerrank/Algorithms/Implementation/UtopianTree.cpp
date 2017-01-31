#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
   ios::sync_with_stdio(0);
	int t, n;
	cin >> t;
	vector<int> arr(61);
	int tree = 1;
	arr[0] = 1;
	for (int i = 1;i < arr.size();++i) {
		if (i % 2 == 0) tree++;
		else tree *= 2;
		arr[i] = tree;
	}
	while (t--) {
		cin >> n;
		cout << arr[n] << endl;
	}
	return 0;
}
