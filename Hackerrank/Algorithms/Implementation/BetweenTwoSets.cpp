#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template < typename T >
T GCD(T a, T b) {
	if(b) while((a %= b) && (b %= a));
	return a + b;
}
template < typename T >
T LCM(T a, T b) {
	return a * b / GCD(a, b);
}

int main() {
   ios::sync_with_stdio(0);
	int n, m, num;
	cin >> n >> m;
	int lcm = 1;
	for (int i = 0;i < n;++i)
	{
		cin >> num;
		lcm = LCM(lcm, num);
	}
	cin >> num;
	int gcd = num;
	for (int i = 1;i < m;++i)
	{
		cin >> num;
		gcd = GCD(gcd, num);
	}
	int factor = 1;
	int counts = 0;
	int tmp = lcm;
	while (tmp <= gcd)
	{
		if (gcd % tmp == 0)
			counts++;
		factor++;
		tmp = lcm * factor;
	}
	cout << counts << endl;
	return 0;
}
