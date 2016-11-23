//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <iostream>
#include <algorithm>

#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)


using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int* a = new int[n];
    int* b = new int[n];
    rep(i,n)
    {
        cin >> a[i];
    }
    int max = 0;
    rep(i, n)
    {
        FOR(j,i,n-1)
        {
            rep(i, n)
            b[i] = a[i];

            int tmp = 0;
            FOR(k, i, j)
            {
                b[k] ^= 1;
            }
            rep(i, n)
                tmp += b[i];
            max = (max > tmp)?max:tmp;
        }
    }

    cout << max << "\n";
    return 0;
}
