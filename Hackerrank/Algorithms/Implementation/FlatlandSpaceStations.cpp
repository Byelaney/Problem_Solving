// acm.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include <string>
#include <math.h>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <list>
#include <iomanip>
#include <unordered_set>

#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define rep1(i,n) for(int i = 1;i<n;++i)
#define r_rep(i,n) for(int i = n-1;i>=0;--i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define LL long long
#define ULL unsigned long long

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int n, m, val;
	cin >> n >> m;
	vector<int> space(n);
	vector<int> dp_left(n);
	vector<int> dp_right(n);

	for (int i = 0; i < m; ++i)
	{
		cin >> val;
		space[val] = 1;
	}
	dp_left[0] = (space[0] == 1) ? 0 : (n - 1);
	for (int i = 1; i < n; ++i)
	{
		if (space[i])
			dp_left[i] = 0;
		else
			dp_left[i] = dp_left[i - 1] + 1;
	}
	dp_right[n - 1] = (space[n - 1] == 1) ? 0 : (n - 1);
	for (int i = n - 2; i >= 0; --i)
	{
		if (space[i])
			dp_right[i] = 0;
		else
			dp_right[i] = dp_right[i + 1] + 1;
	}
	int maxR = -1;
	for (int i = 0; i < n; ++i)
	{
		if (min(dp_left[i], dp_right[i]) > maxR)
			maxR = min(dp_left[i], dp_right[i]);
	}
	cout << maxR << endl;
	return 0;
}

/**

9801
1089

(1,2,3)
dp[0] dp[1] dp[2] dp[3] dp[4]
1     1     2


*/
