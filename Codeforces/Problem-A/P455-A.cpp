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



unsigned long long MAX(unsigned long long a,unsigned long long b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main() {
    ios::sync_with_stdio(0);
    int n,num;
    cin >> n;

    unsigned long long* a = new unsigned long long[100002];
    unsigned long long* answer = new unsigned long long[100002];
    rep(j, 100002)
    {
        a[j] = 0;
        answer[j] = 0;
    }

    rep(i, n)
    {
        cin >> num;
        ++a[num];
    }

    answer[0] = 0;
    answer[1] = a[1];
    for(unsigned long long i = 2;i<=100000;++i)
    {
        answer[i] = MAX(answer[i-2] + i * a[i], answer[i-1]);
    }

    cout << answer[100000] << endl;
    return 0;
}
