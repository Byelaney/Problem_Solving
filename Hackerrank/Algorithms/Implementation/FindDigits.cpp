#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define rep1(i,n) for(int i = 1;i<n;++i)
#define r_rep(i,n) for(int i = n-1;i>=0;--i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define LL long long
#define ULL unsigned long long

int main() {
   ios::sync_with_stdio(0);
	int t;
	cin >> t;
	ULL num = 0;
	while (t--)
	{
		cin >> num;
		int counts = 0;
		ULL tmp = num;
		while (tmp)
		{
			ULL digit = tmp % 10;
			if (digit != 0 && num%digit == 0)
				counts++;
			tmp /= 10;
		}
		cout << counts << endl;
	}
	return 0;
}
