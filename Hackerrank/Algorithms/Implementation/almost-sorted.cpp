Given an array with  elements, can you sort this array in ascending order using only one of the following operations?

Swap two elements.
Reverse one sub-segment.
Input Format
The first line contains a single integer, , which indicates the size of the array.
The next line contains  integers separated by spaces.

n
d1 d2 ... dn
Constraints


All  are distinct.

Output Format
1. If the array is already sorted, output yes on the first line. You do not need to output anything else.

If you can sort this array using one single operation (from the two permitted operations) then output yes on the first line and then:

a. If you can sort the array by swapping  and , output swap l r in the second line.  and  are the indices of the elements to be swapped, assuming that the array is indexed from  to .

b. Else if it is possible to sort the array by reversing the segment , output reverse l r in the second line. and  are the indices of the first and last elements of the subsequence to be reversed, assuming that the array is indexed from  to .

 represents the sub-sequence of the array, beginning at index  and ending at index , both inclusive.

If an array can be sorted by either swapping or reversing, stick to the swap-based method.

If you cannot sort the array in either of the above ways, output no in the first line.

Sample Input #1

2
4 2
Sample Output #1

yes
swap 1 2
Sample Input #2

3
3 1 2
Sample Output #2

no
Sample Input #3

6
1 5 4 3 2 6
Sample Output #3

yes
reverse 2 5
Explanation
For #1, you can both swap(1, 2) and reverse(1, 2), but if you can sort the array using swap, output swap only.
For #2, it is impossible to sort by one single operation (among those permitted).
For #3, you can reverse the sub-array d[2...5] = "5 4 3 2", then the array becomes sorted.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> dn(n);
    for (int i = 0; i < n; ++i) cin >> dn[i];
    int l = 0, r = n-1;
    for (int i = 0; i < n - 1; ++i) {
        if (dn[i] > dn[i+1]) {
            l = i;
            break;
        }
    }
    for (int i = n-1; n > 0; --i) {
        if (dn[i] < dn[i-1]) {
            r = i;
            break;
        }
    }
    bool canSwap = false;
    bool canReverse = false;
    string command = "";
    swap(dn[l], dn[r]);
    if (is_sorted(dn.begin(), dn.end())) canSwap = true;
    swap(dn[l], dn[r]);
    vector<int>::iterator p1 = dn.begin(), p2 = dn.begin();
    for (int i = 0; i < l; ++i) {
        p1++;p2++;
    }
    for (int i = l; i < r+1; ++i) p2++;
    reverse(p1, p2);
    if (is_sorted(dn.begin(), dn.end())) canReverse = true;
    if (canReverse) command = "reverse ";
    if (canSwap) command = "swap ";
    if (canSwap || canReverse) {
        cout << "yes" << endl;
        cout << command << l+1 << " " << r+1 << endl;
    }
    else cout << "no" << endl;
    return 0;
}

// just find the "l" and "r" then check swap and reverse
// time O(n)
