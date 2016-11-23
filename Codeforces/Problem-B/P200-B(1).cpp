#include <iostream>
#include <stdio.h>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const double EPS = 1e-9;
const int INF = (int)(1e9 + 7.5);
const int MAXN = 100005;

inline int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int n;
	double ans = 0.0, z;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%lf", &z);
		ans += z / 100.0;
	}
	printf("%.9lf\n", (ans / (n + .0)) * 100.0);
	return 0;
}
