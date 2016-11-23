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
#include <stack>
#include <utility>


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
    string a;
    cin >> a;
    int i = 0;
    for(;i<a.size();++i)
    {
        if(a[i] == '1' && i != a.size()-1)
            cout << a[i];
        else if(a[i] == '1' && i == a.size()-1)
        {
            break;
        }
        else
            break;
    }

    for(i = i + 1;i<a.size();++i)
        cout << a[i];

    return 0;
}
