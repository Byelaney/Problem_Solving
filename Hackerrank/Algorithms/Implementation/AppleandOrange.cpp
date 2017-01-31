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
	int s;
	int t;
	cin >> s >> t;
	int a;
	int b;
	cin >> a >> b;
	int m;
	int n;
	cin >> m >> n;
	vector<int> apple(m);
	for (int apple_i = 0; apple_i < m; apple_i++) {
		cin >> apple[apple_i];
	}
	vector<int> orange(n);
	for (int orange_i = 0; orange_i < n; orange_i++) {
		cin >> orange[orange_i];
	}
	int apples = 0;
	for (int i = 0; i < m; i++) {
		int pos = apple[i] + a;
		if (pos >= s && pos <= t)
		{
			apples += 1;
		}
	}
	int oranges = 0;
	for (int i = 0; i < n; ++i)
	{
		int pos = orange[i] + b;
		if (pos >= s && pos <= t)
		{
			oranges += 1;
		}
	}
	cout << apples << endl;
	cout << oranges << endl;
	return 0;
}
