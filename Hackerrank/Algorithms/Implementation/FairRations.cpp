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
	int N;
	cin >> N;
	vector<int> bread(N);
	ULL sum = 0;
	int op = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> bread[i];
		sum += bread[i];
	}
	if (sum & 1)
		cout << "NO" << endl;
	else
	{
		for (int i = 0; i < N; ++i)
		{
			if (bread[i] & 1)
			{
				bread[i] += 1;
				bread[i + 1] += 1;
				op += 2;
			}
		}
		cout << op << endl;
	}

	return 0;
}

/**

9801
1089

(1,2,3)
dp[0] dp[1] dp[2] dp[3] dp[4]
1     1     2


*/
