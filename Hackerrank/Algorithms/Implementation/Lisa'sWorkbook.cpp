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

int specialF(int start_page, int end_page, int t_i, int k)
{
	int special = 0;
	int q_start = 0;
	int q_end = 0;
	for (int p = start_page; p <= end_page; ++p)
	{
		q_start = q_end + 1;
		if (t_i >= k)
			q_end = q_start + k - 1;
		else
			q_end = q_start + t_i - 1;

		if (p >= q_start && p <= q_end)
			special++;
		t_i -= k;
	}
	return special;
}

int main()
{
	ios::sync_with_stdio(0);
	int n, k, t_i;
	cin >> n >> k;
	int start_page = 0;
	int end_page = 0;
	int special = 0;
	for (int i = 0; i < n; ++i)
	{
		start_page = end_page + 1;
		cin >> t_i;
		if (t_i%k == 0)
			end_page = start_page + t_i / k - 1;
		else
			end_page = start_page + t_i / k;

		special += specialF(start_page, end_page, t_i, k);
	}
	cout << special << endl;
	return 0;
}

/**

9801
1089

(1,2,3)
dp[0] dp[1] dp[2] dp[3] dp[4]
1     1     2


*/
