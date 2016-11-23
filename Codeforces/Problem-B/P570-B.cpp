//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//
#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <fstream>

#include <cstring>

#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <math.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;

    int a;
    if(n%2 != 0)
    {
        if(m == (n+1)/2)
            a = m - 1;
        else if(m < (n+1)/2)
            a = m + 1;
        else
            a = m - 1;
    }
    else
    {
        if(m <= n/2)
            a = m + 1;
        else
            a = m - 1;
    }

    if(n == 1)
        a = 1;

    cout << a << endl;
    return 0;
}
