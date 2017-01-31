#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	int d, m, y;
	int ed, em, ey;
	cin >> d >> m >> y;
	cin >> ed >> em >> ey;
	int fine = 0;
	if (y > ey) fine = 10000;
	else if (y == ey)
	{
		if (m > em) fine = 500 * (m - em);
		else if (m == em)
		{
			if (d > ed) fine = 15 * (d - ed);
		}
	}
	cout << fine << endl;
	return 0;
}
