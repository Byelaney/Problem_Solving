#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


string super_reduce(string s)
{
	if (s.size() == 0) return "Empty String";
	string result = "";
	for (int i = 0; i < s.size()-1; ++i)
	{
		if (s[i] == s[i + 1])
		{
			return super_reduce(result + s.substr(i + 2, s.size() - i - 2));
		}
		else
		{
			result += s[i];
		}
	}
	result += s[s.size() - 1];
	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	string s;
	cin >> s;
	cout << super_reduce(s) << endl;
	return 0;
}
