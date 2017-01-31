#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
	ios::sync_with_stdio(0);
	string s;
	cin >> s;
	unsigned long long n;
	cin >> n;

	unsigned long long times = n / s.length();
	unsigned long long remainder = n % s.length();
	unsigned long long i = 0;
	unsigned long long remainder_part = 0;
	unsigned long long result = 0;
	for (; i < remainder; ++i)
	{
		if (s[i] == 'a')
			remainder_part++;
	}
	for (; i < s.length(); ++i)
	{
		if (s[i] == 'a')
			result++;
	}
	result = (result + remainder_part) * times + remainder_part;
	cout << result << endl;
	return 0;
}
