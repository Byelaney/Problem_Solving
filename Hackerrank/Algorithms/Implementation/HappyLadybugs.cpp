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
	int g, n;
	string s;
	cin >> g;
	while (g--)
	{
		cin >> n;
		cin >> s;
		unordered_map<char, int> ump;
		int empty = 0;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == '_') empty++;
			else
			{
				if (ump.count(s[i])) ump[s[i]]++;
				else ump[s[i]] = 1;
			}
		}
		bool lonely = false;
		for (unordered_map<char, int>::iterator it = ump.begin(); it != ump.end(); ++it)
		{
			if (it->second == 1)
			{
				lonely = true;
				break;
			}
		}
		if (lonely) cout << "NO" << endl;
		else
		{
			bool same_color = true;
			for (int i = 0; i < n;i++)
			{
				if (s[i] != '_')
				{
					bool prev = false;
					bool post = false;
					if (i > 0) prev = (s[i] == s[i - 1]) ? true : false;
					if (i < n - 1) post = (s[i] == s[i + 1]) ? true : false;
					if (!(prev || post))
					{
						same_color = false;
						break;
					}
				}
			}
			if (same_color) cout << "YES" << endl;
			else
			{
				if (empty > 0)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
		}
	}
	return 0;
}
