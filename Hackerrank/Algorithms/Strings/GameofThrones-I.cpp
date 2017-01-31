#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


int main() {

    string s;
    cin>>s;

    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string
    vector<int> ary(26);
    for (int i = 0; i < s.size(); ++i) {
        ary[s[i] - 'a']++;
    }
    int odds = 0;
    for (int i = 0; i < ary.size(); ++i) {
        if (ary[i] % 2 == 1) {
            odds++;
        }
    }
    if (odds > 1)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
