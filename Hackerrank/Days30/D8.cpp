#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
	int n;
	cin >> n;
	unordered_map<string, string> phonepage;
	string name = "";
	string phone = "";
	for (int i = 0; i < n; ++i)
	{
		cin >> name;
		cin >> phone;
		phonepage[name] = phone;
	}
	while (cin >> name)
	{
		if (phonepage.count(name) != 0)
			cout << name << "=" << phonepage[name] << endl;
		else
			cout << "Not found" << endl;
	}
	return 0;
}
