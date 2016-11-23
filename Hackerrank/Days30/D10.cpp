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
	int n;
	cin >> n;
	string binary = "";
	while (n)
	{
		binary += to_string(n % 2);
		n = n >> 1;
	}
	reverse(binary.begin(), binary.end());
	int max = 0;
	int count = 0;
	for (int i = 0; i < binary.length(); ++i)
	{
		if (binary[i] == '1')
		{
			count++;
		}
		else
		{
			if (count > max)
			{
				max = count;
			}
			count = 0;
		}
	}
	int result = (max > count) ? max : count;
	cout << result << endl;
    return 0;
}
