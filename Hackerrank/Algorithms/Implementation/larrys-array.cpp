#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> a(N+1);
        a[0] = -1;
        for (int i = 1; i <= N; ++i) cin >> a[i];
        int l = 1, r = N, toSwap = N;
        while (r - l + 1 >= 3) {
            for (int i = l; i <= r; ++i) {
                if (a[i] == toSwap) {
                    if (toSwap > i) {
                        if (i - 1 < 1) {
                            swap(a[i+1], a[i+2]);
                            swap(a[i], a[i+2]);
                        }
                        else {
                            swap(a[i], a[i+1]);
                            swap(a[i-1], a[i]);
                        }
                    }
                }
            }
            r--; toSwap--;
        }
        if (a[l] < a[r]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
