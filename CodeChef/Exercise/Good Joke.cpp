#include <iostream>

using namespace std;

int main() {
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		cin >> n;
		for (int i = 1; i <= n + n; i++) {
			int x;
			cin >> x;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans ^= i;
		}
		cout << ans << endl;
	}

}
