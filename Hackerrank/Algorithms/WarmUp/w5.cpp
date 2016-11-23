#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
	int n;
	cin >> n;
	double pos = 0;
	double neg = 0;
	double zero = 0;
	vector<int> arr(n);
	for (int arr_i = 0; arr_i < n; arr_i++) {
		cin >> arr[arr_i];
		if (arr[arr_i] > 0)
			pos++;
		else if (arr[arr_i] < 0)
			neg++;
		else
			zero++;
	}
	cout << setprecision(7) << pos*1.0 / n << endl;
	cout << setprecision(7) << neg*1.0 / n << endl;
	cout << setprecision(7) << zero*1.0 / n << endl;

}
