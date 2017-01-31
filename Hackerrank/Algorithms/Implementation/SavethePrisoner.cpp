#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   ios::sync_with_stdio(0);
	int T;
	cin >> T;
	long  N, M, S;
	while (T--) {
		cin >> N >> M >> S;
		long id = (M + S) % N - 1;
		if (id == 0) id = N;
		cout << id << endl;
	}
	return 0;
}
