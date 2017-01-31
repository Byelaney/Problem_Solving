#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
   ios::sync_with_stdio(0);
	int n, num;
	cin >> n;
	unordered_map<int, vector<int>> ump;
	int distance = 2147483647;
	bool paired = false;
	for (int i = 0;i < n;++i)
	{
		cin >> num;
		if (ump.count(num))
		{
			vector<int> v_tmp = ump[num];
			v_tmp.push_back(i);
			if (v_tmp[v_tmp.size() - 1] - v_tmp[v_tmp.size() - 2] < distance)
			{
				distance = v_tmp[v_tmp.size() - 1] - v_tmp[v_tmp.size() - 2];
				paired = true;
			}
		}
		else
		{
			vector<int> v;
			v.push_back(i);
			ump[num] = v;
		}
	}
	if (paired)
		cout << distance << endl;
	else
		cout << -1 << endl;
    return 0;
}
