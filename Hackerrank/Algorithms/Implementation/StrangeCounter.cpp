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

void sieveOfEratosthenes(int n)
{
	vector<bool> prime(n + 1, true);
	for (int p = 2; p*p <= n; p++)
	{
		if (prime[p])
		{
			for (int i = p * 2; i <= n; i += p)
				prime[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	ULL t , result;
	cin >> t;
	ULL n = 1;
	ULL multi = 2;
	ULL sums = 3;
	while (sums < t)
	{
		multi *= 2;
		sums = 3 * (multi - 1);
		++n;
	}
	multi /= 2;
	ULL start = sums - (3 * multi) + 1;
	result = 3 * multi - (t - start);
	cout << result << endl;
	return 0;
}

/*
Sn = 3(2^n-1)
An = 3 * 2^(n-1)
*/
