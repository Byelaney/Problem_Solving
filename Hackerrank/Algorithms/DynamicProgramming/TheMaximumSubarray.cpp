

// HackerRank.cpp : Defines the entry point for the console application.
//
#include<set>
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

#define ULL unsigned long long
#define LL long long

using namespace std;

int main() {
	int T, N, a_i;
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<int> num(N);
		cin >> num[0];
		LL un_continuous = 0;
		if (num[0] > 0)
			un_continuous += num[0];
		LL maximu = num[0];
		for (int i = 1;i < N;++i)
		{
			cin >> num[i];
			if (num[i] > 0)
				un_continuous += num[i];
			if (num[i] > maximu)
				maximu = num[i];
		}
		if (un_continuous == 0) un_continuous += maximu;
		LL continuous = num[0];
		LL current = num[0];
		for (int i = 1;i < num.size();++i)
		{
			if (num[i] > current + num[i])
				current = num[i];
			else
				current = current + num[i];

			if (current > continuous)
				continuous = current;
		}

		cout << continuous << " " << un_continuous << endl;
	}
	return 0;
}
