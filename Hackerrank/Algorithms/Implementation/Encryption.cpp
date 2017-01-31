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
	string s;
	getline(cin, s);
	vector<char> v;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] != ' ')
			v.push_back(s[i]);
	}
	int low = floor(sqrt(v.size()));
	int high = ceil(sqrt(v.size()));
	int l = low;//row
	int h = low;//col
	int minM = high * high;
	for (int i = low; i <= high; ++i)
	{
		for (int j = low; j <= high; ++j)
		{
			int tmpSum = i * j;
			if (tmpSum >= v.size() && tmpSum <= minM)
			{
				l = i;
				h = j;
				minM = tmpSum;
			}
		}
	}
	if (l > h) swap(l, h);
	vector<vector<char>> encrypted(l);
	int pos = 0;
	int curH = 0;
	for (int i = 0; i < l; ++i)
	{
		curH = 0;
		while (curH < h)
		{
			if (pos < v.size())
			{
				encrypted[i].push_back(v[pos++]);
				curH++;
			}
			else
				break;
		}
	}
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < encrypted.size(); ++j)
		{
			if (i < encrypted[j].size())
				cout << encrypted[j][i];
		}
		cout << " ";
	}
	cout << endl;
	return 0;
}

/**

9801
1089

(1,2,3)
dp[0] dp[1] dp[2] dp[3] dp[4]
1     1     2


*/
