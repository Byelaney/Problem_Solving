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
    	long int min = 2147483647;
	long int max = 0;
	long int num = 0;
	long int result = 0;
	for (int i = 0; i < 5; ++i)
	{
		cin >> num;
		if (num > max)
			max = num;
		if (num < min)
			min = num;
		result += num;
	}
	cout << result - max << " " << result - min << endl;

    return 0;
}
