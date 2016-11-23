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
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

static int* a = new int[102];

int main() {
    ios::sync_with_stdio(0);
    int n,p,q;
    cin >> n;
    cin >> p;
    int num;
    rep(i, p)
    {
        cin >> num;
        a[num] = 1;
    }
    cin >> q;
    rep(i, q)
    {
        cin >> num;
        a[num] = 1;
    }

    for(int i = 1;i<=n;++i)
    {
        if(a[i] != 1)
        {
            cout << "Oh, my keyboard!" << endl;
            return 0;
        }
    }

    cout << "I become the guy." << endl;
    return 0;
}
