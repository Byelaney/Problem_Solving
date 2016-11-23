#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int n;
	int k;
	int q;
	cin >> n >> k >> q;
	vector<int> a(n);
	vector<int> b(n);
	for (int a_i = 0; a_i < n; a_i++) {
		cin >> a[a_i];
	}
	for (int i = 0; i < (k%n); ++i)
	{
		b[i] = a[n - (k%n) + i];
	}

	int i = 0;
	for (int j = (k%n); j < n; ++j)
	{
		b[j] = a[i++];
	}

	for (int a0 = 0; a0 < q; a0++) {
		int m;
		cin >> m;
		cout << b[m] << endl;
	}
	return 0;
}
