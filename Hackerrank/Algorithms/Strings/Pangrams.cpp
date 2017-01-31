#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
	unordered_set<char> alp;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); ++i)
	{
		char c = tolower(s[i]);
		if (c >= 'a' && c <= 'z')
			alp.insert(c);
	}
	if (alp.size() == 26)
		cout << "pangram" << endl;
	else
		cout << "not pangram" << endl;
	return 0;
}
