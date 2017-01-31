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
	int n = 26;
	vector<int> h(n);
	for (int h_i = 0;h_i < n;h_i++)
		cin >> h[h_i];
	string word;
	cin >> word;
	int height = -1;
	for (int i = 0;i < word.size();++i)
	{
		if (h[word[i] - 'a'] > height)
			height = h[word[i] - 'a'];
	}
	cout << word.size() * height << endl;
	return 0;
}
