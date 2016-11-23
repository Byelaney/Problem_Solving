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
#include <unordered_set>

using namespace std;


int main(){
	int n;
	cin >> n;
	unordered_set<int> uoset;
	int c = 0;
	int sells = 0;
	for (int c_i = 0; c_i < n; c_i++) {
		cin >> c;
		if (uoset.count(c))
		{
			uoset.erase(c);
			sells++;
		}
		else
		{
			uoset.insert(c);
		}
	}
	cout << sells << endl;
	return 0;
}
