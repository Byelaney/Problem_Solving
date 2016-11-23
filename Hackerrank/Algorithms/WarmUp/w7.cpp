#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
	string time;
	cin >> time;
	if (time.substr(8, 2) != "AM")
	{
		if (time.substr(0, 2) != "12")
		{
			int hh = stoi(time.substr(0, 2));
			string s = to_string(hh + 12);
			time[0] = s[0];
			time[1] = s[1];
		}
	}
	else
	{
		if (time.substr(0, 2) == "12")
		{
			time[0] = '0';
			time[1] = '0';
		}
	}
	cout << time.substr(0,8) << endl;
}
