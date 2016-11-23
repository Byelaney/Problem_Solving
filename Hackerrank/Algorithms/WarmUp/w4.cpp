#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
    }
    int left_sum = 0;
    int right_sum = 0;
    int dig_l = 0;
    int dig_r = n-1;

    for (int i = 0;i<n;++i) {
        left_sum += a[i][dig_l++];
        right_sum += a[i][dig_r--];
    }

    int result = max(left_sum,right_sum) - min(left_sum,right_sum);
    cout << result << endl;
    return 0;
}
