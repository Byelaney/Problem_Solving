#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/**
 1. 从右往左找，从左往右是降序的左边第一个 O(n)。
 2. 把它右边的设置为pivlot。
 3. 从pivlot向右边移动，找到要交换的点并交换。
 4. 将pivlot右边的字符串倒转。
 */
string my_next_permutation(string s)
{
    int pivlot = -1;
    for (int i = int(s.length()-1); i>0; --i)
    {
        if (s[i] > s[i-1])
        {
            pivlot = i-1;
            break;
        }
    }
    // pivlot is in range
    if (pivlot >= 0 && pivlot < s.length())
    {
        int swap_idx = (int)s.length() - 1;
        for (int i = pivlot + 1; i < s.length(); ++i)
        {
            if (s[pivlot] >= s[i])
            {
                swap_idx = i - 1;
                break;
            }
        }
        swap(s[swap_idx], s[pivlot]);
        string::iterator it = s.begin();
        for (int i = 0; i <= pivlot; ++i) it++;
        reverse(it, s.end());
    }
    else s = "no answer";
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> s;
        cout << my_next_permutation(s) << endl;
    }
    return 0;
}
