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
	string S;
	cin >> S;
	int cosmics = 0;
	for (int i = 0;i < S.size();)
	{
		if (S[i] != 'S') cosmics++;
		if (S[i+1] != 'O') cosmics++;
		if (S[i+2] != 'S') cosmics++;
		i += 3;
	}
	cout << cosmics << endl;
	return 0;
}
