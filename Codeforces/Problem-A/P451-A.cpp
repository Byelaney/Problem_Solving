#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include <string>
#include <math.h>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <list>

#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define rep1(i,n) for(int i = 1;i<n;++i)
#define r_rep(i,n) for(int i = n-1;i>=0;--i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define LL long long
#define ULL unsigned long long

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;

    if (n == 1 || m == 1)
        cout << "Akshat" << endl;
    else
    {
        int dur = min(n,m) - 1;
        n -= dur;
        m -= dur;

        if (dur%2 == 0)
            cout << "Akshat" << endl;
        else
            cout << "Malvika" << endl;
    }

    return 0;
}
