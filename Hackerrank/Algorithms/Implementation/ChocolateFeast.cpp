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

bool isKaprekar(ULL num)
{
	ULL square = num * num;
	vector<int> digits;
	int digit = 0;
	while (square != 0)
	{
		digit = square % 10;
		digits.push_back(digit);
		square /= 10;
	}
	int l = 0;
	int r = 0;
	reverse(digits.begin(), digits.end());
	for (int i = 0; i < digits.size() / 2; ++i)
	{
		l = l * 10 + digits[i];
	}
	for (int i = (int)digits.size() / 2; i < digits.size(); ++i)
	{
		r = r * 10 + digits[i];
	}
	if (l + r == num) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(0);
	int t, n, c, m;
	int result = 0;
	int left = 0;
	cin >> t;
	while (t--)
	{
		result = 0;
		left = 0;
		cin >> n >> c >> m;
		result += n / c;
		left += n / c;
		while (left >= m)
		{
			result += left / m;
			left = left / m + left % m;
		}
		cout << result << endl;
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
