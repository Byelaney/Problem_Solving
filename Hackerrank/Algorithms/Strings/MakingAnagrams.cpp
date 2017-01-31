#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   ios::sync_with_stdio(0);
	string s1, s2;
	cin >> s1 >> s2;
	int a1[26];
	int a2[26];
	for (int i = 0;i < 26;++i)
	{
		a1[i] = 0;
		a2[i] = 0;
	}
	for (int i = 0;i < s1.size();++i)
		a1[s1[i] - 'a'] += 1;
	for (int i = 0;i < s2.size();++i)
		a2[s2[i] - 'a'] += 1;
	int counts = 0;
	for (int i = 0;i < 26;++i)
	{
		if (a1[i] != a2[i])
			counts += max(a1[i], a2[i]) - min(a1[i], a2[i]);
	}
	cout << counts << endl;
	return 0;
}
