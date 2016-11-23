//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <math.h>
#include <set>
#include <queue>
#include <algorithm>


#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define LL long long
#define ULL unsigned long long

using namespace std;

int MIN(const int a,const int b)
{
    if(a < b)
        return a;
    else
        return b;
}


int ABS(int x)
{
    if(x < 0)
        return -x;
    else
        return x;
}


int main()
{
    ios::sync_with_stdio(0);
    ULL x;
    cin >> x;
    vector<int> digits;
    int n = 0;
    while (x) {
        digits.push_back(x%10);
        x /= 10;
        ++n;
    }

    for(int i = n-1;i >= 0;--i)
    {
        if(i != n-1)
        {
            if(digits[i] >= 5)
                cout << 9-digits[i];
            else
                cout << digits[i];
        }
        else
        {
            if(digits[i] == 9)
                cout << 9;
            else
            {
                if(digits[i] >= 5)
                    cout << 9-digits[i];
                else
                    cout << digits[i];
            }
        }
    }

    return 0;
}
