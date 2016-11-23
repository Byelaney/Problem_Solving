#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int reverse(int num)
{
	int result = 0;
	while (num)
	{
		result = result * 10 + num % 10;
		num /= 10;
	}
	return result;
}

int main() {
    int i, j, k = 0;
	cin >> i >> j >> k;
	int result = 0;
	for (int day = i; day <= j; ++day)
	{
		int reversed = reverse(day);
		if ((max(day,reversed) - min(day,reversed)) % k == 0)
		{
			result += 1;
		}
	}
	cout << result << endl;
    return 0;
}
