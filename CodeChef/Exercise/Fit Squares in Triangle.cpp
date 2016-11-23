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


int main()
{
    ios::sync_with_stdio(0);
    int a[10001];
    for(int i = 0;i<=3;++i)
        a[i] = 0;

    int diff = 1;
    for(int i = 4;i<=10000;i=i+2)
    {
        a[i] = a[i-1] + diff;
        a[i+1] = a[i];
        ++diff;
    }


    int T,B;
    cin >> T;
    while(T--)
    {
        cin >> B;
        cout << a[B] << endl;
    }

    return 0;
}
