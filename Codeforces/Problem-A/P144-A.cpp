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
	int n;
	cin >> n;
	int a[101];
	rep(i, n)
		cin >> a[i];
	int l, r = 0;
	rep(i, n)
	{
		if (a[i] > a[r])
			r = i;
		if (a[i] <= a[l])
			l = i;
	}

	if (r > l)
		cout << r + n - l - 2 << endl;
	else
		cout << r + n - l - 1 << endl;
    return 0;
}
