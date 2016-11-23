#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
	cin >> n;
	int seed = 5;
	int people = 0;
	for (int i = 0; i < n; ++i)
	{
		people += seed / 2;
		seed = seed / 2 * 3;
	}
	cout << people << endl;
    return 0;
}
