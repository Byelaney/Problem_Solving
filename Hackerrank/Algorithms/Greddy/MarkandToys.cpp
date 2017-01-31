#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define ULL unsigned long long

using namespace std;


int main() {
    ios::sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	vector<int> price(N);
	for (int i = 0; i < N; ++i)
		cin >> price[i];
	sort(price.begin(), price.end());
	ULL sums = 0;
	int counts = 0;
	for (int i = 0; i < N; ++i)
	{
		if (sums + price[i] <= K)
		{
			sums += price[i];
			counts++;
		}
	}
	cout << counts << endl;
	return 0;
}
